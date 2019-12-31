#pragma once

#include<string>
using namespace std;

//字符结构体
struct CharInfo
{
	char _ch;//具体字符
	size_t _count;//字符出现的次数
	string _strCode;//字符的编码
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

private:
	vector<CharInfo> _fileInfo;//统计字符出现次数的数组
};
