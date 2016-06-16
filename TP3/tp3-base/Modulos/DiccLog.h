#ifndef MODULOS_DICCLOG_H_INCLUDED
#define MODULOS_DICCLOG_H_INCLUDED

#include "ModulosBasicos.h"
#include <iostream>
#include <string>
#include <ostream>

using namespace aed2;
using namespace std;

namespace modulos{

template<class K ,class S>
class DiccLog{
	public:
		
	 struct nodoAB;

  	class Iterador;
		class const_Iterador;

		DiccLog();
		DiccLog(const DiccLog<K,S>& otro);
		DiccLog<K,S>& operator=(const DiccLog<K,S>& otro);

		Iterador Definir(const K& clave, const S& significado);

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

        Iterador(const typename Dicc<K,S>::Iterador& otro);

        Iterador& operator = (const typename Dicc<K,S>::Iterador& otro);

        bool operator == (const typename Dicc<K,S>::Iterador&) const;

        bool HaySiguiente() const;
        const K& SiguienteClave() const;
        S& SiguienteSignificado();
        void Avanzar();
        void EliminarSiguiente();
       

      private:	
      		nodoAB* siguiente;
      		nodoAB* anterior;
      		Lista<nodoAB*> recorrido;
      		bool busca;

      		friend typename DiccLog<K,S>::Iterador DiccLog<K,S>::CrearIt();
       	 	friend class DiccLog<K,S>::const_Iterador;

       
    };

   	class const_Iterador
    {
    	public:

        	const_Iterador();

        	const_Iterador(const typename Dicc<K,S>::Iterador& otro);

	        const_Iterador(const typename Dicc<K,S>::const_Iterador& otro);

    	    const_Iterador& operator = (const typename Dicc<K,S>::const_Iterador& otro);

        	bool operator==(const typename Dicc<K,S>::const_Iterador&) const;

	        bool HaySiguiente() const;
    	    const K& SiguienteClave() const;
        	const S& SiguienteSignificado() const;
        	void Avanzar();
        
    	private:

       		nodoAB* siguiente;
      		nodoAB* anterior;
      		Lista<nodoAB*> recorrido;
      		bool busca;

      		friend typename DiccLog<K,S>::const_Iterador DiccLog<K,S>::CrearIt() const;
   

    };


    
    private:
/*
   		struct nodoAB {
   		 
      	nodoAB* padre;
   			nodoAB* izq;
   			nodoAB* der;
   			K clave;
   			S significado; 
        nodoAB( K k, const S& s) : clave(k), significado(s){}
        friend ostream& operator<<(ostream& os, const DiccLog<K,S>::nodoAB& n) {
          return os << n.clave << ":" << n.significado;
        }

   		};
		
*/
	};	

  //ACA van las funciones


};

#endif