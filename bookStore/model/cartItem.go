package model

//CartItem 购物项结构体
type CartItem struct {
	CartItemID int64   //购物项的id(购物车里每一条数据的id 自增的)
	Book       *Book   //购物项中的图书信息 Book结构体指针
	Count      int64   //购物项中图书的数量 每本书的数量
	Amount     float64 //购物项中图书的金额小计，通过计算得到
	CartID     string  //购物车ID 当前购物项属于哪一个购物车
}

//GetAmount 获取购物项中图书的金额小计(Amount 每种书的金额)，有图书的价格和图书的数量计算得到
func (cartItem *CartItem) GetAmount() float64 {
	//获取当前购物项中图书的价格
	price := cartItem.Book.Price
	return float64(cartItem.Count) * price//转换类型了
}
