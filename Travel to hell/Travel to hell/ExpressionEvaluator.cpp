#include "ExpressionEvaluator.h"
#include <iostream>
#include <string>
 



ExpressionEvaluator::ExpressionEvaluator() : count_operand_(20) {

	operands_ = new double [count_operand_] {0};
	cout << "Объект типа ExpressionEvaluator создан" << endl << endl;
}

ExpressionEvaluator::ExpressionEvaluator(int n) : count_operand_(n) {

	operands_ = new double [count_operand_] {0};
	cout << "Объект типа ExpressionEvaluator создан" << endl << endl;
}

ExpressionEvaluator::~ExpressionEvaluator() {
	delete[] operands_;
	cout << "Объект типа ExpressionEvaluator удален" << endl << endl;
}

void ExpressionEvaluator::SetOperand(size_t pos, double value) {
	if (pos <= count_operand_) {
		operands_[pos] = value;
	}
}

void ExpressionEvaluator::SetOperands(double* ops,size_t n ) {
	if (n <= count_operand_) {
		for (int i = 0; i < n; i++) {
			operands_[i] = ops[i];
		}
	}
}

int ExpressionEvaluator::getCountOperand()const {
	return count_operand_;
}

double* ExpressionEvaluator::getOperands()const {
	return operands_;
}

string ExpressionEvaluator::CheckSign(double oper) {

	string res = "";
	if (oper < 0)
	{
		res = "(" + to_string(oper) + ")";
	}
	else  res = to_string(oper);
	return res;
}