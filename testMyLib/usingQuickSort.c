/*
测试bubbleSort.c的文件

*/

#include<stdio.h>
#include<string.h>
#include"../myLib/lists/quickSort.h"

void main(int argc, char* argv[])
{
    int len     =   argc-1;
    int list[len];
    int i;
    for(i=0;i<len;i++)
    {
        list[i] =   atoi(argv[i+1]);
    }

    
    printf("排序前---->");
    for(i=0;i<len;i++)
    {
        printf("%d  ",list[i]);
    }
    printf("\n排序后---->");

    //int list[5] =   {2,3,4,1,2};
    quickSort(list,0,len-1);
    for(i=0;i<len;i++)
    {
        printf("%d  ",list[i]);
    }
    printf("\n");
}

