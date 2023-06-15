#include <stdio.h>
#include "my_colas_lib.h"

int main(){
    QUEUE *queue;
    create_queue(&queue);
    int data_deleted = 0;
    for (int i = 0; i < 31; i++){
        to_queue(&queue, i);
        if(i != 0 && i % 5 == 0){
            unqueue(&queue, &data_deleted);
            printf("Se fue el nodo con el numero %d.\n", data_deleted);
        }
    }
    print_queue(&queue);
    
    return 0;
}