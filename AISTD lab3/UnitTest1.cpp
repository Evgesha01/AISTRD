#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept>
#include "../Lab3Aistrd_Koryagin/func_n_class.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace UnitTest3
{
	TEST_CLASS(UnitTest3)
	{
	public:
		TEST_METHOD(insert)
		{
			Tree* tree = new Tree();
			Tree* tree2 = new Tree();
			tree->get_root(10);
			tree->insert(5);
			tree->insert(15);
			tree->insert(100);
			tree->insert(20);

			tree2->get_root(10);
			tree2->insert(5);
			tree2->insert(15);
			tree2->insert(100);
			tree2->insert(20);

			tree->Queue();
			tree2->Queue();
			Iterator* iter;
			iter = tree->bft_creator();
			Iterator* iter2;
			iter2 = tree2->bft_creator();
			for (int i = 0; i < 4; i++)
			{
				Assert::AreEqual(iter2->next(), iter->next());
			}
			tree->deleting_tree();
			tree2->deleting_tree();
		}

		TEST_METHOD(remove)
		{
			Tree* tree = new Tree();
			Tree* tree2 = new Tree();
			tree->get_root(10);
			tree->insert(5);
			tree->insert(15);
			tree->insert(100);
			tree->insert(20);
			tree->remove(20);

			tree2->get_root(10);
			tree2->insert(5);
			tree2->insert(15);
			tree2->insert(100);

			tree->Queue();
			tree2->Queue();
			Iterator* iter;
			iter = tree->bft_creator();
			Iterator* iter2;
			iter2 = tree2->bft_creator();
			for (int i = 0; i < 3; i++)
			{
				Assert::AreEqual(iter2->next(), iter->next());
			}
			tree->deleting_tree();
			tree2->deleting_tree();
		}

		TEST_METHOD(contains)
		{
			Tree* tree = new Tree();
			tree->get_root(10);
			tree->insert(5);
			tree->insert(15);
			tree->insert(100);
			tree->insert(20);

			Assert::AreEqual(true, tree->contains(15));
		}
	};
}