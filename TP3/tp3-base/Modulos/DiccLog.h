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
	
  private:
    struct nodoAB { 
            nodoAB* padre;
            nodoAB* izq;
            nodoAB* der;
            K clave;
            S significado; 

            nodoAB(const K k, const S& s) : padre(NULL) , izq(NULL) , der(NULL), clave(k), significado(s){}
            friend ostream& operator<<(ostream& os, const DiccLog<K,S>::nodoAB& n) {
              return os << n.clave << ":" << n.significado;
            }
          };

  public:

  	class ItLog;
		class const_ItLog;

		DiccLog();
		DiccLog(const DiccLog<K,S>& otro);
    ~DiccLog();
		DiccLog<K,S>& operator=(const DiccLog<K,S>& otro);

		void Definir(const K& clave, const S& significado);

		bool EsVacio() const;
    bool Definido(const K& clave) const;
		S& Obtener(const K& clave);
		void Borrar(const K& clave);
		const K Maximo() const;
		const K Minimo() const;
		
		ItLog CrearIt();
    const_ItLog CrearIt() const;
    
    ItLog Buscar(const K&);
    const_ItLog Buscar(const K&) const;

    class ItLog
    {
  
      public:

        ItLog();

        ItLog(const typename DiccLog<K, S>::ItLog& otro);

        ItLog& operator = (const typename DiccLog<K, S>::ItLog& otro);

        bool operator == (const typename DiccLog<K,S>::ItLog& otro) const;

        bool HaySiguiente() const;
        const K& SiguienteClave() const;
        S& SiguienteSignificado() const;
        void Avanzar();
        void EliminarSiguiente();

        // FUNCIONES PRIVADAS, ¿QUE HACEMOS?
        void EliminarHoja();
        void EliminarRaiz();
        void EliminarConUnHijo();
        void AgregarComoSiguiente(K clave, S sig);

      private:
      
      	friend class DiccLog<K,S>;
        friend class DiccLog<K,S>::const_ItLog;

        	nodoAB* siguiente;
      		nodoAB* anterior;
      		Pila<nodoAB*> recorrido;
      		bool busca;
          DiccLog<K,S>* diccionario;


          ItLog(DiccLog<K,S>* d);

      		friend typename DiccLog<K,S>::ItLog DiccLog<K,S>::CrearIt();

          friend ostream& operator<<(ostream& os, const typename DiccLog<K,S>::ItLog& it){
            return os << (it->siguiente).clave << ":" << (it->siguiente).significado << endl;
          }
    };

   	class const_ItLog   // <------- ¿HAY QUE HACER ESTA MIERDA? NOOOO, justificar que nuestro iterador no modificable es igual al modificable sólo que con algunas funciones restringidas.
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
          const DiccLog<K,S>* diccionario;

          friend class DiccLog<K,S>;

          const_ItLog(const DiccLog<K,S>* d);

      		friend typename DiccLog<K,S>::const_ItLog DiccLog<K,S>::CrearIt() const;
          
         friend ostream& operator<<(ostream& os, const typename DiccLog<K,S>::const_ItLog& it){
            return os << (it->siguiente).clave << ":" << (it->siguiente).significado << endl;
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
DiccLog<K,S>::ItLog::ItLog(const typename DiccLog<K, S>::ItLog& otro): siguiente(otro.siguiente), anterior(otro.anterior), recorrido(otro.recorrido), busca(otro.busca), diccionario(otro.diccionario){}

template<class K ,class S>
DiccLog<K,S>::ItLog::ItLog(DiccLog<K,S>* d): siguiente(d->raiz), anterior(NULL), busca(false), diccionario(d){}


template<class K ,class S>
typename DiccLog<K,S>::ItLog& DiccLog<K,S>::ItLog::operator = (const typename DiccLog<K, S>::ItLog& otro){
  siguiente = otro.siguiente;
  anterior = otro.anterior;
  recorrido = otro.recorrido;
  busca = otro.busca;
  return *this;
}

template<class K ,class S>
bool DiccLog<K,S>::ItLog::operator == (const typename DiccLog<K, S>::ItLog& otro) const{
  return (siguiente==otro.siguiente && anterior==otro.anterior && recorrido==otro.recorrido && busca==otro.busca);
}

template<class K ,class S>
bool DiccLog<K,S>::ItLog::HaySiguiente() const{
  return siguiente != NULL;
}

template<class K ,class S>
const K& DiccLog<K,S>::ItLog::SiguienteClave() const{
  return siguiente->clave;
}


template<class K ,class S>
S& DiccLog<K,S>::ItLog::SiguienteSignificado() const{
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
  n->padre = anterior;
  if(anterior->clave > clave){
    anterior->izq = n;
  }else{
    anterior->der = n;
  }
  this->siguiente = n;
}


template<class K ,class S>
void DiccLog<K,S>::ItLog::EliminarSiguiente(){
  if(siguiente->clave != diccionario->raiz->clave && siguiente->der == NULL && siguiente->izq == NULL){
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
        nodoAB* antrec = rec->padre;
        typename DiccLog<K,S>::ItLog it = diccionario->Buscar(rec->clave);
        temp->clave = rec->clave;
        temp->significado = rec->significado;
        if(rec->der == NULL){
          it.EliminarHoja();
          /*rec->padre->izq = NULL;
          delete rec;*/
        }else{
          it.EliminarConUnHijo();
          /*nodoAB* temp2 = siguiente;
          antrec->izq = temp2->der;
          temp2 = antrec->der;
          delete rec;
          rec=temp2;*/
        }
      } 
    }else{
      EliminarRaiz();
    }
  }
}



