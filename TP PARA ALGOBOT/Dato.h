#ifndef DATO_H_   //dato es parte de la carpeta modulos
#define DATO_H_

#include <iostream>
#include <ostream>
#include <string>
#include <cassert>
#include "aed2/TiposBasicos.h"
#include "aed2/Conj.h"
#include "aed2/Lista.h"
#include "aed2/Dicc.h"

using namespace aed2;
using namespace std;

//namespace modulos {

class Dato {
		public:
			 Dato();
			 ~Dato();
			 Dato(String s);
			 Dato(Nat n);
			 Dato (const Dato&);
			 bool EsNat() const;
			 bool EsString() const;
			 bool MismoTipo(const Dato otro) const;
			 Nat ValorNat() const;
			 String ValorStr() const;
			 Dato MaxDato(const Conj<Dato> cd);
			 Dato MinDato(const Conj<Dato> cd);
			 bool MenorOIgual(const Dato otro) const;
			// ostream& mostrarDato(ostream&) const;
			 bool operator==(const Dato&) const;
			 bool operator!=(const Dato&) const;
			 
	//friend ostream& operator<<(ostream& os , const Dato& d);		 
		private:
			bool tipo;
			Nat nat;
			String str;			
};
	

//};

#endif
