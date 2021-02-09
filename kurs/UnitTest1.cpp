#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept>
#include "../KursRab_Koryagin/eq_func.h"
#include "../KursRab_Koryagin/calculator.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace UnitTestKurs
{
	TEST_CLASS(UnitTestKurs)
	{
	public:
		TEST_METHOD(fill_eq) //test filling of the equation
		{
			Equation equation;
			equation.equation.push_back('c');
			equation.equation.push_back('o');
			equation.equation.push_back('s');
			equation.equation.push_back('p');
			equation.equation.push_back('i');
			Assert::AreEqual('c', equation.equation[0]);
			Assert::AreEqual('o', equation.equation[1]);
			Assert::AreEqual('s', equation.equation[2]);
			Assert::AreEqual('p', equation.equation[3]);
			Assert::AreEqual('i', equation.equation[4]);
		}
		TEST_METHOD(check_wr) //equation verification function test
		{
			Equation equation;
			equation.equation.push_back('c');
			equation.equation.push_back('o');
			equation.equation.push_back('s');
			equation.equation.push_back('p');
			equation.equation.push_back('i');
			equation.equation.push_back('-');
			Assert::AreEqual(true, equation.check_wr());
		}

		TEST_METHOD(Srch_oprtr) //test of the operator search function
		{
			Equation equation;
			equation.equation.push_back('c');
			equation.equation.push_back('o');
			equation.equation.push_back('s');
			equation.equation.push_back('p');
			equation.equation.push_back('i');
			equation.equation.push_back('-');
			Assert::AreEqual(true, equation.Srch_oprtr(equation.equation[5]));
		}

		TEST_METHOD(task_count) //test of the equation solution function
		{
			Equation equation;
			equation.equation.push_back('c');
			equation.equation.push_back('o');
			equation.equation.push_back('s');
			equation.equation.push_back('p');
			equation.equation.push_back('i');
			equation.equation.push_back('-');
			equation.equation.push_back('c');
			equation.equation.push_back('o');
			equation.equation.push_back('s');
			equation.equation.push_back('p');
			equation.equation.push_back('i');
			equation.inf_to_post();
			double answer = 0;
			Assert::AreEqual(answer, equation.task_count());
		}
	};
}

