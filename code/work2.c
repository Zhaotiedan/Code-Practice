int main()
{
	int a = 2;
	int b = 3;
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("a=%d  b=%d\n", a, b);
	system("pause");
	return 0;
}