#include <stdio.h>
#include <stdlib.h>


typedef enum {FALSE, TRUE} BOOL;


struct Lista{
    int valor;
    struct Lista *ant;
    struct Lista *sig;
};

struct Lista *extraer_nodo(struct Lista **L, int pos); 

//------(Adding Functions)

void add_elem_end(struct Lista **L, int value);
void add_elem_start(struct Lista **L, int value);
void add_in_pos(struct Lista **L, int value, int pos);

//------(Deleting Functions)

void delete_elem_end(struct Lista **L, int *dato_saliente);
void delete_elem_start(struct Lista **L, int *dato_saliente);
void delete_in_pos(struct Lista **L, int pos, int *dato_saliente);

//------(Creating/Modifing Functions/Memory)

struct Lista *crear_nodo();

//------(Other Functions)
void imprimir_lista(struct Lista **L);
void crear(struct Lista **L);
int largo_lista(struct Lista **L);
BOOL out_of_range(struct Lista **L, int pos);
BOOL lista_vacia(struct Lista **L);
void swap_nodes(struct Lista **L, int pos1, int pos2);
void order_list(struct Lista **L);


void crear(struct Lista **L){
    *L =  NULL; 
}

struct Lista *crear_nodo(int value){
    struct Lista *nuevo = (struct Lista *) malloc(sizeof(struct Lista));
    nuevo->valor = value;
    nuevo->sig = NULL;
    return nuevo;
}

void delete_elem_end(struct Lista **L, int *dato_saliente){
    if((*L) == NULL){
        printf("Oh, no hay elementos en la lista... :0\n");
    }else if(largo_lista(L) == 1){
        (*L) = NULL;
    }else{
        struct Lista *p = (*L);
        struct Lista *aux;
        while(p->sig != NULL){
            aux = p;
            p = p->sig;
        }
        (*dato_saliente) = p->valor;
        aux->sig = NULL;
        free(p);
    }
}

void delete_elem_start(struct Lista **L, int *dato_saliente){
    struct Lista *p = (*L);
    if(p == NULL){
        printf("Oh, no hay elementos en la lista... :0\n");
        return;
    }
    if(largo_lista(L) == 1){
        (*L) = NULL;
    }
    struct Lista *aux = p->sig;
    (*L) = aux;
    (*dato_saliente) = p->valor;
    free(p);
}

// PENDIENTE A TERMINAR
void delete_in_pos(struct Lista **L, int pos, int *dato_saliente){
    struct Lista *p = (*L);
    if(pos >  largo_lista(&p)) return;
    if(p == NULL){
        printf("Oh, no hay elementos en la lista... :0\n");
        return;
    }else{
        struct Lista *aux, *new_sig;
        int i = 0;
        while(i < pos){
            aux = p;
            p = p->sig;          
            i++;
        }
        new_sig = p->sig;
        (*dato_saliente) = p->valor;
        aux->sig = new_sig;
        free(p);
    }
}

void add_elem_end(struct Lista **L, int value){
    struct Lista *p;
    p = *L;

    struct Lista *nuevo = crear_nodo(value);

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

void add_elem_start(struct Lista **L, int value){
    
    struct Lista *nuevo = crear_nodo(value);
    if(lista_vacia(L) == TRUE){
        *L = nuevo;
    }else{
        struct Lista *temp1, *temp2;
        temp1 = *L;
        *L = nuevo;
        nuevo->sig = temp1;
    }
}

BOOL lista_vacia(struct Lista **L){
    if((*L) == NULL){
        return TRUE;
    }
    return FALSE;
}

int largo_lista(struct Lista **L){
    struct Lista *p = *L;
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

void imprimir_lista(struct Lista **L){
    struct Lista *p = *L;
    if(p == NULL){
        printf("Lista : | Lista vacia |\n");
        return;
    }
    printf("Lista : |");
    while (p != NULL){
        printf("%d|", p->valor);
        p = p->sig;
    }
    printf("\n");
}

struct Lista *extraer_nodo(struct Lista **L, int pos){
    struct Lista *p = (*L);
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

BOOL out_of_range(struct Lista **L, int pos){
    if(pos > largo_lista(L)-1  || pos < 0){
        return TRUE;
    }
    return FALSE;
}

void add_in_pos(struct Lista **L, int value, int pos){
    if(lista_vacia(L) == TRUE){
        printf("No puedes agregar nodos a posiciones cuando la lista está vacía.\n");
        return;
    }
    if(out_of_range(L, pos+1) == TRUE){
        printf("Posicion fuera de rango!!\n");
        return;
    }
    struct Lista *nuevo = crear_nodo(value);
    struct Lista *p, *aux;
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

void swap_nodes(struct Lista **L, int pos1, int pos2){
    if(pos1 == pos2){
        return;
    }
    struct Lista *p1, *p2, *p1_anterior, *p2_anterior, *p1_sig, *p2_sig, *punt;
    p1 = (*L);
    p2 = (*L);
    punt = (*L);
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

    if(p1_sig == p2){
        p1_anterior->sig = p2;
        p2->sig = p1;
        p1->sig = p2_sig;
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

void order_list(struct Lista **L){
    int len =largo_lista(L);
    printf("%d\n", len);
    for (int i = 0; i < len - 1; i++){
        for (int j = 0; j < len - i - 1; j++){
            printf("lolol %d, %d \n", i, j);
            if (extraer_nodo(L, j+1)->valor < extraer_nodo(L, j)->valor){
                printf("swap\n");
                swap_nodes(L, j, j+1);
            }
        }
    }
}

/*int particion(struct Lista **L, int bajo, int alto){
    int pivote, i, j;
    pivote = extraer_nodo(L, alto)->valor;
    i = (bajo - 1);
    for (j = bajo; j <= alto - 1; j++)
    {
        if (extraer_nodo(L, j)->valor <= pivote)
        {
            i++;
            swap_nodes(L, i, j);
        }
    }
    swap_nodes(L, i+1, alto);
    return (i + 1);
}

void quickSort(struct Lista **L, int bajo, int alto){
    int pi;
    if (bajo < alto)
    {
        pi = particion(L, bajo, alto);
        quickSort(L, bajo, pi - 1);
        quickSort(L, pi + 1, alto);
    }
}*/