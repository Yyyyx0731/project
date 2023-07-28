#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <io.h>


//����

//��ʼ�� 
#define List_Init(list,node){\
	list=(node*)malloc(sizeof(node)); \ 
	list->next=NULL;\
}










 

//��ҳ�� 
//��ҳ���ݽṹ��
typedef struct
{
	int totalRecords;	//�ܼ�¼��
	int offset;			//��ǰҳ��ʼ��¼����ڵ�һ����¼��ƫ�Ƽ�¼��
	int pageSize;		//ҳ���С
	void *curPos;		//��ǰҳ��ʼ��¼�������еĽ���ַ
}Pagination_t;


//���ݷ�ҳ��paging��ƫ����offset����ҳ����λ������list�Ķ�Ӧλ��
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


//����ҳ��paging��λ������list�ĵ�һҳ
#define Paging_Locate_FirstPage(list, paging) { \
		paging.offset=0;						\
		paging.curPos=(void *)((list)->next);	\
	}

//����ҳ��paging��λ������list�����һҳ
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

//��������list����ҳ��paging,ʹ��ָ��curPos���α���pagingָ��ҳ����ÿ�����
//����iΪ���ͼ���������
#define Paging_ViewPage_ForEach(list, paging, list_node_t, pos, i) 	\
	for (i=0, pos = (list_node_t *) (paging.curPos);	\
			pos != list && i < paging.pageSize; 		\
			i++, pos=pos->next)							\


//���ݷ�ҳ��paging���㵱ǰ��ҳ��
#define Pageing_CurPage(paging) 	(0==(paging).totalRecords?0:1+(paging).offset/(paging).pageSize)


//���ݷ�ҳ��paging������ܵ�ҳ��
#define Pageing_TotalPages(paging)	(((paging).totalRecords%(paging).pageSize==0)?\
	(paging).totalRecords/(paging).pageSize:\
	(paging).totalRecords/(paging).pageSize+1)


//����paging�жϵ�ǰҳ���Ƿ�Ϊ��һҳ�����Ϊtrue��ʾ�ǣ�����false
#define Pageing_IsFirstPage(paging) (Pageing_CurPage(paging)<=1)


//����paging�жϵ�ǰҳ���Ƿ�Ϊ���һҳ�����Ϊtrue��ʾ�ǣ�����false
#define Pageing_IsLastPage(paging) 	(Pageing_CurPage(paging)>=Pageing_TotalPages(paging))


