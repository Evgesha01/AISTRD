#include <iostream>
#include <math.h>
#include <stdexcept>
#include "eq_func.h"
using namespace std;
void Equation::inf_to_post() //the function converts the equation to a postfix form
{
	string interim;
	interim.empty();
	Equation* prev;
	prev = stack;
	for (int j = 0; j < equation.size(); j++)
	{
		if (equation[j] == ' ')
			continue;
		else if (Srch_oprnd(equation[j]))
		{
			while (!Srch_oprtr(equation[j]) && equation[j] != ' ')
			{
				interim += equation[j];
				j++;
				if (j == equation.size())
				{
					break;
				}
			}
			interim += ' ';
			j--;
		}
		else if (Srch_oprtr(equation[j]))
		{
			if (equation[j] == '(')
			{
				prev = new Equation;
				prev->go = stack;
				stack = prev;
				stack->smbl = equation[j];
			}
			else if (equation[j] == ')')
			{
				while (stack->smbl != '(')
				{
					interim += stack->smbl;
					interim += ' ';
					stack = stack->go;
				}
				if (stack->smbl == '(')
				{
					stack = stack->go;
				}
			}
			else if (equation[j] == '-' && Srch_oprnd(equation[j + 1]))
			{
				interim += '-';
				j++;
				while (!Srch_oprtr(equation[j]) && equation[j] != ' ')
				{
					interim += equation[j];
					j++;
					if (j == equation.size())
					{
						break;
					}
				}
				interim += ' ';
				j--;
			}
			else
			{
				if (stack != NULL)
				{
					if (take_prior(equation[j]) <= take_prior(stack->smbl))
					{
						while (take_prior(equation[j]) <= take_prior(stack->smbl))
						{
							interim += stack->smbl;
							interim += ' ';
							stack = stack->go;
							if (stack == NULL)
								break;
						}
						prev = new Equation;
						prev->go = stack;
						stack = prev;
						stack->smbl = equation[j];
					}
					else
					{
						prev = new Equation;
						prev->go = stack;
						stack = prev;
						stack->smbl = equation[j];
					}
				}
				else
				{
					prev = new Equation;
					prev->go = stack;
					stack = prev;
					stack->smbl = equation[j];
				}
			}
		}
		else if (equation[j] == 'p' && equation[j + 1] == 'i')
		{
			for (int i = 0; i < 2; i++)
			{
				interim += equation[j];
				j++;
			}
			interim += ' ';
			j--;
		}
		else if (equation[j] == 'e')
		{
			interim += equation[j];
			interim += ' ';
		}
		else if (equation[j] == 'c' && equation[j + 1] == 'o' && equation[j + 2] == 's')
		{
			if (Srch_oprnd(equation[j + 3]))
			{
				for (int i = 0; i < 3; i++)
				{
					interim += equation[j];
					j++;
				}
				while (!Srch_oprtr(equation[j]) && equation[j] != ' ')
				{
					interim += equation[j];
					j++;
					if (j == equation.size())
					{
						break;
					}
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 3] == '-' && Srch_oprnd(equation[j + 4]))
			{
				for (int i = 0; i < 3; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += '-';
				j++;
				while (!Srch_oprtr(equation[j]) && equation[j] != ' ')
				{
					interim += equation[j];
					j++;
					if (j == equation.size())
					{
						break;
					}
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 3] == '-' && equation[j + 4] == 'p' && equation[j + 5] == 'i')
			{
				for (int i = 0; i < 6; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 3] == '-' && equation[j + 4] == 'e')
			{
				for (int i = 0; i < 5; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 3] == 'p' && equation[j + 4] == 'i')
			{
				for (int i = 0; i < 5; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 3] == 'e')
			{
				for (int i = 0; i < 4; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += ' ';
				j--;
			}
			else
			{
				cout << "----------------------------" << endl;
				cout << "Wrong symbol or operation: " << equation[j] << endl << endl;
				cout << "----------------------------" << endl;
				indicator = true;
				stack = prev;
				while (stack != NULL)
				{
					stack = stack->go;
					delete prev;
					prev = stack;
				}
				return;
			}
		}
		else if (equation[j] == 's' && equation[j + 1] == 'i' && equation[j + 2] == 'n')
		{
			if (Srch_oprnd(equation[j + 3]))
			{
				for (int i = 0; i < 3; i++)
				{
					interim += equation[j];
					j++;
				}
				while (!Srch_oprtr(equation[j]) && equation[j] != ' ')
				{
					interim += equation[j];
					j++;
					if (j == equation.size())
					{
						break;
					}
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 3] == '-' && Srch_oprnd(equation[j + 4]))
			{
				for (int i = 0; i < 3; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += '-';
				j++;
				while (!Srch_oprtr(equation[j]) && equation[j] != ' ')
				{
					interim += equation[j];
					j++;
					if (j == equation.size())
					{
						break;
					}
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 3] == '-' && equation[j + 4] == 'p' && equation[j + 5] == 'i')
			{
				for (int i = 0; i < 6; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 3] == '-' && equation[j + 4] == 'e')
			{
				for (int i = 0; i < 5; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 3] == 'p' && equation[j + 4] == 'i')
			{
				for (int i = 0; i < 5; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 3] == 'e')
			{
				for (int i = 0; i < 4; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += ' ';
				j--;
			}
			else
			{
				cout << "----------------------------" << endl;
				cout << "Wrong symbol or operation: " << equation[j] << endl << endl;
				cout << "----------------------------" << endl;
				indicator = true;
				stack = prev;
				while (stack != NULL)
				{
					stack = stack->go;
					delete prev;
					prev = stack;
				}
				return;
			}
		}
		else if (equation[j] == 't' && equation[j + 1] == 'g')
		{
			if (Srch_oprnd(equation[j + 2]))
			{
				for (int i = 0; i < 2; i++)
				{
					interim += equation[j];
					j++;
				}
				while (!Srch_oprtr(equation[j]) && equation[j] != ' ')
				{
					interim += equation[j];
					j++;
					if (j == equation.size())
					{
						break;
					}
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 2] == '-' && Srch_oprnd(equation[j + 3]))
			{
				for (int i = 0; i < 2; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += '-';
				j++;
				while (!Srch_oprtr(equation[j]) && equation[j] != ' ')
				{
					interim += equation[j];
					j++;
					if (j == equation.size())
					{
						break;
					}
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 2] == '-' && equation[j + 3] == 'p' && equation[j + 4] == 'i')
			{
				for (int i = 0; i < 5; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 2] == '-' && equation[j + 3] == 'e')
			{
				for (int i = 0; i < 4; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 2] == 'p' && equation[j + 3] == 'i')
			{
				for (int i = 0; i < 4; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 2] == 'e')
			{
				for (int i = 0; i < 3; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += ' ';
				j--;
			}
			else
			{
				cout << "----------------------------" << endl;
				cout << "Wrong symbol or operation: " << equation[j] << endl << endl;
				cout << "----------------------------" << endl;
				indicator = true;
				stack = prev;
				while (stack != NULL)
				{
					stack = stack->go;
					delete prev;
					prev = stack;
				}
				return;
			}
		}
		else if (equation[j] == 'c' && equation[j + 1] == 't' && equation[j + 2] == 'g')
		{
			if (Srch_oprnd(equation[j + 3]))
			{
				for (int i = 0; i < 3; i++)
				{
					interim += equation[j];
					j++;
				}
				while (!Srch_oprtr(equation[j]) && equation[j] != ' ')
				{
					interim += equation[j];
					j++;
					if (j == equation.size())
					{
						break;
					}
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 3] == '-' && Srch_oprnd(equation[j + 4]))
			{
				for (int i = 0; i < 3; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += '-';
				j++;
				while (!Srch_oprtr(equation[j]) && equation[j] != ' ')
				{
					interim += equation[j];
					j++;
					if (j == equation.size())
					{
						break;
					}
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 3] == '-' && equation[j + 4] == 'p' && equation[j + 5] == 'i')
			{
				for (int i = 0; i < 6; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 3] == '-' && equation[j + 4] == 'e')
			{
				for (int i = 0; i < 5; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 3] == 'p' && equation[j + 4] == 'i')
			{
				for (int i = 0; i < 5; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 3] == 'e')
			{
				for (int i = 0; i < 4; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += ' ';
				j--;
			}
			else
			{
				cout << "----------------------------" << endl;
				cout << "Wrong symbol or operation: " << equation[j] << endl << endl;
				cout << "----------------------------" << endl;
				indicator = true;
				stack = prev;
				while (stack != NULL)
				{
					stack = stack->go;
					delete prev;
					prev = stack;
				}
				return;
			}
		}
		else if (equation[j] == 'l' && equation[j + 1] == 'n')
		{
			if (Srch_oprnd(equation[j + 2]))
			{
				for (int i = 0; i < 2; i++)
				{
					interim += equation[j];
					j++;
				}
				while (!Srch_oprtr(equation[j]) && equation[j] != ' ')
				{
					interim += equation[j];
					j++;
					if (j == equation.size())
					{
						break;
					}
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 2] == '-' && Srch_oprnd(equation[j + 3]))
			{
				for (int i = 0; i < 2; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += '-';
				j++;
				while (!Srch_oprtr(equation[j]) && equation[j] != ' ')
				{
					interim += equation[j];
					j++;
					if (j == equation.size())
					{
						break;
					}
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 2] == '-' && equation[j + 3] == 'p' && equation[j + 4] == 'i')
			{
				for (int i = 0; i < 5; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 2] == '-' && equation[j + 3] == 'e')
			{
				for (int i = 0; i < 4; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 3] == 'p' && equation[j + 4] == 'i')
			{
				for (int i = 0; i < 4; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 2] == 'e')
			{
				for (int i = 0; i < 3; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += ' ';
				j--;
			}
			else
			{
				cout << "----------------------------" << endl;
				cout << "Wrong symbol or operation: " << equation[j] << endl << endl;
				cout << "----------------------------" << endl;
				indicator = true;
				stack = prev;
				while (stack != NULL)
				{
					stack = stack->go;
					delete prev;
					prev = stack;
				}
				return;
			}
		}
		else if (equation[j] == 'l' && equation[j + 1] == 'o' && equation[j + 2] == 'g')
		{
			if (Srch_oprnd(equation[j + 3]))
			{
				for (int i = 0; i < 3; i++)
				{
					interim += equation[j];
					j++;
				}
				while (!Srch_oprtr(equation[j]) && equation[j] != ' ')
				{
					interim += equation[j];
					j++;
					if (j == equation.size())
					{
						break;
					}
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 3] == '-' && Srch_oprnd(equation[j + 4]))
			{
				for (int i = 0; i < 3; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += '-';
				j++;
				while (!Srch_oprtr(equation[j]) && equation[j] != ' ')
				{
					interim += equation[j];
					j++;
					if (j == equation.size())
					{
						break;
					}
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 3] == '-' && equation[j + 4] == 'p' && equation[j + 5] == 'i')
			{
				for (int i = 0; i < 6; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 3] == '-' && equation[j + 4] == 'e')
			{
				for (int i = 0; i < 5; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 3] == 'p' && equation[j + 4] == 'i')
			{
				for (int i = 0; i < 5; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 3] == 'e')
			{
				for (int i = 0; i < 4; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += ' ';
				j--;
			}
			else
			{
				cout << "----------------------------" << endl;
				cout << "Wrong symbol or operation: " << equation[j] << endl << endl;
				cout << "----------------------------" << endl;
				indicator = true;
				stack = prev;
				while (stack != NULL)
				{
					stack = stack->go;
					delete prev;
					prev = stack;
				}
				return;
			}
		}
		else if (equation[j] == 's' && equation[j + 1] == 'q' && equation[j + 2] == 'r' && equation[j + 3] == 't')
		{
			if (Srch_oprnd(equation[j + 4]))
			{
				for (int i = 0; i < 4; i++)
				{
					interim += equation[j];
					j++;
				}
				while (!Srch_oprtr(equation[j]) && equation[j] != ' ')
				{
					interim += equation[j];
					j++;
					if (j == equation.size())
					{
						break;
					}
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 4] == '-' && Srch_oprnd(equation[j + 5]))
			{
				for (int i = 0; i < 4; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += '-';
				j++;
				while (!Srch_oprtr(equation[j]) && equation[j] != ' ')
				{
					interim += equation[j];
					j++;
					if (j == equation.size())
					{
						break;
					}
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 4] == '-' && equation[j + 5] == 'p' && equation[j + 6] == 'i')
			{
				for (int i = 0; i < 7; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 4] == '-' && equation[j + 5] == 'e')
			{
				for (int i = 0; i < 6; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 4] == 'p' && equation[j + 5] == 'i')
			{
				for (int i = 0; i < 6; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 4] == 'e')
			{
				for (int i = 0; i < 5; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += ' ';
				j--;
			}
			else
			{
				cout << "----------------------------" << endl;
				cout << "Wrong symbol or operation: " << equation[j] << endl << endl;
				cout << "----------------------------" << endl;
				indicator = true;
				stack = prev;
				while (stack != NULL)
				{
					stack = stack->go;
					delete prev;
					prev = stack;
				}
				return;
			}
		}
		else if (equation[j] == 'a' && equation[j + 1] == 'b' && equation[j + 2] == 's')
		{
			if (Srch_oprnd(equation[j + 3]))
			{
				for (int i = 0; i < 3; i++)
				{
					interim += equation[j];
					j++;
				}
				while (!Srch_oprtr(equation[j]) && equation[j] != ' ')
				{
					interim += equation[j];
					j++;
					if (j == equation.size())
					{
						break;
					}
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 3] == '-' && Srch_oprnd(equation[j + 4]))
			{
				for (int i = 0; i < 3; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += '-';
				j++;
				while (!Srch_oprtr(equation[j]) && equation[j] != ' ')
				{
					interim += equation[j];
					j++;
					if (j == equation.size())
					{
						break;
					}
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 3] == '-' && equation[j + 4] == 'p' && equation[j + 5] == 'i')
			{
				for (int i = 0; i < 6; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 3] == '-' && equation[j + 4] == 'e')
			{
				for (int i = 0; i < 5; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 3] == 'p' && equation[j + 4] == 'i')
			{
				for (int i = 0; i < 5; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += ' ';
				j--;
			}
			else if (equation[j + 3] == 'e')
			{
				for (int i = 0; i < 4; i++)
				{
					interim += equation[j];
					j++;
				}
				interim += ' ';
				j--;
			}
			else
			{
				cout << "----------------------------" << endl;
				cout << "Wrong symbol or operation: " << equation[j] << endl << endl;
				cout << "----------------------------" << endl;
				indicator = true;
				stack = prev;
				while (stack != NULL)
				{
					stack = stack->go;
					delete prev;
					prev = stack;
				}
				return;
			}
		}
		else
		{
			cout << "----------------------------" << endl;
			cout << "Wrong symbol or operation: " << equation[j] << endl << endl;
			cout << "----------------------------" << endl;
			indicator = true;
			stack = prev;
			while (stack != NULL)
			{
				stack = stack->go;
				delete prev;
				prev = stack;
			}
			return;
		}
	}
	while (stack != NULL)
	{
		interim += stack->smbl;
		interim += ' ';
		stack = stack->go;
	}
	stack = prev;
	while (stack != NULL)
	{
		stack = stack->go;
		delete prev;
		prev = stack;
	}
	delete prev;
	equation.empty();
	equation = interim;
	cout << "------------------------------------------------" << endl;
	cout << "The equation in the postfix form of the entry: ";
	cout << equation << endl;
	cout << "------------------------------------------------" << endl;
}
double Equation::task_count() //function for calculating the entered equation
{
	double ans = 0;
	Equation* prev;
	prev = stack;
	for (int j = 0; j < equation.size(); j++)
	{
		if (equation[j] == ' ')
			continue;
		if (Srch_oprnd(equation[j]) || equation[j] == '.')
		{
			string eq_part;
			eq_part.empty();
			while (!Srch_oprtr(equation[j]) && equation[j] != ' ')
			{
				eq_part += equation[j];
				j++;
				if (j == equation.size())
					break;
			}
			prev = new Equation;
			prev->go = stack;
			stack = prev;
			stack->amount = stod(eq_part);
			ans = stack->amount;
		}
		else if (Srch_oprtr(equation[j]) && !Srch_oprnd(equation[j + 1]))
		{
			double num_1 = stack->amount;
			stack = stack->go;
			delete prev;
			double num_2 = stack->amount;
			prev = stack;
			stack = stack->go;
			delete prev;
			switch (equation[j])
			{
			case '+': ans = num_2 + num_1; break;
			case '-': ans = num_2 - num_1; break;
			case '*': ans = num_2 * num_1; break;
			case '/': ans = num_2 / num_1; break;
			case '^': ans = pow(num_2, num_1); break;
			}
			prev = new Equation;
			prev->go = stack;
			stack = prev;
			stack->amount = ans;
		}
		else if (Srch_oprtr(equation[j]) && Srch_oprnd(equation[j + 1]))
		{
			string eq_part;
			eq_part.empty();
			eq_part += '-';
			j++;
			while (!Srch_oprtr(equation[j]) && equation[j] != ' ')
			{
				eq_part += equation[j];
				j++;
				if (j == equation.size())
					break;
			}
			prev = new Equation;
			prev->go = stack;
			stack = prev;
			stack->amount = stod(eq_part);
			ans = stack->amount;
		}
		else if (equation[j] == 'p')
		{
			string eq_part;
			eq_part.empty();
			for (int i = 0; i < 2; i++)
			{
				eq_part += equation[j];
				j++;
			}
			prev = new Equation;
			prev->go = stack;
			stack = prev;
			stack->amount = 3.141593;
			j--;
			ans = stack->amount;
		}
		else if (equation[j] == 'e')
		{
			string eq_part;
			eq_part.empty();
			eq_part += equation[j];
			prev = new Equation;
			prev->go = stack;
			stack = prev;
			stack->amount = 2.718282;
			ans = stack->amount;
		}
		else if (equation[j] == 'c' && equation[j + 1] == 'o')
		{
			string eq_part;
			eq_part.empty();
			while (!Srch_oprnd(equation[j]) && !Srch_oprtr(equation[j]) && equation[j] != '.' && equation[j] != 'p' && equation[j] != 'e')
			{
				j++;
			}
			while (equation[j] != ' ')
			{
				eq_part += equation[j];
				j++;
			}
			prev = new Equation;
			prev->go = stack;
			stack = prev;
			if (eq_part[0] == 'p')
			{
				stack->amount = cos(3.141593);
			}
			else if (eq_part[0] == 'e')
			{
				stack->amount = cos(2.718282);
			}
			else if (eq_part[1] == 'p')
			{
				stack->amount = cos(-3.141593);
			}
			else if (eq_part[1] == 'e')
			{
				stack->amount = cos(-2.718282);
			}
			else
				stack->amount = cos(stod(eq_part));
			j--;
			ans = stack->amount;
		}
		else if (equation[j] == 's' && equation[j + 1] == 'i')
		{
			string eq_part;
			eq_part.empty();
			while (!Srch_oprnd(equation[j]) && !Srch_oprtr(equation[j]) && equation[j] != '.' && equation[j] != 'p' && equation[j] != 'e')
			{
				j++;
			}
			while (equation[j] != ' ')
			{
				eq_part += equation[j];
				j++;
			}
			prev = new Equation;
			prev->go = stack;
			stack = prev;
			if (eq_part[0] == 'p')
			{
				stack->amount = sin(3.141593);
			}
			else if (eq_part[0] == 'e')
			{
				stack->amount = sin(2.718282);
			}
			else if (eq_part[1] == 'p')
			{
				stack->amount = sin(-3.141593);
			}
			else if (eq_part[1] == 'e')
			{
				stack->amount = sin(-2.718282);
			}
			else
				stack->amount = sin(stod(eq_part));
			j--;
			ans = stack->amount;
		}
		else if (equation[j] == 't' && equation[j + 1] == 'g')
		{
			string eq_part;
			eq_part.empty();
			while (!Srch_oprnd(equation[j]) && !Srch_oprtr(equation[j]) && equation[j] != '.' && equation[j] != 'p' && equation[j] != 'e')
			{
				j++;
			}
			while (equation[j] != ' ')
			{
				eq_part += equation[j];
				j++;
			}
			prev = new Equation;
			prev->go = stack;
			stack = prev;
			if (eq_part[0] == 'p')
			{
				stack->amount = tan(3.141593);
			}
			else if (eq_part[0] == 'e')
			{
				stack->amount = tan(2.718282);
			}
			else if (eq_part[1] == 'p')
			{
				stack->amount = tan(-3.141593);
			}
			else if (eq_part[1] == 'e')
			{
				stack->amount = tan(-2.718282);
			}
			else
				stack->amount = tan(stod(eq_part));
			j--;
			ans = stack->amount;
		}
		else if (equation[j] == 'c' && equation[j + 1] == 't')
		{
			string eq_part;
			eq_part.empty();
			while (!Srch_oprnd(equation[j]) && !Srch_oprtr(equation[j]) && equation[j] != '.' && equation[j] != 'p' && equation[j] != 'e')
			{
				j++;
			}
			while (equation[j] != ' ')
			{
				eq_part += equation[j];
				j++;
			}
			prev = new Equation;
			prev->go = stack;
			stack = prev;
			if (eq_part[0] == 'p')
			{
				stack->amount = 1 / (tan(3.141593));
			}
			else if (eq_part[0] == 'e')
			{
				stack->amount = 1 / (tan(2.718282));
			}
			else if (eq_part[1] == 'p')
			{
				stack->amount = 1 / (tan(-3.141593));
			}
			else if (eq_part[1] == 'e')
			{
				stack->amount = 1 / (tan(-2.718282));
			}
			else
				stack->amount = 1 / (tan(stod(eq_part)));
			j--;
			ans = stack->amount;
		}
		else if (equation[j] == 'l' && equation[j + 1] == 'n')
		{
			string eq_part;
			eq_part.empty();
			while (!Srch_oprnd(equation[j]) && !Srch_oprtr(equation[j]) && equation[j] != '.' && equation[j] != 'p' && equation[j] != 'e')
			{
				j++;
			}
			while (equation[j] != ' ')
			{
				eq_part += equation[j];
				j++;
			}
			prev = new Equation;
			prev->go = stack;
			stack = prev;
			if (eq_part[0] == 'p')
			{
				stack->amount = log(3.141593);
			}
			else if (eq_part[0] == 'e')
			{
				stack->amount = log(2.718282);
			}
			else if (eq_part[1] == 'p')
			{
				stack->amount = log(-3.141593);
			}
			else if (eq_part[1] == 'e')
			{
				stack->amount = log(-2.718282);
			}
			else
				stack->amount = log(stod(eq_part));
			j--;
			ans = stack->amount;
		}
		else if (equation[j] == 'l' && equation[j + 1] == 'o')
		{
			string eq_part;
			eq_part.empty();
			while (!Srch_oprnd(equation[j]) && !Srch_oprtr(equation[j]) && equation[j] != '.' && equation[j] != 'p' && equation[j] != 'e')
			{
				j++;
			}
			while (equation[j] != ' ')
			{
				eq_part += equation[j];
				j++;
			}
			prev = new Equation;
			prev->go = stack;
			stack = prev;
			if (eq_part[0] == 'p')
			{
				stack->amount = log10(3.141593);
			}
			else if (eq_part[0] == 'e')
			{
				stack->amount = log10(2.718282);
			}
			else if (eq_part[1] == 'p')
			{
				stack->amount = log10(-3.141593);
			}
			else if (eq_part[1] == 'e')
			{
				stack->amount = log10(-2.718282);
			}
			else
				stack->amount = log10(stod(eq_part));
			j--;
			ans = stack->amount;
		}
		else if (equation[j] == 's' && equation[j + 1] == 'q')
		{
			string eq_part;
			eq_part.empty();
			while (!Srch_oprnd(equation[j]) && !Srch_oprtr(equation[j]) && equation[j] != '.' && equation[j] != 'p' && equation[j] != 'e')
			{
				j++;
			}
			while (equation[j] != ' ')
			{
				eq_part += equation[j];
				j++;
			}
			prev = new Equation;
			prev->go = stack;
			stack = prev;
			if (eq_part[0] == 'p')
			{
				stack->amount = sqrt(3.141593);
			}
			else if (eq_part[0] == 'e')
			{
				stack->amount = sqrt(2.718282);
			}
			else if (eq_part[1] == 'p')
			{
				stack->amount = sqrt(-3.141593);
			}
			else if (eq_part[1] == 'e')
			{
				stack->amount = sqrt(-2.718282);
			}
			else
				stack->amount = sqrt(stod(eq_part));
			j--;
			ans = stack->amount;
		}
		else if (equation[j] == 'a' && equation[j + 1] == 'b')
		{
			string eq_part;
			eq_part.empty();
			while (!Srch_oprnd(equation[j]) && !Srch_oprtr(equation[j]) && equation[j] != '.' && equation[j] != 'p' && equation[j] != 'e')
			{
				j++;
			}
			while (equation[j] != ' ')
			{
				eq_part += equation[j];
				j++;
			}
			prev = new Equation;
			prev->go = stack;
			stack = prev;
			if (eq_part[0] == 'p')
			{
				stack->amount = abs(3.141593);
			}
			else if (eq_part[0] == 'e')
			{
				stack->amount = abs(2.718282);
			}
			else if (eq_part[1] == 'p')
			{
				stack->amount = abs(-3.141593);
			}
			else if (eq_part[1] == 'e')
			{
				stack->amount = abs(-2.718282);
			}
			else
				stack->amount = abs(stod(eq_part));
			j--;
			ans = stack->amount;
		}
	}
	while (stack != NULL)
	{
		prev = stack;
		stack = stack->go;
		delete prev;
	}
	equation.empty();
	return ans;
}