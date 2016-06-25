#include "DiccString.h"
using namespace std;
using namespace aed2;
using namespace modulos;

#include <cassert>

int main(){
	DiccString<String> d;

	d.Definir("Dr.Balanced", "Neutral");
	d.Definir("Antonidas" , "Mage");
	d.Definir("Doomhammer" , "Shaman");
	d.Definir("Sap" , "Rogue");
	//d.Definir("Cenarius" , "Druid");

	return 0;
}