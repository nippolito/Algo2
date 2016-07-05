DATO


iMin:

int i = CrearIt(c);
res = Siguiente(i);
while(HaySiguiente(i)){
	if(iMenorOIgual(Siguiente(i), res)){
		res = Siguiente(i);
	}
	Avanzar(i);
}




iMax:

int i = CrearIt(c);
res = Siguiente(i);
while(HaySiguiente(i)){
	if(!(iMenorOIgual(Siguiente(i), res))){
		res = Siguiente(i);
	}
	Avanzar(i);
}


iMenorOIgual:

if(s.tipo?){
	res = (s.Nat <= s2.Nat);
}else{
	i = 0:
	while(i < Longitud(s.String) && i < Longitud(s2.String) && s.String[i] = s2.String[i]){
		i++;
	}
	if(i == Longitud(s.String) || i == Longitud(s2.String)){
		res = (Longitud(e.String) <= Longitud(s2.String) ); 
	}else{
		res = (ord(s.String) <= ord(s2.String) ) 
	}
}



REGISTRO



iCampos:

res = vacio();
i = CrearIt(r);
while(HaySiguiente(i)){
	Agregar(res, SiguienteClave(i));
	Avanzar(i);
}




iCopiarCampos:

it = CrearIt(cc);
res = Copiar(r1);
while(HaySiguiente(it)){
	if(iDef?(Siguiente(it), r1)) {
		DefinirLento(Siguiente(it), Obtener(Siguiente(it), r2), res);
	}else{
		Definir(Siguiente(it), Obtener(Siguiente(it), r2), res);
	}
	Avanzar(it);
}


iCoincideAlguno:

b = false;
it1 = CrearIt(r1);
while(HaySiguiente(it1) && !b){
	if(Obtener(Siguiente(it1), r1) == Obtener(Siguiente(it1), r2) ){
		b = true;
	}
	Avanzar(it);
}
res = b;


iCoincidenTodos:

b = true;
it1 = CrearIt(cc);
while(HaySiguiente(it1) && b){
	if(Obtener(Siguiente(it1), r1) != Obtener(Siguiente(it1), r2)){
		b = false;
	}
	Avanzar(it1);
}
res = b;




iDiferenciaSimetrica;

res = vacio();
ItConj(campo) it = CrearIt(campos(r2));
while(HaySiguiente(i)){
	if(!(Pertenece(Campos(r1), Siguiente(i)))){
		Agregar(res, Siguiente(i));
	}
	Avanzar(it);
}





TABLA




iNuevaTabla:

string c = Default;
int m = 0;
string str = vacio();
res = < 0, < c, m, m, vacio() >, < c, str, str, vacio() >, < false, false >, s, claves, columnas, vacio() >;




iAgregarRegistro:

AgregarAtras(mt.registros, r);
itLista(registro) it = CrearItUlt(mt.registros);
Retroceder(it);
if(mt.IndicesUsados.Nat){
	int n = Obtener(mt.indiceN.campo, r);
	if(!(MenorOIgual(mt.indiceN.minimo, n))){
		mt.indiceN.minimo = n;
	}
	if(MenorOIgual(mt.indiceN.maximo, n)){
		mt.indiceN.maximo = n;
	}
	if(Definido?(mt.indiceN.regpordato, n)){
		AgregarAtras(Obtener(mt.indiceN.regpordato, n), < it, CrearIt(Vacia()) > );
	}else{
		Definir(mt.indiceN.regpordato, n, AgregarAtras(Vacia(), < it, CrearIt(Vacia()) >));
	}
	if(mt.indicesUsados.String){
		itLista(apuntador) In = Retroceder(CrearItUlt(Obtener(mt.indiceN.regpordato, n)));
	}
}
if(mt.IndicesUsados.String){
	string s = Obtener(mt.indiceS.campo, r);
	if(!( MenorOIgual(mt.indiceS.minimo, s))){
		mt.indiceS.minimo = s;
	}
	if(MenorOIgual(mt.indiceS.maximo, s)){
		mt.indiceS.maximo = s;
	}
	if(Definido?(mt.indiceS.regpordato, s)){
		AgregarAtras(Obtener(mt.indiceS.regpordato, s), < it, CrearIt(vacio()) >);
	}else{
		Definir(mt.indiceS.regpordato, s, AgregarAtras(vacio(), < it, CrearIt(Vacio()) >));
	}
	if(mt.indicesUsados.Nat){
		itLista(apuntador) Is = Retroceder(CrearItUlt(Obtener(mt.indiceS.regpordato, s)));
	}
}
if(mt.indicesUsados.Nat && mt.indicesUsados.Str){
	Siguiente(Is).compadre = In;
	Siguiente(In).compadre = Is;
}
mt.modificaciones++;



