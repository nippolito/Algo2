#include "DiccLog.h"

using namespace std;
using namespace aed2;
using namespace modulos;

void CrearVacioYLlenarlo(){
	DiccLog<Nat,String> d;
	for (int i=2;i<10;i=i+2){
		d.Definir(i,"Puto");
	}
	d.Definir(3, "Tu Vieja");
	d.Definir(7,"Tu Hermana");
	d.Definir(0, "Tu Vieja");
	d.Definir(1, "Pelas como un granjero");
	for (int i=0; i<10;i++){
		if (d.Definido(i)){
			d.Borrar(i);
		}
	}
	assert(d.EsVacio());
}

void ChequeaSiEstanDefinidos(){
	DiccLog<Nat,String> d;
	for (int i=2;i<10;i=i+2){
		d.Definir(i,"Puto");
	}
	d.Definir(3, "Tu Vieja");
	d.Definir(7,"Tu Hermana");
	d.Definir(5, "Tu Vieja");
	d.Definir(1, "Pelas como un granjero");
	for (int i=8; i > 0;i--){
		assert(d.Definido(i));
		
	}
	assert(!d.EsVacio());
}



void DameDicc()
{
	DiccLog<Nat,String> d;
	
	d.Definir(3, "Tu Vieja");
	d.Definir(7,"Tu Hermana");
	d.Definir(0, "Tu Puta Vieja");
	d.Definir(1, "Pelas como un granjero");
	d.Definir(11, "Hola");
	d.Definir(99,"C'thun");
	d.Definir(66, "C'thun, C'thun , C'thuuuuuuuuuuuuun");
	d.Definir(127, "Piratas");

  	typename DiccLog<Nat,String>::ItLog it = d.CrearIt();  // No podemos covertir un dicclog a un const dicclog
  //	typename DiccLog<Nat,String>::const_ItLog it2 = d.Buscar();

	while(it.HaySiguiente())
	{
		cout << it.SiguienteClave() << ":" << it.SiguienteSignificado() << endl;
		it.Avanzar();
	}
}

void BuscarYAvanzar(){
	DiccLog<Nat,String> d;

	d.Definir(3, "Tu Vieja");
	d.Definir(7,"Tu Hermana");
	d.Definir(0, "Tu Puta Vieja");
	d.Definir(1, "Pelas como un granjero");
	d.Definir(11, "Hola");
	d.Definir(99,"C'thun");
	d.Definir(66, "C'thun, C'thun , C'thuuuuuuuuuuuuun");
	d.Definir(127, "Piratas");

	typename DiccLog<Nat,String>::ItLog it1 = d.Buscar(0);
	while(it1.HaySiguiente())
	{
		cout << it1.SiguienteClave() << ":" << it1.SiguienteSignificado() << endl;
		it1.Avanzar();
	}

	cout << "Maximo? : " << d.Maximo() << endl;
	cout << "Minimo? : " << d.Minimo() << endl;
}



int main(){
	CrearVacioYLlenarlo();
	ChequeaSiEstanDefinidos();
	DameDicc();
	BuscarYAvanzar();





	return 0;
}