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