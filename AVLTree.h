#pragma once

#include<map>
//AVLTree 高度平衡二叉搜索树
//它是二叉搜索树
//并且要求树和它的所有子树的高度差都不超过1

//为了方便实现，我们这里引入了平衡因子（这个只是一种方式，不是必须的）
//平衡因子 = 右子树的高度-左子树的高度

template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	int _bf;//平衡因子

	pair<K, V> _kv;

	AVLTreeNode(const pair<K,V>& kv)
		:_left(nullptr)
		,_right(nullptr)
		._parent(nullptr)
		,_kv(kv)
		,_bf(0)
	{}
};

template<class K,class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	bool Insert(consy pair<K.V>& kv)
	{
		//1.先按搜索树的规则进行插入
		if (_root = nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if(cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
			cur = new Node(kv);
			if (parent->_kv.first < kv.first)
			{
				parent->_right = cur;
				cur->_parent = parent;
			}
			else
			{
				parent->_left = cur;
				cur->_parent = parent;
			}

			//2.更新平衡因子
			while (parent)
			{
				if (cur == parent->_right)
				{
					parent->_bf++;
				}
				else
				{
					parent->_left--;
				}

				if (parent->_bf == 0)
				{
					break;
				}
				else if (parent->_bf == 1 || parent->_bf == -1)
				{
					cur = parent;
					parent = parent->_parent;
				}
				else if(parent->_bf == 2 || parent->_bf == -2)
				{
					//出现问题了，需要旋转处理
				}
			}

			return 0;
		}
	}

private:
	Node* _root = nullpty;
};
