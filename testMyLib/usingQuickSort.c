/*
测试bubbleSort.c的文件

*/

#include<stdio.h>
#include<string.h>
#include"../myLib/lists/quickSort.h"
#include<sys/timeb.h>

void main(int argc, char* argv[])
{
    //int len     =   argc-1;
    //int list[len];
    //int i;
    //for(i=0;i<len;i++)
    //{
    //    list[i] =   atoi(argv[i+1]);
    //}

    //
    //printf("排序前---->");
    //for(i=0;i<len;i++)
    //{
    //    printf("%d  ",list[i]);
    //}
    //printf("\n排序后---->");

    ////int list[5] =   {2,3,4,1,2};
    //quickSort(list,0,len-1);
    //for(i=0;i<len;i++)
    //{
    //    printf("%d  ",list[i]);
    //}
    //printf("\n");

    //int len =   argc-1;
    int len =   atoi(argv[1]);
    int list[len];
    //printf("len=%d\n",len);
    int i;
    //把输入的数值赋给数组list
    //for(i=1;i<=len;i++)
    //{
    //    list[i-1] =   atoi(argv[i]);
    //}

    //根据设定的数组长度，创造随机数进行测试
    struct timeb tmb,tmb2;

    srand(time(NULL));
    for(i=0;i<len;i++)
    {
        list[i] =   rand()%len;
    }

    printf("排序前的数组---->");
    //for(i=0;i<len;i++)
    //{
    //    printf("%d  ",list[i]);
    //}
    printf("\n");

    ftime(&tmb);
    quickSort(list,0,len-1);
    ftime(&tmb2);
    printf("快速排序耗时：%ld (milliseconds)\n", (tmb2.time-tmb.time)*1000+(tmb2.millitm-tmb.millitm));

    printf("排序后的数组---->");
    //for(i=0;i<len;i++)
    //{
    //    printf("%d  ",list[i]);
    //}
    printf("\n");



}

