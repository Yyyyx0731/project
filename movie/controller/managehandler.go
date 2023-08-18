package controller

import (
	"encoding/json"
	"fmt"
	"html/template"
	"movie/dao"
	"movie/model"
	"movie/utils"
	"net/http"
	"strconv"
	"strings"
)


//验证后台管理密钥
func CheckKey(w http.ResponseWriter,r *http.Request)  {
	//获取用户名和密码
	cinemaName := r.PostFormValue("cinema")
	key := r.PostFormValue("key")
	cinema := dao.CheckCinemaNameAndKey(cinemaName,key)
	if cinema.ID > 0 {   //key正确

		//用户名和密码正确
		//生成UUID作为Session的id
		uuid := utils.CreateUUID()
		//创建一个Session
		sess := &model.Session1{
			SessionID: uuid,
			CinemaName:  cinemaName,
			CinemaID:    cinema.ID,
		}
		//将Session保存到数据库中
		dao.AddSession1(sess)
		//创建一个Cookie，让它与Session相关联
		cookie := http.Cookie{
			Name:     "cinema",
			Value:    uuid,
			HttpOnly: true,
		}
		//将cookie发送给浏览器
		http.SetCookie(w, &cookie)

		//获取电影类型(正在热映/即将上映)
		typeN:= r.FormValue("type")
		var typeNow int
		if typeN=="" {
			typeNow=0
		}else{
			typeNow,_= strconv.Atoi(typeN)
		}

		movies0, movies1 := dao.GetMoviesByType()

		movieType := &model.MovieType{
			typeNow,
			cinemaName,
			movies0,
			movies1,
		}

		t := template.Must(template.ParseFiles("views/pages/manager/manage.html"))
		t.Execute(w,movieType)
	}else {		//错误
		//用户名或密码不正确
		t := template.Must(template.ParseFiles("views/pages/manager/checkKey.html"))
		t.Execute(w, "影城名或密码不正确！")
	}


}

//后台管理
func Manage(w http.ResponseWriter,r *http.Request)  {
	cinemaName := r.FormValue("cinemaName")
	if cinemaName=="" {
		_,session1 := CinemaIsLogin(r)
		//fmt.Println(session1)
		cinemaName = session1.CinemaName
	}

	//获取类型
	typeN:= r.FormValue("type")
	var typeNow int
	if typeN=="" {
		typeNow=0
	}else{
		typeNow,_= strconv.Atoi(typeN)
	}

	movies0, movies1 := dao.GetMoviesByType()

	movieType := &model.MovieType{
		typeNow,
		cinemaName,
		movies0,
		movies1,
	}

	t := template.Must(template.ParseFiles("views/pages/manager/manage.html"))
	t.Execute(w,movieType)
}

//注册影城
func RegisterCinema(w http.ResponseWriter,r *http.Request)  {
	//获取用户名和密码
	cinemaName := r.PostFormValue("cinema")
	password := r.PostFormValue("key")
	address := r.PostFormValue("address")

	cinema := dao.CheckCinemaNameAndKey(cinemaName,password)
	if cinema.ID > 0 { //查到了该影城 证明已经注册过
		t := template.Must(template.ParseFiles("views/pages/manager/registerCinema.html"))
		t.Execute(w,"该影城已注册！")
	}else {	//未注册
		dao.AddCinema(cinemaName,password,address)
		//fmt.Println("cinema1:",cinema1)

		cinema1 := dao.GetCinemaByName(cinemaName)

		//用户名和密码正确
		//生成UUID作为Session的id
		uuid := utils.CreateUUID()
		//创建一个Session
		sess := &model.Session1{
			SessionID: uuid,
			CinemaName:  cinemaName,
			CinemaID:    cinema1.ID,
		}
		//fmt.Println("sess:",sess)
		//将Session保存到数据库中
		err := dao.AddSession1(sess)
		if err!= nil{
			fmt.Println(err)
		}
		//fmt.Println(err)
		//fmt.Println("sess:",sess)
		//创建一个Cookie，让它与Session相关联
		cookie := http.Cookie{
			Name:     "cinema",
			Value:    uuid,
			HttpOnly: true,
		}
		//将cookie发送给浏览器
		http.SetCookie(w, &cookie)

		t := template.Must(template.ParseFiles("views/pages/manager/register_success1.html"))
		t.Execute(w,cinemaName)
	}

}


func CheckCinemaName(w http.ResponseWriter,r *http.Request)  {
	//获取用户输入的用户名
	cinemaName := r.PostFormValue("cinemaName")
	//fmt.Println(cinemaName)
	//password := r.PostFormValue("key")
	//调用userdao中验证用户名和密码的方法
	cinema := dao.CheckCinemaName(cinemaName)
	//fmt.Println(cinema)
	if cinema.ID > 0 {
		//已存在
		w.Write([]byte("<font style='color:red'>该影城已注册！</font>"))
	} else {
		//用户名可用
		w.Write([]byte("<font style='color:green'>影城名可用</font>"))
	}
}

