/*
测试log运算和指数计算

*/

#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main(int argc, char* argv[])
{
    int a   =   atoi(argv[1]);
    printf("ln(%d)=%f\n",a,log(a));
    int result  =   log(a);
    printf("ln(%d)=%d\n",a,result);



}


