#include "DiccString.h"
using namespace std;
using namespace aed2;
using namespace modulos;

#include <cassert>

int main(){
	DiccString<String> d;

	//d.Definir("A", "Puto");
	//d.Definir("AB", "Tu Vieja");
	//d.Definir("Varian Wrynn", "Warrior");
	d.Definir("Antonidas" , "Mage");
	//d.Definir("" , "Puta");
	//d.Borrar("Varian Wrynn");
	//cout << d.Definido("Antonidas") << endl;
    //cout << d.Definido("Varian Wrynn") << endl;
    //d.Borrar("Antonidas");
	//d.Definir("Doomhammer" , "Shaman");
    //cout << d.Definido("VERDURA") << endl;
    //d.Definir("Antique Healbot" , "Neutral");
	//d.Definir("Cenarius" , "Druid");
	//d.Definir("Gorehowl" , "Warrior");
	typename DiccString<String>::ItStr it = d.CrearIt();
	while( it.HaySiguiente() ){
		cout << "Clave actual: " << it.SiguienteClave() << endl;
		it.Avanzar();
		if (it.HaySiguiente()){
			cout << "Significado actual: " << it.SiguienteSignificado() << endl;
		}
		//cout << (it.HaySiguiente()==false) <<endl;
	}

	//d.Borrar("Sap");
	//d.Borrar("Cenarius");

	return 0;
}