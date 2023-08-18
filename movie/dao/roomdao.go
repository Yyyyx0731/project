package dao

import (
	"fmt"
	"movie/utils"
)

func GetRoomIDByName(roomName string)int{
	var roomId int
	sqlStr := "select id from room where name=?"
	err:=utils.Db.QueryRow(sqlStr,roomName).Scan(&roomId)
	if err != nil {
		fmt.Println("query:",err)
	}
	return roomId
}

func GetRowAndColumnByRoomID(roomId int)(int,int){
	var row,column int
	sqlStr := "select seat_row,seat_column from room where id=?"
	err:=utils.Db.QueryRow(sqlStr,roomId).Scan(&row,&column)
	if err != nil {
		fmt.Println("query:",err)
	}
	return row,column
}


func GetRoomIDByCinemaName(cinemaName string) []int{
	var roomIds []int
	var cinemaId int
	sqlStr := "select id from cinema where name=?"
	err:=utils.Db.QueryRow(sqlStr,cinemaName).Scan(&cinemaId)
	if err != nil {
		fmt.Println("query:",err)
	}

	sqlStr1 := "select id from room where cinemaID=?"
	//执行
	rows1, err := utils.Db.Query(sqlStr1, cinemaId)
	if err != nil {
		fmt.Println(err)
		return nil
	}
	for rows1.Next() {
		var roomId int
		rows1.Scan(&roomId)
		//添加到切片中
		roomIds=append(roomIds,roomId)
	}
	return roomIds
}

func UpdateRoom(roomId int,name string,row int,column int){
	sqlStr := "update room set name=?,seat_row=?,seat_column=? where id=? "

	_, err := utils.Db.Exec(sqlStr, name,row,column,roomId)
	if err != nil {
		fmt.Println("update room:",err)
		return
	}
}

func AddRoom(roomName string,row int,column int,cinemaId int){
	sqlStr:="insert into room(name,seat_row,seat_column,cinemaID) values(?,?,?,?)"
	_, err := utils.Db.Exec(sqlStr, roomName,row,column,cinemaId)
	if err!=nil {
		fmt.Println("add room:",err)
	}
}

func DeleteRoomByRoomId(roomId int){
	sqlStr := `delete from room  where id = ?`
	_, err := utils.Db.Exec(sqlStr, roomId)
	if err != nil {
		fmt.Println("delete:", err)
		return
	}
}
