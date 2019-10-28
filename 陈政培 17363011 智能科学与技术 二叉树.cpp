#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
typedef struct Node								//二叉树结构体 
{
	char n; 
	struct Node *left, *right; 
	int depth; 
}Node; 

Node *r; 										//树根节点 
char ans[1000]; 								//结果记录数组 
int arr=1,flag=0,d; 

int pow(int a, int b)							//次方计算函数 
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

void printtree(Node *Root)						//格式化打印二叉树函数 
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

void build(Node *Root,char value)				//输入并生成二叉树 
{
	Root->n=value;
	printtree(r);								//实时打印当前二叉树 
	if(d<Root->depth)
		d=Root->depth;							//记录树的深度 
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
void bfs(Node *Root, char t)					//深度搜索函数 
{
	if(Root == NULL)
	{
		return;
	}
	if(Root->n == t)
	{
		flag=1;									//flag变量用来记录是否找到目标字符，如果找到则标记为1 
		ans[arr]=Root->n;
		arr++;
		return;
		
	}
	bfs(Root->left,t);							//递归搜索树的左节点 
	if(flag==1)									//如果已经找到目标字符，则需要记录当前深度搜索的路径 
	{
		ans[arr]=Root->n;
		arr++;
		return;
	}
	bfs(Root->right,t);							//递归搜索树的右节点 
	if(flag==1)									//如果已经找到目标字符，则需要记录当前深度搜索的路径 
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
	
	cout<<"本程序仍然有部分bug，只有在生成完全二叉树时才可以按照格式打印树，如果为非完全二叉树则会出现格式错误\n";
	cout<<"本程序支持单个字符的输入，如果不需要继续生成左右节点则输入 # \n" ;
	
	r=(Node *)malloc(sizeof(Node)); 			//生成根节点 
	r->left=NULL;r->right=NULL;r->depth=1; 		//初始化根节点数据 
	cout<<"\n请输入根节点的值:";
	cin>>t;
	build(r,t); 								//调用生成树函数 
	cout<<"\n请输入需要找到的目标字符：";
	cin>>t;
	bfs(r,t); 									//调用深度搜索函数寻找目标字符 
	for(int i=arr-1;i>=1;i--) 					//将搜索路径按照从根节点出发输出 
	{
		cout<<ans[i]<<" ";
	}
}
 
