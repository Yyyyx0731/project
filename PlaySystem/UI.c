#include "UI.h"


#define UpKey 72
#define DownKey 80

char c1,ch;

char ztToChar(int x)
{
	if(x==1){
		return '#';//��ѡ 
	}else if(x==0){
		return '-';//��ѡ 
	}else if(x==-1){
		return '!';//�� 
	} 
}

void goto_xy(int x, int y)//��λ���λ�õ�ָ������
{   
    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { x,y };
    SetConsoleCursorPosition(hOut, pos);
}

void menu1()
{
		system("cls");
		system("color E2");
		
		printf("\n\n\n\n\n\n\n\n");
		printf("\t\t\t\t******************** �� ӭ �� �� **********************\n\n");
		printf("\t\t\t\t********");
		printf("             ��       ¼               ");
		printf("********\n\n");
		printf("\t\t\t\t********");
		printf("             ע       ��               "); 
		printf("********\n\n");
		printf("\t\t\t\t*******************************************************\n\n");
	
		int line=10;
		int choice=1;
		goto_xy(64, line);  
		 
	    while((c1 = getch())!='\r'){
			if (c1==-32){
				ch=getch();
			}
			//�����ƶ�
			if (ch== UpKey&&choice>1){
				choice-=1;
				line -= 2;							
				goto_xy(64, line);
				menu1();
			}	
			//�����ƶ�
			if (ch == DownKey&&choice<2){
				choice+=1;
				line += 2;
				goto_xy(64, line);
			}
			
		}
		if(choice==1){		 
		    //�����¼���� 
		    menuLogin1();
		}
		if(choice==2){
			//����ע����� 
			menuRegister1();
		}
		
}

void menuLogin1()
{
		system("color F1");
		system("cls");
		printf("\n\n\n\n\n\n\n\n");
		printf("\t\t\t\t******************** �� ¼ �� �� **********************\n\n");
		printf("\t\t\t\t********");
		printf("             ��       ��               ");
		printf("********\n\n");
		printf("\t\t\t\t********");
		printf("            ��    ��    Ա             "); 
		printf("********\n\n");
		printf("\t\t\t\t********");
		printf("             ��       ��               ");
		printf("********\n\n");
		printf("\t\t\t\t*******************************************************\n\n");
	
		int line=10;
		int choice=1;
		goto_xy(64, line);  
    	while((c1 = getch())!='\r'){
			if (c1==-32){
				ch=getch();
			}
			//�����ƶ�
			if (ch== UpKey&&choice>1){
				choice-=1;
				line -= 2;							
				goto_xy(64, line);
			//	menu1();
			}	
			//�����ƶ�
			if (ch == DownKey&&choice<3){
				choice+=1;
				line += 2;
			//	menuLogin2(movieHead);
				goto_xy(64, line);
			}
		}
		if(choice==1){		 
	    	//�û���¼                                       
			 menuUsersLogin(); 
		}
		if(choice==2){
			//����Ա��¼                                          
			menuAdminLogin();
		}
		if(choice==3){
			menu1();
		}
}


void menuRegister1()
{
		system("cls");
		system("color F1");
		printf("\n\n\n\n\n\n\n\n");
		printf("\t\t\t\t******************** ע �� �� �� **********************\n\n");
		printf("\t\t\t\t********");
		printf("             ��       ��              ");
		printf("********\n\n");
		printf("\t\t\t\t********");
		printf("            ��    ��    Ա             "); 
		printf("********\n\n");
		printf("\t\t\t\t********");
		printf("             ��       ��               "); 
		printf("********\n\n");
		printf("\t\t\t\t*******************************************************\n\n");
	
		int line=10;
		int choice=1;
		goto_xy(64, line);  
    	while((c1 = getch())!='\r'){
			if (c1==-32){
				ch=getch();
			}
			//�����ƶ�
			if (ch== UpKey&&choice>1){
				choice-=1;
				line -= 2;							
				goto_xy(64, line);
			//	menu1();
			}	
			//�����ƶ�
			if (ch == DownKey&&choice<3){
				choice+=1;
				line += 2;
				goto_xy(64, line);
			}
		}
		if(choice==1){
			menuUsersRegister();
		}
		if(choice==2){
			menuAdminRegister();
		}
		if(choice==3){
			menu1();
		}
	
}

//��������ʱ����Ϊ*�� 
//pwdΪ����ֵ
void passwordInput(char pwd[]){
	char input_char;
	int index = 0;
	fflush(stdin);//������뻺��
	//������ʾ*����֧���˸�  
	while((input_char = getch()) != '\r'){//���з� 
		if(input_char == '\b'){//�˸�� 
			if(index < 0)
				continue;
			if(index > 0){
				putchar('\b');
				putchar(' ');
				putchar('\b');
				index--;
			}	
		}else{
			printf("*");
			pwd[index++] = input_char;
		}
	}
	pwd[index] = '\0';//������ 
}

void menuUsersLogin()//�û���¼����
{
	char name[20];
	char password[20];


	system("cls");
	system("color F5");
	printf("\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t******************** �� ¼ �� �� **********************\n\n");
	printf("\t\t\t\t-------------------���س���ȷ������--------------------\n\n");
	printf("\t\t\t\t********");
	printf("   �� �� �� ��                         ");
	printf("********\n\n"); 
	printf("\t\t\t\t********");
	printf("      �� �� ��                         "); 
	printf("********\n\n");
	printf("\t\t\t\t*******************************************************\n\n");
	
	int line=12;
	int choice=1;
	goto_xy(54, line);  
	gets(name);

	
	line += 2;
	goto_xy(54, line);
	passwordInput(password);

	
	//�ж��û����û����������Ƿ���ȷ 
	if(usersCheck_BLL(name,password)==1){                 
		//��ȷ������û��˵�
		//��ȡ�û�
		printf("\n\t\t\t\t\t\t��½�ɹ������س���������");
		getchar();
		usersMenu1(name);
	}else if(usersCheck_BLL(name,password)==-1){
		printf("\n\t\t\t\t\t   ���û������ڣ����س�����ע��ҳ�档");
		getchar();
		menuUsersRegister();
	}else if(usersCheck_BLL(name,password)==0){
		printf("\n\t\t\t\t\t    �û�����������󣡰��س��������롣");
		getchar();
		menuUsersLogin();
	}
	 
} 

