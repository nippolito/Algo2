#include "base.h"
using namespace std;
using namespace aed2;
using namespace modulos;

void AgregarYBorr(){
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
	r3.Definir("pipa", d1);
	r3.Definir("aguero", d5);
	r3.Definir("otamendi crack", d4);
	r3.Definir("todos muertos menos otamendi", d3);
	
	Conj<String> clav;
	clav.Agregar("aguero");
	Base b;
	Tabla t("tablita", clav, r);

	t.AgregarRegistro(r);
	t.AgregarRegistro(r2);
	t.AgregarRegistro(r3);

	cout << "Las Tablas son: " << b.Tablas() << endl;
	b.AgregarTabla(t);
	cout << "Las Tablas son: " << b.Tablas() << endl;

	Registro reg;
	Dato det("messi");
	reg.Definir("pipa", reg);

	b.InsertarEntrada(reg, t);
	cout << b.RegistrosB(t1) << endl;

	b.Borrar(reg, t);


}



int main(){








	return 0;
}