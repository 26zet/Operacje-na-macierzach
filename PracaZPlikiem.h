#ifndef PRACAZPLIKIEM
#define PRACAZPLIKIEM
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class PracaZPlikiem{

	string Nazwa;
public:
	PracaZPlikiem(string Nazwa):Nazwa(Nazwa){}
	
	vector<vector<double>> WczytajMacierz(){
		vector<vector<double>> Macierz;
		vector<double> Wektor;
		fstream fs;
		fs.open(Nazwa,fstream::in);	//wczytanie pliku do odczytu
		if(!fs.is_open())		//sprawdzanie, czy plik sie otworzyl
			exit(3);
		while(!fs.eof()){
			string t;
			getline(fs,t);		//wczytuje liniê z fs do t
			string::size_type st = 0;		//specjalny rodzaj przetrzymuj¹cy nr wskazywanego bitu
			while(t != ""){
				Wektor.push_back(stod(t,&st));		//stod na pierwszym miejscu string, na drugim zwraca indeks spacji
				t.erase(0,st);			//usuniecie elementow ze stringa
			}
			Macierz.push_back(Wektor);
			Wektor.clear();
		}
		return Macierz;
	}

	void ZapiszMacierz(vector<vector<double>> Macierz){
		string s;
		fstream fs;
		fs.open("Wyjscie.txt",fstream::out);
		for(int i = 0; i < Macierz.size();i++){
			for(int j = 0; j < Macierz[0].size();j++){
				s.append(to_string(Macierz[i][j]));	//append - dodaje so s, to_string - konwertuje na string 
				if(j + 1 != Macierz[0].size())
					s.append(" ");
				else if(i != Macierz.size())
					s.append("\n");
			}
			fs << s;
			s = "";
		}

	};

};
#endif // !PRACAZPLIKIEM