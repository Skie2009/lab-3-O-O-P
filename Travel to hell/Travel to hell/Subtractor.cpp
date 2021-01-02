#include "Subtractor.h"
#include <iostream>
#include <fstream>
 
using namespace std;


Subtractor::Subtractor() : ExpressionEvaluator(){
	cout << "Объект типа Subtractor создан" << endl << endl;
}

Subtractor::Subtractor(int n) : ExpressionEvaluator(n){
	cout << "Объект типа Subtractor создан" << endl << endl;
}

Subtractor::~Subtractor() {
	cout << "Объект типа Subtractor удален" << endl << endl;
}

double Subtractor::calculate() {
	double res = operands_[0];
	for (int i = 1; i < count_operand_; i++) {
		res -= operands_[i];
	}
	return res;
}

void Subtractor::LogToScreen(){
	cout << "<" << count_operand_ << ">" << endl;
	for (int i = 0; i < count_operand_-1; i++) {
		
		cout <<CheckSign( operands_[i]) << " - ";
	}
	cout <<CheckSign( operands_[count_operand_ - 1]);
	cout << endl;
}

void Subtractor::LogToFile(const string& filename){

	fstream out(filename + ".txt", ios_base::app | ios_base::out);
	if (out.is_open()) {
		for (int i = 0; i < count_operand_-1; i++) {
			
				out <<CheckSign( operands_[i]) << " - ";
		}
		out <<CheckSign( operands_[count_operand_ - 1]);
		out << endl;
	}
	out.close();
}

void Subtractor::shuffle(){ 
	
	int first = 0;
	int last = 0;
	
	for (int i = 0; i < count_operand_; i++) {

		if ((int)operands_[i] != operands_[i]) {
			first = i;
			break;
		}
	}
	for (int i = count_operand_ - 1; i >= 0; i--) {
		if ((int)operands_[i] != operands_[i]) {
			last = i;
			break;
		}
	}
	if (operands_[first]!=operands_[last]){
		double tmp = operands_[first];
		operands_[first] = operands_[last];
		operands_[last] = tmp;
	}
}


void Subtractor::shuffle(size_t i, size_t j){
	if (i < count_operand_ && j < count_operand_) {
		if ((int)operands_[i] != operands_[i] || (int)operands_[j] != operands_[j]) {

			double tmp = operands_[i];
			operands_[i] = operands_[j];
			operands_[j] = tmp;
		}
	}
}