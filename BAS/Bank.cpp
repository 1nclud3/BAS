#include "Bank.h"
#include <iostream>

using namespace std;

Bank::Bank()
{
	liczba_kont = 0;
	liczba_pkont = 0;
}

Bank::Bank(const Bank &wzor)
{
	delete[] baza_kont;
	delete[] tymczasowa_baza;
	delete[] baza_pkont;
	delete[] tymczasowa_pbaza;
	liczba_kont = wzor.LiczbaKont();
	baza_kont = wzor.baza_kont;
	tymczasowa_baza = wzor.tymczasowa_baza;
	liczba_pkont = wzor.LiczbaPkont();
	baza_pkont = wzor.baza_pkont;
	tymczasowa_pbaza = wzor.tymczasowa_pbaza;
}

Bank::~Bank()
{
}

Bank & Bank::operator=(const Bank &wzor)
{
	delete[] baza_kont;
	delete[] tymczasowa_baza;
	delete[] baza_pkont;
	delete[] tymczasowa_pbaza;
	liczba_kont = wzor.LiczbaKont();
	baza_kont = wzor.baza_kont;
	tymczasowa_baza = wzor.tymczasowa_baza;
	liczba_pkont = wzor.LiczbaPkont();
	baza_pkont = wzor.baza_pkont;
	tymczasowa_pbaza = wzor.tymczasowa_pbaza;
	return *this;
}

int Bank::LiczbaKont() const
{
	return liczba_kont;
}

int Bank::LiczbaPkont() const
{
	return liczba_pkont;
}

int Bank::Logowanie(int numer, string haslo) const
{
	for (int i = 0; i < liczba_kont; i++)
		if ((numer == baza_kont[i].Numer()) && (haslo == baza_kont[i].Haslo()))
			return i;
	return -1;
}

int Bank::SzukaniePkonta(int numer) const
{
	for (int i = 0; i < liczba_pkont; i++)
		if ((numer == baza_pkont[i].KontoGlowne()))
			return i;
	return -1;
}

Konto* Bank::BazaKont(int index) const
{
	return &baza_kont[index];
}

Podkonto* Bank::BazaPkont(int index) const
{
	return &baza_pkont[index];
}

void Bank::DodajKonto()
{
	Konto konto1;
	konto1.Wpisz();
	if (liczba_kont != 0)
	{
		tymczasowa_baza = new Konto[liczba_kont];
		for (int i = 0; i < liczba_kont; i++)
			tymczasowa_baza[i] = *(baza_kont+i);
		baza_kont = new Konto[(liczba_kont + 1)];
		for (int i = 0; i < liczba_kont; i++)
			baza_kont[i] = *(tymczasowa_baza+i);
		baza_kont[liczba_kont] = konto1;
		liczba_kont++;
		delete[] tymczasowa_baza;
	}
	else
	{
		baza_kont = new Konto[1];
		baza_kont[liczba_kont] = konto1;
		liczba_kont++;
	}
}

void Bank::WpiszKonto(Konto nowe_konto)
{
	if (liczba_kont != 0)
	{
		tymczasowa_baza = new Konto[liczba_kont];
		for (int i = 0; i < liczba_kont; i++)
			tymczasowa_baza[i] = *(baza_kont + i);
		baza_kont = new Konto[(liczba_kont + 1)];
		for (int i = 0; i < liczba_kont; i++)
			baza_kont[i] = *(tymczasowa_baza + i);
		baza_kont[liczba_kont] = nowe_konto;
		liczba_kont++;
		delete[] tymczasowa_baza;
	}
	else
	{
		baza_kont = new Konto[1];
		baza_kont[liczba_kont] = nowe_konto;
		liczba_kont++;
	}
}

void Bank::Wypisz() const
{
	for (int i = 0; i < liczba_kont; i++)
	{
		cout << "Numer konta w systemie: " << i + 1;
		baza_kont[i].Wypisz();
		cout << "\n";
	}
	for (int i = 0; i < liczba_pkont; i++)
	{
		cout << "Numer podkonta w systemie: " << i + 1;
		baza_pkont[i].Wypisz();
		cout << "\n";
	}
}

void Bank::Przelew(int numer_konta_wlasciciela, int numer_konta_adresata, int kwota)
{
	for (int i = 0; i < liczba_kont; i++)
		if (baza_kont[i].Numer() == numer_konta_wlasciciela)
		{
			if (baza_kont[i].Saldo() < kwota)
			{
				cout << "Za malo srodkow na koncie\n";
				return;
			}
			else
				for (int j = 0; j < liczba_kont; j++)
					if (baza_kont[j].Numer() == numer_konta_adresata)
					{
						baza_kont[j].Saldo((baza_kont[j].Saldo() + kwota));
						baza_kont[i].Saldo((baza_kont[i].Saldo() - kwota));
						cout << "Kwota zostala wyslana\n";
						return;
					}
		}
	cout << "Nie znaleziono podanego numeru konta";
}

void Bank::UsunKonto(int numer_konta)
{
	for (int i = 0; i < liczba_pkont; i++)
		if (baza_pkont[i].KontoGlowne() == numer_konta)
		{
			tymczasowa_pbaza = new Podkonto[liczba_pkont];
			for (int j = 0; j < liczba_pkont; j++)
				tymczasowa_pbaza[j] = *(baza_pkont + j);
			delete[] baza_pkont;
			baza_pkont = new Podkonto[(liczba_pkont - 1)];
			for (int j = 0, k = 0; k < liczba_pkont; j++, k++)
			{
				if (k == i)
					j--;
				else
					baza_pkont[j] = *(tymczasowa_pbaza + k);
			}
			delete[] tymczasowa_pbaza;
			liczba_pkont--;
		}
	for (int i = 0; i < liczba_kont; i++)
		if (baza_kont[i].Numer() == numer_konta)
		{
			tymczasowa_baza = new Konto[liczba_kont];
			for (int j = 0; j < liczba_kont; j++)
				tymczasowa_baza[j] = *(baza_kont + j);
			delete[] baza_kont;
			baza_kont = new Konto[(liczba_kont - 1)];
			for (int j = 0, k = 0; k < liczba_kont; j++, k++)
			{
				if (k == i)
					j --;
				else
					baza_kont[j] = *(tymczasowa_baza + k);
			}
			delete[] tymczasowa_baza;
			liczba_kont --;
			cout << "Konto zostalo usuniete\n";
			return;
		}
	cout << "Nie odnaleziono konta o podanym numerze\n";
}

void Bank::DodajPkonto(int numer_konta)
{
	for (int i = 0; i < liczba_kont; i++)
		if (baza_kont[i].Numer() == numer_konta)
		{
			Podkonto podkonto1(*(baza_kont + i));
			if (liczba_pkont != 0)
			{
				tymczasowa_pbaza = new Podkonto[liczba_pkont];
				for (int j = 0; j < liczba_kont; j++)
					tymczasowa_pbaza[j] = *(baza_pkont + j);
				baza_pkont = new Podkonto[(liczba_pkont + 1)];
				for (int j = 0; j < liczba_pkont; j++)
					baza_pkont[j] = *(tymczasowa_pbaza + j);
				baza_kont[liczba_kont] = podkonto1;
				liczba_pkont++;
				delete[] tymczasowa_pbaza;
			}
			else
			{
				baza_pkont = new Podkonto[1];
				baza_pkont[liczba_pkont] = podkonto1;
				liczba_pkont++;
			}
		}
}