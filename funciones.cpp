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
	if(!(Pertenece?(Campos(r1), Siguiente(i)))){
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










