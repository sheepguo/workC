/*
shellSort.c
希尔排序

author:guozheng
date:2015/07/02
*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void shellSort(int* list, int len)
{
    /*
    伪代码：
    步骤一：先求增量序列，使用公式dlta[k]=2^(t-k+1)-1;
    步骤二：根据增量序列进行排序，如下
        k=0:t-1循环
            i=dlta[k]:len-1循环(这部分和简单插入排序的方式很相似）
                将list[i]放在已经排序过后的合适位置（按照增量序列进行跳跃）
            end
        end
    */

    //求增量序列
    int     k,t;
    //int*    dlta;

    t   =   (int)(log(len+1)/log(2));
    //dlta=   (int*) malloc(t*sizeof(int));
    int dlta[t];
    for(k=0;k<t;k++)
    {
        dlta[k] =   pow(2,t-k)-1;
    }

    //根据增量序列进行排序
    int i,j,temp;
    for(k=0;k<t;k++)    //t种增量序列
    {
        for(i=dlta[k];i<len;i++)   //从第k个数字开始检查，不断插入到前面已经排序好的位置中
        {
            temp    =   list[i];
            j       =   i-dlta[k];
            while(j>=0 && list[j]>temp)
            {
                list[j+dlta[k]] =   list[j];
                j               =   j - dlta[k];
            }
            list[j+dlta[k]] =   temp;
        }
    
    }
}

//void main(int argc, char* argv[])
//{
//    int     len,i;
//    int*    list;
//    printf("请输入数组长度：");
//    scanf("%d",&len);
//    printf("请输入数组：");
//    for(i=0;i<len;i++)
//    {
//        //printf("记录数据,i=%d\n",i);
//        scanf("%d",&list[i]);
//    }
//
//    printf("原始数组为---->");
//    for(i=0;i<len;i++)
//        printf("%d   ",list[i]);
//    printf("\n");
//
//    shellSort(list,len);
//
//    printf("排序后数组为---->");
//    for(i=0;i<len;i++)
//        printf("%d   ",list[i]);
//    printf("\n");
//}    
