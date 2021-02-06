#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept>
#include "../Lab2Aistrd_Koryagin/class_func.h"
#include "../Lab2Aistrd_Koryagin/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		int length;

		TEST_METHOD_INITIALIZE(setUp)
		{
			length = 10;
		}

		TEST_METHOD_CLEANUP(cleanUP)
		{
			length = 0;
		}

		TEST_METHOD(quick_sort)
		{
			Array test(length);
			int fill_test[10] = { 2,3,5,7,10,14,17,23,52,100 };

			for (int i = 0; i < length; i++)
			{
				test.filling(i, fill_test[i]);
			}

			Array arr(length);
			int arr_test[10] = { 7,3,10,5,2,17,14,100,23,52 };

			for (int i = 0; i < length; i++)
			{
				arr.filling(i, arr_test[i]);
			}

			arr.quicksort(0, 9);

			for (int i = 0; i < length; i++)
			{
				Assert::AreEqual(arr.getValue(i), test.getValue(i));
			}

		}

		TEST_METHOD(insertion_sort)
		{
			Array test(length);
			int fill_test[10] = { 2,3,5,7,10,14,17,23,52,100 };

			for (int i = 0; i < length; i++)
			{
				test.filling(i, fill_test[i]);
			}

			Array arr(length);
			int arr_test[10] = { 7,3,10,5,2,17,14,100,23,52 };

			for (int i = 0; i < length; i++)
			{
				arr.filling(i, arr_test[i]);
			}

			arr.InsertionSort();

			for (int i = 0; i < length; i++)
			{
				Assert::AreEqual(arr.getValue(i), test.getValue(i));
			}

		}

		TEST_METHOD(bogo_sort)
		{
			Array test(length);
			int fill_test[10] = { 2,3,5,7,10,14,17,23,52,100 };

			for (int i = 0; i < length; i++)
			{
				test.filling(i, fill_test[i]);
			}

			Array arr(length);
			int arr_test[10] = { 7,3,10,5,2,17,14,100,23,52 };

			for (int i = 0; i < length; i++)
			{
				arr.filling(i, arr_test[i]);
			}

			arr.BogoSort();

			for (int i = 0; i < length; i++)
			{
				Assert::AreEqual(arr.getValue(i), test.getValue(i));
			}

		}

		TEST_METHOD(counting_sort)
		{
			Char_Array test(length);
			int fill_test[10] = { 1,2,3,4,5,6,7,8,9,10 };

			for (int i = 0; i < length; i++)
			{
				test.filling(i, fill_test[i] + '0');
			}

			Char_Array arr(length);
			int arr_test[10] = { 2,1,3,4,5,8,9,7,6,10 };

			for (int i = 0; i < length; i++)
			{
				arr.filling(i, arr_test[i] + '0');
			}

			arr.CountingSort();

			for (int i = 0; i < length; i++)
			{
				Assert::AreEqual(arr.getValue(i), test.getValue(i));
			}

		}

	};
}

