#pragma once
#include "Uzytkownik.h"
#include "Konto.h"

class Podkonto : public Konto
{
public:
	Podkonto();
	Podkonto(const Podkonto &wzor);
	Podkonto(Konto konto_glowne);
	~Podkonto();
	Podkonto & operator=(const Podkonto &wzor);
	int KontoGlowne() const;
	void Wypisz() const;
	int Wplac(Konto konto_glowne);
	int Wyplac(Konto konto_glowne);
private:
	int p_konto_glowne;
	int k_numer;
	int k_saldo;
	Uzytkownik k_wlasciciel;
};