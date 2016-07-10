#include "Dato.h"

//using namespace modulos;
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


 	Dato MaxDato(const Conj<Dato> cd){
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

	Dato MinDato(const Conj<Dato> cd){
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


	/*ostream& Dato::mostrarDato(ostream& os) const
	{
		if (tipo) {
			os << nat;
		} else{
			os << str;
		}

	return os;
	}*/


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


	/*ostream& operator<<(ostream& os, const Dato& d){
		return d.mostrarDato(os);
	}*/
/*
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
	cout << c << endl;
	c.Agregar(s1);
	c.Agregar(s2);
	c.Agregar(s3);
	c.Agregar(s4);
	c.Agregar(s5);
	c.Agregar(s6);
	cout << c << endl;
	cout << MinDato(c) << endl;
	cout << MaxDato(c) << endl;
	cout << s5.ValorStr() << endl;
	cout << n1.ValorNat() << endl;
	cout << s5 << endl;
	cout << n1 << endl;
	cout << n1.MismoTipo(s5) << endl;
	cout << s1.MenorOIgual(s2) << endl;
	cout << n6.EsNat() << endl;
	cout << s6.EsString() << endl;

  
	
	return 0;
}*/