/*
factorial.c
递归法和非递归法计算阶乘
并比较两种方法的耗时
发现递归法的耗时大约为非递归的两倍

author:guozheng
date:2015/06/30
*/

#include<stdio.h>
#include<sys/timeb.h>

long factorial(long n)
{
    /*
    伪代码：
    当n>1时
        return n*factorial(n-1)
    else return 1;
    */
    if(n<0) {printf("n不能小于0\n"); return -1;}
    if(n>1) return n*factorial(n-1);
    else    return 1;
}


//不使用递归的方法求阶乘
long factorial2(int n)
{
    /*
    伪代码：
    i=1:n，循环
        result = result * i
    end
    */
    long i;
    long result;
    result  =   1;
    for(i=1;i<=n;i++)
        result*=i;
    return  result;
}

void main(int argc, char* argv[])
{
    int n;
    int times,i;
    int result;
    printf("请输入n：");
    scanf("%d",&n);
    printf("请输入重复次数：");
    scanf("%d",&times);

    struct timeb tmb,tmb2;
   
    ftime(&tmb);
    for(i=0;i<times;i++) result=factorial(n);
    printf("\n递归方法，%d的阶乘等于%d\n",n,result);
    ftime(&tmb2);
    printf("递归方法耗时：%d (milliseconds)\n\n", (tmb2.time-tmb.time)*1000+(tmb2.millitm-tmb.millitm));   

    ftime(&tmb);
    for(i=0;i<times;i++) result=factorial2(n);
    printf("非递归方法，%d的阶乘等于%d\n",n,result);
    ftime(&tmb2);
    printf("递归方法耗时：%d (milliseconds)\n", (tmb2.time-tmb.time)*1000+(tmb2.millitm-tmb.millitm));   

}


