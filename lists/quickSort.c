/*
qucikSort.c
快速排序

author:guozheng
date:2015/06/30
*/

#include<stdio.h>
#include<string.h>


//在快速排序中，以start处元素为基准，将其摆放到合适的位置
int partition(int* list, int start, int end)
{
   /*
    伪代码：
    pivot=list[start];
    当start<end时，循环：
        从尾部开始寻找第一个小于pivot的值，另end为该位置，并将该值移到start位置
        从部开始寻找第一个大于pivot的值，另start为该位置，并将该值移到end位置
    结束循环
    将pivot放在start位置
    返回start
   */
    
    int pivot;
    pivot   =   list[start];
    while(start<end)
    {
        while(start<end && list[end]>=pivot) end--;
        list[start] =   list[end];
        while(start<end && list[start]<=pivot) start++;
        list[end]   =   list[start];
    }
    list[start]     =   pivot;
    return start;
}

void quickSort(int* list, int start, int end)
{
    /*
    伪代码：
    当start<end时，循环
        以第一个元素作为基准，把该元素搬移到合适的位置（调用函数partition);
        quickSort(list,start,middle-1);
        quickSort(list,middle+1,start);
    结束循环

    如何写partition函数，请转到partition函数处
    */
    int middle,i;
    //printf("start=%d,end=%d\n",start,end);
    if(start<end)
    {
        middle  =   partition(list,start,end);
        //printf("middle=%d\n",middle);
        //for(i=0;i<=3;i++) printf("%d ",list[i]); printf("\n");
        quickSort(list,start,middle-1);
        quickSort(list,middle+1,end);
    }
}

void main(int argc, char* argv[])
{
    int len =   argc-1;
    int list[len];
    //printf("len=%d\n",len);
    int i;
    //把输入的数值赋给数组list
    for(i=1;i<=len;i++)
    {
        list[i-1] =   atoi(argv[i]);
    }

    printf("排序前的数组---->");
    for(i=0;i<len;i++)
    {
        printf("%d  ",list[i]);
    }
    printf("\n");

    quickSort(list,0,len-1);
    
    printf("排序后的数组---->");
    for(i=0;i<len;i++)
    {
        printf("%d  ",list[i]);
    }
    printf("\n");

}

