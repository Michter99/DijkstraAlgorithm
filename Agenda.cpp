#include "Agenda.h"

Agenda::Agenda()
{
	for (int i = 0; i < MAX_AGENDA; i++) {
		agenda[i] = new Nodo();
	}
}

Agenda::~Agenda()
{
	for (int i = 0; i < MAX_AGENDA; i++) {
		agenda[i] = NULL;
		delete[] agenda[i];
	}
}

void Agenda::ins(Nodo* nodo)
{
	if (cantidad_en_agenda == MAX_AGENDA)
		return;
	agenda[cantidad_en_agenda] = nodo;
	cantidad_en_agenda++;
}

void Agenda::ordena_agenda_de_menor_a_mayor()
{
	Nodo* temp;
	for (int i = 0; i < cantidad_en_agenda - 1; i++) {
		for (int j = 0; j < cantidad_en_agenda - i - 1; j++) {
			if (agenda[j]->distancia_acumulada > agenda[j + 1]->distancia_acumulada) {
				temp = agenda[j];
				agenda[j] = agenda[j + 1];
				agenda[j + 1] = temp;
			}
		}
	}
}

void Agenda::elimina_el_primer_nodo_de_la_agenda()
{
	for (int i = 0; i < cantidad_en_agenda; i++)
	{
		agenda[i] = agenda[i + 1];
	}
	cantidad_en_agenda--;
}

bool Agenda::isIn(string pVal) {
	for (int i = 0; i < cantidad_en_agenda; i++) {
		if (agenda[i]->nombre == pVal)
			return true;
	}
	return false;
}

Nodo* Agenda::getNode(string pVal) {
	for (int i = 0; i < cantidad_en_agenda; i++) {
		if (agenda[i]->nombre == pVal)
			return agenda[i];
	}
	return NULL;
}