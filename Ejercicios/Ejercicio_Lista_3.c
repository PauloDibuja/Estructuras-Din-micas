#include "../Listas/my_list_lib.h"

void print_reverse(LISTA **L, int p);

int main(){
    LISTA *lista;
    crear(&lista);
    for (int i = 0; i < 7; i++){
        add_elem_end(&lista, i);
    }
    imprimir_lista(&lista);
    print_reverse(&lista, 3);
    return 0;
}

void print_reverse(LISTA **L, int p){
    LISTA *punt, *aux;
    crear(&aux);
    punt = (*L);
    int dato_salvado = 0;
    int i = 0;
    int len = largo_lista(L);
    for (int i = 0; i < largo_lista(L); i++){
        if(i >= p) {
            add_elem_start(&aux, extraer_nodo(L, i)->valor);
        }
    }
    for (int i = 0; i < len - p; i++){
        delete_elem_end(L, &dato_salvado);
    }
    printf("Aux\n");
    imprimir_lista(&aux);
    for (int i = 0; i < largo_lista(&aux); i++){
        delete_elem_start(&aux, &dato_salvado);
        add_elem_end(L, dato_salvado);
    }
}