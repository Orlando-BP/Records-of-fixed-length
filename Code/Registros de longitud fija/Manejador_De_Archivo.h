#pragma once
#include <iostream>
#include <fstream>
#include "Clase_A.h"
using namespace std;
class Manejador_De_Archivo
{
	Clase_A obj;
public:
	Manejador_De_Archivo();
	void CrearObjetoA();
	void insertarFinal();//listo
	void insertarInicio();//listo
	void Mostrar();//listo
	void MostrarUNO();//listo
	int Buscar(int key);
	void LlenarSecundario();
	void Eliminar();//listo
	void Modificar();//listo
	void MenuModificar();
	bool VerificarLlave(int key);
	void Menu();
};

