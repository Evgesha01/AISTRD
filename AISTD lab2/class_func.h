#pragma once
#include <iostream>
#include <cstdlib>
#include <stdexcept>
using namespace std;
class Array
{
	int* array;
	int length;

public:
	Array(int ar_len) // constructor
	{
		array = new int[ar_len];
		length = ar_len;
	}
	~Array() // destructor
	{
		delete[] array;
	}
	void randfilling() //Array filling
	{
		int temp;
		for (int i = 0; i < length; i++)
		{
			temp = rand() % 2;
			if (temp == 0)
			{
				array[i] = (rand() % 10) * (-1);
			}
			else
				array[i] = rand() % 10;
		}
	}
	int getValue(int ind) //Getting array`s value
	{
		return array[ind];
	}
	int cor() // Bogo sort`s part
	{
		int len = length;
		while (--len > 0)
			if (array[len - 1] > array[len])
				return 0;
		return 1;
	}
	void BogoSort() //Bogo sort
	{
		while (!cor())
		{
			for (int i = 0; i < length; ++i)
				swap(array[i], array[(rand() % length)]);
		}
	}
	void quicksort(int start, int end) //QuickSort
	{
		int mid, counter;
		int start_2 = start, end_2 = end;
		mid = array[(start_2 + end_2) / 2];
		do
		{
			while (array[start_2] < mid) start_2++;
			while (array[end_2] > mid) end_2--;
			if (start_2 <= end_2)
			{
				counter = array[start_2];
				array[start_2] = array[end_2];
				array[end_2] = counter;
				start_2++;
				end_2--;
			}
		} while (start_2 < end_2);
		if (start < end_2) quicksort(start, end_2);
		if (start_2 < end) quicksort(start_2, end);
	}
	void BinarySearch(int key) //BinarySearch
	{
		bool flag = false;
		int lt = 0;
		int rt = length - 1;
		int mid;
		while ((lt <= rt) && (flag != true))
		{
			mid = (lt + rt) / 2;
			if (array[mid] == key) flag = true;
			if (array[mid] > key) rt = mid - 1;
			else lt = mid + 1;
		}
		if (flag)
		{
			cout << "Index " << key << " is equal to: " << mid << endl;
		}
		else
		{
			throw domain_error("There is no such an element in this array!\n");
		}
	}
	void InsertionSort() //InsertionSort
	{
		int flag = 0, temp = 0;
		for (int i = 0; i < length - 1; i++)
		{
			flag = i + 1;
			temp = array[flag];
			for (int j = i + 1; j > 0; j--)
			{
				if (temp < array[j - 1])
				{
					array[j] = array[j - 1];
					flag = j - 1;
				}
			}
			array[flag] = temp;
		}
	}
	void print_to_console() //Printing the array
	{
		cout << "|";
		for (int i = 0; i < length; i++)
		{
			cout << getValue(i) << "|";
		}
		cout << endl;
	}
	void filling(int ind, int elem) //Manually filling the array
	{
		array[ind] = elem;
	}
};
class Char_Array
{
	char* array;
	int length;

public:
	Char_Array(int ar_len) // constructor
	{
		array = new char[ar_len];
		length = ar_len;
	}
	~Char_Array() // destructor
	{
		delete[] array;
	}
	void filling(int ind, char elem) //Filling the char array
	{
		array[ind] = elem + '0';
	}
	void print_to_console() //Printing the char array
	{
		cout << "|";
		for (int i = 0; i < length; i++)
		{
			cout << getValue(i) << "|";
		}
		cout << endl;
	}
	void CountingSort() //Counting sort
	{
		int* output = new int[length];
		int* numbers = new int[length];
		int max = 0;
		int temp = 0;
		int temp2 = 0;
		int temp3 = 0;
		for (int i = 1; i < length; i++)
		{
			temp = array[i] - '0';
			if (temp > max)
			{
				max = temp;
			}
		}
		for (int i = 0; i <= max; ++i)
		{
			numbers[i] = 0;
		}
		for (int i = 0; i < length; i++)
		{
			numbers[array[i] - '0']++;
		}
		for (int i = 1; i <= max; i++)
		{
			numbers[i] += numbers[i - 1];
		}
		for (int i = length - 1; i >= 0; i--)
		{
			output[numbers[array[i] - '0'] - 1] = array[i] - '0';
			numbers[array[i] - '0']--;
		}
		for (int i = 0; i < length; i++)
		{
			array[i] = output[i] + '0';
		}
	}
	char getValue(int ind) //Getting the value of array
	{
		return array[ind];
	}
	void randfilling() // Random filling of the char array
	{
		for (int i = 0; i < length; i++)
		{
			array[i] = rand() % 10 + '0';
		}
	}
};