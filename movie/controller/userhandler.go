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
)

func Index(w http.ResponseWriter,r *http.Request)  {
	//var mainPage *model.MainPage
	mainPage,_:= dao.GetMainPageMovie()
	//fmt.Println(mainPage)
	//调用IsLogin函数判断是否已经登录
	flag, session := IsLogin(r)
	if flag {
		//已经登录，设置page中的IsLogin字段和Username的字段值
		mainPage.IsLogin = true
		mainPage.Username = session.UserName
	}
	//解析模板文件
	t := template.Must(template.ParseFiles("views/index.html"))
	//执行
	t.Execute(w,mainPage)
}

func Login(w http.ResponseWriter,r *http.Request)  {
	//判断是否已经登录
	flag, _ := IsLogin(r)
	if flag {	//已经登录
		//已经登录则不再重复提交表单，避免session表中多生成一个改用户的session
		Index(w, r)//去首页
	} else {	//未登录
		//获取用户名和密码
		username := r.PostFormValue("username")
		password := r.PostFormValue("password")
		//调用userdao中验证用户名和密码的方法
		user, _ := dao.CheckUserNameAndPassword(username, password)

		if user.ID != 0 {
			//用户名和密码正确
			//生成UUID作为Session的id
			uuid := utils.CreateUUID()
			//创建一个Session
			sess := &model.Session{
				SessionID: uuid,
				UserName:  user.Username,
				UserID:    user.ID,
			}
			//将Session保存到数据库中
			dao.AddSession(sess)
			//创建一个Cookie，让它与Session相关联
			cookie := http.Cookie{
				Name:     "user",
				Value:    uuid,
				HttpOnly: true,
			}
			//将cookie发送给浏览器
			http.SetCookie(w, &cookie)
			t := template.Must(template.ParseFiles("views/pages/user/login_success.html"))
			t.Execute(w, user)
		} else {
			//用户名或密码不正确
			t := template.Must(template.ParseFiles("views/pages/user/login.html"))
			t.Execute(w, "用户名或密码不正确！")
		}
	}
	//t := template.Must(template.ParseFiles("views/index.html"))
	//t.Execute(w,"")
}

func Register(w http.ResponseWriter,r *http.Request)  {
	//获取用户名和密码
	username := r.PostFormValue("username")
	password := r.PostFormValue("password")
	tel := r.PostFormValue("tel")
	//调用userdao中验证用户名和密码的方法
	user, _ := dao.CheckUserName(username)

	if user.ID > 0 {
		//用户名已存在
		t := template.Must(template.ParseFiles("views/pages/user/register.html"))
		t.Execute(w, "用户名已存在！")
	} else {
		//用户名可用，将用户信息保存到数据库中
		dao.SaveUser(username, password, tel)
		//用户名和密码正确
		t := template.Must(template.ParseFiles("views/pages/user/register_success.html"))
		t.Execute(w, user)

	}
	//t := template.Must(template.ParseFiles("views/index.html"))
	//t.Execute(w,"")
}

func Movies(w http.ResponseWriter,r *http.Request)  {
	//获取页码
	pageNo := r.FormValue("pageNo")
	if pageNo == "" {
		pageNo = "1"
	}
	pageNow,_ := strconv.Atoi(pageNo)

	//获取类型
	typeN:= r.FormValue("type")
	var typeNow int
	if typeN=="" {
		typeNow = 0
	}else {
		typeNow,_= strconv.Atoi(typeN)
	}

	movie0,movie1,totalPage0,totalPage1,totalRecord0,totalRecord1 := dao.GetMovieByPage(pageNow)

	//判断是否登录
	flag, session:= IsLogin(r)

	if flag {
		//已经登录
		moviePage := &model.MoviePage{
			movie0,
			movie1,
			session,
			true,
			typeNow,
			pageNow,
			totalPage0,
			totalPage1,
			totalRecord0,
			totalRecord1,
		}
		//moviePage.Session = session
		t := template.Must(template.ParseFiles("views/pages/user/movies.html"))
		t.Execute(w,moviePage)
	}else {
		//未登录
		moviePage := &model.MoviePage{
			movie0,
			movie1,
			session,
			false,
			typeNow,
			pageNow,
			totalPage0,
			totalPage1,
			totalRecord0,
			totalRecord1,
		}
		t := template.Must(template.ParseFiles("views/pages/user/movies.html"))
		t.Execute(w,moviePage)
	}

}



