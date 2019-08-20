#include "Uzytkownik.h"
#include <iostream>

using namespace std;

Uzytkownik::Uzytkownik()
{
}

Uzytkownik::Uzytkownik(const Uzytkownik &wzor)
{
	u_imie = wzor.Imie();
	u_nazwisko = wzor.Nazwisko();
	u_data_urodzenia = wzor.u_data_urodzenia;
}

Uzytkownik::Uzytkownik(const char* imie, const char* nazwisko)
{
	u_imie = imie;
	u_nazwisko = nazwisko;
	Data data1;
	data1.Ustaw(1, 1, 1920);
	u_data_urodzenia = data1;
}

Uzytkownik::~Uzytkownik()
{
}

Uzytkownik & Uzytkownik::operator=(const Uzytkownik &wzor)
{
	u_imie = wzor.Imie();
	u_nazwisko = wzor.Nazwisko();
	u_data_urodzenia = wzor.u_data_urodzenia;
	return *this;
}

string Uzytkownik::Imie() const
{
	return u_imie;
}

string Uzytkownik::Nazwisko() const
{
	return u_nazwisko;
}

void Uzytkownik::Imie(string nowe_imie)
{
	u_imie = nowe_imie;
}

void Uzytkownik::Nazwisko(string nowe_nazwisko)
{
	u_nazwisko = nowe_nazwisko;
}

void Uzytkownik::DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok)
{
	Data data1;
	data1.Ustaw(nowy_dzien, nowy_miesiac, nowy_rok);
	u_data_urodzenia = data1;
}

void Uzytkownik::Wpisz()
{
	cout << "imie: ";
	string imie;
	cin >> imie;
	Imie(imie);

	cout << "nazwisko: ";
	string nazwisko;
	cin >> nazwisko;
	Nazwisko(nazwisko);

	int dzien, miesiac, rok;
	cout << "Podaj date urodzenia:\n";
	cout << "Podaj dzien: ";
	cin >> dzien;
	cout << "Podaj miesiac: ";
	cin >> miesiac;
	cout << "Podaj rok: ";
	cin >> rok;
	DataUrodzenia(dzien, miesiac, rok);
}

void Uzytkownik::Wypisz() const
{
	cout << u_imie << " " << u_nazwisko << " ";
	u_data_urodzenia.Wypisz();
}