void menuAdminLogin()//����Ա��¼���� 
{
	char name[20];
	char password[20];
	system("color F5");
	system("cls");
	printf("\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t******************** �� ¼ �� �� **********************\n\n");
	printf("\t\t\t\t-------------------���س���ȷ������--------------------\n\n");
	printf("\t\t\t\t********");
	printf("   �� �� �� ��                         ");
	printf("********\n\n"); 
	printf("\t\t\t\t********");
	printf("      �� �� ��                         "); 
	printf("********\n\n");
	printf("\t\t\t\t*******************************************************\n\n");
	
	int line=12;
	int choice=1;
	goto_xy(54, line);  
	gets(name);
	
	line += 2;
	goto_xy(54, line);
	passwordInput(password);

	//�жϹ���Ա���û����������Ƿ���ȷ 
	if(adminCheck_BLL(name,password)==1){//ͨ�����������㣬���û���ʱ�����Ƿ���ȷ // 
		//��ȷ��������Ա�˵�
		printf("\n\t\t\t\t\t\t��½�ɹ������س���������");
		getchar();
		adminMenu();
	}else if(adminCheck_BLL(name,password)==0){
		printf("\n\t\t\t\t�û���������������������롣���س�������");
		getchar();
		menuAdminLogin();
	}else if(adminCheck_BLL(name,password)==-1){
		printf("\n\t\t\t\t\t   ���û������ڣ����س�����ע��ҳ�档");
		getchar();
		menuAdminRegister();
	}
}

void menuUsersRegister()//�û�ע����� 
{
	char name[20];
	char tel[20]; 
	char password[20];
	
		system("color F5");
		system("cls");
		printf("\n\n\n\n\n\n\n\n");
		printf("\t\t\t\t******************** ע �� �� �� **********************\n\n");
		printf("\t\t\t\t********");
		printf("   �� �� �� ��                         ");
		printf("********\n\n"); 
		printf("\t\t\t\t********");
		printf("      �� �� ��                         "); 
		printf("********\n\n");
		printf("\t\t\t\t********");
		printf("      �� �� ��                         "); 
		printf("********\n\n");
		printf("\t\t\t\t********");
		printf("ȷ �� �� �� ��                         "); 
		printf("********\n\n");
		printf("\t\t\t\t*******************************************************\n\n");
	
		fflush(stdin);
		int line=10;
		goto_xy(54, line);
		gets(name); 
		int i,flag=1;
		for(i=0;name[i]!='\0';i++){
				ch=name[i];
				if(!(ch>=48&&ch<=57)&&!(ch==95)&&!(ch>=65&&ch<=90)&&!(ch>=97&&ch<=122)){
					flag=0;
					break;
				}
		}
		if(strlen(name)==0){
			printf("\t\t\t\t         �û�������Ϊ�գ����س��������롣");
			fflush(stdin);
			getchar();
			menuUsersRegister(); 
		} 
		if(flag==0){
			printf("\t\t\t\t\t�û���ֻ�������֡���ĸ���»�����ɣ����س��������롣");
			fflush(stdin);
			getchar();
			menuUsersRegister(); 
		}
		i++;
		if(i>12){
			printf("\t\t\t\t\t\t�û������ó���12λ�����س��������롣"); 
			fflush(stdin);
			getchar();
			menuUsersRegister();
		}	
		if(findUsersName(name)){
			color(14);
			printf("\n\t\t\t\t���û����Ѵ��ڣ����س��������롣");
			fflush(stdin);
			getchar();
			menuUsersRegister();
		}	
		
		line += 2;
		goto_xy(54, line);
		gets(tel);
		if(strlen(tel)==0){
			printf("\t\t\t\t             �绰����Ϊ�գ����س��������롣");
			fflush(stdin);
			getchar();
			menuUsersRegister(); 
		} 
		line += 2;
		goto_xy(54, line);
		passwordInput(password);
		flag=1;
		for(i=0;password[i]!='\0';i++){
				ch=password[i];
				if(!(ch>=48&&ch<=57)&&!(ch>=65&&ch<=90)&&!(ch>=97&&ch<=122)){
					flag=0;
					break;
				}
		}
		if(flag==0){
			printf("\n\t\t\t\t\t    ����ֻ�������֡���ĸ��ɣ����س��������롣");
			fflush(stdin);
			getchar();
			menuUsersRegister(); 
		}
		i++;
		if(i>12||i<6){
			printf("\n\t\t\t\t\t    ����ֻ����6~12λ֮�䣡���س��������롣"); 
			fflush(stdin);
			getchar();
			menuUsersRegister();
		}		
		goto_xy(54, 18);

		char password2[20]; 
		line += 2;
		goto_xy(54, line);
		passwordInput(password2);
		if(strcmp(password,password2)){
			printf("\n\t\t\t\t�����������벻һ�£����س��������롣");
			fflush(stdin);
			getchar();
			menuUsersRegister();
		}
	
		
		//�����û�
		addUsersNode_BLL(name,tel,password);
		printf("\n\t\t\t\t\t\tע��ɹ������س���������");
		getchar();
		usersMenu1(name);
	
}

