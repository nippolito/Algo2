#ifndef MODULOS_DICCSTRING_H_INCLUDED
#define MODULOS_DICCSTRING_H_INCLUDED

#include "ModulosBasicos.h"
#include <iostream>
#include <string>
#include <ostream>
#include "pila.h"

using namespace aed2;
using namespace std;

namespace modulos{

template<class S>
class DiccString{
	public:

	  struct nodoStr;
    struct data;

  	class ItStr;
		class const_ItStr;

		DiccString();
		DiccString(const DiccString<S>& otro);
    ~DiccString();
		DiccString<S>& operator=(const DiccString<S>& otro);

		void Definir(const String& clave, const S& significado);

		bool EsVacio();
    bool Definido(const String& clave) const;
		const S& Obtener(const String& clave) const;
		void Borrar(const String& clave);
		const String Maximo();
		const String Minimo();
		
		ItStr CrearIt();
    const_ItStr CrearIt() const;
    
    ItStr Buscar(const String&);
    const_ItStr Buscar(const String&) const;

    class ItStr
    {
      public:

        ItStr();

        ItStr(const typename DiccString<S>::ItStr& otro);

        ItStr& operator = (const typename DiccString<S>::ItStr& otro);

        bool operator == (const typename DiccString<S>::ItStr& otro) const;

        bool HaySiguiente() const;
        const String& SiguienteClave() const;
        S& SiguienteSignificado();
        void Avanzar();
        void EliminarSiguiente();

        // FUNCIONES PRIVADAS, ¿QUE HACEMOS?
        bool ApuntaAHoja();
        void AgregarComoSiguiente(String clave, S sig);

      private:	
      		nodoStr* siguiente;
      		nodoStr* anterior;
      		Pila<data> recorrido;
          String clave;
      		bool busca;

      		friend typename DiccString<S>::ItStr DiccString<S>::CrearIt();
       	 	friend class DiccString<S>::const_ItStr;

        /*  friend ostream& operator<<(ostream& os, const typename DiccString<S>::ItStr& it){
          os<<"it";
          return os;
          }*/
    };

   	class const_ItStr   // <------- ¿HAY QUE HACER ESTA MIERDA?
    {
    	public:

        	const_ItStr();

        	const_ItStr(const typename DiccString<S>::ItStr& otro);

          const_ItStr(const typename DiccString<S>::const_ItStr& otro);

    	    const_ItStr& operator = (const typename DiccString<S>::const_ItStr& otro);

        	bool operator==(const typename DiccString<S>::const_ItStr& otro) const;

	        bool HaySiguiente() const;
    	    const String& SiguienteClave() const;
        	const S& SiguienteSignificado() const;
        	void Avanzar();
        
    	private:

       		nodoStr* siguiente;
      		nodoStr* anterior;
      		Pila<data> recorrido; //asegurar que la lista funcione como una pila (insertar por adelante y sacar por adelante)
          String clave;
      		bool busca;

      		friend typename DiccString<S>::const_ItStr DiccString<S>::CrearIt() const;
          
         /* friend ostream& operator<<(ostream& os, const typename DiccString<S>::ItStr& it){
          os<<"it";
          return os;
          }*/

    };

    struct nodoStr { 
      nodoStr* padre;
      nodoStr* caracteres[256];     // ¿Asi se inicializan arreglos?
      S* significado; 

      nodoStr(const S& s) : padre(NULL), significado(s){}
      friend ostream& operator<<(ostream& os, const DiccString<S>::nodoStr& n) {
        return os << n.clave << ":" << n.significado;
      }

      };

    struct data { 
      nodoStr* sig;
      String clav;

      data(const S& s, const String& c) : clav(c), sig(s){}
      friend ostream& operator<<(ostream& os, const DiccString<S>::nodoStr& n) {
        return os << n.clave << ":" << n.significado;
      }

      };

    
    private:
		
