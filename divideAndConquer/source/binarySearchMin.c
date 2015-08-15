/*
binarySearchMin.c
升序int数组中，寻找第一次出现target的位置，有可能不存在该值。

使用分治的思想完成

author:guozheng
date:2015/08/15
*/

#include<stdio.h>

//使用循环
int binarySearchMin(int a[], int len, int target)
{
    int min=0;
    int max=len-1;
    int mid;
    while(min<=max)
    {
        mid =   min+((max-min)>>1);
        if(a[mid]<target)   min=mid+1;
        else if(a[mid]>target)  max=mid-1;
        else if(min!=max)   max=mid;
        else if(a[min]==target) return min;
        else    return -1;
    }
    return  -1;
}

//使用递归方法
int binarySearchMin2(int a[], int min, int max, int target)
{
    if(min>max) return -1;  //跳出递归的标准
    int mid;
    mid =   min+((max-min)>>1);
    if(a[mid]<target)   return binarySearchMin2(a,mid+1,max,target);
    else if(a[mid]>target)  return binarySearchMin2(a,min,mid-1,target);
    else if(min!=max)   return binarySearchMin2(a,min,mid,target);
    else if(a[min]==target) return min;
    else    return -1;
}


int main()
{
    int a[]={1,2,3,3,3,3,3,3,4,5,6};
    printf("%d\n",binarySearchMin(a,6,3));
    printf("%d\n",binarySearchMin2(a,0,5,3));
    return  0;

}
