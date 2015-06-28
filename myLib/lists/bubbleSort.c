/*
bubbleSort.c
对数组进行冒泡排序

author:guozheng
date:2015/06/28
*/

#include<stdio.h>
#include<string.h>


void swap(int* list, int i, int j)
{
    
    int temp;
    temp    =   list[i];
    list[i] =   list[j];
    list[j] =   temp;
}

void bubbleSort(int* list, int len)
{
    /*
    冒泡法思路（升序排列）：
    1、每一趟子循环负责把该数组中最大的值搬移到最后一位；
    2、不断重复上述操作，直到数组长度只有1；
    */
    int i,j;
    for(i=len;i>1;i--)
    {
        for(j=1;j<i;j++)
        {
            //printf("i=%d,j=%d,list[j-1]=%d,list[j]=%d\n",i,j,list[j-1],list[j]);
            if(list[j-1]>list[j]) swap(list,j-1,j);
        }
    }
}

//void main(int argc, char* argv[])
//{
//    int len     =   argc-1;
//    int list[len];
//    int i;
//    for(i=0;i<len;i++)
//    {
//        list[i] =   atoi(argv[i+1]);
//    }
//
//    //int list[5] =   {2,3,4,1,2};
//    bubbleSort(list,len);
//    for(i=0;i<len;i++)
//    {
//        printf("%d, ",list[i]);
//    }
//    printf("\n");
//}
