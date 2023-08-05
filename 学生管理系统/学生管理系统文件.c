#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cnt=0;
char name[20];
	int num;
	int age;
	int score;

typedef struct Node
{
	char name[20];
	int num;
	int age;
	int score;
	struct Node* next;
}Node,*Linklist;

Linklist crHeadNode()
{
	Linklist headNode=(Linklist)malloc(sizeof(Node));
	headNode->next=NULL;
	return headNode;
}

Linklist crNewNode(char name[],int num,int age,int score)//创建一个新学生结点
{
	Linklist P=(Linklist)malloc(sizeof(Node));
	strcpy(P->name,name);
	P->num=num;
	P->age=age;
	P->score=score;
	return P;
}

void addStuTail(Linklist headNode,Linklist P,char name[],int num,int age,int score)//在尾部插入一个学生信息
{
	P=crNewNode(name,num,age,score);
	while(headNode->next){
		headNode=headNode->next;
	}
	P->next=NULL;
	headNode->next=P;
	cnt++;
}

Linklist seekNode(Linklist headNode,int x)//寻找前一学生结点
{
	while(--x){
		headNode=headNode->next;
	}
	if(!headNode){
		return NULL;
	}
	return headNode;
}

void deleteNode(Linklist headNode,int x)//删除某学生信息
{
	headNode=seekNode(headNode,x);
	if(!headNode||!headNode->next){
		return ;
	}
	Linklist P=headNode->next;
	headNode->next=headNode->next->next;
	free(P);
	cnt--;
}

void modifyNode(Linklist headNode,int x)
{
	int score;
	headNode=seekNode(headNode,x);
	if(!headNode){
		return;
	}
	headNode=headNode->next;
	if(!headNode)
	{
		return;
	}
	printf("请输入你要修改的值：");
	scanf("%d",&score);
	headNode->score=score;
}

void searchNode(Linklist headNode,int x)//按序号查找
{
	headNode=seekNode(headNode,x);
	if(!headNode){
		printf("找不到该学生信息！\n");
		return;
	}
	headNode=headNode->next;
	if(!headNode){
		printf("找不到该学生信息！\n");
		return;
	}
	printf("姓名：%s\n学号：%d\n年龄：%d\n成绩：%d\n",headNode->name,headNode->num,headNode->age,headNode->score);
}

void ListReverse(Linklist headNode)//链表逆置   逆置思想：将头节点提出来，后续将链表排在头节点后，将其依次插到头节点与第一节点之间
{
	Linklist p,s;
	p=headNode->next;
	headNode->next=NULL;
	while(p)
	{
		s=p;
		p=p->next;
		//头插
		s->next=headNode->next;
		headNode->next=s;
	}
	printf("姓名\t学号\t年龄\t成绩\n");
	headNode=headNode->next;
	while(headNode){
		printf("%-8s%-8d%-8d%-8d\n",headNode->name,headNode->num,headNode->age,headNode->score);
		printf("\n");
		headNode=headNode->next;
	}
}


void printfList(Linklist headNode)//打印
{
	printf("姓名\t学号\t年龄\t成绩\n");
	headNode=headNode->next;
	while(headNode){
		printf("%-8s%-8d%-8d%-8d\n",headNode->name,headNode->num,headNode->age,headNode->score);
		printf("\n");
		headNode=headNode->next;
	}
}

void saveList(Linklist headNode)//保存
{
	FILE* fp=fopen("../data/member.txt","w");
	if(fp==NULL){
		printf("打开文件失败\n");
		return ;
	}
	headNode=headNode->next;
    while(headNode){
    	fprintf(fp,"%s\t%d\t%d\t%d\n",headNode->name,headNode->num,headNode->age,headNode->score);
    	headNode=headNode->next;
	}
	fclose(fp);
	fp=NULL;
	printf("保存成功!\n\n");
}

void readList(Linklist headNode)
{
	FILE* fp=fopen("../data/member.txt","r");
    if(fp==NULL){
		printf("打开文件失败\n");
		return ;
	}
	while(1){
		Linklist P=(Linklist)malloc(sizeof(Node));
	    P->next=NULL;
		if(fscanf(fp,"%s %d %d %d",P->name,&P->num,&P->age,&P->score)!=EOF){
			printf("%-8s%-8d%-8d%-8d\n",P->name,P->num,P->age,P->score);
		    printf("\n");
			headNode->next=P;
			headNode=headNode->next;
		}else{
			return;
		}
	}
	
	fclose(fp);
	fp=NULL;
}

void menu()//菜单
{
	printf("1——插入学生信息\n");
	printf("2——删除学生信息\n");
	printf("3——查找学生信息\n");
	printf("4——修改学生成绩\n");
	printf("5——保存学生信息\n");
	printf("6——打印学生信息\n");
	printf("7——读取文件信息\n");
	printf("8——逆序输出信息\n");
}

int choice()
{
	int choice;
	printf("请输入要进行的操作序号：\n");
	scanf("%d",&choice);
	return choice;
}

void work(Linklist headNode)
{
	
	menu();
	int a=choice();
	switch(a){
		case 1:{
			char name[20];
			int num,age,score;
			int n,i;
			printf("输入学生人数：");
			scanf("%d",&n);
			for(i=0;i<n;i++){
			    printf("请输入姓名、学号、年龄、成绩：\n");
			    scanf("%s %d %d %d",&name,&num,&age,&score);
		    	Linklist P;
			    addStuTail(headNode,P,name,num,age,score);
	    	}
			printf("增添成功!\n");
			break;
		}
		case 2:	{
			printf("请输入你要删除的学生序号：\n");
			int x;
			scanf("%d",&x);
			deleteNode(headNode,x);
			printf("删除成功!\n");
			break;
		}
		case 3:{
			printf("请输入你要查找的学生学号：\n");
			int x;
			scanf("%d",&x);
			searchNode(headNode,x);
			break;
		}
		case 4:{
			printf("请输入你要进行信息修改的学生编号：\n");
			int x;
			scanf("%d",&x);
			modifyNode(headNode,x);
			printf("修改成功!\n");
			break;
		}
		case 5:{
			saveList(headNode);
			break;
		}
		case 6:{
			printfList(headNode);
			break;
		}
		case 7:{
			readList(headNode);
			break;
		}
		case 8:{
			ListReverse(headNode);
			break;
		}
		default:
		    printf("输入错误\n"); break;
	}

}


int main()
{
	Linklist headNode=crHeadNode();
	while(1){
	    work(headNode);
   }
	return 0;
}



