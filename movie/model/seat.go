package model

type Seat struct {
	Row int
	Column int
	Status int //0-可选白  1-已售红
	First int
}

//某个厅的行列数
type Seats struct {
	Rows int
	Columns int
	//Seat []*Seat
}

type SelectSeatInfo struct {
	MovieName string
	CinemaName string
	RoomName string
	Price float64
	Seats []*Seat
	Columns int
	TimeID int
}