    nodoStr* raiz;

	};


//  ------------>> FUNCIONES DEL ITSTR <<---------------

template<class S>
DiccString<S>::ItStr::ItStr(): siguiente(NULL), anterior(NULL), clave (""),busca(false){}

template<class S>
DiccString<S>::ItStr::ItStr(const typename DiccString<S>::ItStr& otro): siguiente(otro.siguiente), anterior(otro.anterior), clave(otro.clave), busca(otro.busca), recorrido(otro.recorrido) {}

template<class S>
typename DiccString<S>::ItStr& DiccString<S>::ItStr::operator = (const typename DiccString<S>::ItStr& otro){
  DiccString<S>::ItStr res(otro);
  return res;
}
/*
template<class S>
bool operator == (const typename DiccString<S>::ItStr& otro) const;
*/
template<class S>
bool DiccString<S>::ItStr::HaySiguiente() const{
  return siguiente !=NULL;
}

template<class S>
const String& DiccString<S>::ItStr::SiguienteClave() const{
  return clave;
}

template<class S>
S& DiccString<S>::ItStr::SiguienteSignificado(){
  return *(siguiente->significado);
}

template<class S>
void DiccString<S>::ItStr::Avanzar(){
  if(busca){
    typename DiccString<S>::ItStr it(*this);
    while(it.anterior != NULL){
      it.siguiente = it.anterior;
      it.anterior = it.anterior->padre;
    }
    while(it.clave != clave){
      int j = 255;
      while(j >= 0){
        if(siguiente->caracteres[j] != NULL){
          String nuevaclave = clave;
          data d;
          d.sig = siguiente->caracteres[j];
          char cj = j;
          nuevaclave.append(&cj); //OJO con el &, no sabemos si funca!
          d.clav = nuevaclave;
          recorrido.Apilar(d);
        }
        j--;
      }
      it.siguiente = it.recorrido.Tope().sig;
      it.clave = it.recorrido.Tope().clave;
      it.anterior = it.siguiente->padre;
      it.recorrido.Desapilar();
    }
    *this = it;
    busca = false;
  }
  int j = 255;
  while(j >= 0){
    if(siguiente->caracteres[j] != NULL){
      String nuevaclave = clave;
      data d;
      d.sig = siguiente->caracteres[j];
      char cj = j;
      nuevaclave.append(&cj);
      d.clav = nuevaclave;
      recorrido.Apilar(d);  
    }
    j--;
  }
  if(recorrido.EsVacia()){
    anterior = siguiente;
    siguiente = NULL;
  }else{
    while(recorrido.Tope().sig->significado == NULL && !recorrido.EsVacia()){
      int j = 255;
      nodoStr* guardanodo = recorrido.Tope().sig;
      String guardaclave = recorrido.Tope().clav;
      recorrido.Desapilar();
      while(j >= 0){
        if(guardanodo->caracteres[j] != NULL){
          String nuevaclave = guardaclave;
          data d;
          d.sig = guardanodo->caracteres[j];
          char cj = j;
          nuevaclave.append(&cj); //OJO con el &, no sabemos si funca!
          d.clav = nuevaclave;
          recorrido.Apilar(d);
        }
        j--;
      }
    }
    if(recorrido.EsVacia()){
      anterior = siguiente;
      siguiente = NULL;
    }else{
      siguiente = recorrido.Tope();
      anterior = siguiente->padre;
      recorrido.Desapilar();
    }
  }
}
/*
template<class S>
void EliminarSiguiente();
*/

//  ------------>> FUNCIONES DEL DICCSTRING <<---------------

/*
template<class S>
DiccString<S>::DiccString():raiz(NULL){}

template<class S>
DiccString<S>::DiccString(const DiccString<S>& otro){}

template<class S>
DiccString<S>::~DiccString(){}

template<class S>
DiccString<S>& operator=(const DiccString<S>& otro){}
*/


};	


  #endif