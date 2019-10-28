#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
struct note
{
	int x;
	int y;
	int s;
};
struct note que[2501];
struct door
{
	int x1;
	int y1;
	int x2;
	int y2;
	int temp;
};
struct door fly[26];
char maze[51][51];
int book[51][51];
int main()
{
	int T;
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};//1-right 2-down 3-left 4-up
	cin>>T;
	int ans[T+1];
	int N,M,stx,sty,endx,endy,flag=0,tx,ty,step=0;
	int head=1,tail=1;
	for(int p=1;p<=T;p++)
	{
		for(int i=0;i<26;i++)
		{
			fly[i].temp=0;
		}
		cin>>N>>M;
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=M;j++)
			{
				cin>>maze[i][j];
				if(maze[i][j]=='L')
				{stx=i;sty=j;}
				if(maze[i][j]=='Q')
				{endx=i;endy=j;}
				if(maze[i][j]>=97 && maze[i][j]<=122)
				{
					if(fly[maze[i][j]-'a'].temp==0)
					{
						fly[maze[i][j]-'a'].x1=i;fly[maze[i][j]-'a'].y1=j;
						fly[maze[i][j]-'a'].temp=1;
					}
					if(fly[maze[i][j]-'a'].temp==1)
					{
						fly[maze[i][j]-'a'].x2=i;fly[maze[i][j]-'a'].y2=j;
						fly[maze[i][j]-'a'].temp=2;
					}
				}
			}
		}
			que[tail].x=stx;que[tail].y=sty;que[tail].s=step;
			step++;tail++;book[stx][sty]=1;
			while(head<tail)
			{cout<<tail<<" ";
				for(int k=0;k<=3;k++)
				{
					//cout<<head<<endl;
					tx=que[head].x+next[k][0];
					ty=que[head].y+next[k][1];
					if(tx<1 || ty<1 || tx>M || ty>N)
						continue;
					if(maze[tx][ty]!='#' && book[tx][ty]==0)
					{
						if(maze[tx][ty]=='.')
						{
							book[tx][ty]=1;
							que[tail].x=tx;que[tail].y=ty;que[tail].s=step;
							tail++;
							//cout<<tail<<" ";
						}
						else
						{
							book[tx][ty]=1;
							if(tx==fly[maze[tx][ty]-'a'].x1)
							{
								book[tx][ty]=1;
								tx=fly[maze[tx][ty]-'a'].x2;
								ty=fly[maze[tx][ty]-'a'].y2;
								book[tx][ty]=1;
								que[tail].x=tx;que[tail].y=ty;que[tail].s=step;
								tail++;//cout<<tail<<" ";
							}
							else
							{
								book[tx][ty]=1;
								tx=fly[maze[tx][ty]-'a'].x1;
								ty=fly[maze[tx][ty]-'a'].y1;
								book[tx][ty]=1;
								que[tail].x=tx;que[tail].y=ty;que[tail].s=step;
								tail++;//cout<<tail<<" ";
							}
						}
					}
						if(tx==endx && ty==endy)
						{
							flag=1;
							break;
						}
				}
					if(flag==1)
						break;
					head++;
					if(que[head].s>step)
					step++;
					//cout<<head<<" ";
			}
			if(head==tail)
				ans[p]=-1;
			else
				ans[p]=que[tail-1].s;
				//cout<<tail<<" ";
				//for(int i=1;i<=tail-1;i++)
				cout<<que[tail-1].s<<" ";
		flag=0;head=1;tail=1;
	}
	for(int c=1;c<=T;c++)
	cout<<ans[c]<<endl;
}
