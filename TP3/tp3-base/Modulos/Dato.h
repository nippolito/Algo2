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
			// Dato();
			 Dato(String s);
			 Dato(Nat n);
			 bool EsNat() const;
			 bool EsString() const;
			 bool MismoTipo(const Dato otro) const;
			 modulos::Nat ValorNat() const;
			 modulos::String ValorStr() const;
			 Dato Max(const Conj<Dato> cd);
			 Dato Min(const Conj<Dato> cd);
			 bool MenorOIgual(const Dato otro) const;
			 
		private:
			bool tipo;
			modulos::Nat nat;
			modulos::String str;			
};
	//Dato::Dato(): tipo(true) , nat(0) , str(" ") {}
	 
	Dato::Dato(String s): tipo(false) , nat(0) , str(s) {} 

	Dato::Dato(Nat n): tipo(true) , nat(n) , str(" ") {} 
	
	bool Dato::EsNat() const {
		return tipo;
	}

	bool Dato::EsString() const {
		return !tipo;
	}

	bool Dato::MismoTipo(const Dato otro) const{
		return (tipo == otro.tipo);
	}
 
 	modulos::Nat Dato::ValorNat() const{
 		return nat;
 	}

 	modulos::String Dato::ValorStr() const{
 		return str;
 	}

 	bool Dato::MenorOIgual(const Dato otro) const{
 		bool res;
 			if(tipo){
    		res = (nat <= otro.nat);
			}else{
			int i = 0;
			while(i < str.size() && i < otro.str.size() && str[i] == otro.str[i]){
				i++;
			}
			if(i == str.size() || i == otro.str.size()){
			res = (str.size() <= otro.str.size() ); 
			}else{
			res = (str[i] <= otro.str[i] ) ;
			}
			}
	}


 	Dato Dato::Max(const Conj<Dato> cd){
 		typename Conj<Dato>::const_Iterador i = cd.CrearIt();
		Dato res = i.Siguiente();
		while(i.HaySiguiente()){
			if(!(i.Siguiente().MenorOIgual(res))){
				res = i.Siguiente();
			}
			i.Avanzar();
 		}
 	return res;
	}

	Dato Dato::Min(const Conj<Dato> cd){
 		typename Conj<Dato>::const_Iterador i = cd.CrearIt();
		Dato res = i.Siguiente();
		while(i.HaySiguiente()){
			if((i.Siguiente().MenorOIgual(res))){
				res = i.Siguiente();
			}
			i.Avanzar();
 		}
 	return res;
	}


};

#endif