#include "class_func.h"
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <stdexcept>
using namespace std;
int main()
{
	/*for (int i = 0; i < 10; i++)
	{
		int length = 1000;
		Array ar(length);
		ar.randfilling();
		chrono::system_clock::time_point start = chrono::system_clock::now();
		ar.quicksort(0, length-1);
		chrono::system_clock::time_point end = chrono::system_clock::now();
		chrono::duration<double> sec = end - start;
		cout << "the execution time of the quick sort function is " << sec.count() << " seconds" << endl << endl;
	}*/
	Array ar(10);
	ar.randfilling();
	ar.print_to_console();
	cout << "Quick sort:" << endl;
	ar.quicksort(0, 9);
	ar.print_to_console();
	cout << endl;
	cout << "Binary search:" << endl;
	ar.BinarySearch(5);
	cout << endl;
	ar.randfilling();
	ar.print_to_console();
	cout << "Insertion sort:" << endl;
	ar.InsertionSort();
	ar.print_to_console();
	cout << endl;
	ar.randfilling();
	ar.print_to_console();
	cout << "Bogo sort:" << endl;
	ar.BogoSort();
	ar.print_to_console();
	cout << endl;
	Char_Array ch_ar(12);
	ch_ar.randfilling();
	ch_ar.print_to_console();
	cout << "Counting sort:" << endl;
	ch_ar.CountingSort();
	ch_ar.print_to_console();
	cout << endl;
}