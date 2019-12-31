#pragma once

/*创建huffman树：
1.以每个权值为节点创建N棵二叉树森林
2.如果二叉树森林中超过两个数：
   a.从二叉树森林中取出 根节点权值最小 的两颗二叉树（1.排序--效率低，2.优先级队列--采用堆的方式进行处理
   b.以该两棵二叉树作为 某个节点的左右子树创建一颗新的二叉树，且该节点权值为左右节点的权值之和
   c.将新创建的二叉树插入到森林中
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//节点结构体
template<class T>
struct HuffmanTreeNode
{
	HuffmanTreeNode(const const T& data=T())
		:_data(data)
		,_pLeft(nullptr)
		,_pRight(nullptr)
	{}
	HuffmanTreeNode<T>* _pLeft;
	HuffmanTreeNode<T>* _pRight;
	HuffmanTreeNode<T>* _pParent;
	T _data;//节点权值
};

//优先级队列默认是大堆,但是我们需要的是小根堆，现在需要新定义一个比较方式构建小堆
template<class T>
class Less
{
	typedef HuffmanTreeNode<T> Node;
public:
	bool operator()(const Node* pLeft, const Node* pRight)
	{
		return pLeft->_data > pRight->_data;
	}
};
//哈夫曼树类
template<class T>
class HuffmanTree
{
	typedef HuffmanTreeNode<T> Node;
public:
	//两种构造方法都可以
	HuffmanTree()
		:_pRoot(nullptr)
	{}

	HuffmanTree(const vector<T>& vdata)
	{
		CreateHuffmanTree(vdata);
	}


	~HuffmanTree()
	{
		_DestroyTree(_pRoot);
	}
	//创建哈弗曼树
	void CreateHuffmanTree(const vector<T>& vdata)
	{
		//1.构建森林:将每个节点放入到优先级队列中（按堆的方式，已经自动排序）,放节点的地址
		//priority_queue<Node*> q;
		priority_queue<Node*, vector<Node*>, Less<T>> q;
		for (auto e : vdata)
		{
			q.push(new Node(e));
		}

		//2.当森林中有两颗或超过两个树
		while (q.size() > 1)
		{
			//取两颗较小的树
			Node* pLeft = q.top();
			q.pop();
			Node* pRight = q.top();
			q.pop();
			//得到新节点
			Node* pParent = new Node(pLeft->_data + pRight->_data);
			pParent->_pLeft = pLeft;
			pParent->_pRight = pRight;
			//将该新树加入森林
			q.push(pParent);
		}
		//循环退出时，此时所剩的树就是哈弗曼树
		_pRoot = q.top();
	}

	//销毁哈弗曼树
private:
	void _DestroyTree(Node*& pRoot)
	{
		if(pRoot)
		{
			_DestroyTree(pRoot->_pLeft);
			_DestroyTree(pRoot->_pRight);
			delete pRoot;
			pRoot = nullptr;
		}
	}
private:
	Node* _pRoot;
};

void TestHuffmanTree()
{
	vector<int> v{ 3,1,7,5 };
	HuffmanTree<int> t;
	t.CreateHuffmanTree(v);
	// 上面可写成
	/*HuffmanTree<int> t(v);*/
}
