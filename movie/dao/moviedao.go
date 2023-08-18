package dao

import (
	"fmt"
	"movie/model"
	"movie/utils"
	"strconv"
	"strings"
	"time"
)

//得到主页的所有电影 返回一个MainPage主页结构体
func GetMainPageMovie() (*model.MainPage,error){
	t:=time.Now()
	timeNow:=t.Format("2006-01-02")

	//var cnt int
	//sqlStr1 := "select count(*) from movies where movies.online_time<=?"
	//utils.Db.QueryRow(sqlStr1,timeNow).Scan(&cnt)
	//if cnt%4 ==0 {
	//}
	sqlStr := "select * from movies where online_time <= ? limit ?,?"
	rows1,err := utils.Db.Query(sqlStr,timeNow,0,4)
	if err!= nil {
		return nil,err
	}
	rows11,err := utils.Db.Query(sqlStr,timeNow,4,4)
	if err!= nil {
		return nil,err
	}
	var movieOnline []*model.Movie
	for rows1.Next(){
		movie := &model.Movie{}
		rows1.Scan(&movie.ID,&movie.Name,&movie.Director,&movie.Type,&movie.Time,&movie.TimeOnline,&movie.Where,&movie.Version,&movie.Introduce,&movie.ImgPath,&movie.Amount,&movie.Score)
		movieOnline = append(movieOnline,movie)
		//fmt.Println(movie)
	}
	//fmt.Println(movieOnline)
	var movieOnline2 []*model.Movie
	for rows11.Next(){
		movie := &model.Movie{}
		rows11.Scan(&movie.ID,&movie.Name,&movie.Director,&movie.Type,&movie.Time,&movie.TimeOnline,&movie.Where,&movie.Version,&movie.Introduce,&movie.ImgPath,&movie.Amount,&movie.Score)
		movieOnline2 = append(movieOnline2,movie)
		//fmt.Println(movie)
	}

	sqlStr2 := "select * from movies where online_time> ? limit ?,?"
	rows2,err := utils.Db.Query(sqlStr2,timeNow,0,4)
	if err!= nil {
		return nil,err
	}
	rows22,err := utils.Db.Query(sqlStr2,timeNow,4,4)
	if err!= nil {
		return nil,err
	}
	var movieNone []*model.Movie
	for rows2.Next(){
		movie := &model.Movie{}
		rows2.Scan(&movie.ID,&movie.Name,&movie.Director,&movie.Type,&movie.Time,&movie.TimeOnline,&movie.Where,&movie.Version,&movie.Introduce,&movie.ImgPath,&movie.Amount,&movie.Score)
		movieNone = append(movieNone,movie)
		//fmt.Println(movie)
	}
	//fmt.Println("------------------------------------")
	var movieNone2 []*model.Movie
	for rows22.Next(){
		movie := &model.Movie{}
		rows22.Scan(&movie.ID,&movie.Name,&movie.Director,&movie.Type,&movie.Time,&movie.TimeOnline,&movie.Where,&movie.Version,&movie.Introduce,&movie.ImgPath,&movie.Amount,&movie.Score)
		movieNone2 = append(movieNone2,movie)
		//fmt.Println(movie)
	}

	sqlStr3 := "select * from movies where online_time<= ? order by amount desc ,name asc limit ?,?"
	rows3,err := utils.Db.Query(sqlStr3,timeNow,0,5)
	if err!= nil {
		return nil,err
	}
	var rankByAmount []*model.Movie
	for rows3.Next() {
		movie := &model.Movie{}
		rows3.Scan(&movie.ID,&movie.Name,&movie.Director,&movie.Type,&movie.Time,&movie.TimeOnline,&movie.Where,&movie.Version,&movie.Introduce,&movie.ImgPath,&movie.Amount,&movie.Score)
		rankByAmount = append(rankByAmount,movie)
		//fmt.Println(movie)
	}

	sqlStr4 := "select * from movies where online_time<= ? order by score desc ,name asc limit ?,?"
	rows4,err := utils.Db.Query(sqlStr4,timeNow,0,5)
	if err!= nil {
		return nil,err
	}
	var rankByScore []*model.Movie
	for rows4.Next() {
		movie := &model.Movie{}
		rows4.Scan(&movie.ID,&movie.Name,&movie.Director,&movie.Type,&movie.Time,&movie.TimeOnline,&movie.Where,&movie.Version,&movie.Introduce,&movie.ImgPath,&movie.Amount,&movie.Score)
		rankByScore = append(rankByScore,movie)
	}

	mainPage := &model.MainPage {
		movieOnline,
		movieOnline2,
		movieNone,
		movieNone2,
		rankByAmount[0],
		rankByAmount[1],
		rankByAmount[2],
		rankByAmount[3],
		rankByAmount[4],
		rankByScore[0],
		rankByScore[1],
		rankByScore[2],
		rankByScore[3],
		rankByScore[4],
		"",
		false,
	}
	//fmt.Println(mainPage)
	return mainPage,nil

}

