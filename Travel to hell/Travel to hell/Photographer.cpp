#include "Photographer.h"
 


Photographer::Photographer() : Employee(),count_photo_(0) {
	cout << "Фотограф " << name_ << " " << surname_ << " занесен в базу" << endl << endl;
}

Photographer::Photographer(const string& name, const string& surname, char gender, short year_birth, short year_start, const string& phone,int count_photo) : Employee(name, surname, gender, year_birth, year_start, phone),count_photo_(count_photo) {
	cout << "Фотограф " << name_ << " " << surname_ << " занесен в базу" << endl << endl;
}

Photographer::~Photographer() {
	cout << "Фотограф " << name_ << " " << surname_ << " уволен к чертям!" << endl << endl;
}



ostream& Photographer::operator<<(ostream& out) {

	out << "Имя фотографа " << name_ << endl;
	out << "Фамилия фотографа " << surname_ << endl;
	out << "Пол фотографа " << gender_ << endl;
	out << "Год рождения фотографа " << year_birth_ << endl;
	out << "Год начала карьеры фотографа " << year_start_ << endl;
	out << "Телефон фотографа " << phone_ << endl;
	out << "Количество фото в портфолио " << count_photo_ << endl<<endl;

	return out;
}

void Photographer::serialize()const {
	const string path = name_ + ".txt";
	ofstream fout(path);
	if (fout.is_open()) {
		fout << "Имя фотографа " << name_ << endl;
		fout << "Фамилия фотографа " << surname_ << endl;
		fout << "Пол фотографа " << gender_ << endl;
		fout << "Год рождения фотографа " << year_birth_ << endl;
		fout << "Год начала карьеры фотографа " << year_start_ << endl;
		fout << "Телефон фотографа " << phone_ << endl;
		fout << "Количество фото в портфолио " << count_photo_ << endl << endl;
	}
	fout.close();
}

void Photographer::setCountPhoto(const int count_photo) {
	count_photo_ = count_photo;
}
int Photographer::getCountPhoto()const {
	return count_photo_;
}

void Photographer::PrintStatistics() {
	*this << cout;
}

void Photographer::Imitation() {
	cout << "--------------------------------START Imitation---------------------------------" << endl;
	for (size_t i = 0; i < 3; i++) {
		cout << "Фотоссессия №" << i + 1 << endl;
		//srand(time(i));

		int votes = rand() % 30;
		if (votes >= 10) {
			rating_ += rand() % 10 + 1;
		}
		cout << "Проголосовало: " << votes << " за фотографа " << name_ << endl;
		cout << "Текущий рейтинг: " << rating_ << " фотографа " << name_ << " " << surname_ << endl << endl;
		cout << "--------------------------------Imitation-------------------------------------" << endl;
	}
	cout << "--------------------------------END Imitation----------------------------------" << endl;
}

void Photographer::Process(const string& photo_path) {
	cout << "Photo "<< photo_path <<" was processed by " << name_;
	count_photo_++;
	cout << " Количество фото в портифолио " << count_photo_ << endl << endl;
}