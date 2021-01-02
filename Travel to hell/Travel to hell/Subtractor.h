#pragma once
#include "ExpressionEvaluator.h"
#include "IShuffle.h"

class Subtractor : public ExpressionEvaluator, public IShuffle
{
public:
	
	Subtractor();
	Subtractor(int n);
	~Subtractor();

	double calculate() override;

	void LogToFile(const string& filename) override;
	void LogToScreen() override;

	void shuffle() override;
	void shuffle(size_t i, size_t j) override;
};