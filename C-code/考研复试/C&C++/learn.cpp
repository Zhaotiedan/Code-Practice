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


3.在struct结构定义的后面使用data[0]的好处：
~.方便管理内存缓冲区：如果用指针 char* 代替 char data[0] 来指向新开辟的空间，需要两次malloc也需要两次free。用char data[0]，一次malloc即完成，方便管理缓冲区。
~.可以减少内存碎片化：如果在struct尾部用指针*指向新开辟的buffer长度，struct本身相较buffer长度是很小的，即碎片化的内存。而用char data[0]指向新开辟的buffer，只需一次malloc，struct和buffer的空间是连续的。即减少了内存的碎片化。
~.节省空间（这里就不得不说说指针和data[0]的区别）

使用指针和data[0]有一下区别：
~.地址的连续性，data[0]和结构体是一个连续的存储空间，使用指针就不是连续的。连续的存储空间通过不同的强转使用起来比较灵活。
~.data[0]不占用任何内存，*data占用4字节 。
~.建议：C++的类中可以使用 *data但是不要使用data[0]，因为这样使用可能会导致类中的一些看不到的东西被覆盖。


4.or语句有效循环体只有一个语句
for(i=1;i<=5;)//结果是无限循环
  printf("%d",i);
i++;

5.break和continue的区别
break：结束整个循环过程，不再判断执行循环的条件是否成立
continue：只结束本次循环，而不是终止整个循环。并且只能在循环语句中使用（ for、while 和 do…while）除此之外 continue 不能在任何语句中使用。
eg：
int main(void)
{
    int val; 
    printf("请输入您想去的楼层:");
    while (1)
    {
        scanf("%d", &val);
        switch (val)
        {
        case 1:
            printf("1层开!\n");
            break;  //跳出switch
        case 2:
            printf("2层开!\n");
            break;  //跳出switch
        default:
            printf("该层不存在, 请重新输入:");
            continue;  //结束本次while循环
        }
        break;  //跳出while
    }
    return 0;
}
