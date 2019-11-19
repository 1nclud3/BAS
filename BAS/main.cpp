#include "Data.h"
#include "Uzytkownik.h"
#include "Konto.h"
#include "Podkonto.h"
#include "Bank.h"
#include <iostream>

using namespace std;

int main()
{
	Bank bank1;
	Uzytkownik uzytkownik0("admin", "admin");
	Konto konto0(100000, "haslo", 500, 0, uzytkownik0);
	bank1.WpiszKonto(konto0);
	int zalogowano = -1;
	system("cls");

	cout << "\t\t\t\t*****WITAJ W PROGRAMIE BANK ACCOUNT SIMULATOR*****\n";
	cout << "PROGRAM POSIADA KONTO TESTOWE O DANYCH LOGOWANIA:\n";
	cout << "NUMER: 100000\nHASLO: haslo\n";
	cout << "KORZYSTAJ Z NIEGO PRZY TESTOWANIU FUNKCJI PROGRAMU";
	cin.get();
	system("cls");

	while (1)
	{
		if (zalogowano == -1)
		{
			system("cls");
			cout << "1 - Logowanie\n";
			cout << "2 - Utworz konto\n";
			cout << "0 - Zamknij program\n";
			int opcja;
			cin >> opcja;
			switch (opcja)
			{
			case 1:
			{
				system("cls");
				cout << "LOGOWANIE\n";
				cout << "Podaj swoj numer konta: ";
				int numer;
				cin >> numer;
				cout << "Podaj swoje haslo: ";
				string haslo;
				cin >> haslo;
				if ((bank1.Logowanie(numer, haslo)) != -1)
				{
					cout << "Poprawnie zalogowano\n";
					zalogowano = (bank1.Logowanie(numer, haslo));
					cin.get();
					cin.get();
					continue;
				}
				else
				{
					cout << "Podano bledne dane\n";
					cin.get();
					cin.get();
					continue;
				}
			}
			case 2:
			{
				system("cls");
				cout << "REJSTRACJA\n";
				bank1.DodajKonto();
				cout << "Twoje konto zostalo utworzone, mozesz sie zalogowac z ekranu glownego\n";
				cout << "Koniecznie zapamietaj swoj numer konta oraz haslo\n";
				cin.get();
				cin.get();
				continue;
			}
			case 0:
				return 0;
			case 86:
			{
				system("cls");
				bank1.Wypisz();
				cin.get();
				cin.get();
				continue;
			}
			default:
				continue;
			}
		}

		if (zalogowano != -1)
		{
			Konto* akt_konto = bank1.BazaKont(zalogowano);
			int pkonto = (bank1.SzukaniePkonta((*(akt_konto)).Numer()));
			Podkonto* akt_pkonto = bank1.BazaPkont(pkonto);
			system("cls");
			cout << "Zalogowales sie do swojego konta, co chcesz zrobic?\n\n";
			cout << "1 - Zarzadzanie kontem\n";
			cout << "2 - Operacje finansowe\n";
			cout << "3 - Pozyczki i oszczednosci\n";
			cout << "0 - Wyloguj\n";
			int opcja;
			cin >> opcja;
			switch (opcja)
			{
			case 1:
			{
				system("cls");
				cout << "ZARZADZANIE KONTEM\n";
				cout << "1 - Wyswietl pelne dane Twojego konta\n";
				cout << "2 - Sprawdz saldo\n";
				cout << "3 - Sprawdz swoje zadluzenie\n";
				cout << "4 - Zmien haslo\n";
				cout << "5 - Usun konto\n";
				cout << "0 - Wroc\n";
				int lokopcja;
				cin >> lokopcja;
				switch (lokopcja)
				{
				case 1:
				{
					system("cls");
					(*(akt_konto)).Wypisz();
					cin.get();
					cin.get();
					continue;
				}
				case 2:
				{
					system("cls");
					(*(akt_konto)).WypiszSaldo();
					cin.get();
					cin.get();
					continue;
				}
				case 3:
				{
					system("cls");
					(*(akt_konto)).WypiszZadluzenie();
					cin.get();
					cin.get();
					continue;
				}
				case 4:
				{
					system("cls");
					(*(akt_konto)).ZmianaHasla();
					cin.get();
					cin.get();
					continue;
				}
				case 5:
				{
					int numer = (*(akt_konto)).Numer();
					system("cls");
					bank1.UsunKonto(numer);
					zalogowano = -1;
					cin.get();
					cin.get();
					continue;
				}
				case 0:
					continue;
				default:
					continue;
				}
			}
			case 2:
			{
				system("cls");
				cout << "OPERACJE FINANSOWE\n";
				cout << "1 - Wplac srodki na konto\n";
				cout << "2 - Wyplac srodki\n";
				cout << "3 - Wykonaj przelew\n";
				cout << "0 - Wroc\n";
				int lokopcja;
				cin >> lokopcja;
				switch (lokopcja)
				{
				case 1:
				{
					system("cls");
					(*(akt_konto)).Wplac();
					cin.get();
					cin.get();
					continue;
				}
				case 2:
				{
					system("cls");
					(*(akt_konto)).Wyplac();
					cin.get();
					cin.get();
					continue;
				}
				case 3:
				{
					int numer_wl = (*(akt_konto)).Numer();
					system("cls");
					cout << "Podaj numer konta adresata: ";
					int numer_adr;
					cin >> numer_adr;
					cout << "Podaj kwote jaka chcesz przelac: ";
					int przelew;
					cin >> przelew;
					bank1.Przelew(numer_wl, numer_adr, przelew);
					(*(akt_konto)).WypiszSaldo();
					cin.get();
					cin.get();
					continue;
				}
				case 0:
					continue;
				default:
					continue;
				}
			}
			case 3:
			{
				system("cls");
				cout << "POZYCZKI I OSZCZEDNOSCI\n";
				cout << "1 - Wez pozyczke\n";
				cout << "2 - Splac pozyczke\n";
				cout << "3 - Otworz konto oszczednosciowe\n";
				cout << "4 - Sprawdz stan konta oszczednosciowego\n";
				cout << "5 - Wplac srodki na konto oszzednosciowe\n";
				cout << "6 - Wyplac srodki z konta oszczednosciowego\n";
				cout << "0 - Wroc\n";
				int lokopcja;
				cin >> lokopcja;
				switch (lokopcja)
				{
				case 1:
				{
					system("cls");
					(*(akt_konto)).Pozyczka();
					cin.get();
					cin.get();
					continue;
				}
				case 2:
				{
					system("cls");
					(*(akt_konto)).Splac();
					cin.get();
					cin.get();
					continue;
				}
				case 3:
				{
					int numer_wl = (*(akt_konto)).Numer();
					system("cls");
					bank1.DodajPkonto(numer_wl);
					cout << "Konto oszczednosciowe zostalo utworzone\n";
					cout << "Przy kazdej wplacie na konto oszczednosciowe zyskujesz dodatkowe 10%\n";
					cout << "Wyplacic mozesz jedynie kwote wieksza niz 1000\n";
					cin.get();
					cin.get();
					continue;
				}
				case 4:
				{
					if (pkonto == -1)
						continue;
					system("cls");
					(*(akt_pkonto)).Wypisz();
					cin.get();
					cin.get();
					continue;
				}
				case 5:
				{
					if (pkonto == -1)
						continue;
					system("cls");
					int k = (*(akt_pkonto)).Wplac((*(akt_konto)));
					int l = (*(akt_konto)).Saldo();
					int w = l - k;
					(*(akt_konto)).Saldo(w);
					cin.get();
					cin.get();
					continue;
				}
				case 6:
				{
					if (pkonto == -1)
						continue;
					system("cls");
					int k = (*(akt_pkonto)).Wyplac((*(akt_konto)));
					int l = (*(akt_konto)).Saldo();
					int w = l + k;
					cin.get();
					cin.get();
					continue;
				}
				case 0:
					continue;
				default:
					continue;
				}
			}
			case 0:
			{
				zalogowano = -1;
				cout << "Poprawnie wylogowano\n";
				cin.get();
				cin.get();
				continue;
			}
			}
		}
	}	
	cin.get();
	cin.get();

	return 0;
}