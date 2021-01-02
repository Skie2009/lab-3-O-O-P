#include "Designer.h"
 


Designer::Designer() : Employee() {
	cout << "Дизайнер " << name_ << " " << surname_ << " занесен в базу" << endl << endl;
}

Designer::Designer(const string& name, const string& surname, char gender, short year_birth, short year_start, const string& phone) : Employee(name, surname, gender, year_birth, year_start, phone) {
	cout << "Дизайнер " << name_ << " " << surname_ << " занесен в базу" << endl << endl;
}

Designer::~Designer() {
	cout << "Дизайнер " << name_ << " " << surname_ << " уволен к чертям!" << endl << endl;
}

ostream& Designer::operator<<(ostream& out) {

	out << "Имя дизайнера " << name_ << endl;
	out << "Фамилия дизайнера " << surname_ << endl;
	out << "Пол дизайнера " << gender_ << endl;
	out << "Год рождения дизайнера " << year_birth_ << endl;
	out << "Год начала карьеры дизайнера " << year_start_ << endl;
	out << "Телефон дизайнера " << phone_ << endl<<endl;
	
	return out;
}

void Designer::serialize()const {
	const string path = name_ + ".txt";
	ofstream fout(path);
	if (fout.is_open()) {
		fout << "Имя дизайнера " << name_ << endl;
		fout << "Фамилия дизайнера " << surname_ << endl;
		fout << "Пол дизайнера " << gender_ << endl;
		fout << "Год рождения дизайнера " << year_birth_ << endl;
		fout << "Год начала карьеры дизайнера " << year_start_ << endl;
		fout << "Телефон дизайнера " << phone_ << endl << endl;
	}
	fout.close();
}

void Designer::PrintStatistics() {
	*this << cout;
}

void Designer::Imitation() {
	cout << "--------------------------------START Imitation--------------------------" << endl;
	for (size_t i = 0; i < 3; i++) {
		cout << "Картина №" << i + 1 << endl;
		//srand(time(i));

		int votes = rand() % 30;
		if (votes >= 10) {
			rating_ += rand() % 10 + 1;
		}
		cout << "Проголосовало: " << votes << " за дизайнера " << name_ << endl;
		cout << "Текущий рейтинг: " << rating_ << " дизайнера " << name_ << " " << surname_ << endl << endl;
		cout << "--------------------------------Imitation-------------------------------------" << endl;
	}
	cout << "--------------------------------END Imitation-----------------------------" << endl;
}

void Designer::Process(const string& photo_path) {
	cout << "Image "<<photo_path<<" was produced by " << name_<<endl;
	int t = rand() % 10 + 1;
	rating_ += t;
	cout << "Рейтинг нарастился на " << t << ". Текущий рейтинг: " << rating_<<endl<<endl;
}