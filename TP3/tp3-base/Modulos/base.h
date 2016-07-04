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
					//tupla() tabmod("default"){}
				};

				struct Join {
					String campo;
					Lista<tupla> cambios;
					typename Lista<Tabla>::Iterador verJoin;
					//join(): campo("default"){}
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
			void GenerarVistaJoin(const String t,const String c);
			void BorrarJoin(Tabla t1, Tabla t2);
			Conj<Registro> Buscar(Registro criterio,Tabla t1);
			Conj<Registro> VistaJoin(const String t1, const String t2);
			Conj<Registro> Registros(const String t1);
			Nat CantidadDeAccesos(const String t);

		private:	
		
			Conj<Tabla> tablas;
			DiccString<typename::Conj<Tabla>::Iterador> TporNombre;
			Conj<String> nombres;
			typename Conj<Tabla>::Iterador TablaMax;
			DiccString< DiccString<Join> > joins;
			Lista<Tabla> losjoins;

	};



//----------------------------------------> ALGORITMOS <-------------------------------
Base::Base(){}

Base::Base(const Base& otra): tablas(otra.tablas) ,TporNombre(otra.TporNombre),  nombres(otra.nombres) , TablaMax(otra.TablaMax) , joins(otra.joins) , losjoins(otra.losjoins) {}

Base::~Base(){}

Conj<String> Base::Tablas(){
	Conj<String> res;
	typename DiccString<typename::Conj<Tabla>::Iterador>::const_ItStr it = TporNombre.CrearIt();
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
	tablas.AgregarRapido(t);
	typename Conj<Tabla>::const_Iterador i = tablas.CrearIt();
	while(i.HaySiguiente() && i.Siguiente().DameNombre() != t.DameNombre()){
		i.Avanzar();
	}
	TporNombre.Definir(t.DameNombre(), i);
	nombres.AgregarRapido( t.DameNombre());
	if(tablas.EsVacio()){
		TablaMax = i;
	}else{
		if(t.DameNombre().CantidadAccesos() > TablaMax.Siguiente().DameNombre().CantidadAccesos()){
			TablaMax = i;
		}
	}
}

















};

#endif