#include "Dato.h"
#include <iostream>
#include <string>
#include <cassert>
using namespace modulos;
using namespace std;

int main(){

	Dato n1 (30);
	Dato n2 (14);
	Dato n3 (2);
	Dato n4 (22);
	Dato n5 (10);
	Dato n6 (20);
	Dato s1 ("Antonidas");
	Dato s2 ("Arthas");
	Dato s3 ("Jaina");
	Dato s4  ("Thrall");
	Dato s5 ("Grommash");
	Dato s6 ("Durotan");

	Conj<Dato> c;
	c.Agregar(s1);
	c.Agregar(s2);
	c.Agregar(s3);
	c.Agregar(s4);
	c.Agregar(s5);
	c.Agregar(s6);

  
	
	return 0;
}