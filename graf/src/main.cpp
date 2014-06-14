#include "uruchom.hh"


using namespace std;



int main(){

dzialanie tabl;
tabl.wczytaj("data10.txt");
int wynik;
wynik=tabl.stoper();
cout << endl<<wynik << endl;


return 0;
}
