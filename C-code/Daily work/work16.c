//1.
char *myString()
{
	char buffer[6] = { 0 };
	char *s = "hello world";
	for (int i = 0; i < sizeof(buffer) - 1; i++)
	{
		buffer[i] = *(s + i);
	}
	return buffer;
}
int main()
{
	char * buffer = myString();
	printf("%s\n", buffer);//结果为烫烫烫的随机值，因为buffer为局部数组，函数结束后会被收回
	system("pause");
	return 0;
}

//2.
int main()
{
	char a[1000];
	int i;
	for (i = 0; i < 1000; i++)
	{
		a[i] = (char)(-1 - i);
	}
	printf("%d\n", strlen(a));//255
	system("pause");
	return 0;
}

//3.
int main()
{
	const int i = 0;
	int *j = (int *)&i;
	*j = 1;
	printf("%d,%d", i, *j);//1,1
	system("pause");
	return 0;
}
//4.
int main()
{
	unsigned int a = 0xFFFFFFF7;
	unsigned char i = (unsigned char)a;
	char *b = (char *)&a;
	printf("%08x,%08x", i, *b);
	system("pause");
	return 0;
}
//5.
int main()
{
	char *str = "abcde";
	str += 2;
	printf("%lu\n", str);//打印c的地址
	system("pause");
	return 0;
}

//6.
int main()
{
	int x, y, z;
	x = 1;
	y = 1;
	z = x++, y++, ++y;
	printf("%d,%d,%d\n", x, y, z);
	//x=2  y=3  z=1 赋值运算符优先级高于逗号表达式，所以先算
	//(z=x++),y++,++y
}

//7.
int main()
{
	int i = 10;
	int j = 10, k = 3;
	k *= i + j;
	printf("%d\n", k);
	//  k=3  +优先级高于*=
}

//8.
在一般系统中,设float x[8];假设数组x开始于内存1000单元,则x[2]的存储始于( 1008  )
首先要明白这里的1000是16进制的，要知道x[2]存储起始，就得知道x[2]距离x[0]间有多少个元素就行了，很明显中间相隔x[0]和x[1]两个元素，又因为一个folat类型
元素占4个字节，所以中间间隔2*4=8字节，转换为16进制还是8,1000+8=1008


//9.
DOS中扩展名为.BAK的文件称为  备份文件。
备份文件(Backup File）,拷贝到存储介质上的文件，可以帮助您保护数据，以防其在系统硬件或存储介质出现故障时受到破坏。

//10.
设整型变量n的值为2，执行语句“n+=n-=n*n”后，n的值是（        ）
*优先级最高，先算n*n=4 此时n=2
+=和-=是同级，从右往左，n=n-4=-2 此时n=-2
最后+=  =n+n=-2-2=-4 

//11.
i
nt main()
{
char *p="abcdefgh",*r;
long *q;
q=(long*)p;
q++;
r=(char*)q;
printf("%s\n",r);
}y
输出efgh，long占四个字节，q++就到了e

//12.
#
include <stdio.h>
int main()
{
char str[]="ABCD", *p=str;
printf("%d\n", *(p+4));
return 0;
};
输出 0
