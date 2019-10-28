#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
int numa[10000],numb[10000],ans[100000002];
int aplus(int numa[], int numb[], int la, int lb, int ans[])
{
	int a=la,b=lb,temp;
	//memset(ans,0,sizeof(ans));
	for(int i=1;i<=lb;i++)
	{
		temp=i-1;
		for(int j=1;j<=la;j++)
		{
			ans[temp+j]+=numa[j]*numb[i];
		}
	}
	for(int i=1;i<=temp;i++)
	{
		if(ans[i]>=10)
		{
			if(ans[temp] >= 10)
                temp++;
			ans[i+1]+=ans[i]/10;
			ans[i]=ans[i]%10;
		}
	}
	return temp;
}
int main()
{
	string a,b;
	cin>>a>>b;
	int la,lb,result;
	la=a.size();
	lb=b.size();
	for(int i=1;i<=la;i++)
	{
		numa[i]=a[la-i]-'0';
		numb[i]=b[lb-i]-'0';
	}
	result=aplus(numa,numb,la,lb,ans);
	for(int i=result;i>=1;i--)
	cout<<ans[i];
	cout<<endl;
}
