#include "Clase_B.h"

Clase_B::Clase_B()
{
	Double = -1;
	Boolean = false;
}

Clase_B::Clase_B(double D, bool B)
{
	Double = D;
	Boolean = B;
}

void Clase_B::Mostrar()
{
	stringstream ss;
	ss << "Valor Double: " << Double << endl << "Valor Booleano: " << Boolean << endl;
	cout << ss.str();
}