//根据电影的id从数据库中查询电影
func GetMovieByID(movieId int)(*model.Movie,error){
	//写sql语句
	sqlStr := "select * from movies where id = ?"

	movie := &model.Movie{}
	//执行
	err := utils.Db.QueryRow(sqlStr, movieId).Scan(&movie.ID,&movie.Name,&movie.Director,&movie.Type,&movie.Time,&movie.TimeOnline,&movie.Where,&movie.Version,&movie.Introduce,&movie.ImgPath,&movie.Amount,&movie.Score)
	if err!= nil{
		fmt.Println(err)
		return nil,err
	}
	//fmt.Println(movie)
	return movie, nil
}

//查找影院
func GetCinema (name string,password string)(int,error){
	sqlStr := "select id from cinema where name=?and password=?"
	var id int
	err := utils.Db.QueryRow(sqlStr,name).Scan(&id)
	if err!= nil{
		fmt.Println(err)
		return 0,err
	}
	return id,nil
}

//选影院界面 得到电影信息和所有影院
func GetMovieAndCinema (movieId string) (*model.MovieAndCinema,error){
	Id ,err:= strconv.Atoi(movieId)
	movie,_ := GetMovieByID(Id)
	sqlStr := "select id,name,address from cinema"
	rows,err := utils.Db.Query(sqlStr)
	if err!= nil{
		fmt.Println(err)
		return nil,err
	}
	var cinemas []*model.Cinema
	for rows.Next(){
		cinema := &model.Cinema{}
		rows.Scan(&cinema.ID,&cinema.Name,&cinema.Address)
		cinemas = append(cinemas,cinema)
	}
	movieAndCinema := &model.MovieAndCinema{
		movie,
		cinemas,
	}
	return movieAndCinema,nil
}

//更新评分
func UpdateScore(movieId string,score string) {
	Id ,err:= strconv.Atoi(movieId)
	movie,_ := GetMovieByID(Id)

	oldScore := movie.Score
	inputScore,err := strconv.ParseFloat(score,64)
	oldScore1 := oldScore*10
	inputScore1 := inputScore*10
	if err!= nil{
		fmt.Println(err)
		return
	}
	newScore := (oldScore1+inputScore1)/2.0/10.0
	movie.Score = newScore
	sqlStr := "update movies set score = ? where id = ?"
	_, err = utils.Db.Exec(sqlStr, newScore,movieId)
	if err != nil {
		fmt.Println("exec err:",err)
		return
	}
}

