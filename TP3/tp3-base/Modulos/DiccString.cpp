#include "DiccString.h"
using namespace std;
using namespace aed2;
using namespace modulos;

#include <cassert>

int main(){
	DiccString<Nat> D;
	//assert(D.EsVacio());
	D.Definir("A",27);
	cerr << "Definio piola" << endl;
	cerr << D.Definido("A") << endl;
	//cout << D.Obtener("A") << endl;
	cout << "VIVA PERON" << endl;
	D.Definir("AN",11);
	cout << "VIVA PERON" << endl;




	return 0;
}