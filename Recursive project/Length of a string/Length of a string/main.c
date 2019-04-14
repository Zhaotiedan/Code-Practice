#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//é€’å½’
int Strlen(const char *str)
{
	if (*str == '\0')
		return 0;
	else
		return 1 + Strlen(str+1);
}
int main()
{
	char *arr = "abcd";//char *arr ={'a','b','c','d'};
	int result = 0;
	result = Strlen(arr);
	printf("%d", result);
	system("pause");
	return 0;
}
//éé€’å½’
int Strlen(char *str)
{
	int count = 0;
<<<<<<< HEAD
	assert(str != NULL);//¶ÏÑÔ  ±ÜÃâÖ¸ÕëÎª¿ÕÖµ Óöµ½Ö¸Õë¾ÍÒª¼Ó  ÊÇÒ»¸öºê²»ÊÇº¯Êı Ö»ÔÚDebugÌõ¼şÏÂ¹ÜÓÃ
	while (*str != '\0')//ÒòÎª×Ö·û´®ÒÔ\0½áÎ²
=======
	assert(str != NULL);//æ–­è¨€  é‡åˆ°æŒ‡é’ˆå°±è¦åŠ   æ˜¯ä¸€ä¸ªå®ä¸æ˜¯å‡½æ•° åªåœ¨Debugæ¡ä»¶ä¸‹ç®¡ç”¨
	while (*str != '\0')//å› ä¸ºå­—ç¬¦ä¸²ä»¥\0ç»“å°¾
>>>>>>> 77fda4d6d4feebcfadf61d72df084eb1d6451e47
	{
		count++;
		str++;
	}
	return count;
}
int main()
{
	char *arr = "abcd";
	int result = 0;
	result = Strlen(arr);
	printf("%d", result);
	system("pause");
	return 0;
}
