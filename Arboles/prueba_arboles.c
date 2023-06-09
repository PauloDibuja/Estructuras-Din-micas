# include <stdio.h>
# include <stdlib.h>

struct arbol{
    char elem;
    struct arbol *izq;
    struct arbol *der;
};

void rec_preorden(struct arbol *a_punt);
void rec_inorden(struct arbol *a_punt);
void rec_postorden(struct arbol *a_punt);

void visitar(struct arbol *a_punt);
int main(){
    struct arbol *raiz, *h, *m, *z, *k, *c, *j, *a, *i;
    struct arbol *n, *p, *y, *b, *e, *d, *x, *l;

    h=(struct arbol *)malloc(sizeof(struct arbol));
    m=(struct arbol *)malloc(sizeof(struct arbol));
    z=(struct arbol *)malloc(sizeof(struct arbol));
    k=(struct arbol *)malloc(sizeof(struct arbol));
    c=(struct arbol *)malloc(sizeof(struct arbol));
    j=(struct arbol *)malloc(sizeof(struct arbol));
    a=(struct arbol *)malloc(sizeof(struct arbol));
    i=(struct arbol *)malloc(sizeof(struct arbol));
    n=(struct arbol *)malloc(sizeof(struct arbol));
    p=(struct arbol *)malloc(sizeof(struct arbol));
    y=(struct arbol *)malloc(sizeof(struct arbol));
    b=(struct arbol *)malloc(sizeof(struct arbol));
    e=(struct arbol *)malloc(sizeof(struct arbol));
    d=(struct arbol *)malloc(sizeof(struct arbol));
    x=(struct arbol *)malloc(sizeof(struct arbol));
    l=(struct arbol *)malloc(sizeof(struct arbol));

    h->elem='h';
    h->izq=m;
    h->der=z;

    m->elem='m';
    m->izq=k;
    m->der=NULL;

    z->elem='z';
    z->izq=c;
    z->der=j;

    k->elem='k';
    k->izq=a;
    k->der=i;

    c->elem='c';
    c->izq=NULL;
    c->der=NULL;

    j->elem='j';
    j->izq=n;
    j->der=p;

    a->elem='a';
    a->izq=NULL;
    a->der=NULL;

    i->elem='i';
    i->izq=NULL;
    i->der=y;

    n->elem='n';
    n->izq=NULL;
    n->der=NULL;

    p->elem='p';
    p->izq=b;
    p->der=e;

    y->elem='y';
    y->izq=NULL;
    y->der=NULL;


    b->elem='b';
    b->izq=NULL;
    b->der=NULL;

    e->elem='e';
    e->izq=d;
    e->der=x;

    d->elem='d';
    d->izq=NULL;
    d->der=l;

    x->elem='x';
    x->izq=NULL;
    x->der=NULL;

    l->elem='l';
    l->izq=NULL;
    l->der=NULL;

    raiz=h;
    printf("\nPreorden ");
    rec_preorden(raiz);
    printf("\nInorden ");
    rec_inorden(raiz);
    printf("\nPostorden ");
    rec_postorden(raiz);
    printf("\n\n<< Finalizado >>\n\n");
    return 0;
}

void visitar(struct arbol *a_punt){
    printf("%c - ", a_punt->elem);
}


void rec_preorden(struct arbol *a_punt){
    if (a_punt != NULL){
        visitar(a_punt);
        rec_preorden(a_punt->izq);
        rec_preorden(a_punt->der);
    }
}

void rec_inorden(struct arbol *a_punt){
    if(a_punt != NULL){
        rec_inorden(a_punt->izq);
        visitar(a_punt);
        rec_inorden(a_punt->der);
    }
}

void rec_postorden(struct arbol *a_punt){
    if(a_punt != NULL){
        rec_postorden(a_punt->izq);
        rec_postorden(a_punt->der);
        visitar(a_punt);
    }
}