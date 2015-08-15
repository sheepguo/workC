/*
secondOptimalSearch.c：近似最优查找树

author:guozheng
date:2015/07/15
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct node
{
    int data;
    int weight;
}node;  //包含数值和权重的数据结构node

typedef struct BiTNode
{
    int     number;
    node    value;
    struct BiTNode *lchild,*rchild;       
}BiTNode;   //二叉树的数据结构


int secondOptimalSearch()
{
    return 0;
}

//查找数组中合适的根节点
int findRoot(node* list, int start, int end)
{
    /*
    伪代码：
    len =   end-start+1
    生成累计表sum[len];
    least   =    sum[len-1]-sum[0];
    root    =   0;
    i=1:len-1循环
        temp=abs(sum[len-1]-sum[i]-sum[i-1])
        if(temp<least){root=i;least=temp;}
    end
    return root;
    */

    int len =   end-start+1;
    int sum[len];
    int i;

    //初始化累计表sum[len]
    sum[0]  =   list[start].weight;
    for(i=1;i<len;i++)
    {
        sum[i]=sum[i-1]+list[start+i].weight;
    }

    int least   =   sum[len-1]-sum[0];
    int root    =   0;
    int temp;
    for(i=0;i<len;i++)
    {
        temp=abs(sum[len-1]-sum[i]-sum[i-1]);   
        if(temp<least){root=i;least=temp;}
    }
    
    return  root;
}


//根据数组list，生成近似最有查找树T
void createSOSTree(BiTNode **T, node* list, int start, int end)
{
    /*
    伪代码：
    使用递归
    结束条件：start>end
    root=findRoot(list,start,end)
    *T=malloc();
    T->value=list[root];
    T->number=root;
    createSOSTree(T->lchild,list,start,root-1);
    createSOSTree(T->rchild,list,root+1,end);
    */

    if(start>end) return;
    int root    =   findRoot(list,start,end);
    *T          =   (BiTNode*) malloc(sizeof(BiTNode));
    (*T)->value =   list[root];
    (*T)->number=   root;
    createSOSTree(&((*T)->lchild),list,start,root-1);
    createSOSTree(&((*T)->rchild),list,root+1,end);
}

int main()
{
    node list[9];
    int i;
    for(i=0;i<9;i++)
    {
        list[i].data    =   i;
    }
    list[0].weight  =   1;
    list[1].weight  =   1;
    list[2].weight  =   2;
    list[3].weight  =   5;
    list[4].weight  =   3;
    list[5].weight  =   4;
    list[6].weight  =   4;
    list[7].weight  =   3;
    list[8].weight  =   5;

    BiTNode *T;
    createSOSTree(&T,list,0,8);


    return  0;
}
