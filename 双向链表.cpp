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
    printf("�������ʼ�������������������2^30�����£���\n");
    scanf("%d", &n);
    last = init(&head, n);
    while(op!=0)
    {
    	printf("\n�������\n��������Ҫ���еĲ�����\n1.��������б� \n2.��������б� \n3.ɾ��Ԫ�� \n4.����Ԫ�� \n5.ɾ�������б� \n0.�˳�����");
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
			printf("������Ҫɾ���ڼ���Ԫ�أ����������ĿĬ��ɾ�����һ������\n");
			scanf("%d",&t);
			DelNumqList(&head, t);
			printf("ɾ�����\n");
			PrintListh(head);
		}
		else if(op==4)
		{
			printf("������Ҫ��ӵ�Ԫ��λ�ã�");
			scanf("%d",&t);
			printf("������Ҫ��ӵ����֣�");
			scanf("%d",&t1);
			AddNumqList(&head, t,t1,&last);
			printf("������\n");
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
			printf("�Ƿ�����\n");
		}
    }
    DeleteList(&head);
    return 0;
}
