//1.猜数字游戏
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void menu()
{
	printf("  welcome to my game!   \n");
	printf("********1 to play*******\n");
	printf("********0 to exit*******\n");
	printf("choose 1 as a smart men!\n");
}
void game()
{
	int ret;
	ret = rand() % 100 + 1;
	while (1)
	{
		int guess = 0;
		printf("请输入答案吧");
		scanf("%d", &guess);
		if (guess < ret)
		{
			printf("猜小了\n");
		}
		else if (guess > ret)
		{
			printf("猜大了\n");
		}
		else
		{
			printf("哟，竟然猜对了\n");
			break;
		}
	}
}

int main()
{
	int input;
	srand((unsigned int)time(NULL));//随机种子，让每一次产生的随机数都不一样  NULL:不保存time函数的返回值
	do
	{
		menu();
		printf("请选择>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏");
			break;
		default:
			printf("干啥呢，好好输");
			break;
		}

	} while (input);
	system("pause");
	return 0;
}

//2.登录密码
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int i = 0;
	int count = 0;
	char password[10] = { 0 };// 0 '0’ =‘\0’ NULL
	for (i = 0; i < 3; i++)
	{
		printf("请输入密码>");
		scanf("%s", password);  //加&代表整个数组的地址  不加代表这个数组里首元素的地址
		if (strcmp(password, "1234") == 0)
		{
			printf("恭喜，登陆成功");
			break;
		}
		else
			count--;
		printf("输入错误，还有%d次输入机会");

	}
	if (i == 3)
	{
		printf("三次全错，退出系统");
	}
	system("pause");
	return 0;
}

//3.二分查找法

/*二分查找的优点，递归和非递归，建立在有序的基础之上*/
#include<stdio.h>
#include<stdlib.h>

int binarysearch(int arr[], int k, int left, int right)//arr[]本质是指针 
//=int binarysearch(int arr[],int k, int sz)   int left; int righr=sz-1;
{
	while (left <= right)
	{
		int mid = left + (right - left) / 2;//此句需放while里面，每结束一次if要清零
		if (arr[mid] > k)
		{
			right = mid - 1;
		}
		else if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else
			return mid;
	}
	return -1;
}

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int key = 0;
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	/*arr在哪定义，就在哪使用sizeof(arr) / sizeof(arr[0]) 如果将此句放入子函数，则right值为0 ，因为sizeof（arr）=4，是一个指针变量的大小（4或8）
	因为传参的是首元素的地址，而在子函数中 arr[]来接收，所以它就是一个指针arr[]也可改成*arr
	所以，不能在子函数内部计算主函数参数部分的数组元素个数，如果需要，那么就在主函数中算好再传进去 int sz= sizeof(arr) / sizeof(arr[0])  但是这样不够灵活*/
	int mid = left + (right - left) / 2;
	int zss = 0; //定义一个整型的值
	scanf("%d", &key);
	zss = binarysearch(arr, key, left, right);//来接收这个函数返回值
	if (zss == -1)
	{
		printf("can't find\n");
	}
	else
	{
		printf("下标是%d\n", zss);
	}
	system("pause");
	return 0;
}

//4.接收字符

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int word = 0;
	while ((word = getchar()) != EOF)//end of file ->ctrl+Z    ctrl+c 中断程序
	{
		if (word >= 'a' && word <= 'z')
		{
			printf("%c", word - 32);//putchar(ch-32);
		}
		else if (word >= 'A' && word <= 'Z')
		{
			printf("%c", word + 32);
		}
		else if (word >= '0'&&word <= '9')//在这里，if执行完以后就不会执行后面的if else了
		{


		}
	}
	system("pause");
	return 0;
}