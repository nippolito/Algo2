
#include "base.h"

using namespace std;
using namespace aed2;
using namespace modulos;


// void AgregarYBorr(){
// 	Dato d1("Peron");
// 	Dato d2("Evita");
// 	Dato d3("Campora");
// 	Dato d4("Isabel");
// 	Dato d5("Nestor");	
// 	Registro r;
// 	r.Definir("aguero", d4);
// 	r.Definir("pipa", d2);
// 	r.DefinirLento("otamendi crack", d4);
// 	r.DefinirLento("todos muertos menos otamendi", d5);
// 	Registro r2;
// 	r2.Definir("aguero", d1);
// 	r2.Definir("pipa", d1);
// 	r2.Definir("otamendi crack", d1);
// 	r2.Definir("todos muertos menos otamendi", d1);
// 	Registro r3;
// 	r3.Definir("pipa", d1);
// 	r3.Definir("aguero", d5);
// 	r3.Definir("otamendi crack", d4);
// 	r3.Definir("todos muertos menos otamendi", d3);
	
// 	Conj<String> clav;
// 	clav.Agregar("aguero");
// 	Base b;
// 	Tabla t("tablita", clav, r);

// 	t.AgregarRegistro(r);
// 	t.AgregarRegistro(r2);
// 	t.AgregarRegistro(r3);

// 	cout << "Las Tablas son: " << b.Tablas() << endl;
// 	b.AgregarTabla(t);
// 	cout << "Las Tablas son: " << b.Tablas() << endl;

// 	Registro reg;
// 	Dato det("messi");
// 	reg.Definir("pipa", reg);

// 	b.InsertarEntrada(reg, t);
// 	cout << b.RegistrosB(t1) << endl;

// 	b.Borrar(reg, t);
// }


// void Joinss(){
// 	Dato d1("Peron");
// 	Dato d2("Evita");
// 	Dato d3("Campora");
// 	Dato d4("Isabel");
// 	Dato d5("Nestor");	
// 	Registro r;
// 	r.Definir("aguero", d4);
// 	r.Definir("pipa", d2);
// 	r.DefinirLento("otamendi crack", d4);
// 	r.DefinirLento("todos muertos menos otamendi", d5);
// 	Registro r2;
// 	r2.Definir("aguero", d1);
// 	r2.Definir("pipa", d1);
// 	r2.Definir("otamendi crack", d1);
// 	r2.Definir("todos muertos menos otamendi", d1);
// 	Registro r3;
// 	r3.Definir("pipa", d1);
// 	r3.Definir("aguero", d5);
// 	r3.Definir("otamendi crack", d4);
// 	r3.Definir("todos muertos menos otamendi", d3);
	
// 	Conj<String> clav;
// 	clav.Agregar("pipa");
// 	Base b;
// 	Tabla t("tablita", clav, r);

// 	t.AgregarRegistro(r);
// 	t.AgregarRegistro(r2);
// 	t.AgregarRegistro(r3);

// 	cout << "Las Tablas son: " << b.Tablas() << endl;
// 	b.AgregarTabla(t);
// 	cout << "Las Tablas son: " << b.Tablas() << endl;

// 	Dato xz("popa");
// 	Dato xx("popo");
// 	Dato zx("papo");
// 	Dato xc("opap");
// 	Registro carlos;
// 	carlos.Definir("pipa", d1);
// 	carlos.Definir("messi", xz);
// 	carlos.Definir("cufa", xc);
// 	Registro loscar;
// 	loscar.Definir("pipa", xz);
// 	loscar.Definir("messi", xc);
// 	loscar.Definir("cufa", zx);

// 	Tabla t2("tablota", clav, carlos);

// 	b.GenerarVistaJoin(t.DameNombre(), t2.DameNombre(), "pipa");
// 	cout << "Hay Join? " << b.HayJoin(t.DameNombre(), t2.DameNombre()) << endl;
// 	cout << "El campo de Join es: " << b.CampoJoin(t.DameNombre(), t2.DameNombre()) << endl;
// 	cout << "El join es: " << b.VistaJoin(t.DameNombre(), t2.DameNombre()).Siguiente() << endl;

// 	b.BorrarJoin(t.DameNombre(), t2.DameNombre());

// 	cout << "borré el Join" << endl;
// 	cout << "No debería haber Join, lo hay?: " << b.HayJoin(t.DameNombre(), t2.DameNombre()) << endl;

// }


// void tablamaxim{
	
// 	Dato d1("Peron");
// 	Dato d2("Evita");
// 	Dato d3("Campora");
// 	Dato d4("Isabel");
// 	Dato d5("Nestor");	
// 	Registro r;
// 	r.Definir("aguero", d4);
// 	r.Definir("pipa", d2);
// 	r.DefinirLento("otamendi crack", d4);
// 	r.DefinirLento("todos muertos menos otamendi", d5);
// 	Registro r2;
// 	r2.Definir("aguero", d1);
// 	r2.Definir("pipa", d1);
// 	r2.Definir("otamendi crack", d1);
// 	r2.Definir("todos muertos menos otamendi", d1);
// 	Registro r3;
// 	r3.Definir("pipa", d1);
// 	r3.Definir("aguero", d5);
// 	r3.Definir("otamendi crack", d4);
// 	r3.Definir("todos muertos menos otamendi", d3);
	
// 	Conj<String> clav;
// 	clav.Agregar("pipa");
// 	Base b;
// 	Tabla t("tablita", clav, r);

