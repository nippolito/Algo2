#ifndef MODULOS_BASE_H_INCLUDED
#define MODULOS_BASE_H_INCLUDED

#include "tabla.h"


using namespace std;
using namespace aed2;


namespace modulos{
	class Base{
		
		private: 
				
				struct tupla{
					String tabmod;
					Registro regmod;
					tupla(){}
				};

				struct Join {
					String campo;
					Lista<tupla> cambios;
					typename Lista<Tabla>::Iterador verJoin;
					Join(){} //CHEQUEAR QUE LO CREE VACIO
				};

		public:

			Base();
			Base(const Base& otra);
			~Base();
			Base& operator=(const Base& otra);
			Conj<String> Tablas(); 
			Tabla DameTabla(const String t);
			bool HayJoin(const String t1, const String t2);
			String CampoJoin(const String t1,const String t2);
			void AgregarTabla(Tabla t);
			void InsertarEntrada(Registro r, String t);
			void Borrar(Registro r, String t);
			const typename Lista<Tabla>::Iterador GenerarVistaJoin(const String t, const String t2, const String c);
			void BorrarJoin(const String t1, const String t2);
			Conj<Registro> Buscar(const Registro criterio, String t1);
			const typename Lista<Tabla>::Iterador VistaJoin(const String t1, const String t2);
			Conj<Registro> RegistrosB(const String t1);
			Nat CantidadDeAccesosB(const String t);
			String TablaMaxima();

		private:	
		
