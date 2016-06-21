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
        ItStr(nodoStr* s, nodoStr* a, String c, bool b);

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
          const_ItStr(nodoStr* s, nodoStr* a, String c, bool b);

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

      nodoStr(S* s) : padre(NULL), significado(s){}
      /*friend ostream& operator<<(ostream& os, const DiccString<S>::nodoStr& n) {
        return os << n.clave << ":" << n.significado;
      }*/

      };

    struct data { 
      nodoStr* sig;
      String clav;

      data(const S& s, const String& c) : clav(c), sig(s){}
      /*friend ostream& operator<<(ostream& os, const DiccString<S>::nodoStr& n) {
        return os << n.clave << ":" << n.significado;
      }*/

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
DiccString<S>::ItStr::ItStr(nodoStr* s, nodoStr* a, String c, bool b): siguiente(s), anterior(a), busca(b), clave(c){}

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

template<class S>
void DiccString<S>::ItStr::EliminarSiguiente(){
  siguiente->significado = NULL;
  while(ApuntaAHoja() && siguiente->significado == NULL && anterior != NULL){
    int j = *(clave.end());
    delete siguiente;
    anterior[j] = NULL;
    siguiente = anterior;
    anterior = anterior->padre;
  }
  if(recorrido.EsVacia()){
    anterior = siguiente;
    siguiente = NULL;
  }else{
    siguiente = recorrido.Tope().sig;
    clave = recorrido.Tope().clav;
    anterior = siguiente->padre;
    recorrido.Desapilar();
  }
}

template<class S>
bool DiccString<S>::ItStr::ApuntaAHoja(){
  bool res = true;
  int i = 0;
  while(res && i<256){
    res = res || (siguiente->caracteres)[i]==NULL;
  }
  return res;
}

template<class S>
void DiccString<S>::ItStr::AgregarComoSiguiente(String c, S s){
  S* p = &s;
  if (anterior==NULL){
    nodoStr n(p);
    for (int i=0;i<256;i++){
      n.caracteres[i] = NULL;
    }
  }else{
    cerr << (anterior==NULL) << endl;
    if(c == clave && siguiente!=NULL){
      cerr << "Salio por THEN" << endl;
      siguiente->significado = p;
    }else{
      cerr << "Salio por ELSE" << endl;
      int j = clave.length();
      nodoStr n(NULL);
      for (int i=0;i<256;i++){
        n.caracteres[i] = NULL;
      }
      n.padre = anterior;
      int i=c[j];
      (anterior->caracteres)[i] = &n;
      siguiente = &n;
      j++;
      while(j < c.length()){
        nodoStr n(NULL);
        for (int i=0;i<256;i++){
          n.caracteres[i] = NULL;
        }
        n.padre = anterior;
        int i=c[j];
        (anterior->caracteres)[i] = &n;
        anterior = siguiente;
        siguiente = &n;
      j++;
      }
      clave = c;
      siguiente->significado = p;
    }
  }
}


//  ------------>> FUNCIONES DEL DICCSTRING <<---------------


template<class S>
DiccString<S>::DiccString():raiz(NULL){}

template<class S>
DiccString<S>::DiccString(const DiccString<S>& otro){
  typename DiccString<S>::ItStr it (otro);
  while(HaySiguiente(it)){
     Definir(it.SiguienteClave(),it.SiguienteSignificado());
    it.Avanzar();
  }
}

template<class S>
DiccString<S>::~DiccString(){
  typename DiccString<S>::ItStr it = CrearIt();
  while(it.HaySiguiente()){
    it.EliminarSiguiente();
  }
}

template<class S>
DiccString<S>& DiccString<S>::operator=(const DiccString<S>& otro){
  typename DiccString<S>::ItStr res = new ItStr(otro);
  return *res;
}

template<class S>
typename DiccString<S>::ItStr DiccString<S>::CrearIt(){
  typename DiccString<S>::ItStr res(raiz,NULL,"",false);
  return res;
}

template<class S>
typename DiccString<S>::ItStr DiccString<S>::Buscar(const String& s){
  nodoStr* rec = raiz;
  nodoStr* padre = NULL;
  String clave = "";
  int j = 0;
  int n = s.length();
  while (clave!=s && rec!=NULL){
    int i = s[j];
    padre = rec;
    rec = (rec->caracteres)[i];
    clave.append(&s[j]);
    j++;
  }
  typename DiccString<S>::ItStr res(rec,padre,clave,true);
  cerr << "El Buscar funca  " << (rec==NULL) << endl;
  return res;
}

template<class S>
void DiccString<S>::Definir(const String& clave, const S& significado){
  Buscar(clave).AgregarComoSiguiente(clave,significado);
}

template<class S>
bool DiccString<S>::EsVacio(){
  return raiz==NULL;
}

template<class S>
bool DiccString<S>::Definido(const String& clave) const{
  return Buscar(clave).HaySiguiente();
}

template<class S>
const S& DiccString<S>::Obtener(const String& clave) const{
  return Buscar(clave).SiguienteSignificado();
}

template<class S>
void DiccString<S>::Borrar(const String& clave){
  Buscar(clave).EliminarSiguiente();
}

template<class S>
const String DiccString<S>::Minimo(){
  DiccString<S>::ItStr i = CrearIt();
  while(!i.ApuntaAHoja()){
    i.Avanzar();
  }
  String res = i.clave;
  return res;
}

template<class S>
const String DiccString<S>::Maximo(){
  nodoStr* a = raiz;
  String res = "";
  while(a != NULL){
    int j = 255;
    while(j > 0 && (a->caracteres)[j] == NULL){
      j--;
    }
    char i = j;
    res.append(&i);
    a = (a->caracteres)[j];
  }
  return res;
}


};	


  #endif