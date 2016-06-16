#ifndef MODULOS_DICCLOG_H_INCLUDED
#define MODULOS_DICCLOG_H_INCLUDED

#include "ModulosBasicos.h"
#include <iostream>
#include <string>
#include <ostream>
#include "pila.h"

using namespace aed2;
using namespace std;

namespace modulos{

template<class K ,class S>
class DiccLog{
	public:

	  struct nodoAB;

  	class ItLog;
		class const_ItLog;

		DiccLog();
		DiccLog(const DiccLog<K,S>& otro);
    ~DiccLog();
		DiccLog<K,S>& operator=(const DiccLog<K,S>& otro);

		ItLog Definir(const K& clave, const S& significado);

		bool EsVacio();
    bool Definido(const K& clave) const;
		const S& Obtener(const K& clave) const;
		void Borrar(const K& clave);
		const K Maximo();
		const K Minimo();
		
		ItLog CrearIt();
    const_ItLog CrearIt() const;
    
    ItLog Buscar(const K&);
    const_ItLog Buscar(const K&) const;

    class ItLog
    {
      public:

        ItLog();

        ItLog(const typename Dicc<K, S>::ItLog& otro);

        ItLog& operator = (const typename Dicc<K, S>::ItLog& otro);

        bool operator == (const typename Dicc<K,S>::ItLog&) const;

        bool HaySiguiente() const;
        const K& SiguienteClave() const;
        S& SiguienteSignificado();
        void Avanzar();
        void EliminarSiguiente();

        // FUNCIONES PRIVADAS, ¿QUE HACEMOS?
        void EliminarHoja();
        void EliminarRaiz();
        void EliminarConUnHijo();
        void AgregarComoSiguiente(K clave, S sig);      

      private:	
      		nodoAB* siguiente;
      		nodoAB* anterior;
      		Pila<nodoAB*> recorrido;
      		bool busca;

      		friend typename DiccLog<K,S>::ItLog DiccLog<K,S>::CrearIt();
       	 	friend class DiccLog<K,S>::const_ItLog;

        /*  friend ostream& operator<<(ostream& os, const typename DiccLog<K,S>::ItLog& it){
          os<<"it";
          return os;
          }*/
    };

   	class const_ItLog
    {
    	public:

        	const_ItLog();

        	const_ItLog(const typename Dicc<K,S>::ItLog& otro);

          const_ItLog(const typename Dicc<K, S>::const_ItLog& otro);

    	    const_ItLog& operator = (const typename Dicc<K, S>::const_ItLog& otro);

        	bool operator==(const typename Dicc<K,S>::const_ItLog&) const;

	        bool HaySiguiente() const;
    	    const K& SiguienteClave() const;
        	const S& SiguienteSignificado() const;
        	void Avanzar();
        
    	private:

       		nodoAB* siguiente;
      		nodoAB* anterior;
      		Pila<nodoAB*> recorrido; //asegurar que la lista funcione como una pila (insertar por adelante y sacar por adelante)
      		bool busca;

      		friend typename DiccLog<K,S>::const_ItLog DiccLog<K,S>::CrearIt() const;
          
         /* friend ostream& operator<<(ostream& os, const typename DiccLog<K,S>::ItLog& it){
          os<<"it";
          return os;
          }*/

    };

    struct nodoAB { 
      nodoAB* padre;
      nodoAB* izq;
      nodoAB* der;
      K clave;
      S significado; 

      nodoAB( K k, const S& s) : padre(NULL) , izq(NULL) , der(NULL), clave(k), significado(s){}
      friend ostream& operator<<(ostream& os, const DiccLog<K,S>::nodoAB& n) {
        return os << n.clave << ":" << n.significado;
      }

      };

    
    private:
		
    nodoAB* raiz;

	};	

template<class K, class S>
ostream& operator << (ostream &os, const DiccLog<K,S>& d);

template<class K, class S>
bool operator == (const DiccLog<K,S>& d1, const DiccLog<K,S>& d2);

// Funciones del ItLog

template<class K ,class S>
DiccLog<K,S>::ItLog::ItLog(): siguiente(NULL), anterior(NULL), busca(false){}

template<class K ,class S>
DiccLog<K,S>::ItLog::ItLog(const typename DiccLog<K,S>::ItLog& otro): siguiente(otro.siguiente), anterior(otro.anterior), recorrido(otro.recorrido), busca(otro.busca){}

template<class K ,class S>
typename DiccLog<K,S>::ItLog& DiccLog<K,S>::ItLog::operator = (const typename Dicc<K, S>::ItLog& otro){
  DiccLog<K,S>::ItLog 
}





//aca van las funciones de dicclog

template<class K ,class S>
DiccLog<K,S>::DiccLog(): raiz(NULL) {};

template<class K ,class S>
DiccLog<K,S>::DiccLog(const DiccLog<K,S>& otro){
  

}

template<class K ,class S>
DiccLog<K,S>::~DiccLog(){

}

/*
template<class K ,class S>
void DiccLog<K,S>::Definir(const K clave, const S sig) const{
  if (EsVacio()){
    nodoAB* p = new nodoAB(clave,sig);
    raiz = p;
  }else{
    Buscar(clave).AgregarComoSiguiente(clave, sig);
  }
}*/









};

#endif