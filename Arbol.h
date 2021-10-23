#pragma once
#include "Nodo.h"

class Arbol
{
public:
	Arbol(const string nombre_del_nodo, float distancia_acumulada);
	~Arbol();
	Nodo* raiz_del_arbol;
	bool isIn(const string nombre_del_nodo_hijo, Nodo* nodo_actual, int flag = 0);
	bool insHijo(Nodo* padre, Nodo* hijo);
	void genera_camino_entre_un_nodo_y_la_raiz(Nodo* meta, string* camino, int& cantidad_en_camino); //debe devolver un arreglo con los saltos entre ciudades
};