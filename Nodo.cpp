#include "Nodo.h"

Nodo::Nodo()
{
	distancia_acumulada = 0;
	cantidad_hijos = 0;
	padre = NULL;
	for (int i = 0; i < MAX_HIJOS; i++) {
		hijos[i] = NULL;
	}
}

Nodo::Nodo(const string nombre, float distancia_acumulada)
{
	Nodo::nombre = nombre;
	Nodo::distancia_acumulada = distancia_acumulada;
	cantidad_hijos = 0;
}

Nodo::~Nodo()
{

}