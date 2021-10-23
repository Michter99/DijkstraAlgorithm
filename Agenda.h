#pragma once
#include <iostream>
#include "Nodo.h"
#define MAX_AGENDA 20

using namespace std;

class Agenda
{
public:
	Agenda();
	~Agenda();
	Nodo* agenda[MAX_AGENDA];
	int cantidad_en_agenda = 0;
	void ins(Nodo* nodo);
	void ordena_agenda_de_menor_a_mayor();
	void elimina_el_primer_nodo_de_la_agenda();
	bool isIn(string pVal);
	Nodo* getNode(string pVal);
};