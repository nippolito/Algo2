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


namespace modulo{
	template <typename T>
	class Tabla {
		private:

			struct apuntador {
				typename Lista<T>::Iterador reg;
				typename Lista<T>::Iterador compadre;
				Lista<T> l;
				apuntador(): reg(l.CrearIt()), compadre(l.CrearIt()){}
			};

			struct indiceNat {
				String campo;
				Dato minimo;
				Dato maximo;
				DiccLog< Dato, Lista<apuntador> > regpordato;

				indiceNat() : campo("higuain muerto") , minimo(0), maximo(0), regpordato(DiccLog< Dato, Lista<apuntador> >){}
			};

			struct indiceStr {
				String campo;
				Dato minimo;
				Dato maximo;
				DiccString< Lista<apuntador> > regpordato;

				indiceStr() : campo("higuain muerto") , minimo("a"), maximo("z"), regpordato(DiccString< Lista<apuntador> >){}
			};

			struct tupla {
				bool nat;
				bool str;

				tupla() : nat(false) , str(false) {}
			};



		public:
			Tabla();
			Tabla(const Tabla& otra);
			~Tabla();
			Tabla& operator=(const Tabla& otra);
			void AgregarRegistro(const Registro r);
			void BorrarRegistro(const Registro crit);
			void Indexar(const String c);
			bool TipoCampo(const String c);
			const Conj<Registro> Registros() const;
			const Conj<String> Claves() const;
			Dato Minimo(const String c);
			Dato Maximo(const String c);
			const Conj<String> Indices() const;
			bool Compatible(const Registro r) const;
			Conj<Registro> CombinarRegistro(const String c, const Tabla t) const;
			Conj<Dato> DameColumna(const String c, const Conj<Registro> cr) const;
			bool MismosTipos(const Registro r) const;
			Conj<Registro> BuscarT(const Registro r);
			Nat CantidadDeAccesos() const;
			bool Esta(const Registro r) const;
			void BuscarYBorrar(const Registro crit);
			ostream& mostrarTabla(ostream& os) const;

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