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

/*
				-------> PREGUNTA A GERVA <-----
		ESTAS FUNCIONES NO ESTAN DISEÑADAS Y NO LAS USAMOS EN EL TP, ¿LAS PONEMOS?

bool EnTodos(const String c, const Conj<Registro>){}

Registro CombinarTodos(const String c, const Conj<Registro>) const{}
		
*/

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

Dicc<String,Dato> Registro::DameDic(){
	return dic;
}
/*
int main(){
	Dato d1("Peron");
	Dato d2("Evita");
	Dato d3("Campora");
	Dato d4("Isabel");
	Dato d5("Nestor");
	
	Registro r;
	r.Definir("General", d1);
	r.Definir("Descamisados", d2);
	r.DefinirLento("Traicion", d4);
	r.DefinirLento("Bisco", d5);
	
	cout << d5 << endl;
	cout << d1 << endl;
	cout << r.Def("General") << endl;
	cout << r.DameDic() << endl;
	cout << r.DameDic().Significado("General") << endl;
	cout << r.Obtener("General") << endl;
	
	Conj<String> cs(r.Campos());
	cout << cs << endl;
	
	Registro r2;
	r2.Definir("General", d1);
	r2.DefinirLento("Traicion", d1);
	
	Conj<String> c(r2.Campos());

	cout << r.CoincidenTodos(c,r2) << endl;
	Registro ft (r.CopiarCampos(c,r2));
	//cout << ft.DameDic() << endl;
	Registro R = r.AgregarCampos(r2);
	cout << r.DiferenciaSimetrica(r2) << endl;
	cout << r2.DiferenciaSimetrica(r) << endl;
	cout << R.DameDic() << endl;
	Registro R2 = r2.AgregarCampos(r);
	cout << R2.DameDic() << endl;
	
	return 0;
}*/
