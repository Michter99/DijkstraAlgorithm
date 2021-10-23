#include "Datos.h"

Datos::Datos(int cantidad_conexiones)
{
	cantidad_datos = 0;
	datos = new CAMPOS[cantidad_conexiones];
}

Datos::~Datos()
{
	datos = NULL;
	delete[] datos;
}

void Datos::load(string pPath)
{
	string distancia_temp;
	fstream lFile(pPath, fstream::in);
	if (lFile.is_open()) {
		while (!lFile.eof()) {
			getline(lFile, datos[cantidad_datos].nombre_estado1, ',');
			getline(lFile, datos[cantidad_datos].nombre_estado2, ',');
			getline(lFile, distancia_temp, '\n');
			datos[cantidad_datos].distancia = stof(distancia_temp);
			cantidad_datos++;
		}
		lFile.close();
	}
}

void Datos::dijkstra(string ciudad_origen, string ciudad_destino)
{
	Arbol arbol(ciudad_origen, 0);
	int cantidad_ruta = 0;
	int cant_hijos = 0;
	float* distancia = new float[MAX_HIJOS];
	string* ruta_ideal = new string[30];
	string* ciudades_conexion = new string[MAX_HIJOS];
	Agenda agenda;
	Nodo* temp = new Nodo();
	Nodo* hijo_temp;

	agenda.ins(arbol.raiz_del_arbol);

	while (agenda.cantidad_en_agenda != 0)
	{
		temp = agenda.agenda[0];
		if (temp->nombre != ciudad_destino) {
			agenda.elimina_el_primer_nodo_de_la_agenda();
			buscar_conexiones(temp->nombre, ciudades_conexion, distancia, cant_hijos);
			for (int i = 0; i < cant_hijos; i++)
			{
				hijo_temp = new Nodo(ciudades_conexion[i], distancia[i] + temp->distancia_acumulada);
				Nodo* tempNom = agenda.getNode(hijo_temp->nombre);
				if (agenda.isIn(ciudades_conexion[i]) && hijo_temp->distancia_acumulada < tempNom->distancia_acumulada)
				{
					tempNom->distancia_acumulada = hijo_temp->distancia_acumulada;
					tempNom->padre = temp;
				}
				else
				{
					if (!(arbol.isIn(hijo_temp->nombre, temp))) {
						arbol.insHijo(temp, hijo_temp);
						agenda.ins(hijo_temp);
					}
				}
			}
			agenda.ordena_agenda_de_menor_a_mayor();
		}
		else
			break;
	}
	arbol.genera_camino_entre_un_nodo_y_la_raiz(temp, ruta_ideal, cantidad_ruta);

	cout << "RUTA IDEAL:" << endl;
	cout << ciudad_origen << endl;
	for (int i = cantidad_ruta - 1; i >= 0; i--) {
		cout << ruta_ideal[i] << endl;
	}
	cout << "Distancia: " << temp->distancia_acumulada << endl << endl;
}

void Datos::dijkstra_evitar_ciudad(string ciudad_origen, string ciudad_destino, string ciudad_a_evitar)
{
	Arbol arbol(ciudad_origen, 0);
	int cantidad_ruta = 0;
	int cant_hijos = 0;
	float* distancia = new float[MAX_HIJOS];
	string* ruta_ideal = new string[30];
	string* ciudades_conexion = new string[MAX_HIJOS];
	Agenda agenda;
	Nodo* temp = new Nodo();
	Nodo* hijo_temp;

	agenda.ins(arbol.raiz_del_arbol);

	while (agenda.cantidad_en_agenda != 0)
	{
		temp = agenda.agenda[0];
		if (temp->nombre != ciudad_destino) {
			agenda.elimina_el_primer_nodo_de_la_agenda();
			buscar_conexiones(temp->nombre, ciudades_conexion, distancia, cant_hijos, ciudad_a_evitar);
			for (int i = 0; i < cant_hijos; i++)
			{
				hijo_temp = new Nodo(ciudades_conexion[i], distancia[i] + temp->distancia_acumulada);
				Nodo* tempNom = agenda.getNode(hijo_temp->nombre);
				if (agenda.isIn(ciudades_conexion[i]) && hijo_temp->distancia_acumulada < tempNom->distancia_acumulada)
				{
					tempNom->distancia_acumulada = hijo_temp->distancia_acumulada;
					tempNom->padre = temp;
				}
				else
				{
					if (!(arbol.isIn(hijo_temp->nombre, temp))) {
						arbol.insHijo(temp, hijo_temp);
						agenda.ins(hijo_temp);
					}
				}
			}
			agenda.ordena_agenda_de_menor_a_mayor();
		}
		else
			break;
	}
	arbol.genera_camino_entre_un_nodo_y_la_raiz(temp, ruta_ideal, cantidad_ruta);

	cout << "RUTA IDEAL EVITANDO " << ciudad_a_evitar << ":" << endl;
	cout << ciudad_origen << endl;
	for (int i = cantidad_ruta - 1; i >= 0; i--) {
		cout << ruta_ideal[i] << endl;
	}
	cout << "Distancia: " << temp->distancia_acumulada << endl << endl;
}

