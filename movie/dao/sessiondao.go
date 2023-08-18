package dao

import (
	"movie/model"
	"movie/utils"
)

//GetSession 根据session的Id值从数据库中查询Session
func GetSession(sessID string) (*model.Session, error) {
	//写sql语句
	sqlStr := "select session_id,username,user_id from sessions where session_id = ?"
	//预编译
	inStmt, err := utils.Db.Prepare(sqlStr)
	if err != nil {
		return nil, err
	}
	//执行
	row := inStmt.QueryRow(sessID)
	//创建Session
	sess := &model.Session{}
	//扫描数据库中的字段值为Session的字段赋值
	row.Scan(&sess.SessionID, &sess.UserName, &sess.UserID)
	return sess, nil
}

//GetSession 根据session的Id值从数据库中查询Session
func GetSession1(sessID string) (*model.Session1, error) {
	//写sql语句
	sqlStr := "select session_id,cinemaName,cinema_id from sessions1 where session_id = ?"
	//预编译
	inStmt, err := utils.Db.Prepare(sqlStr)
	if err != nil {
		return nil, err
	}
	//执行
	row := inStmt.QueryRow(sessID)
	//创建Session
	sess := &model.Session1{}
	//扫描数据库中的字段值为Session的字段赋值
	row.Scan(&sess.SessionID, &sess.CinemaName, &sess.CinemaID)
	return sess, nil
}

//AddSession 向数据库中添加Session
func AddSession(sess *model.Session) error {
	//写sql语句
	sqlStr := "insert into sessions values(?,?,?)"
	//执行sql
	_, err := utils.Db.Exec(sqlStr, sess.SessionID, sess.UserName, sess.UserID)
	if err != nil {
		return err
	}
	return nil
}

//AddSession 向数据库中添加Session
func AddSession1(sess *model.Session1) error {
	//写sql语句
	sqlStr := "insert into sessions1 values(?,?,?)"
	//执行sql
	_, err := utils.Db.Exec(sqlStr, sess.SessionID, sess.CinemaName, sess.CinemaID)
	if err != nil {
		return err
	}
	return nil
}

//DeleteSession 删除数据库中的Session
func DeleteSession(sessID string) error {
	//写sql语句
	sqlStr := "delete from sessions where session_id = ?"
	//执行sql
	_, err := utils.Db.Exec(sqlStr, sessID)
	if err != nil {
		return err
	}
	return nil
}

//DeleteSession 删除数据库中的Session
func DeleteSession1(sessID string) error {
	//写sql语句
	sqlStr := "delete from sessions1 where session_id = ?"
	//执行sql
	_, err := utils.Db.Exec(sqlStr, sessID)
	if err != nil {
		return err
	}
	return nil
}