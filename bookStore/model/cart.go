package model

//Cart 购物车结构体
type Cart struct {
	CartID      string      //购物车的id(主键,自己设置，不用自增)
	CartItems   []*CartItem //购物车中所有的购物项(购物车里的一条条数据)
	TotalCount  int64       //购物车中图书的总数量，通过计算得到
	TotalAmount float64     //购物车中图书的总金额，通过计算得到
	UserID      int         //当前购物车所属的用户(外键)
	UserName	string
}

//GetTotalCount 获取购物车中图书的总数量
func (cart *Cart) GetTotalCount() int64 {
	var totalCount int64
	//遍历购物车中的购物项切片
	for _, v := range cart.CartItems {
		totalCount = totalCount + v.Count//(单条数据的本数)
	}
	return totalCount
}

//GetTotalAmount 获取购物车中图书的总金额
func (cart *Cart) GetTotalAmount() float64 {
	var totalAmount float64
	//遍历购物车中的购物项切片
	for _, v := range cart.CartItems {
		totalAmount = totalAmount + v.GetAmount()//(每种书的金额小计)
	}
	return totalAmount

}
