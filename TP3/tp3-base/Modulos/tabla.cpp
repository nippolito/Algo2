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
	// cout << t.Esta(carlos) << endl;
	// t.Indexar("pipa");
	// t.MostrameIndices();

	Dato as(1);
	Dato ad(2);
	Dato af(3);
	Dato ag(4);
	Dato stc("nacho");
	Registro nico;
	nico.Definir("pipa", as);
	nico.Definir("messi", ad);
	nico.Definir("cufa", af);
	nico.Definir("str", stc);
	Registro cufa;

	cufa.Definir("pipa", af);
	cufa.Definir("messi", af);
	cufa.Definir("cufa", af);
	cufa.Definir("str", stc);

	Tabla t5("tableta", clav, nico);
	t5.AgregarRegistro(nico);
	t5.AgregarRegistro(cufa);
	t5.Indexar("str");
	t5.Indexar("pipa");

	t5.MostrameIndices();

	Registro crit;
	crit.Definir("pipa", as);
	// t5.BuscarYBorrar(crit);
	//cout << t5.Esta(nico) << endl;

}

void Borra(){
	Dato d1("Peron");
	Dato d2("Evita");
	Dato d3("Campora");
	Dato d4("Isabel");
	Dato d5("Nestor");	
	Dato xz("popa");
	Dato xx("popo");
	Dato zx("papo");
	Dato xc("opap");
	Dato as(1);
	Dato ad(2);
	Dato af(3);
	Dato ag(4);
	Registro r;
	r.Definir("aguero", d3);
	r.Definir("pipa", as);
	r.DefinirLento("otamendi crack", d4);
	r.DefinirLento("todos muertos menos otamendi", d5);
	Registro r2;
	r2.Definir("aguero", d1);
	r2.Definir("pipa", ad);
	r2.Definir("otamendi crack", d1);
	r2.Definir("todos muertos menos otamendi", d1);
	Registro r3;
	r3.Definir("aguero", d5);
	r3.Definir("pipa", ag);
	r3.Definir("otamendi crack", d4);
	r3.Definir("todos muertos menos otamendi", d3);
	Registro carlos;
	carlos.Definir("pipa", d1);
	carlos.Definir("messi", xz);
	carlos.Definir("cufa", xc);
	Registro loscar;
	loscar.Definir("pipa", d2);
	loscar.Definir("messi", xc);
	loscar.Definir("cufa", zx);
	Registro r10;
	r10.Definir("aguero",d5);
	Registro nico;
	nico.Definir("pipa", as);
	nico.Definir("messi", ad);
	nico.Definir("cufa", af);
	Registro cufa;
	cufa.Definir("pipa", af);
	cufa.Definir("messi", af);
	cufa.Definir("cufa", af);
	Registro crit;
	crit.Definir("pipa", as);
	Registro crit2;
	crit2.Definir("pipa", ag);
	Registro crit3;
	crit3.Definir("aguero",d1);
	Conj<String> clav;
	clav.Agregar("pipa");
	Tabla t("tablita", clav, r);
	t.AgregarRegistro(r);
	t.AgregarRegistro(r2);
	t.AgregarRegistro(r3);
	//Tabla t2(t);
	//Tabla t3("tablota", clav, carlos);
	//t3.AgregarRegistro(carlos);
	//t3.AgregarRegistro(loscar);
	//Tabla t5("tableta", clav, nico);
	//t5.AgregarRegistro(nico);
	//t5.AgregarRegistro(cufa);
	//cout << "Prueba con indice String" << endl;
	t.Indexar("pipa");	
	cout << "El dato maximo es: " << t.Maximo("pipa") << endl;
	cout << "El dato minimo es: " << t.Minimo("pipa") << endl;
	cout << t.Esta(r)<<endl;
	cout << "Los registros antes :" << t.Registros()<<endl;
	cout << t.Indices()<<endl;
	cout << t.Compatible(r) << "    " << t.Compatible(crit) << endl;
	t.BorrarRegistro(crit);
	cout << t.Esta(r)<<endl;
	cout <<endl<<"Los registros despues: " << t.Registros() << endl ;
	cout << "El dato maximo es: " << t.Maximo("pipa") << endl;
	cout << "El dato mínimo es: " << t.Minimo("pipa") << endl;
	cout << "Los registros antes :" << t.Registros();
	t.BorrarRegistro(crit3);
	cout <<endl<<"Los registros despues: " << t.Registros() << endl ;
	cout << "Los registros antes :" << t.Registros();
	t.BorrarRegistro(crit2);
	cout <<endl<<"Los registros despues: " << t.Registros() << endl ;
	cout << "El dato mínimo es: " << t.Minimo("pipa") << endl;
	cout << "El dato maximo es: " << t.Maximo("pipa") << endl;

	/*
	cout << "Los registros son: " << t.Registros() << endl; 
	cout << "Las claves son: " << t.Claves() << endl;
	cout << "Las columnas son: " << t.Columnas() << endl;
	t.Indexar("pipa");
	cout << "El dato máximo es: " << t.Maximo("pipa") << endl;
	cout << "El nombre de la tabla es: " << t.DameNombre() << endl;
	cout << "El tipo del campo pipa es: " << t.TipoCampo("pipa") << endl;
	cout <<"Los registros que coinciden con r10 son: " << t.BuscarT(r10) << endl;
	cout <<"Los registros combinados son: " <<t.CombinarRegistro("pipa", t3) << endl;
	cout <<"Esta Carlos?" <<t.Esta(carlos) << endl;
	cout << "Los indices son de t:"; 
	t.MostrameIndices();
	cout << "Los indices son de t5 son: ";
	t5.MostrameIndices();
	t5.BuscarYBorrar(crit);
	*/
	
}
void Indexar(){
	Dato d1("Peron");
	Dato d2("Evita");
	Dato d3("Campora");
	Dato d4("Isabel");
	Dato d5("Nestor");	
	Dato xz("popa");
	Dato xx("popo");
	Dato zx("papo");
	Dato xc("opap");
	Dato as(1);
	Dato ad(2);
	Dato af(3);
	Dato ag(4);
	Registro r;
	r.Definir("aguero", d3);
	r.Definir("pipa", as);
	r.DefinirLento("otamendi crack", d4);
	r.DefinirLento("todos muertos menos otamendi", d5);
	Registro r2;
	r2.Definir("aguero", d1);
	r2.Definir("pipa", ad);
	r2.Definir("otamendi crack", d1);
	r2.Definir("todos muertos menos otamendi", d1);
	Registro r3;
	r3.Definir("aguero", d5);
	r3.Definir("pipa", ag);
	r3.Definir("otamendi crack", d4);
	r3.Definir("todos muertos menos otamendi", d3);
	Registro carlos;
	carlos.Definir("pipa", d1);
	carlos.Definir("messi", xz);
	carlos.Definir("cufa", xc);
	Registro loscar;
	loscar.Definir("pipa", d2);
	loscar.Definir("messi", xc);
	loscar.Definir("cufa", zx);
	Registro r10;
	r10.Definir("aguero",d5);
	Registro nico;
	nico.Definir("pipa", as);
	nico.Definir("messi", ad);
	nico.Definir("cufa", af);
	Registro cufa;
	cufa.Definir("pipa", af);
	cufa.Definir("messi", af);
	cufa.Definir("cufa", af);
	Registro crit;
	crit.Definir("pipa", as);
	Registro crit2;
	crit2.Definir("pipa", ag);
	Registro crit3;
	crit3.Definir("aguero",d1);
	Conj<String> clav;
	clav.Agregar("pipa");
	Tabla t("tablita", clav, r);
	t.AgregarRegistro(r);
	t.AgregarRegistro(r2);
	t.AgregarRegistro(r3);
	
	t.Indexar("pipa");
	t.Indexar("otamendi crack");
	cout << t.Indices()<<endl;
	//t.MostrameIndices();
	t.BorrarRegistro(crit3);
	cout << t.Esta(r) << t.Esta(crit) << endl;
}	




int main(){
	//Borra();
	Indexar();




	return 0;
}