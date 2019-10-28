#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
int gcd(int a,int b)
{
	if(b==0)
	return a;
	else
	gcd(b,a%b);
}
int main()
{
	int a,b,m;
	cin>>a>>b;
	m=a/gcd(a,b)*b;
	cout<<"最大公约数="<<gcd(a,b)<<endl;
	cout<<"最小公倍数="<<m<<endl;
	return 0;
}
