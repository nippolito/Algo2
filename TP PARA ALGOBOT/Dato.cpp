#include "Dato.h"

using namespace modulos;
using namespace std;
using namespace aed2;



	Dato::Dato(): tipo(true) , nat(0) , str(" ") {}
	 
	Dato::Dato(String s): tipo(false) , nat(0) , str(s) {} 

	Dato::Dato(Nat n): tipo(true) , nat(n) , str(" ") {} 
	
	Dato::Dato(const Dato& otro){
		tipo = otro.tipo;
		nat = otro.nat;
		str = otro.str;
	}
	
	Dato::~Dato(){} // Las clases que tienen miembros estaticos (cosas sin punteros) la funcion ~Dato destruye la tupla automaticamente


	bool Dato::EsNat() const {
		return tipo;
	}

	bool Dato::EsString() const {
		return !tipo;
	}

	bool Dato::MismoTipo(const Dato otro) const{
		return (tipo == otro.tipo);
	}
 
 	Nat Dato::ValorNat() const{
 		return nat;
 	}

 	String Dato::ValorStr() const{
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
		return res;
	}


 	Dato Dato::MaxDato(const Conj<Dato> cd){
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

	Dato Dato::MinDato(const Conj<Dato> cd){
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

	 bool Dato::operator==(const Dato& otro) const
	 {
	 	bool res = false;
	 	
	 	if (tipo != otro.tipo){return res;}
	 	
	 	if (tipo)
	 	{
	 		res = (nat == otro.nat);
	 	}
	 	else
	 	{
	 		res = (str == otro.str);
	 	}
	 	return res;
	 }

	 bool Dato::operator!=(const Dato& otro) const 
	 {
	 	return !(operator==(otro));
	 }
