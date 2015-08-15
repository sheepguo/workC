/*
sequentialSearch.c：顺序查找；

author:guozheng
date:2015/07/15
*/

#include<stdio.h>

int sequentialSearch(int key, int* list, int len)
{
    /*
    伪代码：
    i=0:len-1循环
        如果list[i]==key,返回i;
        如果list[i]!=key,i++;
    end
    返回-1；
    */

    int i   =   0;
    while(i<len && list[i]!=key)
        i++;

    return i>=len?-1:i; //如果i>=len，就返回-1；否则返回i
}

int main(int argc, char* argv[])
{
    //int list[5] =   {1,2,3,4,5};
    //int key     =   4;
    //printf("%d\n",sequentialSearch(key,list,5));
     
    
    
    
    
    return  1;




}
