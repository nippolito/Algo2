#ifndef MODULOS_DICCLOG_H_INCLUDED
#define MODULOS_DICCLOG_H_INCLUDED

#include "ModulosBasicos.h"
#include <iostream>
#include <string>
#include <ostream>
#include "pila.h"
#include <cassert>

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

		void Definir(const K& clave, const S& significado);

		bool EsVacio();
    bool Definido(const K& clave);   //le sacamos el CONST
		S& Obtener(const K& clave);
		void Borrar(const K& clave);
		const K Maximo();
		const K Minimo();
		
		ItLog CrearIt() const;
  //  const_ItLog CrearIt() const;
    
    ItLog Buscar(const K&);
   // const_ItLog Buscar(const K&) const;

    class ItLog
    {
      public:

        ItLog();

        ItLog(const typename DiccLog<K, S>::ItLog& otro);

        ItLog(nodoAB* sig, nodoAB* ant, bool b);

        ItLog& operator = (const typename DiccLog<K, S>::ItLog& otro);

        bool operator == (const typename DiccLog<K,S>::ItLog& otro) const;

        bool HaySiguiente();    //le sacamos el CONST
        const K& SiguienteClave() const;
        S& SiguienteSignificado();
        void Avanzar();
        void EliminarSiguiente();

        // FUNCIONES PRIVADAS, ¿QUE HACEMOS?
        DiccLog<K,S> Arbol();  // <-- Hubo que agregarla porque flasheamos con la estructura
        void EliminarHoja();
        void EliminarRaiz();
        void EliminarConUnHijo();
        void AgregarComoSiguiente(K clave, S sig);

      private:	
      		nodoAB* siguiente;
      		nodoAB* anterior;
      		Pila<nodoAB*> recorrido;
      		bool busca;

          ItLog(DiccLog<K,S>* d);

      		friend typename DiccLog<K,S>::ItLog DiccLog<K,S>::CrearIt() const;
       	 	//friend class DiccLog<K,S>::const_ItLog;

          friend ostream& operator<<(ostream& os, const typename DiccLog<K,S>::ItLog& it){
            return os << (it->siguiente).clave << ":" << (it->siguiente).significado << endl;
          }
    };

  /* 	class const_ItLog   // <------- ¿HAY QUE HACER ESTA MIERDA? NOOOO, justificar que nuestro iterador no modificable es igual al modificable sólo que con algunas funciones restringidas.
    {
    	public:

        	const_ItLog();

        	const_ItLog(const typename DiccLog<K,S>::ItLog& otro);

          const_ItLog(const typename DiccLog<K, S>::const_ItLog& otro);

    	    const_ItLog& operator = (const typename DiccLog<K, S>::const_ItLog& otro);

        	bool operator==(const typename DiccLog<K,S>::const_ItLog& otro) const;

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
          
          friend ostream& operator<<(ostream& os, const typename DiccLog<K,S>::ItLog& it){
          os<<"it";
          return os;
          }

    }; */

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
ostream& operator << (ostream &os, const DiccLog<K, S>& d);

template<class K, class S>
bool operator == (const DiccLog<K,S>& d1, const DiccLog<K,S>& d2);

// Funciones del ItLog

template<class K ,class S>
DiccLog<K,S>::ItLog::ItLog(): siguiente(NULL), anterior(NULL), busca(false){}

template<class K ,class S>
DiccLog<K,S>::ItLog::ItLog(const typename DiccLog<K, S>::ItLog& otro): siguiente(otro.siguiente), anterior(otro.anterior), recorrido(otro.recorrido), busca(otro.busca){}

template<class K ,class S>
DiccLog<K,S>::ItLog::ItLog(nodoAB* sig, nodoAB* ant, bool b): siguiente(sig) , anterior(ant), busca(b) {}


template<class K ,class S>
typename DiccLog<K,S>::ItLog& DiccLog<K,S>::ItLog::operator = (const typename DiccLog<K, S>::ItLog& otro){
  typename DiccLog<K,S>::ItLog* res = new ItLog(otro);
  //nodoAB* n = new nodoAB(clave,sig);
  return *res;
}

template<class K ,class S>
bool DiccLog<K,S>::ItLog::operator == (const typename DiccLog<K, S>::ItLog& otro) const{
  return (siguiente==otro.siguiente && anterior==otro.anterior && recorrido==otro.recorrido && busca==otro.busca);
}

