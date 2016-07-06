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


namespace modulos{
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
				DiccLog< Nat, Lista<apuntador> > regpordato;
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
			bool Esta(const Registro r)const;
			void BuscarYBorrar(const Registro crit);
			ostream& mostrarTabla(ostream& os) const;
			const String DameNombre() const; //ESTO NO ESTA EN EL TP
			const Registro Columnas() const;
			void MostrameIndices() const;
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

const Registro Tabla::Columnas() const{
	Registro r;
	r = columnas;
	return r;
}

void Tabla::AgregarRegistro(const Registro r){
	typename Lista<apuntador>::Iterador In;
	typename Lista<apuntador>::Iterador Is;
	registros.AgregarAtras(r);
	typename Lista<Registro>::Iterador it = registros.CrearItUlt();
	it.Retroceder();
	if(indicesUsados.nat){
		Nat n = r.Obtener(indiceN.campo).ValorNat(); //EN el tp no haciamos la conversion de dato a nat
		if (indiceN.regpordato.EsVacio()){
				indiceN.maximo = n;
				indiceN.minimo = n;			
		}else{
			if(!(indiceN.minimo.MenorOIgual(n))){
				indiceN.minimo = n;
			}
			if(indiceN.maximo.MenorOIgual(n)){
				indiceN.maximo = n;
			}
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
		if(indiceS.regpordato.EsVacio()){
				indiceS.minimo = s;
				indiceS.maximo = s;
		}else{
			if(!( indiceS.minimo.MenorOIgual(s))){
				indiceS.minimo = s;
			}
			if(indiceS.maximo.MenorOIgual(s)){
				indiceS.maximo = s;
			}
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
	assert(columnas.Def(c));
	return columnas.Obtener(c).EsNat();
}

const Conj<Registro> Tabla::Registros() const{		// No actualizamos un cambio de estructura, "registros" es una Lista  y no un Conj
	Conj<Registro> res;
	typename Lista<Registro>::const_Iterador it = registros.CrearIt();
	while(it.HaySiguiente()){
		res.Agregar(it.Siguiente());		
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
	Dicc<String, Dato> dc = columnas.DameDic();
	typename Dicc<String,Dato>::Iterador it = dc.CrearIt();
		while(it.HaySiguiente() && TipoCampo(it.SiguienteClave()) == it.SiguienteSignificado().EsNat()){
			it.Avanzar();
		}
	return (!it.HaySiguiente());
}

Nat Tabla::CantidadDeAccesos() const{
	return modificaciones;
}


Conj<Registro> Tabla::BuscarT(const Registro crit) const{
	Dicc<String,Dato> ds = crit.DameDic();
	typename Dicc<String,Dato>::Iterador it = ds.CrearIt();
	while(it.HaySiguiente() && columnas.Def(it.SiguienteClave()) && TipoCampo(it.SiguienteClave()) == it.SiguienteSignificado().EsNat()){
		it.Avanzar();
	}
	Conj<Registro> res;
	Conj<String> cs = crit.Campos();
	if(!(it.HaySiguiente())){
		if(indicesUsados.nat == true && cs.Pertenece(indiceN.campo)){
			Nat n = crit.Obtener(indiceN.campo).ValorNat();
			typename DiccLog< Nat, Lista<apuntador> >::const_ItLog ir2 = indiceN.regpordato.Buscar(n);
			typename Lista<apuntador>::const_Iterador i = ir2.SiguienteSignificado().CrearIt(); 
			while(i.HaySiguiente()){
				if(crit.CoincidenTodos(cs, i.Siguiente().reg.Siguiente())){
					res.AgregarRapido(i.Siguiente().reg.Siguiente());
				}
				i.Avanzar();
			}
		}else{
			if(indicesUsados.str == true && cs.Pertenece(indiceS.campo)){
				String s = crit.Obtener(indiceS.campo).ValorStr();
				typename DiccString< Lista<apuntador> >::const_ItStr ir = indiceS.regpordato.Buscar(s);
				typename Lista<apuntador>::const_Iterador i = ir.SiguienteSignificado().CrearIt(); 
				while(i.HaySiguiente()){
					if(crit.CoincidenTodos(cs, i.Siguiente().reg.Siguiente())){
						res.AgregarRapido(i.Siguiente().reg.Siguiente());
					}
					i.Avanzar();
				}
			}else{
				typename Lista<Registro>::const_Iterador i = registros.CrearIt(); 
				while(i.HaySiguiente()){
					if(crit.CoincidenTodos(cs, i.Siguiente())){
						res.AgregarRapido(i.Siguiente());
					}
					i.Avanzar();
				}
			}
		}
	}
	return res;
}



Conj<Registro> Tabla::CombinarRegistro(const String c, const Tabla t) const{		//NO TIRA ERROR PORQUE DEVUELVE UNA LISTA EN VEZ DE UN CONJ (NO FUNCIONA EL CONJ SI LE PASAS LISTAS)
	Conj<Registro> res;
	Lista<Registro> lr = registros;
	typename Lista<Registro>::const_Iterador it = lr.CrearIt();		// Los Dicc(campo,dato) son Registros y cambiamos Conj por Lista porque no actualizamos el cambio de estructura
	Dato valor;
	while(it.HaySiguiente()){
		valor = it.Siguiente().Obtener(c);
		Registro crit;
		crit.Definir(c,valor);
		Conj<Registro> cr = t.BuscarT(crit);
		typename Conj<Registro>::Iterador Ic = cr.CrearIt();
		while (Ic.HaySiguiente()){
			res.Agregar(it.Siguiente().AgregarCampos(Ic.Siguiente()));
			Ic.Avanzar();					// En el tp no avanzaba el iterador... genius
		}
		it.Avanzar();					// En el tp no avanzaba el iterador... DOUBLE GENUIS
	}
	return res;
}

const String Tabla::DameNombre() const{
	return nombre;
}

bool Tabla::Esta(const Registro r) const{
	bool res=false;
	if(Compatible(r)){
		if(indicesUsados.nat || indicesUsados.str){
			if(indicesUsados.nat && claves.Pertenece(indiceN.campo)){
				Nat n = r.Obtener(indiceN.campo).ValorNat();
				if(indiceN.regpordato.Definido(n)){
					res = (r == indiceN.regpordato.Obtener(n).Primero().reg.Siguiente());
				}
			}
			if(indicesUsados.str && claves.Pertenece(indiceN.campo)){
				String s = r.Obtener(indiceS.campo).ValorStr();
				if(indiceS.regpordato.Definido(s)){
					res = (r == indiceS.regpordato.Obtener(s).Primero().reg.Siguiente());
				}
			}
		}else{
			Lista<Registro> ri = registros;
			typename Lista<Registro>::const_Iterador i = ri.CrearIt();
			while(i.HaySiguiente()){
				res = (res || (i.Siguiente() == r));
				i.Avanzar();
			}
		}
	}
	return res;
}

void Tabla::Indexar(const String c){
	typename Lista<Registro>::Iterador it = registros.CrearIt();
	Dato min = it.Siguiente().Obtener(c);
	Dato max = it.Siguiente().Obtener(c);
	if(TipoCampo(c)){
		indicesUsados.nat = true;
		indiceN.campo = c;
		while(it.HaySiguiente()){
			if(it.Siguiente().Obtener(c).MenorOIgual(min)){
				min = it.Siguiente().Obtener(c);
			}
			if(!(it.Siguiente().Obtener(c).MenorOIgual(max))){
				max = it.Siguiente().Obtener(c);
			}
			apuntador a;
			a.reg = it;
			if(indiceN.regpordato.Definido(it.Siguiente().Obtener(c).ValorNat())){
				indiceN.regpordato.Obtener(it.Siguiente().Obtener(c).ValorNat()).AgregarAtras(a);
			}else{
				Lista<apuntador> L;
				L.AgregarAtras(a);
				indiceN.regpordato.Definir(it.Siguiente().Obtener(c).ValorNat(), L);
			}
			if(indicesUsados.str){
				typename Lista<apuntador>::Iterador In = indiceN.regpordato.Obtener( it.Siguiente().Obtener(c).ValorNat() ).CrearItUlt();
				In.Retroceder();
				typename Lista<apuntador>::Iterador Is = indiceS.regpordato.Obtener( it.Siguiente().Obtener(indiceS.campo).ValorStr() ).CrearIt();
				while ( !(Is.Siguiente().reg.Siguiente() == it.Siguiente()) ){
					Is.Avanzar();
				}
				Is.Siguiente().compadre = In;
				In.Siguiente().compadre = Is;
			}
			it.Avanzar();			// En el TP2 no avanzabamos el iterador... TRIIIPLE GENIUS
		}
		indiceN.minimo = min;			// No actualizabamos los maximos y
		indiceN.maximo = max;			// minimos en el TP2
	}else{
		indicesUsados.str = true;
		indiceS.campo = c;
		while(it.HaySiguiente()){
			if(!(min.MenorOIgual(it.Siguiente().Obtener(c).ValorStr()))){
				min = it.Siguiente().Obtener(c);
			}
			if(max.MenorOIgual(it.Siguiente().Obtener(c).ValorStr())){
				max = it.Siguiente().Obtener(c);
			}
			apuntador a;
			a.reg = it;
			if(indiceS.regpordato.Definido(it.Siguiente().Obtener(c).ValorStr())){
				indiceS.regpordato.Obtener(it.Siguiente().Obtener(c).ValorStr()).AgregarAtras(a);
			}else{
				Lista<apuntador> L;
				L.AgregarAtras(a);
				indiceS.regpordato.Definir(it.Siguiente().Obtener(c).ValorStr(), L);
			}
			if(indicesUsados.nat){
				typename Lista<apuntador>::Iterador Is = indiceS.regpordato.Obtener(it.Siguiente().Obtener(c).ValorStr()).CrearItUlt(); 
				Is.Retroceder();
				typename Lista<apuntador>::Iterador In = indiceN.regpordato.Obtener(it.Siguiente().Obtener(indiceN.campo).ValorNat()).CrearIt();
				while(!(In.Siguiente().reg.Siguiente() == it.Siguiente()) ){
					In.Avanzar();
				}
				In.Siguiente().compadre = Is;
				Is.Siguiente().compadre = In;
			}
			it.Avanzar();
		}
		indiceS.minimo = min;
		indiceS.maximo = max;
	}
}

void Tabla::MostrameIndices() const{
	if(indicesUsados.nat){
		cout << "Indice Nat:" << endl;
		/*cout << indiceN.campo << endl;
		cout << indiceN.minimo << endl;
		cout << indiceN.maximo << endl;*/
		typename DiccLog<Nat, Lista<apuntador> >::const_ItLog in = indiceN.regpordato.CrearIt();
		while(in.HaySiguiente()){
			cerr << in.SiguienteClave() << ":  "<< endl;
			typename Lista<apuntador>::const_Iterador i = in.SiguienteSignificado().CrearIt();
			while(i.HaySiguiente()){
				cerr << i.Siguiente().reg.Siguiente() << "-->" << i.Siguiente().compadre.Siguiente().reg.Siguiente() << endl;
				i.Avanzar();
			}
			in.Avanzar();
			cout << endl<<endl;
		}
	}
	if(indicesUsados.str){
		cout << "Indice String" << endl;
		/*cout << indiceS.campo << endl;
		cout << indiceS.minimo << endl;
		cout << indiceS.maximo << endl;*/
		typename DiccString<Lista<apuntador> >::const_ItStr is = indiceS.regpordato.CrearIt();
		is.Avanzar();
		while(is.HaySiguiente()){
			cerr << is.SiguienteClave() << ":  " << endl;
			typename Lista<apuntador>::const_Iterador i = is.SiguienteSignificado().CrearIt();
			while(i.HaySiguiente()){
				cerr << i.Siguiente().reg.Siguiente() << "--->" << i.Siguiente().compadre.Siguiente().reg.Siguiente() << endl;
				i.Avanzar();
			}
			is.Avanzar();
			cout << endl<< endl;
		}
	}
}



void Tabla::BuscarYBorrar(const Registro crit){
	Dicc<String, Dato> dica = crit.DameDic();								
	typename Dicc<String,Dato>::Iterador it7 = dica.CrearIt();			
	typename Lista<Registro>::Iterador rs = registros.CrearIt();			
	Dato d = it7.SiguienteSignificado();
	String c = it7.SiguienteClave();									
	while(rs.HaySiguiente() && !(rs.Siguiente().Obtener(c) == d)) {
		rs.Avanzar();
	}
	if(indicesUsados.nat || indicesUsados.str){
		if(indicesUsados.nat){
			typename Lista<apuntador>::Iterador fa = indiceN.regpordato.Obtener(rs.Siguiente().Obtener(indiceN.campo).ValorNat()).CrearIt();
			while(fa.HaySiguiente() && fa.Siguiente().reg.Siguiente().Obtener(c) != d){	
				fa.Avanzar();
			}
			Nat m = fa.Siguiente().reg.Siguiente().Obtener(indiceN.campo).ValorNat();					//fa es el iterador al apuntador correspondiente y m es el dato del registro correspondiente
			if(indicesUsados.str){
				String s4 = fa.Siguiente().reg.Siguiente().Obtener(indiceS.campo).ValorStr(); 
				//cerr << indiceS.regpordato.Definido(s4) << endl;
				Lista<apuntador> la2 = indiceS.regpordato.Obtener(s4);
				if(la2.Longitud() == 1){
					indiceS.regpordato.Borrar(s4);
				}else{
					fa.Siguiente().compadre.EliminarSiguiente();
				}
			}
			if((indiceN.regpordato.Obtener(rs.Siguiente().Obtener(indiceN.campo).ValorNat())).Longitud() == 1){
				indiceN.regpordato.Borrar(m);
			}
			fa.Siguiente().reg.EliminarSiguiente();
			fa.EliminarSiguiente();
			if(indiceN.maximo == m){
				indiceN.maximo = indiceN.regpordato.Maximo();
			}
			if(indiceN.minimo == m){
				indiceN.minimo = indiceN.regpordato.Minimo();
			}
		}else{
			if(indicesUsados.str){
				Lista<apuntador> ts = indiceS.regpordato.Obtener(rs.Siguiente().Obtener(indiceS.campo).ValorStr());
				typename Lista<apuntador>::Iterador fu = ts.CrearIt();
				while(fu.HaySiguiente() && fu.Siguiente().reg.Siguiente().Obtener(c) != d){
					fu.Avanzar();
				}
				String n = fu.Siguiente().reg.Siguiente().Obtener(indiceS.campo).ValorStr();
				/*if (indicesUsados.nat){
					fu.Siguiente().compadre.EliminarSiguiente();
					Nat coso = rs.Siguiente().Obtener(indiceN.campo).ValorNat();
					if(indiceN.regpordato.Obtener(coso).Longitud() == 0){
						indiceN.regpordato.Borrar(coso);
					}
				}*/
				if(indiceS.regpordato.Obtener(rs.Siguiente().Obtener(indiceS.campo).ValorStr()).Longitud() == 1){
					fu.Siguiente().reg.EliminarSiguiente();
					cerr << "Quedo sin registros D=" << endl;
					indiceS.regpordato.Borrar(n);
				}else{
					fu.Siguiente().reg.EliminarSiguiente();
					fu.EliminarSiguiente();
				}
				if(indiceS.maximo == n){
					cerr << "Actualiza maximo a  " << indiceS.regpordato.Maximo() << endl;
					indiceS.maximo = indiceS.regpordato.Maximo();
				}
				if(indiceS.minimo == n){
					cerr << "Actualiza minimo" << endl;
					indiceS.minimo = indiceS.regpordato.Minimo();
				}
			}
		}
	}else{
		rs.EliminarSiguiente();
	}
}

void Tabla::BorrarRegistro(const Registro crit){
	modificaciones++;
	Dicc<String, Dato> ms = crit.DameDic();
	typename Dicc<String,Dato>::const_Iterador j = ms.CrearIt();
	String c = j.SiguienteClave();
	Nat d = j.SiguienteSignificado().ValorNat();
	String f = j.SiguienteSignificado().ValorStr();
	if(TipoCampo(c)){
		if (!DameColumna(c,Registros()).Pertenece(d)){
			return;
		}
		if(indicesUsados.nat && indiceN.campo == c){
			typename DiccLog< Nat,Lista<apuntador> >::ItLog it = indiceN.regpordato.Buscar(d);  //
			if(it.HaySiguiente()){
				typename Lista<apuntador>::Iterador itl = it.SiguienteSignificado().CrearIt();
				if(indicesUsados.str){
					String s = it.SiguienteSignificado().Primero().reg.Siguiente().Obtener(indiceS.campo).ValorStr();
					//String s = it.SiguienteSignificado().Primero().reg.Siguiente().Obtener(indiceS.campo).ValorStr();
					itl.Siguiente().compadre.EliminarSiguiente();
					if(claves.Pertenece(indiceS.campo) || indiceS.regpordato.Obtener(s).Longitud() == 0){
						indiceS.regpordato.Borrar(s);
					}
				}
				itl.Siguiente().reg.EliminarSiguiente();
				indiceN.regpordato.Borrar(d);
				if(indiceN.maximo == d && !(indiceN.regpordato.EsVacio())){
					indiceN.maximo = indiceN.regpordato.Maximo();
				}
				if(indiceN.minimo == d && !(indiceN.regpordato.EsVacio())){
					indiceN.minimo = indiceN.regpordato.Minimo();
				}
			}
		}else{
			BuscarYBorrar(crit);
		}
	}else{
		if (!DameColumna(c,Registros()).Pertenece(f)){
			return;
		}
		if(indicesUsados.str && indiceS.campo == c){
			typename DiccString< Lista<apuntador> >::ItStr it = indiceS.regpordato.Buscar(f);
			if(it.SiguienteClave() == f){
				typename Lista<apuntador>::Iterador itl = it.SiguienteSignificado().CrearIt();
				if(indicesUsados.nat){
					Nat n = it.SiguienteSignificado().Primero().reg.Siguiente().Obtener(indiceN.campo).ValorNat();
					itl.Siguiente().compadre.EliminarSiguiente();
					if(claves.Pertenece(indiceN.campo) || indiceN.regpordato.Obtener(n).Longitud() == 0){
						indiceN.regpordato.Borrar(n);
					} 
				}
				itl.Siguiente().reg.EliminarSiguiente();
				indiceS.regpordato.Borrar(f);
				if(indiceS.maximo == f && !(indiceS.regpordato.EsVacio())){
					indiceS.maximo = indiceS.regpordato.Maximo();
				}
				if(indiceS.minimo == f && !(indiceS.regpordato.EsVacio())){
					indiceS.minimo = indiceS.regpordato.Minimo();
				}
			}
		}else{
			BuscarYBorrar(crit);
		}
	}
}

/*
ostream& mostrarTabla(ostream& os) const;
*/





// ---------------------->  FIN ALGORITMOS <----------------------
};




#endif