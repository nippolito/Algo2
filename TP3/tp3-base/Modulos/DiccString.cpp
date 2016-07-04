#include "DiccString.h"
using namespace std;
using namespace aed2;
using namespace modulos;

#include <cassert>

void AgregarPrefijos(){
	DiccString<Nat> d;
	String clave1 = "";
	String clave2 = "hsdvas";
	Nat j = 0;
	Nat j2 = 100;
	for (int i=0; i<29; i++){			// EL NUMERO MAGICO ES 60!!!!!!     <---------- PREGUNTAR A GERVA... O NO
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

void permutaciones(){
	DiccString<Nat> d;
	Nat sig = 27;
	char ci;
	char cj;
	char ck;
	String clav="";
	for (int i=65; i<123; i++){				// Aca se rompe todo cuando usamos caracteres menos populares (ASCII: 0-64 y 124-255)
		for(int j=65;j<123;j++){
			for(int k=65;k<66;k++){
				ci = i;
				cj = j;
				ck = k;
				clav = "";
				clav.push_back(ci);
				clav.push_back(cj);
				clav.push_back(ck);
				cout << "Iteracion (" << i-65 << "," << j-65 << "," << k-65 <<"):  " << clav << endl;
				if(!d.Definido(clav)){
					d.Definir(clav,sig);
				}
			}
		}
	}
}

void DameSignificados(){
	DiccString<Nat> d;
	Nat a [13];
	for (int i =0 ; i < 13 ; i++){
		 a[i] = i+27;
	}
	String claves[13];
	claves[0] = "a";
	claves[1] = "ana";
	claves[2] = "banana";
	claves[3] = "anastasia";
	claves[4] = "babosa";
	claves[5] = "baboso";
	claves[6] = "wolo";
	claves[7] = "no";
	claves[8] = "queremos";
	claves[9] = "example@example.com";
	claves[10] = "osos";
	claves[11] = "banananananana";
	claves[12] = "wololololololololo";

	for (int i=0;i<13;i++){
		d.Definir(claves[i],a[i]);
	}
	for (int i=0;i<13;i++){
		cout << claves[i] << " --> " <<d.Obtener(claves[i]) << endl;
	}
	cout << "El maximo es: " << d.Maximo() << endl;
	cout << "El minimo es: " << d.Minimo() << endl;





}

void SearchAndDestroy(){
	DiccString<String> d;
	String a = "$";
	d.Definir("a",a);
	d.Definir("ana",a);
	d.Definir("banana",a);
	d.Definir("anastasia",a);
	d.Definir("babosa",a);
	d.Definir("baboso",a);
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
	/*AgregarPrefijos();
	SearchAndDestroy();
	permutaciones();
	*/
	//DameSignificados();
	DiccString<String> d;
	
	//String a = "$";
	//String b = "eso";
	//d.Definir("a",a);
	//d.Definir("ana",a);
	//d.Definir("banana",b);
	
	DiccString<String> d2(d);	

	return 0;
}