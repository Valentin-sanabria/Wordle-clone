#include <stdio.h>

int main (void) {

    int n, p, m;

    printf("Elija tres enteros positivos:\n\n");

    do {
        scanf("%d", &n);

        if(n<0) {
            printf("Ingrese un numero mayor que 0:\n");
        }

    } while(n<0);

    printf("Eligio correctamente su primer numero");
    printf("\n\n");

    do {
        scanf("%d", &p);

        if(p<0) {
            printf("Ingrese un numero mayor que 0:\n");
        }

    } while(p<0);

    printf("Eligio correctamente su segundo numero");
    printf("\n\n");

    do {
        scanf("%d", &m);
        if(m<n) {
            printf("Ingrese un entero mayor que el primero:\n");
        }
    } while(m<n);

    printf("Eligio correctamente su tercer numero");
    printf("\n\n");


    int nro = 0;
    int k = 0;

    while(k<=m) {

        if (k==m || k>m){
            break;
        }
        else {
            k = n + (nro * p);
            printf("%d ", k);
            nro++;
        }
    }

    return 0;
}
