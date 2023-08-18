package dao

import (
	"fmt"
	"movie/model"
	"movie/utils"
)

func UpdateSeatStatus(roomId,row,column int){
	sqlStr := "update seats set statues = ? where roomID = ? and seat_row=? and  seat_column=?"

	_, err := utils.Db.Exec(sqlStr, 1,roomId,row,column)
	if err != nil {
		fmt.Println("exec err:",err)
		return
	}
}

func GetSeatsByRoomID(roomId int) []*model.Seat{
	var seats []*model.Seat
	sqlStr := "select seat_row,seat_column,statues,first from seats where roomID=?"
	//执行
	rows, err := utils.Db.Query(sqlStr, roomId)
	if err != nil {
		fmt.Println(err)
		return nil
	}
	for rows.Next() {
		seat := &model.Seat{}
		rows.Scan(&seat.Row,&seat.Column,&seat.Status,&seat.First)
		//添加到切片中
		seats = append(seats,seat)
	}
	return seats
}


func DeleteSeatByRoomID(roomId int){
	sqlStr := `delete from seats  where roomID = ?`
	_, err := utils.Db.Exec(sqlStr, roomId)
	if err != nil {
		fmt.Println("delete seats:", err)
		return
	}
}


func DeleteAndSetSeats(roomId,row,column int){
	DeleteSeatByRoomID(roomId)
	AddSeats(roomId,row,column)
}


func AddSeats(roomId,row,column int){
	sqlStr:="insert into seats(seat_row,seat_column,statues,roomID,first) values(?,?,?,?,?)"

	for i:=1;i<=row;i++ {
		for j:=1;j<=column;j++ {
			var flag int
			if j==1 {
				flag=1
			}else{
				flag=0
			}
			_,err:=utils.Db.Exec(sqlStr,i,j,0,roomId,flag)
			if err!=nil {
				fmt.Println("i,j:",err)
			}
		}
	}
}
