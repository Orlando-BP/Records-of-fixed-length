#pragma once
#include <iostream>
#include "Clase_B.h"

using namespace std;
class Clase_A
{
	char Cadena[20];
	int Llave;
	int Contador_B;
	Clase_B Obj_B[5];
public:
	Clase_A();
	Clase_A(int key);
	int DarLlave();
	int DarContadorB();
	void AumentarContB();
	void SetCadena();
	void SetLlave(int key);
	void SetObjB(Clase_B objB);
	void Mostrar();
};

