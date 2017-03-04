#ifndef KMACIERZ
#define KMACIERZ
#include "Macierz.h"

class KMacierz:public Macierz{
public:	
	double det(vector<int> V1,vector<int> V2){
		double d = 0;
		if(V1.size() == 1)
				return Mwk[V1[0]][V2[0]];
		else
		{
			for(int i = 0; i < V1.size();i++)
			{
				
				int temp1 = V1[0];
				int temp2 = V2[i];
				V1.erase(V1.begin());
				V2.erase(V2.begin() + i);
				if(i%2){
					d -= Mwk[temp1][temp2]*det(V1,V2);
				}
				else{
					d += Mwk[temp1][temp2]*det(V1,V2);
				}
				V1.emplace(V1.begin(),temp1);
				V2.emplace(V2.begin()+i,temp2);
			}
			return d;
		}
	};
public:
	double W;
	KMacierz(){}
	KMacierz(int n, int m):Macierz(n,m){};		//wypelnia macierz zerami
	KMacierz(list<list<double>> Elementy):Macierz(Elementy){};	//tworzenie macierzy przez wczytywanie z list
	KMacierz(vector<vector<double>> Elementy):Macierz(Elementy){};
	void ObliczDet(){
		W = 0;
		vector<int> V1,V2;
		for(int i = 0; i < n; i++){
			V1.push_back(i);
			V2.push_back(i);
		}
		W = det(V1,V2);
	};
	KMacierz Odwrotna(){	//liczenie odwrotnej macierzy
		
		KMacierz KM(n,n);
		vector<int> V1,V2;
		for(int i = 0; i < n; i++){
			V1.push_back(i);
			V2.push_back(i);
		}
		W = det(V1,V2);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
			{
				int temp1 = V1[i];
				int temp2 = V2[j];
				V1.erase(V1.begin() + i);
				V2.erase(V2.begin() + j);
				if((i+j)%2)
					KM.Mwk[j][i] = -det(V1,V2)/W;
				else
					KM.Mwk[j][i] = det(V1,V2)/W;
				V1.emplace(V1.begin() + i,temp1);
				V2.emplace(V2.begin() + j,temp2);
			}
			KM.MkwZMwk();
		return KM;
	};
	
};

#endif // !KMacierz
