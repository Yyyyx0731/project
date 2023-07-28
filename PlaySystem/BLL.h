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




typedef struct Users//�û� 
{
	char usersName[20];
	char tel[20];
	char password[20];
	struct Users *next;
}users,*usersList;

typedef struct Admin//������Ա 
{
	char name[20];
	char tel[20];
	char password[20];
	struct Admin *next; 
}admin,*adminList;

typedef struct Seat//������ɾĳӰ������λ
{
	int row;
	int column;
	int status;//  0��ѡ / 1�Ѿ���ѡ�� /-1���� 
	int roomID;
	struct Seat* next;
}seat,*seatList;

typedef struct Studio
{
	int ID;
	int seatCount;
	int rows;
	int columns; 
//	int seat[100][100];//  0��ѡ / 1�Ѿ���ѡ�� /-1���� 
	struct Studio *next;
}studio,*studioList;

typedef struct Movie
{
	int ID;
	char name[50];
	char type[20];//���� 
	int time;//ʱ�� (xx min)
	int year;
	int month;
	int date;
	int price;//Ʊ�� 
	int num;//Ʊ�� �������� 
	int income; 
//	int roomID;
	struct Movie* next1;
}movie,*movieList;

//����������ӰID�����ơ�ʱ�������ڡ���ʼʱ�䡢����ʱ�䡢Ӱ��ID
//x,ID,hour,minute
typedef struct Play
{
	int x;
	struct Movie movie;//ID��ʱ����roomID 
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
	int number;//��� 
	int row;
	int column;
	struct Users users;
	struct Play play;
	struct Orders* nex;
}orders,*ordersList;



//�����ʼ�� 




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





//�ж��û����û����������Ƿ���ȷ 
int usersCheck_BLL(char name[],char password[]);
//�жϹ���Ա���û����������Ƿ���ȷ 
int adminCheck_BLL(char name[],char password[]);

//�����û����� 
void addUsersNode_BLL(char name[],char tel[],char password[]);	
//�������Ա���� 
void addAdminNode_BLL(char name[],char tel[],char password[]);

//ѡ��ɹ���Ҫ������λ״̬ 
int selectSeat_BLL(int ID,int row,int column);//�ɹ�����1 
//���붩������
void ordersAdd_BLL(char name[],int x,int ID,int row,int column);
//ĳ��Ӱ��Ʊ�������۶�
void updatePrice_BLL(int ID);

//void movieAdd_BLL(int ID,char name[],char type[],int time,int month,int date,int price,int roomID);
//���������� 
void movieDelete_BLL(int ID);
void movieModify_BLL(int ID,int choice);//1.����  2.ʱ��  3.��ӳ����  4.Ʊ��
//int movieSearch_BLL(int ID,int choice);


void studioAdd_BLL(int rows,int columns);
void studioDelete_BLL(int ID);
void studioModify_BLL(int ID,int choice);

int seatModify_BLL(int ID,int row,int column,int zt);

//��Ʊ 
void deleteOrders_BLL(int x);

int checkDate(int year,int month,int date);

int runYear(int year);



#endif // !_BLL_H_

