#ifndef MODULOS_DATO_H_INCLUDED   //registro es parte de la carpeta modulos
#define MODULOS_DATO_H_INCLUDED

#include <iostream>
#include <string>
#include <cassert>
#include "ModulosBasicos.h"
#include "Dato.h"

using namespace aed2;

namespace modulos {
	
class Registro{
	public:
		Registro();
		void Definir(String c, Dato d);
		void DefinirLento(String c, Dato d);
		void Borrar(String c);
		bool Def(String c) const;
		Dato Obtener(String c) const;
		Conj<String> Campos() const;
		bool BorraAlgo(const Registro crit) const;
		Registro AgregarCampos(const Registro r2) const;		// El Registro implicito this es r_1
		Registro CopiarCampos(const Conj<String> cc, const Registro r2);
		bool CoincideAlguno(const Conj<String> cc, const Registro r2) const;
		bool CoincidenTodos(const Conj<String> cc, const Registro r2) const;
		bool EnTodos(const String c, const Conj<Registro>);
		Registro CombinarTodos(const String c, const Conj<Registro>) const;
		Conj<String> DiferenciaSimetrica(const Registro r2) const;
	
	private:
		Dicc<String,Dato> dic;
}

Registro::Registro(): dic(Dicc()){}

void Registro::Definir(String c, Dato d){
	dic.DefinirRapido(c,d)
	}
	
	
void Registro::DefinirLento(String c, Dato d){
	dic.Definir(c,d)
	}


};

#endif
