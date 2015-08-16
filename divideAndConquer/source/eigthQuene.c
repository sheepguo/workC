/*
八皇后问题，使用三种方法
1、回溯法，solve();
2、分治思想，用递归实现，solve2();
3、分治思想，用循环实现，solve3();

*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//检查由于第index个的皇后的引入，是否会导致冲突
int check(int* cheese, int index, int n)
{
    if(index==-1) return 1;
    int i;
    for(i=0;i<index;i++)
    {
        if(cheese[i]==cheese[index])    return 0;
    }
    if(abs(cheese[index]-cheese[index-1])==1) return 0;
    return 1;
}


void add(int* cheese, int index)
{
    cheese[index]   =   1;
    return;
}

//由于出错，修改第index个皇后的位置
int change(int* cheese, int index, int n)
{
    if(cheese[index] == n) return 0;    //已经最大了，不能再更改
    else    cheese[index]++;
    return  1;
}

int solve(int n)
{
    int cheese[n];
    int i;
    for(i=0;i<n;i++) cheese[i]=-1;
    
    int index=-1;
    while(index<n)
    {
        if(check(cheese,index,n))
        {
            index++;
            if(index<n) add(cheese,index);
        }
        else
        {
            while(!change(cheese,index,n))
            {
                index--;
                if(index==-1) return 0;
            }
        }
    }
    for(i=0;i<n;i++) printf("%d  ",cheese[i]); printf("\n");
    return  1;
}

typedef struct node
{
    int data;
    struct node *next;
}node;

void insertAtStart(node* start, int n)
{
    node* p =   (node*)malloc(sizeof(node));
    p->data =   n;
    p->next =   start->next;
    start->next =   p;
}

void insertAtEnd(node* end, int n)
{
    node* p =   (node*)malloc(sizeof(node));
    p->next =   NULL;
    p->data =   n;
    end->next->next =   p;
    end->next   =   p;
}

void recursion(int n, node* start, node* end)
{
    if(n<=4) return;
    recursion(n-1,start,end);
    if(start->next->data!=n-1) insertAtStart(start,n);
    else    insertAtEnd(end,n);
}

void traverse(node* start)
{
    node* p =   start->next;
    while(p != NULL)
    {
        printf("%d  ",p->data);
        p   =   p->next;
    }
    printf("\n");
}

int solve3(int n)
{
    if(n<4) return  0;
    
    //初始化链表
    node* start =   (node*)malloc(sizeof(node));
    start->next =   NULL;
    node* end   =   (node*)malloc(sizeof(node));
    end->next   =   NULL;
    node* p     =   (node*)malloc(sizeof(node));
    p->data     =   3;
    p->next     =   start->next;
    start->next =   p;
    end->next   =   p;
    insertAtStart(start,1);
    insertAtStart(start,4);
    insertAtStart(start,2);

    int i;
    for(i=5;i<=n;i++)
    {
        if(start->next->data!=i-1) insertAtStart(start,i);
        else    insertAtEnd(end,i);
    }
    traverse(start);
    return  1;

}

int solve2(int n)
{
    if(n<4) return  0;
    
    //初始化链表
    node* start =   (node*)malloc(sizeof(node));
    start->next =   NULL;
    node* end   =   (node*)malloc(sizeof(node));
    end->next   =   NULL;
    node* p     =   (node*)malloc(sizeof(node));
    p->data     =   3;
    p->next     =   start->next;
    start->next =   p;
    end->next   =   p;
    insertAtStart(start,1);
    insertAtStart(start,4);
    insertAtStart(start,2);
    

    recursion(n,start,end); 
    
    traverse(start);
    return  1;
}

int main(int argc, char* argv[])
{
    int number  =   atoi(argv[1]);
    if(solve(number)==0) printf("number=%d时，无法解决八皇后问题\n",number);
    if(solve2(number)==0) printf("number=%d时，无法解决八皇后问题\n",number);
    if(solve3(number)==0) printf("number=%d时，无法解决八皇后问题\n",number);
    return  0;
}