template<class K ,class S>
void DiccLog<K,S>::ItLog::EliminarHoja(){
  if(siguiente->padre->izq->clave == siguiente->clave){
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
  }else{
    siguiente = NULL;
  }
}




template<class K ,class S>
void DiccLog<K,S>::ItLog::EliminarRaiz(){                               // Le agregamos el caso en que la raiz no tiene hijos y cuando su
  if(siguiente->der != NULL && siguiente->izq != NULL){                 // hijo derecho tiene ambos hijos (no los contemplamos en el diseño)
    nodoAB* temp = siguiente;
    nodoAB* rec = temp->der;
    while(rec->izq != NULL){
      rec = rec->izq;
    }
    nodoAB* antrec = rec->padre;
    typename DiccLog<K,S>::ItLog it = diccionario->Buscar(rec->clave);
    temp->clave = rec->clave;
    temp->significado = rec->significado;
    if(rec->der == NULL){
     it.EliminarHoja();
      /*rec->padre->izq = NULL;
      delete rec;
      rec = NULL;*/
    }else{
     it.EliminarConUnHijo();
      /*nodoAB* temp2 = siguiente;
      antrec->izq = temp2->der;
      temp2 = antrec->der;
      delete rec;
      rec=temp2;*/
    }
  }else{
    if(siguiente->der != NULL){
      nodoAB* temp = siguiente->der;
      delete siguiente;
      siguiente = temp;
      diccionario->raiz = temp;
      siguiente->padre = NULL;
    }else{
      if(siguiente->izq!=NULL){
        nodoAB* temp = siguiente->izq;
        delete siguiente;
        siguiente = temp;
        diccionario->raiz = temp;
        siguiente->padre = NULL;
      }else{
        delete siguiente;
        siguiente = NULL;
        diccionario->raiz = NULL;
      }
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
      temp = anterior->der;
    }else{
      anterior->izq = temp->izq;
      temp = anterior->izq;
    }
  }else{
    (temp->der)->padre = anterior;
    if(anterior->der == siguiente){
      anterior->der = temp->der;
      temp = anterior->der;
    }else{
      anterior->izq = temp->der;
      temp = anterior->der;
    }
  }
  delete siguiente;
  siguiente=temp;
}



// Funciones del const_ItLog

template<class K ,class S>
DiccLog<K,S>::const_ItLog::const_ItLog(): siguiente(NULL), anterior(NULL), busca(false){}

template<class K ,class S>
DiccLog<K,S>::const_ItLog::const_ItLog(const typename DiccLog<K, S>::const_ItLog& otro): siguiente(otro.siguiente), anterior(otro.anterior), recorrido(otro.recorrido), busca(otro.busca), diccionario(otro.diccionario){}

template<class K ,class S>
DiccLog<K,S>::const_ItLog::const_ItLog(const DiccLog<K,S>* d): siguiente(d->raiz), anterior(NULL), busca(false), diccionario(d){}


