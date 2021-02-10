#include "class_n_func.h"
#include <iostream>
#include <stdexcept>
using namespace std;
void main()
{
	List* list1 = new List;
	List* list2 = new List;
	list1->push_back(1);
	list1->push_back(2);
	list1->push_back(3);
	list2->push_back(4);
	list2->push_back(5);
	cout << "List 1: Element with choosen index: " << list1->at(1);
	cout << endl;
	cout << "List 2: Element with choosen index: " << list2->at(0);
	cout << endl;
	cout << "List 1 size: " << list1->get_size();
	cout << endl;
	cout << "List 2 size: " << list2->get_size();
	cout << endl;
	cout << "List 1: ";
	list1->print_to_console();
	cout << "List 2: ";
	list2->print_to_console();
	if (list1->isEmpty() == true)
	{
		cout << "List 1 is not empty.";
		cout << endl;
	}
	else
	{
		cout << "List 1 is empty.";
		cout << endl;
	}
	if (list2->isEmpty() == true)
	{
		cout << "List 2 is not empty.";
		cout << endl;
	}
	else
	{
		cout << "List 2 is empty.";
		cout << endl;
	}
	list1->push_front_l(*list2);
	list1->print_to_console();
	list2->clear();
	list1->clear();
	delete list1;
	list2->clear();
	delete list2;
	exit(0);
}