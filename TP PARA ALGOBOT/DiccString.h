#ifndef DICCSTRING_H_
#define DICCSTRING_H_


#include <iostream>
#include <string>
#include <ostream>
#include "pila.h"
#include "aed2/TiposBasicos.h"
#include "aed2/Lista.h"
#include "aed2/Dicc.h"
#include "aed2/Conj.h"


using namespace aed2;
using namespace std;

namespace modulos{

template<class S>
class DiccString{
  private:

    struct nodoStr { 
        nodoStr* padre;
        nodoStr* caracteres[256];
        S* significado; 

        nodoStr(S* s) : padre(NULL), significado(s){for(int j = 0 ; j < 256 ; j++){
        caracteres[j]=NULL;}
        };
      };

    struct data { 
      nodoStr* sig;
      String clav;

      data(nodoStr* s, String c) : sig(s), clav(c) {}
    };


	public:

  	class ItStr;
		class const_ItStr;

		DiccString();
		DiccString(const DiccString<S>& otro);
    ~DiccString();
		DiccString<S>& operator=(const DiccString<S>& otro);

		void Definir(const String& clave,const S& sig);

		bool EsVacio() const;
    bool Definido(const String& clave) const;
		S& Obtener(const String& clave);
    const S& Obtener(const String& clave) const;
		void Borrar(const String& clave);
		const String Maximo() const;
		const String Minimo() const;
		
		ItStr CrearIt();
    const_ItStr CrearIt() const;
    
    ItStr Buscar(const String&);
    const_ItStr Buscar(const String&) const;
    bool sonTodosNull(nodoStr*[],int);
    void destructorrecursivo(nodoStr*);
   

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
    
      

      private:	
      		
        friend class DiccString<S>;
        friend class DiccString<S>::const_ItStr;

          nodoStr* siguiente;
      		nodoStr* anterior;
      		Pila<data> recorrido;
          String clave;
      		bool busca;
          DiccString<S>* diccionario;    // EN EL TP NO ESTABA, PERDIAMOS REFERENCIA AL ARBOL

          ItStr(nodoStr* s, nodoStr* a, String c, bool b, DiccString<S>* d);

          void AgregarComoSiguiente(const String clave,const S& sig);
          bool ApuntaAHoja(); 

      		friend typename DiccString<S>::ItStr DiccString<S>::CrearIt();
         

        friend ostream& operator<<(ostream& os, const typename DiccString<S>::ItStr& it){
            return os << (it->siguiente).clave << ":" << (it->siguiente).significado << endl;
          }
    };

   	class const_ItStr
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

          friend class DiccString<S>;

       		nodoStr* siguiente;
      		nodoStr* anterior;
      		Pila<data> recorrido; //asegurar que la lista funcione como una pila (insertar por adelante y sacar por adelante)
          String clave;
      		bool busca;
          const DiccString<S>* diccionario; 

         const_ItStr(nodoStr* s, nodoStr* a, String c, bool b, const DiccString<S>* d);
         bool ApuntaAHoja();

      		friend typename DiccString<S>::const_ItStr DiccString<S>::CrearIt() const;
          
         friend ostream& operator<<(ostream& os, const typename DiccString<S>::const_ItStr& it){
            return os << (it->siguiente).clave << ":" << (it->siguiente).significado << endl;
          }

    };
    
    private:
		
    nodoStr* raiz;

	};

template<class S>
ostream& operator << (ostream &os, const DiccString<S>& d);

template<class S>
bool operator == (const DiccString<S>& d1, const DiccString<S>& d2);


//  ----------------------------------->> FUNCIONES DEL ITSTR <<--------------------------------------------------


template<class S>
DiccString<S>::ItStr::ItStr(): siguiente(NULL), anterior(NULL), clave (""),busca(false), diccionario(NULL){}

template<class S>
DiccString<S>::ItStr::ItStr(const typename DiccString<S>::ItStr& otro): siguiente(otro.siguiente), anterior(otro.anterior), clave(otro.clave), busca(otro.busca), recorrido(otro.recorrido), diccionario(otro.diccionario) {}

template<class S>
DiccString<S>::ItStr::ItStr(nodoStr* s, nodoStr* a, String c, bool b, DiccString<S>* d): siguiente(s), anterior(a), busca(b), clave(c), diccionario(d){}

