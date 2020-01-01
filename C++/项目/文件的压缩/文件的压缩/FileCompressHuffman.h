#pragma once

#include<string>
#include<vector>
using namespace std;
#include"HuffmanTree.h"

//字符结构体
struct CharInfo
{
	char _ch;//具体字符
	size_t _count;//字符出现的次数
	string _strCode;//字符的编码

	CharInfo(size_t count = 0)
		:_count(count)
	{}

	CharInfo operator+(const CharInfo& value)
	{
		return CharInfo(_count + value._count);
	}

	bool operator>(const CharInfo& value)const//注意这个const在这里修饰this指针的指向--就是左操作数
	{
		return _count > value._count;
	}

	bool operator==(const CharInfo& value)
	{
		return _count == value._count;
	}
};

//文件压缩类
class FileCompressHuff
{
public:
	FileCompressHuff();
	//压缩
	void CompressFile(const string& path);

	//解压缩
	void UnCompressFile(const string& path);

public:
	vector<CharInfo> GetfileInfo()
	{
		return _fileInfo;
	}
		
//获取字符的哈夫曼编码
private:
	void GetHuffmanCode(HuffmanTreeNode<CharInfo>* pRoot);

private:
	vector<CharInfo> _fileInfo;//统计字符出现次数的数组，由于数组中序需要存放结构体，所以需要定义vector类型
};
