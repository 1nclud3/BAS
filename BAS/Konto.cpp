#include "Konto.h"
#include "Podkonto.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Konto::Konto()
{
	k_saldo = 0;
	k_zadluzenie = 0;
}

Konto::Konto(const Konto &wzor)
{
	k_numer = wzor.Numer();
	k_haslo = wzor.Haslo();
	k_saldo = wzor.Saldo();
	k_zadluzenie = wzor.Zadluzenie();
	k_wlasciciel = wzor.k_wlasciciel;
}

Konto::Konto(int numer, const char* haslo, int saldo, int zadluzenie, Uzytkownik wlasciciel)
{
	k_numer = numer;
	k_haslo = haslo;
	k_saldo = saldo;
	k_zadluzenie = zadluzenie;
	k_wlasciciel = wlasciciel;
}

Konto::~Konto()
{
}

Konto & Konto::operator=(const Konto &wzor)
{
	k_numer = wzor.Numer();
	k_haslo = wzor.Haslo();
	k_saldo = wzor.Saldo();
	k_zadluzenie = wzor.Zadluzenie();
	k_wlasciciel = wzor.k_wlasciciel;
	return *this;
}

int Konto::Numer() const
{
	return k_numer;
}

string Konto::Haslo() const
{
	return k_haslo;
}

int Konto::Saldo() const
{
	return k_saldo;
}

int Konto::Zadluzenie() const
{
	return k_zadluzenie;
}

Uzytkownik Konto::Wlasciciel() const
{
	return k_wlasciciel;
}

void Konto::Numer(int nowy_numer)
{
	k_numer = nowy_numer;
}

void Konto::Haslo(string nowe_haslo)
{
	k_haslo = nowe_haslo;
}

void Konto::Saldo(int nowe_saldo)
{
	k_saldo = nowe_saldo;
}

void Konto::Zadluzenie(int nowe_zadluzenie)
{
	k_zadluzenie = nowe_zadluzenie;
}

void Konto::Wlasciciel(Uzytkownik nowy_wlasciciel)
{	
	k_wlasciciel = nowy_wlasciciel;
}

void Konto::Wpisz()
{
	srand(time(NULL));//losowanie

	Uzytkownik uzytkownik1;
	uzytkownik1.Wpisz();
	Wlasciciel(uzytkownik1);

	cout << "Podaj haslo: ";
	string haslo;
	cin >> haslo;
	Haslo(haslo);

	int numer;
	numer = (rand() % 899998) + 100001;	
	cout << "Twoj przydzielony numer konta to: " << numer << "\n";
	Numer(numer);
}

void Konto::Wypisz() const
{
	cout << "\nDane wlasciciela:\n";
	k_wlasciciel.Wypisz();
	cout << "Dane konta:\n";
	cout << "mumer: " << k_numer;
	cout << "\naktualne haslo: " << k_haslo;
	cout << "\nsaldo: " << k_saldo;
	cout << "\nzadluzenie: " << k_zadluzenie << "\n";
}

void Konto::WypiszSaldo() const
{
	cout << "Saldo: " << k_saldo << "\n";
}

void Konto::WypiszZadluzenie() const
{
	cout << "Zadluzenie: " << k_zadluzenie << "\n";
}

void Konto::ZmianaHasla()
{
	cout << "Podaj nowe haslo: ";
	string haslo;
	cin >> haslo;
	Haslo(haslo);
	cout << "Haslo zostalo zmienione\n";
}

void Konto::Wyplac()
{
	cout << "Jaka kwote chcialbys wyplacic z konta?\n";
	int kwota;
	cin >> kwota;
	if (kwota > k_saldo)
	{
		cout << "Za malo srodkow na koncie\n";
		return;
	}		
	else
	{
		k_saldo -= kwota;
		cout << "Srodki zostaly wyplacone\n";
		cout << "Na koncie pozostalo " << Saldo() << "\n";
	}
}

void Konto::Wplac()
{
	cout << "Jaka kwote chcialbys wplacic na konto?\n";
	int kwota;
	cin >> kwota;
	k_saldo += kwota;
	cout << "Srodki zostaly wplacone\n";
	cout << "Na koncie znajduje sie kwota " << Saldo() << "\n";
}

void Konto::Pozyczka()
{
	cout << "Oprocentowanie pozyczki wynosi 10%\n";
	cout << "Jaka kwote chcialbys pozyczyc od banku?\n";
	int pozyczka;
	cin >> pozyczka;
	k_saldo += pozyczka;
	k_zadluzenie += (pozyczka * 0.1 + pozyczka);
	cout << "Pozyczka udzielona!\n";
	cout << "Twoje zadluzenie wynosi " << k_zadluzenie << "\n";
	WypiszSaldo();
}

void Konto::Splac()
{
	cout << "Twoje zadluzenie wynosi " << k_zadluzenie << "\n";
	cout << "Jaka kwote chcialbys splacic?\n";
	int kwota;
	cin >> kwota;
	if (kwota > k_saldo)
	{
		cout << "Za malo srodkow na koncie\n";
		return;
	}
	if (kwota > k_zadluzenie)
	{
		cout << "Podana kwota jest za duza\n";
		return;
	}
	k_saldo -= kwota;
	k_zadluzenie -= kwota;
	cout << "Twoje zadluzenie wynosi " << k_zadluzenie << "\n";
	WypiszSaldo();
}