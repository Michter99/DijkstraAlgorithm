#pragma once
#include <iostream>
#define MAX_HIJOS 6

using namespace std;

class Nodo
{
public:
	Nodo();
	Nodo(const string nombre, float distancia_acumulada);
	~Nodo();

	string nombre;
	float distancia_acumulada;
	int cantidad_hijos;
	Nodo* padre;
	Nodo* hijos[MAX_HIJOS];
};