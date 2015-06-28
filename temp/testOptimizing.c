/*
testOptimizing.c
用来测试gcc的优化选项是否具有作用

author:guozheng
date:2015/06/27

*/

#include<stdio.h>
#include<time.h>
#include<sys/timeb.h>
#include<string.h>

void main(int argc, char* argv[])
{
    int i,sum;
    int temp = atoi(argv[1]); 
    struct timeb tmb,tmb2;
    ftime(&tmb);
    for(i=0;i<temp;i++)
    {
        sum=i;
        //sum+=i;
        //printf("%d",i);
    }
    printf("sum=%d\n",sum);
    ftime(&tmb2);
    printf("The loop used is %ld (milliseconds)\n", (tmb2.time-tmb.time)*1000+(tmb2.millitm-tmb.millitm));



}