//去评分
func Eva(w http.ResponseWriter,r *http.Request)  {
	//判断是否登录
	flag, _ := IsLogin(r)
	if flag {
		//已经登录
		movieID := r.FormValue("movieId")
		Id ,err:= strconv.Atoi(movieID)
		if err!=nil {
			fmt.Println(err)
		}
		movie,_ := dao.GetMovieByID(Id)
		t := template.Must(template.ParseFiles("views/pages/user/eva.html"))
		t.Execute(w,movie)
	}else {
		//没有登录
		//w.Write([]byte("请先登录！"))
		t := template.Must(template.ParseFiles("views/pages/user/login.html"))
		t.Execute(w,"")
	}
}


//去榜单
func Rank(w http.ResponseWriter,r *http.Request)  {
	//获取类型
	rtype:= r.FormValue("rankType")
	var rankType int
	if rtype=="" {
		rankType = 0
	}else {
		rankType,_ = strconv.Atoi(rtype)
	}


	movies0, movies1 := dao.GetMovies()

	//判断是否登录
	flag, session:= IsLogin(r)
	if flag {
		//已经登录
		rankPage := &model.RankPage{
			movies0,
			movies1,
			true,
			session,
			rankType,
		}
		t := template.Must(template.ParseFiles("views/pages/user/rank.html"))
		t.Execute(w, rankPage)
	} else {
		//没有登录
		rankPage := &model.RankPage{
			movies0,
			movies1,
			false,
			session,
			rankType,
		}
		t := template.Must(template.ParseFiles("views/pages/user/rank.html"))
		t.Execute(w, rankPage)
	}

}

//选影院
func SelectCinema(w http.ResponseWriter,r *http.Request) {
	//判断是否登录
	flag, _ := IsLogin(r)
	if flag {
		//已经登录
		//获取要买的电影的id
		movieID := r.FormValue("movieId")
		movieAndCinema, _ := dao.GetMovieAndCinema(movieID)
		t := template.Must(template.ParseFiles("views/pages/user/selectCinema.html"))
		t.Execute(w, movieAndCinema)
	} else {
		//没有登录
		//w.Write([]byte("请先登录！"))
		t := template.Must(template.ParseFiles("views/pages/user/login.html"))
		t.Execute(w,"")
	}
}

//选择场次
func SelectTime(w http.ResponseWriter,r *http.Request)  {
	Id := r.FormValue("movieId")
	movieId,_ := strconv.Atoi(Id)
	//fmt.Println(movieId)

	Id1 := r.FormValue("cinemaId")
	cinemaId,_ := strconv.Atoi(Id1)
	//获取日期
	d := r.FormValue("date")
	if d==""{
		d="0"
	}
	date,_ := strconv.Atoi(d)

	timeInfo := dao.GetTimePage(movieId,cinemaId,date)
	timePage := &model.TimePage{
		timeInfo,
	}

	t := template.Must(template.ParseFiles("views/pages/user/selectTime.html"))
	t.Execute(w,timePage)
}

//选座位
func SelectSeat(w http.ResponseWriter,r *http.Request) {
	roomName := r.FormValue("roomName")
	time := r.FormValue("timeId")
	timeId,_ := strconv.Atoi(time)
//fmt.Println(timeId)
	//get movieName
	movieId := dao.GetMovieIDByTimeID(timeId)
	movie,_ := dao.GetMovieByID(movieId)
	movieName := movie.Name
	//get cinemaName
	roomId := dao.GetRoomIDByName(roomName)
	//fmt.Println(roomId)
	cinema:=dao.GetCinemaByRoomID(roomId)
	cinemaName := cinema.Name
	//get columns
	columns := dao.GetRoomByRoomID(roomId).Column
	//columns := room.Column
	//get price
	price := dao.GetPriceByTimeID(timeId)
	//get selectedSeat
	//s := r.PostFormValue("s")
	//fmt.Println("s:",s)
	seats := dao.GetSeatsByRoomID(roomId)

	selectSeatInfo := &model.SelectSeatInfo{
		movieName,
		cinemaName,
		roomName,
		price,
		seats,
		columns,
		timeId,
	}

	t := template.Must(template.ParseFiles("views/pages/user/selectSeat.html"))
	t.Execute(w,selectSeatInfo)

}

