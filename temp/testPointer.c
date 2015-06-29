/*
测试在调用函数中，改变形参值，并进行返回
*/

#include<stdio.h>

void change(int* i)
{
    *i  +=  1;
}

void change2(int* i)
{
    (*i)++;
}

void main()
{
    int i=0;
   
   change(&i);
    printf("i=%d\n",i);
    
    change2(&i);
    printf("i=%d\n",i);
}