void menuAdminRegister()//����Աע����� 
{
	char name[20];
	char tel[20];
	char password[20];
	system("color F5");
	system("cls");
	printf("\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t******************** ע �� �� �� **********************\n\n");
	printf("\t\t\t\t********");
	printf("   �� �� �� ��                         ");
	printf("********\n\n"); 
	printf("\t\t\t\t********");
	printf("      �� �� ��                         "); 
	printf("********\n\n");
	printf("\t\t\t\t********");
	printf("      �� �� ��                         "); 
	printf("********\n\n");
	printf("\t\t\t\t********");
	printf("ȷ �� �� �� ��                         "); 
	printf("********\n\n");
	printf("\t\t\t\t********");
	printf("   �� ֤ �� ��                         "); 
	printf("********\n\n");
	printf("\t\t\t\t*******************************************************\n\n");
	
		int line=10;
		goto_xy(54, line);
		gets(name); 
		int i,flag=1;
		for(i=0;name[i]!='\0';i++){
				ch=name[i];
				if(!(ch>=48&&ch<=57)&&!(ch==95)&&!(ch>=65&&ch<=90)&&!(ch>=97&&ch<=122)){
					flag=0;
					break;
				}
		}
		if(strlen(name)==0){
			printf("\t\t\t\t         �û�������Ϊ�գ����س��������롣");
			fflush(stdin);
			getchar();
			menuAdminRegister(); 
		} 
		if(flag==0){
			printf("\t\t\t\t\t�û���ֻ�������֡���ĸ���»�����ɣ����س��������롣");
			fflush(stdin);
			getchar();
			menuAdminRegister(); 
		}
		i++;
		if(i>12){
			printf("\t\t\t\t\t\t�û������ó���12λ�����س��������롣"); 
			fflush(stdin);
			getchar();
			menuAdminRegister();
		}	
		if(findAdminName(name)){
			color(14);
			printf("\n\t\t\t\t���û����Ѵ��ڣ����س��������롣");
			fflush(stdin);
			getchar();
			menuAdminRegister();
		}	
		
		line += 2;
		goto_xy(54, line);
		gets(tel);
		
		line += 2;
		goto_xy(54, line);
		passwordInput(password);
		flag=1;
		for(i=0;password[i]!='\0';i++){
				ch=password[i];
				if(!(ch>=48&&ch<=57)&&!(ch>=65&&ch<=90)&&!(ch>=97&&ch<=122)){
					flag=0;
					break;
				}
		}
		if(flag==0){
			printf("\n\t\t\t\t\t    ����ֻ�������֡���ĸ��ɣ����س��������롣");
			fflush(stdin);
			getchar();
			menuAdminRegister(); 
		}
		i++;
		if(i>12||i<6){
			printf("\n\t\t\t\t\t    ����ֻ����6~12λ֮�䣡���س��������롣"); 
			fflush(stdin);
			getchar();
			menuAdminRegister();
		}		
		goto_xy(54, 18);

		char password2[20]; 
		line += 2;
		goto_xy(54, line);
		passwordInput(password2);
		if(strcmp(password,password2)){
			printf("\n\t\t\t\t�����������벻һ�£����س��������롣");
			fflush(stdin);
			getchar();
			menuAdminRegister();
		}
		
		char pass[20];
		line += 2;
		goto_xy(54, line);
		//printf("\n\t\t\t\t��������֤�룺");
		scanf("%s",pass);
		while(passCheck(pass)==0){
			printf("\n\t\t\t\t��֤��������������룺");
			scanf("%s",pass);
		}
	
	//�������Ա���� 
	addAdminNode_BLL(name,tel,password);//                                              //
	printf("\n\t\t\t\t\t\tע��ɹ������س���������");
	fflush(stdin);
	getchar();
	adminMenu();
}


//�û����ܲ˵� �����ݳ�����Ʊ����Ʊ�� 
void usersMenu1(char name[])
{
	system("color E1");
	system("cls");
	printf("\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t********************   ��   ��   **********************\n\n");
	printf("\t\t\t\t");
	printf("                     �� �� �� ��                       ");
	printf("\n\n"); 
	printf("\t\t\t\t");
	printf("                     �� ѯ �� Ӱ                       ");
	printf("\n\n"); 
	printf("\t\t\t\t");
	printf("                     �� �� �� ��                         "); 
	printf("\n\n");
	printf("\t\t\t\t");
	printf("                     �� �� �� ��                         "); 
	printf("\n\n");
	printf("\t\t\t\t");
	printf("                     �� �� �� ¼                        "); 
	printf("\n\n"); 
	printf("\t\t\t\t*******************************************************\n\n");
	
	int line=10;
	int choice=1;
	goto_xy(64, line);  
	
    while((c1 = getch())!='\r'){
		if (c1==-32){
				ch=getch();
			}
		//�����ƶ�
			if (ch== UpKey&&choice>1){
				choice-=1;
				line -= 2;							
				goto_xy(64, line);
			//	menu1();
			}	
			//�����ƶ�
			if (ch == DownKey&&choice<5){
				choice+=1;
				line += 2;
				goto_xy(64, line);
			}
	}
	if(choice==1){		 
	    //�û��ݳ��б����
		usersMovies(name);
	}
	if(choice==2){
		//��ѯ�ݳ� 
		usersSearch(name);
	}
	if(choice==3){
		//�鿴��������
		viewOrders(name);
	}
	if(choice==4){
		modifyPassword(name); //�޸����� 
	} 
	if(choice==5){
		exit(0);
	} 
	
}


//����Ա���ܲ˵�
void adminMenu()
{
	system("color E1");
	system("cls");
	printf("\n\n\n\n\n\n");
	printf("\t\t\t\t********************   ��   ��   **********************\n\n");
	printf("\t\t\t\t");
	printf("                     �� ѯ �� ��                        ");
	printf("\n\n"); 
	printf("\t\t\t\t");
	printf("                     �� Ӱ �� ��                       "); 
	printf("\n\n");
	printf("\t\t\t\t");
	printf("                     �� �� �� ��                          "); 
	printf("\n\n"); 
	printf("\t\t\t\t");
	printf("                    �� �� �� �� ��                     "); 
	printf("\n\n");
	printf("\t\t\t\t");
	printf("                     �� �� �� λ                         "); 
	printf("\n\n");
	printf("\t\t\t\t");
	printf("                   Ʊ �� �� �� �� ��                        "); 
	printf("\n\n");
	printf("\t\t\t\t");
	printf("                     �� �� �� ��                         "); 
	printf("\n\n"); 
	printf("\t\t\t\t");
	printf("                     �� �� �� ¼                        "); 
	printf("\n\n"); 
	printf("\t\t\t\t*******************************************************\n\n");
	
	int line=8;
	int choice=1;
	goto_xy(66, line);  
	
    while((c1 = getch())!='\r'){
		if (c1==-32){
				ch=getch();
			}
		//�����ƶ�
		if (ch== UpKey&&choice>1){
			choice-=1;
			line -= 2;							
			goto_xy(66, line);		
		}
		//�����ƶ�
		if (ch == DownKey&&choice<8){
			choice+=1;
			line += 2;
			goto_xy(66, line);
		}		
	}
	
	if(choice==1){		 
	    //����Ա�ݳ��б����
		adminMovies();
	}
	if(choice==2){
		//�����Ӱ���� 
		manageMovie();
	}
	if(choice==3){
		managePlay();
	} 
	if(choice==4){
		//�����ݳ������� 
		manageStudio();
	}
	if(choice==5){
		//������λ 
		manageSeat();
	}
	if(choice==6){
		//Ʊ�������۶���� 
		income(); 
	}
	if(choice==7){
		//�û����Ͻ��� 
		usersInformation();
	}
	if(choice==8){
		exit(0);
	}
	
}



