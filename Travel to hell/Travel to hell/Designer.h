#pragma once
#include "Employee.h"
class Designer : public Employee
{

public:
	Designer();
	Designer(const string& name, const string& surname, char gender, short year_birth, short year_start, const string& phone);
	~Designer();

	void Imitation() override;
	void PrintStatistics() override;
	void Process(const string& photo_path);

	//serialize\deserialize
	void serialize()const override;




	ostream& operator<<(ostream& out) override;

};