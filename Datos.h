#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Agenda.h"
#include "Arbol.h"

using namespace std;

typedef class CAMPOS* PCAMPOS;

class CAMPOS
{
public:
	string nombre_estado1;
	string nombre_estado2;
	float distancia = 0.0f;
};

class Datos
{
protected:
	void buscar_conexiones(const string ciudad, string* ciudades_conexion, float* distancia, int& cant_hijos);
	void buscar_conexiones(const string ciudad, string* ciudades_conexion, float* distancia, int& cant_hijos, string ciudad_a_evitar);
	PCAMPOS datos;
	int cantidad_datos;
public:
	Datos(int cantidad_conexiones);
	~Datos();
	void load(string pPath);
	void dijkstra(string ciudad_origen, string ciudad_destino);
	void dijkstra_evitar_ciudad(string ciudad_origen, string ciudad_destino, string ciudad_a_evitar);
	void dijkstra_ciudad_escala(string ciudad_origen, string ciudad_destino, string ciudad_escala);
};