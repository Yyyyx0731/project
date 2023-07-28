#pragma once
 
#ifndef _UI_H_
#define _UI_H_
 
 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<io.h>
#include<conio.h>
#include<Windows.h>
#include"UI.h"
#include"BLL.h"
#include"DAL.h"


void color(int x);

char ztToChar(int x);

//char ztToChar(int x)//easyx
//{
//	if(x==1){
//		return '#';//被选 
//	}else if(x==0){
//		return '~';//可选 
//	}else if(x==-1){
//		return ' ';//损坏 
//	} 
//}

void goto_xy(int x, int y);//定位光标位置到指定坐标

void passwordInput(char pwd[]);//输入密码时隐藏为*号 

void menu1();//初始菜单 
//void menu2();

void menuLogin1();//登录界面 
//void menuLogin2();
//void menuLogin3();

void menuRegister1();//注册界面 
//void menuRegister2();
//void menuRegister3();

void menuUsersLogin();//用户登录界面 
void menuAdminLogin();//管理员登录界面 

void menuUsersRegister();//用户注册界面 
void menuAdminRegister();//管理员注册界面 

void usersMenu1(char name[]);//用户功能界面 
//void usersMenu2(int choice);
//void usersMenu3(int choice);
void adminMenu();//管理员功能界面 

void usersMovies(char name[]); //用户演出列表 
void adminMovies();//管理员演出列表 

void selectSeat(int x,char name[]);

void usersSearch(char name[]);
void adminSearch();

//void searchMovie();

//void printMovie(movie *P);

void usersSearching(int choice,char name[]);
void adminSearching(int choice);

void viewOrders(char name[]);

void manageMovie();//管理员管理 
void manageStudio();
void manageSeat();
void managePlay();

void income();//票房及销售额 （打印时用tatal计算总销售额） 

void usersInformation();//用户信息 

void modifyPassword(char name[]);





#endif // !_UI_H_
