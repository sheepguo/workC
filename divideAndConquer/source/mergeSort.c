/*
mergeSort.c 归并排序

author:guozheng
date:2015/08/15
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void merge(int* array, int min, int mid, int max)
{
    int len =   max-min+1;
    int* array2 =   (int *)malloc(len*sizeof(int));
    int index   =   0;
    
    int point1=min;
    int point2=mid+1;
    
    while(point1<=mid && point2<=max)
    {
        if(array[point1]<array[point2]) //如果point1指向的数更小
        {
            array2[index]   =   array[point1];
            index++;
            point1++;
        }
        else
        {
            array2[index]   =   array[point2];
            index++;
            point2++;
        }
    }
    if(point2>max && point1<=mid)   //如果后半段已经拷贝完，且前半段没有，就把前半段的剩余部分复制到后半段的最后
    {
        while(point1<=mid)
        {
            array[max+point1-mid] =   array[point1];
            point1++;
        }
    }
    int i;
    for(i=0;i<index;i++)
    {
        array[min+i]=array2[i];
    }
    free(array2);
}



void mergeSort(int* array, int min, int max)
{
    if(min>=max) return;
    int mid;
    mid =   min+((max-min)>>1);
    mergeSort(array,min,mid);
    mergeSort(array,mid+1,max);
    merge(array,min,mid,max);
}

int main(int argc, char* argv[])
{
    int len =   atoi(argv[1]);
    int array[len],array2[len];
    srand(time(NULL));
    int i;
    for(i=0;i<len;i++)  {array[i]=rand()%10000; array2[i]=array[i];}

    printf("排序前的数组---->\n");
    for(i=0;i<len;i++) printf("%d  ",array[i]); printf("\n");

    mergeSort(array,0,len-1);
    printf("递归方法排序后的数组---->\n");
    for(i=0;i<len;i++) printf("%d  ",array[i]); printf("\n");

    //quickSort2(array2,len);
    //printf("循环方法排序后的数组---->\n");
    //for(i=0;i<len;i++) printf("%d  ",array2[i]); printf("\n");

    return 0;
}
