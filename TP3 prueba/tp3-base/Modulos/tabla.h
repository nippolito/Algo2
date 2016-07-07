#ifndef MODULOS_TABLA_H_INCLUDED
#define MODULOS_TABLA_H_INCLUDED

//#include "ModulosBasicos.h"
#include <iostream>
#include <string>
#include <ostream>
#include "pila.h"
#include "registro.h"
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
			Tabla(const String& s,const Conj<String>& clav, Registro& colum);
			~Tabla();
			Tabla& operator = (const Tabla& otra);
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


};




#endif