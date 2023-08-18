package model

type ManageTime struct {
	CinemaName string
	Times []*Time1
}

type Time1 struct {
	ID int
	MovieID int
	MovieName string
	Date string
	StartTime string
	EndTime string
	Price float64
	RoomID int
	RoomName string
}

type ModifyTime struct {
	TimeID int
	MovieName string
	//Version string
	DateAndTime string
	Price float64
	RoomName string
	CinemaName string
	//Modify bool
}

