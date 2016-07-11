#include "Driver.h"

bool aed2::operator == (const aed2::Columna& c1, const aed2::Columna& c2)
{
  return c1.nombre == c2.nombre and c1.tipo == c2.tipo;
}


using namespace aed2;
using namespace modulos;


  ////////////////////////////////////////////////////////////////////////////////
 //                             Conversor                                      //
////////////////////////////////////////////////////////////////////////////////

 modulos::Dato DSDN(const Driver::Dato& d){        // Dato Suyo a Dato Nuestro
  if ( d.esNat() ) {
    modulos::Dato res(d.dameNat());
    return res;
  }else{
    modulos:: Dato res(d.dameString());
    return res;
  }
}

Driver::Dato DNDS(const modulos::Dato& d){      // Dato Nuestro a Dato Suyo
  if ( d.EsNat() ) {
    Driver::Dato res(d.ValorNat());
    return res;
  }else{
    Driver::Dato res(d.ValorStr());
    return res;
  }
}


modulos::Registro RSRN(const Driver::Registro& r){                      // Registro Suyo a Registro Nuestro
  typename Dicc<String,Driver::Dato>::const_Iterador it = r.CrearIt();
  modulos::Registro res;
  while(it.HaySiguiente()){
    modulos::Dato d = DSDN(it.SiguienteSignificado());
    res.Definir( it.SiguienteClave(), d);
    it.Avanzar();
  }
  return res;
}


Driver::Registro RNRS(const modulos::Registro& r){                      // Registro Nuestro a Registro Suyo
  const Dicc<String,modulos::Dato> dc = r.DameDic();
  typename Dicc<String,modulos::Dato>::const_Iterador it = dc.CrearIt();
  Driver::Registro res;
  while(it.HaySiguiente()){
    Driver::Dato d = DNDS( it.SiguienteSignificado() );
    res.Definir( it.SiguienteClave(), d);
    it.Avanzar();
  }
  return res;
}



////////////////////////////////////////////////////////////////////////////////
// Dato
////////////////////////////////////////////////////////////////////////////////

Driver::Dato::Dato(const aed2::Nat& x)
  : tipo_( NAT ), nat_( x )
{}

Driver::Dato::Dato(const aed2::String& x)
  : tipo_( STR ), str_( x )
{}

bool Driver::Dato::esNat() const
{
  return tipo_ == NAT;
}

bool Driver::Dato::esString() const
{
  return tipo_ == STR;
}

TipoCampo Driver::Dato::tipo() const
{
  return tipo_;
}

const aed2::Nat& Driver::Dato::dameNat() const
{
  assert( esNat() );
  return nat_;
}

const aed2::String& Driver::Dato::dameString() const
{
  assert( esString() );
  return str_;
}

bool Driver::Dato::operator == (const Dato& otro) const
{
  return tipo_ == otro.tipo_ and (
    ( tipo_ == NAT and nat_ == otro.nat_ ) or
    ( tipo_ == STR and str_ == otro.str_ )
  );
}

bool Driver::Dato::operator != (const Dato& otro) const
{
  return not (*this == otro);
}

ostream& Driver::Dato::mostrarSuDato(ostream& os) const
  {
    if (esNat()) {
      os << nat_;
    } else{
      os << str_;
    }

  return os;
  }

ostream& operator<<(ostream& os, const Driver::Dato& d){
    return d.mostrarSuDato(os);
  }

////////////////////////////////////////////////////////////////////////////////
// Base de datos
////////////////////////////////////////////////////////////////////////////////

Driver::Driver()
{
  
  //assert(false);
}

Driver::~Driver()
{
  // TODO ...
  //assert(false);
}

// Tablas

