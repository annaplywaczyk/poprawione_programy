/*
 * uruchom.cpp
 *
 *  Created on: 11 maj 2014
 *      Author: Ania
 */

#include "uruchom.hh"
#include <fstream>
#include <iostream>
#include <cstdlib>


LARGE_INTEGER dzialanie::wlaczStoper()
{
 LARGE_INTEGER start;
 DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
 QueryPerformanceCounter(&start);
 SetThreadAffinityMask(GetCurrentThread(), oldmask);
 return start;
}

LARGE_INTEGER dzialanie::wylaczStoper()
{
 LARGE_INTEGER stop;
 DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
 QueryPerformanceCounter(&stop);
 SetThreadAffinityMask(GetCurrentThread(), oldmask);
 return stop;
}

void dzialanie::wczytaj(string nazwa)
{
//dla tablicy na podstawie listy i drzewa binarnego

	ifstream plik;
	plik.open(nazwa.c_str());
	int liczba_ele;
	string klucz;
	if (!plik)
	{
		cerr << "Brak pliku!" << endl;
	}
	plik >> liczba_ele;
	for(int i=1; plik >> klucz; i++)
	{
		tablica.dodaj(klucz,i);
		if(i<11)
			klucze.push_back(klucz);
	}
	plik.close();
//dla tablicy haszującej
	/*ifstream plik;
	plik.open(nazwa.c_str());
	int liczba_ele;
	obiekt<int> elem;
	if (!plik)
	{
		cerr << "Brak pliku!" << endl;
	}
	plik >> liczba_ele;
	for(int i=1; plik >> elem.Klucz; i++)
	{
		elem.Wart_Klucza=i;
		tablica.dodaj(elem);
		if(i<11)
			klucze.push_back(elem.Klucz);
	}
	plik.close();*/
	it = klucze.begin();
}

void dzialanie::algorytm()
{
	int zmienna;
	zmienna=tablica.pobierz(*it);
	it++;
}

int dzialanie::stoper()
{
	LARGE_INTEGER start, stop;
	start=wlaczStoper();
	algorytm();
	stop=wylaczStoper();
	int wynik=stop.QuadPart-start.QuadPart;
	return wynik;
}

void dzialanie::czysc()
{
	klucze.clear();
	//tablica.clear();
}
