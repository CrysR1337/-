#include <stdio.h>
#define MAXN 1000
int prime[MAXN],sol[MAXN],used[MAXN],n;
//prime[i]=1表示i是质数,sol[i]=当前输出方案中环上第i个数,
//used[i]=当前输出方案中环上第i个数
int isprime(int in) //是质数返回1，不是返回0
{
	int i;
	for(i=2;i<in;i++)
		if(in%i==0)
			return 0;
	return 1;
}
void dfs(int m) //填写环上第m个数
{
	int i,j;
	if(m>n) //最后一个数已经填写完
	{
		for(j=1;j<=n;j++)
			printf("%d ",sol[j]);
		printf("\n");
		return;
	}
	for(i=2;i<=n;i++)
	{
		if(used[i]==0&&prime[sol[m-1]+i]) //数字i没有用过且i与第m-1个数之和为质数
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
	used[1]=1; //数字1被用过了
	sol[1]=1; //第一个数是数字1
	dfs(2);
	return 0;
}
