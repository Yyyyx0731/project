package model

type Session struct {
	SessionID string//cookie的value是sessionID(UUID)
	UserName  string
	UserID    int//用作外键，关联user表
}

type Session1 struct {
	SessionID string//cookie的value是sessionID(UUID)
	CinemaName  string
	CinemaID    int//用作外键，关联user表
}
