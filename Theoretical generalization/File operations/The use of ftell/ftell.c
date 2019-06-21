#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE*pfile;
	long size;
	pfile = fopen("test.txt", "rb");
	if (pfile == NULL)perror("Error opening file");
	else
	{
		fseek(pfile, 0, SEEK_END);
		size = ftell(pfile);
		fclose(pfile);
		printf("Size of test.txt:%ld bytes.\n", size);
	}
	system("pause");
	return 0;
}