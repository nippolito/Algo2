#ifndef MODULOS_DATO_H_INCLUDED 
#define MODULOS_DATO_H_INCLUDED

#include <iostream>
#include <ostream>
#include <string>
#include <cassert>
#include "todo.h"


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
			 Nat ValorNat() const;
			 String ValorStr() const;
			 Dato MaxDato(const Conj<Dato> cd);
			 Dato MinDato(const Conj<Dato> cd);
			 bool MenorOIgual(const Dato otro) const;
			 bool operator==(const Dato&) const;
			 bool operator!=(const Dato&) const;
			 	 
		private:
			bool tipo;
			Nat nat;
			String str;			
};
	

};

#endif
