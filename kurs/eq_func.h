#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <stdexcept>
using namespace std;
class Equation
{
	char smbl;
	double amount;
	class Equation* stack;
	class Equation* go;
public:
	bool indicator;
	string equation;
	Equation() //class constructor
	{
		stack = NULL;
		indicator = false;
		go = NULL;
	}
	~Equation() //class destructor
	{
		go = NULL;
		delete stack;
		delete go;
	}
	void fill_eq() //the function for entering a string with an equation
	{
		cout << "----------------------------------" << endl;
		cout << "|Enter the equation in infix form|\n";
		cout << "----------------------------------" << endl;
		getline(cin, equation);
	}
	bool check_wr() //the function checks the correctness of the entered equation
	{
		string interim;
		interim.empty();
		for (int i = 0; i < equation.size(); i++)
		{
			while (equation[i] != ' ')
			{
				interim += equation[i];
				i++;
				if (i == equation.size())
				{
					break;
				}
			}
		}
		if (Srch_oprtr(interim[0]) && interim[0] != '-' && interim[0] != '(')
		{
			cout << "----------------------------" << endl;
			cout << "Wrong symbol or operation: " << interim[1] << endl << endl;
			cout << "----------------------------" << endl;
			return true;
		}
		if (interim[0] == '-' && !Srch_oprnd(interim[1]))
		{
			cout << "----------------------------" << endl;
			cout << "Wrong symbol or operation: " << interim[2] << endl << endl;
			cout << "----------------------------" << endl;
			return true;
		}
		for (int i = 0; i < interim.size(); i++)
		{
			if (Srch_oprtr(interim[i]) && interim[i] != '(' && interim[i] != ')')
			{
				if (Srch_oprtr(interim[i + 1]) && interim[i + 1] != '-' && interim[i + 1] != '(' && interim[i + 1] != ')')
				{
					cout << "----------------------------" << endl;
					cout << "Wrong symbol or operation: " << interim[i] << endl << endl;
					cout << "----------------------------" << endl;
					return true;
				}
				if (Srch_oprtr(interim[i + 1]) && interim[i + 1] == '-' && (!Srch_oprnd(interim[i + 2]) && interim[i + 2] != 'e' && (interim[i + 2] != 'p' && interim[i + 3] != 'i')))
				{
					cout << "----------------------------" << endl;
					cout << "Wrong symbol or operation: " << interim[i] << endl << endl;
					cout << "----------------------------" << endl;
					return true;
				}
				if (i + 1 == interim.size() && interim[i] != '(' && interim[i] != ')')
				{
					cout << "----------------------------" << endl;
					cout << "Wrong symbol or operation: " << interim[i] << endl << endl;
					cout << "----------------------------" << endl;
					return true;
				}
				if (Srch_oprnd(interim[i + 1]) && i > 0 && Srch_oprnd(interim[i - 1]))
				{
					interim.insert(i + 1, " ");
				}
				if (interim[i] == '-' && i > 0 && Srch_oprnd(interim[i + 1]) && (interim[i - 1] == '(' || interim[i - 1] == ')'))
				{
					interim.insert(i + 1, " ");
				}
			}
			if (i + 1 == interim.size() && interim[i] == '(')
			{
				cout << "----------------------------" << endl;
				cout << "Wrong symbol or operation: " << interim[i] << endl << endl;
				cout << "----------------------------" << endl;
				return true;
			}
			if (Srch_oprnd(interim[i]))
			{
				while (interim[i] == '.' || Srch_oprnd(interim[i]))
				{
					if (i == interim.size())
					{
						break;
					}
					if (interim[i] == '.' && interim[i + 1] == '.')
					{
						cout << "----------------------------" << endl;
						cout << "Wrong symbol or operation: " << interim[i] << endl << endl;
						cout << "----------------------------" << endl;
						return true;
					}
					i++;
				}
				if (!Srch_oprtr(interim[i]) && interim[i] != ' ')
				{
					if (i < interim.size())
					{
						cout << "----------------------------" << endl;
						cout << "Wrong symbol or operation: " << interim[i] << endl << endl;
						cout << "----------------------------" << endl;
						return true;
					}
				}
				i--;
			}
		}
		equation.empty();
		equation = interim;
		return false;
	}
	bool Srch_oprtr(char val) //the search function of the operator
	{
		switch (val)
		{
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
		case ')':
		case '(':
			return true;
			break;
		default:
			return false;
		}
	}
	bool Srch_oprnd(char val) //the search function of the operand
	{
		switch (val)
		{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			return true;
		default:
			return false;
		}
	}
	int take_prior(char val) //the search function of operator precedence
	{
		switch (val)
		{
		case'+':
			return 1;
			break;
		case'-':
			return 1;
			break;
		case'*':
			return 2;
			break;
		case'/':
			return 2;
			break;
		case'^':
			return 3;
			break;
		case')':
			return 0;
			break;
		case'(':
			return 0;
			break;
		}
	}
	void inf_to_post();
	double task_count();
};
