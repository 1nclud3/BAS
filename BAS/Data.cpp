#include "Data.h"
#include <iostream>

using namespace std;

Data::Data()
{
}

Data::Data(const Data &wzor)
{
	d_Dzien = wzor.Dzien();
	d_Miesiac = wzor.Miesiac();
	d_Rok = wzor.Rok();
}

Data::~Data()
{
}

Data & Data::operator=(const Data &wzor)
{
	d_Dzien = wzor.Dzien();
	d_Miesiac = wzor.Miesiac();
	d_Rok = wzor.Rok();
	return *this;
}

int Data::Dzien() const
{
	return d_Dzien;
}

int Data::Miesiac() const
{
	return d_Miesiac;
}

int Data::Rok() const
{
	return d_Rok;
}

void Data::Ustaw(int dzien, int miesiac, int rok)
{
	d_Dzien = dzien;
	d_Miesiac = miesiac;
	d_Rok = rok;
	Koryguj();
}

void Data::Wpisz()
{
	int dzien, miesiac, rok;
	cout << "Podaj dzien: ";
	cin >> dzien;
	cout << "Podaj miesiac: ";
	cin >> miesiac;
	cout << "Podaj rok: ";
	cin >> rok;
	Ustaw(dzien, miesiac, rok);
}

void Data::Koryguj()
{
	if (d_Rok < 1920)
		d_Rok = 1920;
	if (d_Rok > 2019)
		d_Rok = 2019;
	if (d_Miesiac < 1)
		d_Miesiac = 1;
	if (d_Miesiac > 12)
		d_Miesiac = 12;
	if (d_Dzien < 1)
		d_Dzien = 1;
	if ((d_Dzien > 31) && (d_Miesiac == 1 || 3 || 5 || 7 || 8 || 10 || 12))
		d_Dzien = 31;
	if ((d_Dzien > 30) && (d_Miesiac == 4 || 6 || 9 || 11))
		d_Dzien = 30;
	if (((d_Dzien > 28) && (d_Miesiac == 2) && (d_Rok % 4 == 0) && (d_Rok % 100 != 0)) || ((d_Dzien > 28) && (d_Miesiac == 2) && (d_Rok % 400 == 0)))
	{
		d_Dzien = 29;
		return;
	}
	if ((d_Dzien > 28) && (d_Miesiac == 2))
		d_Dzien = 28;
}

void Data::Wypisz() const
{
	cout << d_Dzien << "-" << d_Miesiac << "-" << d_Rok << "\n";
}