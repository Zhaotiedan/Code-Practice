#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE*pfile;
	pfile = fopen("test.txt", "wb");
	fputs("This is an apple.", pfile);
	fseek(pfile, 9, SEEK_SET);
	fputs("sam", pfile);
	fclose(pfile);
	system("pause");
	return 0;
}