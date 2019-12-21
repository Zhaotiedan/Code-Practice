#pragma once

#include<iostream>
using namespace std;
/*二叉搜索树特性：
1.对于任意节点，比其左子树中任意节点都大，比其右子树中任意节点都小
2.最左侧的节点一定是最小的，最右侧的节点一定是最大的
3.中序遍历：是一个有序序列*/

//节点结构体
template<class T>
struct BSTNode
{
	BSTNode(const T& data=T())
		:_pleft(nullptr)
		,_pright(nullptr)
		,_data(data)
	{}
	
	BSTNode<T>* _pleft;//左孩子
	BSTNode<T>* _pright;//右孩子
	T _data;//数据域
};

//二叉搜索树类
template<class T>
class BSTree
{
	typedef BSTNode<T> Node;
public:
	BSTree()//记得初始化根节点
		:_proot(nullptr)
	{}
public:
	//1.查找
	/*若根节点不为空：
	如果当前根节点data==查找的data true
	如果当前根节点data>查找data，往左子树查找
	如果当前根节点data<查找data，往右子树查找
	否则返回false*/
	Node* Find(const T& data)
	{
		Node* pcur = _proot;
		while (nullptr != pcur)
		{
			if (pcur->_data > data)
			{
				pcur = pcur->_pleft;
			}
			else if (pcur->_data < data)
			{
				pcur = pcur->_pright;
			}
			else
			{
				return pcur;
			}
		}
		return nullptr;
	}

	//2.插入
	//分两步：1.查找待插入节点的插入位置  2.插入新节点
	/* 如果是空数，则直接插入，返回true
	  如果是非空树，先找待插入节点在二叉搜索树树中的位置，
	  从当前根节点pur开始查找，当pcur不为空的时候
	  若当前根节点data>插入data，往左子树查找
	  若当前根节点data<插入data，往右子树查找
	  若当前根节点data==插入data，数据存在，返回
	  最后跳出循环时，pcur的位置就是新节点要插入的位置*/
	bool Insert(const T& data)
	{
	//1.查找插入位置
		//空树
		if (nullptr == _proot)
		{
			_proot = new Node(data);
			return true;
		}

		//非空树
		Node* pcur = _proot;
		Node* parent = nullptr;//循环结束时，pcur找到的位置是空的，所以需要一个parent在上面循环中来记录待插入位置的父节点
		while (pcur)
		{
			parent = pcur;//更新parent
			if (pcur->_data > data)
			{
				pcur = pcur->_pleft;
			}
			else if (pcur->_data < data)
			{
				pcur = pcur->_pright;
			}
			else
			{
				return false;
			}
		}
		
	//2.插入新节点
		pcur = new Node(data);
		if (parent->_data > data)
		{
			parent->_pleft = pcur;
		}
		else
		{
			parent->_pright = pcur;
		}
		return true;
	}

	//3.删除节点
	//分两步：1.查找删除节点位置  2.删除该节点
	bool Delete(const T& data)
	{
		//空树
		if (nullptr == _proot)
		{
			return false;
		}

		//非空树
		//1.查找位置
		Node* pcur = _proot;
		Node* parent = nullptr;
		while (pcur)
		{
			if (pcur->_data == data)
			{
				break;
			}
			else if (pcur->_data > data)
			{
				parent = pcur;
				pcur = pcur->_pleft;
			}
			else
			{
				parent = pcur;
				pcur = pcur->_pright;
			}
		}
		if (pcur == nullptr)
			return false;

		//2.删除节点
		//有种情况：
		/*a.删除节点无孩子节点且无左孩子
		  b.删除节点无右孩子
		  c.删除节点左右孩子都有
		*/
		//a.删除节点无孩子节点且无左孩子
		Node* pdelNode = pcur;
		if (nullptr == pcur->_pleft)
		{
			//根节点
			if (nullptr == parent)
			{
				_proot = parent->_pright;
			}
			//非根节点
			else
			{
				//删除节点是父节点的左节点
				if (pcur == parent->_pleft)
				{
					parent->_pleft = pcur->_pright;
				}
				//删除节点是父节点的右节点
				else
				{
					parent->_pright = pcur->_pright;
				}
			}
		}
		//b.删除节点无右孩子,只有左孩子
		else if (nullptr == pcur->_pright)
		{
			//根节点
			if (nullptr == parent)
			{
				parent = parent->_pleft;
			}
			//非根节点
			else
			{
				//删除节点是父节点的左节点
				if (pcur == parent->_pleft)
				{
					parent->_pleft = pcur->_pleft;
				}
				//删除节点是父节点的右节点
				else
				{
					parent->_pright = pcur->_pleft;
				}
			}
		}
		//c.删除节点左右孩子都有
		//在pCur的左子树中找一个替代节点-->一定是左子树中最大的节点(最右侧节点)
		//或者右子树，最小，最左侧
		//将替代节点中的内容赋值给待删除节点，然后删除替代节点
		else
		{
			Node* pdel = pcur->_pleft;
			parent = pcur;
			while (pdel->_pright)
			{
				parent = pdel;
				pdel = pdel->_pright;
			}
			pcur->_data = pdel->_data;

			//删除替代节点
			//替代节点是父节点的左节点
			if (parent->_pleft == pdel)
			{
				parent->_pleft = pdel->_pleft;
			}
			//替代节点是父节点的右节点
			else
			{
				parent->_pright = pdel->_pleft;
			}
			pdelNode = pdel;
		}
		delete pdelNode;
		return true;
	}

