/*����Ϊ���������㷨����*/
// QuickSort.cpp : �������̨Ӧ�ó������ڵ㡣
//��С��������

//#include <stdafx.h>
#include <iostream>  
using namespace std;  
void quickSort(int a[],int,int);  
  /*
  l = 0;
  len=sizeof(array)/sizeof(int);  

  */
void quickSort(int s[], int l, int r)  
{  
    if (l< r)  
    {        
        int i = l, j = r, x = s[l];  
        while (i < j)  
        {  
            while(i < j && s[j]>= x) // ���������ҵ�һ��С��x����  
                j--;   
            if(i < j)  
                s[i++] = s[j];  
            while(i < j && s[i]< x) // ���������ҵ�һ�����ڵ���x����  
                i++;   
            if(i < j)  
                s[j--] = s[i];  
        }  
        s[i] = x;  
        quickSort(s, l, i - 1); // �ݹ����  
        quickSort(s, i + 1, r);  
    }  
} 
