#include "DiccString.h"
using namespace std;
using namespace aed2;
using namespace modulos;

#include <cassert>

int main(){
	DiccString<String> d;

	d.Definir("Varian Wrynn", "Warrior");
	d.Definir("Antonidas" , "Mage");
	d.Definir("Doomhammer" , "Shaman");
	//d.Definir("Antique Healbot" , "Neutral");
	//d.Definir("Cenarius" , "Druid");

	//d.Borrar("Sap");
	//d.Borrar("Cenarius");

	return 0;
}