//从数据库读出指定厅的行列数，以json响应给前端
func GetSeatsInfo(w http.ResponseWriter,r *http.Request){
	roomName := r.FormValue("roomName")
	//fmt.Println("roomName:",roomName)
	//time := r.FormValue("timeId")
	//timeId,_ := strconv.Atoi(time)

	roomId := dao.GetRoomIDByName(roomName)
	//从数据库读出指定厅的行列数 和所有座位状态
	row,column := dao.GetRowAndColumnByRoomID(roomId)
	//seats := dao.GetSeatsByRoomID(roomId)

	allSeats := model.Seats{
		row,
		column,
		//seats,
	}
	//将data转换为json字符串
	json, _ := json.Marshal(allSeats)
	//响应到浏览器
	w.Write(json)
}

//从数据库所有座位状态，以json响应给前端
func GetSeatsStatus(w http.ResponseWriter,r *http.Request){
	roomName := r.FormValue("roomName")
	//fmt.Println("roomName:",roomName)
	//time := r.FormValue("timeId")
	//timeId,_ := strconv.Atoi(time)

	roomId := dao.GetRoomIDByName(roomName)
	//从数据库读出指定厅的行列数 和所有座位状态
	//row,column := dao.GetRowAndColumnByRoomID(roomId)
	seats := dao.GetSeatsByRoomID(roomId)
//fmt.Println(seats)
	//allStatues := model.SeatStatues{
	//	seats,
	//}
	//将data转换为json字符串
	json, _ := json.Marshal(seats)
	//响应到浏览器
	w.Write(json)
}


//IsLogin 判断用户是否已经登录 false 没有登录 true 已经登录
func IsLogin(r *http.Request) (bool, *model.Session) {
	//根据Cookie的name获取Cookie
	cookie, _ := r.Cookie("user")
	if cookie != nil {
		//获取Cookie的value(sessionID)
		cookieValue := cookie.Value
		//根据cookieValue去数据库中查询与之对应的Session
		session, _ := dao.GetSession(cookieValue)
		if session.UserID > 0 {
			//已经登录
			return true, session
		}
	}
	//没有登录
	return false, nil
}

//Logout //处理用户注销的函数
func Logout(w http.ResponseWriter, r *http.Request) {
	//获取Cookie
	cookie, _ := r.Cookie("user")
	if cookie != nil {
		//获取cookie的value值(即sessionID)
		cookieValue := cookie.Value
		//删除数据库中与之对应的Session
		dao.DeleteSession(cookieValue)
		//设置cookie失效
		cookie.MaxAge = -1
		//将修改之后的cookie发送给浏览器
		http.SetCookie(w, cookie)
	}
	//去首页
	Index(w, r)
}

//CheckUserName 通过发送Ajax验证用户名是否可用
func CheckUserName(w http.ResponseWriter, r *http.Request) {
	//获取用户输入的用户名
	username := r.PostFormValue("username")
	//调用userdao中验证用户名和密码的方法
	user, _ := dao.CheckUserName(username)

	if user.ID > 0 {
		//用户名已存在
		w.Write([]byte("<font style='color:red'>用户名已存在！</font>"))
	} else {
		//用户名可用
		w.Write([]byte("<font style='color:green'>用户名可用</font>"))
	}
}


func Search (w http.ResponseWriter, r *http.Request) {
	str := r.FormValue("search")
	//fmt.Println(str)
	movies := dao.GetSearchMoviesByStr(str)
	flag,session := IsLogin(r)
	userName := session.UserName
	search := &model.Search{
		movies,
		userName,
		flag,
	}
	t := template.Must(template.ParseFiles("views/pages/user/searchResult.html"))
	t.Execute(w,search)
}