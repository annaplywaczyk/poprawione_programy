#include "uruchom.hh"
#include <sstream>
#include <fstream>
#include <time.h>
#include <string>
#include <iostream>

using namespace std;



/*!
 * \file
 * \brief
 * Funkcja zmieniajaca nazwy dla roznych wielkosci problemu, aby za kazdym razem nie
 * trzeba bylo wczytywac na nowo pliku.
 * \param[in] i - zmienna wykorzystana aby zdefiniowac jaka wielkosc problemu ma byc sprawdzona w programie.
 * \return Funkcja zwraca nazwy plikow do wczytania.
 */

string zmien_nazwy(int i)
{
	// zdefiniowane zmienne oraz czesci nazw plikow, ktore sie zmieniac beda;
			string czesc_1 = "dane";
			int liczba=i;
			string czesc_2=".txt";
			string nazwa_pliku1;

			// konwersja int na string aby nazwa programu mogla sie zmieniac samoczynnie;
			ostringstream numer;
			numer << liczba;
			string element=numer.str();

			//tworzone nazwy plikow
			return nazwa_pliku1=czesc_1+element+czesc_2;
}

/*!
 * \brief
 * Funkcja otwiera plik do zapisania wnioskow i danych z obliczonym czasem pobierania wartosci
 * z tablicy asocjacyjnej. W funkcji tej wykorzystane jest rowniez powtorzenie danego problemu,
 * aby miec usredniony czas.
 */

void dzialaj()
{
	dzialanie tab;

	int a=0, il;
	ofstream plik("wnio_d.csv");
	for (il=10; il<100000000; il=il*10)
	{
		double suma=0;
		string nazwa=zmien_nazwy(il);
		tab.wczytaj(nazwa);
		cout << "wczytano " << il << endl;
		for (a=0; a<10; a++)
		{
			double czas=tab.stoper();
			cout <<"czas: "<< czas << endl;
			suma+=czas;
		}
		cout <<"suma"<<suma/10 << endl;
		//stworzenie pliku i zapisanie do niego danych o testowanym pliku

		plik << il << "," << a <<"," <<suma/10 << endl;
		plik.flush();
		tab.czysc();
	}
}



void gen_random(char *s, const int len) {
    static const char alphanum[] =
    	"abcdefghijklmnopqrstuwzyx"
    	"QWERTYUIOPLKJHGFDSAZXCVBNM"
    		"1234567890-=][';/.,";
    for (int i = 0; i < len; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    s[len] = 0;
}

/*! \brief Funkcja generuje pliki z danymi wejsciowymi
 *
 */
void generator(){
	string wejscie;
	int tab[7]={10,100,1000,10000,100000,1000000,10000000};
	ofstream plik;
	char  klucz[21];
	srand(time(NULL));
	for(int i=0; i<7; i++){
		wejscie = zmien_nazwy(tab[i]);
		plik.open(wejscie.c_str(), ios::out);
		plik << tab[i];
		for(int j=0; j<tab[i]; j++ ){
			gen_random(klucz,20);
			plik << "\n";
			plik << klucz;
		}
		plik.close();
	}
}
/*!
 * \brief
 * Przyklad uzycia i poprawnego dzialania tablicy asocjacyjnej.
 */

int main()
{
	dzialaj();
	return 0;
}


