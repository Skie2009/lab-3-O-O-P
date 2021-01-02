#pragma once
#include "ExpressionEvaluator.h"
#include "IShuffle.h"
#include <fstream>

using namespace std;

class CustomExpressionEvaluator : public ExpressionEvaluator, public IShuffle
{
public:
	CustomExpressionEvaluator();
	CustomExpressionEvaluator(int n);
	~CustomExpressionEvaluator();

	double calculate() override;

	void LogToFile(const string& filename) override;
	void LogToScreen() override;

	

	void shuffle() override;
	void shuffle(size_t i, size_t j) override;

	

};

