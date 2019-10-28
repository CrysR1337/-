#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<stdio.h>
using namespace std;

#define MAXSIZE 1000
#define N 30

typedef struct
{
    int x, y; 
    int e;
} Triple;

typedef struct
{
    Triple data[MAXSIZE];
    int mu, nu, tu;
} TSMatrix;

TSMatrix FastMultSMatrix_2(TSMatrix A,TSMatrix B);
void RPos(TSMatrix M, int rpos[]);
TSMatrix FastTransposeSMatrix(TSMatrix M);
TSMatrix ArrayToTriple(int A[][N], int m, int n);

int main()
{
	TSMatrix a,b,c;
	int m,n,i,j,k;
	cin>>m>>n;
	int arr1[m][n];
	k=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>arr1[i][j];
			if (arr1[i][j] != 0)
			{
				a.data[k].x = i + 1; 
				a.data[k].y = j + 1; 
				a.data[k++].e = arr1[i][j];
			}
			a.mu = m;
			a.nu = n;
			a.tu = k;  
		}
	}
	cin>>m>>n;
	int arr2[m][n];
	k=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>arr2[i][j];
			if (arr2[i][j] != 0)
			{
				b.data[k].x = i + 1; 
				b.data[k].y = j + 1; 
				b.data[k++].e = arr2[i][j];
			}
			b.mu = m;
			b.nu = n;
			b.tu = k; 
		}
	}
	if(a.nu!=b.mu)
    {
    	printf( "行列不相等，乘法计算错误\n" );
		return 0;
    }
	c=FastMultSMatrix_2(a,b);
	cout<<"矩阵行数："<<c.mu<<"矩阵列数："<<c.nu<<"矩阵元素个数："<<c.tu<<endl;
	cout<<"二维矩阵：";
	int arr3[c.mu][c.nu];
	for (i=0; i<c.mu; i++)
		for (j=0; j<c.nu; j++)
			arr3[i][j] = 0;
	for (i=0; i<c.tu; i++)
		arr3[c.data[i].x-1][c.data[i].y-1] = c.data[i].e;
	for (i=0; i<c.mu; i++)
	{
		cout<<endl;
		for (j=0; j<c.nu; j++)
		{
			cout<<arr3[i][j]<<" ";
		}
	}
	cout<<endl;
	return 0;
}

TSMatrix FastMultSMatrix_2(TSMatrix A,TSMatrix B)
{  
    TSMatrix C;
    int Arpos[N] = {0}, Brpos[N] = {0};
    int arow, brow, ccol;
    int i, p, q, ta, tb;          
    C.mu= A.mu;
    C.nu= B.nu;
    C.tu= 0;
    if(A.tu * B.tu != 0)
    {
		B= FastTransposeSMatrix(B);
        RPos(A,Arpos);
        RPos(B,Brpos);    
        for(arow=1; arow<=A.mu; arow++)
        {
            ta= (arow < A.mu) ? Arpos[arow] : A.tu;   
            for(brow=1; brow<=B.mu; brow++)
            {
                C.data[C.tu].e= 0;
                p= Arpos[arow-1];      
                tb= (brow < B.mu) ? Brpos[brow] : B.tu;
                q= Brpos[brow-1];
                while(p < ta && q < tb)
                {
                    if(A.data[p].y < B.data[q].y)
                    	p++;
                    else if (A.data[p].y > B.data[q].y)
                    	q++;
                	else
                        C.data[C.tu].e+= A.data[p++].e * B.data[q++].e;
                }
                if(C.data[C.tu].e != 0)
                {
                    C.data[C.tu].x= arow;
                	C.data[C.tu++].y= brow;
                }
            }
        }
	}
    return C;
}

void RPos(TSMatrix M, int rpos[])
{
    int num[N] = {0};
    int i, row;
    for(i=0; i<M.tu; i++)
		num[M.data[i].x-1]++;     
    rpos[0]= 0;
    for(row=1; row<M.mu; row++)
    	rpos[row]= rpos[row-1] + num[row-1];
}

TSMatrix FastTransposeSMatrix(TSMatrix M)
{
    TSMatrix T;
    int k, i, col;
    int num[N] = {0};
    int cpot[N] = {0};
    T.mu= M.nu;
    T.nu= M.mu;
    T.tu= M.tu;
    if(T.tu > 0)
    {
        for(i=0; i<M.tu; i++)
			num[M.data[i].y-1]++;
        cpot[0]= 0;
        for(col=1; col<M.nu; col++)
        	cpot[col]= cpot[col-1] + num[col-1];
        for(i=0; i<M.tu; i++)
        {
        	col= M.data[i].y - 1;
            k= cpot[col];
            T.data[k].x= M.data[i].y;
            T.data[k].y= M.data[i].x;         
            T.data[k].e= M.data[i].e;
        	cpot[col]++;
    	}
    }
    return T;
}

TSMatrix ArrayToTriple(int A[][N], int m, int n)
{
TSMatrix T;
int i, j, k;

k = 0;
for (i=0; i<m; i++)
for (j=0; j<n; j++)
if (A[i][j] != 0)
{
T.data[k].x = i + 1;
T.data[k].y = j + 1;
T.data[k++].e = A[i][j];
}
T.mu = m;
T.nu = n;
T.tu = k; 
return T;
}