iBorrarRegistro:

t.modificaciones++;
typename Dicc<Campo,Dato>::Iterador j = crit.DameDic().CrearIt();
Campo c = j.SiguienteClave();
Dato d = j.SiguienteSignificado();
if(Nat?(d) == tipoCampo(c, t) ){
	if(t.indicesUsados.nat && t.indiceN.campo == c){
		typename DiccLog<K,S>::ItLog it = Buscar(t.indiceN.regpordato, d);
	}
	if(it.SiguienteClave() == d){
		if(t.indicesUsados.str){
			String s = obtener(t.indiceS.campo, (it.SiguienteSignificado()).reg.Siguiente());
		}
		typename Lista<apuntador>::Iterador itl = it.SiguienteSignificado().CrearIt();
		(itl.Siguiente().reg).EliminarSiguiente();
		if(t.indicesUsados.str){
			itl.Siguiente().compadre.EliminarSiguiente();
			if(Pertenece?(claves(t), indiceS.campo) || Longitud(Obtener(indiceS.regpordato, s)) == 1){
				Borrar(indiceS.regpordato, s);
			}
		}
		Borrar(indiceN.regpordato, d);
		if(mt.indiceN.maximo == d){
			mt.indiceN.maximo = Maximo(mt.indiceN.regpordato);
		}
		if(mt.indiceN.minimo == d){
			mt.indiceN.minimo = Minimo(mt.indiceN.regpordato);
		}
	}
}else{
	if(t.indicesUsados.str && t.indiceS.campo == c){
		typename DiccLog<S>::ItLog it = Buscar(t.indiceN.regpordato, d);
		if(it.SiguienteClave() == d){
			if(t.indicesUsados.nat){
				Nat n = Obtener(t.indiceN.campo, it.SiguienteSignificado().reg.Siguiente());
			}
			typename Lista<apuntador>::Iterador itl = it.SiguienteSignificado().CrearIt();
			itl.Siguiente().reg.EliminarSiguiente();
			if(t.indicesUsados.nat){
				itl.Siguiente().compadre.EliminarSiguiente();
				if(Pertenece?(claves(t), indiceN.campo) || Longitud(Obtener(indiceN.regpordato, n)) == 1){
					Borrar(mt.indiceN.regpordato, n);
				}
			}
			Borrar(indiceS.regpordato, d);
			if(mt.indiceS.maximo == d){
				mt.indiceS.maximo = Maximo(mt.indiceS.regpordato);
			}
			if(mt.indiceS.minimo == d){
				mt.indiceS.minimo = Minimo(mt.indiceS.regpordato);
			}
		}
	}else{
		BuscarYBorrar(crit, mt);
	}
}


BuscarYBorrar:

