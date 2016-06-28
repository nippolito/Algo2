#ifndef MODULOS_TABLA_H_INCLUDED
#define MODULOS_TABLA_H_INCLUDED

#include "ModulosBasicos.h"
#include <iostream>
#include <string>
#include <ostream>
#include "pila.h"
#include "reg.cpp"
#include "DiccString.h"
#include "DiccLog.h"

using namespace std;
using namespace aed2;


namespace modulo{
	class Tabla {
		private:

			struct apuntador {
				typename Lista<Registro>::Iterador reg;
				typename Lista<apuntador>::Iterador compadre;
				apuntador(){}
			};

			struct indiceNat {
				String campo;
				Dato minimo;
				Dato maximo;
				DiccLog< Dato, Lista<apuntador> > regpordato;
				//DiccLog< Dato, Lista<T> > res;
				indiceNat() : campo("higuain muerto") , minimo(0), maximo(0){}
			};

			struct indiceStr {
				String campo;
				Dato minimo;
				Dato maximo;
				DiccString< Lista<apuntador> > regpordato;
				//DiccString< Lista<T> > res;
				indiceStr() : campo("higuain muerto") , minimo("a"), maximo("z"){}
			};

			struct tupla {
				bool nat;
				bool str;

				tupla() : nat(false) , str(false) {}
			};



		public:
			Tabla();
			Tabla(const Tabla& otra);
			Tabla(String s , Conj<String> clav, Registro colum);
			~Tabla();
			Tabla& operator=(const Tabla& otra);
			void AgregarRegistro(const Registro r);
			void BorrarRegistro(const Registro crit);
			void Indexar(const String c);
			bool TipoCampo(const String c) const;
			const Conj<Registro> Registros() const;
			const Conj<String> Claves() const;
			Dato Minimo(const String c);
			Dato Maximo(const String c);
			const Conj<String> Indices() const;
			bool Compatible(const Registro r) const;
			Conj<Registro> CombinarRegistro(const String c, const Tabla t) const;
			Conj<Dato> DameColumna(const String c, const Conj<Registro> cr) const;
			bool MismosTipos(const Registro r) const;
			Conj<Registro> BuscarT(const Registro r) const;
			Nat CantidadDeAccesos() const;
			bool Esta(const Registro r) const;
			void BuscarYBorrar(const Registro crit);
			ostream& mostrarTabla(ostream& os) const;

