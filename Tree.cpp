#include "Tree.h"

Tree::Tree(int value)
{
	root = new Node(value);
};
bool Tree::add(int val)
{
	return addRecur(&root, val);
};
void Tree::print()
{
	printRecur(root);
	std::cout << std::endl;
};
void Tree::deleteVal(int val)
{
	deleteRecur(&root, val);
};

void Tree::deleteRecur(Node** ppNode, int delValue)
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
int Tree::minRecur(Node* pNode)
{
	while (pNode->left != NULL)
	{
		pNode = pNode->left;
	}
	return pNode->value;
};
void Tree::printRecur(Node* pNode)
{
	if (pNode != NULL)
	{
		printRecur(pNode->left);
		std::cout << pNode->countLeft << ":" << pNode->value << ' ';
		printRecur(pNode->right);
	}
}
bool Tree::addRecur(Node** ppNode, int val)
{
	if (*ppNode == NULL)
	{
		*ppNode = new Node(val);
		return true;
	}
	else if (val < (*ppNode)->value)
		return addRecur(&((*ppNode)->left), val);
	else if (val >(*ppNode)->value)
		return addRecur(&((*ppNode)->right), val);
	return false;
};
void Tree::setAllLeftCount()
{
	Node* pNode = root;
	while (pNode->left != NULL)
	{
		pNode = pNode->left;
	}
	int i = 0;
	setLeftCount(pNode,i);
}
void Tree::setLeftCount(Node* pNode, int& i)
{
	Node* current = root;
	Node* successor = NULL;
	while (current != NULL)
	{
		if (current->value > pNode->value)
		{
			successor = current;
			current = current->left;
		}
		else
			current = current->right;
	}
	pNode->countLeft=i;
	i++;
	if (successor == NULL)
		return;
	setLeftCount(successor,i);
};
int& Tree::operator[](int n)
{
	Node* pNode = root;
	while (n != pNode->countLeft)
	{
		if (pNode->countLeft > n)
			pNode = pNode->left;
		else
			pNode = pNode->right;
	}
	// std::cout << pNode->value;
	return pNode->value;
};
