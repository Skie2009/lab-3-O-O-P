#pragma once
#include "ExpressionEvaluator.h"
class Multiplier : public ExpressionEvaluator
{
public:
	Multiplier();
	Multiplier(int n);
	~Multiplier();

	double calculate() override;
	
	void LogToFile(const string& filename) override;
	void LogToScreen() override;

	


};