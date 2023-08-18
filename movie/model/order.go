package model

type Order struct {
	ID string
	UserID int
	Date string
	Count int
	Amount int
	TimeID int
	OrderItems []*TimeAndSeat
	Pay int
}

type Order1 struct {
	ID string
}

type OrderItemsTable struct {
	ID int
	OrderId string
	TimeID int
	Row int
	Column int
	Price float64
}

type OrderTable struct {
	OrderID string
	Date string
	Count int
	Amount int
	UserID int
	//TimeID int
}

type MyOrder struct {
	Orders []*Order
}
