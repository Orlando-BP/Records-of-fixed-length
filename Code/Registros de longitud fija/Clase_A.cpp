#include "Clase_A.h"
#include "Clase_B.h"
Clase_A::Clase_A()
{
	for (int i = 0; i < 20; i++) {
		Cadena[i]= '.';
	}
	Llave = -1;
	Contador_B = 5;
}

Clase_A::Clase_A(int key)
{
	int B;
	string C;
	Llave = key;
	cout << "Ingresa La cadena: " << endl;
	cin >> C;
	int size = C.length();
	for (int i = 0; i < 20; i++) {
		Cadena[i] = '.';
	}
	if (size < 20) {
		for (int i = 0; i < size; i++) {
			Cadena[i] = C[i];
		}
	}
	else {
		for (int i = 0; i < 20; i++) {
			Cadena[i] = C[i];
		}
	}
	
	cout << "Cuantos objetos de clase B quieres?: " << endl;
	cin >> B;
	if (B <= 5) {
		Contador_B = B;
	}
	else {
		Contador_B = 5;
	}
	for (int i = 0; i < Contador_B; i++) {
		double Double = 0;
		bool Bool = false;
		cout << "Objeto B# "<<i+1 << endl;
		cout << "Ingresa Double: " << endl;
		cin >> Double;
		cout << "Ingresa booleano 1 o 0: " << endl;
		cin >> Bool;
		Clase_B objB(Double, Bool);
		Obj_B[i] = objB;
	}

}

int Clase_A::DarLlave()
{
	return Llave;
}

int Clase_A::DarContadorB()
{
	return Contador_B;
}

void Clase_A::AumentarContB()
{
	Contador_B++;
}

void Clase_A::SetCadena()
{
	string C;
	cout << "Ingresa La nueva cadena: " << endl;
	cin >> C;
	int size = C.length();
	for (int i = 0; i < 20; i++) {
		Cadena[i] = '.';
	}
	if (size < 20) {
		for (int i = 0; i < size; i++) {
			Cadena[i] = C[i];
		}
	}
	else {
		for (int i = 0; i < 20; i++) {
			Cadena[i] = C[i];
		}
	}
}

void Clase_A::SetLlave(int key)
{
	Llave = key;
}

void Clase_A::SetObjB(Clase_B objB)
{
	Obj_B[Contador_B-1] = objB;
}

void Clase_A::Mostrar()
{
	stringstream ss;
	ss << "Nombre: ";
	for (int i = 0; i < 20; i++) {
		if(Cadena[i]!='.')
			ss << Cadena[i];
	}
	ss << endl << "Llave de registro: " << Llave << endl<< "--Objetos de clase_B--"<<endl;
	cout << ss.str();
	for (int i = 0; i < Contador_B; i++) {
		cout << "    Objeto_B #" << i + 1 << endl;
		Obj_B[i].Mostrar();
	}
	cout << endl;
}
