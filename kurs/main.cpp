#include <iostream>
#include <stdexcept>
#include "eq_func.h"
using namespace std;
int main()
{
	int key = 0;
	Equation equation;
	while (key != 2)
	{
		cout << "------------------------------------------------" << endl;
		cout << "|Enter 1 to calculate the equation or 2 to exit|\n";
		cout << "------------------------------------------------" << endl;
		cin >> key;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());

		switch (key)
		{
		case 1:
		{
			equation.indicator = false;
			equation.fill_eq();
			if (!equation.check_wr())
			{
				equation.inf_to_post();
				if (equation.indicator == false)
				{
					cout << "------------------------------------" << endl;
					cout << "|The result of this calculation: " << equation.task_count() << " |"<< endl;
					cout << "------------------------------------" << endl;
				}
			}
			break;
		}
		case 2:
		{
			break;
		}
		default:
			cout << "Error! Wrong entered symbol!" << endl << endl;;
			throw invalid_argument("Wrong entered symbol!");
		}
	}
	cout << "-------------------------------------" << endl;
	cout << "|Calculator was successfully closed!|" << endl;
	cout << "-------------------------------------" << endl;
	exit(0);
}