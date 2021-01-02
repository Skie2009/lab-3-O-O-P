#include "CustomExpressionEvaluator.h"
#include <iostream>
 
#include <fstream>
using namespace std;



CustomExpressionEvaluator::CustomExpressionEvaluator() : ExpressionEvaluator() {
	cout << "Объект типа CustomExpressionEvaluator создан" << endl << endl;
}

CustomExpressionEvaluator::CustomExpressionEvaluator(int n) : ExpressionEvaluator(n) {
	cout << "Объект типа CustomExpressionEvaluator создан" << endl << endl;
}

CustomExpressionEvaluator::~CustomExpressionEvaluator() {
	cout << "Объект типа CustomExpressionEvaluator удален" << endl << endl;
}

double CustomExpressionEvaluator::calculate() {
	double res = operands_[0];
	for (int i = 1; i < count_operand_; i++) {
		if ((i-1) % 2 == 0) {
			res *=  operands_[i];
		}
		else
		{
			res /= operands_[i];
		}
	}
	return res;
}

void CustomExpressionEvaluator::LogToScreen() {

	cout << "<" << count_operand_ << ">" << endl;
	for (int i = 0; i < count_operand_-1; i++) {
		if (i%2==0) {
			cout <<CheckSign(operands_[i]);
			cout << " times ";
		}
		else {
			cout <<CheckSign( operands_[i]);
			cout << " divided by ";
		}
	}
	cout <<CheckSign(operands_[count_operand_ - 1]);
	cout  << endl;
}

void CustomExpressionEvaluator::LogToFile(const string& filename) {

	fstream out(filename+".txt",ios_base::app|ios_base::out);
	if (out.is_open()) {
		out << "<" << count_operand_ << ">" << endl;
		for (int i = 0; i < count_operand_ - 1; i++) {
			if (i % 2 == 0) {
				out <<CheckSign( operands_[i]);
				out << " times ";
			}
			else {
				out << CheckSign(operands_[i]);
				out << " divided by ";
			}
		}
		out <<CheckSign(operands_[count_operand_ - 1]);
		out << endl;
	}
	out.close();
}

void CustomExpressionEvaluator::shuffle() {

	int first = 0;
	int last = 0;

	for (int i = 0; i < count_operand_; i++) {

		if ((int)operands_[i] != operands_[i]) {
			first = i;
		}
	}
	for (int i = count_operand_ - 1; i >= 0; i--) {
		if ((int)operands_[i] != operands_[i]) {
			last = i;
		}
	}
	if (operands_[first] != operands_[last]) {
		double tmp = operands_[first];
		operands_[first] = operands_[last];
		operands_[last] = tmp;
	}
}


void CustomExpressionEvaluator::shuffle(size_t i, size_t j) {

	if (i < count_operand_ && j < count_operand_) {
		if ((int)operands_[i] != operands_[i] || (int)operands_[j] != operands_[j]) {

			double tmp = operands_[i];
			operands_[i] = operands_[j];
			operands_[j] = tmp;
		}
	}
}