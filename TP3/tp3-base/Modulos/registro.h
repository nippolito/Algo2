#ifndef MODULOS_REGISTRO_H_INCLUDED   //registro es parte de la carpeta modulos
#define MODULOS_REGISTRO_H_INCLUDED

#include <iostream>
#include <string>
#include <cassert>
#include "ModulosBasicos.h"
#include "Dato.h"

using namespace aed2;

namespace modulos {
	
class Registro {		// Algunas funciones con "?" cambiaron de nombre
	public:
		Registro();
		Registro(const Registro& otro);
		void Definir(const String c, const Dato d);
		void DefinirLento(const String c, const Dato d);
		void Borrar(const String c);
		bool Def(const String c) const;
		Dato Obtener(const String c) const;
		Conj<String> Campos() const;
		bool BorraAlgo(const Registro crit) const;	// Es "Borrar?"
		Registro AgregarCampos(const Registro r2) const;		// El Registro implicito this es r_1
		Registro CopiarCampos(const Conj<String> cc, const Registro r2) const;
		bool CoincideAlguno(const Conj<String> cc, const Registro r2) const;
		bool CoincidenTodos(const Conj<String> cc, const Registro r2) const;
		bool EnTodos(const String c, const Conj<Registro>);
		Registro CombinarTodos(const String c, const Conj<Registro>) const;
		Conj<String> DiferenciaSimetrica(const Registro r2) const;
	
	private:
		Dicc<String,Dato> dic;
};

Registro::Registro(){}

Registro::Registro(const Registro& otro): dic(otro.dic){}

void Registro::Definir(String c, Dato d){
	dic.DefinirRapido(c,d);
}

void Registro::DefinirLento(String c, Dato d){
	dic.Definir(c,d);
}

void Registro::Borrar(const String c){
	dic.Borrar(c);
}

bool Registro::Def(const String c) const{
	dic.Definido(c);
}

Dato Registro::Obtener(const String c) const{
	dic.Significado(c);
}

Conj<String> Registro::Campos() const{
	Conj<String> res;
	typename Dicc<String,Dato>::const_Iterador it = dic.CrearIt();
	while (it.HaySiguiente()){
		res.AgregarRapido(it.SiguienteClave());
		it.Avanzar();
	}
	return res;
}
/*
bool Registro::BorraAlgo(const Registro crit) const{
	return CoincidenTodos(crit.Campos(),crit);
}

Registro Registro::AgregarCampos(const Registro r2) const{
	return CopiarCampos(DiferenciaSimetrica(r2),r2);
}
*/
Registro Registro::CopiarCampos(const Conj<String> cc, const Registro r2) const{
	Conj<String>::const_Iterador it = cc.CrearIt();
	
	Registro res(*this);
	while(it.HaySiguiente()){
		if (Def(it.Siguiente())){
			res.DefinirLento(it.Siguiente(), r2.Obtener(it.Siguiente()));
		}else{
			res.Definir(it.Siguiente(), r2.Obtener(it.Siguiente()));
		}
	}
}

// Esta mal diseñada, recorre el registro r1 en vez de cc
bool Registro::CoincideAlguno(const Conj<String> cc, const Registro r2) const{
	bool b = false;
	typename Conj<String>::const_Iterador it1 = cc.CrearIt();
	while(it1.HaySiguiente() && !b){
		if(Obtener(it1.Siguiente()) == r2.Obtener(it1.Siguiente()) ){
			b = true;
		}
		it1.Avanzar();
	}
	return b;
}

// Esta mal diseñada, recorre el registro r1 en vez de cc
/*
bool Registro::CoincidenTodos(const Conj<String> cc, const Registro r2) const{
	
	bool b = true;
	typename Conj<String>::const_Iterador it1 = cc.CrearIt();
	while(it1.HaySiguiente() && b){
		if(!(Obtener(it1.Siguiente()) == r2.Obtener(it1.Siguiente()))){
			b = false;
		}
		it1.Avanzar();
	}
	return b;
}
*/
/*
		bool EnTodos(const String c, const Conj<Registro>);
		Registro CombinarTodos(const String c, const Conj<Registro>) const;
		Conj<String> DiferenciaSimetrica(const Registro r2) const;
*/
};

#endif