//�û��ݳ��б���Ʊ�� 
void usersMovies(char name[])
{	
	system("color 07");
	system("cls");
	color(7);
	printf("\n\n"); 
	printf("\t\t\t********************************* �� �� �� �� ******************************\n");
	printf("\t\t\t%-3s %-3s     %-8s    %-5s  %-12s  %-5s   %-5s %-6s %6s\n","����","��ӰID","����","����","����","ʱ��","ʱ��","Ʊ��","Ӱ��ID");
	printf("\t\t\t----------------------------------------------------------------------------\n\n");
	//ѭ����������
	sortTime();
	readPlayList();

	color(7);
	printf("\t\t\t----------------------------------------------------------------------------\n");
	color(10);
	printf("\t\t\t\t\t        [B]uy ��Ʊ | [R]eturn ����\n");
	color(7);
	printf("\t\t\t****************************************************************************\n\n");
	char ch;
	color(14); 
	printf("\n\n\t\t\t��������Ҫ���еĲ�����");
	fflush(stdin);
	scanf("%c",&ch);
	if(ch=='B'||ch=='b'){
		printf("\n\t\t\t��������Ҫ����ĵ�Ӱ����:");
		int x;
		fflush(stdin);
		scanf("%d",&x); 
		//����ѡ������
		selectSeat(x,name);		 
	}else if(ch=='r'||ch=='R'){
		usersMenu1(name);
	}else{
		usersMovies(name);
	}
	
}

void adminMovies()
{	
	system("color 07");
	system("cls");
	color(7);
	printf("\n\n"); 
		printf("\t\t\t********************************* �� �� �� �� ******************************\n");
	printf("\t\t\t\t%-3s %-3s     %-8s    %-5s  %-12s  %-5s   %-5s %-6s %6s\n","����","��ӰID","����","����","����","ʱ��","ʱ��","Ʊ��","Ӱ��ID");
	printf("\t\t\t----------------------------------------------------------------------------\n\n");
	//ѭ����������
	color(13);
	fflush(stdout);
	sortTime();
	readPlayList();

	color(7);
	printf("\t\t\t---------------------------------------------------------------------------\n");
	color(10);
	printf("\t\t\t\t\t[S]earch ��ѯ | [R]eturn ����\n");
	color(7);
	printf("\t\t\t***************************************************************************\n\n");

	color(14); 
	printf("\n\n\t\t\t��������Ҫ���еĲ�����");
	fflush(stdin);
	char ch=getchar();
		 
	if(ch=='r'||ch=='R'){
		adminMenu();
	}else if(ch=='s'||ch=='S'){
		adminSearch();
	}else{
		adminMovies();
	}
	
}

//ѡ������
void selectSeat(int x,char name[]) 
{
	system("color 07");
	system("cls");

	
	//���ļ�������
	int roomID=readPlayList_Search(x); 

	
    printf("\n\n\n\n");
    color(7);
    printf("\t\t\t\t========================================================\n");
    printf("\t\t\t\t*********************  Room  %2d  **********************\n",roomID);
    printf("\t\t\t\t--------------------------------------------------------\n");
	int rows=readStudioList_row(roomID); 
	int columns=readStudioList_column(roomID);
	//��ӡ��λ 
	fflush(stdout);
	printSeat(roomID,rows,columns);

	printf("--------------------------------------------------------\n");
	color(14);
	printf("\t\t\t\t\t[S]elete ѡ��      |         [R]eturn ����\n");
	color(7);
	printf("\t\t\t\t========================================================\n\n");
	color(14);
	printf("\t\t\t\t��������Ҫ���еĲ�����");
	fflush(stdin);
	char c=getchar(); 
	while(c!='s'&&c!='S'&&c!='r'&&c!='R'){
		color(14);
		printf("\n\t\t\t\t���벻���Ϲ涨�����������룺"); 
		fflush(stdin);
		c=getchar();
	} 
	if(c=='s'||c=='S'){
		printf("\n\t\t\t\t������Ҫѡ�����λ���кţ�");
		int row,column;
		scanf("%d %d",&row,&column);
		if(findSeatByRC(row,column)==1){
			color(14);
			printf("\n\t\t\t\t����λ�ѱ�ѡ�������ظ�ѡ�񣡰��س�������"); 
			getchar();getchar();
			selectSeat(x,name);
		}else if(findSeatByRC(row,column)==-1){
			color(14);
			printf("\n\t\t\t\t����λ�𻵣�����ѡ�񣡰��س�������");
			getchar();getchar();
			selectSeat(x,name);
		}
		
		if(seatModify_BLL(roomID,row,column,1)){//     seleteSeat_BLL()��ѡ��ɹ���Ҫ������λ״̬    //
			color(14);
			int ID=PlayList_SearchID(x);
			ordersAdd_BLL(name,x,ID,row,column);//             ���붩������                  //
			//Ʊ�������۶�+1��
			updatePrice_BLL(ID);//         ����ĳ��Ӱ��Ʊ�������۶�         //
		//	sortIncome(); 
			printf("\n\t\t\t\tѡ���ɹ������س�����\n");
			getchar();getchar();
			selectSeat(x,name);
		}else{
			color(14);
			printf("\n\t\t\t\tѡ��ʧ�ܣ�\n");
			selectSeat(x,name);
		}
	}else if(c=='r'||c=='R'){
		usersMovies(name);
	}
	
} 

