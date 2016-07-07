#ifndef MODULOS_PILA_H_INCLUDED
#define MODULOS_PILA_H_INCLUDED

#include "ModulosBasicos.h"
#include <iostream>
#include <string>
#include <ostream>

using namespace aed2;
using namespace std;

namespace modulos{
	template <typename T>
	class Pila{

		public:

			Pila();
			Pila(const Pila& otro);
			~Pila();


			bool EsVacia();
			void Apilar(const T elem);
			void Desapilar();
			T& Tope();

		private:
			Lista<T> list;
	};

template <typename T>
Pila<T>::Pila(){}

template <typename T>
Pila<T>::Pila(const Pila& otro): list(otro.list){}

template <typename T>
Pila<T>::~Pila(){
	while (!EsVacia()){
		Desapilar();
	}
}

template <typename T>
bool Pila<T>::EsVacia(){
	return (list.Longitud()==0);
}

template <typename T>
void Pila<T>::Desapilar(){
	list.Fin();
}

template <typename T>
void Pila<T>::Apilar(const T elem){
	list.AgregarAdelante(elem);
}

template <typename T>
T& Pila<T>::Tope(){
	return list.Primero();
}

};

#endif