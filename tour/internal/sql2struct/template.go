package sql2struct

import (
	"fmt"
	"github.com/golang/program/travel_study/tour/internal/word"
	"html/template"
	"os"
)

//预定义模板
const structTpl = `type {{.TableName | ToCamelCase}} struct {
{{range .Columns}}	{{ $length := len .Comment}} {{ if gt $length 0 }}// {{.Comment}} {{else}}// {{.Name}} {{ end }}
	{{ $typeLen := len .Type }} {{ if gt $typeLen 0 }}{{.Name | ToCamelCase}}	{{.Type}}	{{.Tag}}{{ else }}{{.Name}}{{ end }}
{{end}}}

func (model {{.TableName | ToCamelCase}}) TableName() string {
	return "{{.TableName}}"
}`
//const structTpl = `type {{.TableName | ToCamelCase}} struct {
//{{range .Columns}}
//	{{$length := len .Comment}}
//	{{if gt $length 0 }}//
//		{{.Comment}}
//	{{else}}//
//		{{.Name}}
//	{{end}}
//	{{ $typeLen := len .Type }}
//	{{if gt $typeLen 0 }}
//		{{.Name | ToCamelCase}} {{.Type}} {{.Tag}}
//	{{else}}
//		{{.Name}}
//	{{end}}
//{{end}}
//
//func (model {{.TableName | ToCamelCase}}) TableName() string {
//	return "{{.TableName}}"
//}`



//对模板渲染对象进行声明

// StructTemplate 承担主轴的
type StructTemplate struct {
	structTpl string
}

// StructColumn 储存转换后的Go结构体中的所有字段信息
type StructColumn struct {
	Name    string
	Type    string
	Tag     string
	Comment string
}

// StructTemplateDB 储存最终用于渲染的模板对象信息
type StructTemplateDB struct {
	TableName string
	Columns   []*StructColumn
}



func NewStructTemplate() *StructTemplate {
	return &StructTemplate{structTpl: structTpl}
}


// AssemblyColumns 通过查询COLUMNS表所组装得到的tbColumns进行进一步分解和转换
// 例如：数据库类型到Go结构体的转换 对JSON tag的处理
func (t *StructTemplate)AssemblyColumns(tbColumns []*TableColumn) []*StructColumn{
	tplColumns := make([]*StructColumn,0,len(tbColumns))
	for _,column := range tbColumns {
		tplColumns = append(tplColumns,&StructColumn{
			Name: column.ColumnName,
			Type: DBTypeToStructType[column.DataType],
			//Tag: fmt.Sprintf("`json:"+"\"%s\""+"`",column.ColumnName),
			//Tag: fmt.Sprintf("`json:"+`"`+"%s"+`"`+"`",column.ColumnName),
			Tag: fmt.Sprintf("`json:"+"%s"+"`",column.ColumnName),
			Comment: column.ColumnComment,
		})
	}
	return tplColumns
}


// Generate 对模块渲染的自定义和模板对象对象进行处理
func (t *StructTemplate) Generate(tableName string,tplColumns []*StructColumn) error {
	//声明一个名为 sql2struct 的新模板对象
	tpl := template.Must(template.New("sql2struct").Funcs(template.FuncMap{
		"ToCamelCase":word.UnderscoreToUpperCamelCase, //定义自定义函数ToCamelCase，并与word.UnderscoreToUpperCamelCase方法绑定
	}).Parse(t.structTpl))
	//组装符合预定义模板的模板对象
	tplDB := StructTemplateDB{
		TableName: tableName,
		Columns: tplColumns,
	}
	//进行渲染
	err := tpl.Execute(os.Stdout,tplDB)
	if err!= nil {
		return err
	}
	return nil
}


