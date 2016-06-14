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
itDicc(campo, dato) j = crit.CrearIt(); 
campo c = j.SiguienteClave();
dato d = j.SiguienteSignificado();
if(Nat?(d) = tipoCampo(c, t) ){
	if(t.indicesUsados.Nat && t.indiceN.campo == c){
		itDiccLog() it = Buscar(t.indiceN.regpordato, d);   //***
	}
	if(it.SiguienteClave() == d){
		if(t.indicesUsados.String){
			String s = obtener(t.indiceS.campo, Siguiente(it.SiguienteSignificado().reg));   //***
		}
		ItLista(apuntador) itl = CrearIt(it.SiguienteSignificado());
		EliminarSiguiente(itl.Siguiente().reg);
		if(t.indicesUsados.String){
			EliminarSiguiente(itl.Siguiente().compadre);   //***
			if(Pertenece?(claves(t), indiceS.campo) || Longitud(Obtener(indiceS.regpordato, s)) == 1){
				Borrar(indiceS.regpordato, s);
			}
		}
		Borrar(indiceN.regpordato, d);
		if(mt.indiceN.maximo == d){
			mt.indiceN.maximo = Maximo(mt.indiceN.regpordat);
		}
		if(mt.indiceN.minimo == d){
			mt.indiceN.minimo = Minimo(mt.indiceN.regpordato);
		}
	}
}else{
	if(t.indicesUsados.String && t.indiceS.campo == c){
		ItDiccString() it = Buscar(t.indiceS.regpordato, d);    //*****
		if(it.SiguienteClave() == d){
			if(t.indicesUsados.Nat){
				Nat n = Obtener(t.indiceN.campo, Siguiente(it.SiguienteSignificado().reg));
			}
			itLista(apuntador) itl = CrearIt(it.SiguienteSignificado());
			EliminarSiguiente(itl.Siguiente().reg);
			if(t.indicesUsados.Nat){
				EliminarSiguiente(itl.Siguiente().compadre));
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

itConj(registro) rs = CrearIt(mt.registros);
while(HaySiguiente(rs) && !(Obtener(Siguiente(rs), c) == d)) {
	Avanzar(rs);
}
if(mt.indicesUsados.Nat || mt.indicesUsados.String){
	if(mt.indicesUsados.Nat){
		ls = Obtener(Obtener(Siguiente(rs), mt.indiceN.campo), mt.indiceN.regpordato);
		fa = CrearIt(ls);
		while(HaySiguiente(fa) && Obtener(Siguiente(Siguiente(fa).reg), c) == d){
			Avanzar(fa);
		}
		m = Significado(Siguiente(Siguiente(fa).reg), mt.indiceN.campo);
		EliminarSiguiente(fa.reg);
		if(Longitud(Obtener(Obtener(Siguiente(rs), mt.indiceN.campo))) == 0){
			Borrar(mt.indiceN.regpordato, Obtener(Siguiente(Siguiente(fa).reg), mt.indiceN.campo));
		}
		if(mt.indiceN.maximo == m){
			mt.indiceN.maximo = Maximo(mt.indiceN.regpordato);
		}
		if(mt.indiceN.minimo == m){
			mt.indiceN.minimo = Minimo(mt.indiceN.regpordato);
		}
	}
	if(mt.indicesUsados.String){
		ts = Obtener(Obtener(Siguiente(rs), mt.indiceS.campo), mt.indiceS.regpordato);
		fu = CrearIt(ts);
		while(HaySiguiente(fu) && Obtener(Siguiente(Siguiente(fu).reg), c) == d){
			Avanzar(fu);
		}
		n = Significado(Siguiente(Siguiente(fu).reg), mt.indiceS.campo);
		EliminarSiguiente(fu.reg);
		if(Longitud(Obtener(Obtener(Siguiente(rs), mt.indiceS.campo))) == 0){
			Borrar(mt.indiceS.regpordato, Obtener(Siguiente(Siguiente(fu).reg), mt.indiceS.campo));
		}
		if(mt.indiceS.maximo == n){
			mt.indiceS.maximo = Maximo(mt.indiceS.regpordato);
		}
		if(mt.indiceS.minimo == n){
			mt.indiceS.minimo = Minimo(mt.indiceS.regpordato);
		}
	}
}else{
	EliminarSiguiente(rs);
}


iIndexar:

itLista(Dicc(campo, dato)) it = mt.registros.CrearIt();
int min = Significado(it, c);
int max = Significado(it, c);
if(TipoCampo(c, mt)){
	mt.indicesUsados.Nat = true;
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
		if(mt.indicesUsados.String){
			itLista(apuntador) In = Retroceder(CrearItUlt(Obtener(mt.indiceN.regpordato, Significado(it, c)))); //****
			Is = CrearIt(Obtener(mt.indiceS.regpordato), Significado(it, c));  //****
		}
		while(Obtener(Siguiente(Siguiente(Is).reg), indiceS.campo) != Significado(it, c)){
			Avanzar(Is);
		}
		Siguiente(Is).compadre = In;
		Siguiente(In).compadre = Is;
	}
}else{
	mt.indicesUsados.String = true;
	mt.indiceS.campo = c;
	while(HaySiguiente(it)){
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
		if(mt.indicesUsados.Nat){
			itLista(apuntador) Is = Retroceder(CrearItUlt(Obtener(mt.indiceS.regpordato, Significado(it, c))));
			In = CrearIt(Obtener(mt.indiceN.regpordato, Significado(it, c)));
			while(Obtener(Siguiente(Siguiente(In).reg), indiceN.campo) != Significado(it, c)){
				Avanzar(In);
			}
			Siguiente(In).compadre = Is;
			Siguiente(Is).compadre = In;
		}
		Avanzar(it);
	}
	mt.indiceS.minimo = min;
	mt.indiceS.maximo = max;
}




iMismosTipos, chequeár dónde tiene que estar esta función porque nunca usamos la tabla:

itDicc(campo, dato) it1 = r.CrearIt();
while(it1.HaySiguiente() && (TipoCampo(it1.SiguienteClave(), t) == Nat?(it1.SiguienteSignificado()))){
	Avanzar(it);
}
bool res = !(HaySiguiente(it1));




iDameColumna:

conj(Dato) res = vacio();
Conj(Dicc(campo, clave)) it = cr.CrearIt();
while(it.HaySiguiente()){
	Agregar(res, Significado(c, it.Siguiente()));
	it.Avanzar();
}





iBuscarT:

itDicc(campo, dato) it = crit.CrearIt();
while(it.HaySiguiente() && Def?(it.SiguienteClave(), t.columnas) && (Nat?(SiguienteSignificado(it)) == tipoCampo(SiguienteClave(it), t))){
	Avanzar(it);
}
conj(registro) res = vacio();
conj(campo) cs = campos(crit);
if(!(HaySiguiente(it))){
	if(t.indicesUsados.Nat == true && Pertenece?(t.indiceN.campo, cs)){
		ItLog(nat, Lista(apuntador)) i = Buscar(t.indiceN.regpordato, n);
		ItLista(apuntador) I = i.SiguienteSignificado().CrearIt();
		while(I.HaySiguiente()){
			if(CoincidenTodos(Siguiente(I.Siguiente().res), cs, crit)){
				AgregarRapido(res, Siguiente(I.Siguiente().res));
			}
			I.Avanzar();
		}
	}else{
		if(t.indicesUsados.String == true && Pertenece?(t.indiceS.campo, cs)){
			ItStr(conj(ItLista(registro))) ir = Buscar(t.indiceS.regpordato, ****);
			ItLista(itLista(registro)) I = CrearIt(SiguienteSignificado(ir));
			while(I.HaySiguiente()){
				if(CoincidenTodos(Siguiente(I.Siguiente().reg), cs, crit)){
					AgregarRapido(res, Siguiente(I.Siguiente().reg));
				}
				Avanzar(I);
			}
		}else{
			ItLista(registro) I = CrearIt(t.registros);
			while(HaySiguiente(I)){
				if(CoincidenTodos(Siguiente(I), cs, crit)){
					AgregarRapido(res, Siguiente(I));
				}
				Avanzar(I);
			}
		}
	}
}




iEsta:

if(!(compatible(r,t))){
	bool res = false;
}else{
	if(mt.indicesUsados.Nat == true || mt.indicesUsados.String == true){
		if(mt.indicesUsados.Nat && Pertenece?(mt.claves, mt.indiceN.campo)){
			if(Definido?(mt.indiceN.regpordato, Obtener(mt.indiceN.campo, r))){
				res = (r == primero(Siguiente(Significado(mt.indiceN.regpordato))).reg);
			}
		}
		if(mt.indicesUsados.String && Pertenece?(mt.claves, mt.indiceN.campo))){
			if(Definido?(mt.indiceS.regpordato, Obtener(mt.indiceS.campo, r))){
				res = (r == primero(Siguiente(Significado(mt.indiceS.regpordato))).reg);
			}
		}
	}else{
		ItReg() i = mt.registros.CrearIt();
		res = false;
		while(i.HaySiguiente()){
			res = (res || (i.Siguiente() == r));
			i.Avanzar();
		}
	}
}










iCombinarRegistros;

conj(registro) res = vacio();
ItConj(Dicc(campo, dato)) it = CrearIt(Registros(t1));
while(it.HaySiguiente()){
	dato valor = Obtener(HaySiguiente(it), c);
	registro crit = Definir(c, d, vacio());
	ItConj(registro) Ic = CrearIt(BuscarT(t2, crit));
	while(Ic.HaySiguiente()){
		Agregar(res, AgregarCampos(it.Siguiente(), Ic.Siguiente()));
	}
}					//no explotan ambos ciclos????








