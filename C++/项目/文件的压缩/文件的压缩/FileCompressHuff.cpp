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

//获取字符的哈夫曼编码
void FileCompressHuff::GetHuffmanCode(HuffmanTreeNode<CharInfo>* pRoot)
{
	if (nullptr == pRoot)
	{
		return;
	}
	GetHuffmanCode(pRoot->_pLeft);
	GetHuffmanCode(pRoot->_pRight);

	//来到叶子节点处--左右节点为空
	if (nullptr == pRoot->_pLeft&&pRoot->_pRight)
	{
		/*往上走，如果是上一个的左，code为0，为右则为1，所以为了找到上一个节点，在节点结构体加入pParent指针*/

		//从当前叶子节点位置开始
		HuffmanTreeNode<CharInfo>* pCur = pRoot;
		HuffmanTreeNode<CharInfo>* pParent = pRoot->_pParent;
		string& strCode= pCur->_data._strCode;
		vector<CharInfo> fileInfo = FileCompressHuff::GetfileInfo();
		//vector<CharInfo> fileInfo;
		while (pParent)
		{
			if (pCur == pParent->_pLeft)//当前节点为上一个的左
			{
				strCode += '0';
			}
			else//当前节点为上一个的右
			{
				strCode += '1';
			}

			//更新pCur和pParent的值
			pCur = pParent;
			pParent = pCur->_pParent;
		}
		reverse(strCode.begin(), strCode.end());
		fileInfo[pRoot->_data._ch]._strCode = strCode;//下标对应元素的 _strCode
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
		//读取文件
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
	HuffmanTree<CharInfo> t(_fileInfo, CharInfo(0));//树节点中的权值是结构体CharInfo类型的  CharInfo(0)--不把出现次数为0的字符放入树中
	//3.获取每个字符的编码
	

	//4.按照获取到的字符编码重新改写源文件

	delete[] ReadBuff;
	fclose(fin);
}