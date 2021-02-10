#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;
class Node
{
	int nmbr;
	class Node* next;
	friend class List;
};
class List
{
	Node* head;
	Node* last;
	int count = 0;
public:
	List() 
	{ 
		head = NULL;
		last = head;
	}
	~List()
	{
		head = NULL;
		last = NULL;
		delete head;
		delete last;
	}
	void push_front(int num)
	{
		Node* elem = new Node();
		elem->nmbr = num;
		count++;
		if (head == NULL)
		{
			elem->next = NULL;
			head = elem;
			last = head;
		}
		else
		{
			elem->next = head;
			head = elem;
		}
	}
	void insert(int index, int num)
	{
		if (index < 0)
		{
			throw underflow_error("Index is lower than a minimum size!");
		}
		if (index > count)
		{
			throw underflow_error("Index is higher than a maximum size!");
		}
		Node* elem = new Node();
		Node* tmpr;
		elem->nmbr = num;
		count++;
		tmpr = head;
		if (index == 0)
		{
			if (head == NULL)
			{
				elem->next = NULL;
				head = elem;
				last = head;
			}
			else
			{
				elem->next = head;
				head = elem;
			}
		}
		else
		{
			for (int i = 0; i < index - 1; i++)
			{
				tmpr = tmpr->next;
			}
			elem->next = tmpr->next;
			tmpr->next = elem;
		}
		tmpr = NULL;
		delete tmpr;
	}
	void push_back(int num)
	{
		Node* elem = new Node();
		Node* tmpr;
		elem->nmbr = num;
		count++;
		if (head == NULL)
		{
			elem->next = NULL;
			head = elem;
			last = head;
		}
		else
		{
			tmpr = head;
			while (tmpr->next != NULL)
			{
				tmpr = tmpr->next;
			}
			elem->next = NULL;
			tmpr->next = elem;
			last = tmpr;
		}
		tmpr = NULL;
		delete tmpr;
	}
	void print_to_console()
	{
		Node* tmpr;
		tmpr = head;
		cout << "|";
		while (tmpr != NULL)
		{
			cout << tmpr->nmbr << "|";
			tmpr = tmpr->next;
		}
		if (tmpr == NULL)
		{
			cout << "NULL|";
		}
		cout << endl;
		tmpr = NULL;
		delete tmpr;
	}
	void pop_back()
	{
		if (count == 0)
			throw underflow_error("List was already empty!");
		last = head;
		Node* tmpr;
		tmpr = head;
		while (last->next != NULL)
		{
			last = last->next;
		}
		if (tmpr != last)
		{
			while (tmpr->next != last)
			{
				tmpr = tmpr->next;
			}
			last->next = NULL;
			delete last;
			tmpr->next = NULL;
			last = tmpr;
		}
		else
		{
			delete tmpr;
		}
		count--;
		tmpr = NULL;
		delete tmpr;
	}
	void remove(int index)
	{
		Node* tmpr;
		if (count > 0)
		{
			tmpr = head;
			if (index == 0)
			{
				tmpr = head;
				head = head->next;
				tmpr->next = NULL;
				delete tmpr;
			}
			else if (index == count - 1)
			{
				if (count == 0)
					return;
				last = head;
				tmpr = head;
				while (last->next != NULL)
				{
					last = last->next;
				}
				if (tmpr != last)
				{
					while (tmpr->next != last)
					{
						tmpr = tmpr->next;
					}
					last->next = NULL;
					delete last;
					tmpr->next = NULL;
					last = tmpr;
				}
				else
				{
					delete tmpr;
				}
			}
			else
			{
				for (int i = 0; i < index; i++)
				{
					tmpr = tmpr->next;
				}
				last = tmpr->next;
				tmpr->next = last;
				delete last;
			}
			count--;
		}
		tmpr = NULL;
		delete tmpr;
	}
	int at(int index)
	{
		if (index > count || count < 0 || index < 0)
			throw underflow_error("Index size or list size are lower or higher than acceptable values!");
		last = head;
		for (int i = 0; i < index; i++)
		{
			last = last->next;
		}
		return last->nmbr;
	}
	void set(int index, int value)
	{
		if (index > count || count < 0 || index < 0)
			throw underflow_error("Index size or list size are lower or higher than acceptable values!");
		Node* tmpr;
		tmpr = head;
		for (int i = 0; i < index; i++)
		{
			tmpr = tmpr->next;
		}
		Node* elem = new Node();
		elem->nmbr = value;
		tmpr->nmbr = elem->nmbr;
		elem->next = NULL;
		delete elem;
		tmpr = NULL;
		delete tmpr;
	}
	void pop_front()
	{
		if (count == 0)
			throw underflow_error("List was already empty!");
		Node* tmpr;
		tmpr = head;
		head = head->next;
		tmpr->next = NULL;
		delete tmpr;
		count--;
	}
	size_t get_size()
	{
		return count;
	}
	bool isEmpty()
	{
		return (count != 0);
	}
	void clear()
	{
		Node* tmpr;
		for (int j = 0; j < count; j++)
		{
			tmpr = head;
			head = head->next;
			tmpr->next = NULL;
			delete tmpr;
		}
		count = 0;
		tmpr = NULL;
		delete tmpr;
	}
	void push_front_l(List l1)
	{
		Node* tmpr;
		int temp = l1.count;
		count = l1.count + count;
		if (head != NULL)
		{
			last = head;
			while (last->next != NULL)
			{
				last = last->next;
			}
		}
		l1.last = l1.head;
		while (temp != 0)
		{
			Node* elem = new Node();
			elem->nmbr = 0;
			if (head == NULL)
			{
				elem->next = NULL;
				head = elem;
				last = head;
				last->nmbr = l1.last->nmbr;
				l1.last = l1.last->next;
			}
			else
			{
				
				tmpr = head;
				while (tmpr->next != NULL)
				{
					tmpr = tmpr->next;
				}
				elem->next = NULL;
				tmpr->next = elem;
				last = elem;
				last->nmbr = l1.last->nmbr;
				l1.last = l1.last->next;
			}
			temp--;
		}
		tmpr = NULL;
		delete tmpr;
	}
};