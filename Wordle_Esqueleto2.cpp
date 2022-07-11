/*

A3-4) VOS PODES REY, TENES TIEMPO Y UN VIDEO QUE SIRVE COMO GUIA. CHILL.


*/


#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define INTENTO_EQUIVOCADO 500	//Cuando tiene que pasar al siguiente renglon porque no adivino la palabra. Independientemente de si acerto alguna letra.
#define LETRA_CORRECTA 50	 //Letra que esta en la palabra pero no en esa posicion
#define LETRA_PERFECTA 100	//Letra que esta en la palabra y en esa posicion
#define VICTORIA 2000 //Adivino la palabra
#define VICTORIA_PERFECTA 10000  //Adivino la palabra en el primer intento
#define DERROTA 0 //No adivino la palabra
#define TAMAÑO_LISTA (sizeof(char)*5)*30 // Cantidad de letras por palabra y cantidad de palabras en la lista, cambiar ultimo numero en caso de agregar o sacar palabras
//  y el primero en caso de modificar el largo de cada palabra

int empezarJuego(char[], int, int);
void desglosarPalabra(char[], char[]);
void randomPalabra(char[]);

int main()
{
	
	int i = 0, cantPartidas = 8, partidaActual = 1, puntajeMaximo = 0, puntajeMinimo = 0, promedioPuntaje = 0;
	char palabra[6];
	
	randomPalabra(palabra);
	
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

	int i = 0, j = 0, k = 0, v = 0, zzz = 0, puntos = 5000, puntosTotales=0, finalizarSesion = 0, puntajeMaximo = 0, partidaMaxima = 0, puntajeMinimo = 50000, partidaMinima = 0, promedioPuntaje = 0, cantVictorias = 0, intentosCorrectos = 0;
	char intento[6];
	char salirAntes[3];

	for (i = 0; i < cantPartidas; i++) { // Partida actual

		
		printf("\nPartida Nro %d de %d.\n", partidaActual, cantPartidas);
		printf("La palabra es %s\n", palabra);

		for (j = 0; j < 6; j++) { // Intento actual.

			printf("\nIngrese su intento:  ");
			scanf("%s", &intento);

			for (k = 0; k < 5; k++) { // Comparar letras de la palabra con letras del intento

				if ( tolower(palabra[k]) == tolower(intento[k]) ) {

					printf("Correcto ");
					intentosCorrectos++;

				}

				if (tolower(palabra[k]) != tolower(intento[k]) && ( tolower(intento[k]) == tolower(palabra[0]) || tolower(intento[k]) == tolower(palabra[1]) || tolower(intento[k]) == tolower(palabra[2]) || tolower(intento[k]) == tolower(palabra[3]) || tolower(intento[k]) == tolower(palabra[4]) || tolower(intento[k]) == tolower(palabra[5])) ) {

					printf("Casi ");
					zzz = 1;

				}

				if ( tolower(palabra[k]) != tolower(intento[k]) && zzz != 1 ) {

					printf("Incorrecto ");

				}

				if (intentosCorrectos == 5) {

					v = 727;
				
				}

				zzz = 0;

			}

			intentosCorrectos = 0;

			if (v == 727 && j != 0) {

				puntos = puntos + VICTORIA;
				intentosCorrectos = 0;
				cantVictorias++;
				j = 5;

				printf("\nAdivinaste la palabra, felicitaciones!. Tu puntaje total de esta partida es de %d puntos.\n", puntos);

				if (puntajeMaximo < puntos) {

					puntajeMaximo = puntos;
					partidaMaxima = partidaActual;
				}

				if (puntos < puntajeMinimo) {

					puntajeMinimo = puntos;
					partidaMinima = partidaActual;
				}


			}

			if (v == 727 && j == 0) {

				printf("\nAdivinaste la palabra en el primer intento!! Te mereces 10000 puntos.\n");
				puntos = puntos + VICTORIA_PERFECTA;
				intentosCorrectos = 0;		
				cantVictorias++;
				j = 5;

				if (puntajeMaximo < puntos) {

					puntajeMaximo = puntos;
					partidaMaxima = partidaActual;
				}

				if (puntos < puntajeMinimo) {

					puntajeMinimo = puntos;
					partidaMinima = partidaActual;
				}
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
			
		puntosTotales = puntosTotales + puntos;
		puntos = 5000;

		if (partidaActual != cantPartidas) {

			printf("\nHas terminado la partida numero %d de %d, deseas salir ahora y terminar tu sesion de juego antes de tiempo? Ingresa Si o No.\n", partidaActual, cantPartidas);
			scanf("%s", &salirAntes);

			if (_stricmp(salirAntes, "Si") == 0) {

				i = (cantPartidas - 1);
			}
		}

		partidaActual++;
		randomPalabra(palabra);

	}


	promedioPuntaje = puntosTotales / cantVictorias;
	printf("\nTerminaste todas tus partidas, tu puntuacion total es de %d, tu cantidad de victorias es %d y tu promedio de puntos fue de: %d.\n", puntosTotales, cantVictorias, promedioPuntaje);
	printf("Ademas, conseguiste tu puntuacion maxima de %dpts en tu partida nro %d y conseguiste tu puntuacion minima de %dpts en la partida nro %d.\n\n", puntajeMaximo, partidaMaxima, puntajeMinimo, partidaMinima);

	return 0;

}



void randomPalabra(char palabra[]) {

	int lineaActual = 0, lineaElegida = 0;
	bool seguirLeyendo = true;

	srand(time(NULL));
	lineaElegida = rand() % 30 + 1;


	FILE* archivoTxt;

	archivoTxt = fopen("palabras.txt", "r");
	if (archivoTxt == NULL) {

		printf("El archivo no existe.");
	}
	else {

		do {

			fgets(palabra, 6, archivoTxt);

			if (_stricmp(palabra, "\n") != 0) {

				lineaActual++;
			}



		} while (lineaActual != lineaElegida); //Porque si hago esto funciona y se para pero si pongo un if(fgets..etc == NULL) no?? no son tecnicamente lo mismo escrito diferente?
		//por cierto, no entiendo porque de la nada fgets toma la string de caracteres y el \n como dos lineas diferentes, me vino de 10, pero antes no m funcionaba asi, y me tomaba siempre la palabra con el simbolo al final, por ejemplo "gatos\n". 

	}

	fclose(archivoTxt);


}