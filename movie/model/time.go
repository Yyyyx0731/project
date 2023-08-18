package model

type Time struct {
	ID int
	MovieID int
	Date string
	StartTime string
	Price float64
	RoomID int
}

type TimePage struct {
	TimeInfo []*TimeInfo
}

type TimeInfo struct {
	TimeID int
	StartTime string
	EndTime string
	Version string
	RoomName string
	Price float64
}

type TimeAndSeat struct {
	TimeID int
	MovieName string
	TimeLong int
	Date string //2023-08-18
	StartTime string
	EndTime string
	Cinema string //name
	Room string//name
	Row int
	Column int
	Price float64
}