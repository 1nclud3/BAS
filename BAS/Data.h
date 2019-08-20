#pragma once

class Data
{
public:
	Data();
	Data(const Data &wzor);
	~Data();
	Data & operator=(const Data &wzor);
	int Dzien() const;
	int Miesiac() const;
	int Rok() const;
	void Ustaw(int dzien, int miesiac, int rok);
	void Wpisz();
	void Koryguj();
	void Wypisz() const;
private:
	int d_Dzien;
	int d_Miesiac;
	int d_Rok;
};