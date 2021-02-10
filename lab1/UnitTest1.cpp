#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept>
#include "../Lab1_Koryagin/class_n_func.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace UnitTest1
{
	TEST_CLASS(HeaderTests)
	{
	public:
		List* lst;
		List* lst2;
		TEST_METHOD_INITIALIZE(setUp)
		{
			lst = new List();
			lst2 = new List();
		}
		TEST_METHOD_CLEANUP(cleanUP)
		{
			delete lst;
			delete lst2;
		}

		TEST_METHOD(correct_push_back)
		{
			lst->push_back(1);
			lst2->push_back(2);
			lst->push_back(3);
			lst2->push_back(4);
			lst->push_back(5);
			lst2->push_back(6);
			Assert::AreEqual(lst->get_size(), lst2->get_size());
		}

		TEST_METHOD(correct_push_front)
		{
			lst->push_front(3);
			lst2->push_front(1);
			lst->push_front(1);
			lst2->push_front(2);
			lst->push_front(3);
			lst2->push_front(4);
			lst->push_front(5);
			lst2->push_front(6);
			Assert::AreEqual(lst->get_size(), lst2->get_size());
		}

		TEST_METHOD(correct_pop_back)
		{
			lst->push_back(1);
			lst->push_back(2);
			lst->push_back(3);
			lst2->push_back(1);
			lst2->push_back(2);
			lst->pop_back();
			Assert::AreEqual(lst->get_size(), lst2->get_size());
		}

		TEST_METHOD(correct_pop_front)
		{
			lst->push_back(3);
			lst->push_back(1);
			lst->push_back(2);
			lst2->push_back(1);
			lst2->push_back(2);
			lst->pop_front();
			Assert::AreEqual(lst->get_size(), lst2->get_size());
		}

		TEST_METHOD(correct_insert)
		{
			size_t size = 3;
			lst->push_front(1);
			lst->push_front(3);
			lst->insert(1, 2);
			Assert::AreEqual(lst->get_size(), size);
		}

		TEST_METHOD(correct_index_at)
		{
			lst->push_back(1);
			lst->push_back(2);
			lst->push_back(3);
			lst->push_back(4);
			lst->push_back(5);
			lst->push_back(6);
			Assert::AreEqual(lst->at(1), 2);
		}

		TEST_METHOD(correct_remove)
		{
			size_t size = 4;
			lst->push_front(1);
			lst->push_front(2);
			lst->push_back(3);
			lst->push_back(4);
			lst->push_back(5);
			lst->remove(1);
			Assert::AreEqual(lst->get_size(), size);
		}

		TEST_METHOD(correct_get_size)
		{
			lst->push_back(1);
			lst->push_back(2);
			lst->push_back(3);
			size_t size = 3;
			Assert::AreEqual(lst->get_size(), size);
		}

		TEST_METHOD(correct_clear)
		{
			size_t size = 0;
			lst->push_front(1);
			lst->push_front(2);
			lst->push_front(3);
			lst->clear();
			Assert::AreEqual(lst->get_size(), size);
		}

		TEST_METHOD(correct_set)
		{
			size_t size = 3;
			lst->push_front(1);
			lst->push_front(2);
			lst->push_front(3);
			lst->set(1, 3);
			Assert::AreEqual(lst->get_size(), size);
		}

		TEST_METHOD(correct_isEmpty)
		{
			lst->push_front(1);
			lst->push_front(2);
			lst->push_front(3);
			Assert::AreEqual(lst->isEmpty(), true);

		}

		TEST_METHOD(correct_push_front_l1)
		{
			size_t size = 5;
			lst->push_back(1);
			lst->push_back(2);
			lst2->push_back(3);
			lst2->push_back(4);
			lst2->push_back(5);
			lst->push_front_l(*lst2);
			Assert::AreEqual(lst->get_size(), size);
		}

	};
}
