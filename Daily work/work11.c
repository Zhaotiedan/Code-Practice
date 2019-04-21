/*1.实现一个函数，可以左旋字符串中的k个字符。 
ABCD左旋一个字符得到BCDA 
ABCD左旋两个字符得到CDAB */
#include<stdio.h>
#include<stdlib.h>

void Reverse(char *left, char *right)
{
	while (left < right)
	{
		char tmp = 0;
		tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void Left_handed(char *arr, int k, int len)
{
	int i = 0;
	char *p = arr;
	while (i < k)
	{
		p = arr + i;
		i++;
	}
	Reverse(arr, p);
	Reverse(p + 1, arr + len - 1);
	Reverse(arr, arr + len - 1);
}
int main()
{
	int k = 0;
	char arr[] = "ABCDE";
	int len = sizeof(arr) / sizeof(arr[0]) - 1;
	scanf("%d", &k);
	Left_handed(arr, k, len);
	printf("%s", arr);
	system("pause");
	return 0;
}

/*2.判断一个字符串是否为另外一个字符串旋转之后的字符串。 
例如：给定s1 =AABCD和s2 = BCDAA，返回1 
给定s1=abcd和s2=ACBD，返回0. 

AABCD左旋一个字符得到ABCDA 
AABCD左旋两个字符得到BCDAA 

AABCD右旋一个字符得到DAABC
*/
