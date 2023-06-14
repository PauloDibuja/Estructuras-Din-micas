#include <stdio.h>
#include <stdlib.h>


struct node{
    int value;
    struct node *next;
};

typedef enum {FALSE, TRUE} BOOLEAN;
typedef struct node STACK;

// Funciones para pilas

// Crear
void create_stack(STACK **S);
// Apilar
void push(STACK **S, int value);
// Desapilar
void pop(STACK **S, int *value);
// Mostrar
void print_stack(STACK **S);
// Vacía?
BOOLEAN is_empty_stack(STACK **S);

// Crear nodo
STACK *create_new_node();

void create_stack(STACK **S){
    (*S) = NULL;
    return;
}

STACK *create_new_node(int value){
    STACK *new = (STACK *) malloc(sizeof(STACK));
    new->value = value;
    new->next = NULL;
    return new;
}

BOOLEAN is_empty_stack(STACK **S){
    if ((*S) == NULL){
        return TRUE;
    }else{
        return FALSE;
    }
    
}

void push(STACK **S, int value){
    STACK *new = create_new_node(value);
    if((*S) == NULL){
        (*S) = new;
    }else{
        STACK *p, *p_sig;
        p = (*S);
        (*S) = new;
        new->next = p;
    }
}

void pop(STACK **S, int *value){
    if((*S) == NULL){
        printf("LA PILA ESTA VACIA, PASTEL!!");
        return;
    }else{
        STACK *p;
        p = (*S);
        *value = p->value;
        (*S) = p->next;
        free(p);
    }
}

void print_stack(STACK **S){
    STACK *p;
    p = (*S);
    if(is_empty_stack(S) == TRUE){
        printf("| Pila Vacía |\n");
        return;
    }else{
        while (p != NULL){
            printf("| %d |", p->value);
            p = p->next;  
        }
        
        printf("\n");
    }
}