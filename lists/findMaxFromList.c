/*
findMaxFromList.c
从N个数中找出最大的m个

author:guozheng
date:2015/06/28
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/timeb.h>
#include"../myLib/lists/bubbleSort.h"

//n是list长度，m是要找出的数量
//先排序，再找出最大的m个。时间复杂度：n*lg(n)
void solution1(int* list, int n, int m)
{
    bubbleSort(list,n); //使用冒泡法排序
    int i;
    printf("使用方法一，得到的最大%d个数是--->",m);
    for(i=0;i<m;i++)
    {
        printf("%d  ",list[n-i-1]);
    }
    printf("\n");
}


//从数组list中找出最大的数值
//将list中最大的值搬移到最后的位置
int findMax(int* list, int len)
{
    int i,temp;
    for(i=0;i<len-1;i++)
    {
        if(list[i]>list[i+1])
        {
            temp        =   list[i];
            list[i]     =   list[i+1];
            list[i+1]   =   temp;
        }
    }
    return  list[len-1];
}


//方法二：先找出最大的那个，再找出次大的那个，依次进行。时间复杂度：n*m
void solution2(int* list, int n, int m)
{
    int i;
    printf("\n使用方法二，得到的最大%d个数是--->",m);
    for(i=0;i<m;i++)
    {
        printf("%d  ",findMax(list,n-i));
    }
    printf("\n");
}

//方法三：找一个临时的长度为m的数组，用来保存临时的最大m个数
void solution3(int* list, int n, int m)
{
    int tempM[m];
    int i,j;
    for(i=0;i<m;i++)
    {
        tempM[i]    =   list[i];    //把list的前m个数值保存到tempM中
    }
    
    bubbleSort(tempM,m);            //把tempM进行升序排序

    for(i=m;i<n;i++)    //从list的第m+1个开始遍历到结束，如果比tempM中最小的大，则放入tempM中合适的位置
    {
        if(list[i]>tempM[0])   //如果list[i]大于tempM的最小值
        {
            for(j=2;j<=m;j++)   //从tempM的第2个开始遍历，如果list[i]小于等于tempM[j-1]，就用list[i]填充tempM[j-2]，并结束循环;如果list[i]大于tempM[j-1]，先把tempM[j-1]已到tempM[j-2],并接着往下比较；
            {
                if(list[i]<=tempM[j-1])
                {
                    tempM[j-2]  =   list[i];
                    break;
                }
                else
                {
                    tempM[j-2]  =   tempM[j-1];
                }
            }
            if(j==m+1) tempM[m-1]   =   list[i];    //如果list[i]比tempM中所有的数都大，则在该循环外部将list[i]赋给tempM[m-1]
        }
    }
   
    printf("\n使用方法三，得到的最大%d个数是--->",m);
    for(i=m-1;i>=0;i--)
    {
        printf("%d  ",tempM[i]);
    }
    printf("\n");
}

//void main(int argc, char* argv[])
//{
//    //调用的格式为./findMaxFormList 2 2 3 4 53 1 ，其中第一个2代表m，后面的数字代表数组
//    int len     =   argc-2;
//    int list[len],list1[len],list2[len],list3[len];
//    int i;
//    int m=atoi(argv[1]);
//    for(i=0;i<len;i++)
//    {
//        list[i] =   atoi(argv[i+2]);
//        list1[i]=   atoi(argv[i+2]);
//        list2[i]=   atoi(argv[i+2]);
//        list3[i]=   atoi(argv[i+2]);
//    }
//    
//    solution1(list1,len,m);
//    solution2(list2,len,m);
//    solution3(list3,len,m);
//
//}



void main(int argc, char* argv[])
{
    //调用的格式为./findMaxFormList 2 100，其中第一个2表示m，第二个数字100代表数组长度，使用随机的方式进行生成
    int m       =   atoi(argv[1]);
    int len     =   atoi(argv[2]);
    int list[len],list1[len],list2[len],list3[len];
    int i;
    srand(time(NULL));
    for(i=0;i<len;i++)
    {
        list[i] =   rand()%len;        
        list1[i]=   list[i];
        list2[i]=   list[i];
        list3[i]=   list[i];
    }
    
    //printf("原始数组---->");
    //for(i=0;i<len;i++)
    //{
    //    printf("%d  ",list[i]);
    //}
    //printf("\n");
    struct timeb tmb,tmb2;
    ftime(&tmb);
    solution1(list1,len,m);
    ftime(&tmb2);
    printf("\n方法一耗时：%ld (milliseconds)\n", (tmb2.time-tmb.time)*1000+(tmb2.millitm-tmb.millitm));
    
    ftime(&tmb);
    solution2(list2,len,m);
    ftime(&tmb2);
    printf("\n方法二耗时：%ld (milliseconds)\n", (tmb2.time-tmb.time)*1000+(tmb2.millitm-tmb.millitm));
    
    ftime(&tmb);
    solution3(list3,len,m);
    ftime(&tmb2);
    printf("\n方法三耗时：%ld (milliseconds)\n", (tmb2.time-tmb.time)*1000+(tmb2.millitm-tmb.millitm));

}

