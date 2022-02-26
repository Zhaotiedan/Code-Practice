1. c中整型常量只有三种形式：10进制、8进制、16进制
#include<stdio.h>
void main()
{
    int i,j;
    i=010;//8进制,必须以0开头，数字为0~7
    j=9;
    printf("%d,%d",i-j,i+j);//-1,17
}

2.逗号运算符，逗号表达式值为最后一个b表达式的值，中间非赋值语句可忽略
#include<stdio.h>
void main()
{
    int a;
    printf("%d\n",(a=3*5,a*4,a+5));//a=15,输出20
}

eg2
若已定义 int a,则表达式 a=10,a+10,a++的值是：10，因为先计算表达式的值再计算a的值