template<class K ,class S>
typename DiccLog<K,S>::const_ItLog& DiccLog<K,S>::const_ItLog::operator = (const typename DiccLog<K, S>::const_ItLog& otro){
  siguiente = otro.siguiente;
  anterior = otro.anterior;
  recorrido = otro.recorrido;
  busca = otro.busca;
  return *this;
}

template<class K ,class S>
bool DiccLog<K,S>::const_ItLog::operator == (const typename DiccLog<K, S>::const_ItLog& otro) const{
  return (siguiente==otro.siguiente && anterior==otro.anterior && recorrido==otro.recorrido && busca==otro.busca);
}

template<class K ,class S>
bool DiccLog<K,S>::const_ItLog::HaySiguiente() const{
  return siguiente != NULL;
}

template<class K ,class S>
const K& DiccLog<K,S>::const_ItLog::SiguienteClave() const{
  return siguiente->clave;
}


template<class K ,class S>
const S& DiccLog<K,S>::const_ItLog::SiguienteSignificado() const{
  return siguiente->significado;
}

template<class K ,class S>
void DiccLog<K,S>::const_ItLog::Avanzar(){
  if(busca){
    typename DiccLog<K,S>::const_ItLog it(*this);
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
  if (EsVacio()){
    nodoAB* p = new nodoAB(clave,sig);
    raiz = p;
  }else{
    Buscar(clave).AgregarComoSiguiente(clave, sig);
  }

}

template<class K ,class S>
typename DiccLog<K,S>::ItLog DiccLog<K,S>::CrearIt(){
  //typename DiccLog<K,S>::ItLog res = ItLog(this);
  return ItLog(this);
}

template<class K ,class S>
typename DiccLog<K,S>::const_ItLog DiccLog<K,S>::CrearIt() const{
  //typename DiccLog<K,S>::const_ItLog res = ItLog(this);
  return const_ItLog(this);
}


template<class K ,class S>
typename DiccLog<K,S>::ItLog DiccLog<K,S>::Buscar(const K& c){
  typename DiccLog<K,S>::ItLog res = CrearIt();
  res.busca = true;
  while(res.HaySiguiente() && res.SiguienteClave() != c){
    if(c < res.siguiente->clave){
      res.anterior = res.siguiente;
      res.siguiente = res.siguiente->izq;
    }else{
      res.anterior = res.siguiente;
      res.siguiente = res.siguiente->der;
    }
  }
  return res;
}


template<class K ,class S>
typename DiccLog<K,S>::const_ItLog DiccLog<K,S>::Buscar(const K& c) const{
  typename DiccLog<K,S>::const_ItLog res = CrearIt();
  res.busca = true;
  while(res.HaySiguiente() && res.SiguienteClave() != c){
    if(c < (res.siguiente)->clave){
      res.anterior = res.siguiente;
      (res.siguiente) = (res.siguiente)->izq;
    }else{
      res.anterior = res.siguiente;
      (res.siguiente) = (res.siguiente)->der;
    }
  }
  return res;
}


template<class K ,class S>
DiccLog<K,S>& DiccLog<K,S>::operator=(const DiccLog<K,S>& otro){
  typename DiccLog<K,S>::ItLog it = CrearIt();
  while(it.HaySiguiente())
  {
    it.nodoStrSiguiente();
  }
  it = otro.CrearIt();
  while(it.HaySiguiente()){
    Definir(it.SiguienteClave(),it.SiguienteSignificado());
    it.Avanzar();
  }

return *this;
}

template<class K ,class S>
bool DiccLog<K,S>::EsVacio() const{
  return raiz==NULL;
}


template<class K ,class S>
bool DiccLog<K,S>::Definido(const K& clave) const{
  return Buscar(clave).HaySiguiente();
}

template<class K ,class S>
S& DiccLog<K,S>::Obtener(const K& clave){
  return Buscar(clave).SiguienteSignificado();
}

template<class K ,class S>
void DiccLog<K,S>::Borrar(const K& clave){
  //assert(Definido(clave));
  Buscar(clave).EliminarSiguiente();
}


template<class K ,class S>
const K DiccLog<K,S>::Maximo() const{
  nodoAB* p = raiz;
  while(p->der!=NULL){
    p = p->der;
  }
  return p->clave;
}


template<class K ,class S>
const K DiccLog<K,S>::Minimo() const{
  nodoAB* p = raiz;
  while(p->izq!=NULL){
    p = p->izq;
  }
  return p->clave;
}


};

#endif