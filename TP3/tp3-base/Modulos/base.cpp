
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
	
	Base b;

	//Stats
	Dato d1(14);
	Dato d2(16);
	Dato d3(11);
	Dato d4(9);
	Dato d5(12);
	Dato d6(10);
	
	//Nombres
	Dato n1("Jon Snow"); // Nombre es campo clave
	Dato n2("Arthas");
	Dato n3("Legolas");
	Dato n4("Dumbledore");
	Dato n5("Aslan");

	//Alineaciones
	Dato a1( "Neutral Bueno");
	Dato a2("Neutral");
	Dato a3("Caotico");
	Dato a4("Bueno");
	Dato a5("Caotico Neutral");
	
	//IDS
	Dato i1(4009); //ID es campo clave
	Dato i2(6679);
	Dato i3(3339);
	Dato i4(8989);
	Dato i5(1234);
	Dato i6(4321);

	//Registros  de la Tabla T1;
	Registro r1;
	r1.Definir("Fuerza",d1 );
	r1.Definir("Destreza", d2 );
	r1.Definir("Inteligencia", d3);
	r1.Definir("Constitucion" , d4);
	r1.Definir("Sabiduria", d5);
	r1.Definir("Carisma" , d6);
	r1.Definir("Nombre",n1 );
	r1.Definir("Alineacion" ,a1 );
	r1.Definir("ID Pj" , i1);

	Registro r2;
	r2.Definir("Fuerza", d2);
	r2.Definir("Destreza", d6);
	r2.Definir("Inteligencia",d5);
	r2.Definir("Constitucion" ,d4 );
	r2.Definir("Sabiduria",d3 );
	r2.Definir("Carisma" , d1);
	r2.Definir("Nombre",n2 );
	r2.Definir("Alineacion" ,a3 );
	r2.Definir("ID Pj" ,i2);

	Registro r3;
	r3.Definir("Fuerza", d5);
	r3.Definir("Destreza", d6);
	r3.Definir("Inteligencia",d4);
	r3.Definir("Constitucion" , d2);
	r3.Definir("Sabiduria", d1);
	r3.Definir("Carisma" , d3);
	r3.Definir("Nombre", n3);
	r3.Definir("Alineacion" , a4);
	r3.Definir("ID Pj" ,i3);

	Registro r4;
	r4.Definir("Fuerza", d3);
	r4.Definir("Destreza", d2);
	r4.Definir("Inteligencia",d4);
	r4.Definir("Constitucion" , d6);
	r4.Definir("Sabiduria", d1);
	r4.Definir("Carisma" , d5);
	r4.Definir("Nombre", n4);
	r4.Definir("Alineacion" ,a5);
	r4.Definir("ID Pj" , i4);

	Registro r10;
	r10.Definir("Fuerza", d3);
	r10.Definir("Destreza", d2);
	r10.Definir("Inteligencia",d4);
	r10.Definir("Constitucion" , d6);
	r10.Definir("Sabiduria", d1);
	r10.Definir("Carisma" , d5);
	r10.Definir("Nombre", n5);
	r10.Definir("Alineacion" ,a5);
	r10.Definir("ID Pj" , i5);	

	// Tabla t1. Sus campos son : Fuerza , Destreza , Inteligencia , Constitucion, Sabiduria , Carisma, Nombre(clave), Alineacion , ID Pj(clave)
	Conj<String> clavest1;
	clavest1.Agregar("ID Pj");
	clavest1.Agregar("Nombre");
	Tabla t1("Tabla T1", clavest1 , r1);
	t1.AgregarRegistro(r1);
	t1.AgregarRegistro(r2);
	t1.AgregarRegistro(r3);
	t1.AgregarRegistro(r4);
	t1.AgregarRegistro(r10);

	//Tabla t2 . Sus campos son : Clases , Profesion , Nivel , Id Pj(clave)
	// Datos de la Tabla t2

	//Clases
	Dato c1("Guerrero");
	Dato c2("Mago");
	Dato c3("Arquero");
	Dato c4("Paladin");
	Dato c5("Sacerdote");
	Dato c6("Nigromante");
	Dato c7("Picaro");

	//Profesion
	Dato p1("Herrero");
	Dato p3("Artesano");
	Dato p4("Cocinero");
	Dato p5("Alquimista");

	//Nivel 
	Dato l1(2);
	Dato l2(3);
	Dato l3(1);
	Dato l4(2);

	//Nombres 
	Dato no1("Carlos");
	Dato no2("Sancho");
	Dato no3("Don Quijote");
	Dato no4("Charles");


	//ID Pj son los Datos i1,i2,i3,i4

	//Registros de la tabla T2:

	Registro r5;
	r5.Definir("Clase",c1);
	r5.Definir("Profesion",p1);
	r5.Definir("Nivel",l2);
	r5.Definir("ID Pj", i1);
	r5.Definir("Nombre", no1);

	Registro r6;
	r6.Definir("Clase",c2);
	r6.Definir("Profesion",p3);
	r6.Definir("Nivel",l1);
	r6.Definir("ID Pj", i2);
	r6.Definir("Nombre", no2);

	Registro r7;
	r7.Definir("Clase",c3);
	r7.Definir("Profesion",p1);
	r7.Definir("Nivel",l3);
	r7.Definir("ID Pj", i3);
	r7.Definir("Nombre", no3);
	
	Registro r8;
	r8.Definir("Clase",c7);
	r8.Definir("Profesion",p4);
	r8.Definir("Nivel",l4);
	r8.Definir("ID Pj", i4);
	r8.Definir("Nombre", no4);

	Registro r9;
	r9.Definir("Clase",c7);
	r9.Definir("Profesion",p4);
	r9.Definir("Nivel",l4);
	r9.Definir("ID Pj", i5);
	r9.Definir("Nombre", no4);


	Conj<String> clavest2;
	clavest2.Agregar("ID Pj");
	Tabla t2("Tabla T2", clavest2 , r5);
	t2.AgregarRegistro(r5);
	t2.AgregarRegistro(r6);
	t2.AgregarRegistro(r7);
	t2.AgregarRegistro(r8);

	//Agrego las tablas a la base
	b.AgregarTabla(t1);
	b.AgregarTabla(t2);
	
	Registro crit2;
	crit2.Definir("ID Pj", i5);
	t1.Indexar("ID Pj");

	// ACA EMPIEZAN LOS TESTS 

	 cout << "Las Tablas de la base son :" << b.Tablas() << endl;
	 cout << "Los registros de las Tablas son :" << endl;
	 cout << "Tabla T1 :" << b.DameTabla(t1.DameNombre()).Registros() << endl;
	 cout << endl;
	 cout << "Tabla T2 :" << b.DameTabla(t2.DameNombre()).Registros() << endl;

	//Genero Joins
	cout <<"Se genera el Join entre T1 y t2 por ID Pj : "  << endl; 
	cout << b.GenerarVistaJoin(t1.DameNombre(),t2.DameNombre(),"ID Pj").Siguiente().Registros() << endl;
	cout << b.HayJoin(t1.DameNombre(),t2.DameNombre()) << endl;
	cout << "El campo de Join es: " << b.CampoJoin(t1.DameNombre(), t2.DameNombre()) << endl;

	b.InsertarEntrada(r9, t2.DameNombre());
	cout << "El Join por ID Pj entre t1 y t2 es :" << b.VistaJoin(t1.DameNombre(),t2.DameNombre()).Siguiente().Registros() << endl;
	cout << "Voy a borrar " << endl;
	cout << endl;
	b.Borrar(crit2, t2.DameNombre());
	//b.DameTabla(t2.DameNombre()).MostrameIndices();
	cout << "El Join por ID Pj entre t1 y t2 es :" << b.VistaJoin(t1.DameNombre(),t2.DameNombre()).Siguiente().Registros() << endl;


	return 0;
}