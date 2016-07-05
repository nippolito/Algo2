#include "tabla.h"
using namespace std;
using namespace aed2;
using namespace modulos;


void AgregarYBorrar(){
	Dato d1("Peron");
	Dato d2("Evita");
	Dato d3("Campora");
	Dato d4("Isabel");
	Dato d5("Nestor");	
	Registro r;
	r.Definir("aguero", d4);
	r.Definir("pipa", d2);
	r.DefinirLento("otamendi crack", d4);
	r.DefinirLento("todos muertos menos otamendi", d5);

	Registro r2;
	r2.Definir("aguero", d1);
	r2.Definir("pipa", d1);
	r2.Definir("otamendi crack", d1);
	r2.Definir("todos muertos menos otamendi", d1);

	Registro r3;
	r3.Definir("pipa", d5);
	r3.Definir("aguero", d5);
	r3.Definir("otamendi crack", d4);
	r3.Definir("todos muertos menos otamendi", d3);

	Conj<String> clav;
	clav.Agregar("pipa");
	Tabla t("tablita", clav, r);

	t.AgregarRegistro(r);
	t.AgregarRegistro(r2);
	t.AgregarRegistro(r3);

	// Registro r4;
	// r4.Definir("pipa", d1);
	// cout << "Los registros son: " << t.Registros() << endl; 
	// cout << "Las claves son: " << t.Claves() << endl;
	// cout << "Las columnas son: " << t.Columnas() << endl;
	// // cout << "El dato mínimo es: " << t.Minimo("pipa") << endl;
	// // cout << "El dato máximo es: " << t.Maximo("pipa") << endl;
	// cout << "El nombre de la tabla es: " << t.DameNombre() << endl;
	// cout << "El tipo del campo pipa es: " << t.TipoCampo("pipa") << endl;

	Tabla t2(t);
	Registro r10;
	r10.Definir("aguero",d5);


	Dato xz("popa");
	Dato xx("popo");
	Dato zx("papo");
	Dato xc("opap");
	Registro carlos;
	carlos.Definir("pipa", d1);
	carlos.Definir("messi", xz);
	carlos.Definir("cufa", xc);
	Registro loscar;
	loscar.Definir("pipa", d2);
	loscar.Definir("messi", xc);
	loscar.Definir("cufa", zx);

	Tabla t3("tablota", clav, carlos);
	t3.AgregarRegistro(carlos);
	t3.AgregarRegistro(loscar);

	// cout << t.BuscarT(r10) << endl;
	
	//cout << t.CombinarRegistro("pipa", t3) << endl;
	//t.BorrarRegistro(r4);
	//debiera eliminarme los registros r2 y r3
	cout << t.Esta(r) << endl;
}

void Index(){
	
}





int main(){
	AgregarYBorrar();





	return 0;
}