//��ѯ�ݳ�ѡ���id��Ƭ�������ͣ����ڣ� 
void usersSearch(char name[])
{
	system("color 07");
	system("cls");
	color(7);
	printf("\n\n\n\n\n\n");
	printf("\t\t\t\t******************** �� ѯ �� �� **********************\n\n");
	printf("\t\t\t\t-------------------------------------------------------\n\n");
	color(14);
	printf("\t\t\t\t");
	printf("                     Ƭ �� �� ѯ                       ");
	printf("\n\n"); 
	printf("\t\t\t\t");
	printf("                     ID  ��   ѯ                       "); 
	printf("\n\n");
	printf("\t\t\t\t");
	printf("                     �� �� �� ѯ                     "); 
	printf("\n\n");
	printf("\t\t\t\t");
	printf("                     �� �� �� ѯ                        "); 
	printf("\n\n");
	printf("\t\t\t\t");
	printf("                     ��       ��                     "); 
	printf("\n\n");
	color(7);
	printf("\t\t\t\t-------------------------------------------------------\n\n");
	printf("\t\t\t\t*******************************************************\n\n");
	
	int line=10;
	int choice=1;
	goto_xy(64, line);  
	
    while((c1 = getch())!='\r'){
		if (c1==-32){
				ch=getch();
			}
		//�����ƶ�
		if (ch== UpKey&&choice>1){
			choice-=1;
			line -= 2;							
			goto_xy(64, line);		
		}
		//�����ƶ�
		if (ch == DownKey&&choice<5){
			choice+=1;
			line += 2;
			goto_xy(64, line);
		}		
	}	
	if(choice==5){
		usersMenu1(name);
	}else{
		usersSearching(choice,name);
	}
		
}

void adminSearch()
{
	system("color 07");
	system("cls");
	color(7);
	printf("\n\n\n\n\n\n");
	printf("\t\t\t\t******************** �� ѯ �� �� **********************\n\n");
	printf("\t\t\t\t-------------------------------------------------------\n\n");
	color(14);
	printf("\t\t\t\t");
	printf("                     Ƭ �� �� ѯ                       ");
	printf("\n\n"); 
	printf("\t\t\t\t");
	printf("                     ID  ��   ѯ                       "); 
	printf("\n\n");
	printf("\t\t\t\t");
	printf("                     �� �� �� ѯ                     "); 
	printf("\n\n");
	printf("\t\t\t\t");
	printf("                     �� �� �� ѯ                        "); 
	printf("\n\n");
	printf("\t\t\t\t");
	printf("                     ��       ��                     "); 
	printf("\n\n");
	color(7);
	printf("\t\t\t\t-------------------------------------------------------\n\n");
	printf("\t\t\t\t*******************************************************\n\n");
	
	int line=10;
	int choice=1;
	goto_xy(64, line);  
	
    while((c1 = getch())!='\r'){
		if (c1==-32){
				ch=getch();
			}
		//�����ƶ�
		if (ch== UpKey&&choice>1){
			choice-=1;
			line -= 2;							
			goto_xy(64, line);		
		}
		//�����ƶ�
		if (ch == DownKey&&choice<5){
			choice+=1;
			line += 2;
			goto_xy(64, line);
		}		
	}	
	if(choice==5){
		adminMenu();
	}else{
		adminSearching(choice);
	}
		
}
	 
	 
//���в�ѯ���� 
void usersSearching(int choice,char name[])
{
	system("color 07");
	system("cls");
	color(7);
	printf("\n\n\n\n\n\n");
	printf("\t\t\t********************************* �� �� �� �� ******************************\n");
	printf("\t\t\t%-3s %-3s     %-8s    %-5s  %-12s  %-5s   %-5s %-6s %6s\n","����","��ӰID","����","����","����","ʱ��","ʱ��","Ʊ��","Ӱ��ID");
	printf("\t\t\t----------------------------------------------------------------------------\n\n");

	if(choice==1){
		printf("\t\t\t\t������Ҫ��ѯ�ĵ�Ӱ���ƣ�");
		char name[20];
		scanf("%s",name);
		printf("\n");
		playSearch_Name(name);
	}
	if(choice==2){
		printf("\t\t\t\t������Ҫ��ѯ�ĵ�ӰID��");
		int ID;
		scanf("%d",&ID);
		printf("\n");
		playSearch_ID(ID);

	}
	if(choice==3){
		printf("\t\t\t\t������Ҫ��ѯ�ĵ�Ӱ���ͣ�");
		char type[20];
		scanf("%s",type);
		printf("\n");
		playSearch_Type(type);
		
	}
	if(choice==4){
		int date,month;
		printf("\t\t\t\t������Ҫ��ѯ���·ݺ����ڣ��ÿո��������");
		scanf("%d",&month);
		scanf("%d",&date);
		printf("\n");
		playSearch_Date(month,date);

	}                                             //

	color(7);
	printf("\t\t\t----------------------------------------------------------------------------\n");
	color(10);
	printf("\t\t\t\t\t      [S]earch ������ѯ |[R]eturn ����\n");
	color(7);
	printf("\t\t\t****************************************************************************\n\n");
	color(14);
	fflush(stdin);
	printf("\t\t\t\t��������Ҫ���еĲ�����");
	fflush(stdin);
	char x=getchar();
	while(x!='s'&&x!='S'&&x!='r'&&x!='R'&&x!='b'&&x!='B'){
		color(14);
		printf("\t\t\t������Ĳ��������Ϲ涨�����������룺");
		scanf("%c",&x);
	}
	if(x=='R'||x=='r'){
		usersMenu1(name);
	}else if(x=='S'||x=='s'){
		usersSearch(name);
	}
	
}

void adminSearching(int choice)
{
	system("color 07");
	system("cls");
	color(7);
	printf("\n\n\n\n\n\n");
	printf("\t\t\t********************************* �� �� �� �� ******************************\n");
	printf("\t\t\t%-3s %-3s     %-8s    %-5s  %-12s  %-5s   %-5s %-6s %6s\n","����","��ӰID","����","����","����","ʱ��","ʱ��","Ʊ��","Ӱ��ID");
	printf("\t\t\t----------------------------------------------------------------------------\n\n");

	if(choice==1){
		printf("\t\t\t������Ҫ��ѯ�ĵ�Ӱ���ƣ�");
		char name[20];
		scanf("%s",name);
		printf("\n");
		playSearch_Name(name);
	}
	if(choice==2){
		printf("\t\t\t������Ҫ��ѯ�ĵ�ӰID��");
		int ID;
		scanf("%d",&ID);
		printf("\n");
		playSearch_ID(ID);
	}
	if(choice==3){
		printf("\t\t\t������Ҫ��ѯ�ĵ�Ӱ���ͣ�");
		char type[20];
		scanf("%s",type);
		printf("\n");
		playSearch_Type(type);
		
	}
	if(choice==4){
		int date,month;
		printf("\t\t\t������Ҫ��ѯ���·ݺ����ڣ��ÿո��������");
		scanf("%d",&month);
		scanf("%d",&date);
		printf("\n");
		playSearch_Date(month,date);

	}
	color(7);
	printf("\t\t\t----------------------------------------------------------------------------\n");
	color(10);
	printf("\t\t\t\t\t[S]earch ������ѯ | [R]eturn ����\n");
	color(7);
	printf("\t\t\t****************************************************************************\n\n");
	color(14);
	printf("\t\t\t��������Ҫ���еĲ�����");
	char x;
	fflush(stdin);
	scanf("%c",&x);
	while(x!='s'&&x!='S'&&x!='r'&&x!='R'){
		color(14);
		printf("\n\t\t\t������Ĳ��������Ϲ涨�����������룺");
		scanf("%c",&x);
	}
	if(x=='R'||x=='r'){
		adminMenu();
	}else if(x=='S'||x=='s'){
		adminSearch();
	}
	
}


