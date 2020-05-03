#include <iostream>
#include <fstream>
using namespace std;
struct Date {
	short day;
	short month;
	short year;
	bool isCorrect();
};

bool Date::isCorrect()
{
	bool result = false;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		if ((day <= 31) && (day > 0))
			result = true;
		break;
	}

	case 4:
	case 6:
	case 9:
	case 11:
	{
		if ((day <= 30) && (day > 0))
			result = true;
		break;
	}

	case 2:
	{
		if (year % 4 != 0)
		{
			if ((day <= 28) && (day > 0))
				result = true;
		}
		else
			if (year % 400 == 0)
			{
				if ((day <= 29) && (day > 0))
					result = true;
			}
			else
				if ((year % 100 == 0) && (year % 400 != 0))
				{
					if ((day == 28) && (day > 0))
						result = true;
				}
				else
					if ((year % 4 == 0) && (year % 100 != 0))
						if ((day <= 29) && (day > 0))
							result = true;
		break;
	}

	default:
		result = false;
	}

	return result;
}
struct Human
{
	char Surname[64];		//Фамилия
	char Name[64];			//Имя
	char Middlename[64];	//Отчетсво
	char Gender[64];		//Пол
	char Nationality[64];	//Национальность
	int Height;				//Рост
	int Weight;				//Вес
	Date birthday;
	int number;				//Номер
	char adress[128];		//Адрес

};


int main()
{
	setlocale(LC_ALL, "RUS");

	const int N = 1;
	Human group[N];

	ofstream F;
	F.open("D:\\games\\Human.txt", ios::out);
	
	for (int i = 0; i < N; i++)
	{
		cout << "\n............Human..[" << i + 1 << "]........" << endl;
		cout << "\nВведите Фамилию: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].Surname, 64);

		cout << "\nВвдеите Имя: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].Name, 64);

		cout << "\nВведите Отчество: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].Middlename, 64);

		cout << "\nВведите Пол: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].Gender, 64);

		cout << "\nВведите Национальность: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].Nationality, 64);

		cout << "\nВведите Рост: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> group[i].Height;

		cout << "\nВведите Вес: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> group[i].Weight;

		do
		{
			cout << "\nВведите Дату Рождения: ";
			cin.ignore(std::cin.rdbuf()->in_avail());
			cin >> group[i].birthday.day >> group[i].birthday.month >> group[i].birthday.year;
		} while (!group[i].birthday.isCorrect());
		cin.clear();

		cout << "\nВведите Номер Телефона: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> group[i].number;

		cout << "\nВведите Дом. Адрес: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> group[i].adress;

	}
	
	
	for (int i = 0; i < N; i++)
	{
		cout << "\n...............DATA......................" << endl;
		cout << "\nФИО: " << group[i].Surname << " " << group[i].Name << " " << group[i].Middlename;
		cout << "\nПол: " << group[i].Gender;
		cout << "\nНациональность: " << group[i].Nationality;
		cout << "\nРост: " << group[i].Height;
		cout << "\nВес: " << group[i].Weight;
		cout << "\nДата Рождения: " << group[i].birthday.day << "." << group[i].birthday.month << "." << group[i].birthday.year;
		cout << "\nНомер Телефона: " << group[i].number;
		cout << "\nДом. Адрес: " << group[i].adress << endl;
		
	}
	for (int i = 0; i < N; i++)
	{
		F << "ФИО: " << group[i].Surname << " " << group[i].Name << " " << group[i].Middlename << "\n" <<"Пол: "<< group[i].Gender << "\n" <<"Национальность: "<< group[i].Nationality << "\n" <<"Рост: "<< group[i].Height << "\n"
			<<"Вес: "<< group[i].Weight << "\n" <<"Дата Рождения: "<< group[i].birthday.day << "." << group[i].birthday.month << "." << group[i].birthday.year << "\n" <<"Номер Телефона: "<< group[i].number << "\n" <<"Дом. Адрес:"<< group[i].adress << "\n" << endl;
	}
	F.close();
	system("pause");
	return 0;
}