#pragma once
 
#ifndef _BLL_H_
#define _BLL_H_
 
 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<io.h>
#include<conio.h>
#include<Windows.h>
#include"UI.h"
#include"DAL.h"




typedef struct Users//用户 
{
	char usersName[20];
	char tel[20];
	char password[20];
	struct Users *next;
}users,*usersList;

typedef struct Admin//管理人员 
{
	char name[20];
	char tel[20];
	char password[20];
	struct Admin *next; 
}admin,*adminList;

typedef struct Seat//用于增删某影厅的座位
{
	int row;
	int column;
	int status;//  0可选 / 1已经被选过 /-1坏了 
	int roomID;
	struct Seat* next;
}seat,*seatList;

typedef struct Studio
{
	int ID;
	int seatCount;
	int rows;
	int columns; 
//	int seat[100][100];//  0可选 / 1已经被选过 /-1坏了 
	struct Studio *next;
}studio,*studioList;

typedef struct Movie
{
	int ID;
	char name[50];
	char type[20];//类型 
	int time;//时长 (xx min)
	int year;
	int month;
	int date;
	int price;//票价 
	int num;//票房 （个数） 
	int income; 
//	int roomID;
	struct Movie* next1;
}movie,*movieList;

//场次数、电影ID、名称、时长、日期、开始时间、结束时间、影厅ID
//x,ID,hour,minute
typedef struct Play
{
	int x;
	struct Movie movie;//ID、时长、roomID 
	int hour;
	int minute;
	int year;
	int month;
	int date;
	int roomID;
	struct Play* next;
}play,*playList;

typedef struct Orders
{
	int number;//序号 
	int row;
	int column;
	struct Users users;
	struct Play play;
	struct Orders* nex;
}orders,*ordersList;



//链表初始化 




usersList crUsersHead();
usersList crNewUsers(char name[],char tel[],char password[]);
adminList crAdminHead();
adminList crNewAdmin(char name[],char tel[],char password[]);
ordersList crOrdersHead();
ordersList crNewOrders(int ID,char name[],char type[],int month,int date,int time,int row,int column);
movieList crMovieHead();
movieList crNewMovie(int ID,char name[],char type[],int time,int month,int date,int price,int roomID);
studioList crStudioHead();
studioList crNewStudio(int ID,int rows,int columns,int seat);
seatList crSeatHead();
seatList crNewSeat(int roomID,int row,int column);
playList crPlayHead();
playList crNewPlay(int ID,int hour,int minute,int month,int date,int roomID);





//判断用户的用户名和密码是否正确 
int usersCheck_BLL(char name[],char password[]);
//判断管理员的用户名和密码是否正确 
int adminCheck_BLL(char name[],char password[]);

//存入用户链表 
void addUsersNode_BLL(char name[],char tel[],char password[]);	
//存入管理员链表 
void addAdminNode_BLL(char name[],char tel[],char password[]);

//选择成功后要更新座位状态 
int selectSeat_BLL(int ID,int row,int column);//成功返回1 
//加入订单链表
void ordersAdd_BLL(char name[],int x,int ID,int row,int column);
//某电影的票房和销售额
void updatePrice_BLL(int ID);

//void movieAdd_BLL(int ID,char name[],char type[],int time,int month,int date,int price,int roomID);
//包含结点查找 
void movieDelete_BLL(int ID);
void movieModify_BLL(int ID,int choice);//1.类型  2.时长  3.上映日期  4.票价
//int movieSearch_BLL(int ID,int choice);


void studioAdd_BLL(int rows,int columns);
void studioDelete_BLL(int ID);
void studioModify_BLL(int ID,int choice);

int seatModify_BLL(int ID,int row,int column,int zt);

//退票 
void deleteOrders_BLL(int x);

int checkDate(int year,int month,int date);

int runYear(int year);



#endif // !_BLL_H_

