#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<cstring>
#include<string>
using namespace std;

typedef struct Node pNode;
struct Node
{
    unsigned int data;
    pNode *prev, *next;
};
pNode *init(pNode **head, int n)
{
    pNode *p, *s;
    (*head) = (pNode *)malloc(sizeof(pNode));
    if ((*head) == NULL)
        exit(0);
    (*head)->next = NULL;
    (*head)->prev = NULL;
    p = (*head);
    int i;
    for (i = 0; i < n; i++)
    {
        s = (pNode *)malloc(sizeof(pNode));
        if (s == NULL)
            exit(0);
        s->data=i*i;
        s->next = NULL;
        p->next = s;
        s->prev = p;
        p = s;
    }
    s = (pNode *)malloc(sizeof(pNode));
    p->next=s;
    s->prev=p;
    s->next=NULL;
    return s;
}
void PrintListh(pNode *head)
{
    pNode *p;
    p = head->next;
    if (head->next == NULL)
        printf("the list is empty\n");
    while(p->next != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
void PrintListl(pNode *last)
{
    pNode *p;
    p = last->prev;
    if (last->prev == NULL)
        printf("the list is empty\n");
    while(p->prev != NULL)
    {
        printf("%d ", p->data);
        p = p->prev;
    }
    printf("\n");
}
void DeleteList(pNode **head)
{
    pNode *p;
    while((*head)->next != NULL)
    {
        p = (*head);
        p->next->prev = NULL;
        (*head) = p->next;
        free(p);
    }
}
void DelNumqList(pNode **head, int n)
{
    int i;
    pNode *p;
    p = (*head)->next;
    for (i = 1; i < n; ++i)
    {
    	if(p->next==NULL)
    	{
    		break;
    	}
    	p = p->next;
	}
    if(p->next == NULL)
    {
        p->prev->next = NULL;
        free(p);
    }
    else
    {
        p->next->prev = p->prev;
        p->prev->next = p->next;
        free(p);
    }
}
void AddNumqList(pNode **head, int n, int t,pNode **last)
{
    int i,flag=0;
    pNode *p,*s;
    p = (*head)->next;
    for (i = 1; i < n; ++i)
    {
    	if(p->next==NULL)
    	{
    		flag=1;
    		break;
    	}
    	p = p->next;
    }
    if(p->next == NULL)
    {
        p->data = t;
        (*last)=(pNode *)malloc(sizeof(pNode));
        p->next=(*last);
        (*last)->prev=p;
        (*last)->next=NULL;
    }
    else
    {
    	s = (pNode *)malloc(sizeof(pNode));
    	s->next=p->next;
    	p->next=s;
    	s->next->prev=s;
        s->data=t;
    }
}
int main()
{
    int n, element, flag,op=1,t,t1;
    pNode *head, *last;
    printf("请输入初始创建的链表个数（建议2^30个以下）：\n");
    scanf("%d", &n);
    last = init(&head, n);
    while(op!=0)
    {
    	printf("\n创建完成\n请输入需要进行的操作：\n1.正序输出列表 \n2.逆序输出列表 \n3.删除元素 \n4.插入元素 \n5.删除所有列表 \n0.退出程序");
    	scanf("%d",&op);
    	if(op==1)
		{
			PrintListh(head);
		} 
		else if(op==2)
		{
			PrintListl(last);
		}
		else if(op==3)
		{
			printf("输入需要删除第几个元素（超过最大数目默认删除最后一个）：\n");
			scanf("%d",&t);
			DelNumqList(&head, t);
			printf("删除完成\n");
			PrintListh(head);
		}
		else if(op==4)
		{
			printf("输入需要添加的元素位置：");
			scanf("%d",&t);
			printf("输入需要添加的数字：");
			scanf("%d",&t1);
			AddNumqList(&head, t,t1,&last);
			printf("添加完成\n");
			PrintListh(head);
		}
		else if(op==5)
		{
			DeleteList(&head);
			PrintListh(head);
			printf("test\n");
		}
		else if(op==0)
		{
			DeleteList(&head);
			break;
		}
		else
		{
			printf("非法操作\n");
		}
    }
    DeleteList(&head);
    return 0;
}
