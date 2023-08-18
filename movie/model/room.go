package model

type Room struct {
	ID int
	Name string
	Row int
	Column int
	CinemaID int
}

func (room *Room) GetSeatCount() int{
	var cnt int
	cnt = room.Row*room.Column
	return cnt
}

type ManageRoom struct {
	Rooms []*Room
	CinemaName string
}
