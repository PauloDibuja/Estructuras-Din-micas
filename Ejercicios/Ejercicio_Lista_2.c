#include "../Listas/my_list_lib.h"

int suma(LISTA **L);
int main(){
    LISTA *list;
    crear(&list);
    for (int i = 1; i < 101; i++){
        add_elem_end(&list, i);
    }
    imprimir_lista(&list);
    int total = 0;
    total = suma(&list);
    printf("La suma de los elementos de la lista da %d.\n", total);
    return 0;
}

int suma(LISTA **L){
    if((*L) == NULL){
        return 0;
    }else{
        return suma(&((*L)->sig)) + (*L)->valor;
    }
}