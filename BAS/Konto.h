#pragma once
#include "Uzytkownik.h"

class Konto
{
public:
	Konto();
	Konto(const Konto &wzor);
	Konto(int numer, const char* haslo, int saldo, int zadluzenie, Uzytkownik wlasciciel);
	~Konto();
	Konto & operator=(const Konto &wzor);
	int Numer() const;
	string Haslo() const;
	int Saldo() const;
	int Zadluzenie() const;
	Uzytkownik Wlasciciel() const;
	void Numer(int nowy_numer);
	void Haslo(string nowe_haslo);
	void Saldo(int nowe_saldo);
	void Zadluzenie(int nowe_zadluzenie);
	void Wlasciciel(Uzytkownik nowy_wlasciciel);
	void Wpisz();
	void virtual Wypisz() const;
	void WypiszSaldo() const;
	void WypiszZadluzenie() const;
	void ZmianaHasla();
	void Wyplac();
	void Wplac();
	void Pozyczka();
	void Splac();
private:
	int k_numer;
	string k_haslo;
	int k_saldo;
	int k_zadluzenie;
	Uzytkownik k_wlasciciel;
};