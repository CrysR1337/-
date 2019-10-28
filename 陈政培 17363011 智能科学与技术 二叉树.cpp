#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
typedef struct Node								//�������ṹ�� 
{
	char n; 
	struct Node *left, *right; 
	int depth; 
}Node; 

Node *r; 										//�����ڵ� 
char ans[1000]; 								//�����¼���� 
int arr=1,flag=0,d; 

int pow(int a, int b)							//�η����㺯�� 
{
	if(b<=0)
		return 1;
	else
	{
		int temp=1;
		for(int i=1;i<=b;i++)
			temp=temp*a;
		return temp;
	}
}

void printtree(Node *Root)						//��ʽ����ӡ���������� 
{
	system("cls");
	int x=d-1;
	Node *que[1000],*temp=NULL;
	Node *s=(Node *)malloc(sizeof(Node));
	s->left=NULL;s->right=NULL;s->n='#';
	for(int i=1;i<=999;i++)
		que[i]=NULL;
	int head=1,tail=2;
	que[head]=Root;
	for(int i=1;i<=pow(2,x)-1;i++)
				cout<<" ";
	while(head!=tail)
	{
		if(temp!=NULL && que[head]->depth!=temp->depth)
		{
			cout<<endl;
			x--;
			for(int i=1;i<=pow(2,x)-1;i++)
				cout<<" ";
		}
		cout<<que[head]->n;
		for(int i=1;i<=pow(2,x+1)-1;i++)
				cout<<" ";
		temp=que[head];
		if(temp->left!=NULL)
			que[tail++]=temp->left;
		if(temp->right!=NULL)
			que[tail++]=temp->right;
		head++;
	}
	cout<<endl;
} 

void build(Node *Root,char value)				//���벢���ɶ����� 
{
	Root->n=value;
	printtree(r);								//ʵʱ��ӡ��ǰ������ 
	if(d<Root->depth)
		d=Root->depth;							//��¼������� 
	char left,right;
	if(1)
	{
		cout<<"Enter left node for "<<Root->n<<": ";
		cin>>left;
		if(left!='#')
		{
			Root->left=(Node *)malloc(sizeof(Node));
			Root->left->left=NULL;Root->left->right=NULL;Root->left->depth=Root->depth+1;
			build(Root->left,left);
		}
		else
			Root->left=NULL;
		if(1)
		{
			cout<<"Enter right node for "<<Root->n<<": ";
			cin>>right;
			if(right!='#')
			{
				Root->right=(Node *)malloc(sizeof(Node));
				Root->right->left=NULL;Root->right->right=NULL;Root->right->depth=Root->depth+1;
				build(Root->right,right);
			}
			else
				Root->right=NULL;
		}
		
	}
}
void bfs(Node *Root, char t)					//����������� 
{
	if(Root == NULL)
	{
		return;
	}
	if(Root->n == t)
	{
		flag=1;									//flag����������¼�Ƿ��ҵ�Ŀ���ַ�������ҵ�����Ϊ1 
		ans[arr]=Root->n;
		arr++;
		return;
		
	}
	bfs(Root->left,t);							//�ݹ�����������ڵ� 
	if(flag==1)									//����Ѿ��ҵ�Ŀ���ַ�������Ҫ��¼��ǰ���������·�� 
	{
		ans[arr]=Root->n;
		arr++;
		return;
	}
	bfs(Root->right,t);							//�ݹ����������ҽڵ� 
	if(flag==1)									//����Ѿ��ҵ�Ŀ���ַ�������Ҫ��¼��ǰ���������·�� 
	{
		ans[arr]=Root->n;
		arr++;
		return;
	}
}
 

int main()
{
	int n;
	char t;
	
	cout<<"��������Ȼ�в���bug��ֻ����������ȫ������ʱ�ſ��԰��ո�ʽ��ӡ�������Ϊ����ȫ�����������ָ�ʽ����\n";
	cout<<"������֧�ֵ����ַ������룬�������Ҫ�����������ҽڵ������� # \n" ;
	
	r=(Node *)malloc(sizeof(Node)); 			//���ɸ��ڵ� 
	r->left=NULL;r->right=NULL;r->depth=1; 		//��ʼ�����ڵ����� 
	cout<<"\n��������ڵ��ֵ:";
	cin>>t;
	build(r,t); 								//�������������� 
	cout<<"\n��������Ҫ�ҵ���Ŀ���ַ���";
	cin>>t;
	bfs(r,t); 									//���������������Ѱ��Ŀ���ַ� 
	for(int i=arr-1;i>=1;i--) 					//������·�����մӸ��ڵ������� 
	{
		cout<<ans[i]<<" ";
	}
}
 
