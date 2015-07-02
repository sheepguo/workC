/*
straightInsertionSort.c
直接插入排序

author:guozheng
date:2015/07/02
*/


void straightInsertionSort(int* list, int len)
{
    /*
    伪代码：
    i=1:len-1，循环
        将list[i]插入list[0]->list[i-1]中的合适位置
    end
    */

    int i,j,temp;
    for(i=1;i<len;i++)
    {
        temp    =   list[i];
        j       =   i-1;
        while(j>=0 && list[j] > temp)
        {
            list[j+1]   =   list[j];
            j--;
        }
        list[j+1] =   temp;
        //printf("i=%d",i);
        //for(j=0;j<=i;j++) printf("%d  ",list[j]); printf("\n");
    }

}


//void main(int argc, char* argv[])
//{
//    int     len,i;
//    int*    list;
//    printf("请输入数组长度：");
//    scanf("%d",&len);
//    printf("请输入数组：");
//    for(i=0;i<len;i++)
//    {
//        //printf("记录数据,i=%d\n",i);
//        scanf("%d",&list[i]);
//    }
//    
//    printf("原始数组为---->");
//    for(i=0;i<len;i++)
//        printf("%d   ",list[i]);
//    printf("\n");
//
//    straightInsertionSort(list,len);
//    
//    printf("排序后数组为---->");
//    for(i=0;i<len;i++)
//        printf("%d   ",list[i]);
//    printf("\n");
//}
