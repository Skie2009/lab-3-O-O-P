#pragma once
#include "Employee.h"
class Photographer : public Employee
{
public:
	Photographer();
	Photographer(const string& name, const string& surname, char gender, short year_birth, short year_start, const string& phone,int count_photo);
	~Photographer();

	 void Imitation() override;
	 void PrintStatistics() override;
	 void Process(const string& photo_path);
	 
	//serialize\deserialize
	 void serialize()const override;


	 void setCountPhoto(const int count_photo);
	 int getCountPhoto()const;

	 ostream& operator<<(ostream& out) override;
	//friend std::ostream& operator<< (std::ostream& out, const Photographer& point);

private:
	int count_photo_;

};

