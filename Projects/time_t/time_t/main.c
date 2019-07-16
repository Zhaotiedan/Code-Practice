#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

//struct time {
//	int second;
//	int minute;
//	int hour ;
//	int day ;
//	int month ;
//	int year ;
//};


//int main()
//{
//	time_t timep;
//	struct time *p;
//	int seconds = time(&timep);
//	//time_t (&timep); //获取从1970至今过了多少秒，存入time_t类型的timep
//	p = ctime(&timep);
//	printf("%d/%d/%d %02d:%02d:%02d\n", 1900 + p->year, 1 + p->month, p->day, p->hour, p->minute, p->second);
//	printf("%s", ctime(&timep));
//	printf("%d\n", seconds);
//	system("pause");
//	return 0;
//}

//int main() 
//{
//	time_t timep;
//	int seconds = time(&timep);
//	/*int minute = seconds * 24;
//	int hour = seconds * 24 * 24;
//	int day = seconds * 24 * 24 * 24;
//	int month = seconds * 24 * 24 * 24 * 31;
//	int year = seconds * 24 * 24 * 24 * 31 * 12;
//	printf("%d-%d-%d%d%d%d%d\n", 1970+year,01+month,01+ month,day, hour,seconds);*/
//	//char *str = ctime(&seconds);
//	printf("%s", ctime(&timep));
//	printf("%d\n", seconds);
//	system("pause");
//	return 0;
//}
//typedef u8;
//typedef u16;

//typedef struct time {
//	u8 year;
//	u8 mon : 4;
//	u8 mday : 5;
//	u8 hour : 5;
//	u8 min : 6;
//	u8 sec : 6;
//	u8 wday : 3;
//	u16 yday : 9;
//};



int main()
{
	time_t timep;

	int seconds = time(&timep);


	int i1, i2, i3, i4, i5, i6, i7;
	int j = 0;
	for (j = 0; j < 31; j++)
	{
		if (j / 7 == 1)
		{
			i1++;
		}
		if (j / 7 == 2)
		{
			i2++;
		}
		if (j / 7 == 3)
		{
			i3++;
		}
		if (j / 7 == 4)
		{
			i4++;
		}
	}
}
