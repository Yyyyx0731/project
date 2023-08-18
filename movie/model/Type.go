package model

type MovieType struct {
	Type int//0 1
	CinemaName string
	Movie0 []*Movie
	Movie1 []*Movie
}

type RankType struct {
	RankType int
}

type Data struct {
	Count int
}
