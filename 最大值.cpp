#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int a,max,min;
	cin>>a;
	max=a;min=a;
	for(int i=0;i<9;i++)
	{
		cin>>a;
		if(a>max)
		max=a;
		if(a<min)
		min=a;
	}
	cout<<max<<endl<<min<<endl;
}