template<class S>
typename DiccString<S>::ItStr& DiccString<S>::ItStr::operator = (const typename DiccString<S>::ItStr& otro){
  siguiente = otro.siguiente;
  anterior = otro.anterior;
  recorrido = otro.recorrido;
  busca = otro.busca;
  clave = otro.clave;
  return *this;
}

template<class S>
bool DiccString<S>::ItStr:: operator == (const typename DiccString<S>::ItStr& otro) const
{
  return (siguiente==otro.siguiente && anterior==otro.anterior && recorrido==otro.recorrido && busca==otro.busca && clave == otro.clave);
}

template<class S>
bool DiccString<S>::ItStr::HaySiguiente() const{
  return !(siguiente == NULL);
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
          data d(NULL,"");
          d.sig = siguiente->caracteres[j];
          char cj = j;
          nuevaclave.push_back(cj);
          d.clav = nuevaclave;
          recorrido.Apilar(d);
        }
        j--;
      }
      it.siguiente = it.recorrido.Tope().sig;
      it.clave = it.recorrido.Tope().clav;
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
      data d(NULL,"");
      d.sig = siguiente->caracteres[j];
      char cj = j;
      nuevaclave.push_back(cj);
      d.clav = nuevaclave;
      recorrido.Apilar(d); 
    }
    j--;
  }
  if(recorrido.EsVacia()){
    anterior = siguiente;
    siguiente = NULL;
  }else{
    while(!recorrido.EsVacia() && recorrido.Tope().sig->significado == NULL){
      int j = 255;
      nodoStr* guardanodo = recorrido.Tope().sig;
      String guardaclave = recorrido.Tope().clav;
      recorrido.Desapilar();
      while(j >= 0){
        if(guardanodo->caracteres[j] != NULL){
          String nuevaclave = guardaclave;
          data d(NULL,"");
          d.sig = guardanodo->caracteres[j];
          char cj = j;
          nuevaclave.push_back(cj);
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
      siguiente = recorrido.Tope().sig;
      clave = recorrido.Tope().clav;
      anterior = siguiente->padre;
      recorrido.Desapilar();
    }
  }
}

template<class S>
void DiccString<S>::ItStr::EliminarSiguiente(){
  delete siguiente->significado;
  siguiente->significado = NULL;
  if (anterior==NULL && ApuntaAHoja()){
    delete siguiente;
    diccionario->raiz = NULL;
    siguiente = NULL;
  }else{
    while(ApuntaAHoja() && siguiente->significado == NULL && anterior != NULL){
      int i = clave[clave.length()-1];
      clave.resize(clave.length()-1);
      delete siguiente;
      anterior->caracteres[i] = NULL;
      siguiente = anterior;
      anterior = anterior->padre;
    }
    for(int j=255;j>=0;j--){
      if(siguiente->caracteres[j]!=NULL){
        String nuevaclave = clave;
        data d(NULL,"");
        d.sig = siguiente->caracteres[j];
        char cj = j;
        nuevaclave.push_back(cj);
        d.clav = nuevaclave;
        recorrido.Apilar(d); 
      }
    }
    if(recorrido.EsVacia()){
      anterior = siguiente;
      siguiente = NULL;
    }else{
      Avanzar();
    }
  }
}

template<class S>
bool DiccString<S>::ItStr::ApuntaAHoja(){
  bool res = true;
  int i = 0;
  while(res && i<256){
    res = res && (siguiente->caracteres)[i]==NULL;
    i++;
  }
  return res;
}


template<class S>
void DiccString<S>::ItStr::AgregarComoSiguiente(const String c,const S& s){   // En el diseño falto contemplar el caso de definir la raíz
  S* p = new S;
  *p = s;
  if (anterior==NULL){
    if (diccionario->EsVacio()){
      nodoStr* n = new nodoStr(p);
      diccionario->raiz = n;
      siguiente = n;
      int j = 0;
      while (j<c.length()){
        nodoStr* n = new nodoStr(NULL);
        int i = c[j];
        n->padre = siguiente;
        siguiente->caracteres[i]=n;
        anterior = siguiente;
        siguiente= n;
        j++;
      }
      }
   }else{
    if (!HaySiguiente()){
      nodoStr* n = new nodoStr(NULL);
      int j = clave.length();
      n->padre = anterior;
      int i = c[j-1];
      anterior->caracteres[i] = n;
      siguiente = n;
      while (j<c.length()){
        nodoStr* n = new nodoStr(NULL);
        int i = c[j];
        n->padre = siguiente;
        siguiente->caracteres[i]=n;
        anterior = siguiente;
        siguiente = n;
        j++;
      }
    }
  }
  siguiente->significado = p;
}





//-------------------------------------- Funciones del const_ItStr ---------------------------------------



template<class S>
DiccString<S>::const_ItStr::const_ItStr(): siguiente(NULL), anterior(NULL), clave (""),busca(false), diccionario(NULL){}

template<class S>
DiccString<S>::const_ItStr::const_ItStr(const typename DiccString<S>::const_ItStr& otro): siguiente(otro.siguiente), anterior(otro.anterior), clave(otro.clave), busca(otro.busca), recorrido(otro.recorrido), diccionario(otro.diccionario) {}

template<class S>
DiccString<S>::const_ItStr::const_ItStr(nodoStr* s, nodoStr* a, String c, bool b, const DiccString<S>* d): siguiente(s), anterior(a), busca(b), clave(c), diccionario(d){}

template<class S>
typename DiccString<S>::const_ItStr& DiccString<S>::const_ItStr::operator = (const typename DiccString<S>::const_ItStr& otro){
  siguiente = otro.siguiente;
  anterior = otro.anterior;
  recorrido = otro.recorrido;
  busca = otro.busca;
  clave = otro.clave;
  return *this;
}

template<class S>
bool DiccString<S>::const_ItStr:: operator == (const typename DiccString<S>::const_ItStr& otro) const
{
  return (siguiente==otro.siguiente && anterior==otro.anterior && recorrido==otro.recorrido && busca==otro.busca && clave == otro.clave);
}

template<class S>
bool DiccString<S>::const_ItStr::HaySiguiente() const{
  return !(siguiente == NULL);
}

template<class S>
const String& DiccString<S>::const_ItStr::SiguienteClave() const{
  return clave;
}

template<class S>
const S& DiccString<S>::const_ItStr::SiguienteSignificado() const{
  return *(siguiente->significado);
}

template<class S>
void DiccString<S>::const_ItStr::Avanzar(){
  if(busca){
    typename DiccString<S>::const_ItStr it(*this);
    while(it.anterior != NULL){
      it.siguiente = it.anterior;
      it.anterior = it.anterior->padre;
    }
    while(it.clave != clave){
      int j = 255;
      while(j >= 0){
        if(siguiente->caracteres[j] != NULL){
          String nuevaclave = clave;
          data d(NULL,"");
          d.sig = siguiente->caracteres[j];
          char cj = j;
          nuevaclave.push_back(cj);
          d.clav = nuevaclave;
          recorrido.Apilar(d);
        }
        j--;
      }
      it.siguiente = it.recorrido.Tope().sig;
      it.clave = it.recorrido.Tope().clav;
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
      data d(NULL,"");
      d.sig = siguiente->caracteres[j];
      char cj = j;
      nuevaclave.push_back(cj);
      d.clav = nuevaclave;
      recorrido.Apilar(d); 
    }
    j--;
  }
  if(recorrido.EsVacia()){
    anterior = siguiente;
    siguiente = NULL;
  }else{
    while(!recorrido.EsVacia() && recorrido.Tope().sig->significado == NULL){
      int j = 255;
      nodoStr* guardanodo = recorrido.Tope().sig;
      String guardaclave = recorrido.Tope().clav;
      recorrido.Desapilar();
      while(j >= 0){
        if(guardanodo->caracteres[j] != NULL){
          String nuevaclave = guardaclave;
          data d(NULL,"");
          d.sig = guardanodo->caracteres[j];
          char cj = j;
          nuevaclave.push_back(cj);
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
      siguiente = recorrido.Tope().sig;
      clave = recorrido.Tope().clav;
      anterior = siguiente->padre;
      recorrido.Desapilar();
    }
  }
}

template<class S>
bool DiccString<S>::const_ItStr::ApuntaAHoja(){
  bool res = true;
  int i = 0;
  while(res && i<256){
    res = res && (siguiente->caracteres)[i]==NULL;
    i++;
  }
  return res;
}


//  ------------>> FUNCIONES DEL DICCSTRING <<---------------


template<class S>
DiccString<S>::DiccString():raiz(new nodoStr(NULL)){}

template<class S>
DiccString<S>::DiccString(const DiccString<S>& otro){
  typename DiccString<S>::const_ItStr it = otro.CrearIt();
  raiz = new nodoStr(NULL);
  while(it.HaySiguiente()){
    Definir(it.SiguienteClave(),it.SiguienteSignificado()); 
    it.Avanzar();
  }


}

template<class S>
bool DiccString<S>::sonTodosNull(nodoStr* caracteres[] , int n){
 
  if (EsVacio()){return true;}
  int i=0;
  bool res = true;
  while(i<n){
    res = (res && caracteres[i] == NULL);
    i++;
  }
return res;
}


template<class S>
void DiccString<S>::destructorrecursivo(nodoStr* n){  
  if(sonTodosNull(n->caracteres,256)){
    delete n->significado;
    delete n;
  }
  else
  {
    int i = 0;
    while(i<256){
      if(n->caracteres[i] != NULL){
        destructorrecursivo(n->caracteres[i]);
      }
    i++;
    }
  delete n->significado;
  delete n;
  }
}


template<class S>
DiccString<S>::~DiccString(){
  destructorrecursivo(raiz);
}

template<class S>
DiccString<S>& DiccString<S>::operator=(const DiccString<S>& otro){
  destructorrecursivo(raiz); //limpio
  typename DiccString<S>::const_ItStr it = otro.CrearIt();
  raiz = new nodoStr(NULL);
  while(it.HaySiguiente()){
    Definir(it.SiguienteClave(),it.SiguienteSignificado()); 
    it.Avanzar();
  }
  return *this;
}

template<class S>
typename DiccString<S>::const_ItStr DiccString<S>::CrearIt() const{
  typename DiccString<S>::const_ItStr res(raiz,NULL,"",false, this);
  if(res.HaySiguiente() && !Definido("")){
    res.Avanzar();
  }
  return res;
}

template<class S>
typename DiccString<S>::ItStr DiccString<S>::CrearIt(){
  typename DiccString<S>::ItStr res(raiz,NULL,"",false, this);
  if(res.HaySiguiente() && !Definido("")){
    res.Avanzar();
  }  
  return res;
}


template<class S>
typename DiccString<S>::const_ItStr DiccString<S>::Buscar(const String& s) const{
  nodoStr* rec = raiz;
  nodoStr* padre = NULL;
  String clave = "";
  int j = 0;
  while (clave != s && rec != NULL){
    int i = s[j];
    padre = rec;
    rec = (rec->caracteres)[i];
    clave.push_back(s[j]);
    j++;
  }
  typename DiccString<S>::const_ItStr res(rec,padre,clave,true,this);
  return res;
}

template<class S>
typename DiccString<S>::ItStr DiccString<S>::Buscar(const String& s){
  nodoStr* rec = raiz;
  nodoStr* padre = NULL;
  String clave = "";
  int j = 0; 
  while (clave != s && rec != NULL){
    int i = s[j];
    padre = rec;
    rec = (rec->caracteres)[i];
    clave.push_back(s[j]);
    j++;
  }
  typename DiccString<S>::ItStr res(rec,padre,clave,true, this);
  return res;
}

template<class S>
void DiccString<S>::Definir(const String& clave,const S& sig){

Buscar(clave).AgregarComoSiguiente(clave,sig);

}

template<class S>
bool DiccString<S>::EsVacio() const{
  return raiz==NULL;
}

template<class S>
bool DiccString<S>::Definido(const String& clave) const{
  typename DiccString<S>::const_ItStr it = Buscar(clave);
  return it.HaySiguiente() && it.siguiente->significado!=NULL;
}

template<class S>
S& DiccString<S>::Obtener(const String& clave){
  return Buscar(clave).SiguienteSignificado();
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
const String DiccString<S>::Minimo() const {
  DiccString<S>::const_ItStr i = CrearIt();
  return i.clave;
}



template<class S>
const String DiccString<S>::Maximo() const {
  nodoStr* a = raiz;
  String res = "";
  int j = 255;
  while(a != NULL){
    j = 255;
    while(j > 0 && (a->caracteres)[j] == NULL){
      j--;
    }
    char i = j;
    res.push_back(i);
    a = (a->caracteres)[j];
  }
  return res;
}


};	


  #endif