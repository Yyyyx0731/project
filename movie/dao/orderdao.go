package dao

import (
	"fmt"
	"movie/model"
	"movie/utils"
	"strconv"
	"strings"
	"time"
)

func GetMyOrder(userId int)([]*model.Order){
	var orders []*model.Order
	//var orderItems []*model.TimeAndSeat
	//根据用户id得到所有订单
	sqlStr := "select * from orders where userID=?"
	rows, err := utils.Db.Query(sqlStr, userId)
	if err != nil {
		fmt.Println(err)
		return nil
	}
	for rows.Next() {
		order := &model.Order{}
		//读取订单信息
		rows.Scan(&order.ID,&order.Date,&order.Count,&order.Amount,&order.UserID,&order.Pay)
		if order.ID=="" {
			continue
		}
		//根据某个订单id获取该订单中所有订单项详情
		sqlStr1 := "select timeID,seat_row,seat_column,price from orderitems where orderID=?"
		rows1, err := utils.Db.Query(sqlStr1, order.ID)
		if err != nil {
			fmt.Println(err)
			return nil
		}
		for rows1.Next() {
			orderItem := &model.TimeAndSeat{}
			//读取订单项详情
			rows1.Scan(&orderItem.TimeID,&orderItem.Row,&orderItem.Column,&orderItem.Price)
			time1 := GetTimeByTimeID(orderItem.TimeID)
			movie,_ := GetMovieByID(time1.MovieID)
			orderItem.MovieName = movie.Name
			orderItem.TimeLong = movie.Time
			orderItem.Date = time1.Date
			orderItem.StartTime = time1.StartTime

			//now:=time.Now()
			//timeStr := strconv.Itoa(movie.Time)
			//t, _ := time.ParseDuration(timeStr+"m")
			//t1 := now.Add(t)
			//timeNow:=t1.Format("15:04")
			//orderItem.EndTime = timeNow

			//计算结束时间
			parse,_ := time.Parse("15:04",orderItem.StartTime)
			long := movie.Time
			timeStr := strconv.Itoa(long)
			t, _ := time.ParseDuration(timeStr+"m")
			mm1 := parse.Add(t)
			timeNow:=mm1.Format("15:04")
			//fmt.Println(timeNow)
			orderItem.EndTime = timeNow

			orderItem.Cinema = GetCinemaByRoomID(time1.RoomID).Name
			orderItem.Room = GetRoomByRoomID(time1.RoomID).Name
			//把该订单项加入该用户订单的切片中
			order.OrderItems= append(order.OrderItems,orderItem)
		}

		//把该订单添加到所有订单的切片中
		orders = append(orders,order)
	}

	return orders
}


//创建订单
func CreateOrder(str []string,userId int,timeId int) *model.Order{
	var order *model.Order
	strLen := len(str)
	str = str[:strLen-1]
	var add []string
	//var add []string
	//cnt := 0

	//fmt.Println("lenStr:",len(str))
	//fmt.Println("lenAdd:",len(add))
	//fmt.Println("str:",str)
	for _,seatStr := range str{
		seatxy := strings.Split(seatStr,"#")
		//fmt.Println("xy：",seatxy[0],seatxy[1])
		if seatxy[0]=="add"{
			//添加购物项
			add=append(add,seatxy[1])
			//fmt.Println("add：",seatxy[1])
		}else if seatxy[0]=="del"{
			//删除购物项
			for k,v := range add{
				if v==seatxy[1]{
					add = append(add[:k],add[k+1:]...)
					//fmt.Println("flag:",k)
					break
				}
			}
			//fmt.Println("del：",seatxy[1],)
		}
		//fmt.Println("adds0:",add)
	}
	//fmt.Println("8888888")
	//fmt.Println("adds:",add)
	AddOrder(add,userId,timeId)
	return order
}

//func CreateOrder1(userId int,timeId int) *model.Order{
//	orderId := utils.CreateUUID()
//	now := time.Now()
//	date := now.Format("2023-01-02")
//	order := &model.Order{
//		orderId,
//		session.UserID,
//		date,
//
//	}
//}


func AddOrder(add []string,userId int,timeId int){
	orderId := utils.CreateUUID()
	time1 := GetTimeByTimeID(timeId)
	//fmt.Println(time1)
	//date := time1.Date
	now := time.Now()
	date := now.Format("2006-01-02")
	price := time1.Price
	count := len(add)
	amount := price*float64(count)
	sqlStr := "insert into orders(id, date, count, amount, userID,pay) values(?,?,?,?,?,?) "
	_,err:=utils.Db.Exec(sqlStr,orderId,date,count,amount,userId,0)
	if err!=nil {
		fmt.Println(err)
		return
	}
	for _,v := range add{
		str := strings.Split(v,",")
		r := str[0]
		c := str[1]
		row,_ := strconv.Atoi(r)
		column,_ := strconv.Atoi(c)
		AddOrderItems(orderId,timeId,row,column,price)
		UpdateSeatStatus(time1.RoomID,row,column,1)
	}

}

func AddOrderItems(orderId string,timeId int,row int,column int,price float64){
	sqlStr := "insert into orderitems(orderID, timeID, seat_row, seat_column, price) values(?,?,?,?,?)"
	_,err:=utils.Db.Exec(sqlStr,orderId,timeId,row,column,price)
	if err!=nil {
		fmt.Println(err)
		return
	}
}

////根据订单号获取订单详情
//func GetOrderByID(orderId int) *model.Order{
//	var order model.TimeAndSeat
//	sqlStr := "select  orderID, timeID, seat_row, seat_column, price from orderitems where orderID=?"
//	err:=utils.Db.QueryRow(sqlStr,orderId).Scan(&)
//	if err != nil {
//		fmt.Println("query:",err)
//		return nil
//	}
//	return &order
//}

//取消订单
func DeleteOrder(orderId string){
	DeleteOrderItems(orderId)
	sqlStr := `delete from orders  where id = ?`
	_, err := utils.Db.Exec(sqlStr, orderId)
	if err != nil {
		fmt.Println("delete:", err)
		return
	}
}

//删除订单项
func DeleteOrderItems(orderId string){
	sql := "select timeID,seat_row,seat_column from orderitems where orderID=?"
	//执行
	rows, err := utils.Db.Query(sql, orderId)
	if err != nil {
		fmt.Println(err)
		return
	}
	for rows.Next() {
		timeId := 0
		row := 0
		column := 0
		rows.Scan(&timeId,row,column)
		roomId := GetRoomIDByTimeID(timeId)
		UpdateSeatStatus(roomId,row,column,0)
	}

	sqlStr := `delete from orderitems  where orderID = ?`
	_, err = utils.Db.Exec(sqlStr, orderId)
	if err != nil {
		fmt.Println("delete:", err)
		return
	}
}

func UpdatePay (orderId string){
	sqlStr := "update orders set pay = ? where id = ? "

	_, err := utils.Db.Exec(sqlStr, 1,orderId)
	if err != nil {
		fmt.Println("exec err:",err)
		return
	}
}

func GetOrderPayByOderID(orderId string) int{
	var pay int
	sqlStr:="select pay from orders where id =?"

	err:=utils.Db.QueryRow(sqlStr,orderId).Scan(&pay)
	if err != nil {
		fmt.Println("query:",err)
	}
	return pay
}

