#ifndef UKLADROWNAN
#define UKLADROWNAN
#include "Macierz.h"
#include "KMacierz.h"
#include "Wektor.h"
#include <vector>

class UkladRownan{
	
public:
	KMacierz A;
	Macierz B;
	Macierz X;

	UkladRownan(KMacierz A, Macierz B):A(A),B(B){}
	UkladRownan(){}
	virtual void RozwiazUklad(){
		A.ObliczDet();
		if(abs(A.W) > 0.0002)
			X = A.Odwrotna()*B;
	
	} //metoda z macierza odwrotna

};

#endif // !UKLADROWNAN
