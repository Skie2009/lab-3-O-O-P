#include "Multiplier.h"
#include <iostream>
 
#include <fstream>
using namespace std;


Multiplier::Multiplier() : ExpressionEvaluator() {
	cout << "Объект типа Multiplier создан" << endl << endl;
}

Multiplier::Multiplier(int n) : ExpressionEvaluator(n) {
	cout << "Объект типа Multiplier создан" << endl << endl;
}

Multiplier::~Multiplier() {
	cout << "Объект типа Multiplier удален" << endl << endl;
}

double Multiplier::calculate() {
	double res = operands_[0];
	for (int i = 1; i < count_operand_; i++) {
		res *= operands_[i];
	}
	return res;
}

void Multiplier::LogToScreen() {
	cout << "<" << count_operand_ << ">" << endl;
	for (int i = 0; i < count_operand_ - 1; i++) {

			cout <<CheckSign(operands_[i]) << " * ";
	}
	cout <<CheckSign(operands_[count_operand_ - 1]);
	cout << endl;
}

void Multiplier::LogToFile(const string& filename) {

	fstream out(filename + ".txt", ios_base::app | ios_base::out);
	if (out.is_open()) {
		for (int i = 0; i < count_operand_ - 1; i++) {
			
				out <<CheckSign( operands_[i]) << " * ";
		}
		out <<CheckSign( operands_[count_operand_ - 1]);
		out << endl;
	}
	out.close();
}