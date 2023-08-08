package utils

import (
	"database/sql"
	_ "github.com/go-sql-driver/mysql"
)

var Db *sql.DB
var err error

func init()  {
	Db,err = sql.Open("mysql","root:hyx20040731@tcp(localhost:3306)/bookstore")
	if err!=nil {
		panic(err.Error())
	}

}
