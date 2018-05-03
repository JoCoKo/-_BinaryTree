#pragma once
#include <iostream>
#include <stdlib.h>

class Tree;
class Node
{
friend Tree;
public:
	Node(int val):value(val), left(NULL), right(NULL) {};
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
	Tree(int);
	bool add(int);
	void print();
	void deleteVal(int);
	void setAllLeftCount();
	int& operator[] (int);

private:
	void setLeftCount(Node*, int&);
	void deleteRecur(Node**, int);
	int minRecur(Node*);
	void printRecur(Node*);
	bool addRecur(Node**, int);
	Node* root;
};