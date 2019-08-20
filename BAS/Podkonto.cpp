#include "Podkonto.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Podkonto::Podkonto()
{
}

Podkonto::Podkonto(const Podkonto &wzor)
{
	p_konto_glowne = wzor.KontoGlowne();
	k_numer = wzor.Numer();
	k_saldo = wzor.Saldo();
	k_wlasciciel = wzor.k_wlasciciel;
}

Podkonto::Podkonto(Konto konto_glowne)
{
	srand(time(NULL));//losowanie
	p_konto_glowne = konto_glowne.Numer();
	k_numer = (rand() % 899998) + 100001;
	k_saldo = 0;
	k_wlasciciel = konto_glowne.Wlasciciel();
}

Podkonto::~Podkonto()
{
}

Podkonto & Podkonto::operator=(const Podkonto &wzor)
{
	p_konto_glowne = wzor.KontoGlowne();
	k_numer = wzor.Numer();
	k_saldo = wzor.Saldo();
	k_wlasciciel = wzor.k_wlasciciel;
	return *this;
}

int Podkonto::KontoGlowne() const
{
	return p_konto_glowne;
}

void Podkonto::Wypisz() const
{
	cout << "\nDane wlasciciela:\n";
	k_wlasciciel.Wypisz();
	cout << "Dane konta:\n";
	cout << "mumer: " << k_numer;
	cout << "\nkonto glowne: " << p_konto_glowne;
	cout << "\nsaldo: " << k_saldo << "\n";
}

int Podkonto::Wplac(Konto konto_glowne)
{
	cout << "Jaka kwote chcialbys wplacic na konto oszczednosciowe?\n";
	int kwota;
	cin >> kwota;
	if (kwota > konto_glowne.Saldo())
	{
		cout << "Za malo srodkow na koncie\n";
		return 0;
	}
	else
	{
		k_saldo += (kwota*0.1 + kwota);
		cout << "Srodki zostaly wplacone na konto oszcednosciowe\n";
		cout << "Na koncie oszcednosciowym znajduje sie kwota " << k_saldo << "\n";
		return kwota;
	}
	return 0;
}

int Podkonto::Wyplac(Konto konto_glowne)
{
	cout << "Jaka kwote chcialbys wyplacic z konta oszczednosciowego?\n";
	cout << "Musi byc ona wieksza niz 1000\n";
	int kwota;
	cin >> kwota;
	if (kwota > k_saldo)
	{
		cout << "Za malo srodkow na koncie\n";
		return 0;
	}
	else
	{
		if (kwota < 1000)
		{
			cout << "Kwota jest zbyt mala\n";
			return 0;
		}
		else
		{
			k_saldo -= kwota;
			cout << "Srodki zostaly wplacone na konto glowne\n";
			cout << "Na koncie oszcednosciowym pozostalo " << k_saldo << "\n";
			return kwota;
		}
	}	
}