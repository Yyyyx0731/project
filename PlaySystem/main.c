#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<io.h>
#include<conio.h>
#include<Windows.h>
#include"UI.h"
#include"BLL.h"
#include"DAL.h"




void color(int x)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}
 


int main()
{

	menu1();
		
	return 0;
}




