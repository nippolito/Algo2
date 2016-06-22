#include "DiccLog.h"

using namespace std;
using namespace aed2;
using namespace modulos;

int main(){
	 DiccLog<Nat, String> d;
	// Nat n;
	// String s;
	//d.Definir(10, "caca");
	// d.Buscar(10);
	//d.Definido(10);
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