//�鿴��������Ʊ�� 
void viewOrders(char name[])
{
	system("color 07");
	system("cls");
	color(14);
	system("cls");
	color(7);
	printf("\n\n\n\n\n\n");
	printf("\t\t\t******************************** �� �� �� �� *****************************\n\n");
	printf("\t\t\t%-3s %-2s     %-6s    %-4s   %-6s  %-6s %-6s %-6s %6s\n\n","�������","��ӰID","����","����","����","ʱ��","�ݳ�ʱ��","Ӱ��ID","��λ");
	printf("\t\t\t--------------------------------------------------------------------------\n\n");
	sortIncome();
	readOrdersList();

	color(7);
	printf("\t\t\t--------------------------------------------------------------------------\n");
	color(10);
	printf("\t\t\t\t            [C]ancel ��Ʊ    |    [R]eturn ����\n");
	color(7);
	printf("\t\t\t**************************************************************************\n\n");
	color(14);
	printf("\t\t\t��������Ҫ���еĲ�����");
	char x;
	fflush(stdin); 
	scanf("%c",&x);
	while(x!='c'&&x!='C'&&x!='r'&&x!='R'){
		color(14);
		printf("\n\t\t\t������Ĳ��������Ϲ涨�����������룺");
		scanf("%c",&x);
	}
	if(x=='c'||x=='C'){
		printf("\n\t\t\t��������Ҫ��Ʊ�Ķ�����ţ�");
		int n;
		fflush(stdin);
		scanf("%d",&n);
		while(findOrders(n)){
			color(14);
			printf("\n\t\t\t\t�ö����Ų����ڣ����������룺");
			fflush(stdin);
			scanf("%d",&n);
		}
		deleteOrders_BLL(n);
		numReduce_And_SeatUpdate(n);
		color(14);
		printf("\n\t\t\t\t��Ʊ�ɹ������س�������");
		fflush(stdin);
		getchar();
		viewOrders(name);
	}else if(x=='r'||x=='R'){
		usersMenu1(name);
	}
	
}

 
//����Ա���� 
void manageMovie()
{
	system("color 07");
	system("cls");
	color(7);
	printf("\n\n"); 
	printf("\t\t\t\t************************** �� Ӱ �� �� ***********************\n");
	printf("\t\t\t\t%-3s        %-8s      %-8s  %-5s %-5s   %-6s\n","ID","����","����","ʱ��","��ӳ����","Ʊ��");
	printf("\t\t\t\t--------------------------------------------------------------\n\n");
	//ѭ����������
	sortMovieByID();
	readMovieList();

	color(7);
	printf("\t\t\t\t--------------------------------------------------------------\n\n");
	color(10);
	printf("\t\t\t\t[A]dd ���� |[D]elete ɾ�� |[M]odify �޸� |[R]eturn ����\n");
	color(7);
	printf("\t\t\t\t**************************************************************\n\n");

	color(14); 
	printf("\n\n\t\t\t\t��������Ҫ���еĲ�����");
	fflush(stdin);
	char ch=getchar();
 
	if(ch=='a'||ch=='A'){
		printf("\n"); 
	   
	    int ID,time,date,month,price,roomID;
	    char name[20],type[20];
//		printf("����������ӵ�Ӱ��ID��");
//		scanf("%d",&ID);
//		while(findMovieID(ID)){
//			printf("\n��ID�Ѵ��ڣ����������룺"); 
//			fflush(stdin);
//			scanf("%d",&ID);
//		}
		printf("\n����������ӵ�Ӱ�����ƣ�");
		scanf("%s",name); 
		while(findMovieName(name)){
			printf("\n\t\t\t\t�õ�Ӱ�Ѵ��ڣ����������룺");
			fflush(stdin);
			scanf("%s",name);
		}
		printf("\n����������ӵ�Ӱ�����ͣ�");
		scanf("%s",type);
		printf("\n���������ӵ�Ӱ��ʱ�������ӣ�:");
		scanf("%d",&time);
		printf("\n���������ӵ�Ӱ����ӳ���ڣ��·ݺ������ÿո������:");
		scanf("%d %d",&month,&date);
		while(month<1||month>12||date<1||date>31){
			printf("\n\t\t\t\t���ڲ���ȷ�����������룺");
			fflush(stdin);
			scanf("%d %d",&month,&date);
		} 
		printf("\n���������ӵ�Ӱ��Ʊ��:");
		scanf("%d",&price);
	
		//movieAdd(ID,name,type,time,month,date,price);
		movieAdd(name,type,time,month,date,price);
		printf("\n\t\t\t\t��ӳɹ���");
		printf("\n\t\t\t\t���س�����");
		fflush(stdin);
		getchar();
		manageMovie();
	}
	if(ch=='d'||ch=='D'){
		printf("\n"); 
		printf("�������ɾ���ĵ�ӰID��");
		int ID;
		scanf("%d",&ID);
		while(findMovieID(ID)==0){
			printf("\n��ID�����ڣ����������룺"); 
			fflush(stdin);
			scanf("%d",&ID);
		}
		movieDelete_BLL(ID);
		deletePlay(ID);
		cancelTicket(ID);
		printf("\n\t\t\t\tɾ���ɹ���");
		printf("\n\t\t\t\t���س�����");
		fflush(stdin);
		getchar();
		manageMovie();
	} 
	if(ch=='m'||ch=='M'){
		printf("\n��������Ҫ�޸ĵĵ�ӰID:");
		int ID;
		scanf("%d",&ID);
		printf("\t\t1.����\n\t\t2.ʱ��\n\t\t3.��ӳʱ��\n\t\t4.Ʊ��");
		printf("\n");
		printf("������Ҫ�޸ĵ��������ͣ�\n");
		int choice;
		scanf("%d",&choice);
		movieModify_BLL(ID,choice);
		printf("\n\t\t\t\t�޸ĳɹ���"); 
		printf("\n\t\t\t\t���س�����");
		fflush(stdin);
		getchar();
		manageMovie();
	}
	if(ch=='r'||ch=='R'){
		adminMenu();
	}
	
}

