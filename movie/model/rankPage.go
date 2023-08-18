package model

type RankPage struct {
	Movie0 []*Movie
	Movie1 []*Movie
	IsLogin bool
	Session *Session
	Type int
}
