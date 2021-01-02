#pragma once
#include <string>
using namespace std;

class IPictureProcessor {
public:
	virtual void Process(const string& photo_path) = 0;
};