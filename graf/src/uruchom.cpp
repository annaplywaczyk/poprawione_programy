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
tab.wczytaj_graf(nazwa);
}

void dzialanie::algorytm()
{
//tab.DFS(0,8);
//tab.BFS(0,8);
tab.a_star(0,8);
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


