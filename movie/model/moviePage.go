package model

type MoviePage struct {
	Movie0 []*Movie
	Movie1 []*Movie
	Session *Session
	IsLogin bool
	Type int
	PageNo      int   //当前页
	//PageSize    int64   //每页显示的条数
	TotalPageNo0 int  //总页数，通过计算得到
	TotalPageNo1 int   //总页数，通过计算得到
	TotalRecord0 int   //总记录数，通过查询数据库得到
	TotalRecord1 int  //总记录数，通过查询数据库得到
}

//IsHasPrev 判断是否有上一页
func (p *MoviePage) IsHasPrev() bool {
	return p.PageNo > 1
}

//IsHasNext 判断是否有下一页
func (p *MoviePage) IsHasNext0() bool {
	return p.PageNo < p.TotalPageNo0
}
func (p *MoviePage) IsHasNext1() bool {
	return p.PageNo < p.TotalPageNo1
}

//GetPrevPageNo 获取上一页
func (p *MoviePage) GetPrevPageNo() int {
	if p.IsHasPrev() {
		return p.PageNo - 1
	}
	return 1
}

//GetNextPageNo 获取下一页
func (p *MoviePage) GetNextPageNo0() int {
	if p.IsHasNext0() {
		return p.PageNo + 1
	}
	return p.TotalPageNo0

}
func (p *MoviePage) GetNextPageNo1() int {
	if p.IsHasNext1() {
		return p.PageNo + 1
	}
	return p.TotalPageNo1

}