void Datos::dijkstra_ciudad_escala(string ciudad_origen, string ciudad_destino, string ciudad_escala)
{
	Arbol arbol(ciudad_origen, 0);
	int cantidad_ruta = 0;
	int cant_hijos = 0;
	float* distancia = new float[MAX_HIJOS];
	string* ruta_ideal = new string[30];
	string* ciudades_conexion = new string[MAX_HIJOS];
	Agenda agenda;
	Nodo* temp = new Nodo();
	Nodo* hijo_temp;

	agenda.ins(arbol.raiz_del_arbol);

	while (agenda.cantidad_en_agenda != 0)
	{
		temp = agenda.agenda[0];
		if (temp->nombre != ciudad_escala) {
			agenda.elimina_el_primer_nodo_de_la_agenda();
			buscar_conexiones(temp->nombre, ciudades_conexion, distancia, cant_hijos);
			for (int i = 0; i < cant_hijos; i++)
			{
				hijo_temp = new Nodo(ciudades_conexion[i], distancia[i] + temp->distancia_acumulada);
				Nodo* tempNom = agenda.getNode(hijo_temp->nombre);
				if (agenda.isIn(ciudades_conexion[i]) && hijo_temp->distancia_acumulada < tempNom->distancia_acumulada)
				{
					tempNom->distancia_acumulada = hijo_temp->distancia_acumulada;
					tempNom->padre = temp;
				}
				else
				{
					if (!(arbol.isIn(hijo_temp->nombre, temp))) {
						arbol.insHijo(temp, hijo_temp);
						agenda.ins(hijo_temp);
					}
				}
			}
			agenda.ordena_agenda_de_menor_a_mayor();
		}
		else
			break;
	}
	arbol.genera_camino_entre_un_nodo_y_la_raiz(temp, ruta_ideal, cantidad_ruta);

	Arbol arbol2(ciudad_escala, 0);
	int cantidad_ruta2 = 0;
	int cant_hijos2 = 0;
	float* distancia2 = new float[MAX_HIJOS];
	string* ruta_ideal2 = new string[30];
	string* ciudades_conexion2 = new string[MAX_HIJOS];
	Agenda agenda2;
	Nodo* temp2 = new Nodo();
	Nodo* hijo_temp2;

	agenda2.ins(arbol2.raiz_del_arbol);

	while (agenda2.cantidad_en_agenda != 0)
	{
		temp2 = agenda2.agenda[0];
		if (temp2->nombre != ciudad_destino) {
			agenda2.elimina_el_primer_nodo_de_la_agenda();
			buscar_conexiones(temp2->nombre, ciudades_conexion2, distancia2, cant_hijos2);
			for (int i = 0; i < cant_hijos2; i++)
			{
				hijo_temp2 = new Nodo(ciudades_conexion2[i], distancia2[i] + temp2->distancia_acumulada);
				Nodo* tempNom2 = agenda2.getNode(hijo_temp2->nombre);
				if (agenda2.isIn(ciudades_conexion2[i]) && hijo_temp2->distancia_acumulada < tempNom2->distancia_acumulada)
				{
					tempNom2->distancia_acumulada = hijo_temp2->distancia_acumulada;
					tempNom2->padre = temp2;
				}
				else
				{
					if (!(arbol2.isIn(hijo_temp2->nombre, temp2))) {
						arbol2.insHijo(temp2, hijo_temp2);
						agenda2.ins(hijo_temp2);
					}
				}
			}
			agenda2.ordena_agenda_de_menor_a_mayor();
		}
		else
			break;
	}
	arbol2.genera_camino_entre_un_nodo_y_la_raiz(temp2, ruta_ideal2, cantidad_ruta2);

	cout << "RUTA IDEAL CON ESCALA EN " << ciudad_escala << ":" << endl;
	cout << ciudad_origen << endl;
	for (int i = cantidad_ruta - 1; i >= 0; i--) {
		cout << ruta_ideal[i] << endl;
	}
	for (int i = cantidad_ruta2 - 1; i >= 0; i--) {
		cout << ruta_ideal2[i] << endl;
	}
	cout << "Distancia: " << temp->distancia_acumulada + temp2->distancia_acumulada << endl << endl;
}

void Datos::buscar_conexiones(const string ciudad, string* ciudades_conexion, float* distancia, int& cant_hijos)
{
	cant_hijos = 0;
	int h = 0;
	for (int i = 0; i < cantidad_datos; i++)
	{
		if (ciudad == datos[i].nombre_estado1)
		{
			ciudades_conexion[h] = datos[i].nombre_estado2;
			distancia[h] = datos[i].distancia;
			h++;
		}
		if (ciudad == datos[i].nombre_estado2)
		{
			ciudades_conexion[h] = datos[i].nombre_estado1;
			distancia[h] = datos[i].distancia;
			h++;
		}
	}
	cant_hijos = h;
}

void Datos::buscar_conexiones(const string ciudad, string* ciudades_conexion, float* distancia, int& cant_hijos, string ciudad_a_evitar)
{
	cant_hijos = 0;
	int h = 0;
	for (int i = 0; i < cantidad_datos; i++)
	{
		if (ciudad == datos[i].nombre_estado1 && ciudad_a_evitar != datos[i].nombre_estado1)
		{
			ciudades_conexion[h] = datos[i].nombre_estado2;
			distancia[h] = datos[i].distancia;
			h++;
		}
		if (ciudad == datos[i].nombre_estado2 && ciudad_a_evitar != datos[i].nombre_estado2)
		{
			ciudades_conexion[h] = datos[i].nombre_estado1;
			distancia[h] = datos[i].distancia;
			h++;
		}
	}
	cant_hijos = h;
}