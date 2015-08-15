/*
quickSort.c 快速排序 

使用分治的思想，并分别用递归和循环两种方法实现

author:guozheng
date:2015/08/15
*/

#include<stdio.h>
#include<string.h>
#include<sys/timeb.h>
#include<stdlib.h>

#define capacity    1000
//int capacity    =   100;

typedef struct Stack
{
    int data[capacity];
    int length;
}Stack;

//Stack* iniStack()
//{
//    Stack   stack;
//    stack.length    =   0;
//    return  &stack;
//}

int push(Stack* stack, int a)
{
    if(stack->length==capacity) return 0; //如果栈
    stack->data[stack->length]  =  a;
    stack->length++;
    return  1;
}

int pop(Stack* stack)
{
    stack->length--;
    return stack->data[stack->length];
}

int isEmpty(Stack* stack)
{
    if(stack->length==0) return 1;
    else    return 0;
}


void swap(int* array, int a, int b)
{
    int temp;
    temp    =   array[a];
    array[a]=   array[b];
    array[b]=   temp;
}

int adjust(int* array, int min, int max)
{
    int pivot   =   min;
    int data    =   array[min];
    int point   =   min+1;
    
    for(;point<=max;point++)
    {
        if(array[point]<data)
        {
            pivot++;
            swap(array,pivot,point);
        }   
    }
    swap(array,pivot,min);
    return  pivot;
}

//使用递归
void quickSort(int* array, int min, int max)
{
    if(min>=max) return;
    int mid =   adjust(array, min, max);
    quickSort(array,min,mid-1);
    quickSort(array,mid+1,max);
}


//使用循环实现该分治
void quickSort2(int* array, int len)
{
    //Stack* stack =   iniStack();
    Stack* stack    =   (Stack *) malloc(sizeof(Stack));
    stack->length   =   0;
    //stack->data     =   (int *）malloc(capacity*sizeof(int));
    push(stack,0);
    push(stack,len-1);
    int max,min,mid;
    while(!isEmpty(stack))
    {
        max =   pop(stack);
        min =   pop(stack);
        mid =   adjust(array,min,max);
        if(mid-1>min)
        {
            push(stack,min);
            push(stack,mid-1);
        }
        if(mid+1<max)
        {
            push(stack,mid+1);
            push(stack,max);
        }
    }
    free(stack); 
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

    quickSort(array,0,len-1);
    printf("递归方法排序后的数组---->\n");
    for(i=0;i<len;i++) printf("%d  ",array[i]); printf("\n");

    quickSort2(array2,len);
    printf("循环方法排序后的数组---->\n");
    for(i=0;i<len;i++) printf("%d  ",array2[i]); printf("\n");

    return 0;
}
