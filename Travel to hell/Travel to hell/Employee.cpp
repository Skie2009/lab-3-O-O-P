#include "Employee.h"
#include <iostream>
#include <fstream>
#include <ctime>
 
Employee::Employee() {

	name_ = "V";
	surname_ = "V";
	gender_ = 'm';
	year_birth_ = 2001;
	year_start_ = 2016;
	rating_ = 0.0;
	phone_ = "0000000000";
	cout << "Сотрудник " << name_ << " " << surname_ << " занесен в базу" << endl << endl;
}

Employee::Employee(const string& name, const string& surname, char gender, short year_birth, short year_start, const string& phone) :
	name_(name), surname_(surname), gender_(gender), year_birth_(year_birth), year_start_(year_start),phone_(phone)
{
	rating_ = 0.0;
	cout << "Сторудник " << name_ << " " << surname_ << " занесен в базу" << endl << endl;
}

Employee::~Employee() {
	cout << "Сторудник " << name_ << " " << surname_ << " уволен к чертям" << endl << endl;
}

//сеттеры , геттеры

void Employee::setName(const string& name) {
	name_ = name;
}
void Employee::setSurname(const string& surname) {
	surname_ = surname;
}
void Employee::setGender(char gender) {
	gender_ = gender;
}
void Employee::setYearBirth(short year) {
	year_birth_ = year;
}
void Employee::setYearStart(short year) {
	year_start_ = year;
}
void Employee::setRating(double rating) {
	rating_ = rating;
}
void Employee::setPhone(const string& phone) {
	phone_ = phone;
}

string Employee::getName()const {
	return name_;
}
string Employee::getSurname()const {
	return surname_;
}
char Employee::getGender()const {
	return gender_;
}
short Employee::getYearBirth()const {
	return year_birth_;
}
short Employee::getYearStart()const {
	return year_start_;
}
double Employee::getReting()const {
	return rating_;
}
string Employee::getPhone()const {
	return phone_;
}

void Employee::deserialize() {
	const string path = name_ + ".txt";
	string line;
	ifstream fin(path);
	if (fin.is_open()) {

		while (getline(fin, line)) {
			cout << line << endl;
		}
	}
	fin.close();
}