/*
initialChainTable.c
创建单向链表并输出以及单链表相关的基本操作

基本操作有：
1、创建；
2、定位；
3、遍历；
4、插入；
5、删除；

author:guozheng
date:2015/06/29
*/

#include<stdio.h>
#include<string.h>

typedef int ElemType;

typedef struct LNode{
    ElemType        data;
    struct  LNode   *next;
}LNode, *LinkList;
//构造单链表的结构体，包含数据位和下一个节点指针
//LNode即struct LNode,LinkList即struct LNode*


//根据指定长度从尾部开始创建单向链表，其中的数据分别是1,2,3,...,len
LinkList createChainTable(int len)
{
    //创建方法：构造一个适用于单向链表的数据结构；
    //根据链表的长度，不断分配需要的空间，并赋值
    /*
    伪代码：
    L=指向LNode的指针，并且L->next=null;
    i=len->1循环
        新建LNode空间，并赋值，该空间的地址为temp;
        将temp接在该链表的第一个；
    结束循环
    */
    LinkList    L,temp;     //指向链表头的指针和临时创建的LNode指针
    L       =   (LinkList) malloc(sizeof(LNode));
    L->next =   NULL;
    int i;
    for(i=len;i>0;i--)
    {
        temp        =   (LinkList) malloc(sizeof(LNode));
        temp->data  =   i;
        temp->next  =   L->next;
        L->next     =   temp;
    }
    return  L;
}

//遍历输出单链表
void    traverse(LinkList L)
{
    /*
    伪代码：
    temp=L
    当temp->next不等于null时，循环
        temp    =   temp->next;
        输出temp->data;
    结束循环
    */
    
    LinkList    temp    =   L;
    printf("用单链表表示的线性表---->");
    while(temp->next != NULL)
    {
        temp    =   temp->next;
        printf("%d  ",temp->data);
    }
    printf("\n");
}

//取出位置为pos的元素，返回LNode，输出该data
LinkList    getElem(LinkList L, int len, int pos)
{
    /*
    伪代码：
    判断删除位置是否超过链表长度
    temp=L
    i=1:pos,循环
        temp=temp->next;
    结束循环
    输出temp->data;
    返回temp;
    */

    if(pos>len) {printf("error:pos>len\n"); return NULL;}
    LinkList    temp    =   L;
    int i;
    for(i=1;i<=pos;i++)
    {
        temp    =   temp->next;
    }
    printf("第%d个元素是：%d\n",pos,temp->data);
    return temp;
}

//在指定的位置，插入指定的数值
void insert(LinkList L, int len, int pos, int num)
{
    /*
    伪代码：
    判断插入位置是否超过链表长度
    先利用getElem函数找到要插入的位置temp
    创建新的LNode节点new
    new->next=temp->next
    temp->next=new
    */

    if(pos>len) {printf("error:pos>len\n"); return ;}
    
    LinkList    temp,new;
    temp        =   getElem(L,len,pos);
    
    new         =   (LinkList) malloc(sizeof(LNode));
    new->data   =   num;
    
    new->next   =   temp->next;
    temp->next  =   new;
}

//删除操作
void delete(LinkList L, int len, int pos)
{
    /*
    伪代码：
    判断删除位置是否超过链表长度
    找到位置为pos-1的LNode节点，为temp
    temp->next=temp->next->next;
    */

    if(pos>len) {printf("error:pos>len\n"); return ;}

    LinkList temp;
    temp        =   getElem(L,len,pos-1);
    
    temp->next  =   temp->next->next;
}

void    main(int argc, char* argv[])
{
    int len;
    //len =   atoi(argv[1]);
    printf("请输入线性表长度：");
    scanf("%d",&len);

    //创建长度为L的单链表
    LinkList    L;
    L   =   createChainTable(len);

    //遍历并输出
    traverse(L);
    printf("\n");

    //取出某个指定位置的元素
    int pos;
    printf("现在取出一个元素，请输入该元素的位置：");
    scanf("%d",&pos);
    LinkList    temp;
    temp    =   getElem(L,len,pos);
    printf("\n");

    //在指定位置插入某个数值
    int num;
    printf("现在需要插入一个数值，请输入插入的位置：");
    scanf("%d",&pos);
    printf("请输入插入的数值：");
    scanf("%d",&num);
    insert(L,len,pos,num);
    traverse(L);
    printf("\n");

    //删除指定位置
    printf("现在需要删除一个数值，请输入删除的位置：");
    scanf("%d",&pos);
    delete(L,len,pos);
    traverse(L);
    printf("\n");
}




