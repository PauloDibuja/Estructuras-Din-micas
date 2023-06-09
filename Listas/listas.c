#include <stdio.h>
#include <stdlib.h>
#include "my_list_lib.h"

int main(){
    struct Lista *list;
    crear(&list);
    int i;
    for (int i = 0; i < 12; i++)
    {
        add_elem_end(&list, i);
    }
    imprimir_lista(&list);
    int largo = largo_lista(&list);
    printf("El largo de la lista es de %d. \n", largo);

    for (int i = 0; i < largo; i = i + 2){
        add_in_pos(&list, 32, i);
        largo = largo_lista(&list);
    }
    imprimir_lista(&list);
    int p = 0;
    for (int i = 0; i < largo; i++){
        delete_elem_end(&list, &p);
    }
    imprimir_lista(&list);
    return 0;
}
