package logger

import (
	"context"
	"encoding/json"
	"fmt"
	"github.com/gin-gonic/gin"
	"io"
	"log"
	"runtime"
	"time"
)

//日志分级相关代码


// Level 和 Fields 预定义了应用日志的 Level 和 Fields 的具体类型
type Level int8

type Fields map[string]interface{}

//六个日志等级
const (
	LevelDebug Level = iota
	LevelInfo
	LevelWarn
	LevelError
	LevelFatal
	LevelPanic
)


type Logger struct {
	newLogger *log.Logger
	ctx       context.Context
	Level     Level
	fields    Fields
	callers   []string
}


func (l Level) String() string {
	switch l {
	case LevelDebug:
		return "debug"
	case LevelInfo:
		return "info"
	case LevelWarn:
		return "warn"
	case LevelError:
		return "error"
	case LevelFatal:
		return "fatal"
	case LevelPanic:
		return "panic"
	}
	return ""
}




//日志标准化
//进行日志的实例初始化和标准化参数绑定

func NewLogger(w io.Writer, prefix string, flag int) *Logger {
	//参数out设置日志信息写入的目的地。参数prefix会添加到生成的每一条日志前面。参数flag定义日志的属性（时间、文件等等）
	l := log.New(w, prefix, flag)
	return &Logger{newLogger: l}
}

func (l *Logger) clone() *Logger {
	nl := *l
	return &nl
}

// WithLevel 设置日志等级
func (l *Logger) WithLevel(lvl Level) *Logger {
	ll := l.clone()
	ll.Level = lvl
	return ll
}

// WithFields 设置日志公共字段
func (l *Logger) WithFields(f Fields) *Logger {
	ll := l.clone()
	if ll.fields == nil {
		ll.fields = make(Fields)
	}
	for k, v := range f {
		ll.fields[k] = v
	}
	return ll
}

// WithContext 设置日志上下文属性
func (l *Logger) WithContext(ctx context.Context) *Logger {
	ll := l.clone()
	ll.ctx = ctx
	return ll
}

// WithCaller 设置当前某一层调用栈的信息（程序计数器、文件信息、行号）
func (l *Logger) WithCaller(skip int) *Logger {
	ll := l.clone()
	//runtime.Caller能够返回在函数栈中的PC(指令寄存器，可以认为存储了当前执行到了哪里)，所在的文件，所在文件的具体哪一行
	pc, file, line, ok := runtime.Caller(skip)
	if ok {
		f := runtime.FuncForPC(pc)//能够根据给定的指令寄存器给出其所在的行数
		ll.callers = []string{fmt.Sprintf("%s: %d %s", file, line, f.Name())}
	}
	return ll
}

// WithCallersFrames 设置当前的整个调用栈信息
func (l *Logger) WithCallersFrames() *Logger {
	maxCallerDepth := 25
	minCallerDepth := 1
	callers := []string{}
	pcs := make([]uintptr, maxCallerDepth)
	depth := runtime.Callers(minCallerDepth, pcs)
	frames := runtime.CallersFrames(pcs[:depth])
	for frame, more := frames.Next(); more; frame, more = frames.Next() {
		callers = append(callers, fmt.Sprintf("%s: %d %s", frame.File, frame.Line, frame.Function))
		if !more {
			break
		}
	}
	ll := l.clone()
	ll.callers = callers
	return ll
}


// WithTrace 链路追踪
//将储存进去的trace_id和span_id读取出来，然后写入日志信息中
func (l *Logger) WithTrace() *Logger {
	ginCtx, ok := l.ctx.(*gin.Context)
	if ok {
		return l.WithFields(Fields{
			"trace_id": ginCtx.MustGet("X-Trace-ID"),
			"span_id":  ginCtx.MustGet("X-Span-ID"),
		})
	}
	return l
}





// JSONFormat 日志内容的格式化
func (l *Logger) JSONFormat(message string) map[string]interface{} {
	data := make(Fields, len(l.fields)+4)
	data["level"] = l.Level.String()
	data["time"] = time.Now().Local().UnixNano()
	data["message"] = message
	data["callers"] = l.callers
	if len(l.fields) > 0 {
		for k, v := range l.fields {
			if _, ok := data[k]; !ok {
				data[k] = v
			}
		}
	}
	return data
}

// Output 日志输出动作
func (l *Logger) Output(message string) {
	body, _ := json.Marshal(l.JSONFormat(message))
	content := string(body)
	switch l.Level {
	case LevelDebug:
		l.newLogger.Print(content)
	case LevelInfo:
		l.newLogger.Print(content)
	case LevelWarn:
		l.newLogger.Print(content)
	case LevelError:
		l.newLogger.Print(content)
	case LevelFatal:
		l.newLogger.Fatal(content)
	case LevelPanic:
		l.newLogger.Panic(content)
	}
}




//根据先前定义的日志分级，编写对应的日志输出的外部方法

func (l *Logger) Debug(ctx context.Context,v ...interface{}) {
	l.WithLevel(LevelDebug).WithContext(ctx).WithTrace().Output(fmt.Sprint(v...))
}

func (l *Logger) Debugf(ctx context.Context,format string, v ...interface{}) {
	l.WithLevel(LevelDebug).WithContext(ctx).WithTrace().Output(fmt.Sprintf(format, v...))
}

func (l *Logger) Info(ctx context.Context, v ...interface{}) {
	l.WithLevel(LevelInfo).WithContext(ctx).WithTrace().Output(fmt.Sprint(v...))
}

func (l *Logger) Infof(ctx context.Context,format string, v ...interface{}) {
	l.WithLevel(LevelInfo).WithContext(ctx).WithTrace().Output(fmt.Sprintf(format, v...))
}

func (l *Logger) Warn(ctx context.Context, v ...interface{}) {
	l.WithLevel(LevelWarn).WithContext(ctx).WithTrace().Output(fmt.Sprint(v...))
}

func (l *Logger) Warnf(ctx context.Context,format string, v ...interface{}) {
	l.WithLevel(LevelWarn).WithContext(ctx).WithTrace().Output(fmt.Sprintf(format, v...))
}

func (l *Logger) Error(ctx context.Context,v ...interface{}) {
	l.WithLevel(LevelError).WithContext(ctx).WithTrace().Output(fmt.Sprint(v...))
}

func (l *Logger) Errorf(ctx context.Context,format string, v ...interface{}) {
	l.WithLevel(LevelError).WithContext(ctx).WithTrace().Output(fmt.Sprintf(format, v...))
}

func (l *Logger) Fatal(ctx context.Context,v ...interface{}) {
	l.WithLevel(LevelFatal).WithContext(ctx).WithTrace().Output(fmt.Sprint(v...))
}

func (l *Logger) Fatalf(ctx context.Context,format string, v ...interface{}) {
	l.WithLevel(LevelFatal).WithContext(ctx).WithTrace().Output(fmt.Sprintf(format, v...))
}

func (l *Logger) Panic(ctx context.Context,v ...interface{}) {
	l.WithLevel(LevelPanic).WithContext(ctx).WithTrace().Output(fmt.Sprint(v...))
}

func (l *Logger) Panicf(ctx context.Context,format string, v ...interface{}) {
	l.WithLevel(LevelPanic).WithContext(ctx).WithTrace().Output(fmt.Sprintf(format, v...))
}



