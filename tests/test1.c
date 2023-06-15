
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Ejemplo aprenderaprogramar.com
int main()
{
    srand(time(NULL)); // El mayordomo pone a girar la diana
    int test = rand(); // Primer disparo del robot
    printf("El numero aleatorio de test vale %d\n", test);
    printf("Otros numeros aleatorios son: %d, %d, %d\n", rand()%2, rand()%2, rand()%2);
    printf("La constante RAND_MAX vale %d\n", RAND_MAX);
    return 0;
}