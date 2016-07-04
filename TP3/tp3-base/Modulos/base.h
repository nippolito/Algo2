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
			typename Conj<Tabla>::Iterador tablaMax;
			DiccString< DiccString<Join> > joins;
			Lista<Tabla> losjoins;

	};



//----------------------------------------> ALGORITMOS <-------------------------------
Base::Base(){}

Base::Base(const Base& otra): tablas(otra.tablas) ,TporNombre(otra.TporNombre),  nombres(otra.nombres) , tablaMax(otra.tablaMax) , joins(otra.joins) , losjoins(otra.losjoins) {}

Base::~Base(){}

/*Base::Conj<String> Tablas(){
	Conj<String> res;
	typename DiccString<String,typename::Conj<Tabla>::Iterador>::const_ItStr it = TporNombre.CrearIt();
	while(it.HaySiguiente()){
		res.AgregarRapido(it.SiguienteClave());
		it.Avanzar();
	}
	return res;
}*/
/*
Base::Tabla DameTabla(const String t){
	return TporNombre.Obtener(t).Siguiente();
}
*/


















};

#endif