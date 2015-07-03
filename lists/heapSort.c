/*
heapSort.c
堆排序（递增）

author:guozheng
date:2015/07/02
*/

//调整堆，使得堆顶最大。形参中s为调整堆的起始位置，m为结束位置
void heapAdjust(int* list, int s, int m)
{
    /*
    伪代码：
    temp=list[s];
    i=2*s+1;
    从上至下遍历该堆，直到该节点比孩子都大
    while(i<=m)
        选出相对大的孩子节点
        如果双亲更大，就break;
        否则，list[s]=list[i],s=i;i=2*s+1;
    end
    list[s]=temp
    */
    
    int temp,i;
    temp    =   list[s];
    i       =   2*s+1;
    
    while(i<=m)
    {
        if(i<m && list[i]<list[i+1]) i=i+1; //选出更大的孩子节点
        if(temp>list[i]) break;
        list[s] =   list[i];
        s       =   i;
        i       =   2*s+1;
    }
    list[s]     =   temp;
}



void heapSort(int* list, int len)
{
    /*
    伪代码：
    步骤一：创建堆
    i=len/2-1:0循环
        heapAdjust(list,i,len-1) 调节从i到len-1的堆，具体介绍见该函数
    end

    步骤二：不断更换堆顶，并调整堆，逐渐把最大的数都移到尾部
    i=len-1:1循环
        list[0]<-->list[i]
        heapAdjust(list,0,i-1)
    end
    */

    int i,temp;
    for(i=len/2-1;i>=0;i--)
    {
        heapAdjust(list,i,len-1);
    }
    for(i=len-1;i>=1;i--)
    {
        temp    =   list[0];
        list[0] =   list[i];
        list[i] =   temp;
        heapAdjust(list,0,i-1);
    }

}

void main(int argc, char* argv[])
{
    int     len,i;
    int*    list;
    printf("请输入数组长度：");
    scanf("%d",&len);
    list    =   (int*) malloc(len*sizeof(int));
    printf("请输入数组：");
    for(i=0;i<len;i++)
    {
        //printf("记录数据,i=%d\n",i);
        scanf("%d",&list[i]);
    }

    printf("原始数组为---->");
    for(i=0;i<len;i++)
        printf("%d   ",list[i]);
    printf("\n");

    heapSort(list,len);

    printf("排序后数组为---->");
    for(i=0;i<len;i++)
        printf("%d   ",list[i]);
    printf("\n");
}




