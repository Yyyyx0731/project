package controller

import (
	"html/template"
	"movie/dao"
	"movie/model"
	"net/http"
	"strconv"
	"strings"
	//"sync"
	"time"
)


//var wg sync.WaitGroup

//生成订单
func CreateOrder(w http.ResponseWriter,r *http.Request)  {
	_,session := IsLogin(r)

	timeID := r.FormValue("timeId")
	timeId,_ := strconv.Atoi(timeID)
	//fmt.Println("ti:",timeId)

	s := r.FormValue("s")
	//fmt.Println("s:",s)
	if s != "" {
		//fmt.Println("s1:"+s)
		str := strings.Split(s, "-")
		order := dao.CreateOrder(str, session.UserID, timeId)

		//wg.Add(1)
		// go waitToPay(order.ID)
		//wg.Wait()

		t := template.Must(template.ParseFiles("views/pages/order/createOrder.html"))
		t.Execute(w, order)
	} else{
		//CreateOrder(w,r)
		//orderId := utils.CreateUUID()
		//order1 := &model.Order1{
		//	orderId,
		//}
		t := template.Must(template.ParseFiles("views/pages/order/createOrder.html"))
		t.Execute(w, "")
	}
}


func waitToPay(orderId string){
	time.After(time.Minute*5)
	pay := dao.GetOrderPayByOderID(orderId)
	if pay==0 {
		dao.DeleteOrder(orderId)
	}
	//wg.Done()
}


////选择支付或稍后支付
//func UpdatePay(w http.ResponseWriter,r *http.Request){
//	payStr := r.FormValue("pay")
//	orderId := r.FormValue("orderId")
//	pay,_ := strconv.Atoi(payStr)
//	if pay == 1 {
//		dao.UpdatePay(orderId)
//	}
//	GetMyOrder(w,r)
//}


//我的订单
func GetMyOrder(w http.ResponseWriter,r *http.Request)  {
	//判断是否登录
	flag, session:= IsLogin(r)
	//fmt.Println(session)
	//fmt.Println("userid:",userId)
	if flag {
		//已经登录
		userId := session.UserID
		orders := dao.GetMyOrder(userId)
		myOrder := &model.MyOrder{
			orders,
		}
		t := template.Must(template.ParseFiles("views/pages/order/getMyOrder.html"))
		t.Execute(w,myOrder)
	} else {
		//没有登录
		//w.Write([]byte("请先登录！"))

		t := template.Must(template.ParseFiles("views/pages/user/login.html"))
		t.Execute(w,"")
	}

}

//订单详情
func OrderDetail(w http.ResponseWriter,r *http.Request)  {
	orderId := r.FormValue("orderId")
	//orderId,_ := strconv.Atoi(Id)
	//order := dao.GetOrderByID(orderId)

	_,session := IsLogin(r)
	order := dao.GetMyOrder(session.UserID)
	var detail []*model.TimeAndSeat
	for _,v := range order{
		if v.ID==orderId {
			detail=v.OrderItems
		}
	}
	t := template.Must(template.ParseFiles("views/pages/order/orderDetail.html"))
	t.Execute(w,detail)
}

//取消订单
func DeleteOrder(w http.ResponseWriter,r *http.Request)  {
	orderId := r.FormValue("orderId")
	dao.DeleteOrder(orderId)
	GetMyOrder(w,r)
	//t := template.Must(template.ParseFiles("views/pages/order/getMyOrder.html"))
	//t.Execute(w,"")
}


func GoToPay(w http.ResponseWriter,r *http.Request)  {
	orderId := r.FormValue("orderId")
	dao.UpdatePay(orderId)
	GetMyOrder(w,r)
}