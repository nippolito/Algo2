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


void Joinss(){
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
	clav.Agregar("pipa");
	Base b;
	Tabla t("tablita", clav, r);

	t.AgregarRegistro(r);
	t.AgregarRegistro(r2);
	t.AgregarRegistro(r3);

	cout << "Las Tablas son: " << b.Tablas() << endl;
	b.AgregarTabla(t);
	cout << "Las Tablas son: " << b.Tablas() << endl;

	Dato xz("popa");
	Dato xx("popo");
	Dato zx("papo");
	Dato xc("opap");
	Registro carlos;
	carlos.Definir("pipa", d1);
	carlos.Definir("messi", xz);
	carlos.Definir("cufa", xc);
	Registro loscar;
	loscar.Definir("pipa", xz);
	loscar.Definir("messi", xc);
	loscar.Definir("cufa", zx);

	Tabla t2("tablota", clav, carlos);

	b.GenerarVistaJoin(t.DameNombre(), t2.DameNombre(), "pipa");
	cout << "Hay Join? " << b.HayJoin(t.DameNombre(), t2.DameNombre()) << endl;
	cout << "El campo de Join es: " << b.CampoJoin(t.DameNombre(), t2.DameNombre()) << endl;
	cout << "El join es: " << b.VistaJoin(t.DameNombre(), t2.DameNombre()).Siguiente() << endl;

	b.BorrarJoin(t.DameNombre(), t2.DameNombre());

	cout << "borré el Join" << endl;
	cout << "No debería haber Join, lo hay?: " << b.HayJoin(t.DameNombre(), t2.DameNombre()) << endl;

}


void tablamaxima {
	
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
	clav.Agregar("pipa");
	Base b;
	Tabla t("tablita", clav, r);

	t.AgregarRegistro(r);
	t.AgregarRegistro(r2);
	t.AgregarRegistro(r3);

	cout << "Las Tablas son: " << b.Tablas() << endl;
	b.AgregarTabla(t);
	cout << "Las Tablas son: " << b.Tablas() << endl;

	Dato xz("popa");
	Dato xx("popo");
	Dato zx("papo");
	Dato xc("opap");
	Registro carlos;
	carlos.Definir("pipa", d1);
	carlos.Definir("messi", xz);
	carlos.Definir("cufa", xc);
	Registro loscar;
	loscar.Definir("pipa", xz);
	loscar.Definir("messi", xc);
	loscar.Definir("cufa", zx);

	Tabla t2("tablota", clav, carlos);


	Dato ab("Troll");
	Dato ac("Trollsor");
	Dato ad("Profesor");
	Dato ae("Xavier");
	Registro rh;
	carlos.Definir("pipa", d1);
	carlos.Definir("messi", ab);
	carlos.Definir("cufa", ac);
	Registro rj;
	loscar.Definir("pipa", ad);
	loscar.Definir("messi", ae);
	loscar.Definir("cufa", ac);

	Tabla t2("tablota", clav, carlos);



}

int main(){








	return 0;
}