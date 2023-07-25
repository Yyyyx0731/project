package main

import (
	"crypto/md5"
	"database/sql"
	"encoding/hex"
	"fmt"
	_ "github.com/go-sql-driver/mysql"
	"io"
	"net"
	"os"
	"strconv"
	"strings"
	"time"
)


var db *sql.DB
var name string



func main() {

	conn, err := net.Dial("tcp", "127.0.0.1:7890")
	if err!=nil {
		fmt.Println(err)
		return
	}
	 defer  conn.Close()

	connectMysql()
	defer db.Close()

	menu(conn)

	go processMassage(conn)

	//接收
	buf := make([]byte, 1024)
	for {
		length, err := conn.Read(buf)
		if err!=nil{
			fmt.Println("client read:",err)
		}

		fmt.Printf("\n")
		fmt.Println(time.Now().Format("2006/01/02 15:04:05"))
		fmt.Println(string(buf[:length]))

	}

}


func menu(conn net.Conn){
	flag  := 1
	for flag==1 {
		fmt.Println("1.登录")
		fmt.Println("2.注册")
		fmt.Println("3.退出")
		fmt.Println("请选择您要进行的操作:")
		var x string
		fmt.Scan(&x)
		switch x {
		case "1":
			loginMenu(conn)
			flag=0
		case "2":
			registerMenu(conn)
			flag=0
		case "3":
			flag=0
			os.Exit(0)
		default:
			fmt.Println("输入不合法，请重新输入...")
		}
	}

}

func loginMenu(conn net.Conn){
	flag := 1
	for flag==1 {
		fmt.Printf("用户名：")
		var n,p string
		fmt.Scan(&n)
		l:=QueryName(n)
		if l==0 {
			fmt.Println("该用户还未注册！即将进入注册页面...")
				registerMenu(conn)
			break
		}
		fmt.Printf("密码：")
		fmt.Scan(&p)

		var k int =0
		k = Query(n,p,db)
		if k==1 {
			flag=0
			fmt.Println("登录成功！！")
			name=n
			loginMsg := "用户 " + name + " 已上线..."
			_, err := conn.Write([]byte(loginMsg))
			if err!=nil {
				fmt.Println(err)
			}

			functionMenu()//进入功能菜单
		}else {
			fmt.Println("用户名或密码不正确，请重新输入...")
		}
	}
}


func registerMenu(conn net.Conn){
	var n,p1,p2 string
	var mark int =1
	for mark==1{
		fmt.Printf("用户名：")
		fmt.Scan(&n)
		if len(n)>12||len(n)<1 {
			fmt.Println("用户名必须在1~12个字数范围内！请重新输入...")
			continue
		}
		flag:=checkName(n)
		if flag==0 {
			fmt.Println("用户名只能包含数字、字母、下划线！请重新输入...")
			continue
		}
		mark = QueryName(n)
		if mark==1 {
			fmt.Println("该用户名已被使用，请重新输入...")
		}else{
			mark=0
		}
	}
	var flag int = 1
	for  flag==1 {
		fmt.Printf("密码：")
		fmt.Scan(&p1)
		if len(p1)<6||len(p1)>12 {
			fmt.Println("密码必须在6~12个字数范围内！请重新输入...")
			continue
		}
		l:=checkPass(p1)
		if l==0 {
			fmt.Println("用户名只能包含数字、字母！请重新输入...")
			continue
		}
		fmt.Printf("请再次确认密码：")
		fmt.Scan(&p2)
		if p1==p2 {
			flag=0
		}else{
			fmt.Println("两次密码不一致，请重新输入...")
		}
	}
	name=n
	l:=addClient(n,p1)
	if l==0{
		os.Exit(0)
	}
//	fmt.Println("注册成功！！")
	name=n
	loginMsg := "用户 " + name + " 已上线..."
	_, err := conn.Write([]byte(loginMsg))
	if err!=nil {
		fmt.Println(err)
	}
	functionMenu()//进入功能菜单
}

func addClient(n string,p string)int  {
	pp:=MD5Password(p)
	sqlStr:="insert into client(name,password) values(?,?)"
	_,err:=db.Exec(sqlStr,n,pp)
	if err!=nil {
		fmt.Println(err)
		fmt.Printf("注册失败!!")
		return 0
	}else {
		fmt.Println("注册成功！！")
		return 1
	}
}

