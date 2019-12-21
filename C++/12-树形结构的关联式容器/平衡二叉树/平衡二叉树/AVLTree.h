#pragma once

#include<iostream>
using namespace std;

//节点类
template<class T>
struct AVLTreeNode
{
	AVLTreeNode(const T& data=T())//T为内置类型--0   T为自定义类型--该类必须提供无参构造函数
		:_pleft(nullptr)
		,_pright(nullptr)
		,_pparent(nullptr)
		，_data(data)
		,_bf(0)
	{}

	AVLTreeNode<T>* _pleft;
	AVLTreeNode<T>* _pright;
	AVLTreeNode<T>* _pparent;
	T _data;
	int _bf;//平衡因子
};

//平衡二叉树类
template<class T>
class AVLTree
{
	typedef AVLTreeNode<T> Node;
public:
	AVLTree()
		:_proot(nullptr)
	{}
	bool Insert(const T& data)
	{
	//空树
		if (nullptr == _proot)
		{
			_proot = new Node(data);
		}
	//非空树 按照二叉搜索树方式插入
		 //1.查找
		Node* pcur = _proot;
		Node* parent = nullptr;
		while (pcur)
		{
			parent = pcur;
			if (data < pcur->_data)
			{
				pcur = pcur->_pleft;
			}
			else if (data > pcur->_data)
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
		if (data < parent->_data)
		{
			parent->_pleft = pcur;
		}
		else
		{
			parent->_pright = pcur;
		}
		pcur->_pparent = parent;
		//3.更新parent的平衡因子
		//插入前的三种情况：
		/*1.叶子节点---pcur可以插在parent的左侧或者右侧--平衡因子：正负1  对上层会产生影响
		2.只有左孩子---ocur只能插在parent的右侧-----平衡因子：0
		3.只有右孩子---pcur只能插在parent的左侧----平衡因子：0     2.和3对上层没有影响*/


		while ()
		{
			// 插为parent左孩子：平衡因子--
			if (pcur == parent->_pleft)
			{
				parent->_bf--;
			}
			//插为parent右孩子：平衡因子++
			else
			{
				parent->_bf++;
			}


			if (0 == parent->_bf)
			{
				return;
			}
			else if (-1 == parent->_bf || 1 == parent->_bf)//往上更新
			{
				pcur = parent;
				parent = pcur->_pparent;
			}
			else
			{
				//父节点的平衡因子为2或-2:AVL树的性质遭到破坏，树已经不平衡
				//必须对以parent为根的二叉树进行旋转处理

			}
		}
	}
private:
	Node* _proot;
};