		private: 
			Nat modificaciones;
			indiceNat indiceN;
			indiceStr indiceS;
			tupla indicesUsados;
			String nombre;
			Conj<String> claves;
			Registro columnas;
			Lista<Registro> registros;





};


// ----------------------> ALGORITMOS <----------------------

Tabla::Tabla(): modificaciones(0) , nombre("higuain muerto"){}

Tabla::Tabla(const Tabla& otra): modificaciones (otra.modificaciones) , indiceN(otra.indiceN), indiceS(otra.indiceS) , indicesUsados(otra.indicesUsados) , nombre(otra.nombre) , claves (otra.claves) , columnas(otra.columnas), registros(otra.registros) {}	

Tabla::~Tabla(){}

Tabla::Tabla(String s , Conj<String> clav, Registro colum): modificaciones(0) , nombre(s) , claves(clav) , columnas(colum) {}

void Tabla::AgregarRegistro(const Registro r){
	typename Lista<apuntador>::Iterador In;
	typename Lista<apuntador>::Iterador Is;
	registros.AgregarAtras(r);
	typename Lista<Registro>::Iterador it = registros.CrearItUlt();
	it.Retroceder();
	if(indicesUsados.nat){
		Nat n = r.Obtener(indiceN.campo).ValorNat(); //EN el tp no haciamos la conversion de dato a nat
		if(!(indiceN.minimo.MenorOIgual(n))){
			indiceN.minimo = n;
		}
		if(indiceN.maximo.MenorOIgual(n)){
			indiceN.maximo = n;
		}
		if(indiceN.regpordato.Definido(n)){
			apuntador ap;
			ap.reg = it;
			indiceN.regpordato.Obtener(n).AgregarAtras(ap);
		}else{
			apuntador ap;
			ap.reg = it;
			Lista<apuntador> l;
			l.AgregarAtras(ap);
			indiceN.regpordato.Definir(n, l);
		}
		if(indicesUsados.str){
			In = indiceN.regpordato.Obtener(n).CrearItUlt();
			In.Retroceder();
		}
	}
	if(indicesUsados.str){
		String s = r.Obtener(indiceS.campo).ValorStr(); //EN el tp no haciamos la conversion de dato a string
		if(!( indiceS.minimo.MenorOIgual(s))){
			indiceS.minimo = s;
		}
		if(indiceS.maximo.MenorOIgual(s)){
			indiceS.maximo = s;
		}
		if(indiceS.regpordato.Definido(s)){
			apuntador ap2;
			ap2.reg = it;
			indiceS.regpordato.Obtener(s).AgregarAtras(ap2);
		}else{
			apuntador ap2;
			ap2.reg = it;
			Lista<apuntador> l2;
			l2.AgregarAtras(ap2);
			l2.AgregarAtras(ap2);
			indiceS.regpordato.Definir(s, l2);
		}
		if(indicesUsados.nat){
			Is = indiceS.regpordato.Obtener(s).CrearItUlt();
			Is.Retroceder();
		}
	}
	if(indicesUsados.nat && indicesUsados.str){
		Is.Siguiente().compadre = In;
		In.Siguiente().compadre = Is;
	}
	modificaciones++;
}



bool Tabla::TipoCampo(const String c) const {
	typename Dicc<String,Dato>::Iterador it = columnas.DameDic().CrearIt();
	while(it.SiguienteClave() != c){
		it.Avanzar();
	}
return it.SiguienteSignificado().EsNat();
}

const Conj<Registro> Tabla::Registros() const{		// No actualizamos un cambio de estructura, "registros" es una Lista  y no un Conj
	Conj<Registro> res;
	typename Lista<Registro>::const_Iterador it = registros.CrearIt();
	while(it.HaySiguiente()){
		res.AgregarRapido(it.Siguiente());
		it.Avanzar();
	}
	return res;
}

const Conj<String> Tabla::Claves() const{
	return claves;
}



Dato Tabla::Minimo(const String c){
	assert(Indices().Pertenece(c));
	if (TipoCampo(c)){
		return indiceN.minimo;
	}else{
		return indiceS.minimo;
	}
}


Dato Tabla::Maximo(const String c){
	assert(Indices().Pertenece(c));
	if (TipoCampo(c)){
		return indiceN.maximo;
	}else{
		return indiceS.maximo;
	}
}


const Conj<String> Tabla::Indices() const{
 	Conj<String> res;
 	if(indicesUsados.nat){
 		res.AgregarRapido(indiceN.campo);
 	}
 	if(indicesUsados.str){
 		res.AgregarRapido(indiceS.campo);
 	}
 	return res;
 }

bool Tabla::Compatible(const Registro r) const{
	return (r.Campos() == columnas.Campos() && MismosTipos(r));
}

Conj<Dato> Tabla::DameColumna(const String c, const Conj<Registro> cr) const{
 	Conj<Dato> res;
 	typename Conj<Registro>::const_Iterador it = cr.CrearIt();
 	while (it.HaySiguiente()){
 		res.AgregarRapido(it.Siguiente().Obtener(c));
 		it.Avanzar();
 	}
 	return res;
 }

bool Tabla::MismosTipos(const Registro r) const{
	typename Dicc<String,Dato>::Iterador it = columnas.DameDic().CrearIt();
		while(it.HaySiguiente() && TipoCampo(it.SiguienteClave()) == it.SiguienteSignificado().EsNat()){
			it.Avanzar();
		}
	return (!it.HaySiguiente());
}

Nat Tabla::CantidadDeAccesos() const{
	return modificaciones;
}


Conj<Registro> Tabla::CombinarRegistro(const String c, const Tabla t) const{
	Conj<Registro> res;
	typename Lista<Registro>::const_Iterador it = registros.CrearIt();		// Los Dicc(campo,dato) son Registros y cambiamos Conj por Lista porque no actualizamos el cambio de estructura
	Dato valor;
	while(it.HaySiguiente()){
		valor = it.Siguiente().Obtener(c);
		Registro crit;
		crit.Definir(c,valor);
		typename Conj<Registro>::Iterador Ic = t.BuscarT(crit).CrearIt();
		while (Ic.HaySiguiente()){
			res.Agregar(it.Siguiente().AgregarCampos(Ic.Siguiente()));
			Ic.Avanzar();			// En el tp no avanzaba el iterador... genius
		}
		it.Avanzar();			// En el tp no avanzaba el iterador... DOBLE GENUIS
	}
	return res;
}


/*
void BorrarRegistro(const Registro crit);
void Indexar(const String c);
//Conj<Registro> BuscarT(const Registro r) const;
bool Esta(const Registro r) const;
void BuscarYBorrar(const Registro crit);
ostream& mostrarTabla(ostream& os) const;
*/





// ---------------------->  FIN ALGORITMOS <----------------------
};









































#endif