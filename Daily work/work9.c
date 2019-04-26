/*1.编写函数：
unsigned int reverse_bit(unsigned int value);
这个函数的返回值是value的二进制位模式从左到右翻转后的值。

如：
在32位机器上25这个值包含下列各位：
00000000000000000000000000011001
翻转后：（2550136832）
10011000000000000000000000000000
程序结果返回：
2550136832*/
#include<stdio.h>
#include<stdlib.h>

unsigned int reverse_bit(unsigned int value)
{
	unsigned int sum = 0;
	int i = 0;
	for (i = 0; i < 32; i++)
		{
			sum += ((value>>i)&1)*pow(2,31-i);//1*2^31 + 0*2^30 + 0*2^29 +...+ 0*2^0
		}
	return sum;
}
int main()
{
	unsigned int n = 0;
	unsigned int result = 0;
	scanf("%d", &n);
	result = reverse_bit(n);
	printf("%u\n", result);
	system("pause");
	return 0;
}
/*2.不使用（a+b）/2这种方式，求两个数的平均值。*/
//方法一 画图可解决
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	scanf("%d %d", &a, &b);
	c = b + (a - b) / 2;
	printf("%d", c);
	system("pause");
	return 0;
}
//异或法：利用原始（a+b）/2，（a+b）=（a&b）*2+a^b,(a+b)/2=(a&b)+(a^b)>>1 

//两种方法详情剖析见CSDN：https://blog.csdn.net/qq_42913794/article/details/89449344

/*3.编程实现： 
一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。 
请找出这个数字。（使用位运算） 
*/
#include<stdio.h>
#include<stdlib.h>
int Find_Number(int *arr, int len)
{
	int temp = 0;
	int i = 0;
	for (i = 0; i < len; i++)
	{
		temp = temp ^ arr[i];
	}
	return temp;

}
int main()
{
	int arr[] = { 1,2,3,4,3,2,1 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int result = 0;
	result = Find_Number(arr,len);
	printf("%d\n", result);
	system("pause");
	return 0;
}

/*4.有一个字符数组的内容为:"student a am i", 
请你将数组的内容改为"i am a student". 
要求： 
不能使用库函数。 
只能开辟有限个空间（空间个数和字符串的长度无关）。 

student a am i 
i ma a tneduts 
i am a student*/
//先将整个字符串逆置，再将单个单词逆置

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<math.h>

void Reverse_Swap(char *start,char *end)
{
	assert(start!=NULL);
	assert(end != NULL);
	while (start < end)
	{
		char tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}
}
void Reverse_Array(char *arr, int len)
{
	char *p = arr;
	while (*p)
	{
		char *start= p;
		while ((*p != ' ')&&(*p != '\0'))
		{
			p++;
		}
		Reverse_Swap(start,p-1);
		if (*p == ' ')
		{
			p++;
		}
	}
}
int main()
{
	char arr[] = "student a am I";
	int len =sizeof(arr)/sizeof(arr[0])-1;
	char *left = arr;
	char *right =arr+len - 1;
	Reverse_Swap(left, right);
	printf("%s\n", arr);
	Reverse_Array(arr,len);
	printf("%s\n", arr);
	system("pause");
	return 0;
}