func checkName(n string)int  {
	pass:=[]byte(n)
	for k:=range pass{
		if !(pass[k]=='_')&&!(pass[k]>='0'&&pass[k]<='9')&&!(pass[k]>='a'&&pass[k]<='z')&&!(pass[k]>='A'&&pass[k]<='Z') {
			return 0
		}
	}
	return 1
}

func checkPass(p string)int{
	pass:=[]byte(p)
	for k:=range pass{
		if !(pass[k]>='0'&&pass[k]<='9')&&!(pass[k]>='a'&&pass[k]<='z')&&!(pass[k]>='A'&&pass[k]<='Z') {
			return 0
		}
	}
	return 1
}


func functionMenu(){
	fmt.Println(" —— —— —— —— —— —— —— —— —— —— —— —— —— ——")
	fmt.Println("|显示菜单/list                            |")
	fmt.Println("|私聊模式:/private                        |")
	fmt.Println("|修改昵称:/reName                         |")
	fmt.Println("|修改密码:/rePassword                     |")
	fmt.Println("|退出登录:/exit                           |")
	fmt.Println("|传输文件:/file                           |")
	fmt.Println("|在线用户查询:/online                     |")
	fmt.Println("|注销用户:/logOff                         |")
	fmt.Println("|注：若不进行选择，消息发送模式默认为公聊 |")
	fmt.Println(" —— —— —— —— —— —— —— —— —— —— —— —— —— ——")
}

func processMassage(conn net.Conn){
	alive := make(chan bool)
	go func() {
		for{
			//fmt.Println("请输入：")
			var m string
			fmt.Scan(&m)
			msg:=strings.ToLower(m)
			if msg =="/private"{
				fmt.Printf("请输入你要私聊的对象的用户名：")
				var user,m string
				fmt.Scan(&user)
				fmt.Printf("请输入信息：")
				fmt.Scan(&m)
				_, err := conn.Write([]byte("[私聊 "+user+" ] "+name+" :"+m))
				if err != nil {
					conn.Close()
					fmt.Println(err)
					break
				}
			}else if msg == "/rename"{
				var n string
				mark:=1
				for mark==1{
					fmt.Printf("请输入修改后的用户名：")
					fmt.Scan(&n)
					if len(n)>12||len(n)<1 {
						fmt.Println("用户名必须在1~12个字数范围内！请重新输入...")
						continue
					}
					flag:=checkName(n)
					if flag==0 {
						fmt.Println("用户名只能包含数字、字母、下划线！请重新输入...")
						continue
					}
					mark = QueryName(n)
					if mark==1 {
						fmt.Println("该用户名已被使用，请重新输入...")
					}else{
						mark=0
					}
				}
				modifyName(n)
				fmt.Println("用户名修改成功...")
				name=n
				continue
			}else if msg == "/repassword"{
				var p,p1,p2 string
				var flag int = 1
				for  {
					fmt.Printf("请输入原始密码：")
					fmt.Scan(&p)
					mark := Query(name, p, db)
					if mark == 0 {
						fmt.Println("密码错误，请重新输入...")
						continue
					}else {
						break;
					}
				}
				for flag==1 {
					fmt.Printf("请输入修改后的密码：")
					fmt.Scan(&p1)
					if len(p1)<6||len(p1)>12 {
						fmt.Println("密码必须在6~12个字数范围内！请重新输入...")
						continue
					}
					l:=checkPass(p1)
					if l==0 {
						fmt.Println("用户名只能包含数字、字母！请重新输入...")
						continue
					}
					fmt.Printf("请再次确认密码：")
					fmt.Scan(&p2)
					if p1==p2 {
						flag=0
					}else{
						fmt.Println("两次密码不一致，请重新输入...")
					}
				}
				modifyPass(p2)
				fmt.Println("密码修改成功...")
				continue
			}else if msg == "/file"{
				sendFile()
				continue
			}else if msg == "/exit"{
				_, err := conn.Write([]byte("exit "+name))
				if err != nil {
					conn.Close()
					fmt.Println(err)
					break
				}
				os.Exit(0)
			}else if msg =="/online"{
				_, err := conn.Write([]byte("online "+name))
				if err != nil {
					conn.Close()
					fmt.Println(err)
					break
				}
				continue
			}else if msg == "/list"{
				functionMenu()
			}else if msg == "/logoff"{
				deleteClient(name)
				_, err := conn.Write([]byte("exit "+name))
				if err != nil {
					conn.Close()
					fmt.Println(err)
					break
				}
				os.Exit(0)
			}else{//公聊
				_, err := conn.Write([]byte(name+":"+msg))
				if err != nil {
					conn.Close()
					fmt.Println("all:",err)
					break
				}
			}
			alive<-true
		}
	}()

		for {
			select {
			case <-alive:
			case  <-time.After(time.Minute*3):
				fmt.Println("由于您超过三分钟未进行操作，您已被强制下线...")
				_, err := conn.Write([]byte("exit "+name))
				if err != nil {
					conn.Close()
					fmt.Println(err)
					break
				}
				conn.Close()
				os.Exit(0)
			}
		}

}

