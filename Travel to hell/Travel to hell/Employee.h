#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "IPictureProcessor.h"
using namespace std;

class Employee : public IPictureProcessor
{
public:

	Employee(); //constructor пустой(базовый) //при создании объекта вызывается один из существующих конструкторов; То есть конструктор - создает объект класса;

	Employee(const string& name, const string& surname, char gender, short year_birth, short year_start,const string& phone);//constructor с параметрами

	//gettes, setters
	void setName(const string& name);
	void setSurname(const string& surname);
	void setGender(const char gender);
	void setYearBirth(const short year_birth);
	void setYearStart(const short year_start);
	void setRating(const double rating);
	void setPhone(const string& phone);


	string getName()const;
	string getSurname()const;
	char getGender()const;
	short getYearBirth()const;
	short getYearStart()const;
	double getReting()const;
	string getPhone()const;


	virtual void Imitation()=0;
	virtual void PrintStatistics()=0;


////serialize\deserialize
	virtual void serialize()const=0;
	void deserialize();

	virtual  ostream& operator<<(ostream& out)=0;
	

	virtual ~Employee();//destructor


protected:

	string name_;
	string surname_;
	char gender_;
	short year_birth_;
	short year_start_;
	double rating_;
	string phone_;
};

