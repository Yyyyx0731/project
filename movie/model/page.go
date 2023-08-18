package model

type InfoPage struct {
	Movie   *Movie
	Session *Session
	IsLogin bool
}

type MainPage struct {
	MovieOnline []*Movie
	MovieOnline2 []*Movie
	MovieNone []*Movie
	MovieNone2 []*Movie

	//RankByScore []*Movie//top5
	//RankByAmount []*Movie

	RankByAmount1 *Movie
	RankByAmount2 *Movie
	RankByAmount3 *Movie
	RankByAmount4 *Movie
	RankByAmount5 *Movie

	RankByScore1 *Movie
	RankByScore2 *Movie
	RankByScore3 *Movie
	RankByScore4 *Movie
	RankByScore5 *Movie

	Username    string//登录的用户名
	IsLogin bool
}

