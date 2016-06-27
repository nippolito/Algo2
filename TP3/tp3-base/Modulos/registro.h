#ifndef MODULOS_REGISTRO_H_INCLUDED   //registro es parte de la carpeta modulos
#define MODULOS_REGISTRO_H_INCLUDED

#include <iostream>
#include <string>
#include <cassert>
#include "ModulosBasicos.h"
#include "Dato.cpp"

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
		// bool EnTodos(const String c, const Conj<Registro>);
		// Registro CombinarTodos(const String c, const Conj<Registro>) const;
		Conj<String> DiferenciaSimetrica(const Registro r2) const;
		Dicc<String,Dato> DameDic();
		ostream& mostrarRegistro(ostream& os) const;
	
	private:
		Dicc<String,Dato> dic;
};

ostream& operator<<(ostream& os, const Registro& r){
	return r.mostrarRegistro(os);
}

};

#endif
