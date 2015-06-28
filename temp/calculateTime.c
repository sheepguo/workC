/*
用来测试在C程序中，IO操作的耗时和计算的耗时相比，是否会大很多。

*/

#include<stdio.h>
#include<time.h>
#include<sys/timeb.h>


void main(int argc, char* argv[])
{
    int i,sum;
    long start,end;
    //start   =   time(NULL);
    //clock_t t1,t2;
    //t1      =   clock();
    struct timeb tmb,tmb2;
    ftime(&tmb);

    for(i=0;i<1000000;i++)
    {
        sum+=i;
        //sum+=i;
        printf("%d",i);
    }
    
    //t2      =   clock();
    //end     =   time(NULL);
    //printf("tmb.time     = %ld (seconds)\n", tmb.time);
    //printf("tmb.millitm  = %d (mlliseconds)\n", tmb.millitm);
    //printf("\nThe loop used %f seconds.\n",difftime(end,start));
    //float   diff;
    //diff    =   (((float)t2 - (float)t1) / 1000000.0F ) * 1000;
    //printf("\nThe loop used %f seconds.\n",diff);
    
    ftime(&tmb2);
    //printf("tmb2.time     = %ld (seconds)\n", tmb2.time);
    //printf("tmb2.millitm  = %ld (mlliseconds)\n", tmb2.millitm);
    printf("\nThe loop used is %ld (milliseconds)\n", (tmb2.time-tmb.time)*1000+(tmb2.millitm-tmb.millitm));



}