void managePlay()
{
	system("color 07");
	system("cls");
	color(7);
	printf("\n\n"); 
	printf("\t\t\t********************************* �� �� �� �� *******************************\n");
	printf("\t\t\t%-3s %-3s     %-8s    %-5s  %-12s  %-5s   %-5s %-6s %6s\n","����","��ӰID","����","����","����","ʱ��","ʱ��","Ʊ��","Ӱ��ID");
	printf("\t\t\t-----------------------------------------------------------------------------\n\n");
	//ѭ����������
	sortTime();
	readPlayList();//                                                

	color(7);
	printf("\t\t\t-----------------------------------------------------------------------------\n");
	color(10);
	printf("\t\t\t[A]dd ���� |[D]elete ɾ�� |[M]odify �޸� | [U]pdate ���� |[R]eturn ����\n");
	color(7);
	printf("\t\t\t*****************************************************************************\n\n");

	color(14); 
	printf("\n\n\t\t\t��������Ҫ���еĲ�����");
	fflush(stdin);
	char ch=getchar();
 
	if(ch=='a'||ch=='A'){
		printf("\n"); 
	    char name[50];
	    int date,month,hour,minute,roomID;
		printf("������������ݳ��ĵ�Ӱ���ƣ�");
		fflush(stdin);
		scanf("%s",name);
		while(findMovieName(name)==0){
			printf("�õ�Ӱ���Ʋ����ڣ����������룺");
			fflush(stdin);
			scanf("%s",name);
		}
		printf("\n���������ӵ�Ӱ�����ڣ��·ݺ������ÿո������:");
		scanf("%d %d",&month,&date);
		//����Ҫ����ӳ����֮��
		while(findDate(name,month,date)){
			color(14);
			printf("\n��������������ӳ����֮�����������룺");
			scanf("%d %d",&month,&date);
		} 
		 
		printf("\n���������ӵ�Ӱ�Ŀ�ʼʱ�䣨Сʱ�ͷ����ÿո������:");
		scanf("%d %d",&hour,&minute);
		printf("\n���������ӵ�Ӱ����ӳӰ��ID:");
		scanf("%d",&roomID); 
		while(findStudioID(roomID)==0){
			printf("��Ӱ�������ڣ����������룺");
			fflush(stdin);
			scanf("%d",&roomID);
		}

		playAdd(name,month,date,hour,minute,roomID);
	
		printf("\n\t\t\t��ӳɹ���");
		printf("\n\t\t\t���س�����");
		getchar();getchar();
		managePlay();
	}
	if(ch=='d'||ch=='D'){
		printf("\n"); 
		printf("�������ɾ���ݳ��ƻ��ĳ��Σ�");
		int x;
		scanf("%d",&x);
		playDelete(x);
		cancelTicket2(x);
		printf("\n\t\t\tɾ���ɹ���");
		printf("\n\t\t\t���س�����");
		getchar();getchar();
		managePlay();
	} 
	if(ch=='m'||ch=='M'){
		printf("\n��������Ҫ�޸ĵĳ���:");
		int x;
		scanf("%d",&x);
		printf("\n1.��ӳ����\n2.��ӳʱ��\n3.Ӱ��");
		printf("\n");
		printf("������Ҫ�޸ĵ��������ͣ�\n");
		int choice;
		scanf("%d",&choice);
		playModify(x,choice);
		printf("\n\t\t\t�޸ĳɹ���"); 
		printf("\n\t\t\t���س�����");
		getchar();getchar();
		managePlay();
	}
	if(ch=='r'||ch=='R'){
		adminMenu();
	}
	if(ch=='u'||ch=='U'){
		printf("\n\t\t\t������������ڣ��·ݺ������ÿո������:");
		int month,date;
		fflush(stdin);
		scanf("%d %d",&month,&date);
		deleteOverduePlay(month,date);
		updateSeat(); 
		printf("\n\t\t\t���³ɹ���"); 
		printf("\n\t\t\t���س�����");
		getchar();getchar();
		managePlay();
	} 

}

void manageStudio()
{
	system("color 07");
	system("cls");
	color(7);
	printf("\n\n"); 
	printf("\t\t\t\t******************** Ӱ �� �� �� **********************\n\n");
	printf("\t\t\t\t\t%-10s %-10s %-10s %-10s\n","ID","����","����","��λ��"); 
	printf("\t\t\t\t-------------------------------------------------------\n\n");
	color(14);
	sortStudioByID();
	readStudioList();

	color(7);
	printf("\t\t\t\t-------------------------------------------------------\n");
	printf("\t\t\t\t[A]dd ���� |[D]elete ɾ�� |[M]odify �޸� |[R]eturn ����\n");
	printf("\t\t\t\t*******************************************************\n\n");
	color(14);
	printf("\t\t\t\t��������Ҫ���еĲ�����");
	char q;
	fflush(stdin);
	scanf("%c",&q);
	switch(q)
	{
		case 'a':
		case 'A':
			printf("\n");
			int rows,columns; 
			printf("���������ӵ�Ӱ����������������");
			scanf("%d %d",&rows,&columns);
			studioAdd_BLL(rows,columns);
			printf("\n\t\t\t\t��ӳɹ���");
			printf("\n\t\t\t\t���س����¡�");
			fflush(stdin);
			getchar(); 
			break;		
		case 'd':
		case 'D':
			printf("\n");
			printf("�������ɾ����Ӱ��ID:");
			int id;
			scanf("%d",&id);
			while(findStudioID(id)==0){
				color(14);
				printf("\n\t\t\t\t��Ӱ��ID�����ڣ����������룺");
				scanf("%d",&id); 
			}
			studioDelete_BLL(id);//
			deleteSeatByStudioID(id);
			printf("\n\t\t\t\tɾ���ɹ���");
			printf("\n\t\t\t\t���س����¡�");
			fflush(stdin);
			getchar();
			break;	
		case 'm':
		case 'M':
			printf("\n");
			printf("\t\t\t\t��������޸ĵ�Ӱ��ID:");
			int ID1;
			scanf("%d",&ID1);
			while(findStudioID(ID1)==0){
				color(14);
				printf("\n\t\t\t\t��Ӱ��ID�����ڣ����������룺");
				scanf("%d",&ID1); 
			}
			printf("\n\n\t\t\t\t1.����\n\t\t\t\t2.����");
			printf("\n");
			printf("\t\t\t\t������Ҫ�޸ĵ��������ͣ�");
			int choice;
			scanf("%d",&choice);
			studioModify_BLL(ID1,choice);//                          //
			printf("\n\t\t\t\t�޸ĳɹ���");
			printf("\n\t\t\t\t���س����¡�");
			fflush(stdin);
			getchar();
			break;	
		case 'r':
		case 'R':
			adminMenu();
			break;
		
	}
	
	manageStudio();
}

