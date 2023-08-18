package controller

import (
	"fmt"
	"html/template"
	"movie/dao"
	"movie/model"
	"net/http"
	"strconv"
)

//某个电影详情页面
func Info(w http.ResponseWriter,r *http.Request)  {
	//获取要买的电影的id
	movieID := r.FormValue("movieId")
	//fmt.Println("id:",movieID)
	//根据图书的id获取图书信息
	Id, err := strconv.Atoi(movieID)
	if err != nil {
		fmt.Println(err)
	}
	movie, _ := dao.GetMovieByID(Id)

	//判断是否登录
	flag, session:= IsLogin(r)
	if flag {
		//已经登录
		infoPage := &model.InfoPage{
			movie,
			session,
			true,
		}
		t := template.Must(template.ParseFiles("views/pages/user/info.html"))
		t.Execute(w, infoPage)
	} else {
		//没有登录
		infoPage := &model.InfoPage{
			movie,
			session,
			false,
		}
		t := template.Must(template.ParseFiles("views/pages/user/info.html"))
		t.Execute(w, infoPage)
	}
	//t := template.Must(template.ParseFiles("views/pages/user/info.html"))
	//t.Execute(w,"")
}

//提交并更新评分
func SubmitScore(w http.ResponseWriter,r *http.Request)  {
	movieID := r.FormValue("movieId")
	evaScore := r.FormValue("score")
	//fmt.Println(movieID,evaScore)
	dao.UpdateScore(movieID,evaScore)
	movieId,_ := strconv.Atoi(movieID)
	movie ,_:= dao.GetMovieByID(movieId)
	t := template.Must(template.ParseFiles("views/pages/user/eva.html"))
	t.Execute(w,movie)
}
