#include"DAL.h"



void readUsersList()
{
	FILE* fp=fopen("./data/users.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return ;
        }
        users* usersHead=crUsersHead();
        while(1){
        		users* P=(users*)malloc(sizeof(users));
        		P->next=NULL;
                if(fscanf(fp,"%s %s %s",P->usersName,P->tel,P->password)!=EOF){
                		printf("\t\t\t\t         %-20s       %-20s\n\n",P->usersName,P->tel);
					    usersHead->next=P;
                        usersHead=usersHead->next;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
}

int findUsersName(char name[])
{
	FILE* fp=fopen("./data/users.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
               
        }
        users* usersHead=crUsersHead();
        while(1){
        		users* P=(users*)malloc(sizeof(users));
        		P->next=NULL;
                if(fscanf(fp,"%s %s %s",P->usersName,P->tel,P->password)!=EOF){
                		if(name==P->usersName){
                			return 1;
						} 
					    usersHead->next=P;
                        usersHead=usersHead->next;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
        return 0; 
}



void readAdminList()
{
		FILE* fp=fopen("./data/admin.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return ;
        }
        admin* adminHead=crAdminHead();
        while(1){
        		admin* P=(admin*)malloc(sizeof(admin));
        		P->next=NULL;
                if(fscanf(fp,"%s %s %s",P->name,P->tel,P->password)!=EOF){
                		
					    adminHead->next=P;
                        adminHead=adminHead->next;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
}

int findAdminName(char name[])
{
		FILE* fp=fopen("./data/admin.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
              
        }
        admin* adminHead=crAdminHead();
        while(1){
        		admin* P=(admin*)malloc(sizeof(admin));
        		P->next=NULL;
                if(fscanf(fp,"%s %s %s",P->name,P->tel,P->password)!=EOF){
                		if(name==P->name){
                			return 1;
						}
					    adminHead->next=P;
                        adminHead=adminHead->next;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
        return 0;
}



void readMovieList()
{
		FILE* fp=fopen("./data/movie.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return ;
        }
        movie* movieHead=crMovieHead();
        while(1){
        		movie* P=(movie*)malloc(sizeof(movie));
                if(fscanf(fp,"%d %s %s %d %d %d %d %d %d",&P->ID,P->name,P->type,&P->time,&P->month,&P->date,&P->price,&P->num,&P->income)!=EOF){
						printf("\t\t\t\t%-2d       %-8s        %-6s   %-2dmin  %d月%d日    %3d元\n\n",P->ID,P->name,P->type,P->time,P->month,P->date,P->price);
		         		P->next1=NULL; 
					    movieHead->next1=P;
                        movieHead=movieHead->next1;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
}

void readIncome()
{
		FILE* fp=fopen("./data/movie.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return ;
        }
        movie* movieHead=crMovieHead();
        while(1){
        		movie* P=(movie*)malloc(sizeof(movie));
                if(fscanf(fp,"%d %s %s %d %d %d %d %d %d",&P->ID,P->name,P->type,&P->time,&P->month,&P->date,&P->price,&P->num,&P->income)!=EOF){
						printf("\t\t\t\t    %-10d     %-10s      %-10d %-10d\n\n",P->ID,P->name,P->num,P->income);
		         		P->next1=NULL; 
					    movieHead->next1=P;
                        movieHead=movieHead->next1;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
}



void readMoviePrice()
{
		FILE* fp=fopen("./data/movie.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return ;
        }
        movie* movieHead=crMovieHead();
        while(1){
        		movie* P=(movie*)malloc(sizeof(movie));
        		P->next1=NULL; 
        		
                if(fscanf(fp,"%d %s %s %d %d %d %d",&P->ID,P->name,P->type,&P->time,&P->month,&P->date,&P->price)!=EOF){
						printf("\t\t\t\t    %-8d      %-12s     %-6d %10d元\n\n",P->ID,P->name,P->num,P->num,P->price);
					    movieHead->next1=P;
                        movieHead=movieHead->next1;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
}

int readUsersForLogin(char name[],char password[])
{
        FILE* fp=fopen("./data/users.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                
        }
        users* usersHead=crUsersHead();
        users* temp=usersHead;
        while(1){
        		users* P=(users*)malloc(sizeof(users));
        		P->next=NULL;
                if(fscanf(fp,"%s %s %s",P->usersName,P->tel,P->password)!=EOF){
					    usersHead->next=P;
                        usersHead=usersHead->next;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
        
        int flag=0;
        temp=temp->next;
        while(temp){
        	if(strcmp(temp->usersName,name)==0){
        		flag=1;
        		if(strcmp(temp->password,password)==0){
        			return 1;
				}else{
					return 0;
				}
			}
        	temp=temp->next;
		}
		if(flag==0){
			return -1;
		}
}

int passCheck(char pass[])
{
	FILE* fp=fopen("./data/pass.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                
        }

		char passNow[20];
		fscanf(fp,"%s",passNow);
		if(strcmp(pass,passNow)==0){
			return 1;
		}
        fclose(fp);
        fp=NULL;
        return 0;
}

void modifyUsersPassword(char name[],char newPassword[])
{
      FILE* fp=fopen("./data/users.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                
        }
        users* usersHead=crUsersHead();
        users* t=usersHead;
        users* l=usersHead;
        while(1){
        		users* P=(users*)malloc(sizeof(users));
        		P->next=NULL;
                if(fscanf(fp,"%s %s %s",P->usersName,P->tel,P->password)!=EOF){
//                	if(strcmp(l->usersName,name)==0){
//						strcpy(l->password,newPassword);
//					}
					    usersHead->next=P;
                        usersHead=usersHead->next;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
        
        l-l->next;
        while(l){
        	if(strcmp(l->usersName,name)==0){
				strcpy(l->password,newPassword);
				break;
			}
			l=l->next;
		}
		
        FILE* f=fopen("./data/users.txt","w");
		if(f==NULL){
			color(13); 
			printf("\n\t\t\t\t打开文件失败！");
			return ;
		}
		t=t->next;
		while(t){
			fprintf(f,"%-10s %-10s %-10s\n",t->usersName,t->tel,t->password);
			t=t->next;
		}
		fclose(f);
		f=NULL;
}


int readAdminForLogin(char name[],char password[])
{
	 FILE* fp=fopen("./data/admin.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return -2;
        }
        admin* adminHead=crAdminHead();
        admin* temp=adminHead;
        while(1){
        		admin* P=(admin*)malloc(sizeof(admin));
        		P->next=NULL;
                if(fscanf(fp,"%s %s %s",P->name,P->tel,P->password)!=EOF){
					    adminHead->next=P;
                        adminHead=adminHead->next;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
        
        int flag=0;
        temp=temp->next;
        while(temp){
        	if(strcmp(temp->name,name)==0){
        		flag=1;
        		if(strcmp(temp->password,password)==0){
        			return 1;
				}else{
					return 0;
				}
			}
        	temp=temp->next;
		}
		if(flag==0){
			return -1;
		}
}





void movieAdd(char name[],char type[],int time,int month,int date,int price)
{
	FILE* fp=fopen("./data/movie.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return ;
        }
        movie* movieHead=crMovieHead();
       int max=0;
        while(1){
        		movie* P=(movie*)malloc(sizeof(movie));
        		P->next1=NULL; 
                if(fscanf(fp,"%d %s %s %d %d %d %d %d %d",&P->ID,P->name,P->type,&P->time,&P->month,&P->date,&P->price,&P->num,&P->income)!=EOF){
					    max=P->ID;
						movieHead->next1=P;
                        movieHead=movieHead->next1;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
	
	FILE* f=fopen("./data/movie.txt","a");
	if(f==NULL){
		color(13); 
		printf("\n\t\t\t\t打开文件失败！");
		return ;
	}
	int num=0,income=0;
	int ID=max+1;
	fprintf(f,"%-4d %-10s %-8s %-5d %-4d %-4d %-5d %-8d %-4d\n",ID,name,type,time,month,date,price,num,income);
	fclose(f);
	f=NULL;

}


void usersSave(char name[],char tel[],char password[])
{
	FILE* fp=fopen("./data/users.txt","a");
	if(fp==NULL){
		color(13); 
		printf("\n\t\t\t\t打开文件失败！");
		return ;
	}
	fprintf(fp,"%-10s %-15s %-10s\n",name,tel,password);
	fclose(fp);
	fp=NULL;
	
}


void adminSave(char name[],char tel[],char password[])
{
	FILE* fp=fopen("./data/admin.txt","a");
	if(fp==NULL){
		color(13); 
		printf("\n\t\t\t\t打开文件失败！");
		return ;
	}
	fprintf(fp,"%-10s %-15s %-10s\n",name,tel,password);
	fclose(fp);
	fp=NULL;
}




void readStudioList()
{
	FILE* fp=fopen("./data/studio.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return ;
        }
        studio* studioHead=crStudioHead();
        while(1){
        		studio* P=(studio*)malloc(sizeof(studio));
        		P->next=NULL;
                if(fscanf(fp,"%5d %5d %5d %5d",&P->ID,&P->rows,&P->columns,&P->seatCount)!=EOF){
						printf("\t\t\t\t\t%-10d %-10d %-10d %-10d\n",P->ID,P->rows,P->columns,P->seatCount);
						studioHead->next=P;
                		studioHead=studioHead->next;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
}

void studioAdd(int rows,int columns)
{
	FILE* fp=fopen("./data/studio.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return ;
        }
        studio* studioHead=crStudioHead();
        int cnt=0;
        while(1){
        		studio* P=(studio*)malloc(sizeof(studio));
        		P->next=NULL;
                if(fscanf(fp,"%5d %5d %5d %5d",&P->ID,&P->rows,&P->columns,&P->seatCount)!=EOF){
					//printf("\t\t\t\t\t%-10d %-10d %-10d %-10d\n",P->ID,P->rows,P->columns,P->seatCount);
						cnt++;
						studioHead->next=P;
                		studioHead=studioHead->next;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
	
	FILE* f=fopen("./data/studio.txt","a");
	if(f==NULL){
		color(13); 
		printf("\n\t\t\t\t打开文件失败！");
		return ;
	}
	int ID=cnt+1;
	fprintf(f,"%-5d %-5d %-5d %-5d\n",ID,rows,columns,rows*columns);
	
	fclose(f);
	f=NULL;
	
	writeSeatStatus(ID,rows,columns);
}

void writeSeatStatus(int ID,int rows,int columns)
{
	FILE* fp=fopen("./data/seat.txt","a");
	if(fp==NULL){
		color(13); 
		printf("\n\t\t\t\t打开文件失败！");
		return ;
	}
	int i,j;
	int zt=0;
	for(i=1;i<=rows;i++){
		for(j=1;j<=columns;j++){
			fprintf(fp,"%d %d %d %d\t",ID,i,j,zt);
		}
	//	fprintf(fp,"\n");
	}
	fclose(fp);	fp=NULL;
}

void updateSeat()
{
		FILE* fp=fopen("./data/seat.txt","r");
		if(fp==NULL){
			color(13); 
			printf("\n\t\t\t\t打开文件失败！");
			return ;
		}
		seat* seatHead=crSeatHead();
		seat* t=seatHead;
	//	seat* l=seatHead;
        while(1){
        		seat* P=(seat*)malloc(sizeof(seat));
        		P->next=NULL;
                if(fscanf(fp,"%d %d %d %d",&P->roomID,&P->row,&P->column,&P->status)!=EOF){
						if(P->status==1) P->status=0;
						seatHead->next=P;
                		seatHead=seatHead->next;
                }else{
                 		break;
                }
        }
	fclose(fp);
	fp=NULL;
	
	FILE* f=fopen("./data/seat.txt","w");
		if(f==NULL){
			color(13); 
			printf("\n\t\t\t\t打开文件失败！");
			return ;
		}
		t=t->next;
		while(t){
			fprintf(f,"%d %d %d %d\t",t->roomID,t->row,t->column,t->status);
			t=t->next;
		}
		fclose(f);
		f=NULL;
}

void deleteSeatByStudioID(int id)
{
		FILE* fp=fopen("./data/seat.txt","r");
		if(fp==NULL){
			color(13); 
			printf("\n\t\t\t\t打开文件失败！");
			return ;
		}
		seat* seatHead=crSeatHead();
		seat* t=seatHead;
		seat* l=seatHead;
        while(1){
        		seat* P=(seat*)malloc(sizeof(seat));
        		P->next=NULL;
                if(fscanf(fp,"%d %d %d %d",&P->roomID,&P->row,&P->column,&P->status)!=EOF){
						seatHead->next=P;
                		seatHead=seatHead->next;
                }else{
                 		break;
                }
        }
	fclose(fp);
	fp=NULL;
	
	while(l->next){
        	if(l->next->roomID==id){
     	   		seat* q=l->next;
				l->next=l->next->next;
				free(q);
			}
			l=l->next;
		}
		
		
		FILE* f=fopen("./data/seat.txt","w");
		if(f==NULL){
			color(13); 
			printf("\n\t\t\t\t打开文件失败！");
			return ;
		}
		t=t->next;
		while(t){
			fprintf(f,"%d %d %d %d\t",t->roomID,t->row,t->column,t->status);
			t=t->next;
		}
		fclose(f);
		f=NULL;
}


void readStudioList_NoPrint()
{
	FILE* fp=fopen("./data/studio.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return ;
        }
        studio* studioHead=crStudioHead();
        while(1){
        		studio* P=(studio*)malloc(sizeof(studio));
        		P->next=NULL;
                if(fscanf(fp,"%5d %5d %5d %5d",&P->ID,&P->rows,&P->columns,&P->seatCount)!=EOF){
						studioHead->next=P;
                		studioHead=studioHead->next;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
}

int findStudioID(int ID)
{
		FILE* fp=fopen("./data/studio.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                //return ;
        }
        studio* studioHead=crStudioHead();
        while(1){
        		studio* P=(studio*)malloc(sizeof(studio));
        		P->next=NULL;
                if(fscanf(fp,"%5d %5d %5d %5d",&P->ID,&P->rows,&P->columns,&P->seatCount)!=EOF){
						if(ID==P->ID){
							return 1;
						}
						studioHead->next=P;
                		studioHead=studioHead->next;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
        return 0;
}

void readStudioList_Delete(int ID)
{
	FILE* fp=fopen("./data/studio.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return ;
        }
        studio* studioHead=crStudioHead();
        studio* t=studioHead;
        studio* l=studioHead;
        while(1){
        		studio* P=(studio*)malloc(sizeof(studio));
        		P->next=NULL; 
        		if(fscanf(fp,"%5d %5d %5d %5d",&P->ID,&P->rows,&P->columns,&P->seatCount)!=EOF){
						studioHead->next=P;
                		studioHead=studioHead->next;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
        
        while(l->next){
        	if(l->next->ID==ID){
        		break;
			}
			l=l->next;
		}
		studio* q=l->next;
		l->next=l->next->next;
		free(q);
		
		FILE* f=fopen("./data/studio.txt","w");
		if(f==NULL){
			color(13); 
			printf("\n\t\t\t\t打开文件失败！");
			return ;
		}
		t=t->next;
		while(t){
			fprintf(f,"%5d %5d %5d %5d\t",t->ID,t->rows,t->columns,t->seatCount);
			t=t->next;
		}
		fclose(f);
		f=NULL;
}


void readStudioList_Modify(int ID,int choice)
{
		FILE* fp=fopen("./data/studio.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return ;
        }
        studio* studioHead=crStudioHead();
        studio* t=studioHead;
        studio* l=studioHead;
        while(1){
        		studio* P=(studio*)malloc(sizeof(studio));
        		P->next=NULL; 
        		if(fscanf(fp,"%d %d %d %d",&P->ID,&P->rows,&P->columns,&P->seatCount)!=EOF){
						studioHead->next=P;
                		studioHead=studioHead->next;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
        
        while(l->next){
        	if(l->ID==ID){
        		break;
			}
			l=l->next;
		}
		int row,column;
		switch(choice)
		{
			case 1:{
				color(14);
				printf("\t\t\t\t请输入修改后的行数：");
				scanf("%d",&row);
				l->rows=row;
				break;
			}
			case 2:{
				color(14);
				printf("\t\t\t\t请输入修改后的列数：");
				scanf("%d",&column);
				l->columns=column; 
				break;
			}
		}
		l->seatCount=l->rows*l->columns; 
		deleteSeatCuzStudioModify(ID,row,column);
		
		FILE* f=fopen("./data/studio.txt","w");
		if(f==NULL){
			color(13); 
			printf("\n\t\t\t\t打开文件失败！\n");
			return ;
		}		
		t=t->next;
		while(t){
			fprintf(f,"%5d %5d %5d %5d\n",t->ID,t->rows,t->columns,t->seatCount);
			t=t->next;
		}
		fclose(f);
		fp=NULL;
}


int readStudioList_row(int roomID)
{
	FILE* fp=fopen("./data/studio.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return 0;
        }
        studio* studioHead=crStudioHead();
		int rows;
        while(1){
        		studio* P=(studio*)malloc(sizeof(studio));
        		P->next=NULL; 
        		if(fscanf(fp,"%5d %5d %5d %5d",&P->ID,&P->rows,&P->columns,&P->seatCount)!=EOF){
        				if(P->ID==roomID){
        					rows=P->rows;
        					break;
						}
						studioHead->next=P;
                		studioHead=studioHead->next;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
    //    printf("行数是%d",rows);
        return rows;
}

int readStudioList_column(int roomID)
{
		FILE* fp=fopen("./data/studio.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return 0;
        }
        studio* studioHead=crStudioHead();
		int columns;
        while(1){
        		studio* P=(studio*)malloc(sizeof(studio));
        		P->next=NULL; 
        		if(fscanf(fp,"%5d %5d %5d %5d",&P->ID,&P->rows,&P->columns,&P->seatCount)!=EOF){
        				if(P->ID==roomID){
        					columns=P->columns;
        					break;
						}
						studioHead->next=P;
                		studioHead=studioHead->next;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
           // printf("列数是%d",columns);
        return columns;
}


void sortStudioByID()
{
    	FILE* fp=fopen("./data/studio.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return ;
        }
        studio* studioHead=crStudioHead();
        studio* p=studioHead;
        studio* q=studioHead;
        studio* temp=studioHead;
        studio* t=studioHead;
        int cnt=0;
        while(1){
        		studio* P=(studio*)malloc(sizeof(studio));
        		P->next=NULL; 
        		if(fscanf(fp,"%5d %5d %5d %5d",&P->ID,&P->rows,&P->columns,&P->seatCount)!=EOF){
						cnt++;
						studioHead->next=P;
                		studioHead=studioHead->next;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
        
        
        int i,j;
		studio *tail;//创建三个指针
        for(i=0;i<cnt-1;i++)
		{
			j=cnt-i-1;//记录内层循环需要的次数
			q=temp->next;//令q指向第一个结点
			p=q->next;//令p指向后一个结点
			tail=temp;//让tail始终指向q前一个结点
			while(j--)
			{
				if(q->ID>p->ID)
				{
					q->next=p->next;
					p->next=q;
					tail->next=p;
				}
				tail=tail->next;
				q=tail->next;
				p=q->next;
			 } 
		} 
		
		FILE* f=fopen("./data/studio.txt","w");
		if(f==NULL){
			color(13); 
			printf("\n\t\t\t\t打开文件失败！\n");
			return ;
		}		
		t=t->next;
		while(t){
			fprintf(f,"%5d %5d %5d %5d\n",t->ID,t->rows,t->columns,t->seatCount);
			t=t->next;
		}
		fclose(f);
		fp=NULL;
        
}

void sortIncome()
{
	FILE* fp=fopen("./data/movie.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return ;
        }
        movie* movieHead=crMovieHead();
        movie* p=movieHead;
        movie* q=movieHead;
        movie* t=movieHead;
        movie* temp=movieHead;
        int cnt=0;
        while(1){
        		movie* P=(movie*)malloc(sizeof(movie));
        		P->next1=NULL; 
        		//%-2d       %-8s      %-6s   %-2dmin  %d月%d日 %4d元
        		//"ID","名称","类型","时长","上映日期","票价"
                if(fscanf(fp,"%d %s %s %d %d %d %d %d %d",&P->ID,P->name,P->type,&P->time,&P->month,&P->date,&P->price,&P->num,&P->income)!=EOF){
					//	printf("\t\t\t\t%-2d       %-8s        %-6s %-2dmin   %d月%d日 %4d元\n\n",P->ID,P->name,P->type,P->time,P->month,P->date,P->price);
					    cnt++;
						movieHead->next1=P;
                        movieHead=movieHead->next1;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
        
        int i,j;
		movie *tail;
        for(i=0;i<cnt-1;i++)
		{
			j=cnt-i-1;//内层次数
			q=temp->next1;//q指向第一个结点
			p=q->next1;//p指向后一个
			tail=temp;//tail始终指向q前一个
			while(j--)
			{
				if(q->income<p->income)
				{
					q->next1=p->next1;
					p->next1=q;
					tail->next1=p;
				}
				tail=tail->next1;
				q=tail->next1;
				p=q->next1;
			 } 
		} 
		
		FILE* f=fopen("./data/movie.txt","w");
		if(f==NULL){
			color(13); 
			printf("\n\t\t\t\t打开文件失败！");
			return ;
		}
		t=t->next1;
		while(t){
			fprintf(f,"%d %s %s %d %d %d %d %d %d\n",t->ID,t->name,t->type,t->time,t->month,t->date,t->price,t->num,t->income);
			t=t->next1;
		}
		fclose(f);
		f=NULL;
} 




void readMovieList_NoPrint()
{
	FILE* fp=fopen("./data/movie.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return ;
        }
        movie* movieHead=crMovieHead();
       // movie* p=movieHead;
        while(1){
        		movie* P=(movie*)malloc(sizeof(movie));
        		P->next1=NULL; 
        		//%-2d       %-8s      %-6s   %-2dmin  %d月%d日 %4d元
        		//"ID","名称","类型","时长","上映日期","票价"
                if(fscanf(fp,"%d %s %s %d %d %d %d %d %d",&P->ID,P->name,P->type,&P->time,&P->month,&P->date,&P->price,&P->num,&P->income)!=EOF){
					//	printf("\t\t\t\t%-2d       %-8s        %-6s %-2dmin   %d月%d日 %4d元\n\n",P->ID,P->name,P->type,P->time,P->month,P->date,P->price);
					    movieHead->next1=P;
                        movieHead=movieHead->next1;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;

}

void sortMovieByID()
{
    	FILE* fp=fopen("./data/movie.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return ;
        }
        movie* movieHead=crMovieHead();
        movie* p=movieHead;
        movie* q=movieHead;
        movie* temp=movieHead;
        movie* t=movieHead;
        int cnt=0;
        while(1){
        		movie* P=(movie*)malloc(sizeof(movie));
        		P->next1=NULL; 
        		if(fscanf(fp,"%d %s %s %d %d %d %d %d %d",&P->ID,P->name,P->type,&P->time,&P->month,&P->date,&P->price,&P->num,&P->income)!=EOF){
						cnt++;
						movieHead->next1=P;
                		movieHead=movieHead->next1;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
        
        
        int i,j;
		movie *tail;
        for(i=0;i<cnt-1;i++)
		{
			j=cnt-i-1;//内层次数
			q=temp->next1;//q指向第一个结点
			p=q->next1;//p指向后一个
			tail=temp;//tail始终指向q前一个
			while(j--)
			{
				if(q->ID>p->ID)
				{
					q->next1=p->next1;
					p->next1=q;
					tail->next1=p;
				}
				tail=tail->next1;
				q=tail->next1;
				p=q->next1;
			 } 
		} 
		
		FILE* f=fopen("./data/movie.txt","w");
		if(f==NULL){
			color(13); 
			printf("\n\t\t\t\t打开文件失败！\n");
			return ;
		}		
		t=t->next1;
		while(t){
			fprintf(f,"%d %s %s %d %d %d %d %d %d\n",t->ID,t->name,t->type,t->time,t->month,t->date,t->price,t->num,t->income);
			t=t->next1;
		}
		fclose(f);
		fp=NULL;
}



char* findMovieNameByID(int ID)
{
	FILE* fp=fopen("./data/movie.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return 0;
        }
        movie* movieHead=crMovieHead();
        char *name;
        while(1){
        		movie* P=(movie*)malloc(sizeof(movie));
        		P->next1=NULL; 
                if(fscanf(fp,"%d %s %s %d %d %d %d %d %d",&P->ID,P->name,P->type,&P->time,&P->month,&P->date,&P->price,&P->num,&P->income)!=EOF){
						if(P->ID==ID){
							strcpy(name,P->name);
							break;
						}
					    movieHead->next1=P;
                        movieHead=movieHead->next1;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
        return name;
}

int findMovieTimeByID(int ID)
{
	FILE* fp=fopen("./data/movie.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return 0;
        }
        movie* movieHead=crMovieHead();
        int time;
        while(1){
        		movie* P=(movie*)malloc(sizeof(movie));
        		P->next1=NULL; 
                if(fscanf(fp,"%d %s %s %d %d %d %d %d %d",&P->ID,P->name,P->type,&P->time,&P->month,&P->date,&P->price,&P->num,&P->income)!=EOF){
						if(P->ID==ID){
							time=P->time;
							break;
						}
					    movieHead->next1=P;
                        movieHead=movieHead->next1;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
        return time;
}

void readMovieList_update(int ID)
{
		FILE* fp=fopen("./data/movie.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return ;
        }
        movie* movieHead=crMovieHead();
        movie* t=movieHead;
        movie* l=movieHead;
        while(1){
        		movie* P=(movie*)malloc(sizeof(movie));
        		P->next1=NULL;         		
                if(fscanf(fp,"%d %s %s %d %d %d %d %d %d",&P->ID,P->name,P->type,&P->time,&P->month,&P->date,&P->price,&P->num,&P->income)!=EOF){
					    movieHead->next1=P;
                        movieHead=movieHead->next1;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
        
        l=l->next1;
        while(l){
        	if(l->ID==ID){
        		break;
			}
			l=l->next1;
		}
		l->num=l->num+1;
		l->income+=l->price; 
		FILE* f=fopen("./data/movie.txt","w");
		if(f==NULL){
			color(13); 
			printf("\n\t\t\t\t打开文件失败！");
			return ;
		}
		t=t->next1;
		while(t){
			fprintf(f,"%d %s %s %d %d %d %d %d %d\n",t->ID,t->name,t->type,t->time,t->month,t->date,t->price,t->num,t->income);
			t=t->next1;
		}
		fclose(f);
		f=NULL;
}

void readMovieList_Delete(int ID)
{
	FILE* fp=fopen("./data/movie.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return ;
        }
        movie* movieHead=crMovieHead();
        movie* t=movieHead;
        movie* l=movieHead;
        while(1){
        		movie* P=(movie*)malloc(sizeof(movie));
        		P->next1=NULL; 
                if(fscanf(fp,"%d %s %s %d %d %d %d %d %d",&P->ID,P->name,P->type,&P->time,&P->month,&P->date,&P->price,&P->num,&P->income)!=EOF){
					    movieHead->next1=P;
                        movieHead=movieHead->next1;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
        
        while(l->next1){
        	if(l->next1->ID==ID){
        		movie* q=l->next1;
				l->next1=l->next1->next1;
				free(q);
        		break;
			}
			l=l->next1;
		}
		
		
		FILE* f=fopen("./data/movie.txt","w");
		if(f==NULL){
			color(13); 
			printf("\n\t\t\t\t打开文件失败！");
			return ;
		}
		t=t->next1; 
		while(t){
			fprintf(f,"%d %s %s %d %d %d %d %d %d\n",t->ID,t->name,t->type,t->time,t->month,t->date,t->price,t->num,t->income);
			t=t->next1;
		}
		fclose(f);
		f=NULL;
		
}

//1.类型  2.时长  3.上映时间  4.票价
void readMovieList_Modify(int ID,int choice)
{
	FILE* fp=fopen("./data/movie.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return ;
        }
        movie* movieHead=crMovieHead();
        movie* t=movieHead;
        movie* l=movieHead;
        while(1){
        		movie* P=(movie*)malloc(sizeof(movie));
        		P->next1=NULL; 
                if(fscanf(fp,"%d %s %s %d %d %d %d %d %d",&P->ID,P->name,P->type,&P->time,&P->month,&P->date,&P->price,&P->num,&P->income)!=EOF){
					    movieHead->next1=P;
                        movieHead=movieHead->next1;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
        
        l=l->next1;
        while(l){
        	if(l->ID==ID){
        		break;
			}
			l=l->next1;
		}
		switch(choice)
		{
			case 1:{//类型 
				color(14);
				printf("\t\t\t\t请输入修改后的类型：");
				char type[20];
				scanf("%s",type);
				strcpy(l->type,type); 
				break;
			}
			case 2:{//时长 
				color(14);
				printf("\t\t\t\t请输入修改后的时长：");
				int time;
				scanf("%d",&time);
				l->time=time; 
				break;
			}
			case 3:{//上映时间 
				color(14);
				printf("\t\t\t\t请输入修改后的上映时间（月份和日期用空格隔开）：");
				int year,month,date;
				scanf("%d %d",&month,&date);
				l->year=year;
				l->month=month;
				l->date=date;
				break;
			}
			case 4:{//票价 
				color(14);
				printf("\t\t\t\t请输入修改后的票价：");
				int price;
				scanf("%d",&price);
				l->price=price; 
				break;
			}
		}
		
		FILE* f=fopen("./data/movie.txt","w");
		if(f==NULL){
			color(13); 
			printf("\n\t\t\t\t打开文件失败！");
			return ;
		}

		t=t->next1;
		while(t){
			fprintf(f,"%d %s %s %d %d %d %d %d %d\n",t->ID,t->name,t->type,t->time,t->month,t->date,t->price,t->num,t->income);
			t=t->next1;
		}
		fclose(f);
		fp=NULL;
}

int findDate(char name[],int month,int date)
{
	FILE* fp=fopen("./data/movie.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return 0;
        }
        movie* movieHead=crMovieHead();
        int roomID;
        while(1){
        		movie* P=(movie*)malloc(sizeof(movie));
        		P->next1=NULL; 
                if(fscanf(fp,"%d %s %s %d %d %d %d %d %d",&P->ID,P->name,P->type,&P->time,&P->month,&P->date,&P->price,&P->num,&P->income)!=EOF){
						if(strcmp(name,P->name)==0){
							if(P->month==month&&P->date>date)
								return 1;
						//	else if(P->year)
							else if(P->month>month)
								return 1;
							else return 0;
						}
					    movieHead->next1=P;
                        movieHead=movieHead->next1;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
       // return 0;
}



void playSearch_Name(char name[])
{
		FILE* fp=fopen("./data/play.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return ;
        }
        play* playHead=crPlayHead();
        int flag=0;
        while(1){
        		play* P=(play*)malloc(sizeof(play));
        		P->next=NULL; 
                if(fscanf(fp,"%d %d %s %s %d %d %d %d %d %d %d",&P->x,&P->movie.ID,P->movie.name,P->movie.type,&P->month,&P->date,&P->movie.time,&P->hour,&P->minute,&P->movie.price,&P->roomID)!=EOF){
                	if(strcmp(P->movie.name,name)==0){
                		flag=1;
						printf("\t\t\t%-3d  %-3d      %-8s     %-5s 2023年%d月%d日 %dmin  %d:%d %3d元 %4d\n\n",P->x,P->movie.ID,P->movie.name,P->movie.type,P->month,P->date,P->movie.time,P->hour,P->minute,P->movie.price,P->roomID);
					}
					    playHead->next=P;
                        playHead=playHead->next;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
        if(flag==0){
        	printf("\n\n\t\t\t没有找到该电影！");
        	printf("\n\n\t\t\t是否进行模糊查找（Y/N）：");
        	fflush(stdin);
        	char ch;
        	scanf("%c",&ch); 
        	if(ch=='Y'||ch=='y')
        		playMoHu(name); 
		}
		
}

void playMoHu(char name[])
{
	int cnt1=0;
	for(cnt1=0;name[cnt1]!='\0';cnt1++){	
	}
	printf("\n\n\t\t\t\t或许你想找的是：\n\n");
	FILE* fp=fopen("./data/play.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return ;
        }
        play* playHead=crPlayHead();
        int flag=0;
        while(1){
        		play* P=(play*)malloc(sizeof(play));
        		P->next=NULL; 
                if(fscanf(fp,"%d %d %s %s %d %d %d %d %d %d %d",&P->x,&P->movie.ID,P->movie.name,P->movie.type,&P->month,&P->date,&P->movie.time,&P->hour,&P->minute,&P->movie.price,&P->roomID)!=EOF){
                		int cnt2=0;
                		char name2[20];
                		strcpy(name2,P->movie.name);
                		int i,j;
                		for(i=0;name[i]!='\0';i++){
                			for(j=0;name2[j]!='\0';j++){
                				if(name[i]==name2[j]){
                					cnt2++;
								}
							}
						}
						if(cnt2==cnt1){
							printf("\t\t\t%-3d  %-3d      %-8s     %-5s 2023年%d月%d日 %dmin  %d:%d %3d元 %4d\n\n",P->x,P->movie.ID,P->movie.name,P->movie.type,P->month,P->date,P->movie.time,P->hour,P->minute,P->movie.price,P->roomID);
						}
					    playHead->next=P;
                        playHead=playHead->next;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
}

void playSearch_ID(int ID)
{
		FILE* fp=fopen("./data/play.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return ;
        }
        play* playHead=crPlayHead();
        int flag=0;
        while(1){
        		play* P=(play*)malloc(sizeof(play));
        		P->next=NULL; 
                if(fscanf(fp,"%d %d %s %s %d %d %d %d %d %d %d",&P->x,&P->movie.ID,P->movie.name,P->movie.type,&P->month,&P->date,&P->movie.time,&P->hour,&P->minute,&P->movie.price,&P->roomID)!=EOF){
                	if(P->movie.ID==ID){
                		flag=1;
						printf("\t\t\t%-3d  %-3d      %-8s     %-5s 2023年%d月%d日 %dmin  %d:%d %3d元 %4d\n\n",P->x,P->movie.ID,P->movie.name,P->movie.type,P->month,P->date,P->movie.time,P->hour,P->minute,P->movie.price,P->roomID);
					}
					    playHead->next=P;
                        playHead=playHead->next;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
        if(flag==0){
        	printf("\n\n\t\t\t没有找到该电影！");
		}
}

void playSearch_Type(char type[])
{
	FILE* fp=fopen("./data/play.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return ;
        }
        play* playHead=crPlayHead();
        int flag=0;
        while(1){
        		play* P=(play*)malloc(sizeof(play));
        		P->next=NULL; 
                if(fscanf(fp,"%d %d %s %s %d %d %d %d %d %d %d",&P->x,&P->movie.ID,P->movie.name,P->movie.type,&P->month,&P->date,&P->movie.time,&P->hour,&P->minute,&P->movie.price,&P->roomID)!=EOF){
                	if(strcmp(P->movie.type,type)==0){
                		flag=1;
						printf("\t\t\t%-3d  %-3d      %-8s     %-5s 2023年%d月%d日 %dmin  %d:%d %3d元 %4d\n\n",P->x,P->movie.ID,P->movie.name,P->movie.type,P->month,P->date,P->movie.time,P->hour,P->minute,P->movie.price,P->roomID);
					}
					    playHead->next=P;
                        playHead=playHead->next;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
        if(flag==0){
        	printf("\n\n\t\t\t没有找到该电影！");
		}
}

void playSearch_Date(int month,int date)
{
		FILE* fp=fopen("./data/play.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return ;
        }
        play* playHead=crPlayHead();
      //  movie* t=movieHead;
        int flag=0;
        while(1){
        		play* P=(play*)malloc(sizeof(play));
        		P->next=NULL; 
        		if(fscanf(fp,"%d %d %s %s %d %d %d %d %d %d %d",&P->x,&P->movie.ID,P->movie.name,P->movie.type,&P->month,&P->date,&P->movie.time,&P->hour,&P->minute,&P->movie.price,&P->roomID)!=EOF){
                	if(P->month==month&&P->date==date){
                		flag=1;
						printf("\t\t\t%-3d  %-3d      %-8s     %-5s 2023年%d月%d日 %dmin  %d:%d %3d元 %4d\n\n",P->x,P->movie.ID,P->movie.name,P->movie.type,P->month,P->date,P->movie.time,P->hour,P->minute,P->movie.price,P->roomID);
					}
					    playHead->next=P;
                        playHead=playHead->next;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
        if(flag==0){
        	printf("\n\n\t\t\t该日期暂时没有电影播放！");
		}
}


void readPlayList()
{
	FILE* fp=fopen("./data/play.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return ;
        }
        play* playHead=crPlayHead();
        while(1){
        		play* P=(play*)malloc(sizeof(play));
        		P->next=NULL; 
        		if(fscanf(fp,"%d %d %s %s %d %d %d %d %d %d %d\n",&P->x,&P->movie.ID,P->movie.name,P->movie.type,&P->month,&P->date,&P->movie.time,&P->hour,&P->minute,&P->movie.price,&P->roomID)!=EOF){
						printf("\t\t\t%-3d  %-3d      %-8s     %-5s 2023年%d月%d日 %dmin  %d:%d %3d元 %4d\n\n",P->x,P->movie.ID,P->movie.name,P->movie.type,P->month,P->date,P->movie.time,P->hour,P->minute,P->movie.price,P->roomID);
						playHead->next=P;
                		playHead=playHead->next;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
}


void deletePlay(int ID)
{
	FILE* fp=fopen("./data/play.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return ;
        }
        playList playHead=crPlayHead();
        play* t=playHead;
        play* r=playHead;
        play* temp=playHead;
        int cnt=0;
        while(1){
        		play* P=(play*)malloc(sizeof(play));
        		P->next=NULL; 
        		if(fscanf(fp,"%d %d %s %s %d %d %d %d %d %d %d\n",&P->x,&P->movie.ID,P->movie.name,P->movie.type,&P->month,&P->date,&P->movie.time,&P->hour,&P->minute,&P->movie.price,&P->roomID)!=EOF){
						cnt++;
						playHead->next=P;
                		playHead=playHead->next;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;

		while (r->next)	
	   {
	   	  play* p = r->next; 
		  if (p->movie.ID == ID)		  
		    {
		    	r->next = p->next;
		   	 	free (p);
	        }	        
	      else
		  {
		  	r = r->next;
		  }  		  
	   }
		
		FILE* f=fopen("./data/play.txt","w");
		if(f==NULL){
			color(13); 
			printf("\n\t\t\t\t打开文件失败！");
			return ;
		}
		t=t->next;
		while(t){
			fprintf(f,"%d %d %s %s %d %d %d %d %d %d %d\n",t->x,t->movie.ID,t->movie.name,t->movie.type,t->month,t->date,t->movie.time,t->hour,t->minute,t->movie.price,t->roomID);
			t=t->next;
		}
		fclose(f);
		f=NULL;
}



void playAdd(char name1[],int month,int date,int hour,int minute,int roomID)
{
	FILE* fp=fopen("./data/movie.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return ;
        }
        movie* movieHead=crMovieHead();
        char type[20];
        int time,price,ID;
        while(1){
        		movie* P=(movie*)malloc(sizeof(movie));
        		P->next1=NULL; 
                if(fscanf(fp,"%d %s %s %d %d %d %d %d %d %d",&P->ID,P->name,P->type,&P->time,&P->month,&P->date,&P->price,&P->num,&P->income)!=EOF){
                	if(strcmp(name1,P->name)==0){
                	//	strcpy(name,P->name);
                		strcpy(type,P->type);
                		time=P->time;
                		price=P->price;
                		ID=P->ID;
					}
					    movieHead->next1=P;
                        movieHead=movieHead->next1;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
	
	FILE* f=fopen("./data/play.txt","a");
	if(f==NULL){
		color(13); 
		printf("\n\t\t\t\t打开文件失败！");
		return ;
	}
	int x=rand() % (99999 - 10000 + 1) + 10000;
	while(findPlayID(x)){
		x=rand() % (99999 - 10000 + 1) + 10000;
	} 
	//"场次","电影ID","名称","类型","时长","日期","时间","票价","影厅ID"
	fprintf(f,"%d %d %s %s %d %d %d %d %d %d %d\n",x,ID,name1,type,month,date,time,hour,minute,price,roomID);
	fclose(f);
	f=NULL;
}

void playDelete(int x)
{
	FILE* fp=fopen("./data/play.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return ;
        }
        play* playHead=crPlayHead();
        play* t=playHead;
        play* l=playHead;
        while(1){
        		play* P=(play*)malloc(sizeof(play));
        		P->next=NULL; 
        		if(fscanf(fp,"%d %d %s %s %d %d %d %d %d %d %d",&P->x,&P->movie.ID,P->movie.name,P->movie.type,&P->month,&P->date,&P->movie.time,&P->hour,&P->minute,&P->movie.price,&P->roomID)!=EOF){
						playHead->next=P;
                		playHead=playHead->next;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
        
        while(l->next){
        	if(l->next->x==x){
        		break;
			}
			l=l->next;
		}
		play* q=l->next;
		l->next=l->next->next;
		free(q);
		
		FILE* f=fopen("./data/play.txt","w");
		if(f==NULL){
			color(13); 
			printf("\n\t\t\t\t打开文件失败！");
			return ;
		}
		t=t->next;
		while(t){
			fprintf(f,"%d %d %s %s %d %d %d %d %d %d %d\n",t->x,t->movie.ID,t->movie.name,t->movie.type,t->month,t->date,t->movie.time,t->hour,t->minute,t->movie.price,t->roomID);
			t=t->next;
		}
		fclose(f);
		f=NULL;
}

void deleteOverduePlay(int month,int date)
{
	FILE* fp=fopen("./data/play.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return ;
        }
        play* playHead=crPlayHead();
        play* t=playHead;
        play* l=playHead;
        int cnt=0; 
        while(1){
        		play* P=(play*)malloc(sizeof(play));
        		P->next=NULL; 
        		if(fscanf(fp,"%d %d %s %s %d %d %d %d %d %d %d",&P->x,&P->movie.ID,P->movie.name,P->movie.type,&P->month,&P->date,&P->movie.time,&P->hour,&P->minute,&P->movie.price,&P->roomID)!=EOF){
						if(P->month<month||(P->month==month&&P->date<date)){
							cnt++;
						}
						playHead->next=P;
                		playHead=playHead->next;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
        
        while(l->next){
//        	int flag=1;
//        	if(l->next->month<month){
//        		flag=0;
//			}
//			if(l->next->month==month&&l->next->date<date){
//				flag=0; 
//			}
//			if(flag==0){
//				play* q=l->next;
//				l->next=l->next->next;
//				free(q);
//			}
//			l=l->next;
			while(cnt>0){
				play* q=l->next;
				l->next=l->next->next;
				free(q);
				cnt--;
			}
			l=l->next;
		}
		
		
		
		FILE* f=fopen("./data/play.txt","w");
		if(f==NULL){
			color(13); 
			printf("\n\t\t\t\t打开文件失败！");
			return ;
		}
		t=t->next;
		while(t){
			fprintf(f,"%d %d %s %s %d %d %d %d %d %d %d\n",t->x,t->movie.ID,t->movie.name,t->movie.type,t->month,t->date,t->movie.time,t->hour,t->minute,t->movie.price,t->roomID);
			t=t->next;
		}
		fclose(f);
		f=NULL;
}

void playModify(int x,int choice)
{
		FILE* fp=fopen("./data/play.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return ;
        }
        play* playHead=crPlayHead();
        play* t=playHead;
        play* l=playHead;
        char name[50];
        while(1){
        		play* P=(play*)malloc(sizeof(play));
        		P->next=NULL; 
                if(fscanf(fp,"%d %d %s %s %d %d %d %d %d %d %d",&P->x,&P->movie.ID,P->movie.name,P->movie.type,&P->month,&P->date,&P->movie.time,&P->hour,&P->minute,&P->movie.price,&P->roomID)!=EOF){
					    if(P->x==x){
					    	strcpy(name,P->movie.name);
						}
						playHead->next=P;
                        playHead=playHead->next;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
        
        l=l->next;
        while(l){
        	if(l->x==x){
        		break;
			}
			l=l->next;
		}
		switch(choice)
		{
			case 1:{//日期 
				color(14);
				printf("\t\t\t\t请输入修改后的日期（月份和日期用空格隔开）：");
				int month,date; 
				scanf("%d %d",&month,&date);
				while(findDate(name,month,date)){
					color(14);
					printf("\n播放日期需在上映日期之后！请重新输入：");
					scanf("%d %d",&month,&date);
				} 
				l->month=month;
				l->date=date;
				break;
			}
			case 2:{//时间 
				color(14);
				printf("\t\t\t\t请输入修改后的放映时间（小时和分钟用空格隔开）：");
				int hour,minute; 
				scanf("%d %d",&hour,&minute);
				l->minute=minute;
				l->hour=hour;
				break;
			}
			case 3:{//影厅 
				color(14);
				printf("\t\t\t\t请输入修改后的上映影厅ID：");
				int ID;
				scanf("%d",&ID);
				while(findStudioID(ID)==0){
					color(14);
					printf("\n\t\t\t\t该影厅ID不存在！请重新输入：");
					scanf("%d",&ID); 
				}
				l->roomID=ID;
				break;
			}
		}
		
		FILE* f=fopen("./data/play.txt","w");
		if(f==NULL){
			color(13); 
			printf("\n\t\t\t\t打开文件失败！");
			return ;
		}

		t=t->next;
		while(t){
			fprintf(f,"%d %d %s %s %d %d %d %d %d %d %d\n",t->x,t->movie.ID,t->movie.name,t->movie.type,t->month,t->date,t->movie.time,t->hour,t->minute,t->movie.price,t->roomID);
			t=t->next;
		}
		fclose(f);
		fp=NULL;
}

int readPlayList_Search(int x)
{
	FILE* fp=fopen("./data/play.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                //return ;
        }
        play* playHead=crPlayHead();
        int roomID;
        while(1){
        		play* P=(play*)malloc(sizeof(play));
        		P->next=NULL; 
                if(fscanf(fp,"%d %d %s %s %d %d %d %d %d %d %d\n",&P->x,&P->movie.ID,P->movie.name,P->movie.type,&P->month,&P->date,&P->movie.time,&P->hour,&P->minute,&P->movie.price,&P->roomID)!=EOF){
					    if(P->x==x){
					    	roomID=P->roomID;
					    	break;
						}
						playHead->next=P;
                        playHead=playHead->next;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
        return roomID;
}

int PlayList_SearchID(int x)
{
	FILE* fp=fopen("./data/play.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
        }
        play* playHead=crPlayHead();
        int ID;
        while(1){
        		play* P=(play*)malloc(sizeof(play));
        		P->next=NULL; 
                if(fscanf(fp,"%d %d %s %s %d %d %d %d %d %d %d\n",&P->x,&P->movie.ID,P->movie.name,P->movie.type,&P->month,&P->date,&P->movie.time,&P->hour,&P->minute,&P->movie.price,&P->roomID)!=EOF){
					    if(P->x==x){
					    	ID=P->movie.ID;
					    	break;
						}
						playHead->next=P;
                        playHead=playHead->next;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
        return ID;
}

int findPlayID(int x)
{
	FILE* fp=fopen("./data/play.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
        }
        play* playHead=crPlayHead();
        int ID;
        while(1){
        		play* P=(play*)malloc(sizeof(play));
        		P->next=NULL; 
                if(fscanf(fp,"%d %d %s %s %d %d %d %d %d %d %d\n",&P->x,&P->movie.ID,P->movie.name,P->movie.type,&P->month,&P->date,&P->movie.time,&P->hour,&P->minute,&P->movie.price,&P->roomID)!=EOF){
					    if(P->x==x){
					    	return 1;
						}
						playHead->next=P;
                        playHead=playHead->next;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
        return 0;
}

void sortTime()
{
	FILE* fp=fopen("./data/play.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                //return ;
        }
        play* playHead=crPlayHead();
        play* p=playHead;
        play* q=playHead;
        play* temp=playHead;
        play* t=playHead;
        int cnt=0;
        while(1){
        		play* P=(play*)malloc(sizeof(play));
        		P->next=NULL; 
                if(fscanf(fp,"%d %d %s %s %d %d %d %d %d %d %d\n",&P->x,&P->movie.ID,P->movie.name,P->movie.type,&P->month,&P->date,&P->movie.time,&P->hour,&P->minute,&P->movie.price,&P->roomID)!=EOF){
					    cnt++;
						playHead->next=P;
                        playHead=playHead->next;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
        
        int i,j;
		play *tail;
        for(i=0;i<cnt-1;i++)
		{
			j=cnt-i-1;//内层次数
			q=temp->next;//q指向第一个结点 
			p=q->next;//p指向后一个
			tail=temp;//tail始终指向q前一个
			while(j--)
			{
				int flag=1;
				if(q->month>p->month)
				{
					flag=0;
				}
				if(q->month==p->month&&q->date>p->date)
				{
					flag=0;
				}
				if(q->month==p->month&&q->date==p->date&&q->hour>p->hour)
				{
					flag=0;
				}
				if(q->month==p->month&&q->date==p->date&&q->hour==p->hour&&q->minute>p->minute)
				{
					flag=0;
				}
				if(flag==0){
					q->next=p->next;
					p->next=q;
					tail->next=p;
				}
				tail=tail->next;
				q=tail->next;
				p=q->next;
			 } 
		} 
		
		FILE* f=fopen("./data/play.txt","w");
		if(f==NULL){
			color(13); 
			printf("\n\t\t\t\t打开文件失败！");
			return ;
		}
		t=t->next;
		while(t){
			fprintf(f,"%d %d %s %s %d %d %d %d %d %d %d\n",t->x,t->movie.ID,t->movie.name,t->movie.type,t->month,t->date,t->movie.time,t->hour,t->minute,t->movie.price,t->roomID);
			t=t->next;
		}
		fclose(f);
		f=NULL;
}




void readOrdersList()
{
		FILE* fp=fopen("./data/orders.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return ;
        }
        orders* ordersHead=crOrdersHead();
        char name[20];
        while(1){
        		orders* P=(orders*)malloc(sizeof(orders));
        		P->nex=NULL;
                if(fscanf(fp,"%s %d %d %d %s %s %d %d %d %d %d %d %d %d",name,&P->number,&P->play.x,&P->play.movie.ID,P->play.movie.name,P->play.movie.type,&P->play.month,&P->play.date,&P->play.movie.time,&P->play.hour,&P->play.minute,&P->play.roomID,&P->row,&P->column)!=EOF){
                		printf("\t\t\t  %-3d   %-3d    %-10s   %-4s  %d月%d日   %-2dmin   %d:%d     %-4d %d排%d列\n\n",P->number,P->play.movie.ID,P->play.movie.name,P->play.movie.type,P->play.month,P->play.date,P->play.movie.time,P->play.hour,P->play.minute,P->play.roomID,P->row,P->column);
					    ordersHead->nex=P;
                        ordersHead=ordersHead->nex;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
}

int findOrdersID(int n)
{
	FILE* fp=fopen("./data/orders.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
              
        }
        orders* ordersHead=crOrdersHead();
        char name[20];
        while(1){
        		orders* P=(orders*)malloc(sizeof(orders));
        		P->nex=NULL;
                if(fscanf(fp,"%s %d %d %d %s %s %d %d %d %d %d %d %d %d",name,&P->number,&P->play.x,&P->play.movie.ID,P->play.movie.name,P->play.movie.type,&P->play.month,&P->play.date,&P->play.movie.time,&P->play.hour,&P->play.minute,&P->play.roomID,&P->row,&P->column)!=EOF){
                	//	printf("\t\t\t  %-3d   %-3d    %-10s   %-4s  %d月%d日   %-2dmin   %d:%d     %-4d %d排%d列\n\n",P->number,P->play.movie.ID,P->play.movie.name,P->play.movie.type,P->play.month,P->play.date,P->play.movie.time,P->play.hour,P->play.minute,P->play.roomID,P->row,P->column);
					    if(P->number==n){
					    	return 1;
						}
					    ordersHead->nex=P;
                        ordersHead=ordersHead->nex;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
        return 0;
}

int findMovieID(int ID)
{
		FILE* fp=fopen("./data/movie.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
              //  return 0;
        }
        movie* movieHead=crMovieHead();
        while(1){
        		movie* P=(movie*)malloc(sizeof(movie));
        		P->next1=NULL;
                if(fscanf(fp,"%d %s %s %d %d %d %d %d %d",&P->ID,P->name,P->type,&P->time,&P->month,&P->date,&P->price,&P->num,&P->income)!=EOF){
					   if(ID==P->ID){
					   	return 1;
					   }
						movieHead->next1=P;
                        movieHead=movieHead->next1;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
        return 0;
}

int findMovieName(char name[])
{
	FILE* fp=fopen("./data/movie.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
              //  return 0;
        }
        movie* movieHead=crMovieHead();
        while(1){
        		movie* P=(movie*)malloc(sizeof(movie));
        		P->next1=NULL;
                if(fscanf(fp,"%d %s %s %d %d %d %d %d %d",&P->ID,P->name,P->type,&P->time,&P->month,&P->date,&P->price,&P->num,&P->income)!=EOF){
					   if(strcmp(P->name,name)==0){
					   	return 1;
					   }
						movieHead->next1=P;
                        movieHead=movieHead->next1;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
        return 0;
}



void ordersAdd(char usersName[],int x,int ID,int row,int column)
{
		FILE* fp=fopen("./data/movie.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return ;
        }
        movie* movieHead=crMovieHead();
        char name[20],type[20];
        int month,date,time;
        while(1){
        		movie* P=(movie*)malloc(sizeof(movie));
        		P->next1=NULL;
                if(fscanf(fp,"%d %s %s %d %d %d %d %d %d",&P->ID,P->name,P->type,&P->time,&P->month,&P->date,&P->price,&P->num,&P->income)!=EOF){
					    if(ID==P->ID){
					    	strcpy(name,P->name);
					    	strcpy(type,P->type);
//					    	month=P->month;
//					    	date=P->date;
					    	time=P->time;
					    	break;
						}
						movieHead->next1=P;
                        movieHead=movieHead->next1;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
        
        FILE* p=fopen("./data/play.txt","r");
        if(p==NULL){
                printf("打开文件失败\n");
               
        }
        play* playHead=crPlayHead();
        int hour,minute,roomID;
        while(1){
        		play* q=(play*)malloc(sizeof(play));
        		q->next=NULL; 
                if(fscanf(p,"%d %d %s %s %d %d %d %d %d %d %d\n",&q->x,&q->movie.ID,q->movie.name,q->movie.type,&q->month,&q->date,&q->movie.time,&q->hour,&q->minute,&q->movie.price,&q->roomID)!=EOF){
					    if(q->x==x){
					    	hour=q->hour;
							minute=q->minute;
							roomID=q->roomID;
							month=q->month;
							date=q->date;
							break;	
						}
						playHead->next=q;
                        playHead=playHead->next;
                }else{
                 		break;
                }
        }
        fclose(p);
        p=NULL;

	FILE* f=fopen("./data/orders.txt","a");
	if(f==NULL){
		color(13); 
		printf("\n\t\t\t\t打开文件失败！");
		return ;
	}
	int n=1000+rand()%(9999-1000+1);
	while(findOrdersID(n)){
		n=1000+rand()%(9999-1000+1);
	}
	fprintf(f,"%-10s %-3d %-3d %-3d %-10s %-8s %-3d %-3d %-4d %-3d %-3d %-3d %-3d %-3d\n",usersName,n,x,ID,name,type,month,date,time,hour,minute,roomID,row,column);
	fclose(f);
	f=NULL;
}

void cancelTicket(int ID)
{
	FILE* fp=fopen("./data/orders.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return ;
        }
        orders* ordersHead=crOrdersHead();
        orders* r=ordersHead;
        orders* t=ordersHead;
        while(1){
        		orders* P=(orders*)malloc(sizeof(orders));
        		P->nex=NULL;
                if(fscanf(fp,"%s %d %d %d %s %s %d %d %d %d %d %d %d %d",P->users.usersName,&P->number,&P->play.x,&P->play.movie.ID,P->play.movie.name,P->play.movie.type,&P->play.month,&P->play.date,&P->play.movie.time,&P->play.hour,&P->play.minute,&P->play.roomID,&P->row,&P->column)!=EOF){
					    ordersHead->nex=P;
                        ordersHead=ordersHead->nex;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
        
       	while (r->nex)	
	   {
	   	  orders* p = r->nex; 
		  if (p->play.movie.ID == ID)		  
		    {
		    	r->nex = p->nex;
		   		 free (p);
	        }	        
	      else
		  {
		  	r = r->nex;
		  }  		  
	   }
		
		
		FILE* f=fopen("./data/orders.txt","w");
		if(f==NULL){
			color(13); 
			printf("\n\t\t\t\t打开文件失败！");
			return ;
		}
		t=t->nex;
		while(t){
			fprintf(f,"%s %d %d %d %s %s %d %d %d %d %d %d %d %d\n",t->users.usersName,t->number,t->play.x,t->play.movie.ID,t->play.movie.name,t->play.movie.type,t->play.month,t->play.date,t->play.movie.time,t->play.hour,t->play.minute,t->play.roomID,t->row,t->column);
			t=t->nex;
		}
		fclose(f);
		f=NULL;
}



void readOrdersList_Delete(int x)
{
	FILE* fp=fopen("./data/orders.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return ;
        }
        orders* ordersHead=crOrdersHead();
        orders* l=ordersHead;
        orders* t=ordersHead;
        while(1){
        		orders* P=(orders*)malloc(sizeof(orders));
        		P->nex=NULL;
                if(fscanf(fp,"%s %d %d %d %s %s %d %d %d %d %d %d %d %d",P->users.usersName,&P->number,&P->play.x,&P->play.movie.ID,P->play.movie.name,P->play.movie.type,&P->play.month,&P->play.date,&P->play.movie.time,&P->play.hour,&P->play.minute,&P->play.roomID,&P->row,&P->column)!=EOF){
					    ordersHead->nex=P;
                        ordersHead=ordersHead->nex;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
        
       // l=l->nex;
        while(l->nex){
        	if(l->nex->number==x){
        		break;
			}
			l=l->nex;
		}
		orders* q=l->nex;
		l->nex=l->nex->nex;
		free(q);
		
		FILE* f=fopen("./data/orders.txt","w");
		if(f==NULL){
			color(13); 
			printf("\n\t\t\t\t打开文件失败！");
			return ;
		}
		t=t->nex;
		while(t){
			fprintf(f,"%s %d %d %d %s %s %d %d %d %d %d %d %d %d\n",t->users.usersName,t->number,t->play.x,t->play.movie.ID,t->play.movie.name,t->play.movie.type,t->play.month,t->play.date,t->play.movie.time,t->play.hour,t->play.minute,t->play.roomID,t->row,t->column);
			t=t->nex;
		}
		fclose(f);
		f=NULL;
}

void cancelTicket2(int x)
{
	FILE* fp=fopen("./data/orders.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return ;
        }
        orders* ordersHead=crOrdersHead();
        orders* l=ordersHead;
        orders* t=ordersHead;
        while(1){
        		orders* P=(orders*)malloc(sizeof(orders));
        		P->nex=NULL;
                if(fscanf(fp,"%s %d %d %d %s %s %d %d %d %d %d %d %d %d",P->users.usersName,&P->number,&P->play.x,&P->play.movie.ID,P->play.movie.name,P->play.movie.type,&P->play.month,&P->play.date,&P->play.movie.time,&P->play.hour,&P->play.minute,&P->play.roomID,&P->row,&P->column)!=EOF){
					    ordersHead->nex=P;
                        ordersHead=ordersHead->nex;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
        
       // l=l->nex;
        while(l->nex){
        	if(l->nex->play.x==x){
        		break;
			}
			l=l->nex;
		}
		orders* q=l->nex;
		l->nex=l->nex->nex;
		free(q);
		
		FILE* f=fopen("./data/orders.txt","w");
		if(f==NULL){
			color(13); 
			printf("\n\t\t\t\t打开文件失败！");
			return ;
		}
		t=t->nex;
		while(t){
			fprintf(f,"%s %d %d %d %s %s %d %d %d %d %d %d %d %d\n",t->users.usersName,t->number,t->play.x,t->play.movie.ID,t->play.movie.name,t->play.movie.type,t->play.month,t->play.date,t->play.movie.time,t->play.hour,t->play.minute,t->play.roomID,t->row,t->column);
			t=t->nex;
		}
		fclose(f);
		f=NULL;
}



int findOrders(int n)
{
		FILE* fp=fopen("./data/orders.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                //return ;
        }
        orders* ordersHead=crOrdersHead();
        while(1){
        		orders* P=(orders*)malloc(sizeof(orders));
        		P->nex=NULL;
                if(fscanf(fp,"%s %d %d %d %s %s %d %d %d %d %d %d %d %d",P->users.usersName,&P->number,&P->play.x,&P->play.movie.ID,P->play.movie.name,P->play.movie.type,&P->play.month,&P->play.date,&P->play.movie.time,&P->play.hour,&P->play.minute,&P->play.roomID,&P->row,&P->column)!=EOF){
					    if(P->number==n){
					    	return 0;
						}
					    ordersHead->nex=P;
                        ordersHead=ordersHead->nex;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
        return 1;
}





void readSeatList_Select(int roomID,int row,int column,int zt)
{
	FILE* fp=fopen("./data/seat.txt","r");
	if(fp==NULL){
		color(13); 
		printf("\n\t\t\t\t打开文件失败！");
		return ;
	}
	seat* seatHead=crSeatHead();
	seat* t=seatHead;
	while(1){
		seat* P=(seat*)malloc(sizeof(seat));
		if(fscanf(fp,"%d %d %d %d",&P->roomID,&P->row,&P->column,&P->status)!=EOF){
			if(P->roomID==roomID&&P->row==row&&P->column==column){
				P->status=zt;
			}
			P->next=NULL;
			seatHead->next=P;
			seatHead=seatHead->next;
		}else{
			break;
		}
	}
	fclose(fp);
	fp=NULL;
	
	FILE* f=fopen("./data/seat.txt","w");
	if(f==NULL){
		color(13); 
		printf("\n\t\t\t\t打开文件失败！");
		return ;
	}
	t=t->next;
	while(t){
		fprintf(f,"%d %d %d %d\n",t->roomID,t->row,t->column,t->status);
		t=t->next;
	}
	fclose(f);
	f=NULL;
}

void numReduce_And_SeatUpdate(int n)
{
		FILE* fp=fopen("./data/orders.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return ;
        }
        orders* ordersHead=crOrdersHead();
        int row,column;
        int ID;
        int roomID;
        while(1){
        		orders* q=(orders*)malloc(sizeof(orders));
        		q->nex=NULL;
                if(fscanf(fp,"%s %d %d %d %s %s %d %d %d %d %d %d %d %d",q->users.usersName,&q->number,&q->play.x,&q->play.movie.ID,q->play.movie.name,q->play.movie.type,&q->play.month,&q->play.date,&q->play.movie.time,&q->play.hour,&q->play.minute,&q->play.roomID,&q->row,&q->column)!=EOF){
                		if(n==q->number){
                			ID=q->play.movie.ID;
							row=q->row;
							column=q->column;
							roomID=q->play.roomID;
							break;
						} 
					    ordersHead->nex=q;
                        ordersHead=ordersHead->nex;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
        
        numReduce(ID);
        readSeatList_Select(roomID,row,column,0);
}

void numReduce(int ID)
{
		FILE* fp=fopen("./data/movie.txt","r");
        if(fp==NULL){
                printf("打开文件失败\n");
                return ;
        }
        movie* movieHead=crMovieHead();
        movie* t=movieHead;
        while(1){
        		movie* P=(movie*)malloc(sizeof(movie));
        		P->next1=NULL;
                if(fscanf(fp,"%d %s %s %d %d %d %d %d %d",&P->ID,P->name,P->type,&P->time,&P->month,&P->date,&P->price,&P->num,&P->income)!=EOF){
					    if(ID==P->ID){
					    	P->num-=1;
					    	P->income-=P->price;
						}
						movieHead->next1=P;
                        movieHead=movieHead->next1;
                }else{
                 		break;
                }
        }
        fclose(fp);
        fp=NULL;
        
        
		FILE* f=fopen("./data/movie.txt","w");
		if(f==NULL){
			color(13); 
			printf("\n\t\t\t\t打开文件失败！");
			return ;
		}

		t=t->next1;
		while(t){
			fprintf(f,"%d %s %s %d %d %d %d %d %d\n",t->ID,t->name,t->type,t->time,t->month,t->date,t->price,t->num,t->income);
			t=t->next1;
		}
		fclose(f);
		fp=NULL;
}




int findSeatByRC(int row,int column)
{
	FILE* fp=fopen("./data/seat.txt","r");
	if(fp==NULL){
		color(13); 
		printf("\n\t\t\t\t打开文件失败！");
		return 0;
	}
	seat* seatHead=crSeatHead();
	//seat* t=seatHead;
	while(1){
		seat* P=(seat*)malloc(sizeof(seat));
		if(fscanf(fp,"%d %d %d %d",&P->roomID,&P->row,&P->column,&P->status)!=EOF){
			if(P->row==row&&P->column==column){
				if(P->status==1){
					return 1;
				}
				if(P->status==-1){
					return -1;
				}
				if(P->status==0){
					return 0;
				}
				break;
			}
			P->next=NULL;
			seatHead->next=P;
			seatHead=seatHead->next;
		}else{
			break;
		}
	}
	fclose(fp);
	fp=NULL;

}

void deleteSeatCuzStudioModify(int ID,int row,int column)
{
	FILE* fp=fopen("./data/seat.txt","r");
	if(fp==NULL){
		color(13); 
		printf("\n\t\t\t\t打开文件失败！");
		return ;
	}
	seat* seatHead=crSeatHead();
	seat* t=seatHead;
	while(1){
		seat* P=(seat*)malloc(sizeof(seat));
		if(fscanf(fp,"%d %d %d %d",&P->roomID,&P->row,&P->column,&P->status)!=EOF){
			if(P->roomID==ID&&P->roomID<=row&&P->column<=column){
				P->next=NULL;
				seatHead->next=P;
				seatHead=seatHead->next;
			}
		}else{
			break;
		}
	}
	fclose(fp);
	fp=NULL;
	
	FILE* f=fopen("./data/seat.txt","w");
	if(f==NULL){
		color(13); 
		printf("\n\t\t\t\t打开文件失败！");
		return ;
	}
	t=t->next;
	while(t){
		fprintf(f,"%d %d %d %d\n",t->roomID,t->row,t->column,t->status);
		t=t->next;
	}
	fclose(f);
	f=NULL;
}

void printSeat(int roomID,int rows,int columns)
{
	FILE* fp=fopen("./data/seat.txt","r");
	if(fp==NULL){
		color(13); 
		printf("\n\t\t\t\t打开文件失败！");
		return ;
	}
	int i,j;
	seat* seatHead=crSeatHead();
//	seat* p=seatHead;
	printf("\t\t\t\t");
	int k=0,l=0;
	while(1){
		seat* P=(seat*)malloc(sizeof(seat));
		if(fscanf(fp,"%d %d %d %d",&P->roomID,&P->row,&P->column,&P->status)!=EOF){
			if(P->roomID==roomID){
				printf("%c  ",ztToChar(P->status));
				k++;
				if(k%columns==0&&l<rows){
					l++;
					printf("\n\t\t\t\t");
				}
				P->next=NULL;
				seatHead->next=P;
			}else{
				continue;
			}
		}else{
			break ;
		}
	}
	fclose(fp);
	fp=NULL;

}

//void playMoHu(char name[])
//{
//	FILE* p=fopen("./data/play.txt","r");
//        if(p==NULL){
//                printf("打开文件失败\n");
//                
//        }
//        play* playHead=crPlayHead();
//        play* r=playHead;
//        //int hour,minute,roomID;
//        while(1){
//        		play* q=(play*)malloc(sizeof(play));
//        		q->next=NULL; 
//                if(fscanf(p,"%d %d %s %s %d %d %d %d %d %d %d\n",&q->x,&q->movie.ID,q->movie.name,q->movie.type,&q->month,&q->date,&q->movie.time,&q->hour,&q->minute,&q->movie.price,&q->roomID)!=EOF){
////					    if(q->x==x){
////					    	hour=q->hour;
////							minute=q->minute;
////							roomID=q->roomID;	
////						}
//						playHead->next=q;
//                        playHead=playHead->next;
//                }else{
//                 		break;
//                }
//        }
//        fclose(p);
//        p=NULL;
//	
//	int i,j,n = 0;
//	r = playHead->next;
////	char name[20];                      //模糊查找的字符串
// 
////	printf("请输入你要查找的模糊字符串:");
////	getchar();
////	gets(name); 
//	char Listname[20];               //接收链表中的名字 
//	
//	printf("\n\t\t\t\t或许你想查找的是：\n");
//	
//    while(r)
//    {
//         strcpy(Listname,r->movie.name);
//         for(i = 0;i<strlen(Listname);i+=2)
//         {
//         	for(j = 0;j<strlen(name);j+=2)
//         	{
//         		if(Listname[i] == name[j]&&Listname[i+1] == name[j+1])
//         		{
//         			n++;
//				 }
//			 }
//		 }
//		 if(n == strlen(name)/2)
//		{
//			printf("\t\t\t\t%-3d  %-3d      %-8s     %-5s %d月%d日 %dmin  %d:%d %3d元 %4d\n\n",r->x,r->movie.ID,r->movie.name,r->movie.type,r->month,r->date,r->movie.time,r->hour,r->minute,r->movie.price,r->roomID);
//		}
//		n=0;
//		r = r->next;	
//	}
//}