func CheckMovieExist(w http.ResponseWriter,r *http.Request){
	movieName := r.FormValue("movieName")
	movieId := dao.GetMovieIdByName(movieName)
	if movieId>0 {
		//已存在
		w.Write([]byte("<font style='color:red'>该电影已存在！请勿重复添加</font>"))
	}
}


//场次管理
func ManageTime(w http.ResponseWriter,r *http.Request)  {
	_,session1 := CinemaIsLogin(r)
	cinemaName:=session1.CinemaName
	//获得该影院所有场次切片
	times1 := dao.GetTimesByCinemaName(cinemaName)
	manageTime := &model.ManageTime{
		cinemaName,
		times1,
	}
	t := template.Must(template.ParseFiles("views/pages/manager/manageTime.html"))
	t.Execute(w,manageTime)
}

//影厅管理
func ManageRoom(w http.ResponseWriter,r *http.Request)  {
	_,session1 := CinemaIsLogin(r)
	cinemaName:=session1.CinemaName
	cinemaId := dao.GetCinemaByName(cinemaName).ID
	rooms := dao.GetRoomByCinemaID(cinemaId)
	manageRoom := &model.ManageRoom{
		rooms,
		cinemaName,
	}
	t := template.Must(template.ParseFiles("views/pages/manager/manageRoom.html"))
	t.Execute(w,manageRoom)
}


func ToModifyRoom (w http.ResponseWriter,r *http.Request){
	roomIdStr := r.FormValue("roomId")
	roomId,_ := strconv.Atoi(roomIdStr)
	//fmt.Println(time)
	if roomId > 0 {	//更新
		room := dao.GetRoomByRoomID(roomId)
		roomName := room.Name
		row := room.Row
		column := room.Column
		modifyRoom := &model.Room{
			roomId,
			roomName,
			row,
			column,
			0,
		}

		t := template.Must(template.ParseFiles("views/pages/manager/modifyRoom.html"))
		t.Execute(w,modifyRoom)
	}else {	//添加
		t := template.Must(template.ParseFiles("views/pages/manager/modifyRoom.html"))
		t.Execute(w,"")
	}
}


func ToModifyTime (w http.ResponseWriter,r *http.Request){
	timeIdStr := r.FormValue("timeId")
	timeId,_ := strconv.Atoi(timeIdStr)
	//fmt.Println(time)
	if timeId > 0 {	//更新
		time := dao.GetTimeByTimeID(timeId)
		movieId := dao.GetMovieIDByTimeID(timeId)
		movie,_ := dao.GetMovieByID(movieId)
		movieName := movie.Name
		//version := movie.Version
		date := time.Date
		time0 := time.StartTime
		price := time.Price
		roomId := time.RoomID
		roomName := dao.GetRoomByRoomID(roomId).Name
		_,session:= CinemaIsLogin(r)
		modifyTime := &model.ModifyTime{
			timeId,
			movieName,
			//version,
			date+"T"+time0,
			price,
			roomName,
			session.CinemaName,
			//true,
		}
		t := template.Must(template.ParseFiles("views/pages/manager/modifyTime.html"))
		t.Execute(w,modifyTime)
	}else {	//添加
		t := template.Must(template.ParseFiles("views/pages/manager/modifyTime.html"))
		t.Execute(w,"")
	}
}


//添加或修改影厅信息
func ModifyRoom(w http.ResponseWriter,r *http.Request)  {
	roomIdStr := r.FormValue("roomId")
	roomName := r.FormValue("name")
	//fmt.Println(roomName)
	rowStr := r.FormValue("row")
	columnStr := r.FormValue("column")

	roomId,_ := strconv.Atoi(roomIdStr)
	row,_ := strconv.Atoi(rowStr)
	column,_ := strconv.Atoi(columnStr)

	if roomId>0 {
		dao.UpdateRoom(roomId,roomName,row,column)
		dao.DeleteAndSetSeats(roomId,row,column)
	}else{
		_,session := CinemaIsLogin(r)
		cinema := dao.GetCinemaByName(session.CinemaName)
		cinemaId := cinema.ID
		dao.AddRoom(roomName,row,column,cinemaId)
		roomId = dao.GetRoomIDByName(roomName)
		dao.AddSeats(roomId,row,column)
	}

	ManageRoom(w,r)
}


func UpdateRoomInfo(w http.ResponseWriter,r *http.Request){
	rStr := r.FormValue("row")
	cStr := r.FormValue("column")
	row,_ := strconv.Atoi(rStr)
	column,_ := strconv.Atoi(cStr)
	//fmt.Println(row,column)
	data := &model.Data{
		row*column,
	}
	//将data转换为json字符串
	json, _ := json.Marshal(data)
	//响应到浏览器
	w.Write(json)
}


