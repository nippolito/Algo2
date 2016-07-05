#ifndef MODULOS_BASE_H_INCLUDED
#define MODULOS_BASE_H_INCLUDED

#include "tabla.h"


using namespace std;
using namespace aed2;


namespace modulo{
	class Base{
		
		private: 
				
				struct tupla{
					String tabmod;
					Registro regmod;
					tupla(){}
				};

				struct Join {
					String campo;
					Lista<tupla> cambios;
					typename Lista<Tabla>::Iterador verJoin;
					Join(){} //CHEQUEAR QUE LO CREE VACIO
				};

		public:

			Base();
			Base(const Base& otra);
			~Base();
			Base& operator=(const Base& otra);
			Conj<String> Tablas(); 
			Tabla DameTabla(const String t);
			bool HayJoin(const String t1, const String t2);
			String CampoJoin(const String t1,const String t2);
			void AgregarTabla(Tabla t);
			void InsertarEntrada(Registro r, String t);
			void Borrar(Registro r, String t);
			typename Lista<Registro>::Iterador GenerarVistaJoin(const String t, const String t2, const String c);
			void BorrarJoin(const String t1, const String t2);
			Conj<Registro> Buscar(Registro criterio,Tabla t1);
			Conj<Registro> VistaJoin(const String t1, const String t2);
			Conj<Registro> RegistrosB(const String t1);
			Nat CantidadDeAccesosB(const String t);
			String TablaMaxima();

		private:	
		
			Lista<Tabla> tablas;  //igual que arriba
			DiccString<typename::Lista<Tabla>::Iterador> TporNombre;  //En el TP es un Conjunto, lo cambiamos por Lista porque el sig de Conjunto es const
			Conj<String> nombres;
			typename Lista<Tabla>::Iterador TablaMax; //igual que arriba
			DiccString< DiccString<Join> > joins;
			Lista<Tabla> losjoins;

	};



//----------------------------------------> ALGORITMOS <-------------------------------
Base::Base(){}

Base::Base(const Base& otra): tablas(otra.tablas) ,TporNombre(otra.TporNombre),  nombres(otra.nombres) , TablaMax(otra.TablaMax) , joins(otra.joins) , losjoins(otra.losjoins) {}

Base::~Base(){}

Conj<String> Base::Tablas(){
	Conj<String> res;
	typename DiccString<typename::Lista<Tabla>::Iterador>::const_ItStr it = TporNombre.CrearIt();
	while(it.HaySiguiente()){
		res.AgregarRapido(it.SiguienteClave());
		it.Avanzar();
	}
	return res;
}

Tabla  Base::DameTabla(const String t){
	return TporNombre.Obtener(t).Siguiente();
}


void Base::AgregarTabla(Tabla t){
	tablas.AgregarAtras(t);
	typename Lista<Tabla>::Iterador i = tablas.CrearIt();
	while(i.HaySiguiente() && i.Siguiente().DameNombre() != t.DameNombre()){
		i.Avanzar();
	}
	TporNombre.Definir(t.DameNombre(), i);
	nombres.AgregarRapido(t.DameNombre());
	if(tablas.EsVacia()){
		TablaMax = i;
	}else{
		if( CantidadDeAccesosB(t.DameNombre()) > CantidadDeAccesosB(TablaMax.Siguiente().DameNombre())){
			TablaMax = i;
		}
	}
}


void Base::InsertarEntrada(Registro r, String t){
	typename DiccString<typename::Lista<Tabla>::Iterador>::ItStr i = TporNombre.Buscar(t);
	i.SiguienteSignificado().Siguiente().AgregarRegistro(r);
	if(CantidadDeAccesosB(TporNombre.Obtener(t).Siguiente().DameNombre()) > CantidadDeAccesosB(TablaMax.Siguiente().DameNombre())){
		TablaMax = TporNombre.Obtener(t);
	}
	if(joins.Definido(t)){
		typename DiccString<Join>::ItStr it = joins.Obtener(t).CrearIt();
		while(it.HaySiguiente()){
			tupla tps;
			tps.regmod = r;
			tps.tabmod = t;
			it.SiguienteSignificado().cambios.AgregarAdelante(tps);
			if(HayJoin(it.SiguienteClave(), t)){
				joins.Obtener(it.SiguienteClave()).Obtener(t).cambios.AgregarAdelante(tps);
			}
			it.Avanzar();
		}
	}
}


Conj<Registro> Base::Buscar(Registro criterio,Tabla t1){			//falta buscarT
	Conj<Registro> r;
	return r;
}


void Base::Borrar(Registro r, String t){
	typename DiccString<typename::Lista<Tabla>::Iterador>::ItStr i = TporNombre.Buscar(t);
	//i.SiguienteSignificado().BorrarRegistro(r);
	if(CantidadDeAccesosB(TporNombre.Obtener(t).Siguiente().DameNombre()) > CantidadDeAccesosB(TablaMax.Siguiente().DameNombre())){
		TablaMax = TporNombre.Obtener(t);
	}
	if(joins.Definido(t)){
		typename DiccString<Join>::ItStr it = joins.Obtener(t).CrearIt();
		while(it.HaySiguiente()){
			tupla tps;
			tps.regmod = r;
			tps.tabmod = t;
			it.SiguienteSignificado().cambios.AgregarAdelante(tps);
			if(HayJoin(it.SiguienteClave(), t)){
				joins.Obtener(it.SiguienteClave()).Obtener(t).cambios.AgregarAdelante(tps);
			}
			it.Avanzar();
		}
	}
}


String Base::TablaMaxima(){
	return TablaMax.Siguiente().DameNombre();
}


bool Base::HayJoin(const String t1, const String t2){
	return joins.Obtener(t1).Definido(t2);
}


void Base::BorrarJoin(const String t1, const String t2){
	typename DiccString<Join>::ItStr j = joins.Obtener(t1).Buscar(t2);
	j.EliminarSiguiente();
}


String Base::CampoJoin(const String t1,const String t2){
	typename DiccString<Join>::ItStr j = joins.Obtener(t1).Buscar(t2);
	return j.SiguienteSignificado().campo;
}


/*typename Lista<Registro>::Iterador Base::GenerarVistaJoin(const String t1, const String t2, const String c){
	Conj<Registro> rs = t1.combinarRegistros(c, t2);
	typename Registro::Iterador it = rs.CrearIt();
	Conj<String> cla;
	cla.Agregar(c);
	nt = Tabla("nuevat", cla , it.Siguiente());
	nt.Indexar(c);
	while(it.HaySiguiente()){
		nt.AgregarRegistro(it.Siguiente());
	}
	losjoins.AgregarAdelante(nt);
	typename Lista<Tabla>::Iterador it2 = losjoins.CrearIt();
	typename Lista<Registro>::const_Iterador res =  it2.Siguiente().Registros().CrearIt();
	DiccString<Join> d;
	Join js;
	js.campo = c;
	tupla tup;
	js.cambios = tup;
	js.verJoin = it2;
	if(!joins.Definido(t1)){
		d.Definir(t2, js);
		joins.Definir(t1, d);
	}else{
		joins.Obtener(t1).Definir(t2, d);
	}	
} HASTA NO TENER COMBINA REGISTRO NO ANDA*/

// Conj<Registro> Base::RegistrosB(const String t1){
// 	return DameTabla(t1).Registros();
// }


Nat Base::CantidadDeAccesosB(const String t){
	return DameTabla(t).CantidadDeAccesos();
}






};

#endif