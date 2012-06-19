#ifndef __GUSTAVO_BAZAN_PILA_CPP__
#define __GUSTAVO_BAZAN_PILA_CPP__
#include "Gustavo_Bazan_lib.h"

/********************************PILAS*******************************/
//Constructor
pila :: pila () : lista(){
    
}

//Destructor
pila :: ~pila (void){
    ptr_nodo aux;
	
	while(!es_vacia()){
        desempilar();
    }
}

void pila :: vacia(){
	
	while(!es_vacia()){
        desempilar();
    }
	return;
}

bool pila :: es_vacia(){
	if (ultimo == 0) return(true);
	else return(false);
}

void pila :: empilar (elemento e){
	insertar(0, e);
	return;
}

void pila :: desempilar (){
	resto();
}

elemento pila :: tope(){
    elemento e=primero();
    return(e);
}


// operador friend << sobrecargado
ostream& operator << (ostream& co, const pila &pil){
    elemento e;
    ptr_nodo act;
    act=pil.ptr;
    for(int i=0; i < pil.ultimo; i++){
        e=act->get_elemento();
        co << e << " ";
        act=act->get_ptr();
    }
   return co;
}

elemento get_menor(pila *P){
	pila P2, ord;
	elemento e, a, menor=100001;
	while(!P->es_vacia()){
   		e=P->tope();
		P->desempilar();
		if(e < menor){
			if(!ord.es_vacia()){
				a.set_elemento(ord.tope());
				P2.empilar(a);
				ord.desempilar();
			}
			menor=e;
            ord.empilar(e); 
			
        }
		else{
			P2.empilar(e);
		}
	}
	while(!P2.es_vacia()){
		e=P2.tope();
		P2.desempilar();
		P->empilar(e);
	}
	return(menor);
}

#endif