func DeleteRoom(w http.ResponseWriter,r *http.Request){
	roomIdStr := r.FormValue("roomId")
	roomId,_ := strconv.Atoi(roomIdStr)
	dao.DeleteSeatByRoomID(roomId)
	dao.DeleteRoomByRoomId(roomId)
	ManageRoom(w,r)
}


//增加或修改场次信息
func ModifyTime(w http.ResponseWriter,r *http.Request)  {
	timeIdStr := r.FormValue("timeId")
	movieName := r.FormValue("name")
	//version:= r.FormValue("version")
	timestr := r.FormValue("time")
	priceStr := r.FormValue("price")
	roomName := r.FormValue("room")

	//转换数据类型
	timeId,_ := strconv.Atoi(timeIdStr)
	timeStr := strings.Split(timestr,"T")
	date :=timeStr[0]
	time := timeStr[1]

	price,_ := strconv.ParseFloat(priceStr,64)

	//_,session:=CinemaIsLogin(r)
	//cinemaName := session.CinemaName
	//
	//modifyTime := &model.ModifyTime{
	//	timeId,
	//	movieName,
	//	version,
	//	timestr,
	//	price,
	//	roomName,
	//	cinemaName,
	//	true,
	//}
	//
	if timeId>0 {
		movieId := dao.GetMovieIDByTimeID(timeId)
		roomId := dao.GetRoomIDByName(roomName)
		//fmt.Println()
		dao.UpdateTime(timeId,movieId,date,time,price,roomId)
	}else{
		movieId := dao.GetMovieIdByName(movieName)
		roomId := dao.GetRoomIDByName(roomName)
		dao.AddTime(movieId,date,time,price,roomId)
	}

	ManageTime(w,r)
}


//删场次
func DeleteTime(w http.ResponseWriter,r *http.Request)  {
	timeIdStr := r.FormValue("timeId")
	timeId,_ := strconv.Atoi(timeIdStr)
	dao.DeleteTimeByID(timeId)

	ManageTime(w,r)
}


//添加电影
func AddMovie(w http.ResponseWriter,r *http.Request)  {
	cinemaName := r.FormValue("name")
	director := r.FormValue("director")
	movieType := r.FormValue("type")
	timeStr := r.FormValue("time")
	onlineTime := r.FormValue("online")
	version := r.FormValue("version")
	where := r.FormValue("where")
	introduce := r.FormValue("introduce")
	imgPath := r.FormValue("imgPath")

	time,_ := strconv.Atoi(timeStr)

 	if cinemaName!="" {
		dao.AddMovie(cinemaName,director,movieType,time,onlineTime,version,where,introduce,imgPath)
	}

	t := template.Must(template.ParseFiles("views/pages/manager/addMovie.html"))
	t.Execute(w,cinemaName)
}


//删除电影
func DeleteMovie(w http.ResponseWriter,r *http.Request)  {
	movieID := r.FormValue("movieId")
	movieId,_ := strconv.Atoi(movieID)

	dao.DeleteMovie(movieId)

	//cinema := dao.
	//cinemaName := cinema.Name
	movieName := r.FormValue("movieName")
	cinemaName:=""
	if movieName=="" {
		_,session1 := CinemaIsLogin(r)
		cinemaName=session1.CinemaName
	}

	//获取类型
	typeN:= r.FormValue("type")
	var typeNow int
	if typeN=="" {
		typeNow=0
	}else{
		typeNow,_= strconv.Atoi(typeN)
	}

	movies0, movies1 := dao.GetMoviesByType()

	movieType := &model.MovieType{
		typeNow,
		cinemaName,
		movies0,
		movies1,
	}

	t := template.Must(template.ParseFiles("views/pages/manager/manage.html"))
	t.Execute(w,movieType)
}


//IsLogin 判断cinema是否已经登录 false 没有登录 true 已经登录
func CinemaIsLogin(r *http.Request) (bool, *model.Session1) {
	//根据Cookie的name获取Cookie
	cookie, _ := r.Cookie("cinema")
	if cookie != nil {
		//获取Cookie的value(sessionID)
		cookieValue := cookie.Value
		//根据cookieValue去数据库中查询与之对应的Session
		session1, _ := dao.GetSession1(cookieValue)
		if session1.CinemaID > 0 {
			//已经登录
			return true, session1
		}
	}
	//没有登录
	return false, nil
}

//Logout cinema退出登录的函数
func CinemaLogout(w http.ResponseWriter, r *http.Request) {
	//获取Cookie
	cookie, _ := r.Cookie("cinema")
	if cookie != nil {
		//获取cookie的value值(即sessionID)
		cookieValue := cookie.Value
		//fmt.Println(cookieValue)
		//删除数据库中与之对应的Session
		dao.DeleteSession1(cookieValue)
		//设置cookie失效
		cookie.MaxAge = -1
		//将修改之后的cookie发送给浏览器
		http.SetCookie(w, cookie)
	}
	//去首页
	Index(w, r)
}