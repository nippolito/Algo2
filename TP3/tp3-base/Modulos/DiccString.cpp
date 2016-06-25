#include "DiccString.h"
using namespace std;
using namespace aed2;
using namespace modulos;

#include <cassert>

int main(){
	DiccString<String> d;

	d.Definir("Varian Wrynn", "Warrior");
	d.Definir("Antonidas" , "Mage");
	d.Borrar("Varian Wrynn");
//	cout << d.Definido("Antonidas") << endl;
	//d.Borrar("Antonidas");
	//d.Definir("Doomhammer" , EliminarSiguiente"Shaman");
	//d.Definir("Antique Healbot" , "Neutral");
	//d.Definir("Cenarius" , "Druid");

	//d.Borrar("Sap");
	//d.Borrar("Cenarius");

	return 0;
}