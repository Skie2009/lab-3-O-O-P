#pragma once
#include <iostream>
using namespace std;

class ILoggable {

public :

	virtual void LogToScreen()=0;
	virtual void LogToFile(const string& filename)=0;
};
