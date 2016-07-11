#ifndef MODULOS_REGISTRO_H_INCLUDED 
#define MODULOS_REGISTRO_H_INCLUDED

#include <iostream>
#include <string>
#include <cassert>
#include "Dato.h"

using namespace std;
using namespace aed2;

namespace modulos {
	
class Registro {		// Algunas funciones con "?" cambiaron de nombre
	public:
		Registro();
		Registro(const Dicc<String,Dato>& d);
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
		bool operator==(const Registro& r) const;
		Conj<String> DiferenciaSimetrica(const Registro r2) const;
		Dicc<String,Dato> DameDic() const;
		
	private:
		Dicc<String,Dato> dic;
};


};

#endif
