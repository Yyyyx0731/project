#include "UI.h"


#define UpKey 72
#define DownKey 80

char c1,ch;

char ztToChar(int x)
{
	if(x==1){
		return '#';//被选 
	}else if(x==0){
		return '-';//可选 
	}else if(x==-1){
		return '!';//损坏 
	} 
}

void goto_xy(int x, int y)//定位光标位置到指定坐标
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
		printf("\t\t\t\t******************** 欢 迎 光 临 **********************\n\n");
		printf("\t\t\t\t********");
		printf("             登       录               ");
		printf("********\n\n");
		printf("\t\t\t\t********");
		printf("             注       册               "); 
		printf("********\n\n");
		printf("\t\t\t\t*******************************************************\n\n");
	
		int line=10;
		int choice=1;
		goto_xy(64, line);  
		 
	    while((c1 = getch())!='\r'){
			if (c1==-32){
				ch=getch();
			}
			//向上移动
			if (ch== UpKey&&choice>1){
				choice-=1;
				line -= 2;							
				goto_xy(64, line);
				menu1();
			}	
			//向下移动
			if (ch == DownKey&&choice<2){
				choice+=1;
				line += 2;
				goto_xy(64, line);
			}
			
		}
		if(choice==1){		 
		    //进入登录界面 
		    menuLogin1();
		}
		if(choice==2){
			//进入注册界面 
			menuRegister1();
		}
		
}

