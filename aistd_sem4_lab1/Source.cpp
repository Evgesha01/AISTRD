#include "RBTree.h"
#include <iomanip>
#include <iostream>
#include <locale>
using namespace std;
int main()
{
	RBTree* tree = new RBTree;
	tree->insert(15, "one");
	tree->insert(20, "two");
	tree->insert(25, "three");
	tree->get_keys();
	tree->get_values();
	tree->print();
	tree->remove(5);
	tree->remove(10);
	tree->remove(15);
	tree->get_keys();
	tree->get_values();
	tree->print();
	tree->clear();
}
