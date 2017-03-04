#include "Macierz.h"
#include <iostream>

//Macierz::Macierz(fstream &fs){
//	fs.open("Plik.txt",fstream::in);	//wczytanie pliku do odczytu
//	if(!fs.is_open())		//sprawdzanie, czy plik sie otworzyl
//		exit(3);
//	streambuf *sbuf = fs.rdbuf();	//sbuf mozna czytac strumien fs
//	char t = sbuf->sgetc();	//sbumpc - odczyt elementu i przeskok do nastepnego pola
//	while(sbuf->sbumpc() != EOF)			//sgetc - odczyt i powrot do tego samego pola
//	{
//		
//	}
//}

Macierz::Macierz(vector<vector<double>> Elementy):n(Elementy.size()),m(Elementy[0].size()){
	ZaalokujMkw();
	ZaalokujMwk();
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			Mwk[i][j] = Elementy[i][j];
	MkwZMwk();
}

Macierz::Macierz(list<list<double>> Elementy){
	
	list<list<double>>::iterator itL = Elementy.begin();
	list<double>::iterator it = itL->begin();
	n = Elementy.size();
	m = itL->size();
	ZaalokujMwk();
	ZaalokujMkw();
	int i = 0, j = 0;
	for(itL; itL != Elementy.end();++itL,i++){j=0;
		for(it = itL->begin();it != itL->end();++it,j++)
			Mwk[i][j] = *it;
	}
	MkwZMwk();
}

Macierz Macierz::operator+(Macierz &N){
	Macierz MN(n,m);
	try{
		if(n != N.n)
			throw n;
		if(m != N.m)
			throw m;
	}
	catch(int &k){
		cout << "Nie da sie dodac macierzy";
		exit(1);
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			MN.Mwk[i][j] = Mwk[i][j] + N.Mwk[i][j];
	MN.MkwZMwk();
	return MN;
	
}

Macierz Macierz::operator-(Macierz &N){
	Macierz MN(n,m);
	try{
		if(n != N.n)
			throw n;
		if(m != N.m)
			throw m;
	}
	catch(int &k){
		cout << "Nie da sie odjac macierzy";
		exit(1);
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			MN.Mwk[i][j] = Mwk[i][j] - N.Mwk[i][j];
	MN.MkwZMwk();
	return MN;
}

Macierz Macierz::operator*(Macierz &N){
		Macierz MN(n,N.m);
		try{
			if(m != N.n)
				throw m;
		}
		catch(int &k)
		{
			std::cout << "Nie da sie wymnozyc macierzy, zle parametry.";
			exit(2);
		}
		for(int i = 0; i < n; i++)
			for(int j = 0; j < N.m; j++)
				MN.Mwk[i][j] = IloczynSkalarny(Mwk[i],N.Mkw[j],m);
		MN.MkwZMwk();
		return MN;
}

Macierz::Macierz(int n, int m):n(n),m(m){
	ZaalokujMwk();
	ZaalokujMkw();
}

void Macierz::ZaalokujMwk(){
	
	vector<double> pomocniczy;
	for(int i = 0; i < m; i++)
		pomocniczy.push_back(0.0);
	for(int i = 0; i < n; i++)
	Mwk.push_back(pomocniczy);
}

void Macierz::ZaalokujMkw(){
	
	vector<double> pomocniczy;
	for(int i = 0; i < n; i++)
		pomocniczy.push_back(0);
	for(int i = 0; i < m; i++)
	Mkw.push_back(pomocniczy);

}

void Macierz::MkwZMwk(){
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			Mkw[j][i] = Mwk[i][j];
};

double Macierz::IloczynSkalarny(vector<double> a, vector<double> b, int n){
	
	double IlSk = 0;
	for(int i = 0; i < n; i++)
		IlSk += a[i]*b[i];
	return IlSk;
};

Macierz Macierz::Transponowana(){
	Macierz MN(m,n);
	MN.Mwk = this->Mkw;
	MN.Mkw = this->Mwk;
	return MN;
};

Macierz Macierz::operator*(double t){
	Macierz MN(m,n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			MN.Mwk[i][j] *= t;
	MN.MkwZMwk();
	return MN;
};