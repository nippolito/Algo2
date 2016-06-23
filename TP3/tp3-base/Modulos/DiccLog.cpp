#include "DiccLog.h"

using namespace std;
using namespace aed2;
using namespace modulos;

void CrearVacioYLlenarlo(){
	DiccLog<Nat,String> d;
	for (int i=0;i<10;i=i+2){
		d.Definir(i,"Puto");
	}
	d.Definir(3, "Tu Vieja");
	d.Definir(7,"Tu Hermana");
	//d.Borrar(6);
	//cerr << "Borro el 6" << endl;
	d.Definir(1, "Pelas como un granjero");
	for (int i=0; i<10;i=i+2){
		cout << i << endl;
		assert(d.Definido(i));
		if (d.Definido(i)){
			d.Borrar(i);
			cout << "Borro el " << i << endl;
		}
	}
	assert(d.EsVacio());
}



int main(){
	//CrearVacioYLlenarlo();

	DiccLog<Nat,String> d;
	/*d.Definir(10,"Caca");
	cerr << "Definio piola" << endl;
	cerr << d.EsVacio() << endl;
	d.Borrar(10);
	cerr << "Borro piola" << endl;*/
	/*for (int i=0;i<4;i=i+2){
		d.Definir(i,"Puto");
	}*/
	d.Definir(5, "Tu Vieja");
	d.Definir(6,"Tu Hermana");
	//cerr << "Ya lo creo" << endl;
	//d.Borrar(6);
	//cerr << "Borro el 6" << endl;
	//d.Definir(3, "Pelas como un granjero");
	d.Definir(4, "Pelas como un granjero");
	//d.Definir(2, "Pelas como un granjero");
	//d.Definir(1, "Pelas como un granjero");
	d.Borrar(5);
	//d.Borrar(6);
	//d.Borrar(5);
	// for (int i=0; i<4;i=i+2){
	// 	//cout << i << endl;
	// 	//assert(d.Definido(i));
	// 	d.Borrar(i);
	// 	cout << "Borro el " << i << endl;
	// }
	//assert(d.EsVacio());

	//d.Definir(10, "Antonio");
	//d.Definir(6, "Sylvanas");
	//d.Definir(4, "Brann Bronzebeard");
	//d.Borrar(6);
	//cout << d.Obtener(10) << endl;
	//cout << d.Obtener(4) << endl;
	//cout << d.Definido(6) << endl;
	//d.Definir(30, "The Ancient One");
	//d.Buscar(10);
	//cout << d.Definido(10) << endl;
	//d.Definir(12, "hola");
	//d.Definir(11, "carlos");
	//d.Obtener(10);
	//DiccLog<Nat, String>::ItLog it = d.CrearIt();
	//cout << it.siguiente << endl;
    //DiccLog<Nat, String>::nodoAB p(10, "caca");
   // cout << p << endl;
	// int ch;
	// while (1)
	// {
	// 	cout << endl << endl;
	// 	cout << " Operaciones del DiccLog " << endl;
	// 	cout << " ----------------------------- " << endl;
	// 	cout << " 1. Inserción/Creación " << endl;
	// 	cout << " 2. Eliminar " << endl;
	// 	cout << " 3. Buscar " << endl;
	// 	cout << " 4. EsVacio? " << endl;
	// 	cout << " 5. Obtener " << endl;
	// 	cout << " 6. Máximo " << endl;
	// 	cout << " 7. Mínimo " << endl;
	// 	cout << " 10. Salir " << endl;
	// 	cout << " Elegí tu opción : ";
	// 	cin >> ch;
	// 	switch (ch)
	// 	{
	// 	case 1: cout << " Ingresá la clave (Nat): ";
	// 		cin.ignore(1);
	// 		cin >> n >> endl;
	// 		cout << "Ingresá el significado (String) : ";
	// 		cin >> s >> endl;
	// 		dl.Definir(n, s);
	// 		break;
	// 	case 2: cout << endl;
	// 		cout << " ¿Qué clave querés eliminar (Nat)? " << endl;
	// 		cin >> n;
	// 		cout << " -------------------" << endl;
	// 		dl.Borrar(n);
	// 		break;
	// 	case 3: cout << endl;
	// 		cout << " ¿Qué clave querés buscar? (Nat) " << endl;
	// 		cin >> n;
	// 		cout << " -------------------" << endl;
	// 		cout << dl.Buscar(n) << endl;
	// 		break;
	// 	case 4: cout << endl;
	// 		cout << "Es Vacío el Diccionario?" << dl.EsVacio() << endl;
	// 		break;
	// 	case 5: cout << " ¿Que significado querés? (clave Nat) ";
	// 		cin.ignore(1);
	// 		cin >> n >> endl;
	// 		cout << dl.Obtener(n) << endl;
	// 		break;
	// 	case 6: cout << " El máximo es: " << dl.Maximo() << endl;
	// 		break;
	// 	case 7: cout << " El mínimo es: " << dl.Minimo() << endl;
	// 		break;
	// 	case 10: 
	// 		return 0;
	// 		break;
	// 	}
	// }
	return 0;
}