#ifndef MACIERZ
#define MACIERZ
#include <list>
#include <vector>
#include <fstream>

using namespace std;

class Macierz{
public:
	vector<vector<double>> Mwk;
	vector<vector<double>> Mkw;
	int n;
	int m;
	void ZaalokujMwk();
	void ZaalokujMkw();
	void MkwZMwk();
	double IloczynSkalarny(vector<double> a, vector<double> b, int n);
	
public:
	Macierz(){}
	Macierz(int n, int m);		//wypelnia macierz zerami
	Macierz(list<list<double>> Elementy);	//tworzenie macierzy przez wczytywanie z list
	Macierz(vector<vector<double>> Elementy);
	//Macierz(double **Mwk, int n, int m):Mwk(Mwk),n(n),m(m){ZaalokujMkw();MkwZMwk();}	
	//Macierz(fstream &fs);	//tworzenie macierzy przez wczytywanie z pliku
	Macierz operator+(Macierz &N); //dodawanie macierzy
	Macierz operator*(Macierz &N); //mnozenie macierzy
	Macierz operator-(Macierz &N); //odejmowanie macierzy
	Macierz operator*(double t);	//mnozenie przez skalar
	Macierz Transponowana();
};

#endif