			Lista<Tabla> tablas;  //igual que arriba
			DiccString<typename::Lista<Tabla>::Iterador> TporNombre;  //En el TP es un Conjunto, lo cambiamos por Lista porque el sig de Conjunto es const
			Conj<String> nombres;
			typename Lista<Tabla>::Iterador TablaMax; //igual que arriba
			DiccString< DiccString<Join> > joins;
			Lista<Tabla> losjoins;

	};



//----------------------------------------> ALGORITMOS <-------------------------------
Base::Base(){}

Base::Base(const Base& otra): tablas(otra.tablas) ,TporNombre(otra.TporNombre),  nombres(otra.nombres) , TablaMax(otra.TablaMax) , joins(otra.joins) , losjoins(otra.losjoins) {}

// Base& Base::operator=(const Base& otra){
// 	tablas = otra.tablas;
// 	TporNombre = otra.TporNombre;
// 	nombres = otra.nombres;
// 	TablaMax = otra.TablaMax;
// 	joins = otra.joins;
// 	losjoins = otra.losjoins;
// 	return *this;
// }

Base::~Base(){}

Conj<String> Base::Tablas(){
	Conj<String> res;
	// DiccString<typename::Lista<Tabla>::Iterador> dld = TporNombre;
	typename DiccString<typename::Lista<Tabla>::Iterador>::ItStr it = TporNombre.CrearIt();
	while(it.HaySiguiente()){
		res.AgregarRapido(it.SiguienteClave());
		it.Avanzar();
	}
	return res;
}

Tabla Base::DameTabla(const String t){
	return TporNombre.Obtener(t).Siguiente();
}


void Base::AgregarTabla(Tabla t){
	tablas.AgregarAtras(t);
	typename Lista<Tabla>::Iterador i = tablas.CrearIt();
	while(i.HaySiguiente() && i.Siguiente().DameNombre() != t.DameNombre()){
		i.Avanzar();
	}
	cerr << "sale ciclo" << endl;
	TporNombre.Definir(t.DameNombre(), i);
	nombres.AgregarRapido(t.DameNombre());
	if(tablas.Longitud() == 1){
		TablaMax = i;
	}else{
		if( CantidadDeAccesosB(t.DameNombre()) > CantidadDeAccesosB(TablaMax.Siguiente().DameNombre())){
			TablaMax = i;
		}
	}
	cerr << "va a terminar " << endl;
}


void Base::InsertarEntrada(Registro r, String t){
	typename DiccString<typename::Lista<Tabla>::Iterador>::ItStr i = TporNombre.Buscar(t);
	i.SiguienteSignificado().Siguiente().AgregarRegistro(r);
	if(CantidadDeAccesosB(TporNombre.Obtener(t).Siguiente().DameNombre()) > CantidadDeAccesosB(TablaMax.Siguiente().DameNombre())){
		TablaMax = TporNombre.Obtener(t);
	}
	if(joins.Definido(t)){
		typename DiccString<Join>::ItStr it = joins.Obtener(t).CrearIt();
		while(it.HaySiguiente()){
			tupla tps;
			tps.regmod = r;
			tps.tabmod = t;
			it.SiguienteSignificado().cambios.AgregarAdelante(tps);
			if(HayJoin(it.SiguienteClave(), t)){
				joins.Obtener(it.SiguienteClave()).Obtener(t).cambios.AgregarAdelante(tps);
			}
			it.Avanzar();
		}
	}
}


Conj<Registro> Base::Buscar(const Registro criterio,String t1){
	return DameTabla(t1).BuscarT(criterio);
}


void Base::Borrar(Registro r, String t){
	typename DiccString<typename::Lista<Tabla>::Iterador>::ItStr i = TporNombre.Buscar(t);
	cout << i.SiguienteSignificado().Siguiente().DameNombre() << endl;
	i.SiguienteSignificado().Siguiente().BorrarRegistro(r);
	if(CantidadDeAccesosB(TporNombre.Obtener(t).Siguiente().DameNombre()) > CantidadDeAccesosB(TablaMax.Siguiente().DameNombre())){
		TablaMax = TporNombre.Obtener(t);
	}
	if(joins.Definido(t)){
		typename DiccString<Join>::ItStr it = joins.Obtener(t).CrearIt();
		while(it.HaySiguiente()){
			tupla tps;
			tps.regmod = r;
			tps.tabmod = t;
			it.SiguienteSignificado().cambios.AgregarAdelante(tps);
			if(HayJoin(it.SiguienteClave(), t)){
				joins.Obtener(it.SiguienteClave()).Obtener(t).cambios.AgregarAdelante(tps);
			}
			it.Avanzar();
		}
	}
}


String Base::TablaMaxima(){
	return TablaMax.Siguiente().DameNombre();
}


bool Base::HayJoin(const String t1, const String t2){
	if(joins.Definido(t1) == false){
		return false;
	}else{
		return joins.Obtener(t1).Definido(t2);
	}
}


void Base::BorrarJoin(const String t1, const String t2){
	typename DiccString<Join>::ItStr j = joins.Obtener(t1).Buscar(t2);
	j.EliminarSiguiente();
}


String Base::CampoJoin(const String t1,const String t2){
	typename DiccString<Join>::ItStr j = joins.Obtener(t1).Buscar(t2);
	return j.SiguienteSignificado().campo;
}


const typename Lista<Tabla>::Iterador Base::GenerarVistaJoin(const String t1, const String t2, const String c){				//Gerva ahora devolvemos un ite a lista de tabla
	Conj<Registro> rs = DameTabla(t1).CombinarRegistro(c, DameTabla(t2)); //funcional mal COMBINARREGISTRO, a los campos de t2 que no existen en t1 en vez de mergearlos con su dato les pone un dato cualquiera de t1
	typename Conj<Registro>::Iterador it = rs.CrearIt();
	Conj<String> cla;
	cla.Agregar(c);
	Tabla nt = Tabla("nuevat", cla , it.Siguiente());
	nt.Indexar(c);
	while(it.HaySiguiente()){
		nt.AgregarRegistro(it.Siguiente());
		it.Avanzar();
	}
	losjoins.AgregarAdelante(nt);
	typename Lista<Tabla>::Iterador it2 = losjoins.CrearIt();
	// Conj<Registro> lrl = it2.Siguiente().Registros();
	// typename Conj<Registro>::Iterador res =  lrl.CrearIt();
	DiccString<Join> d;
	Join js;
	js.campo = c;
	Lista<tupla> ltup;
	js.cambios = ltup;
	js.verJoin = it2;
	if(!joins.Definido(t1)){
		d.Definir(t2, js);
		joins.Definir(t1, d);
	}else{
		joins.Obtener(t1).Definir(t2, js);
	}	
	return it2;
}

Conj<Registro> Base::RegistrosB(const String t1){
 	return DameTabla(t1).Registros();
}


Nat Base::CantidadDeAccesosB(const String t){
	return DameTabla(t).CantidadDeAccesos();
}


const typename Lista<Tabla>::Iterador Base::VistaJoin(const String t1, const String t2){   //tenemos un const iterador porque nos tiraba error pero no sabemos si es correcto
	Conj<String> cs;
	cs.Agregar(CampoJoin(t1, t2));
	Registro rg1 = DameTabla(t1).Columnas();
	Registro rg2 = DameTabla(t2).Columnas();
	Registro rg3 = rg1.AgregarCampos(rg2); 
	Tabla tab("tab", cs, rg3);
	//tab = joins.Obtener(t1).Obtener(t2).verJoin.Siguiente();
	typename Lista<tupla>::Iterador itC = joins.Obtener(t1).Obtener(t2).cambios.CrearItUlt();
	Registro crit;
	String ca = CampoJoin(t1, t2);
	while(itC.HayAnterior()){
		Dato d;
		d = itC.Anterior().regmod.Obtener(ca);
		crit.Definir(ca, d);
		if(DameTabla(itC.Anterior().tabmod).Esta(itC.Anterior().regmod) ){
			if(itC.Anterior().tabmod == t1){
				if(Buscar(crit, t2).EsVacio() == false ){
					Conj<Registro> crc = Buscar(crit, t2);
					typename Conj<Registro>::Iterador itB2 = crc.CrearIt();
					Registro reg1 = itC.Anterior().regmod.AgregarCampos(itB2.Siguiente());
					tab.AgregarRegistro(reg1);
				}
			}else{
				if(Buscar(crit, t1).EsVacio() == false ){
					Conj<Registro> crd = Buscar(crit, t1);
					typename Conj<Registro>::Iterador itB1 = crd.CrearIt();
					Registro reg2 = itC.Anterior().regmod.AgregarCampos(itB1.Siguiente());
					joins.Obtener(t1).Obtener(t2).verJoin.Siguiente().AgregarRegistro(reg2);   //estaba afuera del If pero lo mandamos acá porque supusimos error previo
				}
			}
		}else{
			// if(!EsVacio(tab.BuscarT(crit)) ){   //el buscarT toma parámetro const pero acá no funcionaría ya que tab no es const. Igual es lógico que busquemos algo para ver si lo podemos eliminar o no
			// 	tab.Borrar(crit);
			// }
		}
		itC.Retroceder();
	}
	// Conj<Registro> lrs = tab.Registros();
	// typename Conj<Registro>::const_Iterador res = lrs.CrearIt();
	typename Lista<Tabla>::Iterador itres = losjoins.CrearIt();
	return itres;
}




};

#endif