func modifyName(n string)  {
	selStr := "update client set name = ? where name = ? "
	_, err := db.Exec(selStr, n,name)
	if err != nil {
		fmt.Println("exec err:",err)
		return
	}

}

func modifyPass(p string)  {
	pp:=MD5Password(p)
	selStr := "update client set password = ? where name = ? "
	_, err := db.Exec(selStr,pp,name)
	if err != nil {
		fmt.Println("exec err:",err)
		return
	}
}

func deleteClient(n string)  {
	sqlStr := `delete from client  where name = ?`
	_, err := db.Exec(sqlStr, n)
	if err != nil {
		fmt.Println("delete:", err)
		return
	}
}

func sendFile()  {
	fmt.Printf("请输入要传输的文件路径：")
	var path string
	fmt.Scan(&path)
	str:=strings.Split(path,".")
	srcFile:=path
	destFile:="copyTest."+str[1]
	tempFile:=destFile+"temp."+str[1]
	file1,_:=os.Open(srcFile)
	file2,_:=os.OpenFile(destFile,os.O_CREATE|os.O_WRONLY,os.ModePerm)
	file3,_:=os.OpenFile(tempFile,os.O_CREATE|os.O_RDWR,os.ModePerm)

	defer file1.Close()
	defer file2.Close()
	//读取临时文件中的数据，根据seek
	file3.Seek(0,io.SeekStart)
	bs:=make([]byte,100,100)
	n1,err:=file3.Read(bs)
	cntStr:=string(bs[:n1])
	cnt,_:=strconv.ParseInt(cntStr,10,64)

	file1.Seek(cnt,0)
	file2.Seek(cnt,0)
	data:=make([]byte,1024,1024)
	n2:=-1// 读取量
	n3:=-1//写入量
	total :=int(cnt)//读取总量

	for{
		//读取
		n2,err=file1.Read(data)
		if err == io.EOF{
			fmt.Printf("文件传输成功！！\n")
			file3.Close()
			os.Remove(tempFile)
			break
		}
		//写入
		n3,_=file2.Write(data[:n2])
		total += n3

		file3.Seek(0,io.SeekStart)
		file3.WriteString(strconv.Itoa(total))
	}
}


func connectMysql() {
	dsn := "root:hyx20040731@tcp(127.0.0.1:3306)/chatroom" //数据源
	var err error
	db, err = sql.Open("mysql", dsn)  //打开数据库连接
	if err != nil {
		fmt.Println("数据库连接失败:", err)
		return
	}
	//defer db.Close()
	err=db.Ping()
	if err!=nil {
		fmt.Println("ping:",err)
	}
	db.SetMaxOpenConns(15) //设置数据库连接池最大连接数
	db.SetMaxIdleConns(5)  //设置最大空闲连接数
	fmt.Println("数据库连接成功...")
}

func Query(name string,password string,db *sql.DB)( x int){
	p:=MD5Password(password)
	sqlStr:="select password from client where name =?;"
	var c string=""
	err:=db.QueryRow(sqlStr,name).Scan(&c)
	if err != nil {
		fmt.Println("query:",err)
	}
	if(p==c) {
		//登录成功
		return 1
	}else{
		return 0
	}
}



func QueryName(name string) (flag int){
	sqlStr:="select name from client where name =?;"
	var n string = ""
	err:=db.QueryRow(sqlStr,name).Scan(&n)
	if err != nil {
		fmt.Println(err)
	}
	if n=="" {
		flag=0
	}else{
		flag=1
	}
	return flag
}

func MD5Password(code string) string {
	MD5 := md5.New()
	_, _ = io.WriteString(MD5, code)
	return hex.EncodeToString(MD5.Sum(nil))
}


