#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	float a,b,c,x,s;
	cout<<"请输入三角形的三边长："<<endl;
	cin>>a>>b>>c;
	if((a<b+c)&&(b<a+c)&&(c<a+b))
	{
		pow(a,2)-pow(x,2)==pow(c,2)-pow(b-x,2);
		s=sqrt(pow(a,2)-pow(x,2))*b/2;
		cout<<"三角形的面积为"<<s<<endl;
	}
	else
	{
	cout<<"Can't"<<endl;
    }
    system("pause");
    return 0;
}