	//找最左元素
	Node* MostLeft()
	{
		if (nullptr == _proot)
		{
			return nullptr;
		}
		Node* pcur = _proot;
		while (pcur->_pleft)
		{
			pcur = pcur->_pleft;
		}
		return pcur;
	}
	//找最右元素
	Node* MostRight()
	{
		if (nullptr == _proot)
		{
			return nullptr;
		}
		Node* pcur = _proot;
		while (pcur->_pright)
		{
			pcur = pcur->_pright;
		}
		return pcur;
	}
	//中序遍历
	void Inorder()//将该接口封装，保护代码
	{
		_Inorder(_proot);
	}
private:
	void _Inorder(Node* proot)
	{
		if (proot)
		{
			_Inorder(proot->_pleft);
			cout << proot->_data << " ";
			_Inorder(proot->_pright);
		}
	}
private:
	Node* _proot;//根节点
};


//二叉搜索树应用
//k模型：检测某个单词是否拼写正确，树节点的值域是正确单词，用单词在树中查找，找到则正确，找不到则错误
//k-v模型：文件中包含了多个ip地址 ，知道每个ip地址出现的次数  <ip，次数>
template<class K, class V>
struct BSTNode
{
	BSTNode(const K& key, const V& value)
		: _pLeft(nullptr)
		, _pRight(nullptr)
		, _key(key)
		, _value(value)
	{}

	BSTNode<T>* _pLeft;
	BSTNode<T>* _pRight;
	K _key;
	V _value;
};

template<class K, class V>
class BSTree
{
	typedef BSTNode<K, V> Node;

public:
	BSTree()
		: _pRoot(nullptr)
	{}

	// 
	Node* Find(const K& key)
	{
		Node* pCur = _pRoot;
		while (pCur)
		{
			if (key == pCur->_key)
				return pCur;
			else if (key < pCur->_key)
				pCur = pCur->_pLeft;
			else
				pCur = pCur->_pRight;
		}

		return nullptr;
	}

	bool Insert(const K& key, const V& value)
	{
		if (nullptr == _pRoot)
		{
			_pRoot = new Node(key, value);
			return true;
		}

		Node* pCur = _pRoot;
		Node* pParent = nullptr;
		while (pCur)
		{
			pParent = pCur;
			if (key < pCur->_key)
				pCur = pCur->_pLeft;
			else if (key > pCur->_key)
				pCur = pCur->_pRight;
			else
				return true;
		}

		pCur = new Node(key, value);
		if (key < pParent->_key)
			pParent->_pLeft = pCur;
		else
			pParent->_pRight = pCur;

		return true;
	}
private:
	Node* _pRoot;
};


//二叉搜索树缺陷：查找时间复杂度O(N),
//如果在构造二叉搜索树期间，数据序列有序或者接近有序：则退化为单支数
//如果二叉搜索树退化为单支树，则该树会失去平衡