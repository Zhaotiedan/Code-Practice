#define _CRT_SECURE_NO_WARNINGS 1


/*压缩：
1.统计每个字符出现的次数 ---FileCompressHuffman.h
2.创建huffman树---HuffmanTree.h
3.获取字符的编码
4.用每个字符的编码重新改写源文件*/

#include"HuffmanTree.h"
#include"FileCompressHuffman.h"

int main()
{
	//TestHuffmanTree();
	FileCompressHuff fc;
	fc.CompressFile("1.txt");
	return 0;
	system("pause");
}