// 	t.AgregarRegistro(r);
// 	t.AgregarRegistro(r2);
// 	t.AgregarRegistro(r3);

// 	cout << "Las Tablas son: " << b.Tablas() << endl;
// 	b.AgregarTabla(t);
// 	cout << "Las Tablas son: " << b.Tablas() << endl;

// 	Dato xz("popa");
// 	Dato xx("popo");
// 	Dato zx("papo");
// 	Dato xc("opap");
// 	Registro carlos;
// 	carlos.Definir("pipa", d1);
// 	carlos.Definir("messi", xz);
// 	carlos.Definir("cufa", xc);
// 	Registro loscar;
// 	loscar.Definir("pipa", xz);
// 	loscar.Definir("messi", xc);
// 	loscar.Definir("cufa", zx);

// 	Tabla t2("tablota", clav, carlos);


// 	Dato ab("Troll");
// 	Dato ac("Trollsor");
// 	Dato ad("Profesor");
// 	Dato ae("Xavier");
// 	Registro rh;
// 	carlos.Definir("pipa", d1);
// 	carlos.Definir("messi", ab);
// 	carlos.Definir("cufa", ac);
// 	Registro rj;
// 	loscar.Definir("pipa", ad);
// 	loscar.Definir("messi", ae);
// 	loscar.Definir("cufa", ac);

// 	Tabla t3("tableta", clav, rh);

// 	cout << b.TablaMaxima();


// }

int main(){
	

	Dato d1("Peron");
	Dato d2("Evita");
	Dato d3("Campora");
	Dato d4("Isabel");
	Dato d5("Nestor");	
	Dato d6(1);
	Dato d7(9999);
	Dato d8(666);

	Registro r;
	r.Definir("aguero", d4);
	r.Definir("pipa", d2);
	r.DefinirLento("otamendi crack", d4);
	r.DefinirLento("todos muertos menos otamendi", d5);
	r.Definir("Jogo Bonito" , d6);
	Registro r2;
	r2.Definir("aguero", d1);
	r2.Definir("pipa", d1);
	r2.Definir("otamendi crack", d1);
	r2.Definir("todos muertos menos otamendi", d1);
	r2.Definir("Jogo Bonito" , d7);
	Registro r3;
	r3.Definir("pipa", d1);
	r3.Definir("aguero", d5);
	r3.Definir("otamendi crack", d4);
	r3.Definir("todos muertos menos otamendi", d3);
	r3.Definir("Jogo Bonito" , d8);
	Conj<String> clav;
	clav.Agregar("aguero");
	Base b;
	Tabla t("tablita", clav, r);
	Tabla t1("tablota", clav, r);
	Tabla t2("tab", clav, r);

	t.AgregarRegistro(r);
	t.AgregarRegistro(r2);
	t.AgregarRegistro(r3);

	b.AgregarTabla(t);
	b.DameTabla(t.DameNombre());
	b.AgregarTabla(t1);
	b.AgregarTabla(t2);
	// cerr << b.CantidadDeAccesosB(t.DameNombre()) << endl;
	// cout << "Las Tablas son: " << b.Tablas() << endl;



	Registro reg;
	Dato det("messi");
	// reg.Definir("pipa", det);
	reg.Definir("aguero", d4);
	//reg.Definir("nacho", d7);
	// reg.Definir("otamendi crack", det);
	// reg.Definir("todos muertos menos otamendi", det);
	// reg.Definir("Jogo Bonito" , d6);
	Registro reggae;
	Dato dete("nicoB");
	reggae.Definir("pipa", dete);

	// b.InsertarEntrada(reg, t.DameNombre());



	

	//cout << b.GenerarVistaJoin(t.DameNombre(), t3.DameNombre(), "aguero" ).Siguiente().Registros() << endl;
	//cout << b.HayJoin(t.DameNombre(), t3.DameNombre()) << endl;
	//cout << b.CampoJoin(t.DameNombre(), t3.DameNombre()) << endl;
	//b.BorrarJoin(t.DameNombre(), t3.DameNombre());
	//cout << b.HayJoin(t.DameNombre(), t3.DameNombre()) << endl;
	//cout << b.VistaJoin(t.DameNombre(), t3.DameNombre()).Siguiente().Registros() << endl;
	Registro asdf;
	asdf.Definir("aguero", d4);
	asdf.Definir("nacho", d4);
	asdf.Definir("nico", d6);
	asdf.Definir("facu", d7);
	Registro gg;
	gg.Definir("aguero", d2);
	gg.Definir("nacho", d4);
	gg.Definir("nico", d7);
	gg.Definir("facu", d6);

	Tabla t3("hola", clav, asdf);

	t3.Indexar("facu");
	cout << "indexo" << endl;
	t3.AgregarRegistro(asdf);
	t3.AgregarRegistro(gg);
	cout << "agrego regs" << endl;
	b.AgregarTabla(t3);


	cout << "vas a borrar" << endl;

	b.Borrar(reg,t3.DameNombre());
	cout << t3.Registros() << endl;
	//cout << b.VistaJoin(t.DameNombre(), t3.DameNombre()).Siguiente().Registros() << endl;

	// cout << b.RegistrosB(t.DameNombre()) << endl;

	// cout << b.Buscar(reg, t.DameNombre()) << endl;
	// cout << b.Buscar(reggae, t.DameNombre()) << endl; //busco algo que no existe

	Base b2(b);


	// cout << b2.CantidadDeAccesosB(t.DameNombre()) << endl;
	// cout << b2.TablaMaxima() << endl;

	



	return 0;
}