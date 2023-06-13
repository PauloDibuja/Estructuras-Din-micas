#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "my_list_lib.h"


int Numero_Secreto(int lim_S, int lim_I);
int main(){
    struct Lista *list;
    crear(&list);
    int random_num = 0;
    add_elem_end(&list, 13);
    add_elem_end(&list, 1);
    add_elem_end(&list, 549);
    add_elem_end(&list, 233);
    add_elem_end(&list, 4578);
    add_elem_end(&list, 89);
    add_elem_end(&list, 93);
    add_elem_end(&list, 3);
    add_elem_end(&list, 174);
    add_elem_end(&list, 65);
    add_elem_end(&list, 13523);
    add_elem_end(&list, 9713);
    add_elem_end(&list, 5613);
    add_elem_end(&list, 1123);
    add_elem_end(&list, 16433);
    add_elem_end(&list, 16343);
    add_elem_end(&list, 124);
    imprimir_lista(&list);
    order_list(&list);
    imprimir_lista(&list);
    
    
}
