package main

import (
	"fmt"
	_ "github.com/go-sql-driver/mysql"
	"net"
	"strconv"
	"strings"
	"sync"
)


var online map[string]Client
var rwMutex sync.RWMutex
var onlineConn map[string] net.Conn


type Client struct{
	//c chan string // 消息管道
	name string
	//addr string	  // ip与端口
	conn net.Conn
}



func main() {

	listen, err := net.Listen("tcp", "127.0.0.1:7890")
	if err != nil {
		fmt.Println(err)
		return
	}
	defer listen.Close()

	//go Manager()
	onlineConn = make(map[string]net.Conn)
	online = make(map[string]Client)

	//读
	for {
		conn, err := listen.Accept()
		if err != nil {
			fmt.Println(err)
			continue
		}
		addr := conn.RemoteAddr().String()
		rwMutex.Lock()
		onlineConn[addr]=conn
		rwMutex.Unlock()

		buf := make([]byte, 1024)
		length, err := conn.Read(buf)
		if err != nil {
			break
		}
		str:=strings.Split(string(buf[:length])," ")
		if str[0]=="用户"&&str[2]=="已上线..." {
			rwMutex.Lock()
			online[str[1]] = Client{str[1],conn}//注册或登录就添加到在线map
			rwMutex.Unlock()
			fmt.Printf("\n"+string(buf[:length])+"\n")
			for k:=range onlineConn{
				onlineConn[k].Write(buf[:length])
			}
		}


		go process(conn)

	}

}

func process(conn net.Conn){
	defer conn.Close()
	buf := make([]byte, 1024)

	for {
		length, err := conn.Read(buf)
		if err != nil {
			break
		}
		if length != 0 {
			str:=strings.Split(string(buf[:length])," ")
			if len(str)>1 {
				//[私聊 user ] name :m
				if str[0]=="[私聊" {
					for k:=range online{
						if str[1]==k {
							online[k].conn.Write([]byte("[私聊]"+str[3]+str[4]))
						}
					}
				}
				if str[0]=="exit" {
					delete(online,str[1])
					s:="\n用户 "+str[1]+" 已离线...\n"
					fmt.Println(s)
					for k:=range onlineConn{
							onlineConn[k].Write([]byte(s))
					}
				}
				if str[0]=="online" {
					m := "当前在线用户：\n"
					cnt:=0
					for k:=range online {
						m+=online[k].name+"\n"
						cnt++
					}
					m+="当前在线人数："+strconv.Itoa(cnt)+"人\n"
					for k:=range online{
						if str[1]==k {
							online[k].conn.Write([]byte(m))
						}
					}
				}
			} else {
				for _,v := range onlineConn{
					v.Write(buf[:length])
				}
			}

			//var num=0
			//for range onlineConn{
			//	num++
			//}

		}
	}

}





//func process1(conn net.Conn) {
//
//	defer conn.Close()
//
//	netAddr := conn.RemoteAddr().String()
//
//	//name:=make([]byte,4096)
//	//_, err := conn.Read(name)
//	//if err!=nil {
//	//	fmt.Println(err)
//	//}
//	//str:=strings.Split(string(name),"#")
//	//var n string
//	//if len(str)>1&&str[0]=="name" {
//	//	n=str[1]
//	//}
//	rwMutex.Lock()
//	client := Client{make(chan string), netAddr, netAddr}
//	rwMutex.Unlock()
//
//	online[netAddr] = client
//
//	go writeMsg(client, conn)
//
//	loginMsg := "				用户" + client.Name + " 已上线!\n"
//	message <- loginMsg
//
//	go func(){
//		buf := make([]byte, 4096)
//		for{
//			n, err := conn.Read(buf) //读取
//			if n == 0{ // 如果消息长度为0，则用户已退出
//				fmt.Printf("				用户%s已退出\n",client.Name)
//				return
//			}
//			if err != nil {
//				fmt.Println("read err ", err)
//				return
//			}
//
//			message <- client.Name + ":" + string(buf[:n-1])
//		}
//	}()
//
//
//}


//func writeMsg(client Client, conn net.Conn) {
//	for {
//		msg := <-client.c
//		conn.Write([]byte(msg+"\n"))
//	}
//}

//func makeMassage(str string, cli Client) string {
//	return  cli.Name + ":" + str
//}



