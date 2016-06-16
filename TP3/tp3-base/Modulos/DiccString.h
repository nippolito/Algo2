#ifndef MODULOS_DICCSTRING_H_INCLUDED
#define MODULOS_DICCLSTRNG_H_INCLUDED

#include "ModulosBasicos.h"
#include <iostream>
#include <string>
#include <ostream>

using namespace aed2;
using namespace std;

namespace modulos{

template<class S>
class DiccLog{
	public:

	  struct nodo;

  	class Iterador;
		class const_Iterador;

		DiccLog();
		DiccLog(const DiccLog<K,S>& otro);
    ~DiccLog();
		DiccLog<K,S>& operator=(const DiccLog<K,S>& otro);

		Iterador Definir(const K& clave, const S& significado);

		bool EsVacio();
    bool Definido(const K& clave) const;
		const S& Obtener(const K& clave) const;
		void Borrar(const K& clave);
		const K Maximo();
		const K Minimo();
		
		Iterador CrearIt();
    const_Iterador CrearIt() const;
    
    Iterador Buscar(const K&);
    const_Iterador Buscar(const K&) const;

    class Iterador
    {
      public:

        Iterador();

        Iterador(const typename Dicc<K, S>::Iterador& otro);

        Iterador& operator = (const typename Dicc<K, S>::Iterador& otro);

        bool operator == (const typename Dicc<K,S>::Iterador&) const;

        bool HaySiguiente() const;
        const K& SiguienteClave() const;
        S& SiguienteSignificado();
        void Avanzar();
        void EliminarSiguiente();
       

      private:	
      		nodo* siguiente;
      		nodo* anterior;
      		Lista<nodo*> recorrido;
      		bool busca;

      		friend typename DiccLog<K,S>::Iterador DiccLog<K,S>::CrearIt();
       	 	friend class DiccLog<K,S>::const_Iterador;

        /*  friend ostream& operator<<(ostream& os, const typename DiccLog<K,S>::Iterador& it){
          os<<"it";
          return os;
          }*/
    };

   	class const_Iterador
    {
    	public:

        	const_Iterador();

        	const_Iterador(const typename Dicc<K,S>::Iterador& otro);

          const_Iterador(const typename Dicc<K, S>::const_Iterador& otro);

    	    const_Iterador& operator = (const typename Dicc<K, S>::const_Iterador& otro);

        	bool operator==(const typename Dicc<K,S>::const_Iterador&) const;

	        bool HaySiguiente() const;
    	    const K& SiguienteClave() const;
        	const S& SiguienteSignificado() const;
        	void Avanzar();
        
    	private:

       		nodo* siguiente;
      		nodo* anterior;
      		Lista<nodo*> recorrido; //asegurar que la lista funcione como una pila (insertar por adelante y sacar por adelante)
      		bool busca;

      		friend typename DiccLog<K,S>::const_Iterador DiccLog<K,S>::CrearIt() const;
          
         /* friend ostream& operator<<(ostream& os, const typename DiccLog<K,S>::Iterador& it){
          os<<"it";
          return os;
          }*/

    };

    struct nodo { 
      nodo* padre;
      nodo* izq;
      nodo* der;
      K clave;
      S significado; 

      nodo( K k, const S& s) : padre(NULL) , izq(NULL) , der(NULL), clave(k), significado(s){}
      friend ostream& operator<<(ostream& os, const DiccLog<K,S>::nodo& n) {
        return os << n.clave << ":" << n.significado;
      }

      };

    
    private:
		
    nodo* puntero;

	};	

template<class S>
ostream& operator << (ostream &os, const DiccLog<K,S>& d);

template<class K, class S>
bool operator == (const DiccLog<K,S>& d1, const DiccLog<K,S>& d2);

//aca van las funciones de dicclog

template<class S>
DiccLog<K,S>::DiccLog(){};

template<class S>
DiccLog<K,S>::DiccLog(const DiccLog<K,S>& otro){
  

}

template<class S>
DiccLog<K,S>::~DiccLog(){

}
