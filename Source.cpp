#include <iostream>
#include <list>
#include "Macierz.h"
#include "PracaZPlikiem.h"
#include "KMacierz.h"
#include "UkladRownan.h"

using namespace std;

int main(){

	list<list<double>> Elementy;
	list<double> la;


	la.push_back(2.0);
	la.push_back(1.0);
	la.push_back(1.0);

	Elementy.push_back(la);
	Elementy.push_back(la);
	Elementy.push_back(la);

	Macierz M(Elementy);
	Macierz M1 = M.Transponowana();
	Macierz M3 = M*M;

	PracaZPlikiem PZP("Plik1.txt");
	PracaZPlikiem PZP2("Plik2.txt");
	vector<vector<double>> W = PZP.WczytajMacierz();
	KMacierz M4(W);
	Macierz M5(PZP2.WczytajMacierz());
	UkladRownan UK(M4,M5);
	UK.RozwiazUklad();
	//M4.ObliczDet();
	//KMacierz M5 = M4.Odwrotna();
	PZP.ZapiszMacierz(UK.X.Mwk);
return 0;
}