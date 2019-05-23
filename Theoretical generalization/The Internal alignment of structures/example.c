//练习1
struct s1
{
	char c1;
	int i;//4
	char c2;
};
printf("%d\n", sizeof(struct s1));//1+3+4+1 不是4的倍数 +2=12

//练习2
struct s2
{
	char c1;
	char c2;//偏移量大小为1，可以直接存储
	int i;//4
};
printf("%d\n", sizeof(struct s2));//1+1+4 不是4的倍数  +2=8

//练习3
struct s3
{
	double d;//8
	char c;
	int i;
};
printf("%d\n", sizeof(struct s3));//8+1+3+4=16 是8的倍数

//练习4（结构体嵌套）
struct s3
{
	double d;//8
	char c;
	int i;
};
struct s4
{
	char c1;
	struct s3 s3;//最大对齐数为8
	double a;
};
printf("%d\n", sizeof(struct s4));//1+7+16+8=32