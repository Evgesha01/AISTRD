#pragma once
#include <iomanip>
#include <iostream>
#include <locale>
using namespace std;
class Iterator
{
public:
	virtual int next() = 0;
	virtual bool has_next() = 0;
};
class BinaryTree
{
	int key;
	class BinaryTree* left;
	class BinaryTree* right;
	class BinaryTree* next;
	friend class Tree;
	friend class Iterator;
public:
	BinaryTree()
	{
		left = NULL;
		right = NULL;
		next = NULL;
	}
};
class Tree
{
	class BinaryTree* cur;
	class BinaryTree* root;
	class BinaryTree* go;
	int size = 0;
	Iterator* bft_it;
	Iterator* dft_it;
	friend class Iterator;
public:
	void get_root(int key)
	{
		if (root == NULL)
		{
			BinaryTree* el = new BinaryTree;
			el->key = key;
			root = el;
			root->left = NULL;
			root->right = NULL;
		}
	}
	void insert(int key)
	{
		cur = root;
		if (key == cur->key)
		{
			cout << "Error! This key is already contained in the tree!\n";
			return;
		}
	r_n:
		while (cur->left != NULL && cur->right != NULL)
		{
			if (key < cur->key)
			{
				cur = cur->left;
			}
			else if (key > cur->key)
			{
				cur = cur->right;
			}
			else
			{
				cout << "Error! This key is already contained in the tree!\n";
				return;
			}
		}
		if (key < cur->key)
		{
			if (cur->left == NULL)
			{
				BinaryTree* el = new BinaryTree;
				el->key = key;
				el->left = NULL;
				el->right = NULL;
				cur->left = el;
			}
			else
			{
				cur = cur->left;
				goto r_n;
			}
		}
		else if (key > cur->key)
		{
			if (cur->right == NULL)
			{
				BinaryTree* el = new BinaryTree;
				el->key = key;
				el->left = NULL;
				el->right = NULL;
				cur->right = el;
			}
			else
			{
				cur = cur->right;
				goto r_n;
			}
		}
		else
		{
			if (key == cur->key)
			{
				cout << "Error! This key is already contained in the tree!\n";
				return;
			}
		}
	}
	bool contains(int key)
	{
		cur = root;
		if (key == cur->key)
		{
			return true;
		}
	r_n:
		while (cur->left != NULL && cur->right != NULL)
		{
			if (key < cur->key)
			{
				cur = cur->left;
			}
			else if (key > cur->key)
			{
				cur = cur->right;
			}
			else
			{
				return true;
			}
		}
		if (key < cur->key)
		{
			if (cur->left == NULL)
			{
				return 0;
			}
			else
			{
				cur = cur->left;
				goto r_n;
			}
		}
		else if (key > cur->key)
		{
			if (cur->right == NULL)
			{
				return 0;
			}
			else
			{
				cur = cur->right;
				goto r_n;
			}
		}
		else
		{
			if (key == cur->key)
			{
				return true;
			}
		}
	}
	void remove(int key)
	{
		cur = root;
		while (true)
		{
			if (key < cur->key && cur->left->key != key)
			{
				cur = cur->left;
			}
			else if (key > cur->key && cur->right->key != key)
			{
				cur = cur->right;
			}
			else
			{
				if (cur->key == key)
				{
					if (cur->left == NULL && cur->right == NULL)
					{
						cur = NULL;
						root = NULL;
					}
					else if (cur->left == NULL && cur->right != NULL)
					{
						cur = cur->right;
					}
					else if (cur->left != NULL && cur->right == NULL)
					{
						cur = cur->left;
					}
					else
					{
						BinaryTree* pt;
						pt = cur;
						pt = pt->right;
						if (pt->left == NULL)
						{
							cur->key = pt->key;
							cur->right = pt->right;
							return;
						}
						BinaryTree* pt1;
						pt1 = cur;
						pt1 = pt1->right;
						while (pt1->left != NULL)
							pt1 = pt1->left;
						while (pt->left != pt1)
							pt = pt->left;
						if (pt1->right == NULL)
						{
							cur->key = pt1->key;
							pt->left = NULL;
						}
						else
						{
							cur->key = pt1->key;
							pt->left = pt1->right;
						}
						pt = NULL;
						pt1 = NULL;
						delete pt, pt1;
					}
					return;
				}
				else if (cur->right != NULL && cur->right->key == key)
				{
					BinaryTree* pt;
					pt = cur;
					pt = pt->right;
					if (pt->left == NULL && pt->right == NULL)
					{
						cur->right = NULL;
					}
					else if (pt->left == NULL && pt->right != NULL)
					{
						cur->right = pt->right;
					}
					else if (pt->left != NULL && pt->right == NULL)
					{
						cur->right = pt->left;
					}
					else
					{
						pt = pt->right;
						if (pt->left == NULL)
						{
							cur->right->key = pt->key;
							cur->right->right = pt->right;
							pt = NULL;
							delete pt;
							return;
						}
						BinaryTree* pt1;
						pt1 = pt;
						while (pt1->left != NULL)
							pt1 = pt1->left;
						while (pt->left != pt1)
							pt = pt->left;
						if (pt1->right == NULL)
						{
							cur->right->key = pt1->key;
							pt->left = NULL;
						}
						else
						{
							cur->right->key = pt1->key;
							pt->left = pt1->right;
						}
					}
					pt = NULL;
					delete pt;
					return;
				}
				else
				{
					BinaryTree* pt;
					pt = cur;
					pt = pt->left;
					if (pt->left == NULL && pt->right == NULL)
					{
						cur->left = NULL;
					}
					else if (pt->left == NULL && pt->right != NULL)
					{
						cur->left = pt->right;
					}
					else if (pt->left != NULL && pt->right == NULL)
					{
						cur->left = pt->left;
					}
					else
					{
						pt = pt->right;
						if (pt->left == NULL)
						{
							cur->left->key = pt->key;
							cur->left->right = pt->right;
							pt = NULL;
							delete pt;
							return;
						}
						BinaryTree* pt1;
						pt1 = pt;
						while (pt1->left != NULL)
							pt1 = pt1->left;
						while (pt->left != pt1)
							pt = pt->left;
						if (pt1->right == NULL)
						{
							cur->left->key = pt1->key;
							pt->left = NULL;
						}
						else
						{
							cur->left->key = pt1->key;
							pt->left = pt1->right;
						}
						pt = NULL;
						pt1 = NULL;
						delete pt, pt1;
					}
					return;
				}
			}
		}
	}
	void Queue()
	{
		BinaryTree* mrk;
		BinaryTree* fnsh;
		go = root;
		if (go == NULL)
		{
			return;
		}
		go->next = NULL;
		fnsh = go;
		mrk = go;
		if (mrk->left != NULL)
		{
			fnsh->next = mrk->left;
			fnsh = fnsh->next;
			fnsh->next = NULL;
		}
		if (mrk->right != NULL)
		{
			fnsh->next = mrk->right;
			fnsh = fnsh->next;
			fnsh->next = NULL;
		}
		mrk = mrk->next;
		while (true)
		{
			if (mrk->left != NULL)
			{
				fnsh->next = mrk->left;
				fnsh = fnsh->next;
				fnsh->next = NULL;
			}
			if (mrk->right != NULL)
			{
				fnsh->next = mrk->right;
				fnsh = fnsh->next;
				fnsh->next = NULL;
			}
			if (mrk->left == NULL && mrk->right == NULL && mrk->next == NULL)
			{
				break;
			}
			mrk = mrk->next;
		}
		mrk = go;
		while (mrk->next != NULL)
		{
			size++;
			mrk = mrk->next;
		}
		mrk = NULL;
		fnsh = NULL;
		delete mrk;
		delete fnsh;
		return;
	}
	void Stack()
	{
		BinaryTree* stack;
		BinaryTree* parent;
		BinaryTree* fnsh;
		BinaryTree* mrk;
		stack = NULL;
		go = root;
		fnsh = go;
		mrk = root;
		fnsh->next = NULL;
		if (mrk->right != NULL)
		{
			stack = mrk->right;
			stack->next = NULL;
		}
		if (mrk->left != NULL)
		{
			mrk = mrk->left;
			fnsh->next = mrk;
			fnsh = fnsh->next;
		}
		while (true)
		{
			if (mrk->right != NULL)
			{
				if (stack == NULL)
				{
					stack = mrk->right;
					stack->next = NULL;
				}
				else
				{
					parent = mrk->right;
					parent->next = stack;
					stack = parent;
				}
			}
			if (mrk->left != NULL)
			{
				mrk = mrk->left;
				fnsh->next = mrk;
				fnsh = fnsh->next;
			}
			else if (stack != NULL)
			{
				mrk = stack;
				fnsh->next = mrk;
				fnsh = fnsh->next;
				stack = stack->next;
			}
			else
			{
				break;
			}
		}
		stack = NULL;
		parent = NULL;
		fnsh = NULL;
		mrk = NULL;
		delete stack;
		delete parent;
		delete fnsh;
		delete mrk;
	}
	void deleting_tree()
	{
		Queue();
		while (go != NULL)
		{
			BinaryTree* dltr;
			dltr = go;
			dltr->left = NULL;
			dltr->right = NULL;
			go = go->next;
			delete dltr;
		}
		cout << "The tree was cleared." << endl;
	}
	void cout_bft()
	{
		cout << "\nbft_iteration:\n";
		Iterator* iter;
		iter = bft_creator();
		cout << "|" << go->key << "|";
		while (iter->has_next())
		cout << iter->next() << "|";
		cout << endl;
		iter = NULL;
		delete iter;
	}
	void cout_dft()
	{
		cout << "\ndft_iteration:\n";
		Iterator* iter;
		iter = dft_iterator();
		cout << "|" << go->key << "|";
		while (size != 0 && iter->has_next())
		{
			cout << iter->next() << "|";
			size--;
		}
		cout << endl;
		iter = NULL;
		delete iter;
	}
	class bft_iter : public Iterator
	{
		class BinaryTree* begin;
	public:
		bft_iter(BinaryTree* go)
		{
			begin = go;
		}
		int next() override
		{
			if (!has_next())
				throw out_of_range("no more elements\n");
			if (begin->next != NULL)
			{
				begin = begin->next;
			}
			return begin->key;
		}
		bool has_next() override
		{
			if (begin->next == NULL)
			{
				return false;
			}
			else return true;
		}
		~bft_iter()
		{
			delete begin;
		}
	};
	class dft_iter : public Iterator
	{
		class BinaryTree* begin;
	public:
		dft_iter(BinaryTree* go)
		{
			begin = go;
		}
		int next() override
		{
			if (!has_next())
				throw out_of_range("no more elements\n");
			if (begin->next != NULL)
			{
				begin = begin->next;
			}
			return begin->key;
		}
		bool has_next() override
		{
			if (begin->next == NULL)
			{
				return false;
			}
			else return true;
		}
		dft_iter()
		{
			delete begin;
		}
	};
	Iterator* bft_creator()
	{
		bft_it = new bft_iter(go);
		return bft_it;
	}
	Iterator* dft_iterator()
	{
		dft_it = new dft_iter(go);
		return dft_it;
	}
	Tree()
	{
		root = NULL;
		cur = NULL;
		go = NULL;
	}
	~Tree()
	{
		delete root;
		delete cur;
		delete go;
		delete bft_it;
		delete dft_it;
	}
};