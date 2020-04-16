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
	RBTreeNode(const T& data = T(), Color color = RED)//节点颜色默认给成红色会对树的影响较小
		:_pLeft(nullptr)
		,_pRight(nullptr)
		,_pParent(nullptr)
		,_data(data)
		,_color(color)
	{}

	RBTreeNode* _pLeft;
	RBTreeNode* _pRight;
	RBTreeNode* _pParent;
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
		_size = 0;
	}

	//插入：1.按照二叉搜索树的方式插入  2.检测是否违反红黑树的性质
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
			pParent->_pLeft = pCur;
		}
		else
		{
			pParent->_pRight = pCur;
		}
		//更新pCur双亲
		pCur->_pParent = pParent;

		//还需检测是否违反红黑树的性质（主要是性质3）
		//因为节点的默认颜色是红色，所以如果新节点的双亲节点是红色，则会违反性质

		/*
	一.p为g的左子树
		1.叔叔节点存在且为红：
		cur可能为红(默认插入节点为红)；也可能为黑(子树不满足红黑树性质，将cur改成黑色)
		p和u设置为黑，g设置为红(避免g有根时，整个这块子树的黑色节点数会多1)
		g：如果为根节点，设置为黑（避免违反红黑树性质）；如果不是根节点，黑色则调整结束，红色则继续向上调整

		2.叔叔节点不存在||叔叔节点为黑色
		 叔叔节点不存在：（根据性质3）则p和cur中一定有一个要为黑，所以这会违背性质4
		 叔叔节点为黑色：cur一定不是插入节点，cur子树中插入新节点后，子树会不满红黑树性质，向上调整时，会将cur从黑改成红
		                 因为性质3，所以p和cur有一个必须改成黑色(cur是为了满足性质才调整的)，所以只能改p为黑色
						 此时树含p的这边又会多出一个黑节点，所以需要将双亲p和祖父g进行颜色交换，对以祖父g为根的树进行右单旋

		3.叔叔节点不存在||叔叔节点为黑色  但cur是p的右孩子
		将p为根的子树进行左单旋，会将cur变成p的左孩子，再交换一下p和cur指向，变成情况2即可

	二.p为g的右子树
	    将树翻转180度即可
		*/

		//p为g的左子树
		while ((pCur != _pHead) && (RED == pParent->_color))
		{	
			Node* grandFather = pParent->_pParent;
			if (pParent == grandFather->_pLeft)//p为g的左子树
			{
				//正常三种情况

				Node* uncle = grandFather->_pRight;

				//情况1.叔叔节点存在且为红
				if (uncle&&uncle->_color == RED)
				{
					//p和u设置为黑，g设置为红
					pParent->_color = BALCK;
					uncle->_color = BALACK;
					grandFather->_color = RED;

					//继续向上调整
					pCur = grandFather;
					pParent = pCur->_pParent;
				}

				//情况2和3，先处理情况3
				else
				{
					//叔叔节点不存在 || 叔叔节点为黑色  cur是p的右孩子
					if (pCur == pParent->_pRight)
					{
						//左单旋，调整为情况2
						RotateLeft(pParent);
						Swap(pParent, pCur);
					}
				}
				//双亲p和祖父g进行颜色交换，对以祖父g为根的树进行右单旋
				grandFather->_color = RED;
				grandFather->_color = BLACK;
				RotateRight(grandFather);
			}

			//p为g的右子树
			else
			{
				//正常情况法反三种
				Node* uncle = grandFather->_pLeft;
				if (uncle->_color == RED)
				{
					pParent->_color = BLACK;
					uncle->_color = BALCK;
					grandFather->_color = RED;

					pCur = grandFather;
					pParent = pCur->_pParent;
				}
				else
				{
					//情况2，3的反情况
					if (pCur == pParent->_pRight)
					{
						//左单旋，调整为情况2
						RotateRight(pParent);
						Swap(pParent, pCur);
					}
					grandFather->_color = RED;
					grandFather->_color = BLACK;
					RotateLeft(grandFather);
				}
			}
		}	

		//更新_pHead的左右指针域
		pRoot->_color = BLACK;
		_pHead->_pLeft = LeftMost();
		_pHead->_pRight = RightMost();
		_size++;
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

	//左单旋
	void RotateLeft(Node* pParent)
	{
		Node* pSubR = pParent->_pRight;
		Node* pSubRL = pSubR->_pLeft;

		pParent->_pRight = pSubRL;
		if (pSubRL)
		{
			pSubRL->_pParent = pParent;
		}
		pSubR->_pLeft = pParent;
		Node* pPParent = pParent->_pParent;
		pParent->_pParent = pSubR;
		pSubR->_pParent = _pPParent;

		if (pPParent == _pHead)//pPParent是根节点
		{
			_pHead->_pParent = pSubR;
		}
		else//pPParent不是根节点
		{
			if (pParent == pPParent->_pLeft)
			{
				pPParent->_pLeft = pSubR;
			}
			else
			{
				pPParent->_pRight = pSubR;
			}
		}

	}

	//右单旋
	void RotateRight(Node* pParent)
	{
		Node* pSubL = pParent->_pLeft;
		Node* pSubLR = pSubL->_pRight;
		pParent->_Left = pSubL;
		if (pSubLR)
		{
			pSubLR->_pParent = pParent;
		}
		pSubL->_pRight = pParent;
		Node* pPParent = pParent->_pParent;
		pSubL->_pParent = pPParent;
		pParent->_pParent = pSubL;
		if (pPParent == _pHead)
		{
			_pHead->_pParent = pSubL;
		}
		else
		{
			if (pParent == pPParent->_pLeft)
			{
				pPParent->_pLeft = pSubL;
			}
			else
			{
				pPParent->_pRight = pSubL;
			}
		}
	}

	Node*& getRoot()
	{
		return _pHead->_pParent;
	}

	Node* _pHead;
	size_t _size;
};

void TestRBtree()
{
	//int arr[]={}
}
