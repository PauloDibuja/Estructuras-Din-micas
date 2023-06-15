#include "../Pilas/my_pilas_lib.h"

void reemplazar(STACK **S, int nuevo, int viejo);

int main(){
    STACK *pila;
    create_stack(&pila);
    print_stack(&pila);
    push(&pila, 39);
    push(&pila, 4);
    push(&pila, 5);
    push(&pila, 5);
    push(&pila, 3);
    push(&pila, 5);
    push(&pila, 5);
    push(&pila, 43);
    print_stack(&pila);
    reemplazar(&pila, 13, 5);
    print_stack(&pila);
    return 0;
}

void reemplazar(STACK **S, int nuevo, int viejo){
    STACK *aux;
    create_stack(&aux);
    int valor_aux = 0;
    while ((*S) != NULL){
        pop(S, &valor_aux);
        push(&aux, valor_aux);   
    }
    while(aux != NULL){
        pop(&aux, &valor_aux);
        if(valor_aux == viejo){
            push(S, nuevo);
        }else{
            push(S, valor_aux);
        }
    }
}