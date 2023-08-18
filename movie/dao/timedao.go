package dao

import (
	"fmt"
	"movie/model"
	"movie/utils"
	"sort"
	"strconv"
	"time"
)

func GetTimeByTimeID(id int)(*model.Time){
	var time model.Time
	//fmt.Println(id)
	sqlStr := "select * from time where id=?"
	err:=utils.Db.QueryRow(sqlStr,id).Scan(&time.ID,&time.MovieID,&time.Date,&time.StartTime,&time.Price,&time.RoomID)
	if err != nil {
		//fmt.Println("query:",err)
		return nil
	}
	return &time
}




////声明一个Hero结构体切片类型
//type TimeInfo []*TimeInfo
//
////切片实现Interface 接口的三个方法
////1.Len() ：返回切片的大小
//func (hs TimeInfo) Len() int {
//	return len(hs)
//}
//
////2.Less(i, j int) :决定使用什么规则进行排序
//func (hs TimeInfo) Less(i, j int) bool {
//	return hs[i].StartTime < hs[j].StartTime     // 按从小到大排序
//	//return hs[i].Name > hs[j].Name  // 按Hero的Name从大到小排序
//}
//
////3.Swap(i, j int) :Less(i, j int)返回true时进行交换
//func (hs TimeInfo) Swap(i, j int) {
//	hs[i], hs[j] = hs[j], hs[i]
//}

func GetTimePage(movieId,cinemaId,date int)([]*model.TimeInfo){
	var times []*model.TimeInfo

	movie,_ := GetMovieByID(movieId)
	long := movie.Time

	//得到该影城所有的房间id 并存入切片
	rooms := GetRoomByCinemaID(cinemaId)
//fmt.Println(rooms)
	now:=time.Now()
	year := now.Year()
	month := int(now.Month())
	day := now.Day()
	if date==1 {
		day = day+1
	}else if date==2 {
		day = day+2
	}
	yearStr := strconv.Itoa(year)
	monthStr := strconv.Itoa(month)
	dayStr := strconv.Itoa(day)
	var dateStr string
	if month<10 {
		dateStr = yearStr+"-0"+monthStr+"-"+dayStr
	}else{
		dateStr = yearStr+"-"+monthStr+"-"+dayStr
	}


	//根据日期和电影id查找符合的场次
	for _,room := range rooms {
		//fmt.Println(dateStr,movieId,room.ID)
		//fmt.Println(room)
		sqlStr := "select id,time,price from time where date=? and movie_ID=? and roomID=? "
		//执行
		rows, err := utils.Db.Query(sqlStr,dateStr,movieId,room.ID)
		if err != nil {
			fmt.Println(err)
			return nil
		}
		for rows.Next() {
			time0 := &model.TimeInfo{}
			rows.Scan(&time0.TimeID,&time0.StartTime,&time0.Price)

			//计算结束时间
			parse,_ := time.Parse("15:04",time0.StartTime)
			timeStr := strconv.Itoa(long)
			t, _ := time.ParseDuration(timeStr+"m")
			mm1 := parse.Add(t)
			timeNow:=mm1.Format("15:04")
			//fmt.Println(timeNow)
			time0.EndTime = timeNow

			time0.Version=movie.Version
			time0.RoomName = room.Name

			//添加到切片中
			times = append(times,time0)
			//fmt.Println(time0)
		}
	}
	sort.SliceStable(times, func(i int, j int) bool {
		return times[i].StartTime< times[j].StartTime
	})
	return times
}


func GetMovieIDByTimeID(timeId int) int{
	var movieId int
	sqlStr := "select movie_ID from time where id=?"
	err:=utils.Db.QueryRow(sqlStr,timeId).Scan(&movieId)
	if err != nil {
		fmt.Println("query:",err)
	}
	return movieId
}

func GetPriceByTimeID(timeId int)float64{
	var price float64
	sqlStr := "select price from time where id=?"
	err:=utils.Db.QueryRow(sqlStr,timeId).Scan(&price)
	if err != nil {
		fmt.Println("query:",err)
	}
	return price
}


func GetTimesByCinemaName(cinemaName string) []*model.Time1{
	//得到该影城的所有roomId
	roomIds := GetRoomIDByCinemaName(cinemaName)

	var Times []*model.Time1

	for _,roomId := range roomIds{
		sqlStr := "select * from time where roomID=?"
		//执行
		rows, err := utils.Db.Query(sqlStr, roomId)
		if err != nil {
			fmt.Println(err)
			return nil
		}
		var times []*model.Time1
		for rows.Next() {
			time0 := &model.Time1{}
			rows.Scan(&time0.ID,&time0.MovieID,&time0.Date,&time0.StartTime,&time0.Price,&time0.RoomID)

			movie,_ := GetMovieByID(time0.MovieID)
			time0.MovieName = movie.Name
			time0.RoomName = GetRoomByRoomID(roomId).Name
			//计算结束时间
			long := movie.Time
			parse,_ := time.Parse("15:04",time0.StartTime)
			timeStr := strconv.Itoa(long)
			t, _ := time.ParseDuration(timeStr+"m")
			mm1 := parse.Add(t)
			timeNow:=mm1.Format("15:04")
			time0.EndTime = timeNow

			//添加到切片中
			times = append(times,time0)
			//fmt.Println(time0)
		}
		Times=append(Times,times...)
	}
	sort.SliceStable(Times, func(i int, j int) bool {
		ti := Times[i].Date+Times[i].StartTime
		tj := Times[j].Date+Times[j].StartTime
		return ti<tj
	})
	return Times
}


func AddTime(movieId int,date string,timeStr string,price float64,roomId int){
	sqlStr:="insert into time(movie_ID, date, time, price, roomID) values(?,?,?,?,?)"

	_,err:=utils.Db.Exec(sqlStr,movieId,date,timeStr,price,roomId)
	if err!=nil {
		fmt.Println(err)
	}
}


func UpdateTime(timeId int,movieId int,date string,timeStr string,price float64,roomId int){
	sqlStr := "update time set movie_ID=?,date=?,time=?,price=?,roomID=? where id=? "

	_, err := utils.Db.Exec(sqlStr,movieId,date,timeStr,price,roomId,timeId)
	if err != nil {
		fmt.Println("exec err:",err)
		return
	}
}

func DeleteTimeByID(timeId int){
	sqlStr := `delete from time where id = ?`

	_, err :=utils.Db.Exec(sqlStr, timeId)
	if err != nil {
		fmt.Println("delete:", err)
		return
	}
}