void Driver::crearTabla(const NombreTabla& nombre, const aed2::Conj<Columna>& columnas, const aed2::Conj<NombreCampo>& claves)
{
  modulos::Registro r;
  Conj<Columna> c = columnas;
  typename Conj<Columna>::Iterador it = c.CrearIt();
  while(it.HaySiguiente()){
    if(it.Siguiente().tipo == NAT){
      modulos::Dato d(4);
      r.Definir(it.Siguiente().nombre, d);
    }else{
      modulos::Dato d("brownie");
      r.Definir(it.Siguiente().nombre, d);
    }
    it.Avanzar();
  }
  modulos::Tabla t(nombre, claves, r);
  b.AgregarTabla(t);
  //assert(false);
}

void Driver::insertarRegistro(const NombreTabla& tabla, const aed2::Driver::Registro& registro)
{
   modulos::Registro r = RSRN(registro);
   b.InsertarEntrada(r,tabla);
   //assert(false);
}

void Driver::borrarRegistro(const NombreTabla& tabla, const NombreCampo& columna, const aed2::Driver::Dato& valor)
{
   modulos::Registro crit;
   crit.Definir(columna,DSDN(valor));
   b.Borrar(crit,tabla);
   //assert(false);
}

aed2::Conj<Columna> Driver::columnasDeTabla(const NombreTabla& tabla) const
{
  Conj<Columna> res;
  modulos::Registro r = b.DameTabla(tabla).Columnas();
  Conj<String> c = b.DameTabla(tabla).Columnas().Campos();
  //typename Dicc<String,Dato>::const_Iterador it = r.DameDic().CrearIt();
  typename Conj<String>::Iterador it = c.CrearIt();
  while(it.HaySiguiente()){
    Columna c;   
    c.nombre = it.Siguiente();
    if (r.Obtener(it.Siguiente()).EsNat()){
      c.tipo = NAT;
    }else{
      c.tipo = STR;
    }
    res.AgregarRapido(c);
    it.Avanzar();
  }
  return res;
  //assert(false);
}

aed2::Conj<NombreCampo> Driver::columnasClaveDeTabla(const NombreTabla& tabla) const
{
  return b.DameTabla(tabla).Claves();     // NombreCampo es String
  //assert(false);
}

aed2::Conj<Driver::Registro> Driver::registrosDeTabla(const NombreTabla& tabla) const
{
  Conj<Driver::Registro> res;
  Conj<modulos::Registro> cr = b.DameTabla(tabla).Registros();
  typename Conj<modulos::Registro>::Iterador itr = cr.CrearIt();
  while(itr.HaySiguiente()){
    res.Agregar(RNRS(itr.Siguiente()));
    itr.Avanzar();
  }
  return res;
  //assert(false);
}

aed2::Nat Driver::cantidadDeAccesosDeTabla(const NombreTabla& tabla) const
{
  return b.CantidadDeAccesosB(tabla);
  //assert(false);
}

Driver::Dato Driver::minimo(const NombreTabla& tabla, const NombreCampo& columna) const
{
  return DNDS(b.DameTabla(tabla).Minimo(columna));
  //assert(false);
}

Driver::Dato Driver::maximo(const NombreTabla& tabla, const NombreCampo& columna) const
{
  return DNDS(b.DameTabla(tabla).Maximo(columna));
  //assert(false);
}

aed2::Conj<Driver::Registro> Driver::buscar(const NombreTabla& tabla, const aed2::Driver::Registro& criterio) const
{
  Conj<Driver::Registro> res;
  modulos::Registro crit = RSRN(criterio);
  Conj<modulos::Registro> cr = b.DameTabla(tabla).BuscarT(crit);
  typename Conj<modulos::Registro>::Iterador itr = cr.CrearIt();
  while(itr.HaySiguiente()){
    res.Agregar(RNRS(itr.Siguiente()));
    itr.Avanzar();
  }
  return res;
  //assert(false);
}

aed2::Conj<NombreTabla> Driver::tablas() const
{
  return b.Tablas();
  //assert(false);
}

const NombreTabla Driver::tablaMaxima() const
{
  return b.TablaMaxima();
  //assert(false);
}

