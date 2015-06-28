/*
testArray.c
用来测试一个知识点，在C语言中，我可以定义一个指针，然后对其指向的区域赋值；
那么，有两种实现方式，一是用malloc方式指定一定大小的空间之后再赋值；二是不指定空间大小直接赋值；
这两种方法有什么区别呢？


其实在使用上，没有本质的区别。但是在安全方面，两者有很大的差异：
如果不用malloc先指定一定大小的内存空间，那么在使用该指针时很有可能会覆盖掉其他进程的内存，从而带来意向不到的问题。
这也应该就是C语言在使用中，不安全的地方，尤其是对于新手。

那么如何合理的使用C语言中的指针呢？
1、非新建，只是读取：例如，定义了一个数组，然后利用指针修改数组，或者利用指针进行参数传递；
2、如果是新建指针，那么一定要指定空间大小，在写入操作时不能超过指定的大小，不然会出问题。

author:guozheng
2015/06/05
*/


#include <stdio.h>
#include <stdlib.h>

void pointerWithoutMalloc()
{
    int*    pointer;
    printf("未手动分配空间的指针指向地址是：%p\n",pointer);
}


void pointerWithMalloc()
{
    int*    pointer =   malloc(10*sizeof(int));
    printf("手动分配空间的指针指向地址是：%p\n",pointer);
    int*    pointer2;
    printf("未手动分配空间的指针指向地址2是：%p\n",pointer2);
}


void main()
{
    pointerWithoutMalloc();
    pointerWithMalloc();
    pointerWithoutMalloc();

}
