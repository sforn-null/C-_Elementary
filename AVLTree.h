#pragma once

#include<map>
//AVLTree �߶�ƽ�����������
//���Ƕ���������
//����Ҫ�������������������ĸ߶Ȳ������1

//Ϊ�˷���ʵ�֣���������������ƽ�����ӣ����ֻ��һ�ַ�ʽ�����Ǳ���ģ�
//ƽ������ = �������ĸ߶�-�������ĸ߶�

template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	int _bf;//ƽ������

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
		//1.�Ȱ��������Ĺ�����в���
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

			//2.����ƽ������
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
					//���������ˣ���Ҫ��ת����
				}
			}

			return 0;
		}
	}

private:
	Node* _root = nullpty;
};
