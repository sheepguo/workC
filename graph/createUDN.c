/*
createUDN.c
采用数组（邻接矩阵）表示法，构造无向图G（undigraph)，并且按照深度优先顺序进行输

author:guozheng
date:2015/07/07
*/

#include<stdio.h>

#define MAXVEX  100                     //最大顶点数，应由用户定义
#define INFINITY    65535               //用65535来代表无穷大
#define DEBUG

typedef struct
{
    char    vexs[MAXVEX];               //顶点表
    int     arc[MAXVEX][MAXVEX];        //邻接矩阵，可以看做边
    int     vexnum,arcnum;              //图的当前顶点数和弧数
}MGraph;

int visited[MAXVEX];                    //在遍历时，用来表示是否被访问过

//寻找在图G中，顶点中出现vex的位置
int locateVex(MGraph* G, char vex)
{
    int i=0;
    while(i<G->vexnum && G->vexs[i] != vex) i++;
    return  i;
}


int createUDN(MGraph* G)
{
    /*
    伪代码：
    先读取键盘输入的顶点数和边数；
    根据键盘输入的顶点字符，初始化数组vexs
    初始化arc数组；
    根据键盘输入的边（两个顶点+一个权值），给数组arc赋值
    */
    
    printf("请输入顶点数和边数：");
    scanf("%d %d",&(G->vexnum),&(G->arcnum));
    
    int i;
    char    temp;
    for(i=0;i<G->vexnum;i++)
    {
        printf("请输入顶点：");
        scanf("%c",&temp);
        scanf("%c",&(G->vexs[i]));
    }
    printf("顶点输入结束^_^\n");
    
    //初始化邻接矩阵，赋值为INFINITY
    int j;
    for(i=0;i<G->vexnum;i++)
        for(j=0;j<G->vexnum;j++)
            G->arc[i][j]    =   INFINITY;
    
    char    vex1,vex2;
    int     weight,k;
    scanf("%c",&temp);
    for(i=0;i<G->arcnum;i++)
    {
        printf("请输入边的两个顶点和权值：(都以空格隔开)");
        scanf("%c %c",&vex1,&vex2);
        scanf("%d",&weight);
        scanf("%c",&temp);
        printf("vex1=%c,vex2=%c,weight=%d,temp=%c\n",vex1,vex2,weight,temp);
        j   =   locateVex(G,vex1);
        k   =   locateVex(G,vex2);
        G->arc[j][k]    =   weight;
        G->arc[k][j]    =   weight;
    }
    return 0; 
}

void printMatrix(MGraph* G)
{
    int i,j;
    printf("邻接矩阵---->\n");
    for(i=0;i<G->vexnum;i++)
    {
        for(j=0;j<G->vexnum;j++)
        {
            printf("%8d",G->arc[i][j]);
        }
        printf("\n");
    }
}

void DFS(MGraph* G, int i)
{
    /*
    伪代码：
    实现递归
    当该节点被访问过时，结束递归
    递归的范围：对所有的存在连线的节点
    */
    
    if(visited[i]   ==  1)   return;
    visited[i]  =   1;
    printf("访问到%c\n",G->vexs[i]);
    int j;
    for(j=0;j<G->vexnum;j++)
    {   
        if(G->arc[i][j]!=INFINITY)  //如果该连线存在
            DFS(G,j);
    }

}

void DFSTraverse(MGraph* G)
{
    /*
    伪代码：
    采用递归方法
    先把全局变量visited初始化为全false
    因为该图不一定是连通的，所以不能只使用一个函数，而是得用两个函数
    DFS()作为递归函数，DFSTraverse()作为外部的调用函数
    遍历各个节点，如果没有被访问过，就调用DFS()
    */
    
    int i;
    printf("深度优先遍历--->\n");
    for(i=0;i<G->vexnum;i++)    visited[i]  =   0;
    for(i=0;i<G->vexnum;i++)
        if(!visited[i]) DFS(G,i);
}


int main()
{
    MGraph  *G;
    G   =   (MGraph*) malloc(sizeof(MGraph));
    createUDN(G);
    printMatrix(G);
    DFSTraverse(G);
    return  1;
}

