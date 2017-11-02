#pragma once
#include <iostream>
#include <stdlib.h>

class Tree;
class Node
{
friend Tree;
public:
	Node(int val):value(val), left(NULL), right(NULL) {};
	virtual ~Node();
private:
	int value;
	Node* left;
	Node* right;
	int countLeft;
};

class Tree
{
public:
//	Tree(): root(NULL) {};
	Tree(int value) 
	{
		root = new Node(value);
	};
	bool add(int val)
	{
		return addRecur(&root, val);
	}
	void print()
	{
		printRecur(root);
		std::cout << std::endl;
	}
	void deleteVal(int val)
	{
		deleteRecur(&root, val);
	};

private:
	void deleteRecur(Node** ppNode, int delValue)
	{
		if (*ppNode != NULL)
		{
			if (delValue < (*ppNode)->value)
				deleteRecur(&((*ppNode)->left), delValue);
			else if (delValue >(*ppNode)->value)
				deleteRecur(&((*ppNode)->right), delValue);
			else if ((*ppNode)->left != NULL && (*ppNode)->right != NULL)
			{
				(*ppNode)->value = minRecur((*ppNode)->right);
				deleteRecur(&((*ppNode)->right), (*ppNode)->value);
			}
			else
				if ((*ppNode)->left != NULL)
					*ppNode = (*ppNode)->left;
				else
					*ppNode = (*ppNode)->right;
		}
	};
	int minRecur(Node* pNode)
	{
		while (pNode->left != NULL)
		{
			pNode = pNode->left;
		}
		return pNode->value;
	}
	void printRecur(Node* pNode)
	{
		if (pNode != NULL)
		{
			printRecur(pNode->left);
			std::cout << pNode->value << ' ';
			printRecur(pNode->right);
		}
	}
	bool addRecur(Node** ppNode, int val)
	{
		if (*ppNode == NULL)
		{
			*ppNode = new Node(val);
			return true;
		}
		else if (val < (*ppNode)->value)
			return addRecur(&((*ppNode)->left), val);
		else if (val > (*ppNode)->value)
			return addRecur(&((*ppNode)->right), val);
		return false;
	};
	Node* root;
};