typename Lista<registro>::Iterador rs = mt.registros.CrearIt();
while(rs.HaySiguiente() && !(Obtener(rs.Siguiente(), c) == d)) {
	rs.Avanzar();
}
if(mt.indicesUsados.nat || mt.indicesUsados.str){
	if(mt.indicesUsados.nat){
		ls = Obtener(Obtener(rs.Siguiente(), mt.indiceN.campo), mt.indiceN.regpordato);
		fa = ls.CrearIt();
		while(fa.HaySiguiente() && Obtener(fa.Siguiente().reg.Siguiente(), c) == d){
			fa.Avanzar();
		}
		m = Significado(fa.Siguiente().reg.Siguiente(), mt.indiceN.campo);
		fa.reg.EliminarSiguiente();
		if(Longitud(Obtener(Obtener(rs.Siguiente(), mt.indiceN.campo))) == 0){
			Borrar(mt.indiceN.regpordato, Obtener(fa.Siguiente().reg.Siguiente(), mt.indiceN.campo));
		}
		if(mt.indiceN.maximo == m){
			mt.indiceN.maximo = Maximo(mt.indiceN.regpordato);
		}
		if(mt.indiceN.minimo == m){
			mt.indiceN.minimo = Minimo(mt.indiceN.regpordato);
		}
	}
	if(mt.indicesUsados.str){
		ts = Obtener(Obtener(rs.Siguiente(), mt.indiceS.campo), mt.indiceS.regpordato);
		fu = ts.CrearIt();
		while(fu.HaySiguiente() && Obtener(fu.Siguiente().reg.Siguiente(), c) == d){
			fu.Avanzar();
		}
		n = Significado(fu.Siguiente().reg.Siguiente(), mt.indiceS.campo);
		fu.reg.EliminarSiguiente();
		if(Longitud(Obtener(Obtener(rs.Siguiente(), mt.indiceS.campo))) == 0){
			Borrar(mt.indiceS.regpordato, Obtener(fu.Siguiente().reg.Siguiente(), mt.indiceS.campo));
		}
		if(mt.indiceS.maximo == n){
			mt.indiceS.maximo = Maximo(mt.indiceS.regpordato);
		}
		if(mt.indiceS.minimo == n){
			mt.indiceS.minimo = Minimo(mt.indiceS.regpordato);
		}
	}
}else{
	rs.EliminarSiguiente();
}


iIndexar:

