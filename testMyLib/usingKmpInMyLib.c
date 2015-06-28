/*
测试程序，用来调用myLib/string中的kmp.c

author:guozheng
2015/06/16

*/

#include <stdio.h>
#include "../myLib/string/kmp.h"

void main(int argc, char* argv[])
{
 
    char*   mainString      =   argv[1];
    char*   patternString   =   argv[2];
    
    int lenOfPatternStr  =   0;
    while(*(patternString+lenOfPatternStr) != '\0') lenOfPatternStr++;    //求模式字符串的长度
   
    int lenOfMainStr  =   0;
    while(*(mainString+lenOfMainStr) != '\0') lenOfMainStr++;    //求模式字符串的长度

    printf("%d\n",match(mainString,patternString,0,lenOfMainStr-1));
    
}
   