//得到电影页电影
func GetMovieByPage(pageNow int)([]*model.Movie,[]*model.Movie,int,int,int,int){
	var movie0,movie1 []*model.Movie

	t:=time.Now()
	timeNow:=t.Format("2006-01-02")


	var cnt0 int
	sqlStr0 := "select count(*) from movies where online_time <= ?"
	err:=utils.Db.QueryRow(sqlStr0,timeNow).Scan(&cnt0)
	var totalPage int
	if cnt0%10 ==0 {
		totalPage = cnt0/10
	}else{
		totalPage = cnt0/10+1
	}

	sqlStr := "select * from movies where online_time <= ? limit ?,?"
	rows,err := utils.Db.Query(sqlStr,timeNow,(pageNow-1)*10,10)
	if err!= nil {
		fmt.Println(err)
		return  nil,nil,0,0,0,0
	}
	for rows.Next(){
		movie := &model.Movie{}
		rows.Scan(&movie.ID,&movie.Name,&movie.Director,&movie.Type,&movie.Time,&movie.TimeOnline,&movie.Where,&movie.Version,&movie.Introduce,&movie.ImgPath,&movie.Amount,&movie.Score)
		movie0 = append(movie0,movie)
		//fmt.Println(movie)
	}


	var cnt1 int
	sqlStr00 := "select count(*) from movies where online_time > ?"
	err=utils.Db.QueryRow(sqlStr00,timeNow).Scan(&cnt1)
	var totalPage1 int
	if cnt1%10 ==0 {
		totalPage1 = cnt1/10
	}else{
		totalPage1 = cnt1/10+1
	}

	sqlStr1 := "select * from movies where online_time > ? limit ?,?"
	rows1,err := utils.Db.Query(sqlStr1,timeNow,(pageNow-1)*10,10)
	if err!= nil {
		fmt.Println(err)
		return nil,nil,0,0,0,0
	}
	for rows1.Next(){
		movie := &model.Movie{}
		rows1.Scan(&movie.ID,&movie.Name,&movie.Director,&movie.Type,&movie.Time,&movie.TimeOnline,&movie.Where,&movie.Version,&movie.Introduce,&movie.ImgPath,&movie.Amount,&movie.Score)
		movie1 = append(movie1,movie)
		//fmt.Println(movie)
	}


	return movie0,movie1,totalPage,totalPage1,cnt0,cnt1
}

//rank页分类获取所有电影 按评分和票房
func GetMovies()([]*model.Movie,[]*model.Movie){
	var movie0,movie1 []*model.Movie

	//t:=time.Now()
	//timeNow:=t.Format("2006-01-02")

	sqlStr := "select * from movies order by score desc ,name asc "
	rows,err := utils.Db.Query(sqlStr)
	if err!= nil {
		fmt.Println(err)
		return nil,nil
	}
	for rows.Next(){
		movie := &model.Movie{}
		rows.Scan(&movie.ID,&movie.Name,&movie.Director,&movie.Type,&movie.Time,&movie.TimeOnline,&movie.Where,&movie.Version,&movie.Introduce,&movie.ImgPath,&movie.Amount,&movie.Score)
		movie0 = append(movie0,movie)
		//fmt.Println(movie)
	}

	sqlStr1 := "select * from movies order by amount desc ,name asc "
	rows1,err := utils.Db.Query(sqlStr1)
	if err!= nil {
		fmt.Println(err)
		return nil,nil
	}
	for rows1.Next(){
		movie := &model.Movie{}
		rows1.Scan(&movie.ID,&movie.Name,&movie.Director,&movie.Type,&movie.Time,&movie.TimeOnline,&movie.Where,&movie.Version,&movie.Introduce,&movie.ImgPath,&movie.Amount,&movie.Score)
		movie1 = append(movie1,movie)
		//fmt.Println(movie)
	}

	return movie0,movie1
}

