#include "../Listas/my_list_lib.h"

void delete_nodes_by_value(LISTA **L, int value);

int main(){
    LISTA *enteros;
    crear(&enteros);
    int enteros_arr[] = {3,6,534,4,3,7,6,4,8,2,3,545,7,5,6};
    for (int i = 0; i < 15; i++){
        add_elem_end(&enteros, enteros_arr[i]);    
    }
    imprimir_lista(&enteros);
    delete_nodes_by_value(&enteros, 3);
    imprimir_lista(&enteros);
}

void delete_nodes_by_value(LISTA **L, int value){
    LISTA *aux, *p;
    int pos = 0;
    p = (*L);
    int dato_saliente = 0;
    while(pos < largo_lista(L)){ 
        int node_v = extraer_nodo(L, pos)->valor;
        if(node_v == value){
            delete_in_pos(L, pos, &dato_saliente);
            p = (*L);
            pos = 0;
        }else{
            p = p->sig;
            pos++;
        }
    }
}