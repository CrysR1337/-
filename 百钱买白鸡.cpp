#include<iostream>
using namespace std;
int main()
{
	int a=0,b,c,x;
	while(a<100)
	{
		a++;
		b=(100-3*a)/2;
		x=(100-3*a)%2;
		switch(x)
		{
			case 0:
				while(b>0)
				{
					b--;
					c=(100-3*a-2*b)*3;
					cout<<a<<" "<<b<<" "<<c<<endl;
				}
				break;
			case 1:
				while(b>0)
				{
					b--;
					c=(100-3*a-2*b)*3;
					cout<<a<<" "<<b<<" "<<c<<endl;
				}
		}
	}
}
