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
	t.Indexar("otamendi crack");	
	t.Indexar("pipa");	
	//t.MostrameIndices();
	//cout << "El dato maximo es: " << t.Maximo("pipa") << endl;
	//cout << "El dato minimo es: " << t.Minimo("pipa") << endl;
	//cout << t.Esta(r)<<endl;
	//cout << "Los registros antes :" << t.Registros()<<endl;
	//cout << t.Indices()<<endl;
	//cout << t.Compatible(r) << "    " << t.Compatible(crit) << endl;
	/*cout << "-------------( 1 )--------------" <<endl;
	t.MostrameIndices();
	cout << "-------------( 2 )--------------" <<endl;*/
	//cout << t.Registros()<<endl;
	t.BorrarRegistro(crit);
	//cout << t.Esta(r)<<endl;
	//cout <<endl<<"Los registros despues: " << t.Registros() << endl ;
	//cout << "El dato maximo es: " << t.Maximo("pipa") << endl;
	//cout << "El dato mínimo es: " << t.Minimo("pipa") << endl;
	
	/*t.MostrameIndices();
	cout << "-------------( 3 )--------------" <<endl;*/

	//cout << "Los registros antes :" << t.Registros() << endl << endl;
	//cout << t.Registros()<<endl;
	t.BorrarRegistro(crit3);

	//t.MostrameIndices();
	//cout << "-------------( 4 )--------------" <<endl;

	//cout <<endl<<"Los registros despues: " << t.Registros() << endl ;
	//cout << "Los registros antes :" << t.Registros() << endl << endl;
	//cout << "antes" << endl;
	//cout << t.Registros()<<endl;
	//cout << "despues" << endl;
	t.BorrarRegistro(crit2);
	t.MostrameIndices();
	cout << "---------------------------" <<endl;
	//cout <<endl<<"Los registros despues: " << t.Registros() << endl ;
	//cout << "El dato mínimo es: " << t.Minimo("pipa") << endl;
	//cout << "El dato maximo es: " << t.Maximo("pipa") << endl;

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

	t.Indexar("otamendi crack");	
	t.Indexar("pipa");
	cout << t.Indices()<<endl;
	//t.MostrameIndices();
	t.BorrarRegistro(crit3);
	cout << t.Esta(r) << t.Esta(crit) << endl;
}	

void ProblemasDeBase(){
	Dato d2("Evita");
	Dato d4("Isabel");
	Dato d6(1);
	Dato d7(9999);

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
    
    Conj<String> clav;
	clav.Agregar("aguero");
	
	Tabla t3("hola", clav, asdf);
    t3.AgregarRegistro(asdf);
	t3.AgregarRegistro(gg);
	t3.Indexar("aguero");
	t3.Indexar("nico");

	Registro crit;
	crit.Definir("aguero", d4);


	cerr <<t3.Registros() << endl;
	t3.BorrarRegistro(crit);
	cerr <<t3.Registros() << endl;


}

void CombinandoRegistros(){
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
	r.Definir("1",d1);
	r.Definir("2",d2);
	r.Definir("3",d3);
	r.Definir("4",d4);
	r.Definir("5",d5);
	r.Definir("6",xc);
	r.Definir("7",xc);
	Registro r1;
	r1.Definir("1",d2);
	r1.Definir("2",d3);
	r1.Definir("3",d4);
	r1.Definir("4",d5);
	r1.Definir("5",d1);
	r1.Definir("6",xx);
	r1.Definir("7",d1);
	Registro r3;
	r3.Definir("6",zx);
	r3.Definir("7",d1);
	r3.Definir("8",as);
	r3.Definir("9",af);
	Registro r2;
	r2.Definir("6",xx);
	r2.Definir("7",xc);
	r2.Definir("8",as);
	r2.Definir("9",af);
	Conj<String> c;
	Tabla t("cacho",c,r);
	Tabla t2("cachito",c,r2);
	t.AgregarRegistro(r);
	t.AgregarRegistro(r1);
	t2.AgregarRegistro(r2);

	cout << t.Registros() << endl << t2.Registros() << endl << endl;
	//cout << r.AgregarCampos(r2) << endl << r2.AgregarCampos(r) << endl << endl;
	cout << t.CombinarRegistro("7",t2) << t.CombinarRegistro("6", t2) << endl << endl;
	cout << t2.CombinarRegistro("7",t) << t2.CombinarRegistro("6", t) << endl << endl;
}

int main(){
	//Borra();
	//Indexar();
	//CombinandoRegistros();

	ProblemasDeBase();


	return 0;
}