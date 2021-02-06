#include "func_n_class.h"
#include <iomanip>
#include <iostream>
#include <locale>
using namespace std;
int main()
{
	Tree* tree = new Tree;
	tree->get_root(100);
	tree->insert(50);
	tree->insert(101);
	tree->insert(110);
	tree->insert(99);
	tree->insert(105);
	tree->insert(7);
	tree->insert(32);
	tree->insert(61);
	tree->insert(12);
	tree->insert(51);
	if (tree->contains(51) == true)
		cout << "Element " << 51 << " is contained in the tree.\n";
	else
		cout << "Element " << 51 << " is not contained in the tree.\n";
	if (tree->contains(500) == true)
		cout << "Element " << 500 << " is contained in the tree.\n";
	else
		cout << "Element " << 500 << " is not contained in the tree.\n";
	if (tree->contains(50) == true)
	{
		tree->remove(51);
		cout << "Element " << 51 << " removed successfully.\n";
	}
	else
		cout << "Element " << 51 << " is not contained in the tree.\n";
	if (tree->contains(500) == true)
		tree->remove(500);
	else
		cout << "Element " << 500 << " is not contained in the tree.\n";
	tree->Queue();
	tree->cout_bft();
	tree->Stack();
	tree->cout_dft();
	tree->deleting_tree();
}