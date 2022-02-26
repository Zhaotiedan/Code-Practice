1. c中整型常量只有三种形式：10进制、8进制、16进制
#include<stdio.h>
void main()
{
    int i,j;
    i=010;//8进制
    j=9;
    printf("%d,%d",i-j,i+j);//-1,17
}
