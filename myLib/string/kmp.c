/*
kmp.c
字符串模式匹配的KMP算法实现，分为两个函数，一是求模式串的next数组，二是利用next数组进行匹配

author:guozheng
2015/06/05
*/

#include "kmp.h"
#include <stdio.h>
#include <stdlib.h>

int* nextFunction(char* patternString)
{

    int length  =   0;
    while(*(patternString+length) != '\0') length++;    //求模式字符串的长度

    int* next   =   (int*) malloc((length+1)*sizeof(int));        //动态分配数组空间
    
    next[1]     =   0;
    int i       =   2;
    int k;
    for(i=2;i<=length;i++)
    {
        k   =   i-1;
        k   =   next[k];
        while(k!=0)
        {
            //printf("i=%d,k=%d,pattern[k-1]=%c,pattern[i-2]=%c\n",i,k,patternString[k-1],patternString[i-2]);
            if(patternString[k-1] == patternString[i-2])
            {
                //printf("patternString[k-1] == patternString[i-1]\n");
                next[i] =   k+1;
                break;
            }
            else
            {
                //printf("patternString[k-1] != patternString[i-1]\n");
                k   =   next[k];
            }
        }
        if(k == 0) next[i] = 1;
    }
    
    for(i=2;i<=length;i++)  //考虑例如aaaab的特殊情况
    {
        k   =   next[i];
        if(patternString[i-1] == patternString[k-1]) next[i] = next[k];
    }
    
    return next;

}


int match(char* mainString, char* patternString, int startPosition, int endPosition)
{
    
    int lenOfMainStr    =   0;
    while(*(mainString+lenOfMainStr) != '\0') lenOfMainStr++;   //主串长度
    int lenOfPatternStr =   0;
    while(*(patternString+lenOfPatternStr) != '\0') lenOfPatternStr++;   //模式串长度
   
    
    int* next   =   (int*) malloc((lenOfPatternStr+1)*sizeof(int));        //动态分配数组空间
    next        =   nextFunction(patternString);
   
    //printf("startPosition=%d, endPosition=%d, lenOfMainStr=%d, lenOfPatternStr=%d\n",startPosition,endPosition,lenOfMainStr,lenOfPatternStr); 

    if(startPosition < 0 || endPosition < 0 || startPosition >= lenOfMainStr || endPosition >= lenOfMainStr) return -2; //表示起始搜索位和结束搜索位不符合要求


    int i   =   startPosition;
    int j   =   0;
    int k   =   0;

    while(i<=endPosition && j<lenOfPatternStr)
    {
        //printf("while的开头--->i=%d,j=%d,mainString[i]=%c,patternString[j]=%c\n",i,j,mainString[i],patternString[j]);
        if(mainString[i] == patternString[j])   //如果该字节匹配成功，就把两个游标都往后移动一位
        {
            i++;
            j++;
        }
        else    //如果该字节不相同
        {
            if(next[j+1] == 0)
            {
                i++;
                j=0;
            }
            else
            {
                j = next[j+1] - 1;
            }
        }
        //printf("while的尾巴--->i=%d,j=%d,mainString[i]=%c,patternString[j]=%c\n",i,j,mainString[i],patternString[j]);
    }
    //printf("while结束了，i=%d,j=%d\n",i,j);
    if(j == lenOfPatternStr)
    {
        return  i-lenOfPatternStr;
    }
    else 
        return  -1; //表示没有匹配的对象

}


//void main(int argc, char* argv[])
//{
//
//    char*    patternString;
//    patternString   =   argv[2];
//
//    char*   mainString;
//    mainString      =   argv[1];
//
//    int lenOfPatternStr  =   0;
//    int i;
//    while(*(patternString+lenOfPatternStr) != '\0') lenOfPatternStr++;    //求模式字符串的长度
//   
//    int lenOfMainStr  =   0;
//    while(*(mainString+lenOfMainStr) != '\0') lenOfMainStr++;    //求模式字符串的长度
//
//    int*    next            =   nextFunction(patternString);
//    
//    //printf("next数组---->\n");
//    //for(i=1;i<lenOfPatternStr+1;i++)
//    //{
//    //    printf("next[%d]=%d\n",i,next[i]);
//    //}
//
//    int pos;
//    pos =   match(mainString,patternString,0,lenOfMainStr-1);
//    //printf("匹配位置是：%d\n",pos);
//    printf("%d\n",pos);
//
//}