// Indices

bool Driver::tieneIndiceNat(const NombreTabla& tabla) const
{
  const Conj<String> indices = b.DameTabla(tabla).Indices();
  typename Conj<String>::const_Iterador it = indices.CrearIt();
  bool res = false;
  while(it.HaySiguiente() && !res){
    res = b.DameTabla(tabla).TipoCampo(it.Siguiente());
    it.Avanzar();
  }
  return res;
  //assert(false);
}

bool Driver::tieneIndiceString(const NombreTabla& tabla) const
{
   const Conj<String> indices = b.DameTabla(tabla).Indices();
  typename Conj<String>::const_Iterador it = indices.CrearIt();
  bool res= false;
  while(it.HaySiguiente() && !res){
    res = !(b.DameTabla(tabla).TipoCampo(it.Siguiente()));
    it.Avanzar();
  }
  return res;
  //assert(false);
}

const NombreCampo& Driver::campoIndiceNat(const NombreTabla& tabla) const
{
  /*const Conj<String> indices = b.DameTabla(tabla).Indices();
  typename Conj<String>::const_Iterador it = indices.CrearIt();
  bool flag = b.DameTabla(tabla).TipoCampo(it.Siguiente());
  while(it.HaySiguiente() && !flag){
    flag = b.DameTabla(tabla).TipoCampo(it.Siguiente());
    it.Avanzar();
  }
  const NombreCampo& ss = it.Siguiente();
  return ss;*/
  //assert(false);
  return b.DameTabla(tabla).DameIndiceNat();

}

const NombreCampo& Driver::campoIndiceString(const NombreTabla& tabla) const
{
  /*const Conj<String> indices = b.DameTabla(tabla).Indices();
  typename Conj<String>::const_Iterador it = indices.CrearIt();
  bool flag=  !b.DameTabla(tabla).TipoCampo(it.Siguiente());
  while(it.HaySiguiente() && !flag){
    flag = !(b.DameTabla(tabla).TipoCampo(it.Siguiente()));
    it.Avanzar();
  }
  return it.Siguiente();
  //assert(false);*/
  return b.DameTabla(tabla).DameIndiceStr();
}

void Driver::crearIndiceNat(const NombreTabla& tabla, const NombreCampo& campo)
{
  b.DameTabla(tabla).Indexar(campo);
  //assert(false);
}

void Driver::crearIndiceString(const NombreTabla& tabla, const NombreCampo& campo)
{
  b.DameTabla(tabla).Indexar(campo);
  //assert(false);
}

// Joins

bool Driver::hayJoin(const NombreTabla& tabla1, const NombreTabla& tabla2) const
{
  return b.HayJoin(tabla1,tabla2);
  //assert(false);
}

const NombreCampo& Driver::campoJoin(const NombreTabla& tabla1, const NombreTabla& tabla2) const
{
  return b.CampoJoin(tabla1,tabla2);
  //assert(false);
}

void Driver::generarVistaJoin(const NombreTabla& tabla1, const NombreTabla& tabla2, const NombreCampo& campo)
{
  b.GenerarVistaJoin(tabla1,tabla2,campo);
  //assert(false);
}

void Driver::borrarVistaJoin(const NombreTabla& tabla1, const NombreTabla& tabla2)
{
  b.BorrarJoin(tabla1,tabla2);
  //assert(false);
}

aed2::Conj<Driver::Registro> Driver::vistaJoin(const NombreTabla& tabla1, const NombreTabla& tabla2)
{
  Conj<Driver::Registro> res;
  Conj<modulos::Registro> cr = b.VistaJoin(tabla1,tabla2).Siguiente().Registros();
  typename Conj<modulos::Registro>::Iterador itr = cr.CrearIt();
  while(itr.HaySiguiente()){
    res.Agregar(RNRS(itr.Siguiente()));
    itr.Avanzar();
  }
  return res;
  //assert(false);
}
