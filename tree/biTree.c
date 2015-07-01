/*
biTree.c
跟二叉树相关的一些操作

author:guozheng
date:2015/07/01
*/

#include<stdio.h>


typedef struct BiTNode{
    int             data;
    struct  BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

int createBiTree(BiTree* T)
{
    /*
    伪代码：
    使用递归；
    createBiTree(T) = 给T节点赋值 + createBiTree(T->lchild) + createBiTree(T->rchild)
    结束依据：输入的节点为逗号 
    */
    
    int ch;
    printf("请按照前序方式输入节点（空为,):");
    scanf("%d",&ch);
    //printf("ch=%d\n",ch);
    if(ch==0) *T   =   NULL;
    else
    {
        *T       =   (BiTree) malloc(sizeof(BiTNode));
        //printf("ch!=0,T=%p\n",*T);
        (*T)->data =   ch;   
        createBiTree(&((*T)->lchild));
        createBiTree(&((*T)->rchild));
    }
    
    //*T       =   (BiTree) malloc(sizeof(BiTNode));
    //printf("ch!=0,T=%p\n",*T);
    return 1;
}

//前序遍历，并输出各个节点
void preOrderTraverse(BiTree T)
{
    /*
    伪代码：
    使用递归方法
    preOrderTraverse(T) = print(T->data) + preOrderTraverse(T->lchild) + preOrderTraverse(T->rchild)
    结束依据：T==NULL
    */
    //printf("在preOrderTraverse函数中\n");
    if(T)
    {
        printf("%d  ",T->data);
        preOrderTraverse(T->lchild);
        preOrderTraverse(T->rchild);
    }
    else return;
}

//中序遍历，并输出各个节点
void inOrderTraverse(BiTree T)
{
    if(T)
    {
        inOrderTraverse(T->lchild);
        printf("%d  ",T->data);
        inOrderTraverse(T->rchild);
    }
    else return;
}


void main(int argc, char* argv[])
{
    BiTree T;
    createBiTree(&T);
    //printf("该二叉树的起始地址:%p\n",T);

    printf("\n按照前序方式输出该二叉树---->\n");
    preOrderTraverse(T);
    printf("\n");

    printf("\n按照中序方式输出该二叉树---->\n");
    inOrderTraverse(T);
    printf("\n");
}



