#include "Dato.h"
#include <iostream>
#include <string>
#include <cassert>
using namespace modulos;
using namespace std;


int main(){

	Dato n (30);
	Dato s ("a");
	Dato n2 (10);
	Dato s2 ("b");
	

	cout << s.MenorOIgual(s2) << endl;

	/*cout << "Bienvenido a la base de datos" << endl;
	cout << "-------------------------------------------------------------------------------------------------" << endl;
	cout << "Esto es un test para el modulo dato" << endl;
	cout << "Luego de 30 turnos en una partida de hearthstone donde se buffeo a C'thun.."<< endl;
	cout << "Su poder es:" << n.ValorNat() << endl;
	cout << "Mientras que " << s2.ValorStr() << endl;
	cout << "Quien gana?" << endl;
	cout << "El ganador es :" << 
*/
	return 0;
}