//根据影院id 在room表中得到该影院的所有roomid，并返回roomid切片
func GetRoomByCinemaID(cinemaId int) []*model.Room {
	var rooms []*model.Room
	sqlStr := "select * from room where cinemaID=?"
	rows,err := utils.Db.Query(sqlStr,cinemaId)
	if err!= nil {
		fmt.Println(err)
		return nil
	}
	for rows.Next(){
		room := &model.Room{}
		rows.Scan(&room.ID,&room.Name,&room.Row,&room.Column,&room.CinemaID)
		rooms=append(rooms,room)
		//fmt.Println(room)
	}
	//fmt.Println(rooms)
	return rooms
}


//电影管理页面得到正在热映和即将上映两类电影
func GetMoviesByType()([]*model.Movie,[]*model.Movie){
	var movie0,movie1 []*model.Movie

	t:=time.Now()
	timeNow:=t.Format("2006-01-02")

	sqlStr := "select * from movies where online_time<= ?"
	rows,err := utils.Db.Query(sqlStr,timeNow)
	if err!=nil {
		fmt.Println(err)
		return nil,nil
	}
	for rows.Next(){
		movie := &model.Movie{}
		rows.Scan(&movie.ID,&movie.Name,&movie.Director,&movie.Type,&movie.Time,&movie.TimeOnline,&movie.Where,&movie.Version,&movie.Introduce,&movie.ImgPath,&movie.Amount,&movie.Score)
		movie0 = append(movie0,movie)
		//fmt.Println(movie)
	}

	sqlStr1 := "select * from movies where online_time> ?"
	rows1,err := utils.Db.Query(sqlStr1,timeNow)
	if err!=nil {
		fmt.Println(err)
		return nil,nil
	}
	for rows1.Next(){
		movie := &model.Movie{}
		rows1.Scan(&movie.ID,&movie.Name,&movie.Director,&movie.Type,&movie.Time,&movie.TimeOnline,&movie.Where,&movie.Version,&movie.Introduce,&movie.ImgPath,&movie.Amount,&movie.Score)
		movie1 = append(movie1,movie)
		//fmt.Println(movie)
	}
	return movie0,movie1
}


func AddMovie(cinemaName string,director string,movieType string,time int,onlineTime string,version string,where string,introduce string,imgPath string){
	online := strings.Split(onlineTime,"T")
	onlinetime := online[0]

	sqlStr:="insert into movies(name, director, type, time, online_time, where_online, version, introduce, img_path, amount, score) values(?,?,?,?,?,?,?,?,?,?,?)"

	_,err:=utils.Db.Exec(sqlStr,cinemaName,director,movieType,time,onlinetime,where,version,introduce,imgPath,0,0)
	if err!=nil {
		fmt.Println(err)
		return
	}

}


func DeleteMovie(cinemaId int){
	sqlStr := `delete from movies  where id = ?`

	_, err := utils.Db.Exec(sqlStr, cinemaId)
	if err != nil {
		fmt.Println("delete:", err)
		return
	}
}

func GetMovieIdByName(movieName string)int{
	sqlStr:="select id from movies where name =?"

	var movieId int
	err:=utils.Db.QueryRow(sqlStr,movieName).Scan(&movieId)
	if err != nil {
		fmt.Println("query:",err)
	}
	return  movieId
}


//用户搜素结果 模糊查询
func GetSearchMoviesByStr(str string)[]*model.Movie{
	s := "%"
	for i:=0;i<=len(str)-3;i=i+3 {
		s = s+str[i:i+3]+"%"
	}
	//fmt.Println(s)
	var movies []*model.Movie
	sqlStr := "SELECT * from movies where movies.name like ?;"
	//执行
	rows, err := utils.Db.Query(sqlStr,s)
	if err != nil {
		fmt.Println("search:",err)
		return nil
	}
	for rows.Next() {
		movie := &model.Movie{}
		rows.Scan(&movie.ID,&movie.Name,&movie.Director,&movie.Type,&movie.Time,&movie.TimeOnline,&movie.Where,&movie.Version,&movie.Introduce,&movie.ImgPath,&movie.Amount,&movie.Score)
		//添加到切片中
		movies = append(movies,movie)
	}
	return movies
}