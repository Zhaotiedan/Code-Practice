#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char input[20] = { 0 };
	system("shutdown -s 60");
	while (1)
	{
		printf("你的电脑将会在60s关机，输入我是猪停止关机");
		scanf("%s", input);
		if (strcmp(input, "我是猪") == 0)
		{
			system("shutdown -a");
			break;
		}
	}
	return 0;
}