typename Dicc<Campo,Dato>::Iterador it = mt.registros.CrearIt();
int min = Significado(it, c);
int max = Significado(it, c);
if(TipoCampo(c, mt)){
	mt.indicesUsados.nat = true;
	mt.indiceN.campo = c;
	while(it.HaySiguiente()){
		if(!(MenorOIgual(min, Significado(it, c)))){
			Dato min = Significado(it,c);
		}
		if(MenorOIgual(max, Significado(it, c))){
			Dato max = Significado(it, c);
		}
		if(Definido?(mt.indiceN.regpordato, Significado(it, c))){
			AgregarAtras(Obtener(mt.indiceN.regpordato, Significado(it,c)), < it, Vacia().CrearIt() >);
		}else{
			Agregar(mt.indiceN.regpordato, Significado(it, c), < it, Vacia().CrearIt() >);
		}
		if(mt.indicesUsados.str){
			typename Lista<apuntador>::Iterador In = Retroceder(Obtener(mt.indiceN.regpordato, Significado(it, c)).CrearItUlt());
			Is = Obtener(mt.indiceS.regpordato, Significado(it, c)).CrearIt();
		}
		while(Obtener(Is.Siguiente().reg.Siguiente(), indiceS.campo) != Significado(it, c)){
			Is.Avanzar();
		}
		Is.Siguiente().compadre = In;
		In.Siguiente().compadre = Is;
	}
}else{
	mt.indicesUsados.str = true;
	mt.indiceS.campo = c;
	while(it.HaySiguiente()){
		if(!(MenorOIgual(min, Significado(it, c)))){
			Dato min = Significado(it, c);
		}
		if(MenorOIgual(max, Significado(it, c))){
			Dato max = Significado(it, c);
		}
		if(Definido?(mt.indiceS.regpordato, Significado(it, c))){
			AgregarAtras(Obtener(mt.indiceS.regpordato, Significado(it, c)), < it, Vacia().CrearIt() >);
		}else{
			Agregar(mt.indiceS.regpordato, Significado(it, c), < it, Vacia().CrearIt() > );
		}
		if(mt.indicesUsados.nat){
			typename Lista<apuntador>::Iterador Is = Retroceder(Obtener(mt.indiceS.regpordato, Significado(it, c)).CrearItUlt()); 
			In = Obtener(mt.indiceN.regpordato, Significado(it, c)).CrearIt();
			while(Obtener(In.Siguiente().reg.Siguiente() != Significado(it, c)){
				In.Avanzar();
			}
			In.Siguiente().compadre = Is;
			Is.Siguiente().compadre = In;
		}
		it.Avanzar();
	}
	mt.indiceS.minimo = min;
	mt.indiceS.maximo = max;
}




iMismosTipos, chequeár dónde tiene que estar esta función porque nunca usamos la tabla:

typename Dicc<Campo,Dato>::Iterador it1 = r.CrearIt();
while(it1.HaySiguiente() && (TipoCampo(it1.SiguienteClave(), t) == Nat?(it1.SiguienteSignificado()))){
	it1.Avanzar();
}
bool res = !(it1.HaySiguiente());




iDameColumna:

Conj<Dato> res = vacio();
Lista< Dicc<Campo, Dato> > it = cr.CrearIt();
while(it.HaySiguiente()){
	Agregar(res, Significado(c, it.Siguiente()));
	it.Avanzar();
}





iBuscarT:

typename Dicc<Campo,Dato>::Iterador it = crit.CrearIt();
while(it.HaySiguiente() && Def?(it.SiguienteClave(), t.columnas) && (Nat?(it.SiguienteSignificado()) == tipoCampo(it.SiguienteClave(), t))){
	it.Avanzar();
}
Lista<Registro> res = vacio();
Conj<Campo> cs = campos(crit);
if(!(it.HaySiguiente()) ){
	if(t.indicesUsados.nat == true && Pertenece?(t.indiceN.campo, cs)){
		typename DiccLog< Nat, Lista<Apuntador> >::ItLog ir = Buscar(t.indiceN.regpordato, n);
		typename Lista<apuntador>::Iterador i = ir.SiguienteSignificado().CrearIt(); 
		while(i.HaySiguiente()){
			if(CoincidenTodos(i.Siguiente().res.Siguiente(), cs, crit)){
				AgregarRapido(res, i.Siguiente().res.Siguiente();
			}
			i.Avanzar();
		}
	}else{
		if(t.indicesUsados.str == true && Pertenece?(t.indiceS.campo, cs)){
			typename DiccStr< Conj<ItLista(registro)> >::ItStr ir = Buscar(t.indiceS.regpordato, ****);
			typename Lista< itLista<registro> >::Iterador i = ir.SiguienteSignificado().CrearIt(); 
			while(i.HaySiguiente()){
				if(CoincidenTodos(i.Siguiente().reg.Siguiente(), cs, crit)){
					AgregarRapido(res, i.Siguiente().reg.Siguiente());
				}
				i.Avanzar();
			}
		}else{
			typename Lista< Registro >::Iterador i = t.registros.CrearIt(); 
			while(i.HaySiguiente()){
				if(CoincidenTodos(i.Siguiente(), cs, crit)){
					AgregarRapido(res, i.Siguiente());
				}
				i.Avanzar();
			}
		}
	}
}




iEsta:

if(!(compatible(r,t))){
	bool res = false;
}else{
	if(mt.indicesUsados.nat == true || mt.indicesUsados.str == true){
		if(mt.indicesUsados.nat && Pertenece?(mt.claves, mt.indiceN.campo)){
			if(Definido?(mt.indiceN.regpordato, Obtener(mt.indiceN.campo, r))){
				res = (r == primero(Significado(mt.indiceN.regpordato).reg.Siguiente() );
			}
		}
		if(mt.indicesUsados.string && Pertenece?(mt.claves, mt.indiceN.campo))){
			if(Definido?(mt.indiceS.regpordato, Obtener(mt.indiceS.campo, r))){
				res = (r == primero(Siguiente(Significado(mt.indiceS.regpordato).reg.Siguiente() );
			}
		}
	}else{
		typename Lista<Registro>::Iterador i = mt.registros.CrearIt(); 
		res = false;
		while(i.HaySiguiente()){
			res = (res || (i.Siguiente() == r));
			i.Avanzar();
		}
	}
}










iCombinarRegistros;

Lista<Registro> res = vacio();
typename Dicc<Campo,Dato>::Iterador it = Registros(t1).CrearIt();
while(it.HaySiguiente()){
	Dato valor = Obtener(it.HaySiguiente(), c);
	Registro crit = Definir(c, d, vacio());
	typename Lista<Registro>::Iterador Ic = BuscarT(t2, crit).CrearIt(); 
	while(Ic.HaySiguiente()){
		Agregar(res, AgregarCampos(it.Siguiente(), Ic.Siguiente()));
	}
}					//no explotan ambos ciclos????






ABB:


iDefinir:

if(esVacio?(p)){
	t = < NULL, c, s, NULL, NULL >;
}else{
	AgregarComoSiguiente(Buscar(p,n), n, s);
}



iMinimo:

puntero(nodoAB(K, S)) a = p;
while(a->izq != NULL){
	a = a->izq;
}
res = a->clave;


iMaximo:

puntero(nodoAB(K, S)) a = p;
while(a->der != NULL){
	a = a->der;
}
res = a->clave;




iBuscar:

res = CrearIt(p);
res.busca = true;
while(HaySiguiente(res) && SiguienteClave(res) != c){
	res.anterior = res.siguiente;
	if(SiguienteClave(res) < c){
		res.siguiente = res.siguiente->der;
	}else{
		res.siguiente = res.siguiente->izq;
	}
}





iEliminarHoja:

if(!esVacia?(i.recorrido)){
	i.siguiente = Tope(i.recorrido);
	i.anterior = i.siguiente->padre;
	Desapilar(i.recorrido);
}



iEliminarRaiz:

if(i.sigiente->der != NULL && i.siguiente->izq != NULL){
	(i.siguiente->izq).padre = i.siguiente->der;
	(i.siguiente->der)->izq = i.sigiente->izq;
	i.siguiente = i.siguiente->der;
}else{
	if(i.siguiente->der != NULL){
		i.siguiente = i.siguiente->der;
	}else{
		i.siguiente = i.siguiente->izq;
	}
}





iEliminarConUnHijo:

puntero(nodoAB(K, S)) temp = i.siguiente;
if(i.siguiente->der != NULL){
	(temp->izq).padre = i.anterior;
	if(i.anterior->der == i.siguiente){
		i.anterior->der = temp->izq;
	}else{
		i.anterior->izq = temp->izq;
	}
	i.siguiente = temp->izq;
}else{
	if(i.anterior->der == i.siguiente){
		i.anterior->der = temp->der;
	}else{
		i.anterior->izq = temp->der;
	}
	i.siguiente = temp->der;
}
temp = NULL;


EliminarSiguiente:

if(i.siguiente->der != NULL && i.siguiente->izq != NULL){
	EiminarHoja(i);
}else{
	if(i.anterior != NULL){
		if((i.siguiente->der == NULL && i.siguiente->izq != NULL) || (i.siguiente->der != NULL && i.siguiente->izq == NULL)){
			EliminarConUnHijo(i);
		}else{
			puntero(nodoAB(K, S)) temp = i.siguiente;
			puntero(nodoAB(K, S)) rec = temp->der;
			while(rec.izq != NULL){
				rec = rec->izq;
			}
			temp->clave = rec->clave;
			temp->significado = rec->significado;
			if(red->der == NULL){
				EliminarHoja(Buscar(*i.abb, rec->clave));
			}else{
				EliminarConUnHijo(Buscar(*i.abb, rec->clave));
			}
			temp = NULL;
		} 
	}else{
		EliminarRaiz(i);
	}
}




iAgregarComoSiguiente:

nodoAB(K, S) n = < i.anteror, c, s, NULL, NULL >;
if(i.anterior->clave > c){
	i.anterior->der = &n;
}else{
	i.anterior->izq = &n;
}
i.siguiente = &n;





iAvanzar:

if(i.busca){
	iter it = i;
	while(it.anterior != NULL){
		it.siguiente = it.anterior;
		it.anteror = it.anterior->padre;
	}
	while(it.siguiente->clave != i.siguiente->clave){
		if(it.siguiente->der != NULL){
			Apilar(it.recorrido, it.siguiente->der);
		}
		if(it.siguiente->izq != NULL){
			Apilar(it.recorrido, it.siguiente->izq);
		}
		it.siguiente = Tope(it.recorrido);
		it.anterior = it.siguiente->padre;
		Desapilar(it.recorrido);
	}
	i = it;
	i.busca = false;
}
if(i.siguiente->der != NULL){
	Apilar(i.recorrido, i.siguiente->der);
}
if(i.siguiente->izq != NULL){
	Apilar(i.recorrido, i.siguiente->izq);
}
if(EsVacia?(i.recorrido)){
	i.anterior = i.siguiente;
	i.siguiente = NULL;
}else{
	i.siguiente = Tope(i.recorrido);
	i.anterior = i.siguiente->padre;
	Desapilar(i.recorrido);
}



DICCTRIE



iMinimo:

ItStr(S) i = CrearIt(p);
while(!ApuntaAHoja(i)){
	Avanzar(i);
}
res = i.clave;



iMaximo:

puntero(nodo(S)) a = p;
res = Vacia();
while(p != NULL){
	int k = 255;
	while(j > 0 && a->caracteres[j] == NULL){
		j--;
	}
	AgregarAtras(res, ord^-1(j));  //ord^-1 WTF
	a = a->caracteres[j];
}




iEliminarSiguiente:

i.siguiente->significado = NULL;
while(ApuntaAHoja(i) && i.siguiente->significado == NULL && i.anterior != NULL){
	int j = ord(Ultimo(i.clave));
	i.anterior[j] = NULL;
	i.siguiente = i.anterior;
	i.anterior = i.anterior->padre;
}
if(EsVacia?(i.recorrido)){
	i.anterior = i.siguiente;
	i.siguiente = NULL;
}else{
	i.siguiente = Tope(i.recorrido).sig;
	i.clave = Tope(i.recorrido).clave;
	i.anterior = i.siguiente->padre;
	Desapilar(i.recorrido);
}






iApuntaAHoja:

res = true;
int j = 255;
while(j > 0 && res){
	res = (i.siguiente->recorrido[j] == NULL);
	j--;
}



iAgregarComoSiguiente:

puntero(S) p = &s;
if(c == i.clave){
	i.siguiente->significado = p;
}else{
	int j = 0;
	while(c[j] != Ultimo(i.clave)){
		j--;
	}
	arreglo(puntero(nodo(S))) a[256];
	nodo(S) n = < NULL, a, i.anterior >;
	i.anterior->caracteres[j] = &n;
	i.siguiente = n;
	j++;
	while(j < Longitud(c)){
	arreglo(puntero(nodo(S))) b[256];
	nodo(S) n = < NULL, b, i.anterior >;
	i.anterior->caracteres[j] = &n;
	i.anterior = i.siguiente;
	i.siguiente = n;
	j++;
	}
	i.clave = Copiar(c);
	i.siguiente->significado = p;
}





iAvanzar:

if(i.busca){
	iter it = i;
	while(it.anterior != NULL){
		it.siguiente = it.anterior;
		it.anterior = it.anterior->padre;
	}
	while(it.clave != i.clave){
		int j = 256;
		while(j >= 0){
			if(i.siguiente->caracteres[j] != NULL){
				string nuevaclave = Copiar(i.clave);
				Apilar(i.recorrido, < i.siguiente->caracteres[j], Agregar(nuevaclave, ord^-1(j)) >);   //ord^-1 WTF
			}
		}
		it.siguiente = Tope(it.recorrido).sig;
		it.clave = Copiar(Tope(it.recorrido).clave);
		it.anterior = it.siguiente->padre;
		Desapilar(it.recorrido);
	}
	i = it;
	i.busca = false;
}
j = 256;
while(j >= 0){
	if(i.siguiente->caracteres[j] != NULL){
		string nuevaclave = Copiar(i.clave);
		Apilar(i.recorrido, < i.siguiente->caracteres[j], Agregar(nuevaclave, ord^-1(j)) >);	//ord^-1 WTF
	}
}
if(EsVacia?(i.recorrido)){
	i.anterior = i.siguiente;
	i.siguiente = NULL;
}else{
	while(Tope(i.recorrido).sig->significado == NULL && !EsVacia?(i.recorrido)){
		Desapilar(i.recorrido);
	}
	if(EsVacia?(i.recorrido)){
		i.anterior = i.siguiente;
		i.siguiente = NULL;
	}else{
		i.siguiente = Tope(i.recorrido);
		i.anterior = i.siguiente->padre;
		Desapilar(i.recorrido);
	}
}






BASE DE DATOS


iTablas:

res = Vacio();

typename DiccStr< >::ItStr i = a.TporNombre.CrearIt();
while(i.HaySiguiente()){
	Agregar(res, i.SiguienteClave());
}



iNuevaBD:

res.tabla = Vacio();
res.TporNombre = Vacio();
res.nombres = Vacio();
res.tablaMax = Vacio().CrearIt();
res.joins = Vacio();
res.LosJoins = Vacia();



iAgregarTabla:

AgregarRapido(a.tablas, mt);
typename Conj<Tabla>::Iterador i = a.tablas.CrearIt();
while(i.HaySiguiente() && i.Siguiente != mt){
	i.Avanzar();
}
Definir(a.TporNombre, nombre(mt), i);
AgregarRapido(a.nombres, nombre(mt));
if(a.tablas == vacio()){
	a.TablaMax = i;
}else{
	if(CantidadAccesos(nombre(mt), a) > CantidadAccesos(nombre(a.TablaMax.Siguiente()), a)){
		a.TablaMax = i;
	}
}



iInsertarEntrada:

typename DiccStr< >::ItStr i = Buscar(a.TporNombre, t);
AgregarRegistro(i.Siguiente(), r);
if(CantidadAccesos(Obtener(a.TporNombre, t).Siguiente(), a) > CantidadAccesos(a.TablaMax.Siguiente(), a)){
	a.TablaMax = Obtener(a.TporNombre, t);
}
if(Definido?(a.joins, t)){
	typename DiccStr< >::ItStr it = Obtener(a.TporNombre, t).CrearIt();
	while(it.HaySiguiente()){
		AgregarAdelante(it.SiguienteSignificado().cambios, < t, r >);
		if(HayJoin(it.SiguienteClave(), t, a)){
			AgregarAdelante(Obtener(Obtener(a.joins, it.SiguienteClave()), t).cambios, < t, r >);
		}
		it.Avanzar();
	}
}





iBorrar:

typename DiccStr< >::ItStr i = Buscar(a.TporNombre, t);
BorrarRegistro(i.SiguienteSignificado(), r);
if(CantidadAccesos(Significado(a.TporNombre, t).Siguiente(), a) > CantidadAccesos(a.tablaMax.Siguiente(), a)){
	a.TablaMax = Obtener(a.TporNombre, t);
}
if(Definido?(a.joins, t)){
	typename DiccStr< >::ItStr it = Obtener(a.joins, t).CrearIt();
	while(it.HaySiguiente()){
		AgregarAdelante(it.SiguienteSignificado().cambios, < t, r >);
		if(HayJoin(it.SiguienteClave(), t, a)){
			AgregarAdelante(Obtener(Obtener(a.joins, it.SiguienteClave(), t).cambios), < t, r >);
		}
		it.Avanzar();
	}
}





iGenerarVistaJoin:

Conj<Registro> rs = combinarRegistros(ca, t1, t2);
typename Registro::Iterador it = rs.CrearIt();
nt = NuevaTabla("nuevat", Agregar(Vacio(), it.campos()));
Indexar(ca, nt);
while(it.HaySiguiente()){
	AgregarRegistro(it.Siguiente, nt);
}
AgregarAdelante(nt, a.LosJoins);
typename DiccStr< >::ItStr it2 = a.LosJoins.CrearIt();
res = Registros(it2.Siguiente()).CrearIt();
if(!Definido?(a.joins, t1)){
	DiccString<Join> d = Definir(Vacio(); t2, < ca, <>, it2 >);
	Definir(a.joins, t1, d);
}else{
	Definir(Significado(a.joins, t1), t2, < ca, <>, it2 >);
}




iVistaJoin:

tab = Obtener(Obtener(a.Joins, t1), t2).Siguiente().verJoin;
typename Lista::Iterador itC = Obtener(Obtener(a.Joins, t1), t2).cambios.CrearItUlt();
Registro crit = Vacio();
String ca = CampoJoin(t1, t2, a);
while(itC.HayAnterior()){
	dato d = Obtener(ca, itC.Anterior().regmod);
	Definir(ca, d, crit);
	if(itC.Anterior().tabmod.Esta(itC.Anterior().regmod)){
		if(itC.Anterior().tabmod == t1){
			if(!EsVacio(Buscar(crit, t2, a))){
				itB2 = Buscar(crit, t2, a).CrearIt();
				registro reg1 = AgregarCampos(itC.Anterior().regmod, itB2.Siguiente());
				AgregarRegistro(reg1, tab);
			}
		}else{
			if(!EsVacio(Buscar(crit, t1, a))){
				itB1 = Buscar(crit, t1, a).CrearIt();
				registro reg2 = AgregarCampos(itC.Anterior().regmod, itB1.Siguiente());
			}
			AgregarRegistro(reg2, tab);
		}
	}else{
		if(!EsVacio?(BuscarT(crit, tab))){
			Borrar(tab, crit);
		}
	}
	itC.Retroceder();
}
res = Registros(tab).CrearIt();