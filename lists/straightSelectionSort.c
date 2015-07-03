/*
straightSelectionSort.c
直接选择排序

author:guozheng
date:2015/07/02
*/

#define INT_MAX 2147483647

int selectMin(int* list, int len, int pos)
{
    int i;
    int temp=INT_MAX;
    int minPos=0;
    for(i=pos;i<len;i++)
    {
        if(list[i]<temp) {temp = list[i]; minPos=i;}
    }
    return minPos;
}


void straightSelectionSort(int* list, int len)
{
    /*
    伪代码：
    i=0:len-1循环
        选出&list[i]数组中最小的值，记其位置为j
        if(i!=j) 交换list[i]和list[j]
    end
    */

    int i,j,temp;
    for(i=0;i<len;i++)
    {
        j   =   selectMin(list,len,i);
        if(i!=j)
        {
            temp    =   list[i];
            list[i] =   list[j];
            list[j] =   temp;
        }
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

    straightSelectionSort(list,len);

    printf("排序后数组为---->");
    for(i=0;i<len;i++)
        printf("%d   ",list[i]);
    printf("\n");
}















