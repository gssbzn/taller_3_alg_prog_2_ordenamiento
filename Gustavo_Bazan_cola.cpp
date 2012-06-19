#ifndef __GUSTAVO_BAZAN_COLA_CPP__
#define __GUSTAVO_BAZAN_COLA_CPP__
#include "Gustavo_Bazan_lib.h"

/********************************PILAS*******************************/
//Constructor
cola :: cola () : lista(){
    
}

//Destructor
cola :: ~cola (void){
    ptr_nodo aux;
	
	while(!es_vacia()){
        desencolar();
    }
}

void cola :: vacia(){
	
	while(!es_vacia()){
        desencolar();
    }
	return;
}

bool cola :: es_vacia(){
	if (ultimo == 0) return(true);
	else return(false);
}

void cola :: encolar (elemento e){
	insertar(ultimo, e);
	return;
}

void cola :: desencolar (){
	resto();
}

elemento cola :: frente(){
    elemento e=primero();
    return(e);
}


// operador friend << sobrecargado
ostream& operator << (ostream& co, const cola &col){
    elemento e;
    ptr_nodo act;
    act=col.ptr;
    for(int i=0; i < col.ultimo; i++){
        e=act->get_elemento();
        co << e << " ";
        act=act->get_ptr();
    }
   return co;
}

#endif
