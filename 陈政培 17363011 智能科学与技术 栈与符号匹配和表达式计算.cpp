#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath> 
#include<string.h>
using namespace std;

struct numstack
{
	int n;
	struct numstack *s;
};
struct opstack
{
	char op;
	struct opstack *s;
};
numstack* numPop(numstack* L)
{
    if(L->s == NULL)
    {
        return NULL;
    }
    numstack* temp = L->s;
    //printf("%d ",temp->data);
    free(L);
    return temp;
}
numstack* numPush(numstack* L, int e)
{
    numstack* newNode = (numstack*) malloc(sizeof(numstack));
    newNode->n = e;
    newNode->s = L;
    L= newNode;
    return L;
}
opstack* opPop(opstack* L)
{
    if(L->s == NULL)
    {
        return NULL;
    }
    opstack* temp = L->s;
    //printf("%d ",temp->data);
    free(L);
    return temp;
}
opstack* opPush(opstack* L, char e)
{
    opstack* newNode = (opstack*) malloc(sizeof(opstack));
    newNode->op = e;
    newNode->s = L;
    L= newNode;
    return L;
}
int main()
{
	char str[10000];
	printf("���������ʵ�ַ���ƥ���Ⲣ�ҷ��س��������λ�ã�������ַ����е�λ�ð������֣�\n");
	printf("��������Խ����������㣬��ʹ�� + - * / �� �� �� �� { } ���Ž�������(����ʹ��Ӣ�ļ��̷��ţ���֧�����ķ�������) \n");
	printf("Ҳ���Բ���������ֱ��ʹ�����Ž���ƥ����\n");
	printf("����������Ҫ���м������ı��ʽ��\n"); 
	scanf("%s",str);
	int i,flag=1,st=0;
	struct numstack *num=NULL;
	struct opstack *op=NULL;
	for (i=0;i<strlen(str);i++)
	{
		if(str[i]=='(')
		{
			st=0;
			op=opPush(op,'(');
		}
		else if(str[i]==')')
		{
			st=0;
			int m=0;
			//cout<<flag<<endl;
			while(op!=NULL && op->op!='(')
			{
				if(num==NULL)
					break;
				int t1=num->n;
				switch(op->op)
				{
					case '+':{
						num=numPop(num);
						num->n=num->n+t1;
						break;
					}
					case '-':{
						num=numPop(num);
						num->n=num->n-t1;
						break;
					}
					case '*':{
						num=numPop(num);
						num->n=num->n*t1;
						break;
					}
					case '/':{
						num=numPop(num);
						num->n=num->n/t1;
						break;
					}
					case '[':{
						flag=0;
						break;
					}
					case '{':{
						flag=0;
						break;
					}
					default:
						break;
				}
				
				if(op==NULL)
				{
					flag=0;
					break;
				}
				if(flag==0)
					break;
				op=opPop(op);
				//cout<<num<<"   "<<num->n<<"   "<<op<<"    "<<op->op<<endl;
			}
			if(op==NULL)
				{
					flag=0;
					break;
				}
			if(num==NULL)
				{
					while(op!=NULL && op->op!='(')
					{
						op=opPop(op);
					}
				}
			if(flag==0)
				break;
			op=opPop(op);
		}
		else if(str[i]=='[')
		{
			st=0;
			op=opPush(op,'[');
		}
		else if(str[i]==']')
		{
			st=0;
			while(op!=NULL && op->op!='[')
			{
				if(num==NULL)
					break;
				int t1=num->n;//cout<<num<<"   "<<num->n<<"   "<<op<<"    "<<op->op<<endl;
				switch(op->op)
				{
					case '+':{
						num=numPop(num);
						num->n=num->n+t1;
						break;
					}
					case '-':{
						num=numPop(num);
						num->n=num->n-t1;
						break;
					}
					case '*':{
						num=numPop(num);
						num->n=num->n*t1;
						break;
					}
					case '/':{
						num=numPop(num);
						num->n=num->n/t1;
						break;
					}
					case '(':{
						flag=0;
						break;
					}
					case '{':{
						flag=0;
						break;
					}
					default:
						break;
				}
				if(flag==0)
					break;
				op=opPop(op);
				
			}
			if(op==NULL)
				{
					flag=0;
					break;
				}
			if(num==NULL)
				{
					while(op!=NULL && op->op!='[')
					{
						op=opPop(op);
					}
				}
			if(flag==0)
				break;
			op=opPop(op);
		}
		else if(str[i]=='{')
		{
			st=0;
			op=opPush(op,'{');
		}        
		else if(str[i]=='}')
		{
			st=0;
			while(op!=NULL && op->op!='{')
			{
				if(num!=NULL)
					break;
				int t1=num->n;
				switch(op->op)
				{
					case '+':{
						num=numPop(num);
						num->n=num->n+t1;
						break;
					}
					case '-':{
						num=numPop(num);
						num->n=num->n-t1;
						break;           
					}    
					case '*':{
						num=numPop(num);
						num->n=num->n*t1;
						break;
					}
					case '/':{
						num=numPop(num);
						num->n=num->n/t1;
						break;
					}
					case '[':{	           
						flag=0;
						break;
					}
					case '(':{
						flag=0;
						break;
					}
					default:
						break;
				}
				if(op==NULL)
				{
					flag=0;
					break;
				}
				if(flag==0)
					break;
				op=opPop(op);
			}
			if(op==NULL)
				{
					flag=0;
					break;
				}
			if(num==NULL)
				{
					while(op!=NULL && op->op!='{')
					{
						op=opPop(op);
					}
				}
			if(flag==0)
				break;
			op=opPop(op);
		}
		else if(str[i]=='+' || str[i]=='-')
		{
			st=0;
			if(op==NULL)
				op=opPush(op,str[i]);
			else if(op->op=='*' || op->op=='/')
			{
				int temp=num->n;
				num=numPop(num);
				if(op->op=='*')
					num->n=num->n*temp;
				else
					num->n=num->n/temp;
				op=opPop(op);
				op=opPush(op,str[i]);
			}
			else if(op->op=='+' || op->op=='-')
			{
				int temp=num->n;
				num=numPop(num);
				if(op->op=='+')
					num->n=num->n+temp;
				else
					num->n=num->n-temp;
				op=opPop(op);
				op=opPush(op,str[i]);
			}
			else
				op=opPush(op,str[i]);
		}
		else if(str[i]=='*' || str[i]=='/')
		{
			st=0;
			if(op==NULL)
				op=opPush(op,str[i]);
			else if(op->op=='*' || op->op=='/')
			{
				int temp=num->n;
				num=numPop(num);
				if(op->op=='*')
					num->n=num->n*temp;
				else
					num->n=num->n/temp;
				op=opPop(op);
				op=opPush(op,str[i]);
			}
			else
			{
				op=opPush(op,str[i]);
			}
		}
		else if(str[i]>=48 && str[i]<=57)
		{
			if(st==0)
			{
				num=numPush(num,(int)(str[i]-'0'));
				st=1;
			}
			else
			{
				num->n=num->n*10+(int)(str[i]-'0');
			}
		}
		//cout<<num<<"   "<<num->n<<"   "<<op<<"    "<<endl;
	}
	if(flag==0)
	{
		printf("����ƥ��ʧ�ܣ�����λ��Ϊ��%d���ַ�\n",i+1);
	}
	else
	{
		
		while(op!=NULL)
			{
				//cout<<num<<"   "<<num->n<<"   "<<op<<"    "<<op->op<<endl;
				if(num==NULL)
					break;
				int t1=num->n;
				switch(op->op)
				{
					case '+':{
						num=numPop(num);
						num->n=num->n+t1;
						break;
					}
					case '-':{
						num=numPop(num);
						num->n=num->n-t1;
						break;
					}
					case '*':{
						num=numPop(num);
						num->n=num->n*t1;
						break;
					}
					case '/':{
						num=numPop(num);
						num->n=num->n/t1;
						break;
					}
					case '[':{
						flag=0;
						break;
					}
					case '{':{
						flag=0;
						break;
					}
					case '(':{
						flag=0;
						break;
					}
					default:
						break;
				}
				op=opPop(op);
			}
		if(flag==0 || op!=NULL)
		{
			printf("����ƥ��ʧ�ܣ�����λ��Ϊ��%d���ַ�\n",i+1);
			return 0;
		}
		printf("����ƥ��ɹ�������Ϊ��%d\n",num->n);
		num=numPop(num);
		//cout<<num<<"   "<<"   "<<op<<endl;
	}
	return 0;
} 
