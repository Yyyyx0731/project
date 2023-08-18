package main

import (
	"movie/controller"
	"net/http"
)

func main() {
	//设置处理静态资源，例如css和js文件
	http.Handle("/static/", http.StripPrefix("/static/", http.FileServer(http.Dir("views/static"))))
	//直接去页面，不需要像上面一样要通过模板引擎
	http.Handle("/pages/", http.StripPrefix("/pages/", http.FileServer(http.Dir("views/pages"))))

	//映射地址 处理器函数
	//去首页
	http.HandleFunc("/main", controller.Index)
	//去登录
	http.HandleFunc("/login",controller.Login)
	//退出后台管理登录
	http.HandleFunc("/cinemaLogout",controller.CinemaLogout)
	//去注册
	http.HandleFunc("/register",controller.Register)
	//通过Ajax请求验证用户名是否可用
	http.HandleFunc("/checkUserName",controller.CheckUserName)
	//退出登录
	http.HandleFunc("/logout",controller.Logout)
	//所有电影
	http.HandleFunc("/movies",controller.Movies)
	//某个电影详情页面
	http.HandleFunc("/info",controller.Info)
	//去评分
	http.HandleFunc("/eva",controller.Eva)
	//提交并更新评分
	http.HandleFunc("/submitScore",controller.SubmitScore)
	//去榜单
	http.HandleFunc("/rank",controller.Rank)
	//选择影院
	http.HandleFunc("/selectCinema",controller.SelectCinema)
	//选择场次
	http.HandleFunc("/selectTime",controller.SelectTime)
	//选择座位
	http.HandleFunc("/selectSeat",controller.SelectSeat)
	//从数据库读出指定厅的行列数 和所有座位状态，以json响应给前端
	http.HandleFunc("/getSeatsInfo",controller.GetSeatsInfo)
	//从数据库所有座位状态，以json响应给前端
	http.HandleFunc("/getSeatsStatus",controller.GetSeatsStatus)
	//生成订单
	http.HandleFunc("/createOrder",controller.CreateOrder)
	//我的订单
	http.HandleFunc("/getMyOrder",controller.GetMyOrder)
	//订单详情
	http.HandleFunc("/orderDetail",controller.OrderDetail)
	//取消订单
	http.HandleFunc("/deleteOrder",controller.DeleteOrder)
	//模糊搜索
	http.HandleFunc("/search",controller.Search)


	//验证后台管理密钥
	http.HandleFunc("/checkKey",controller.CheckKey)
	//后台管理
	http.HandleFunc("/manage",controller.Manage)
	//注册影城
	http.HandleFunc("/registerCinema",controller.RegisterCinema)
	//注册时判断改名字的影城已注册
	http.HandleFunc("/checkCinemaName",controller.CheckCinemaName)
	//场次管理
	http.HandleFunc("/manageTime",controller.ManageTime)
	//处理去添加或修改场次
	http.HandleFunc("/toModifyTime",controller.ToModifyTime)
	//添加或修改场次信息
	http.HandleFunc("/modifyTime",controller.ModifyTime)
	//删除场次
	http.HandleFunc("/deleteTime",controller.DeleteTime)
	//添加电影时查看该电影是否已被添加
	http.HandleFunc("/checkMovieExist",controller.CheckMovieExist)
	//添加电影
	http.HandleFunc("/addMovie",controller.AddMovie)
	//删除电影
	http.HandleFunc("/deleteMovie",controller.DeleteMovie)
	//影厅管理
	http.HandleFunc("/manageRoom",controller.ManageRoom)
	//处理去添加或修改影厅信息
	http.HandleFunc("/toModifyRoom",controller.ToModifyRoom)
	//添加或修改影厅信息
	http.HandleFunc("/modifyRoom",controller.ModifyRoom)
	//修改或添加room时动态获取总座位数
	http.HandleFunc("/updateRoomInfo",controller.UpdateRoomInfo)
	//删除room
	http.HandleFunc("/deleteRoom",controller.DeleteRoom)



	http.ListenAndServe(":8080",nil)

}

