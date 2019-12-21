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