void menuLogin1()
{
		system("color F1");
		system("cls");
		printf("\n\n\n\n\n\n\n\n");
		printf("\t\t\t\t******************** 登 录 界 面 **********************\n\n");
		printf("\t\t\t\t********");
		printf("             用       户               ");
		printf("********\n\n");
		printf("\t\t\t\t********");
		printf("            管    理    员             "); 
		printf("********\n\n");
		printf("\t\t\t\t********");
		printf("             返       回               ");
		printf("********\n\n");
		printf("\t\t\t\t*******************************************************\n\n");
	
		int line=10;
		int choice=1;
		goto_xy(64, line);  
    	while((c1 = getch())!='\r'){
			if (c1==-32){
				ch=getch();
			}
			//向上移动
			if (ch== UpKey&&choice>1){
				choice-=1;
				line -= 2;							
				goto_xy(64, line);
			//	menu1();
			}	
			//向下移动
			if (ch == DownKey&&choice<3){
				choice+=1;
				line += 2;
			//	menuLogin2(movieHead);
				goto_xy(64, line);
			}
		}
		if(choice==1){		 
	    	//用户登录                                       
			 menuUsersLogin(); 
		}
		if(choice==2){
			//管理员登录                                          
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
		printf("\t\t\t\t******************** 注 册 界 面 **********************\n\n");
		printf("\t\t\t\t********");
		printf("             用       户              ");
		printf("********\n\n");
		printf("\t\t\t\t********");
		printf("            管    理    员             "); 
		printf("********\n\n");
		printf("\t\t\t\t********");
		printf("             返       回               "); 
		printf("********\n\n");
		printf("\t\t\t\t*******************************************************\n\n");
	
		int line=10;
		int choice=1;
		goto_xy(64, line);  
    	while((c1 = getch())!='\r'){
			if (c1==-32){
				ch=getch();
			}
			//向上移动
			if (ch== UpKey&&choice>1){
				choice-=1;
				line -= 2;							
				goto_xy(64, line);
			//	menu1();
			}	
			//向下移动
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

//输入密码时隐藏为*号 
//pwd为返回值
void passwordInput(char pwd[]){
	char input_char;
	int index = 0;
	fflush(stdin);//清除输入缓存
	//密码显示*号且支持退格  
	while((input_char = getch()) != '\r'){//换行符 
		if(input_char == '\b'){//退格键 
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
	pwd[index] = '\0';//结束符 
}

void menuUsersLogin()//用户登录界面
{
	char name[20];
	char password[20];


	system("cls");
	system("color F5");
	printf("\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t******************** 登 录 界 面 **********************\n\n");
	printf("\t\t\t\t-------------------按回车键确认输入--------------------\n\n");
	printf("\t\t\t\t********");
	printf("   用 户 名 ：                         ");
	printf("********\n\n"); 
	printf("\t\t\t\t********");
	printf("      密 码 ：                         "); 
	printf("********\n\n");
	printf("\t\t\t\t*******************************************************\n\n");
	
	int line=12;
	int choice=1;
	goto_xy(54, line);  
	gets(name);

	
	line += 2;
	goto_xy(54, line);
	passwordInput(password);

	
	//判断用户的用户名和密码是否正确 
	if(usersCheck_BLL(name,password)==1){                 
		//正确后进入用户菜单
		//读取用户
		printf("\n\t\t\t\t\t\t登陆成功！按回车键继续。");
		getchar();
		usersMenu1(name);
	}else if(usersCheck_BLL(name,password)==-1){
		printf("\n\t\t\t\t\t   该用户不存在！按回车进入注册页面。");
		getchar();
		menuUsersRegister();
	}else if(usersCheck_BLL(name,password)==0){
		printf("\n\t\t\t\t\t    用户名或密码错误！按回车重新输入。");
		getchar();
		menuUsersLogin();
	}
	 
} 

void menuAdminLogin()//管理员登录界面 
{
	char name[20];
	char password[20];
	system("color F5");
	system("cls");
	printf("\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t******************** 登 录 界 面 **********************\n\n");
	printf("\t\t\t\t-------------------按回车键确认输入--------------------\n\n");
	printf("\t\t\t\t********");
	printf("   用 户 名 ：                         ");
	printf("********\n\n"); 
	printf("\t\t\t\t********");
	printf("      密 码 ：                         "); 
	printf("********\n\n");
	printf("\t\t\t\t*******************************************************\n\n");
	
	int line=12;
	int choice=1;
	goto_xy(54, line);  
	gets(name);
	
	line += 2;
	goto_xy(54, line);
	passwordInput(password);

	//判断管理员的用户名和密码是否正确 
	if(adminCheck_BLL(name,password)==1){//通过遍历链表结点，该用户名时密码是否正确 // 
		//正确后进入管理员菜单
		printf("\n\t\t\t\t\t\t登陆成功！按回车键继续。");
		getchar();
		adminMenu();
	}else if(adminCheck_BLL(name,password)==0){
		printf("\n\t\t\t\t用户名或密码错误！请重新输入。按回车键继续");
		getchar();
		menuAdminLogin();
	}else if(adminCheck_BLL(name,password)==-1){
		printf("\n\t\t\t\t\t   该用户不存在！按回车进入注册页面。");
		getchar();
		menuAdminRegister();
	}
}

void menuUsersRegister()//用户注册界面 
{
	char name[20];
	char tel[20]; 
	char password[20];
	
		system("color F5");
		system("cls");
		printf("\n\n\n\n\n\n\n\n");
		printf("\t\t\t\t******************** 注 册 界 面 **********************\n\n");
		printf("\t\t\t\t********");
		printf("   用 户 名 ：                         ");
		printf("********\n\n"); 
		printf("\t\t\t\t********");
		printf("      电 话 ：                         "); 
		printf("********\n\n");
		printf("\t\t\t\t********");
		printf("      密 码 ：                         "); 
		printf("********\n\n");
		printf("\t\t\t\t********");
		printf("确 认 密 码 ：                         "); 
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
			printf("\t\t\t\t         用户名不能为空！按回车重新输入。");
			fflush(stdin);
			getchar();
			menuUsersRegister(); 
		} 
		if(flag==0){
			printf("\t\t\t\t\t用户名只能由数字、字母、下划线组成！按回车重新输入。");
			fflush(stdin);
			getchar();
			menuUsersRegister(); 
		}
		i++;
		if(i>12){
			printf("\t\t\t\t\t\t用户名不得超过12位！按回车重新输入。"); 
			fflush(stdin);
			getchar();
			menuUsersRegister();
		}	
		if(findUsersName(name)){
			color(14);
			printf("\n\t\t\t\t该用户名已存在！按回车重新输入。");
			fflush(stdin);
			getchar();
			menuUsersRegister();
		}	
		
		line += 2;
		goto_xy(54, line);
		gets(tel);
		if(strlen(tel)==0){
			printf("\t\t\t\t             电话不能为空！按回车重新输入。");
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
			printf("\n\t\t\t\t\t    密码只能由数字、字母组成！按回车重新输入。");
			fflush(stdin);
			getchar();
			menuUsersRegister(); 
		}
		i++;
		if(i>12||i<6){
			printf("\n\t\t\t\t\t    密码只能在6~12位之间！按回车重新输入。"); 
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
			printf("\n\t\t\t\t两次输入密码不一致！按回车重新输入。");
			fflush(stdin);
			getchar();
			menuUsersRegister();
		}
	
		
		//存入用户
		addUsersNode_BLL(name,tel,password);
		printf("\n\t\t\t\t\t\t注册成功！按回车键继续。");
		getchar();
		usersMenu1(name);
	
}

void menuAdminRegister()//管理员注册界面 
{
	char name[20];
	char tel[20];
	char password[20];
	system("color F5");
	system("cls");
	printf("\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t******************** 注 册 界 面 **********************\n\n");
	printf("\t\t\t\t********");
	printf("   用 户 名 ：                         ");
	printf("********\n\n"); 
	printf("\t\t\t\t********");
	printf("      电 话 ：                         "); 
	printf("********\n\n");
	printf("\t\t\t\t********");
	printf("      密 码 ：                         "); 
	printf("********\n\n");
	printf("\t\t\t\t********");
	printf("确 认 密 码 ：                         "); 
	printf("********\n\n");
	printf("\t\t\t\t********");
	printf("   验 证 码 ：                         "); 
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
			printf("\t\t\t\t         用户名不能为空！按回车重新输入。");
			fflush(stdin);
			getchar();
			menuAdminRegister(); 
		} 
		if(flag==0){
			printf("\t\t\t\t\t用户名只能由数字、字母、下划线组成！按回车重新输入。");
			fflush(stdin);
			getchar();
			menuAdminRegister(); 
		}
		i++;
		if(i>12){
			printf("\t\t\t\t\t\t用户名不得超过12位！按回车重新输入。"); 
			fflush(stdin);
			getchar();
			menuAdminRegister();
		}	
		if(findAdminName(name)){
			color(14);
			printf("\n\t\t\t\t该用户名已存在！按回车重新输入。");
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
			printf("\n\t\t\t\t\t    密码只能由数字、字母组成！按回车重新输入。");
			fflush(stdin);
			getchar();
			menuAdminRegister(); 
		}
		i++;
		if(i>12||i<6){
			printf("\n\t\t\t\t\t    密码只能在6~12位之间！按回车重新输入。"); 
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
			printf("\n\t\t\t\t两次输入密码不一致！按回车重新输入。");
			fflush(stdin);
			getchar();
			menuAdminRegister();
		}
		
		char pass[20];
		line += 2;
		goto_xy(54, line);
		//printf("\n\t\t\t\t请输入验证码：");
		scanf("%s",pass);
		while(passCheck(pass)==0){
			printf("\n\t\t\t\t验证码错误！请重新输入：");
			scanf("%s",pass);
		}
	
	//存入管理员链表 
	addAdminNode_BLL(name,tel,password);//                                              //
	printf("\n\t\t\t\t\t\t注册成功！按回车键继续。");
	fflush(stdin);
	getchar();
	adminMenu();
}


//用户功能菜单 （查演出，购票，退票） 
void usersMenu1(char name[])
{
	system("color E1");
	system("cls");
	printf("\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t********************   菜   单   **********************\n\n");
	printf("\t\t\t\t");
	printf("                     演 出 列 表                       ");
	printf("\n\n"); 
	printf("\t\t\t\t");
	printf("                     查 询 电 影                       ");
	printf("\n\n"); 
	printf("\t\t\t\t");
	printf("                     查 看 订 单                         "); 
	printf("\n\n");
	printf("\t\t\t\t");
	printf("                     修 改 密 码                         "); 
	printf("\n\n");
	printf("\t\t\t\t");
	printf("                     退 出 登 录                        "); 
	printf("\n\n"); 
	printf("\t\t\t\t*******************************************************\n\n");
	
	int line=10;
	int choice=1;
	goto_xy(64, line);  
	
    while((c1 = getch())!='\r'){
		if (c1==-32){
				ch=getch();
			}
		//向上移动
			if (ch== UpKey&&choice>1){
				choice-=1;
				line -= 2;							
				goto_xy(64, line);
			//	menu1();
			}	
			//向下移动
			if (ch == DownKey&&choice<5){
				choice+=1;
				line += 2;
				goto_xy(64, line);
			}
	}
	if(choice==1){		 
	    //用户演出列表界面
		usersMovies(name);
	}
	if(choice==2){
		//查询演出 
		usersSearch(name);
	}
	if(choice==3){
		//查看订单界面
		viewOrders(name);
	}
	if(choice==4){
		modifyPassword(name); //修改密码 
	} 
	if(choice==5){
		exit(0);
	} 
	
}


//管理员功能菜单
void adminMenu()
{
	system("color E1");
	system("cls");
	printf("\n\n\n\n\n\n");
	printf("\t\t\t\t********************   菜   单   **********************\n\n");
	printf("\t\t\t\t");
	printf("                     查 询 演 出                        ");
	printf("\n\n"); 
	printf("\t\t\t\t");
	printf("                     电 影 管 理                       "); 
	printf("\n\n");
	printf("\t\t\t\t");
	printf("                     演 出 管 理                          "); 
	printf("\n\n"); 
	printf("\t\t\t\t");
	printf("                    管 理 演 出 厅                     "); 
	printf("\n\n");
	printf("\t\t\t\t");
	printf("                     管 理 座 位                         "); 
	printf("\n\n");
	printf("\t\t\t\t");
	printf("                   票 房 及 销 售 额                        "); 
	printf("\n\n");
	printf("\t\t\t\t");
	printf("                     用 户 资 料                         "); 
	printf("\n\n"); 
	printf("\t\t\t\t");
	printf("                     退 出 登 录                        "); 
	printf("\n\n"); 
	printf("\t\t\t\t*******************************************************\n\n");
	
	int line=8;
	int choice=1;
	goto_xy(66, line);  
	
    while((c1 = getch())!='\r'){
		if (c1==-32){
				ch=getch();
			}
		//向上移动
		if (ch== UpKey&&choice>1){
			choice-=1;
			line -= 2;							
			goto_xy(66, line);		
		}
		//向下移动
		if (ch == DownKey&&choice<8){
			choice+=1;
			line += 2;
			goto_xy(66, line);
		}		
	}
	
	if(choice==1){		 
	    //管理员演出列表界面
		adminMovies();
	}
	if(choice==2){
		//管理电影界面 
		manageMovie();
	}
	if(choice==3){
		managePlay();
	} 
	if(choice==4){
		//管理演出厅界面 
		manageStudio();
	}
	if(choice==5){
		//管理座位 
		manageSeat();
	}
	if(choice==6){
		//票房及销售额界面 
		income(); 
	}
	if(choice==7){
		//用户资料界面 
		usersInformation();
	}
	if(choice==8){
		exit(0);
	}
	
}



//用户演出列表（购票） 
void usersMovies(char name[])
{	
	system("color 07");
	system("cls");
	color(7);
	printf("\n\n"); 
	printf("\t\t\t********************************* 演 出 列 表 ******************************\n");
	printf("\t\t\t%-3s %-3s     %-8s    %-5s  %-12s  %-5s   %-5s %-6s %6s\n","场次","电影ID","名称","类型","日期","时长","时间","票价","影厅ID");
	printf("\t\t\t----------------------------------------------------------------------------\n\n");
	//循环遍历链表
	sortTime();
	readPlayList();

	color(7);
	printf("\t\t\t----------------------------------------------------------------------------\n");
	color(10);
	printf("\t\t\t\t\t        [B]uy 购票 | [R]eturn 返回\n");
	color(7);
	printf("\t\t\t****************************************************************************\n\n");
	char ch;
	color(14); 
	printf("\n\n\t\t\t请输入你要进行的操作：");
	fflush(stdin);
	scanf("%c",&ch);
	if(ch=='B'||ch=='b'){
		printf("\n\t\t\t请输入您要购买的电影场次:");
		int x;
		fflush(stdin);
		scanf("%d",&x); 
		//进入选座界面
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
		printf("\t\t\t********************************* 演 出 列 表 ******************************\n");
	printf("\t\t\t\t%-3s %-3s     %-8s    %-5s  %-12s  %-5s   %-5s %-6s %6s\n","场次","电影ID","名称","类型","日期","时长","时间","票价","影厅ID");
	printf("\t\t\t----------------------------------------------------------------------------\n\n");
	//循环遍历链表
	color(13);
	fflush(stdout);
	sortTime();
	readPlayList();

	color(7);
	printf("\t\t\t---------------------------------------------------------------------------\n");
	color(10);
	printf("\t\t\t\t\t[S]earch 查询 | [R]eturn 返回\n");
	color(7);
	printf("\t\t\t***************************************************************************\n\n");

	color(14); 
	printf("\n\n\t\t\t请输入你要进行的操作：");
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

//选座界面
void selectSeat(int x,char name[]) 
{
	system("color 07");
	system("cls");

	
	//从文件读链表
	int roomID=readPlayList_Search(x); 

	
    printf("\n\n\n\n");
    color(7);
    printf("\t\t\t\t========================================================\n");
    printf("\t\t\t\t*********************  Room  %2d  **********************\n",roomID);
    printf("\t\t\t\t--------------------------------------------------------\n");
	int rows=readStudioList_row(roomID); 
	int columns=readStudioList_column(roomID);
	//打印座位 
	fflush(stdout);
	printSeat(roomID,rows,columns);

	printf("--------------------------------------------------------\n");
	color(14);
	printf("\t\t\t\t\t[S]elete 选择      |         [R]eturn 返回\n");
	color(7);
	printf("\t\t\t\t========================================================\n\n");
	color(14);
	printf("\t\t\t\t请输入你要进行的操作：");
	fflush(stdin);
	char c=getchar(); 
	while(c!='s'&&c!='S'&&c!='r'&&c!='R'){
		color(14);
		printf("\n\t\t\t\t输入不符合规定！请重新输入："); 
		fflush(stdin);
		c=getchar();
	} 
	if(c=='s'||c=='S'){
		printf("\n\t\t\t\t请输入要选择的座位行列号：");
		int row,column;
		scanf("%d %d",&row,&column);
		if(findSeatByRC(row,column)==1){
			color(14);
			printf("\n\t\t\t\t该座位已被选，不可重复选择！按回车继续。"); 
			getchar();getchar();
			selectSeat(x,name);
		}else if(findSeatByRC(row,column)==-1){
			color(14);
			printf("\n\t\t\t\t该座位损坏，不可选择！按回车继续。");
			getchar();getchar();
			selectSeat(x,name);
		}
		
		if(seatModify_BLL(roomID,row,column,1)){//     seleteSeat_BLL()里选择成功后要更新座位状态    //
			color(14);
			int ID=PlayList_SearchID(x);
			ordersAdd_BLL(name,x,ID,row,column);//             加入订单链表                  //
			//票房及销售额+1；
			updatePrice_BLL(ID);//         更新某电影的票房和销售额         //
		//	sortIncome(); 
			printf("\n\t\t\t\t选座成功！按回车继续\n");
			getchar();getchar();
			selectSeat(x,name);
		}else{
			color(14);
			printf("\n\t\t\t\t选座失败！\n");
			selectSeat(x,name);
		}
	}else if(c=='r'||c=='R'){
		usersMovies(name);
	}
	
} 

//查询演出选项（按id，片名，类型，日期） 
void usersSearch(char name[])
{
	system("color 07");
	system("cls");
	color(7);
	printf("\n\n\n\n\n\n");
	printf("\t\t\t\t******************** 查 询 演 出 **********************\n\n");
	printf("\t\t\t\t-------------------------------------------------------\n\n");
	color(14);
	printf("\t\t\t\t");
	printf("                     片 名 查 询                       ");
	printf("\n\n"); 
	printf("\t\t\t\t");
	printf("                     ID  查   询                       "); 
	printf("\n\n");
	printf("\t\t\t\t");
	printf("                     类 型 查 询                     "); 
	printf("\n\n");
	printf("\t\t\t\t");
	printf("                     日 期 查 询                        "); 
	printf("\n\n");
	printf("\t\t\t\t");
	printf("                     返       回                     "); 
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
		//向上移动
		if (ch== UpKey&&choice>1){
			choice-=1;
			line -= 2;							
			goto_xy(64, line);		
		}
		//向下移动
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
	printf("\t\t\t\t******************** 查 询 演 出 **********************\n\n");
	printf("\t\t\t\t-------------------------------------------------------\n\n");
	color(14);
	printf("\t\t\t\t");
	printf("                     片 名 查 询                       ");
	printf("\n\n"); 
	printf("\t\t\t\t");
	printf("                     ID  查   询                       "); 
	printf("\n\n");
	printf("\t\t\t\t");
	printf("                     类 型 查 询                     "); 
	printf("\n\n");
	printf("\t\t\t\t");
	printf("                     日 期 查 询                        "); 
	printf("\n\n");
	printf("\t\t\t\t");
	printf("                     返       回                     "); 
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
		//向上移动
		if (ch== UpKey&&choice>1){
			choice-=1;
			line -= 2;							
			goto_xy(64, line);		
		}
		//向下移动
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
	 
	 
//进行查询界面 
void usersSearching(int choice,char name[])
{
	system("color 07");
	system("cls");
	color(7);
	printf("\n\n\n\n\n\n");
	printf("\t\t\t********************************* 演 出 列 表 ******************************\n");
	printf("\t\t\t%-3s %-3s     %-8s    %-5s  %-12s  %-5s   %-5s %-6s %6s\n","场次","电影ID","名称","类型","日期","时长","时间","票价","影厅ID");
	printf("\t\t\t----------------------------------------------------------------------------\n\n");

	if(choice==1){
		printf("\t\t\t\t请输入要查询的电影名称：");
		char name[20];
		scanf("%s",name);
		printf("\n");
		playSearch_Name(name);
	}
	if(choice==2){
		printf("\t\t\t\t请输入要查询的电影ID：");
		int ID;
		scanf("%d",&ID);
		printf("\n");
		playSearch_ID(ID);

	}
	if(choice==3){
		printf("\t\t\t\t请输入要查询的电影类型：");
		char type[20];
		scanf("%s",type);
		printf("\n");
		playSearch_Type(type);
		
	}
	if(choice==4){
		int date,month;
		printf("\t\t\t\t请输入要查询的月份和日期（用空格隔开）：");
		scanf("%d",&month);
		scanf("%d",&date);
		printf("\n");
		playSearch_Date(month,date);

	}                                             //

	color(7);
	printf("\t\t\t----------------------------------------------------------------------------\n");
	color(10);
	printf("\t\t\t\t\t      [S]earch 继续查询 |[R]eturn 返回\n");
	color(7);
	printf("\t\t\t****************************************************************************\n\n");
	color(14);
	fflush(stdin);
	printf("\t\t\t\t请输入您要进行的操作：");
	fflush(stdin);
	char x=getchar();
	while(x!='s'&&x!='S'&&x!='r'&&x!='R'&&x!='b'&&x!='B'){
		color(14);
		printf("\t\t\t您输入的操作不符合规定，请重新输入：");
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
	printf("\t\t\t********************************* 演 出 列 表 ******************************\n");
	printf("\t\t\t%-3s %-3s     %-8s    %-5s  %-12s  %-5s   %-5s %-6s %6s\n","场次","电影ID","名称","类型","日期","时长","时间","票价","影厅ID");
	printf("\t\t\t----------------------------------------------------------------------------\n\n");

	if(choice==1){
		printf("\t\t\t请输入要查询的电影名称：");
		char name[20];
		scanf("%s",name);
		printf("\n");
		playSearch_Name(name);
	}
	if(choice==2){
		printf("\t\t\t请输入要查询的电影ID：");
		int ID;
		scanf("%d",&ID);
		printf("\n");
		playSearch_ID(ID);
	}
	if(choice==3){
		printf("\t\t\t请输入要查询的电影类型：");
		char type[20];
		scanf("%s",type);
		printf("\n");
		playSearch_Type(type);
		
	}
	if(choice==4){
		int date,month;
		printf("\t\t\t请输入要查询的月份和日期（用空格隔开）：");
		scanf("%d",&month);
		scanf("%d",&date);
		printf("\n");
		playSearch_Date(month,date);

	}
	color(7);
	printf("\t\t\t----------------------------------------------------------------------------\n");
	color(10);
	printf("\t\t\t\t\t[S]earch 继续查询 | [R]eturn 返回\n");
	color(7);
	printf("\t\t\t****************************************************************************\n\n");
	color(14);
	printf("\t\t\t请输入您要进行的操作：");
	char x;
	fflush(stdin);
	scanf("%c",&x);
	while(x!='s'&&x!='S'&&x!='r'&&x!='R'){
		color(14);
		printf("\n\t\t\t您输入的操作不符合规定，请重新输入：");
		scanf("%c",&x);
	}
	if(x=='R'||x=='r'){
		adminMenu();
	}else if(x=='S'||x=='s'){
		adminSearch();
	}
	
}


//查看订单（退票） 
void viewOrders(char name[])
{
	system("color 07");
	system("cls");
	color(14);
	system("cls");
	color(7);
	printf("\n\n\n\n\n\n");
	printf("\t\t\t******************************** 订 单 列 表 *****************************\n\n");
	printf("\t\t\t%-3s %-2s     %-6s    %-4s   %-6s  %-6s %-6s %-6s %6s\n\n","订单序号","电影ID","名称","类型","日期","时长","演出时间","影厅ID","座位");
	printf("\t\t\t--------------------------------------------------------------------------\n\n");
	sortIncome();
	readOrdersList();

	color(7);
	printf("\t\t\t--------------------------------------------------------------------------\n");
	color(10);
	printf("\t\t\t\t            [C]ancel 退票    |    [R]eturn 返回\n");
	color(7);
	printf("\t\t\t**************************************************************************\n\n");
	color(14);
	printf("\t\t\t请输入你要进行的操作：");
	char x;
	fflush(stdin); 
	scanf("%c",&x);
	while(x!='c'&&x!='C'&&x!='r'&&x!='R'){
		color(14);
		printf("\n\t\t\t您输入的操作不符合规定，请重新输入：");
		scanf("%c",&x);
	}
	if(x=='c'||x=='C'){
		printf("\n\t\t\t请输入你要退票的订单序号：");
		int n;
		fflush(stdin);
		scanf("%d",&n);
		while(findOrders(n)){
			color(14);
			printf("\n\t\t\t\t该订单号不存在！请重新输入：");
			fflush(stdin);
			scanf("%d",&n);
		}
		deleteOrders_BLL(n);
		numReduce_And_SeatUpdate(n);
		color(14);
		printf("\n\t\t\t\t退票成功！按回车继续。");
		fflush(stdin);
		getchar();
		viewOrders(name);
	}else if(x=='r'||x=='R'){
		usersMenu1(name);
	}
	
}

 
//管理员管理 
void manageMovie()
{
	system("color 07");
	system("cls");
	color(7);
	printf("\n\n"); 
	printf("\t\t\t\t************************** 电 影 列 表 ***********************\n");
	printf("\t\t\t\t%-3s        %-8s      %-8s  %-5s %-5s   %-6s\n","ID","名称","类型","时长","上映日期","票价");
	printf("\t\t\t\t--------------------------------------------------------------\n\n");
	//循环遍历链表
	sortMovieByID();
	readMovieList();

	color(7);
	printf("\t\t\t\t--------------------------------------------------------------\n\n");
	color(10);
	printf("\t\t\t\t[A]dd 增添 |[D]elete 删除 |[M]odify 修改 |[R]eturn 返回\n");
	color(7);
	printf("\t\t\t\t**************************************************************\n\n");

	color(14); 
	printf("\n\n\t\t\t\t请输入你要进行的操作：");
	fflush(stdin);
	char ch=getchar();
 
	if(ch=='a'||ch=='A'){
		printf("\n"); 
	   
	    int ID,time,date,month,price,roomID;
	    char name[20],type[20];
//		printf("请输入待增加电影的ID：");
//		scanf("%d",&ID);
//		while(findMovieID(ID)){
//			printf("\n该ID已存在！请重新输入："); 
//			fflush(stdin);
//			scanf("%d",&ID);
//		}
		printf("\n请输入待增加电影的名称：");
		scanf("%s",name); 
		while(findMovieName(name)){
			printf("\n\t\t\t\t该电影已存在！请重新输入：");
			fflush(stdin);
			scanf("%s",name);
		}
		printf("\n请输入待增加电影的类型：");
		scanf("%s",type);
		printf("\n请输入待添加电影的时长（分钟）:");
		scanf("%d",&time);
		printf("\n请输入待添加电影的上映日期（月份和日期用空格隔开）:");
		scanf("%d %d",&month,&date);
		while(month<1||month>12||date<1||date>31){
			printf("\n\t\t\t\t日期不正确！请重新输入：");
			fflush(stdin);
			scanf("%d %d",&month,&date);
		} 
		printf("\n请输入待添加电影的票价:");
		scanf("%d",&price);
	
		//movieAdd(ID,name,type,time,month,date,price);
		movieAdd(name,type,time,month,date,price);
		printf("\n\t\t\t\t添加成功！");
		printf("\n\t\t\t\t按回车继续");
		fflush(stdin);
		getchar();
		manageMovie();
	}
	if(ch=='d'||ch=='D'){
		printf("\n"); 
		printf("请输入待删除的电影ID：");
		int ID;
		scanf("%d",&ID);
		while(findMovieID(ID)==0){
			printf("\n该ID不存在！请重新输入："); 
			fflush(stdin);
			scanf("%d",&ID);
		}
		movieDelete_BLL(ID);
		deletePlay(ID);
		cancelTicket(ID);
		printf("\n\t\t\t\t删除成功！");
		printf("\n\t\t\t\t按回车继续");
		fflush(stdin);
		getchar();
		manageMovie();
	} 
	if(ch=='m'||ch=='M'){
		printf("\n请输入您要修改的电影ID:");
		int ID;
		scanf("%d",&ID);
		printf("\t\t1.类型\n\t\t2.时长\n\t\t3.上映时间\n\t\t4.票价");
		printf("\n");
		printf("请输入要修改的数据类型：\n");
		int choice;
		scanf("%d",&choice);
		movieModify_BLL(ID,choice);
		printf("\n\t\t\t\t修改成功！"); 
		printf("\n\t\t\t\t按回车继续");
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
	printf("\t\t\t********************************* 演 出 列 表 *******************************\n");
	printf("\t\t\t%-3s %-3s     %-8s    %-5s  %-12s  %-5s   %-5s %-6s %6s\n","场次","电影ID","名称","类型","日期","时长","时间","票价","影厅ID");
	printf("\t\t\t-----------------------------------------------------------------------------\n\n");
	//循环遍历链表
	sortTime();
	readPlayList();//                                                

	color(7);
	printf("\t\t\t-----------------------------------------------------------------------------\n");
	color(10);
	printf("\t\t\t[A]dd 增添 |[D]elete 删除 |[M]odify 修改 | [U]pdate 更新 |[R]eturn 返回\n");
	color(7);
	printf("\t\t\t*****************************************************************************\n\n");

	color(14); 
	printf("\n\n\t\t\t请输入你要进行的操作：");
	fflush(stdin);
	char ch=getchar();
 
	if(ch=='a'||ch=='A'){
		printf("\n"); 
	    char name[50];
	    int date,month,hour,minute,roomID;
		printf("请输入待增加演出的电影名称：");
		fflush(stdin);
		scanf("%s",name);
		while(findMovieName(name)==0){
			printf("该电影名称不存在！请重新输入：");
			fflush(stdin);
			scanf("%s",name);
		}
		printf("\n请输入待添加电影的日期（月份和日期用空格隔开）:");
		scanf("%d %d",&month,&date);
		//日期要在上映日期之后
		while(findDate(name,month,date)){
			color(14);
			printf("\n播放日期需在上映日期之后！请重新输入：");
			scanf("%d %d",&month,&date);
		} 
		 
		printf("\n请输入待添加电影的开始时间（小时和分钟用空格隔开）:");
		scanf("%d %d",&hour,&minute);
		printf("\n请输入待添加电影的上映影厅ID:");
		scanf("%d",&roomID); 
		while(findStudioID(roomID)==0){
			printf("该影厅不存在！请重新输入：");
			fflush(stdin);
			scanf("%d",&roomID);
		}

		playAdd(name,month,date,hour,minute,roomID);
	
		printf("\n\t\t\t添加成功！");
		printf("\n\t\t\t按回车更新");
		getchar();getchar();
		managePlay();
	}
	if(ch=='d'||ch=='D'){
		printf("\n"); 
		printf("请输入待删除演出计划的场次：");
		int x;
		scanf("%d",&x);
		playDelete(x);
		cancelTicket2(x);
		printf("\n\t\t\t删除成功！");
		printf("\n\t\t\t按回车更新");
		getchar();getchar();
		managePlay();
	} 
	if(ch=='m'||ch=='M'){
		printf("\n请输入您要修改的场次:");
		int x;
		scanf("%d",&x);
		printf("\n1.放映日期\n2.放映时间\n3.影厅");
		printf("\n");
		printf("请输入要修改的数据类型：\n");
		int choice;
		scanf("%d",&choice);
		playModify(x,choice);
		printf("\n\t\t\t修改成功！"); 
		printf("\n\t\t\t按回车更新");
		getchar();getchar();
		managePlay();
	}
	if(ch=='r'||ch=='R'){
		adminMenu();
	}
	if(ch=='u'||ch=='U'){
		printf("\n\t\t\t请输入今日日期（月份和日期用空格隔开）:");
		int month,date;
		fflush(stdin);
		scanf("%d %d",&month,&date);
		deleteOverduePlay(month,date);
		updateSeat(); 
		printf("\n\t\t\t更新成功！"); 
		printf("\n\t\t\t按回车更新");
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
	printf("\t\t\t\t******************** 影 厅 列 表 **********************\n\n");
	printf("\t\t\t\t\t%-10s %-10s %-10s %-10s\n","ID","行数","列数","座位数"); 
	printf("\t\t\t\t-------------------------------------------------------\n\n");
	color(14);
	sortStudioByID();
	readStudioList();

	color(7);
	printf("\t\t\t\t-------------------------------------------------------\n");
	printf("\t\t\t\t[A]dd 增添 |[D]elete 删除 |[M]odify 修改 |[R]eturn 返回\n");
	printf("\t\t\t\t*******************************************************\n\n");
	color(14);
	printf("\t\t\t\t请输入你要进行的操作：");
	char q;
	fflush(stdin);
	scanf("%c",&q);
	switch(q)
	{
		case 'a':
		case 'A':
			printf("\n");
			int rows,columns; 
			printf("请输入待添加的影厅的行数、列数：");
			scanf("%d %d",&rows,&columns);
			studioAdd_BLL(rows,columns);
			printf("\n\t\t\t\t添加成功！");
			printf("\n\t\t\t\t按回车更新。");
			fflush(stdin);
			getchar(); 
			break;		
		case 'd':
		case 'D':
			printf("\n");
			printf("请输入待删除的影厅ID:");
			int id;
			scanf("%d",&id);
			while(findStudioID(id)==0){
				color(14);
				printf("\n\t\t\t\t该影厅ID不存在！请重新输入：");
				scanf("%d",&id); 
			}
			studioDelete_BLL(id);//
			deleteSeatByStudioID(id);
			printf("\n\t\t\t\t删除成功！");
			printf("\n\t\t\t\t按回车更新。");
			fflush(stdin);
			getchar();
			break;	
		case 'm':
		case 'M':
			printf("\n");
			printf("\t\t\t\t请输入待修改的影厅ID:");
			int ID1;
			scanf("%d",&ID1);
			while(findStudioID(ID1)==0){
				color(14);
				printf("\n\t\t\t\t该影厅ID不存在！请重新输入：");
				scanf("%d",&ID1); 
			}
			printf("\n\n\t\t\t\t1.行数\n\t\t\t\t2.列数");
			printf("\n");
			printf("\t\t\t\t请输入要修改的数据类型：");
			int choice;
			scanf("%d",&choice);
			studioModify_BLL(ID1,choice);//                          //
			printf("\n\t\t\t\t修改成功！");
			printf("\n\t\t\t\t按回车更新。");
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
	printf("\t\t\t\t******************* 座 位 管 理 ***********************\n\n");
	color(14);
	printf("\t\t\t\t请输入要进行座位管理的影厅ID:");
	int roomID;
	scanf("%d",&roomID);
	printf("\n");
	int rows=readStudioList_row(roomID); 
	int columns=readStudioList_column(roomID);
	fflush(stdout); 
	printSeat(roomID,rows,columns);
	
	printf("\n\n\t\t\t\t请输入要修改状态的座位位置（行，列）:");
	int row,column;
	scanf("%d %d",&row,&column);
	while(row>rows||column>columns){
		printf("\n\t\t\t\t行数或列数超出范围！请重新输入：");
		scanf("%d %d",&row,&column);
	}
	printf("\n\t\t\t\t请输入该座位修改后的状态（0当前可选 / 1已经被选 /-1损坏待修理 ）:");
	int zt;
	scanf("%d",&zt);
	while(zt!=0&&zt!=1&&zt!=-1){
		printf("\n\t\t\t\t输入的状态不符合规定！请重新输入：");
		scanf("%d",&zt);
	}
	printf("\n");
	seatModify_BLL(roomID,row,column,zt);//                                 //
	printSeat(roomID,rows,columns);
	printf("\n\t\t\t\t修改成功！");
	printf("\n\n\t\t\t\t按1继续修改，按0返回上一级:");
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
	printf("\t\t\t\t********************* 修 改 密 码 ***********************\n\n");
	color(11);
	printf("\n\t\t\t\t请输入原始密码：");
	char password[20],newPassword[20];
	passwordInput(password);
	while(usersCheck_BLL(name,password)!=1){
		printf("\n\n\t\t\t\t原始密码错误！按回车重新输入。");
		fflush(stdin);
		passwordInput(password);
	}
	
		printf("\n\n\t\t\t\t请输入修改后的密码：");
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
			printf("\n\t\t\t\t\t    密码只能由数字、字母组成！按回车重新输入。");
			fflush(stdin);
			getchar();
			modifyPassword(name); 
		}
		i++;
		if(i>12||i<6){
			printf("\n\t\t\t\t\t    密码只能在6~12位之间！按回车重新输入："); 
			fflush(stdin);
			getchar();
			modifyPassword(name); 
		}		
	modifyUsersPassword(name,newPassword);
	printf("\n\n\t\t\t\t修改成功！按回车返回。");
	fflush(stdin);
	getchar();
	usersMenu1(name);
} 

//票房及销售额 	
void income()
{
	system("color 07");
	system("cls");
	color(7);
	printf("\n\n"); 
	printf("\t\t\t\t******************** 票 房 查 询 **********************\n\n");
	printf("\t\t\t\t    %-10s     %-10s   %-10s %-10s\n","ID","名称","卖出票数","票房");
	printf("\t\t\t\t-------------------------------------------------------\n\n");
	color(14);
	sortIncome(); 
	readIncome();
	color(7);
	printf("\n\t\t\t\t-------------------------------------------------------\n");
	color(14);
	printf("\t\t\t\t\t\t    [R]eturn 返回\n"); 
	color(7);
	printf("\t\t\t\t*******************************************************\n\n");
	printf("\t\t\t\t\t\t按R返回：");
	char ch;
	scanf("%c",&ch);
	while(ch!='r'&&ch!='R'){
		scanf("%c",&ch);
	}
	adminMenu();
}

//用户信息 
void usersInformation()
{
	system("color 07");
	system("cls");
	color(7);
	printf("\n\n"); 
	printf("\t\t\t\t******************** 用 户 信 息 **********************\n\n");
	printf("\t\t\t\t          %-20s         %-20s","姓名","电话\n"); 
	printf("\t\t\t-------------------------------------------------------\n\n");
	color(14);
	readUsersList();

	color(7);
	printf("\t\t\t\t-------------------------------------------------------\n");
	printf("\t\t\t\t                     [R]eturn 返回\n"); 
	printf("\t\t\t\t*******************************************************\n\n");
	printf("\t\t\t\t按R返回:");
	char ch;
	fflush(stdin);
	scanf("%c",&ch);
		while(ch!='r'&&ch!='R'){
			scanf("%c",&ch);
		}	
	adminMenu();
}






