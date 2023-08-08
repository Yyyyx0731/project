package model

//Session 结构
type Session struct {
	SessionID string//cookie的value是sessionID(UUID)
	UserName  string
	UserID    int//用作外键，关联user表
	Cart      *Cart
	OrderID   string
	Orders    []*Order
}
