
#include "base.h"

using namespace std;
using namespace aed2;
//using namespace modulos;



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

Conj<String> Base::Tablas() const{
	Conj<String> res;
	// DiccString<typename::Lista<Tabla>::Iterador> dld = TporNombre;
	typename DiccString<typename::Lista<Tabla>::Iterador>::const_ItStr it = TporNombre.CrearIt();
	while(it.HaySiguiente()){
		res.AgregarRapido(it.SiguienteClave());
		it.Avanzar();
	}
	return res;
}

Tabla& Base::DameTabla(const String t) const {
	typename Lista<Tabla>::Iterador i = TporNombre.Obtener(t);
	return i.Siguiente();
}


void Base::AgregarTabla(Tabla t){
	tablas.AgregarAtras(t);
	typename Lista<Tabla>::Iterador i = tablas.CrearIt();
	while(i.HaySiguiente() && i.Siguiente().DameNombre() != t.DameNombre()){
		i.Avanzar();
	}
	TporNombre.Definir(t.DameNombre(), i);
	nombres.AgregarRapido(t.DameNombre());
	if(tablas.Longitud() == 1){
		TablaMax = i;
	}else{
		if( CantidadDeAccesosB(t.DameNombre()) > CantidadDeAccesosB(TablaMax.Siguiente().DameNombre())){
			TablaMax = i;
		}
	}
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
	typename DiccString<typename Lista<Tabla>::Iterador>::ItStr i = TporNombre.Buscar(t);
	i.SiguienteSignificado().Siguiente().BorrarRegistro(r);
	if(CantidadDeAccesosB(TporNombre.Obtener(t).Siguiente().DameNombre()) > CantidadDeAccesosB(TablaMax.Siguiente().DameNombre())){
		TablaMax = TporNombre.Obtener(t);
	}
	tupla tps;
	tps.regmod = r;
	tps.tabmod = t;
	if(joins.Definido(t)){
		typename DiccString<Join>::ItStr it = joins.Obtener(t).CrearIt();
		while(it.HaySiguiente()){
			it.SiguienteSignificado().cambios.AgregarAdelante(tps);
			it.Avanzar();
		}
	}
	typename Lista<Tabla>::Iterador j = tablas.CrearIt();
	while(j.HaySiguiente()){
		if(HayJoin(j.Siguiente().DameNombre(), t)){
			joins.Obtener(j.Siguiente().DameNombre()).Obtener(t).cambios.AgregarAdelante(tps);
		}
		j.Avanzar();
	}
}


const String Base::TablaMaxima() const{
	return TablaMax.Siguiente().DameNombre();
}


bool Base::HayJoin(const String t1, const String t2) const{
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


const String& Base::CampoJoin(const String& t1,const String& t2) const{ 
	typename DiccString<Join>::const_ItStr j = joins.Obtener(t1).Buscar(t2);
	return j.SiguienteSignificado().campo;
}


const typename Lista<Tabla>::Iterador Base::GenerarVistaJoin(const String t1, const String t2, const String c){				//Gerva ahora devolvemos un ite a lista de tabla
	Conj<Registro> rs = DameTabla(t1).CombinarRegistro(c, DameTabla(t2)); 
	Registro c1 = DameTabla(t1).Columnas().AgregarCampos(DameTabla(t2).Columnas());
	typename Conj<Registro>::Iterador it = rs.CrearIt();
	Conj<String> cla;
	cla.Agregar(c);
	//const Conj<String> clacopia = cla;
	//const String ss = "nuevat";
	Tabla nt = Tabla( "nuevat", cla , c1);
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
	/*if(!joins.Definido(t2)){
		d.Definir(t1, js);
		joins.Definir(t2, d);
	}else{
		joins.Obtener(t2).Definir(t1, js);
	}*/
	return it2;
}

Conj<Registro> Base::RegistrosB(const String t1){
 	return DameTabla(t1).Registros();
}


Nat Base::CantidadDeAccesosB(const String t) const{
	return DameTabla(t).CantidadDeAccesos();
}


const typename Lista<Tabla>::Iterador Base::VistaJoin(const String t1, const String t2){   //tenemos un const iterador porque nos tiraba error pero no sabemos si es correcto
	typename Lista<Tabla>::Iterador itab = joins.Obtener(t1).Obtener(t2).verJoin;
	typename Lista<tupla>::Iterador itC = joins.Obtener(t1).Obtener(t2).cambios.CrearItUlt();
	Registro crit;
	String ca = CampoJoin(t1, t2);
	while(itC.HayAnterior()){
		Dato d;
		d = itC.Anterior().regmod.Obtener(ca);
		crit.DefinirLento(ca, d);
		if(DameTabla(itC.Anterior().tabmod).Esta(itC.Anterior().regmod) ){
			if(itC.Anterior().tabmod == t1){
				if(Buscar(crit, t2).EsVacio() == false ){
					Conj<Registro> crc = Buscar(crit, t2);
					typename Conj<Registro>::Iterador itB2 = crc.CrearIt();
					Registro reg1 = itC.Anterior().regmod.AgregarCampos(itB2.Siguiente());
					itab.Siguiente().AgregarRegistro(reg1);
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
			if(!itab.Siguiente().BuscarT(crit).EsVacio()){  
				itab.Siguiente().BorrarRegistro(crit);
			}
		}
		itC.EliminarAnterior();
		//itC.Retroceder();
	}
	return itab;
}

