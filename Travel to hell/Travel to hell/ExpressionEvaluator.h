#pragma once
#include "ILoggable.h"
#include "IShuffle.h"
#include <fstream>

using namespace Traveltohell;

class ExpressionEvaluator : public ILoggable
{
public:

	ExpressionEvaluator();
	ExpressionEvaluator(int n);
	virtual ~ExpressionEvaluator();

	virtual double calculate() = 0;
	string CheckSign(double oper);


	void SetOperand(size_t pos, double value);
	void SetOperands(double* ops, size_t n);

	int getCountOperand()const;
	double* getOperands()const;

protected:

	int count_operand_;
	double* operands_;


};