#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <io.h>


//链表

//初始化 
#define List_Init(list,node){\
	list=(node*)malloc(sizeof(node)); \ 
	list->next=NULL;\
}










 

//分页器 
//分页数据结构体
typedef struct
{
	int totalRecords;	//总记录数
	int offset;			//当前页起始记录相对于第一条记录的偏移记录数
	int pageSize;		//页面大小
	void *curPos;		//当前页起始记录在链表中的结点地址
}Pagination_t;


//根据分页器paging的偏移量offset将分页器定位到链表list的对应位置
#define List_Paging(list, paging, list_node_t) {			\
		if(paging.offset+paging.pageSize>=paging.totalRecords){	\
			Paging_Locate_LastPage(list, paging, list_node_t);	}\
		else {													\
			int i;												\
			list_node_t * pos=(list)->next;						\
			for( i=0; i<paging.offset && pos!=list ; i++) 		\
			   pos=pos->next;		 							\
			paging.curPos=(void*)pos;							\
		}														\
	}


//将分页器paging定位到链表list的第一页
#define Paging_Locate_FirstPage(list, paging) { \
		paging.offset=0;						\
		paging.curPos=(void *)((list)->next);	\
	}

//将分页器paging定位到链表list的最后一页
#define Paging_Locate_LastPage(list, paging, list_node_t) {	\
	int i=paging.totalRecords % paging.pageSize;	\
	if (0==i && paging.totalRecords>0)				\
		i=paging.pageSize;							\
	paging.offset=paging.totalRecords-i;			\
	list_node_t * pos=(list)->prev;					\
	for(;i>1;i--)									\
		pos=pos->prev;								\
	paging.curPos=(void*)pos;						\
													\
}

//对于链表list及分页器paging,使用指针curPos依次遍历paging指向页面中每个结点
//这里i为整型计数器变量
#define Paging_ViewPage_ForEach(list, paging, list_node_t, pos, i) 	\
	for (i=0, pos = (list_node_t *) (paging.curPos);	\
			pos != list && i < paging.pageSize; 		\
			i++, pos=pos->next)							\


//根据分页器paging计算当前的页号
#define Pageing_CurPage(paging) 	(0==(paging).totalRecords?0:1+(paging).offset/(paging).pageSize)


//根据分页器paging计算的总的页数
#define Pageing_TotalPages(paging)	(((paging).totalRecords%(paging).pageSize==0)?\
	(paging).totalRecords/(paging).pageSize:\
	(paging).totalRecords/(paging).pageSize+1)


//根据paging判断当前页面是否为第一页。结果为true表示是，否则false
#define Pageing_IsFirstPage(paging) (Pageing_CurPage(paging)<=1)


//根据paging判断当前页面是否为最后一页。结果为true表示是，否则false
#define Pageing_IsLastPage(paging) 	(Pageing_CurPage(paging)>=Pageing_TotalPages(paging))


