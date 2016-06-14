#ifndef MODULOS_DATO_H_INCLUDED   //dato es parte de la carpeta modulos
#define MODULOS_DATO_H_INCLUDED

#include <iostream>
#include <string>
#include <cassert>
#include "ModulosBasicos.h"

using namespace aed2;

namespace modulos {

class Dato {
		public:
			 Dato();
			 Dato DatoString(String s);
			 Dato DatoNat(Nat n);
			 bool Nat() const;
			 bool String() const;
			 bool MismoTipo(const Dato otro) const;
			 modulos::Nat ValorNat() const;
			 modulos::String ValorStr() const;
			 Dato Max(const Conj<Dato> cd);
			 Dato Min(const Conj<Dato> cd);
			 bool MenoroIgual(const Dato otro) const;
			 
		private:
			bool tipo;
			modulos::Nat nat;
			modulos::String str;			
};

	 Dato::Dato(): tipo(true) , nat(0) , str(" ") {}
	 
	 Dato Dato::DatoString(String s){
	 	Dato res = Dato();
	 	res.tipo = false;
	 	res.nat = 0;
	 	res.str = s;
	 	return res;
	 }
	

	 


};

#endif