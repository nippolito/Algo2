#include "registro.h"

using namespace aed2;
using namespace modulos;
using namespace std;


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
	return dic.Definido(c);
}

Dato Registro::Obtener(const String c) const{
	assert(Def(c));
	return dic.Significado(c);
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

bool Registro::BorraAlgo(const Registro crit) const{
	return CoincidenTodos(crit.Campos(),crit);
}

Registro Registro::AgregarCampos(const Registro r2) const{
	return CopiarCampos(DiferenciaSimetrica(r2),r2);
}

Registro Registro::CopiarCampos(const Conj<String> cc, const Registro r2) const{
	Conj<String>::const_Iterador it = cc.CrearIt();
	Registro res(*this);
	while(it.HaySiguiente()){
		if (Def(it.Siguiente())){
			res.DefinirLento(it.Siguiente(), r2.Obtener(it.Siguiente()));
		}else{
			res.Definir(it.Siguiente(), r2.Obtener(it.Siguiente()));
		}
		it.Avanzar();
	}
	return res;
}

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

bool Registro::CoincidenTodos(const Conj<String> cc, const Registro r2) const{
	
	bool b = true;
	typename Conj<String>::const_Iterador it1 = cc.CrearIt();
	while(it1.HaySiguiente() && b){
		if(Obtener(it1.Siguiente()) != r2.Obtener(it1.Siguiente())){
			b = false;
		}
		it1.Avanzar();
	}
	return b;
}

Conj<String> Registro::DiferenciaSimetrica(const Registro r2) const{
	Conj<String> res;
	Conj<String> c2(r2.Campos());
	typename Conj<String>::Iterador it = c2.CrearIt();
	Conj<String> c1(Campos());
	while(it.HaySiguiente()){
		if(!(c1.Pertenece(it.Siguiente()))){
			res.AgregarRapido(it.Siguiente());
		}
		it.Avanzar();
	}
	return res;
}

Dicc<String,Dato> Registro::DameDic() const {
	return dic;
}


bool Registro::operator==(const Registro& r) const{
	return r.CoincidenTodos(Campos(), *this) && CoincidenTodos(r.Campos(), r);
}

