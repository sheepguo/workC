/*
binarySearch.c:二分法查找，分别用迭代和递归的方法

author:guozheng
date:2015/07/15
*/

#include<stdio.h>

int binarySearch(int key, int* list, int len)
{
    /*
    伪代码:
    使用迭代的方法
    初始化start和end
    while(start<end)
        middle=start和end的一半
        如果list[middle]==key,返回middle
        根据list[middle]和key的对比，改变start或者end
    end
    return  -1;
    */
    
    int start,end,middle;
    start   =   0;
    end     =   len-1;
    while(start<=end)
    {
        middle  =   start/2+end/2;
        if(list[middle] == key) return middle;
        else if(list[middle] < key) start = middle+1;
        else    end = middle-1;
    }
    return  -1;
}

int binarySearchUsingRecursion(int key, int* list, int start, int end)
{
    /*
    伪代码：
    使用递归的方法
    递归结束依据：start<end
    middle  =   一半；
    if(middle处正好等于key) 返回middle；
    else if (list[middle]<key) return binarySearchUsingRecursion(key,list,middle+1,end)
    else if (list[middle]>key) return binarySearchUsingRecursion(key,list,start,middle-1)
    */
    if(start>end) return -1;
    int middle  =   start/2+end/2;
    if(list[middle]==key) return middle;
    else if(list[middle]<key) return binarySearchUsingRecursion(key,list,middle+1,end);
    else    return binarySearchUsingRecursion(key,list,start,middle-1);
}

int main(int argc, char* argv[])
{
    int list[5] =   {1,2,3,4,5}; 
    int key     =   6;
    printf("%d\n",binarySearch(key,list,5));
    printf("%d\n",binarySearchUsingRecursion(key,list,0,4));
    return 0;
}
