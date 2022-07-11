/*

A3-4) VOS PODES REY, TENES TIEMPO Y UN VIDEO QUE SIRVE COMO GUIA. CHILL.


*/


#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define INTENTOEQUIVOCADO 500	//Cuando tiene que pasar al siguiente renglon porque no adivino la palabra. Independientemente de si acerto alguna letra.
#define LETRACORRECTA 50	 //Letra que esta en la palabra pero no en esa posicion
#define LETRAPERFECTA 100	//Letra que esta en la palabra y en esa posicion
#define VICTORIA 2000 //Adivino la palabra
#define VICTORIAPERFECTA 10000  //Adivino la palabra en el primer intento
#define DERROTA 0 //No adivino la palabra

int empezarJuego(char[], int, int);
void desglosarPalabra(char[], char[]);

int main()
{

	int i = 0, cantPartidas = 8, partidaActual = 1, puntajeMaximo = 0, puntajeMinimo = 0, promedioPuntaje = 0;
	char palabra[6] = "fumar";
	char arrayLetras[5];

	printf("Bienvenido a Wordle, cuantas partidas deseas jugar en tu sesion de juego?  ");
	scanf("%d", &cantPartidas);

	while (cantPartidas > 8){

		printf("\nLo sentimos, el maximo de partidas por sesion de juegos es 8 :( \nIngresa una nueva cantidad igual o menor a 8:  ");
		scanf("%d", &cantPartidas);
	}

	printf("\nGenial! Empecemos.");

	/*desglosarPalabra(palabra, arrayLetras);*/

	empezarJuego(palabra, cantPartidas, partidaActual);
	

	return 0;
}

int empezarJuego(char palabra[], int cantPartidas, int partidaActual) {

	int i = 0, j = 0, k = 0, v = 0, puntos = 5000, finalizarSesion = 0, puntajeMaximo = 0, puntajeMinimo = 0, promedioPuntaje = 0, intentosCorrectos = 0;
	char intento[6];
	char salirAntes[3];

	for (i = 0; i < cantPartidas; i++) { // Partida actual

		
		printf("\nPartida Nro %d de %d.\n", partidaActual, cantPartidas);


		for (j = 0; j < 6; j++) { // Intento actual.

			printf("\nIngrese su intento:  ");
			scanf("%s", &intento);

			for (k = 0; k < 5; k++) { // Comparar letras de la palabra con letras del intento

				if (palabra[k] == intento[k]) {

					printf("Correcto ");
					intentosCorrectos++;

				}

				if (palabra[k] != intento[k]) {

					printf("Incorrecto ");

				}

				if (intentosCorrectos == 5) {

					v = 727;
				
				}

			}

			intentosCorrectos = 0;

			if (v == 727 && j != 0) {

				printf("\nAdivinaste la palabra, felicitaciones!. Ganaste %d puntos.\n", VICTORIA);
				puntos = puntos + VICTORIA;
				intentosCorrectos = 0;
				j = 5;

			}

			if (v == 727 && j == 0) {

				printf("\nAdivinaste la palabra en el primer intento!! Te mereces 10000 puntos.\n");
				puntos = puntos + VICTORIAPERFECTA;
				intentosCorrectos = 0;		
				j = 5;
			}

			if (v != 727 && j == 5) {

				printf("\n No pudiste adivinar la palabra. Perdiste esta partida.\n");
				

			}

			if (v != 727) {
				printf("\n-500\n");
				puntos = puntos - 500;

			}

			v = 0;
			intentosCorrectos = 0;
			
		}

		if (partidaActual != cantPartidas) {

			printf("\nHas terminado la partida numero %d de %d, deseas salir ahora y terminar tu sesion de juego antes de tiempo? Ingresa Si o No.\n", partidaActual, cantPartidas);
			scanf("%s", &salirAntes);

			if (_stricmp(salirAntes, "Si") == 0) {

				i = (cantPartidas - 1);
			}

		}

		partidaActual++;
		
	}

	printf("Terminaste todas tus partidas, tu puntuacion total fue de: %d", puntos);

	return 0;

}


void desglosarPalabra(char palabra[], char arrayLetras[]) {




}