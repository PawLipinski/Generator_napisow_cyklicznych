#include "stdafx.h"
#include "baza.h"

char Znak::pobierz(char z1, Znak* n)
{
	znak = z1;
	nast = n;

	return z1;
}

bool Znak::wyswietl()
{
	std::cout << znak;
	return 0;
}

Znak::Znak(char z1, Znak *n)
{
	znak = z1;
	nast = n;
}

Znak::~Znak()
{
}

void Rejestr::Ustaw()
{
	Zeruj(1);
	char pom;

	Znak *czasowy;
	Znak *ogon;

	Znak *nowy1 = new Znak;
	head = nowy1;
	czasowy = nowy1;
	ogon = czasowy;

	pom=getchar();
	pobierz(pom, nowy1);

	while (1)
	{
		pom = getchar();
		if ((pom != '\n') && (pom != ' ') && ((pom != '\0')))
		{
			ogon = czasowy;
			Znak *nowy2 = new Znak;
			czasowy->pobierz(pom, nowy2);
			tail = czasowy;
			czasowy = nowy2;
		}

		else
		{
			tail = ogon;
			ogon->nast = NULL;
			break;
		}
	}
}

void Rejestr::Ogon()
{
	std::cout << tail->znak;
	std::cout << "x";
	std::cout << "\n";
}

void Rejestr::Wypisz()
{
	Znak *temp = head;

	if (head == NULL) std::cout << "\n";
	else
	{
		while (1)
		{
			if (temp != tail)
			{
				temp->wyswietl();
				temp = temp->nast;
			}
			else
			{
				temp->wyswietl();
				break;
			}
		}
		std::cout << "\n";
	}
}

void Rejestr::Odwroc()
{
	Znak *pom1, *pom2, *pom3;

	pom3 = tail;
	tail = head;
	head = pom3;

	pom1 = tail;
	pom2 = tail->nast;
	pom3 = pom1;
	tail->nast = NULL;

	do
	{
		pom1 = pom2;
		pom2 = pom2->nast;
		pom1->nast = pom3;

		pom3 = pom1;

	} while (pom1 != head);
}

void Rejestr::Zeruj(bool x)
{
	head = NULL;
	tail = NULL;
}

bool Rejestr::Zeruj()
{
	if (head != NULL)
	{
		Znak *czasowy = head;
		Znak *pomocniczy = czasowy->nast;
		Znak *roboczy = head;

		while (pomocniczy != NULL)
		{
			pomocniczy = czasowy->nast;
			roboczy = czasowy;
			delete czasowy;
			czasowy = pomocniczy;
		}

		head = roboczy;
		Zeruj(1);
		return 1;
	}
	else return 0;
}

void Rejestr::Przesun(long n)
{
	Znak *temp = head;
	double i = 0;

	while ( i< n - 1)
	{
		temp = temp->nast;
		i++;
	}
	tail->nast = head;
	head = temp->nast;
	tail = temp;
	tail->nast = NULL;
}

void Rejestr::Usun(long n)
{
	Znak *czasow = head;
	Znak*pomoc = head;

	for (long i = 0; i < n; i++)
	{
		pomoc = czasow;
		czasow = czasow->nast;
		delete pomoc;
	}
	head = czasow;
}

int Rejestr::Dlugosc()
{
	int i = 0;
	Znak *czasow = head;

	while (czasow->nast != NULL)
	{
		i++;
		czasow = czasow->nast;
	}
	return i;
}

Rejestr::Rejestr(char z, Znak *n)
:Znak(z,n)
{
	Zeruj(1);
}

Rejestr::~Rejestr()
{
}

void TabRejestr::Doklej(int a,int b)
{
		tablica[a].tail->nast = tablica[b].head;
		tablica[a].tail = tablica[b].tail;
		tablica[b].Zeruj(1);
}

void TabRejestr::Skopiuj(int a, int b)
{
	Rejestr *dodawany = new Rejestr;
	Znak *czasowy = tablica[b].head;
	Znak *nowy1 = new Znak;
	Znak *roboczy = nowy1;

	nowy1->znak = czasowy->znak;

	while (1)
	{
		if (czasowy != tablica[b].tail)
		{
			czasowy = czasowy->nast;
			Znak *nowy2 = new Znak;
			nowy2->znak = czasowy->znak;
			roboczy->nast = nowy2;
			roboczy = nowy2;
		}

		else
		{
			Znak *nowy2 = new Znak;
			nowy2->znak = czasowy->znak;
			roboczy->nast = nowy2;
			nowy2->nast = NULL;
			break;
		}
	}

	if (tablica[a].head == NULL)
	{
		tablica[a].head = nowy1;
		tablica[a].tail = roboczy;
		tablica[a].tail->nast = NULL;
	}
		tablica[a].tail->nast = nowy1;
		tablica[a].tail = roboczy;
		tablica[a].tail->nast = NULL;
}

void TabRejestr::Mieszaj(int a, int b)
{
	Znak *pom1;
	Znak *pom2;
	Znak *pom3;
	Znak *pom4;

	if (tablica[a].Dlugosc() > tablica[b].Dlugosc())
	{
		tablica[b].tail = tablica[a].tail;

		pom1 = tablica[a].head;
		pom2 = tablica[b].head;
		while (pom2 != NULL)
		{
			pom3 = pom1->nast;
			pom4 = pom2->nast;
			pom1->nast = pom2;
			pom2->nast = pom3;
			pom1 = pom3;
			pom2 = pom4;
		}
	}

	else
	{
		tablica[a].tail = tablica[b].tail;

		pom1 = tablica[a].head;
		pom2 = tablica[b].head;
		pom3 = pom1->nast;
		while (pom1->nast != NULL)
		{
			pom3 = pom1->nast;
			pom4 = pom2->nast;
			pom1->nast = pom2;
			pom2->nast = pom3;
			pom1 = pom3;
			pom2 = pom4;
		}
		pom1->nast = pom2;
	}

	tablica[b].Zeruj(1);
}

void TabRejestr::Wprowadzanie()
{
	char pol[20];
	char r = '0', s = '0';
	int r2, s2;
	long n;

	while ((std::cin >> pol) &&(pol[0]!=NULL)&& (pol[0] != EOF))
	{
		std::cin >> r;
		r2 = (int)r - 65;

		switch (pol[0])
		{
		case 'Z':
			tablica[r2].Zeruj();
			break;

		case 'W':
			tablica[r2].Wypisz();
			break;

		case 'O':
			tablica[r2].Odwroc();

			break;

		case 'U':
			if (pol[2] == 'T')
			{
				tablica[r2].Ustaw();
				break;
			}
			else
			{
				std::cin >> n;
				tablica[r2].Usun(n);
				break;
			}

		case 'P':
			std::cin >> n;
			tablica[r2].Przesun(n);
			break;

		case 'D':
			std::cin >> s;
			s2 = (int)s - 65;
			Doklej(r2, s2);
			break;

		case 'S':
			std::cin >> s;
			s2 = (int)s - 65;
			Skopiuj(r2, s2);
			break;

		case 'M':
			std::cin >> s;
			s2 = (int)s - 65;
			Mieszaj(r2, s2);
			break;
		default:
			std::cout << "Nie ma takiego polecenia" << std::endl;
			break;
		}
	}
}

TabRejestr::TabRejestr()
{
	Rejestr *tab1 = new Rejestr[Size];

	tablica = tab1;

}

TabRejestr::~TabRejestr()
{
	delete[] tablica;
}


