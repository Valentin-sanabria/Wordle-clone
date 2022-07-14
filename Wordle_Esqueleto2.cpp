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

int empezarJuego(char[], int, int, char[][7]);
void randomPalabra(char[], char[][7]);
void comprobarPalabra(char[], char[][7]);
int puntoLetraCorrecta(char, char[], bool);
int puntoLetraCasi(char letra, char palabra[], bool);

int main()
{
	
	int i = 0, cantPartidas = 8, puntajeMaximo = 0, puntajeMinimo = 0, promedioPuntaje = 0;
	static int partidaActual = 1;
	static char palabra[6]; 
	static char palabrasUsadas[8][7]; //deberia de poner un tamaño mayor por las dudas a pesar de que se que "solo necesito 6", tuve q volver y aumentar el valor a 7 para agregar \n alfinal de todos.


	randomPalabra(palabra, palabrasUsadas);

	printf("Bienvenido a Wordle, cuantas partidas deseas jugar en tu sesion de juego?  ");
	scanf("%d", &cantPartidas);

	while (cantPartidas > 8){

		printf("\nLo sentimos, el maximo de partidas por sesion de juegos es 8 :( \nIngresa una nueva cantidad igual o menor a 8:  ");
		scanf("%d", &cantPartidas);
	}

	printf("\nGenial! Empecemos.");

	

	empezarJuego(palabra, cantPartidas, partidaActual, palabrasUsadas);
	

	return 0;
}

int empezarJuego(char palabra[], int cantPartidas, int partidaActual, char palabrasUsadas[][7]) {

	int i = 0, j = 0, k = 0, v = 0, q = 0, zzz = 0, puntos = 5000, contador = 0, puntosTotales = 0, historialPuntos[8], finalizarSesion = 0;
	int puntajeMaximo = 0, partidaMaxima = 0, puntajeMinimo = 50000, partidaMinima = 0, promedioPuntaje = 0, cantVictorias = 0, intentosCorrectos = 0;
	char intento[6], salirAntes[3];
	bool resetCorrecto = false, resetCasi = false;
	
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
					puntos = puntos + puntoLetraCorrecta(palabra[k], palabra, resetCorrecto);
					resetCorrecto = false;

				}

				if (tolower(palabra[k]) != tolower(intento[k]) && ( tolower(intento[k]) == tolower(palabra[0]) || tolower(intento[k]) == tolower(palabra[1]) || tolower(intento[k]) == tolower(palabra[2]) || tolower(intento[k]) == tolower(palabra[3]) || tolower(intento[k]) == tolower(palabra[4]) || tolower(intento[k]) == tolower(palabra[5])) ) {

					printf("Casi ");
					puntos = puntos + puntoLetraCasi(palabra[k], palabra, resetCasi);
					resetCasi = false;
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

				printf("\nAdivinaste la palabra en el primer intento!! Te mereces 10000 puntos extra.\n");
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
			
		historialPuntos[contador] = puntos;
		puntosTotales = puntosTotales + puntos;
		puntos = 5000;
		contador++;

		if (partidaActual != cantPartidas) {

			printf("\nHas terminado la partida numero %d de %d, deseas salir ahora y terminar tu sesion de juego antes de tiempo? Ingresa Si o No.\n", partidaActual, cantPartidas);
			scanf("%s", &salirAntes);

			if (_stricmp(salirAntes, "Si") == 0) {

				i = (cantPartidas - 1);
			}
		}

		resetCorrecto = true;
		resetCasi = true;
		partidaActual++;
		randomPalabra(palabra, palabrasUsadas);
	
	}


	//final juego, estadisticas y puntos.

	promedioPuntaje = puntosTotales / cantVictorias;
	printf("\nTerminaste todas tus partidas, tu puntuacion total es de %d, tu cantidad de victorias es %d y tu promedio de puntos fue de: %d.\n", puntosTotales, cantVictorias, promedioPuntaje);
	printf("Ademas, conseguiste tu puntuacion maxima de %dpts en tu partida nro %d y conseguiste tu puntuacion minima de %dpts en la partida nro %d.\n\n", puntajeMaximo, partidaMaxima, puntajeMinimo, partidaMinima);
	printf("Por ultimo, te mostramos un historial de todas tus puntuaciones junto a la palabra de esa partida:\n");

	for (q = 0; q < contador; q++) {

		printf("La palabra numero %d fue %s y obtuviste un total de %dpts.\n", q+1, palabrasUsadas[q], historialPuntos[q]);

	}
	return 0;

}


//generar palabra aleatoria para empezar la partida
void randomPalabra(char palabra[], char palabrasUsadas[][7]) {

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

	comprobarPalabra(palabra, palabrasUsadas);
	fclose(archivoTxt);


}

//comprobar que la palabra seleccionada no haya sido usada en una partida anterior de la misma sesion
void comprobarPalabra(char palabra[], char palabrasUsadas[][7]) {

	int j = 0;
	static int totalPalabras = 0;
	
	for (j = 0; j < totalPalabras+1; j++) {

		if (_stricmp(palabrasUsadas[j], palabra) == 0) {

			printf("\nLa palabra era %s pero ya fue usada, buscaremos otra.\n", palabra);
			randomPalabra(palabra, palabrasUsadas);
		
		}

	}
		
	strcpy(palabrasUsadas[totalPalabras], palabra);
	totalPalabras++;

}

//100 puntos por poner la letra en el lugar que iba
int puntoLetraCorrecta(char letra, char palabra[], bool reset) {

	int i = 0, j = 0;
	static int numLetras = 0;
	static char letrasUsadas[7];
	letrasUsadas[6] = '\0';

	if (reset == true) {

		numLetras = 0;
		for (j = 0; j < 7 + 1; j++) {

			letrasUsadas[j] = '\0'; // forma mas practica de vaciar el array que con un loop?

		}

	}

	for (i = 0; i < 7 + 1; i++) {

		if (strchr(letrasUsadas, letra) != NULL) {

			return 0;
		}
		else if (strchr(letrasUsadas, letra) == NULL) {

			letrasUsadas[numLetras] = letra;
			numLetras++;
			return 100;

		}
	}


}

//50 puntos por letra correcta pero que va en un lugar distinto.
int puntoLetraCasi(char letra, char palabra[], bool reset) {

	int i = 0, j = 0;
	static int numLetras = 0;
	static char letrasCasiUsadas[7];
	letrasCasiUsadas[6] = '\0';

	if (reset == true) {

		numLetras = 0;
		for (j = 0; j < 7 + 1; j++) {

			letrasCasiUsadas[j] = '\0'; // forma mas practica de vaciar el array que con un loop?

		}

	}

	for (i = 0; i < 7 + 1; i++) {

		if (strchr(letrasCasiUsadas, letra) != NULL) {

			return 0;
		}
		else if (strchr(letrasCasiUsadas, letra) == NULL) {

			letrasCasiUsadas[numLetras] = letra;
			numLetras++;
			return 50;

		}
	}


}