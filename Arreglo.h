#pragma once

#define MAX 100
template <class T>

class Arreglo
{
private:
	T Datos[MAX];
	int tam;
	public;
	Arreglo();
	int RegresaTam();
	T RegresaVal(int);
	void AsignaValor(int, T);
	void Intercambia(int, int);
	void InterDirectoIzq();
	void InsercionDirecta();
	void SeleccionDirecta();
	void QuickSort();
	void Reduce(int, int);
	int InsertaDesordenado();
	void Lectura();
	void Escribir();
};

template <class T>
Arreglo<T>::Arreglo()
{
	tam = 0;
}

template <class T>
void Arreglo<T>::Intercambia(int, int Ind2)
{
	T Auxiliar;
	Auxiliar = Datos[Ind1];
	Datos[Ind1] = Datos[Ind2];
	Datos[Ind2] = Auxiliar;
}

template <class T>
void Arreglo<T>::InterDirectoIzq()
{
	int Ind1, Ind2;
	for (Ind1 = 1; Ind1 < tam; Ind1++)
		for (Ind2 = tam - 1; Ind2 >= Ind1; Ind2--)
			if (Datos[Ind2 - 1] > Datos[Ind2])
				Intercambia(Ind2 - 1, Ind2);
}

template <class T>
void Arreglo<T>::InsercionDirecta()
{
	int Auxiliar, Indice, IndAux;
	for (Indice = 1; Indice < tam; Indice++)
	{
		Auxiliar = Datos[Indice];
		IndAux = Indice - 1;
		while ((IndAux >= 0) && (Auxiliar < Datos[IndAux]))
		{
			datos[IndAux + 1] = Datos[IndAux];
			IndAux--;
		}
		Datos[IndAux + 1] = Auxiliar;
	}
}

template <class T>
void Arreglo<T>::SeleccionDirecta()
{
	int Menor, Ind1, Ind2, Ind3;
	for (Ind1 = 0; Ind1 < tam - 1; Ind1++)
	{
		Menor = Datos[Ind1];
		Ind2 = Ind1;
		for(Ind3 = Ind1+1; Ind3 < tam; Ind3++)
			if (Datos[Ind3] < Menor)
			{
				Menor = Datos[Ind3];
				Ind2 = Ind3;
			}
		Datos[Ind2] = Datos[Ind1];
		Datos[Ind1] = Menor;
	}
}

template <class T>
void Arreglo<T>::QuickSort()
{
	Reduce(0, tam - 1);
}

template <class T>
void Arreglo<T>::Reduce(int Inicio, int Fin)
{
	if (tam > 0)
	{
		int Izq, Der, Pos, Bandera;
		Izq = Inicio;
		Der = Fin;
		Pos = Inicio;
		Bandera = 1;
		while (Bandera)
		{
			Bandera = 0;
			while ((Datos[Pos] <= Datos[Der]) && (Pos != Der))
				Der--;
			if (Pos != Der)
			{
				Intercambia(Pos, Der);
				Pos = Der;
				while ((Datos[Pos] >= Datos[Izq]) && (Pos != Izq))
					Izq++;
				if (Pos != Izq)
				{
					Bandera = 1;
					Intercambia(Pos, Izq);
					Pos = Izq;
				}
			}
		}
		if ((Pos - 1) > Inicio)
			Reduce(Inicio, Pos - 1);
		if (Fin > (Pos + 1))
			Reduce(Pos + 1, Fin);
	}
}

template <class T>
int Arreglo<T>::InsertaDesordenado()
{
	int Pos, result = 1;
	if (tam < MAX)
	{
		pos = BuscaDesordenado(Valor);
		if (pos < 0)
			Datos[tam++] = Valor;
		else
			result = -1;
	}
	else
		result = 0;
	return result;
}