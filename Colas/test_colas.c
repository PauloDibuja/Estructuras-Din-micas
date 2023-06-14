#include <stdio.h>
#include "my_colas_lib.h"

int main(){
    QUEUE *queue;
    create_queue(&queue);
    print_queue(&queue);
    to_queue(&queue, 12);
    to_queue(&queue, 92);
    print_queue(&queue);
    to_queue(&queue, 662);
    to_queue(&queue, 1423);
    print_queue(&queue);
    int a = 0;
    unqueue(&queue, &a);
    unqueue(&queue, &a);
    print_queue(&queue);
    return 0;
}