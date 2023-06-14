#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *next;
}QUEUE;

typedef enum {FALSE, TRUE} BOOLEAN;

// Crear
void create_queue(QUEUE **Q);
// Encolar
void to_queue(QUEUE **Q, int value);
// Desencolar
void unqueue(QUEUE **Q, int *value);
// Vacía?
BOOLEAN is_empty_queue(QUEUE **Q);
// Crear nodo
QUEUE *create_node(int value);
// Imprimir fila
void print_queue(QUEUE **Q);




void create_queue(QUEUE **Q){
    (*Q) = NULL;
    return;
}
// Encolar
void to_queue(QUEUE **Q, int value){
    QUEUE *n = create_node(value);
    if(is_empty_queue(Q) == TRUE){
        (*Q) = n;
        n->next = n;
        return;
    }else{
        QUEUE *first = (*Q)->next;
        (*Q)->next = n;
        n->next = first;
    }
}
// Desencolar
void unqueue(QUEUE **Q, int *value){
    if(is_empty_queue(Q) == TRUE){
        printf("La cola esta vacia... no se puede desencolar nada.\n");
        return;
    }else{
        QUEUE *first = (*Q)->next;
        QUEUE *next_first = first->next;
        (*Q)->next = next_first;
        *value = first->value;
        free(first);
        return;
    }
}
// Vacía?
BOOLEAN is_empty_queue(QUEUE **Q){
    if((*Q) == NULL) return TRUE;
    else return FALSE;
}
// Crear nodo
QUEUE *create_node(int value){
    QUEUE *new_node = (QUEUE *) malloc(sizeof(QUEUE));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}
// Imprimir fila
void print_queue(QUEUE **Q){
    if(is_empty_queue(Q) == TRUE){
        printf("| Pila Vacía |\n");
        return;
    }else{
        QUEUE *p, *start;       
        p = (*Q)->next;
        start = (*Q)->next;
        do{
            printf("| %d |", p->value);
            p = p->next;  
        }while(p != start);
        
        printf("\n");
    }
}
