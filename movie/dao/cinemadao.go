package dao

import (
	"fmt"
	"movie/model"
	"movie/utils"
)

func GetCinemaByRoomID(roomID int)(*model.Cinema){
	var cinema model.Cinema
	sqlStr := "select cinemaID from room where id=?"
	err:=utils.Db.QueryRow(sqlStr,roomID).Scan(&cinema.ID)
	//fmt.Println(cinema.ID)
	if err != nil {
		fmt.Println("query:",err)
		return nil
	}
	sqlStr1 := "select name,password,address from cinema where id=?"
	err =utils.Db.QueryRow(sqlStr1,cinema.ID).Scan(&cinema.Name,&cinema.Password,&cinema.Address)
	if err != nil {
		fmt.Println("query:",err)
		return nil
	}
	return &cinema
}

func GetRoomByRoomID(roomID int)(*model.Room){
	var room model.Room
	//fmt.Println(roomID)
	sqlStr := "select * from room where id=?"
	err:=utils.Db.QueryRow(sqlStr,roomID).Scan(&room.ID,&room.Name,&room.Row,&room.Column,&room.CinemaID)
	//fmt.Println(room.Row)
	if err != nil {
		fmt.Println("query:",err)
		return nil
	}
	return &room
}


func CheckCinemaNameAndKey(cinemaName,key string) *model.Cinema{
	var cinema model.Cinema
	sqlStr := "select * from cinema where name=? and password=?"
	_=utils.Db.QueryRow(sqlStr,cinemaName,key).Scan(&cinema.ID,&cinema.Name,&cinema.Password,&cinema.Address)
	return &cinema
}

func CheckCinemaName(cinemaName string) *model.Cinema{
	var cinema model.Cinema
	sqlStr := "select * from cinema where name=? "
	_=utils.Db.QueryRow(sqlStr,cinemaName).Scan(&cinema.ID,&cinema.Name,&cinema.Password,&cinema.Address)
	return &cinema
}

func AddCinema(cinemaName,password,address string) {
	sqlStr:="insert into cinema(name,password,address) values(?,?,?)"

	_,err:=utils.Db.Exec(sqlStr,cinemaName,password,address)
	if err!=nil {
		fmt.Println(err)
	}
}


func GetCinemaByID(cinemaId int) *model.Cinema{
	var cinema model.Cinema
	sqlStr := "select * from cinema where id=? "
	_=utils.Db.QueryRow(sqlStr,cinemaId).Scan(&cinema.ID,&cinema.Name,&cinema.Password,&cinema.Address)
	return &cinema
}

func GetCinemaByName(cinemaName string)*model.Cinema{
	var cinema model.Cinema
	sqlStr := "select * from cinema where name=? "
	_=utils.Db.QueryRow(sqlStr,cinemaName).Scan(&cinema.ID,&cinema.Name,&cinema.Password,&cinema.Address)
	return &cinema
}