#pragma once

//颜色类型
enum Color
{
	RED, BLACK
};

//节点结构体
template<class T>
struct RBTreeNode
{
	RBtreeNode(const T& data = T(), Color color = RED)//节点颜色默认给成红色会对树的影响较小
		:_pLeft(nullptr)
		,_pRight(nullptr)
		,_pParent(nullptr)
		,_data(data)
		,_color(color)
	{}

	RBtreeNode* _pLeft;
	RBtreeNode* _pRight;
	RBtreeNode* _pParent;
	T _data;
	Color _color;
};

/*
增加一个头结点，头结点中的
parent->根节点
pleft->最小节点(最左节点)
pright->最大节点(最右节点)
*/
template<class T>
struct RBTree
{
	typedef RBTreeNode<T> Node;
public:
	RBTree()
	{
		_pHead = new Node;
		_pHead->_pLeft = _pHead;
		_pHead->_pRight = _pHead;
	}

	//插入
	bool Insert(const T& data)
	{
		Node*& pRoot = getRoot();
		//空树
		if (nullptr == pRoot)
		{
			pRoot = new Node(data, BLACK);//创建根节点
			//更新头结点的指向
			_pHead->_pLeft = pRoot;
			_pHead->_pRight = pRoot;
			//根节点的pParent要指向头结点
			pRoot->_pParent = _pHead;
			return true;
		}

		//非空，按照二叉搜索树方法插入新节点
		Node* pCur = pRoot;//代表当前遍历到的树节点
		Node* pParent = nullptr;//保存pCur的双亲
		//寻找插入位置
		while (pCur)
		{
			pParent = pCur;//保存每一次pCur的双亲
			if (data < pCur->_data)
			{
				pCur = pCur->_pLeft;
			}
			else if (data > pCur->_data)
			{
				pCur = pCur->_pRight;
			}
			else
			{
				//假设不能插入相同的节点，红黑树的data值唯一
				return false;
			}
		}
		//找到插入位置，位置是pParent
		pCur = new Node(data);
		if (data < pParent->_data)
		{
			pParent->_pLeft = _pCur;
		}
		else
		{
			pParent->_pRight = _pCur;
		}
		//更新pCur双亲
		pCur->_pParent = pParent;

		//还需检测是否违反红黑树的性质（主要是性质3）
		//因为节点的默认颜色是红色，所以如果新节点的双亲节点是红色，则会违反性质
		if (RED == pParent->_color)
		{

		}

		//更新_pHead的左右指针域
		_pHead->_pLeft = LeftMost();
		_pHead->_pRight = RightMost();
		return true;
	}
private:
	//找树中最左侧节点
	Node* LeftMost()
	{
		Node* pRoot = getRoot();
		if (nullptr == pRoot)
		{
			return _pHead;
		}
		else
		{
			Node* pCur = pRoot;
			while (pCur->_pLeft)
			{
				pCur = pCur->_pLeft;
			}
			return pCur;
		}
	}

	//找最右侧节点
	Node* RightMost()
	{
		Node* pRoot = getRoot();
		if (nullptr == pRoot)
		{
			return _pHead;
		}
		else
		{
			Node* pCur = pRoot;
			while (pCur->_pRight)
			{
				pCur = pCur->_pRight;
			}
			return pCur;
		}
	}

	Node*& getRoot()
	{
		return _pHead->_pParent;
	}

	Node* _pHead;
};
