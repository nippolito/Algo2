#ifndef MODULOS_DATO_H_INCLUDED   //dato es parte de la carpeta modulos
#define MODULOS_DATO_H_INCLUDED

#include <iostream>
#include <ostream>
#include <string>
#include <cassert>
#include "ModulosBasicos.h"

using namespace aed2;
using namespace std;

namespace modulos {

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
			 modulos::Nat ValorNat() const;
			 modulos::String ValorStr() const;
			 Dato MaxDato(const Conj<Dato> cd);
			 Dato MinDato(const Conj<Dato> cd);
			 bool MenorOIgual(const Dato otro) const;
			// ostream& mostrarDato(ostream&) const;
			 bool operator==(const Dato&) const;
			 bool operator!=(const Dato&) const;
			 
	//friend ostream& operator<<(ostream& os , const Dato& d);		 
		private:
			bool tipo;
			modulos::Nat nat;
			modulos::String str;			
};
	

};

#endif
