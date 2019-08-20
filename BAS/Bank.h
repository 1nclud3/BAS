#pragma once
#include "Konto.h"
#include "Podkonto.h"

class Bank
{
public:
	Bank();
	Bank(const Bank &wzor);
	~Bank();
	Bank & operator=(const Bank &wzor);
	int LiczbaKont() const;
	int LiczbaPkont() const;
	int Logowanie(int numer, string haslo) const;
	int SzukaniePkonta(int numer) const;
	Konto* BazaKont(int index) const;
	Podkonto* BazaPkont(int index) const;
	void DodajKonto();
	void WpiszKonto(Konto nowe_konto);
	void Wypisz() const;
	void Przelew(int numer_konta_wlasciciela, int numer_konta_adresata, int kwota);
	void UsunKonto(int numer_konta);
	void DodajPkonto(int numer_konta);
private:
	int liczba_kont;
	Konto* baza_kont;
	Konto* tymczasowa_baza;
	int liczba_pkont;
	Podkonto* baza_pkont;
	Podkonto* tymczasowa_pbaza;
};