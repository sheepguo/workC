/*
huffmanCoding.c
进行哈弗曼编码

author:guozheng
date:2015/07/01
*/

#include<stdio.h>
#include<string.h>

//定义结构体，用来表示哈弗曼表中的每一行的数据结构
typedef struct HTNode{
    int weight;
    int parent,lchild,rchild;
}HTNode;

//寻找第parent行以上行中，最小的两个权重值，s1和s2分别是两个权重值相应的行数
void select(HTNode* HT, int parent, int* s1, int* s2)
{
    /*
    先找一个最小的值，赋给s1
    再找一个次小的值，赋给s2
    */
    int i,temp1,temp2;
    temp1    =   0; 
    for(i=0;i<parent;i++)
    {
        if(HT[i].parent == -1 && ((temp1 == 0) || (HT[i].weight < temp1)))  {temp1 = HT[i].weight;  temp2 = i;}
    }
    *s1 =   temp2;
   
    temp1   =   0;
    for(i=0;i<parent;i++)
    {
        if(i != *s1 && HT[i].parent == -1 && ((temp1 == 0) || (HT[i].weight < temp1)))  {temp1 = HT[i].weight;  temp2 = i;}
    }
    *s2 =   temp2;
}


void huffmanCoding(HTNode** HT, char** HC, int* weight, int n)
{
    //HT表示哈弗曼表格，HC表示哈弗曼编码值，weight是表示权重的数组，n是字符的数量
    
    /*
    伪代码：
    阶段一： 形成哈弗曼表
    定义结构体HTNode;
    m=2*n-1;
    初始化表；
    i=n:m-1循环
        寻找表格中从0->i-1行中，最小的两个权重；
        进行双亲和孩子的设定
    end
    
    阶段二的介绍在下面
    */
    
    int m,i;
    m   =   2*n-1;
   
    //初始化哈弗曼表格
    *HT  =  (HTNode*) malloc(m*sizeof(HTNode)); //分配m行哈弗曼表格的空间
    for(i=0;i<n;i++)
    {
        (*HT)[i].weight =   weight[i];
        (*HT)[i].parent =   -1; //-1表示不存在双亲和孩子节点
        (*HT)[i].lchild =   -1;
        (*HT)[i].rchild =   -1;
    }
    for(i=n;i<m;i++)
    {
        (*HT)[i].weight =   0;
        (*HT)[i].parent =   -1; //-1表示不存在双亲和孩子节点
        (*HT)[i].lchild =   -1;
        (*HT)[i].rchild =   -1;
    }

    int s1,s2;
    for(i=n;i<m;i++)
    {
        select(*HT,i,&s1,&s2);
        (*HT)[i].weight =   (*HT)[s1].weight+(*HT)[s2].weight;
        (*HT)[s1].parent=   i;
        (*HT)[s2].parent=   i;
        (*HT)[i].lchild =   s1;
        (*HT)[i].rchild =   s2;
    }

    //输出哈弗曼表
    printf("生成的哈弗曼表如下：\n");
    for(i=0;i<m;i++)
    {
        printf("%4d    %4d    %4d    %4d    %4d\n",i,(*HT)[i].weight,(*HT)[i].parent,(*HT)[i].lchild,(*HT)[i].rchild);
    }


    /*
    阶段二：从叶子节点开始向上追溯
    初始化字符串数组
    对每一个编码字符进行循环
        搜索到根节点
        判断属于左孩子还是右孩子，并相应赋值
    end
    */
    
    HC          =   (char**) malloc(n*sizeof(char*));
    char*   cd  =   (char*) malloc(n*sizeof(char));    
    cd[n-1]     =   '\0';
    

    int j,start,temp;
    for(i=0;i<n;i++)
    {
        start   =   n-1;
        j       =   i;
        temp    =   (*HT)[j].parent;
        while(temp!=-1) //当temp不是头结点时，不断循环
        {
            if((*HT)[temp].lchild == j) cd[--start] =   '0';    //如果是双亲的左孩子，就为1；反之为0
            else    cd[--start] =   '1';
            j       =   temp;
            temp    =   (*HT)[j].parent;
        }
        HC[i]   =   (char*) malloc((n-start)*sizeof(char)); //所需空间时n-start
        strcpy(HC[i],&cd[start]);
    }

    printf("哈夫曼编码如下：\n");
    for(i=0;i<n;i++)
    {
        printf("%s\n",HC[i]);
    }
    
}

void main()
{
    HTNode* HT;
    char*   HC;
    int     weight[]    =   {5,29,7,8,14,23,3,11};
    int     n           =   8;
    huffmanCoding(&HT,&HC,weight,n);
}
