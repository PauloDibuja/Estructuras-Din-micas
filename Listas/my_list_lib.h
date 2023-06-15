#include <stdio.h>
#include <stdlib.h>


typedef enum {FALSE, TRUE} BOOL;


struct Lista{
    int valor;
    struct Lista *ant;
    struct Lista *sig;
};

typedef struct Lista LISTA;

LISTA *extraer_nodo(LISTA **L, int pos); 

//------(Adding Functions)

void add_elem_end(LISTA **L, int value);
void add_elem_start(LISTA **L, int value);
void add_in_pos(LISTA **L, int value, int pos);

//------(Deleting Functions)

void delete_elem_end(LISTA **L, int *dato_saliente);
void delete_elem_start(LISTA **L, int *dato_saliente);
void delete_in_pos(LISTA **L, int pos, int *dato_saliente);

//------(Creating/Modifing Functions/Memory)

LISTA *crear_nodo();

//------(Other Functions)
void imprimir_lista(LISTA **L);
void crear(LISTA **L);
int largo_lista(LISTA **L);
BOOL out_of_range(LISTA **L, int pos);
BOOL lista_vacia(LISTA **L);
void swap_nodes(LISTA **L, int pos1, int pos2);
void order_list(LISTA **L);


void crear(LISTA **L){
    *L =  NULL; 
}

LISTA *crear_nodo(int value){
    LISTA *nuevo = (LISTA *) malloc(sizeof(LISTA));
    nuevo->valor = value;
    nuevo->sig = NULL;
    return nuevo;
}

void delete_elem_end(LISTA **L, int *dato_saliente){
    if((*L) == NULL){
        printf("Oh, no hay elementos en la lista... :0\n");
    }else if(largo_lista(L) == 1){
        (*L) = NULL;
    }else{
        LISTA *p = (*L);
        LISTA *aux;
        while(p->sig != NULL){
            aux = p;
            p = p->sig;
        }
        (*dato_saliente) = p->valor;
        aux->sig = NULL;
        free(p);
    }
}

void delete_elem_start(LISTA **L, int *dato_saliente){
    LISTA *p = (*L);
    if(p == NULL){
        printf("Oh, no hay elementos en la lista... :0\n");
        return;
    }
    if(largo_lista(L) == 1){
        (*L) = NULL;
    }
    LISTA *aux = p->sig;
    (*L) = aux;
    (*dato_saliente) = p->valor;
    free(p);
}

void delete_in_pos(LISTA **L, int pos, int *dato_saliente){
    LISTA *p = (*L);
    if(pos >  largo_lista(&p)) return;
    if(p == NULL){
        printf("Oh, no hay elementos en la lista... :0\n");
        return;
    }else{
        LISTA *aux, *new_sig;
        LISTA *anterior, *siguiente;
        anterior = (*L);
        int i = 0;
        siguiente = p->sig;
        while (i < pos){
            anterior = p;
            p = p->sig;
            if(p->sig != NULL) siguiente = p->sig;
            else siguiente = NULL;
            i++;
        }
        if(p == (*L)){
            (*L) = siguiente;
        }else if(siguiente == NULL){
            anterior->sig = NULL;
        }else{
            anterior->sig = siguiente;
        }
        free(p);
    }
}

void add_elem_end(LISTA **L, int value){
    LISTA *p;
    p = *L;

    LISTA *nuevo = crear_nodo(value);

    if(lista_vacia(L) == TRUE){
        *L = nuevo;
        return;
    }else{
        while(p->sig != NULL){
            p = p->sig;
        }
        p->sig = nuevo;
    }    
}

void add_elem_start(LISTA **L, int value){
    
    LISTA *nuevo = crear_nodo(value);
    if(lista_vacia(L) == TRUE){
        (*L) = nuevo;
    }else{
        LISTA *temp1;
        temp1 = *L;
        *L = nuevo;
        nuevo->sig = temp1;
    }
}

BOOL lista_vacia(LISTA **L){
    if((*L) == NULL){
        return TRUE;
    }
    return FALSE;
}

int largo_lista(LISTA **L){
    LISTA *p = *L;
    if(lista_vacia(L) == FALSE){
        int i = 1;
        while (p->sig != NULL){
            p = p->sig;
            i++;
        }
        return i;
    }
    return 0;
}

void imprimir_lista(LISTA **L){
    LISTA *p = *L;
    if(p == NULL){
        printf("Lista : | Lista vacia |\n");
        return;
    }
    printf("Lista : |");
    printf("|%d|", p->valor);
    while (p->sig != NULL){
        p = p->sig;
        printf("|%d|", p->valor);
    }
    printf("\n");
}

LISTA *extraer_nodo(LISTA **L, int pos){
    LISTA *p = (*L);
    if(out_of_range(&p, pos) == TRUE){
        printf("Posicion fuera de rango!!\n");
        return NULL;
    }
    if(lista_vacia(L) == FALSE){
        int i = 0;
        while(i < pos){
            p = p->sig;
            i++;
        }
        return p;
    }else{
        printf("No se puede extraer de una lista vacia!!\n");
        return NULL;
    }
}

BOOL out_of_range(LISTA **L, int pos){
    if(pos >= largo_lista(L)  || pos < 0){
        return TRUE;
    }
    return FALSE;
}

void add_in_pos(LISTA **L, int value, int pos){
    if(lista_vacia(L) == TRUE){
        printf("No puedes agregar nodos a posiciones cuando la lista está vacía.\n");
        return;
    }
    if(out_of_range(L, pos+1) == TRUE){
        printf("Posicion fuera de rango!!\n");
        return;
    }
    LISTA *nuevo = crear_nodo(value);
    LISTA *p, *aux;
    p = *L;
    int i = 0;
    while (i < pos){ 
        p = p->sig;
        i++;
    }
    aux = p->sig;
    p->sig = nuevo;
    nuevo->sig = aux;
}

void swap_nodes(LISTA **L, int pos1, int pos2){
    if(pos1 == pos2){
        return;
    }
    LISTA *p1, *p2, *p1_anterior, *p2_anterior, *p1_sig, *p2_sig, *punt;
    p1 = (*L);
    p2 = (*L);
    punt = (*L);
    p1_anterior = (*L);
    p2_anterior = (*L);
    int i = 0, j = 0;
    while(i < pos1){
        p1_anterior = p1;
        p1 = p1->sig;
        i++;       
    }
    p1_sig = p1->sig;
    while(j < pos2){
        p2_anterior = p2;
        p2 = p2->sig;
        j++;
    }
    p2_sig = p2->sig;

    // Caso nodos juntos

    if(p1->sig == p2){
        if(pos1 == 0) (*L) = p2;
        else p1_anterior->sig = p2;
        p2->sig = p1;
        if (pos2 == largo_lista(L) - 1) p1->sig = p2_sig;
        else p1->sig = NULL;
        return;
    }

    // Caso por defecto
    if((*L) != p1){
        p1_anterior->sig = p2;
    }else{
        (*L) = p2;
    }
    p2->sig =p1_sig;

    p2_anterior->sig = p1;
    if(p2->sig != NULL){
        p1->sig = p2_sig;
    }else{
        p1->sig = NULL;
    }
}

void order_list(LISTA **L){
    int len =largo_lista(L);
    for (int i = 0; i < len - 1; ++i){
        for (int j = 0; j < len - i - 1; ++j){
            if (extraer_nodo(L, j)->valor > extraer_nodo(L, j+1)->valor){
                printf("len: %d\n", largo_lista(L));
                swap_nodes(L, j, j+1);
                imprimir_lista(L);
            }
        }
    }
}
