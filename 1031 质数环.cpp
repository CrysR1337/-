#include <stdio.h>
#define MAXN 1000
int prime[MAXN],sol[MAXN],used[MAXN],n;
//prime[i]=1��ʾi������,sol[i]=��ǰ��������л��ϵ�i����,
//used[i]=��ǰ��������л��ϵ�i����
int isprime(int in) //����������1�����Ƿ���0
{
	int i;
	for(i=2;i<in;i++)
		if(in%i==0)
			return 0;
	return 1;
}
void dfs(int m) //��д���ϵ�m����
{
	int i,j;
	if(m>n) //���һ�����Ѿ���д��
	{
		for(j=1;j<=n;j++)
			printf("%d ",sol[j]);
		printf("\n");
		return;
	}
	for(i=2;i<=n;i++)
	{
		if(used[i]==0&&prime[sol[m-1]+i]) //����iû���ù���i���m-1����֮��Ϊ����
		{
			used[i]=1;
			sol[m]=i;
			if(m<n) dfs(m+1);
			else if(prime[sol[1]+i]) dfs(m+1);
			sol[m]=0;
			used[i]=0;
		}
	}
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=2;i<=2*n;i++)
		prime[i]=isprime(i);
	used[1]=1; //����1���ù���
	sol[1]=1; //��һ����������1
	dfs(2);
	return 0;
}
