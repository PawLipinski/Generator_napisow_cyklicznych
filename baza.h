#include "stdafx.h"
#include <iostream>


class Znak
{
public:
	char znak;
	Znak *nast;

public:
	char pobierz(char z1, Znak *n);
	bool wyswietl();
	Znak(char='\0', Znak* = NULL);
	~Znak();
};

class Rejestr : public Znak
{
public:
	Znak *head;
	Znak *tail;

public:
	bool Zeruj();	
	void Zeruj(bool x);
	void Wypisz();	
	void Odwroc();	
	void Ustaw();
	int RozmiarTab(char x[]);
	void Ustaw(char tab []);
	void UstawP();
	void Przesun(long n);
	void Usun(long n);	
	int Dlugosc(); //to jest moja funkcja, na potrzeby Mieszaj
	void Ogon();

	Rejestr(char='\0', Znak* = NULL);

	~Rejestr();
};

class TabRejestr : public Rejestr
{
	static const int Size = 26;
	

public:
	Rejestr *tablica;
	void Doklej(int a, int b); //jest
	void Skopiuj(int a, int b); //jest
	void Mieszaj(int a, int b); //jest
	void Wprowadzanie();

	TabRejestr();
	~TabRejestr();

};