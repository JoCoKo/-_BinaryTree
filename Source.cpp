#include <iostream>
#include "Tree.h"

using namespace std;

int main()
{
	Tree* firstTree = new Tree(10);
	firstTree->add(5);
	firstTree->add(20);
	firstTree->add(0);
	firstTree->add(40);
	firstTree->add(-10);
	firstTree->add(9000);
	firstTree->add(20);

	firstTree->setAllLeftCount();

	firstTree->print();
/*	for (int i = 0; i < 8; i++)
	{
		firstTree[i];
	}*/
	firstTree[1];
	getchar();
	return 0;
}
