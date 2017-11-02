#include <iostream>
#include "Tree.h"

using namespace std;

int main()
{
	Tree* firstTree = new Tree(10);
	firstTree->print();
	firstTree->add(5);
	firstTree->print();
	firstTree->add(20);
	firstTree->print();
	firstTree->add(0);
	firstTree->print();
	firstTree->add(40);
	firstTree->print();
	firstTree->add(-10);
	firstTree->print();
	firstTree->add(9000);
	firstTree->print();
	firstTree->add(20);
	firstTree->print();
	firstTree->deleteVal(20);
	firstTree->print();
	getchar();
	return 0;
}
