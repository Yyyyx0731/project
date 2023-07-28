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
//		return '#';//��ѡ 
//	}else if(x==0){
//		return '~';//��ѡ 
//	}else if(x==-1){
//		return ' ';//�� 
//	} 
//}

void goto_xy(int x, int y);//��λ���λ�õ�ָ������

void passwordInput(char pwd[]);//��������ʱ����Ϊ*�� 

void menu1();//��ʼ�˵� 
//void menu2();

void menuLogin1();//��¼���� 
//void menuLogin2();
//void menuLogin3();

void menuRegister1();//ע����� 
//void menuRegister2();
//void menuRegister3();

void menuUsersLogin();//�û���¼���� 
void menuAdminLogin();//����Ա��¼���� 

void menuUsersRegister();//�û�ע����� 
void menuAdminRegister();//����Աע����� 

void usersMenu1(char name[]);//�û����ܽ��� 
//void usersMenu2(int choice);
//void usersMenu3(int choice);
void adminMenu();//����Ա���ܽ��� 

void usersMovies(char name[]); //�û��ݳ��б� 
void adminMovies();//����Ա�ݳ��б� 

void selectSeat(int x,char name[]);

void usersSearch(char name[]);
void adminSearch();

//void searchMovie();

//void printMovie(movie *P);

void usersSearching(int choice,char name[]);
void adminSearching(int choice);

void viewOrders(char name[]);

void manageMovie();//����Ա���� 
void manageStudio();
void manageSeat();
void managePlay();

void income();//Ʊ�������۶� ����ӡʱ��tatal���������۶ 

void usersInformation();//�û���Ϣ 

void modifyPassword(char name[]);





#endif // !_UI_H_
