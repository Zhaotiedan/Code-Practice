#define _CRT_SECURE_NO_WARNINGS 1

#include"FileCompressHuffman.h"
#include<assert.h>
#include"HuffmanTree.h"

//构造函数
FileCompressHuff::FileCompressHuff()
{
	_fileInfo.resize(256);
	//初始化数组，一个下标就是字符acs值的数组
	for (int i = 0; i < 256; i++)
	{
		_fileInfo[i]._ch = i;
		_fileInfo[i]._count = 0;
	}
}

void FileCompressHuff::CompressFile(const string& path)
{
	//1.统计原文件中每个字符出现的次数
	   //打开文件
	FILE* fin = fopen(path.c_str(),"r");
	if (nullptr == fin)
	{
		assert(false);
		return;
	}
	char * ReadBuff = new char[1024];
	int rdSize = 0;
	while (true)
	{
		rdSize = fread(ReadBuff, 1, 1024, fin);//函数返回值为读到了多少个字节
		if (0 == rdSize)//读取文件结束
		{
			break;
		}
		for (int i = 0; i < rdSize; i++)//按实际读到字节数进行统计
		{
			_fileInfo[ReadBuff[i]]._count++;
		}
	}

	//2.以字符出现的次数为权值创建一颗哈弗曼树
	HuffmanTree<CharInfo> t(_fileInfo);
	//3.获取每个字符的编码


	//4.按照获取到的字符编码重新改写源文件

	delete[] ReadBuff;
	fclose(fin);
}
