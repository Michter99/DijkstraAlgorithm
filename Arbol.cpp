#include "Arbol.h"

Arbol::Arbol(const string nombre_del_nodo, float distancia_acumulada)
{
	raiz_del_arbol = new Nodo(nombre_del_nodo, distancia_acumulada);
	raiz_del_arbol->padre = NULL;
}


Arbol::~Arbol()
{
	raiz_del_arbol = NULL;
	delete[] raiz_del_arbol;
}

bool Arbol::isIn(const string nombre_del_nodo_hijo, Nodo* nodo_actual, int flag)
{
	Nodo* temp;
	temp = nodo_actual;
	if (flag == 0)
		temp = raiz_del_arbol;

	if (temp->nombre == nombre_del_nodo_hijo)
		return true;
	else {
		flag = 1;
		for (int i = 0; i < temp->cantidad_hijos; i++) {
			if (isIn(nombre_del_nodo_hijo, temp->hijos[i], flag))
				return true;
		}
	}
	return false;
}

bool Arbol::insHijo(Nodo* padre, Nodo* hijo)
{
	if (padre->cantidad_hijos == MAX_HIJOS)
		return(false);
	padre->hijos[padre->cantidad_hijos] = hijo;
	padre->cantidad_hijos++;
	hijo->padre = padre;
	return(true);
}

void Arbol::genera_camino_entre_un_nodo_y_la_raiz(Nodo* meta, string* camino, int& cantidad_en_camino)
{
	Nodo* temp;
	temp = meta;

	while (temp->padre)
	{
		camino[cantidad_en_camino] = temp->nombre;
		temp = temp->padre;
		cantidad_en_camino++;
	}
}