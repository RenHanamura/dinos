#pragma once
#include <istream>
#include <ostream>
#include <iostream>
#include "Arreglo.h"

#define MAX 100

class Dinos
{
private:
	int Clave;
	char Nombre[MAX], Tipo[MAX], Periodo[MAX];
public:
	Dinos();
	Dinos(int, char[], char[], char[]);
	int operator!= (Dinos);
	friend std::istream &operator>> (std::istream&, Dinos&);
	friend std::ostream &operator<< (std::ostream&, Dinos&);
	void main();
};

Dinos::Dinos()
{}

// Metodo constructor con parametros
Dinos::Dinos(int Clav, char Nom[], char Type[], char Per[])
{
	Clave = Clav;
	strcpy(Nombre, Nom);
	strcpy(Tipo, Type);
	strcpy(Periodo, Per);
}

// Sobrecarga de != para comparacion
int Dinos::operator!=(Dinos ObjD)
{
	if ((Clave != ObjD.Clave) || (strcmp(Nombre, ObjD.Nombre) != 0) || (strcmp(Tipo, ObjD.Tipo) != 0) || (strcmp(Periodo, ObjD.Periodo) != 0))
		return 1;
	else
		return 0;
}

// Sobrecarga de >> para la lectura
std::istream& operator>> (std::istream& Lee, Dinos& ObjDino)
{
	std::cout << "Ingresa la clave del dinosaurio:\n";
	Lee >> ObjDino.Clave;
	std::cout << "Ingresa el nombre del dinosaurio:\n";
	Lee >> ObjDino.Nombre;
	std::cout << "Que tipo de dinosaurio era? (Hervivoro, Carnivoro, Omnivoro)\nIngresa el tipo:\n";
	Lee >> ObjDino.Tipo;
	std::cout << "De que periodo era?\nIngresa su periodo:\n";
	Lee >> ObjDino.Periodo;
	return Lee;
}

// Sobrecarga de << para poder imprimir 
std::ostream& operator<< (std::ostream& Escribir, Dinos& ObjDino)
{
	Escribir << "Datos del dinosaurio:\n";
	Escribir << "Su clave de registro es: " << ObjDino.Clave;
	Escribir << "El nombre de la especie es: " << ObjDino.Nombre;
	Escribir << "El tipo de alimentacion que llevaba era: " << ObjDino.Tipo;
	Escribir << "El periodo en cual vivio fue: " << ObjDino.Periodo;
}

// Aqui va el menu XD
class Menu
{
public:
	Menu();
	int Mostrar();
};

Menu::Menu()
{}

int Menu::Mostrar()
{
	int op;
	do
	{
		std::cout << "Bienvenido al sistema de registro del DinoMuseo\n";
		std::cout << "Porfavor selecciona una dinopcion:\n";
		std::cout << "Que te gustaria Dinohacer?\n";
		std::cout << "1. Registrar un nuevo dino\n";
		std::cout << "2. Obtener un listado de todos los dinos habidos y por haber en este dinosistema\n";
		std::cout << "3. Salir del dinosistema\n";
		std::cin >> op;
	} while (op < 1 || op > 3);
	return op;
}

// Funcion para almacenar
void main()
{
	Arreglo<Dinos> Parque;
	Dinos ObjDino;
	Menu Opciones;
	int op, res;
	Parque.Lectura();
	op = Opciones.Mostrar();

	while (op >= 1 && op <= 2)
	{
		switch (op)
		{
		case 1:
		{
			std::cin >> ObjDino;
			res = Parque.InsertaDesordenado(ObjDino);
			if (res == 1)
				std::cout << "Dino registrado\n";
			else
				if (res == 0)
					std::cout << "Ijole al dinosistema no le queda dinoespacio\n";
				else
					std::cout << "Ese dino ya ha sido dinoregistrado\n";
				break;
		}
		case 2:
		{
			Parque.Escribir();
			break;
		}
		}
		op = Opciones.Mostrar();
	}
}