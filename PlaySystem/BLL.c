#include "BLL.h"

int ordersCount=0;


usersList crUsersHead()//����ͷ���
{
    users* usersHead=(users*)malloc(sizeof(users));
    usersHead->next=NULL;
    return usersHead;
}


usersList crNewUsers(char name[],char tel[],char password[])//�����½��
{
    users* p=(users*)malloc(sizeof(users));
	strcpy(p->usersName,name);
	strcpy(p->tel,tel);
	strcpy(p->password,password);
    return p;
}

adminList crAdminHead()//����ͷ���
{
    admin* adminHead=(admin*)malloc(sizeof(admin));
    adminHead->next=NULL;
    return adminHead;
}


adminList crNewAdmin(char name[],char tel[],char password[])//�����½��
{
    admin* p=(admin*)malloc(sizeof(admin));
    strcpy(p->name,name);
    strcpy(p->tel,tel);
	strcpy(p->password,password);
    return p;
}

seatList crSeatHead()//����ͷ���
{
    seat* seatHead=(seat*)malloc(sizeof(seat));
    seatHead->next=NULL;
    return seatHead;
}

seatList crNewSeat(int roomID,int row,int column)//�����½��
{
    seat* p=(seat*)malloc(sizeof(seat));
	p->roomID=roomID;
	p->row=row;
	p->column=column;
	p->status=0;
    return p;
}


ordersList crOrdersHead()//����ͷ���
{
    orders* ordersHead=(orders*)malloc(sizeof(orders));
    ordersHead->nex=NULL;
    return ordersHead;
}



//"�������","ID","����","����","����","ʱ��","��λ"
ordersList crNewOrders(int ID,char name[],char type[],int month,int date,int time,int row,int column)//�����½��
{
    orders* p=(orders*)malloc(sizeof(orders));
    //ordersCount++;
   // p->number=ordersCount;
    p->play.movie.ID=ID;
    strcpy(p->play.movie.name,name); 
    strcpy(p->play.movie.type,type);
    p->play.month=month;
    p->play.date=date;
    p->play.movie.time=time;
    p->row=row;
    p->column=column;
	return p;
}

movieList crMovieHead()//����ͷ���
{
    movie* movieHead=(movie*)malloc(sizeof(movie));
    movieHead->next1=NULL;
    return movieHead;
}

//ID�����ơ����͡�ʱ������ӳ�·ݡ���ӳ���ڡ�Ʊ�ۡ�Ӱ��ID��Ʊ����0 
movieList crNewMovie(int ID,char name[],char type[],int time,int month,int date,int price,int roomID)//�����½��
{
    movie* p=(movie*)malloc(sizeof(movie));
    p->ID=ID;
	strcpy(p->name,name);
	strcpy(p->type,type);
	p->time=time;
	p->month=month;
	p->date=date;
	p->price=price;
//	p->roomID=roomID;
	p->num=0; 
    return p;
}

studioList crStudioHead()//����ͷ���
{
    studio* studioHead=(studio*)malloc(sizeof(studio));
    studioHead->next=NULL;
    return studioHead;
}

studioList crNewStudio(int ID,int rows,int columns,int seat)
{
	studio* p=(studio*)malloc(sizeof(studio));
	p->ID=ID;
	p->rows=rows;
	p->columns=columns;
	p->seatCount=seat;
	return p;
}

playList crPlayHead()
{
	play* playHead=(play*)malloc(sizeof(play));
    playHead->next=NULL;
    return playHead;
}

playList crNewPlay(int ID,int hour,int minute,int month,int date,int roomID)
{
	play* p=(play*)malloc(sizeof(play));
//	int n=1000+rand()%(9999-1000+1);
//	p->x=n;
	p->movie.ID=ID;
	p->hour=hour;
	p->minute=minute;
	p->roomID=roomID;
	p->movie.time=findMovieTimeByID(ID);
	p->movie.month=month;
	p->movie.date=date;
	strcpy(p->movie.name,findMovieNameByID(ID));
	return p;
}





//�ж��û����û����������Ƿ���ȷ 
int usersCheck_BLL(char name[],char password[])
{
	//���ļ���������
//	readUsersForLogin(name,password);
	
	if(readUsersForLogin(name,password)==1){
		return 1;
	}else if(readUsersForLogin(name,password)==-1){
		return -1;
	}else if(readUsersForLogin(name,password)==0){
		return 0;
	}	 

}

//�жϹ���Ա���û����������Ƿ���ȷ 
int adminCheck_BLL(char name[],char password[])
{
	//���ļ���������
	if(readAdminForLogin(name,password)==1){
		return 1;
	}else if(readAdminForLogin(name,password)==-1){
		return -1;
	}else if(readAdminForLogin(name,password)==0){
		return 0;
	}	 
}






//�����û�
void addUsersNode_BLL(char name[],char tel[],char password[])
{
	usersSave(name,tel,password);
}

//�������Ա���� 
void addAdminNode_BLL(char name[],char tel[],char password[])
{
	adminSave(name,tel,password);
}


//ĳ��Ӱ��Ʊ�������۶�
void updatePrice_BLL(int ID)
{
	//��
	readMovieList_update(ID);

}

//���붩������
void ordersAdd_BLL(char name[],int x,int ID,int row,int column)
{
	//"�������","ID","����","����","����","ʱ��","��λ"
	//orders* t=crNewOrders(p->ID,p->name,p->type,p->month,p->date,p->time,row,column);
//	ordersCount++;
	ordersAdd(name,x,ID,row,column);//               ����movie����                      //
}

//��Ʊ 
void deleteOrders_BLL(int x)
{
//	ordersCount--;
	readOrdersList_Delete(x);
}


//���������� 
void movieDelete_BLL(int ID)
{
	readMovieList_Delete(ID);
	
}

void movieModify_BLL(int ID,int choice)//1.����  2.ʱ��  3.��ӳʱ��  4.Ʊ��
{
	readMovieList_Modify(ID,choice);

}

void studioAdd_BLL(int rows,int columns)
{
	studioAdd(rows,columns);
	
} 

void studioDelete_BLL(int ID)
{
	readStudioList_Delete(ID);
	
} 

//1.����  2.���� 
void studioModify_BLL(int ID,int choice)//������λ���� 
{
	readStudioList_Modify(ID,choice);

}

int seatModify_BLL(int ID,int row,int column,int zt)
{
	readSeatList_Select(ID,row,column,zt);
	return 1;
}
//
//int checkDate(int year,int month,int date)
//{
//	if(month==2){
//		if(runYear(year)){//�� 
//			if(date<1||date>29){
//				return 0;
//			}
//		}else{
//			if(date<1||date>28){
//				return 0;
//			}
//		}
//	}else if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
//			if(date<1||date>31){
//				return 0;
//			}
//	}else if(month>12||month<1){
//		return 0;
//	}else{
//		if(date<1||date>30){
//			return 0;
//		}
//	}
//	return 1;
//}
//
//int runYear(int year)
//{
//	if(year%400==0){
//		return 1;
//	}
//	if(year%4==0&&year%100!=0){
//		return 1;
//	}
//	return 0;
//}





