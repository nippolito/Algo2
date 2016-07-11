#ifndef MODULOS_BASE_H_INCLUDED
#define MODULOS_BASE_H_INCLUDED

#include "tabla.h"
//#include "tabla.cpp"



using namespace std;
using namespace aed2;


namespace modulos{
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
			Conj<String> Tablas() const; 
			Tabla& DameTabla(const String t) const;
			bool HayJoin(const String t1, const String t2) const;
			const String& CampoJoin(const String& t1,const String& t2) const;
			void AgregarTabla(Tabla t);
			void InsertarEntrada(Registro r, String t);
			void Borrar(Registro r, String t);
			const typename Lista<Tabla>::Iterador GenerarVistaJoin(const String t, const String t2, const String c);
			void BorrarJoin(const String t1, const String t2);
			Conj<Registro> Buscar(const Registro criterio, String t1);
			const typename Lista<Tabla>::Iterador VistaJoin(const String t1, const String t2);
			Conj<Registro> RegistrosB(const String t1);
			Nat CantidadDeAccesosB(const String t) const;
			const String TablaMaxima() const;

		private:	
		
			Lista<Tabla> tablas;  //igual que arriba
			DiccString<typename Lista<Tabla>::Iterador> TporNombre;  //En el TP es un Conjunto, lo cambiamos por Lista porque el sig de Conjunto es const
			Conj<String> nombres;
			typename Lista<Tabla>::Iterador TablaMax; //igual que arriba
			DiccString< DiccString<Join> > joins;
			Lista<Tabla> losjoins;

	};
	

};

#endif