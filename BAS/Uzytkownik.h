#pragma once
#include "Data.h"
#include <string>

using namespace std;

class Uzytkownik
{
public:
	Uzytkownik();
	Uzytkownik(const Uzytkownik &wzor);
	Uzytkownik(const char* imie, const char* nazwisko);
	~Uzytkownik();
	Uzytkownik & operator=(const Uzytkownik &wzor);
	string Imie() const;
	string Nazwisko() const;
	void Imie(string nowe_imie);
	void Nazwisko(string nowe_nazwisko);
	void DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok);
	void Wpisz();
	void Wypisz() const;
private:
	string u_imie;
	string u_nazwisko;
	Data u_data_urodzenia;
};