#include "Datos.h"

int main()
{
	unsigned int cantidad_conexiones;
	cantidad_conexiones = 131; //Introducir cantidad de conexiones en el documento
	Datos datos_ciudades(cantidad_conexiones);
	datos_ciudades.load("Grafo_Mexico.txt");

	string ciudad_origen = "Cabo San Lucas";
	string ciudad_destino = "Cancún";
	datos_ciudades.dijkstra(ciudad_origen, ciudad_destino);

	string ciudad_a_evitar = "Tijuana";
	datos_ciudades.dijkstra_evitar_ciudad(ciudad_origen, ciudad_destino, ciudad_a_evitar);

	string ciudad_escala = "Toluca";
	datos_ciudades.dijkstra_ciudad_escala(ciudad_origen, ciudad_destino, ciudad_escala);
}