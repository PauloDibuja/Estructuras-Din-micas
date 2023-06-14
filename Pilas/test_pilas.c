#include <stdio.h>
#include "my_pilas_lib.h"

int main(){
    STACK *pila;
    create_stack(&pila);
    print_stack(&pila);
    push(&pila, 5);
    push(&pila, 4134);
    push(&pila, 777);
    print_stack(&pila);
    push(&pila, 12);
    push(&pila, 654);
    push(&pila, 423);
    print_stack(&pila);
    int a = 0;
    pop(&pila, &a);
    print_stack(&pila);
    return 0;
}