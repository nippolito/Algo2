#include "DiccString.h"
using namespace std;
using namespace aed2;
using namespace modulos;

#include <cassert>

void AgregarSufijos(){
	DiccString<Nat> d;
	String clave1 = "";
	String clave2 = "hsdv";
	Nat j = 0;
	Nat j2 = 100;
	for (int i=0; i<29; i++){			// EL NUMERO MAGICO ES 60!!!!!!
		char c = i;
		char c2 = i+100;
		clave1.push_back(c);
		clave2.push_back(c2);
		d.Definir(clave2, j);
		d.Definir(clave1,j2);
		j++;
		j2++;
	}
}

void SearchAndDestroy(){
	DiccString<String> d;
	String a = "$";
	d.Definir("a",a);
	d.Definir("ana",a);
	d.Definir("banana",a);
	d.Definir("anastasia",a);
	cerr << "Chaannn" << endl;
	d.Definir("babosa",a);
	cerr << "Defino la primera" << endl;
	d.Definir("baboso",a);
	cerr << "Defino la segunda" << endl;
	d.Definir("ya",a);
	d.Definir("no",a);
	d.Definir("queremos",a);
	d.Definir("osos",a);
	d.Definir("banananananananana",a);
	d.Definir("trololololololololololol",a);
	d.Definir("wololooooooooooooo",a);

	d.Borrar("banananananananana");
	cerr << 1 << endl;
	d.Borrar("a");
	cerr << 2 << endl;
	d.Borrar("ana");
	cerr << 3 << endl;
	d.Borrar("anastasia");
	d.Borrar("babosa");
	cerr << d.Definido("baboso") << endl;
	
	d.Borrar("baboso");
	cerr << 6 << endl;
	d.Borrar("ya");
	cerr << 7 << endl;
	
}




int main(){
	/*String s = "LA CONCHA DE TU MADRE ALL BOYS";
	cerr << s[s.length()-1] << endl;
	cerr << *(s.end()) << endl;
	s.resize(s.length()-1);
	cerr << *(s.end()) << endl;*/
	AgregarSufijos();
	SearchAndDestroy();


	return 0;
}