template<class K ,class S>
bool DiccLog<K,S>::ItLog::HaySiguiente(){
  return siguiente != NULL;
}

template<class K ,class S>
const K& DiccLog<K,S>::ItLog::SiguienteClave() const{
  return siguiente->clave;
}


template<class K ,class S>
S& DiccLog<K,S>::ItLog::SiguienteSignificado(){
  return siguiente->significado;
}

template<class K ,class S>
void DiccLog<K,S>::ItLog::Avanzar(){
  if(busca){
    typename DiccLog<K,S>::ItLog it(*this);
    while(it.anterior != NULL){
      it.siguiente = it.anterior;
      it.anterior = it.anterior->padre;
    }
    while(it.siguiente->clave != siguiente->clave){
      if(it.siguiente->der != NULL){
        it.recorrido.Apilar(it.siguiente->der);
      }
      if(it.siguiente->izq != NULL){
        it.recorrido.Apilar(it.siguiente->izq);
      }
      it.siguiente = it.recorrido.Tope();
      it.anterior = it.siguiente->padre;
      it.recorrido.Desapilar();
    }
    *this = it;
    busca = false;
  }
  if(siguiente->der != NULL){
    recorrido.Apilar(siguiente->der);
  }
  if(siguiente->izq != NULL){
    recorrido.Apilar(siguiente->izq);
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


template<class K ,class S>
void DiccLog<K,S>::ItLog::AgregarComoSiguiente(K clave, S sig){
  nodoAB* n = new nodoAB(clave,sig);
  cerr << "crea el nodo" << endl;
  n->padre = anterior;
  cerr << anterior << endl;
  cerr << "casi entra al if" << endl;
  if(anterior->clave > clave){
    anterior->der = n;
  }else{
    anterior->izq = n;
  }
  siguiente = n;
}


template<class K ,class S>
void DiccLog<K,S>::ItLog::EliminarSiguiente(){
  if(siguiente->der != NULL && siguiente->izq != NULL){
    EliminarHoja();
  }else{
    if(anterior != NULL){
      if((siguiente->der == NULL && siguiente->izq != NULL) || (siguiente->der != NULL && siguiente->izq == NULL)){
        EliminarConUnHijo();
      }else{
        nodoAB* temp = siguiente;
        nodoAB* rec = temp->der;
        while(rec->izq != NULL){
          rec = rec->izq;
        }
        temp->clave = rec->clave;
        temp->significado = rec->significado;
        DiccLog<K,S> odin = Arbol();
        if(rec->der == NULL){
          odin.Buscar(rec->clave).EliminarHoja();
        }else{
          odin.Buscar(rec->clave).EliminarConUnHijo();
        }
        temp = NULL;
      } 
    }else{
      EliminarRaiz();
    }
  }
}



template<class K ,class S>
void DiccLog<K,S>::ItLog::EliminarHoja(){
  if(siguiente->padre->izq = siguiente){
    siguiente->padre->izq = NULL;
    delete siguiente;
  }else{
    siguiente->padre->der = NULL;
    delete siguiente;
  }
  if(!recorrido.EsVacia()){
    siguiente = recorrido.Tope();
    anterior = siguiente->padre;
    recorrido.Desapilar();
  }
}




template<class K ,class S>
void DiccLog<K,S>::ItLog::EliminarRaiz(){
  if(siguiente->der != NULL && siguiente->izq != NULL){
    (siguiente->izq)->padre = siguiente->der;
    (siguiente->der)->izq = siguiente->izq;
    delete siguiente;
    siguiente = siguiente->der;
  }else{
    if(siguiente->der != NULL){
      delete siguiente;
      siguiente = siguiente->der;
    }else{
      delete siguiente;
      siguiente = siguiente->izq;
    }
  }
}


template<class K ,class S>
void DiccLog<K,S>::ItLog::EliminarConUnHijo(){
  nodoAB* temp = siguiente;
  if(siguiente->der == NULL){
    (temp->izq)->padre = anterior;
    if(anterior->der == siguiente){
      anterior->der = temp->izq;
    }else{
      anterior->izq = temp->izq;
    }
    delete siguiente;
    siguiente = temp->izq;
  }else{
    (temp->der)->padre = anterior;
    if(anterior->der == siguiente){
      anterior->der = temp->der;
    }else{
      anterior->izq = temp->der;
    }
    delete siguiente;
    siguiente = temp->der;
  }
}


template<class K ,class S>
DiccLog<K,S> DiccLog<K,S>::ItLog::Arbol(){
  nodoAB* p;
  if(siguiente == NULL){
    p = anterior;
  }else{
    p = siguiente;
  }
  while (p->padre!=NULL){
    p = p->padre;
  }
  DiccLog<K,S> res;
  res.raiz = p;
  return res;
}


// ------------>>  Aca van las funciones de Dicclog  <<-----------------


template<class K ,class S>
DiccLog<K,S>::DiccLog(): raiz(NULL){}

template<class K ,class S>
DiccLog<K,S>::DiccLog(const DiccLog<K,S>& otro){
  typename DiccLog<K,S>::ItLog it = otro.CrearIt();
  while(it.HaySiguiente()){
    Definir(it.SiguienteClave(),it.SiguienteSignificado());
    it.Avanzar();
  }
}

template<class K ,class S>
DiccLog<K,S>::~DiccLog(){
  typename DiccLog<K,S>::ItLog it = CrearIt();
  while(it.HaySiguiente()){
    it.EliminarSiguiente();
  }
}


template<class K ,class S>
void DiccLog<K,S>::Definir(const K& clave, const S& sig){
  cerr << "asd" << endl;
  if (EsVacio()){
    cerr << "primero" << endl;
    nodoAB* p = new nodoAB(clave,sig);
    raiz = p;
  }else{
    Buscar(clave).AgregarComoSiguiente(clave, sig);
    cerr << "segundo" << endl;
  }
  cerr << "si" << endl;
}

template<class K ,class S>
typename DiccLog<K,S>::ItLog DiccLog<K,S>::CrearIt() const{
  typename DiccLog<K,S>::ItLog res = ItLog(raiz, NULL, false);
  return res;
}


template<class K ,class S>
typename DiccLog<K,S>::ItLog DiccLog<K,S>::Buscar(const K& c){
  nodoAB* p = raiz;
  cerr << "entro al buscar" << endl;
  while(p->clave != c && !(p->izq == NULL && p->der == NULL)){
    cerr << "se metio al ciclo" << endl;
    if(c < p->clave){
      cerr << "te rompiste?1" << endl;
      p = p->izq;
    }else{
      cerr << "te rompiste?2" << endl;
      p = p->der;
    }
  }
  cerr << "salio del ciclo" << endl;
  bool b = true;
  if (EsVacio())
  {
    typename DiccLog<K,S>::ItLog res = ItLog(NULL, p, b);  //Recordar que acá está el segmentation fault, la primera vez el anterior tiene que ser NULL pero a partir de la segunda el anterior tiene que ser el verdadero anterior
  }else{
    typename DiccLog<K,S>::ItLog res = ItLog(p->padre, p, b);
  }
  cerr << "casi termina" << endl;  //ES UN FORRO
  return res;
}

template<class K ,class S>
DiccLog<K,S>& DiccLog<K,S>::operator=(const DiccLog<K,S>& otro){
  typename DiccLog<K,S>::DiccLog<K,S> res(otro);
  return res;
}



template<class K ,class S>
bool DiccLog<K,S>::EsVacio(){
  return raiz==NULL;
}


template<class K ,class S>
bool DiccLog<K,S>::Definido(const K& clave){
  return Buscar(clave).HaySiguiente();
}

template<class K ,class S>
S& DiccLog<K,S>::Obtener(const K& clave){
  return Buscar(clave).SiguienteSignificado();
}

template<class K ,class S>
void DiccLog<K,S>::Borrar(const K& clave){
  assert(Definido(clave));
  Buscar(clave).EliminarSiguiente();
}


template<class K ,class S>
const K DiccLog<K,S>::Maximo(){
  nodoAB* p = raiz;
  while(p->der!=NULL){
    p = p->der;
  }
  return p->clave;
}


template<class K ,class S>
const K DiccLog<K,S>::Minimo(){
  nodoAB* p = raiz;
  while(p->izq!=NULL){
    p = p->izq;
  }
  return p->clave;
}


};

#endif