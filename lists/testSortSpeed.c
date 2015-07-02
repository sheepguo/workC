/*
testSortSpeed.c
测试各种不同排序算法的速度

author:guozheng
date:2015/07/02
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/timeb.h>
#include"../myLib/lists/quickSort.h"
#include"../myLib/lists/bubbleSort.h"
#include"../myLib/lists/straightInsertionSort.h"
#include"../myLib/lists/straightSelectionSort.h"
#include"../myLib/lists/shellSort.h"
#include"../myLib/lists/heapSort.h"



void main(int argc, char* argv[])
{
    //printf("-1---------------------->\n");
    int len     =   atoi(argv[1]);
    //printf("-2---------------------->\n");
    int repeat  =   atoi(argv[2]);
    int show    =   atoi(argv[3]);  //如果是1，则输出排序之后的值；若是0，则不输出；
    
    //printf("-3---------------------->\n");
    int list[len],list1[len],list2[len],list3[len],list4[len],list5[len],list6[len];
    //printf("-4---------------------->\n");
    int i;
    srand(time(NULL));
    //printf("0---------------------->\n");
    for(i=0;i<len;i++)
    {
        list[i] =   rand()%len;
        list1[i]=   list[i];
        list2[i]=   list[i];
        list3[i]=   list[i];
        list4[i]=   list[i];
        list5[i]=   list[i];
        list6[i]=   list[i];
    } 

    //printf("排序前---->");
    //for(i=0;i<len;i++)
    //{
    //    printf("%d  ",list[i]);
    //}
    //printf("\n");
    //printf("1---------------------->\n");
    struct timeb tmb,tmb2;


    ftime(&tmb);
    printf("\n快速排序---->");
    quickSort(list,0,len-1);
    if(show == 1)
    {
        for(i=0;i<len;i++)
        {
            printf("%d  ",list[i]);
        }
    }
    printf("\n");
    ftime(&tmb2);
    printf("快速排序耗时：%ld (milliseconds)\n", (tmb2.time-tmb.time)*1000+(tmb2.millitm-tmb.millitm));    

    ftime(&tmb);
    printf("\n冒泡排序---->");
    bubbleSort(list,len);
    if(show == 1)
    {
        for(i=0;i<len;i++)
        {
            printf("%d  ",list[i]);
        }
    }
    printf("\n");
    ftime(&tmb2);
    printf("冒泡排序耗时：%ld (milliseconds)\n", (tmb2.time-tmb.time)*1000+(tmb2.millitm-tmb.millitm));    


    ftime(&tmb);
    printf("\n直接插入排序---->");
    straightInsertionSort(list,len);
    if(show == 1)
    {
        for(i=0;i<len;i++)
        {
            printf("%d  ",list[i]);
        }
    }
    printf("\n");
    ftime(&tmb2);
    printf("直接插入排序耗时：%ld (milliseconds)\n", (tmb2.time-tmb.time)*1000+(tmb2.millitm-tmb.millitm));    

    ftime(&tmb);
    printf("\n希尔排序---->");
    shellSort(list,len);
    if(show == 1)
    {
        for(i=0;i<len;i++)
        {
            printf("%d  ",list[i]);
        }
    }
    printf("\n");
    ftime(&tmb2);
    printf("希尔排序耗时：%ld (milliseconds)\n", (tmb2.time-tmb.time)*1000+(tmb2.millitm-tmb.millitm));    

    ftime(&tmb);
    printf("\n直接选择排序---->");
    straightSelectionSort(list,len);
    if(show == 1)
    {
        for(i=0;i<len;i++)
        {
            printf("%d  ",list[i]);
        }
    }
    printf("\n");
    ftime(&tmb2);
    printf("直接选择排序耗时：%ld (milliseconds)\n", (tmb2.time-tmb.time)*1000+(tmb2.millitm-tmb.millitm));    

    ftime(&tmb);
    printf("\n堆排序---->");
    heapSort(list,len);
    if(show == 1)
    {
        for(i=0;i<len;i++)
        {
            printf("%d  ",list[i]);
        }
    }
    printf("\n");
    ftime(&tmb2);
    printf("堆排序耗时：%ld (milliseconds)\n", (tmb2.time-tmb.time)*1000+(tmb2.millitm-tmb.millitm));    






}
