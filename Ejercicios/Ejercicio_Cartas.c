#include "../Pilas/my_pilas_lib.h"
#include <time.h>

void crear_mazo(STACK **S);
void revolver_mazo(STACK **S);

int main(){
    STACK *mazo_ordenado;
    create_stack(&mazo_ordenado);
    crear_mazo(&mazo_ordenado);
    //print_stack(&mazo_ordenado);
    revolver_mazo(&mazo_ordenado);
    //print_stack(&mazo_ordenado);
    return 0;
}

void crear_mazo(STACK **S){
    for (int n = 1; n < 14; n++){
        for (int t = 0; t < 4; t++){
            push(S, n);   
        }
    }
    
}

void revolver_mazo(STACK **S){
    STACK *temp, *aux;
    create_stack(&temp);
    create_stack(&aux);
    int valor_salvado = 0;
    for (int i = 0; i < 52; i++){
        pop(S, &valor_salvado);
        push(&temp, valor_salvado);
    }
    print_stack(S);
    print_stack(&temp);
    print_stack(&aux);
    srand(time(NULL));
    while (is_empty_stack(&temp) == TRUE || is_empty_stack(&aux) == TRUE)
    {
        int random = (rand() % 50) % 3;
        switch (random){
            case 0:
                pop(&temp, &valor_salvado);
                push(S, valor_salvado);
                break;
            case 1:
                pop(&temp, &valor_salvado);
                push(&aux, valor_salvado);
                break;
            case 2:
                if(is_empty_stack(&aux) == FALSE){
                    pop(&aux, &valor_salvado);
                    push(S, valor_salvado);
                }
                break;
    
            default:
                break;
        }
        printf("--------------------------\n");
        print_stack(S);
        print_stack(&temp);
        print_stack(&aux);
        printf("--------------------------\n");
    }
    
    
}