void manageSeat()
{
	system("color 07");
	system("cls");
	color(7);
	printf("\n\n"); 
	printf("\t\t\t\t******************* �� λ �� �� ***********************\n\n");
	color(14);
	printf("\t\t\t\t������Ҫ������λ�����Ӱ��ID:");
	int roomID;
	scanf("%d",&roomID);
	printf("\n");
	int rows=readStudioList_row(roomID); 
	int columns=readStudioList_column(roomID);
	fflush(stdout); 
	printSeat(roomID,rows,columns);
	
	printf("\n\n\t\t\t\t������Ҫ�޸�״̬����λλ�ã��У��У�:");
	int row,column;
	scanf("%d %d",&row,&column);
	while(row>rows||column>columns){
		printf("\n\t\t\t\t����������������Χ�����������룺");
		scanf("%d %d",&row,&column);
	}
	printf("\n\t\t\t\t���������λ�޸ĺ��״̬��0��ǰ��ѡ / 1�Ѿ���ѡ /-1�𻵴����� ��:");
	int zt;
	scanf("%d",&zt);
	while(zt!=0&&zt!=1&&zt!=-1){
		printf("\n\t\t\t\t�����״̬�����Ϲ涨�����������룺");
		scanf("%d",&zt);
	}
	printf("\n");
	seatModify_BLL(roomID,row,column,zt);//                                 //
	printSeat(roomID,rows,columns);
	printf("\n\t\t\t\t�޸ĳɹ���");
	printf("\n\n\t\t\t\t��1�����޸ģ���0������һ��:");
	int x;
	fflush(stdin);
	scanf("%d",&x);
	while(x!=1&&x!=0){
		scanf("%d",&x);
	}
	if(x==1){
		manageSeat();
	}else{
		adminMenu();
	}
	
}

void modifyPassword(char name[])
{
	system("color 07");
	system("cls");
	color(7);
	printf("\n\n"); 
	printf("\t\t\t\t********************* �� �� �� �� ***********************\n\n");
	color(11);
	printf("\n\t\t\t\t������ԭʼ���룺");
	char password[20],newPassword[20];
	passwordInput(password);
	while(usersCheck_BLL(name,password)!=1){
		printf("\n\n\t\t\t\tԭʼ������󣡰��س��������롣");
		fflush(stdin);
		passwordInput(password);
	}
	
		printf("\n\n\t\t\t\t�������޸ĺ�����룺");
		passwordInput(newPassword);
		int flag=1,i=0;
		for(i=0;newPassword[i]!='\0';i++){
				ch=newPassword[i];
				if(!(ch>=48&&ch<=57)&&!(ch>=65&&ch<=90)&&!(ch>=97&&ch<=122)){
					flag=0;
					break;
				}
		}
		if(flag==0){
			printf("\n\t\t\t\t\t    ����ֻ�������֡���ĸ��ɣ����س��������롣");
			fflush(stdin);
			getchar();
			modifyPassword(name); 
		}
		i++;
		if(i>12||i<6){
			printf("\n\t\t\t\t\t    ����ֻ����6~12λ֮�䣡���س��������룺"); 
			fflush(stdin);
			getchar();
			modifyPassword(name); 
		}		
	modifyUsersPassword(name,newPassword);
	printf("\n\n\t\t\t\t�޸ĳɹ������س����ء�");
	fflush(stdin);
	getchar();
	usersMenu1(name);
} 

//Ʊ�������۶� 	
void income()
{
	system("color 07");
	system("cls");
	color(7);
	printf("\n\n"); 
	printf("\t\t\t\t******************** Ʊ �� �� ѯ **********************\n\n");
	printf("\t\t\t\t    %-10s     %-10s   %-10s %-10s\n","ID","����","����Ʊ��","Ʊ��");
	printf("\t\t\t\t-------------------------------------------------------\n\n");
	color(14);
	sortIncome(); 
	readIncome();
	color(7);
	printf("\n\t\t\t\t-------------------------------------------------------\n");
	color(14);
	printf("\t\t\t\t\t\t    [R]eturn ����\n"); 
	color(7);
	printf("\t\t\t\t*******************************************************\n\n");
	printf("\t\t\t\t\t\t��R���أ�");
	char ch;
	scanf("%c",&ch);
	while(ch!='r'&&ch!='R'){
		scanf("%c",&ch);
	}
	adminMenu();
}

//�û���Ϣ 
void usersInformation()
{
	system("color 07");
	system("cls");
	color(7);
	printf("\n\n"); 
	printf("\t\t\t\t******************** �� �� �� Ϣ **********************\n\n");
	printf("\t\t\t\t          %-20s         %-20s","����","�绰\n"); 
	printf("\t\t\t-------------------------------------------------------\n\n");
	color(14);
	readUsersList();

	color(7);
	printf("\t\t\t\t-------------------------------------------------------\n");
	printf("\t\t\t\t                     [R]eturn ����\n"); 
	printf("\t\t\t\t*******************************************************\n\n");
	printf("\t\t\t\t��R����:");
	char ch;
	fflush(stdin);
	scanf("%c",&ch);
		while(ch!='r'&&ch!='R'){
			scanf("%c",&ch);
		}	
	adminMenu();
}






