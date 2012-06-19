#ifndef __GUSTAVO_BAZAN_NODO_CPP__
#define __GUSTAVO_BAZAN_NODO_CPP__
#include "Gustavo_Bazan_lib.h"
/**********************************nodo****************************************/
// Constructor
nodo :: nodo (void){
    prox=NULL;
    
}

void nodo :: set_elemento(elemento e){
     elem.set_elemento(e);
     return;
}

elemento nodo :: get_elemento(){
    return(elem.get_elemento());
}

void nodo :: set_ptr(ptr_nodo p){
    prox=p;
    return;
}

ptr_nodo nodo :: get_ptr(){
    return(prox);
}

#endif
