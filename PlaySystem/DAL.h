#pragma once
 
#ifndef _DAL_H_
#define _DAL_H_
 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<io.h>
#include<conio.h>
#include<Windows.h>
#include<time.h>
#include"UI.h"
#include"BLL.h"
#include"DAL.h"


 

int readUsersForLogin(char name[],char password[]);
int readAdminForLogin(char name[],char password[]);

int passCheck(char pass[]);

void readUsersList();
void readAdminList();
void readMovieList(); 
void readStudioList();
void readOrdersList();
int findOrdersID(int n);

void usersSave(char name[],char tel[],char password[]);

void adminSave(char name[],char tel[],char password[]);

void modifyUsersPassword(char name[],char newPassword[]);

void studioUpdate();

void movieUpdate();

void ordersUpdate();


void movieAdd(char name[],char type[],int time,int month,int date,int price); 

void readStudioList_NoPrint();
void readMovieList_NoPrint();

void readMovieList_update(int ID);
void readMovieList_Delete(int ID);
void readMovieList_Modify(int ID,int choice);
int readPlayList_Search(int x);
//void readMovieList_Search(int ID,int choice);

void readStudioList_Delete(int ID);
void readStudioList_Modify(int ID,int choice);
void sortStudioByID();

//void readStudioList_SeatModify(int ID,int row,int column,int zt);

void ordersAdd(char usersName[],int x,int ID,int row,int column);
void readOrdersList_Delete(int x);
void cancelTicket(int ID);


void studioAdd(int rows,int columns);

void playSearch_Name(char name[]);
void playSearch_ID(int ID);
void playSearch_Type(char type[]);
void playSearch_Date(int month,int date);
void readMoviePrice();

int readStudioList_row(int roomID); 
int readStudioList_column(int roomID);

void deleteSeatByStudioID(int id);

void readSeatList_Select(int roomID,int row,int column,int zt);

void writeSeatStatus(int ID,int rows,int columns);

void printSeat(int roomID,int rows,int columns);

int findSeatByRC(int row,int column);

int findMovieID(int ID);
int findMovieName(char name[]); 
//int movieIDNameCheck(int ID,char name[]);

int findOrders(int n);
int findStudioID(int ID);
int findUsersName(char name[]);
int findAdminName(char name[]);
int findDate(char name[],int month,int date);

char* findMovieNameByID(int ID);
int findMovieMonthByID(int ID);
int findMovieDateByID(int ID);
int findMovieTimeByID(int ID);

void deleteSeatCuzStudioModify(int ID,int row,int column);

void readIncome();

void readPlayList();
void playAdd(char name1[],int month,int date,int hour,int minute,int roomID);
void playDelete(int x);
void playModify(int x,int choice);
int PlayList_SearchID(int x);
int findPlayID(int x);

void cancelTicket2(int x);
//int readPlayList_IDSearch(int x);

void numReduce_And_SeatUpdate(int n);
void numReduce(int ID); 
//void seatUpdate(int roomID,int row,int column);

void sortIncome();

void sortTime();

void deletePlay(int ID);
//void Del(playList L,int ID);

void playMoHu(char name[]);

void deleteOverduePlay(int month,int date);

void updateSeat();

void sortMovieByID();

#endif// !_DAL_H_
