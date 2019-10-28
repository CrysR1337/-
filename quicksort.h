/*下面为快速排序算法程序*/
// QuickSort.cpp : 定义控制台应用程序的入口点。
//从小到大排序

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
            while(i < j && s[j]>= x) // 从右向左找第一个小于x的数  
                j--;   
            if(i < j)  
                s[i++] = s[j];  
            while(i < j && s[i]< x) // 从左向右找第一个大于等于x的数  
                i++;   
            if(i < j)  
                s[j--] = s[i];  
        }  
        s[i] = x;  
        quickSort(s, l, i - 1); // 递归调用  
        quickSort(s, i + 1, r);  
    }  
} 
