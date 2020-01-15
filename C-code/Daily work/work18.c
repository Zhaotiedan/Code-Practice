//1.
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

//2.
int main()
{
	int i = 10;
	int j = 10, k = 3;
	k *= i + j;
	printf("%d\n", k);
	//  k=3  +优先级高于*=
}
