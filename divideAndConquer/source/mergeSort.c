/*
mergeSort.c 归并排序
使用分治的思想，通过递归和循环两种方法实现

author:guozheng
date:2015/08/15
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void merge(int* array, int min, int mid, int max)
{
    int i;
    //printf("进入merge-->");
    //for(i=0;i<5;i++) printf("%d  ",array[i]); printf("\n");
    //printf("min=%d, mid=%d, max=%d\n",min,mid,max);
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
    //printf("point1=%d, point2=%d\n",point1,point2);
    //for(i=0;i<5;i++) printf("%d  ",array[i]); printf("\n");

    if(point2>max && point1<=mid)   //如果后半段已经拷贝完，且前半段没有，就把前半段的剩余部分复制到后半段的最后
    {
        int point=mid;
        while(point>=point1)
        {
            array[max+point-mid] =   array[point];
            point--;
        }
    }
    for(i=0;i<index;i++)
    {
        array[min+i]=array2[i];
    }
    //printf("退出merge-->");
    //for(i=0;i<5;i++) printf("%d  ",array[i]); printf("\n");
    free(array2);
}


//递归的方法
void mergeSort(int* array, int min, int max)
{
    if(min>=max) return;
    int mid;
    mid =   min+((max-min)>>1);
    mergeSort(array,min,mid);
    mergeSort(array,mid+1,max);
    merge(array,min,mid,max);
}

//非递归的方法，循环
void mergeSort2(int* array, int len)
{
    int i,min;
    for(i=2;i<2*len;i*=2)
    {
        for(min=0;min+i/2<=len-1;min+=i)
        {
            if(min+i-1<=len-1) merge(array,min,min+i/2-1,min+i-1);
            else    merge(array,min,min+i/2-1,len-1);
        }
    }
}

int main(int argc, char* argv[])
{
    int len =   atoi(argv[1]);
    int array[len],array2[len];
    srand(time(NULL));
    int i;
    for(i=0;i<len;i++)  {array[i]=rand()%10000; array2[i]=array[i];}

    printf("array排序前的数组---->\n");
    for(i=0;i<len;i++) printf("%d  ",array[i]); printf("\n");

    //printf("array2排序前的数组---->\n");
    //for(i=0;i<len;i++) printf("%d  ",array2[i]); printf("\n");
    
    mergeSort(array,0,len-1);
    printf("递归方法排序后的数组---->\n");
    for(i=0;i<len;i++) printf("%d  ",array[i]); printf("\n");

    mergeSort2(array2,len);
    printf("循环方法排序后的数组---->\n");
    for(i=0;i<len;i++) printf("%d  ",array2[i]); printf("\n");

    return 0;
}
