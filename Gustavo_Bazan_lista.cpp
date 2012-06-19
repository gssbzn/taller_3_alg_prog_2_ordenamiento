#ifndef __GUSTAVO_BAZAN_LISTA_CPP__
#define __GUSTAVO_BAZAN_LISTA_CPP__
#include "Gustavo_Bazan_lib.h"

/********************************listas*******************************/
//Constructor
lista :: lista (void){
    ptr=NULL;
	ultimo=0;
}

//Destructor
lista :: ~lista (void){
	ptr_nodo aux;
	
	while(!es_vacia()){
        aux=ptr;
        ptr=ptr->get_ptr();
        ultimo--;
        delete aux;
    }
}

void lista :: vacia(){
	ptr_nodo aux;
	
	while(!es_vacia()){
        aux=ptr;
        ptr=ptr->get_ptr();
        ultimo--;
        delete aux;
    }
	return;
}

bool lista :: es_vacia(){
	if (ultimo == 0) return(true);
	else return(false);
}

void lista :: insertar (int pos, elemento e){
    ptr_nodo Act, Ant, Q; 
    int i;
    
    Act=ptr; 
    i = 0; 
    Q=new(nodo);
    Q->set_elemento(e);
    while (i < pos-1){
        Ant = Act;
        Act = Act->get_ptr();
        i++;
    }
    if (Act == ptr) ptr = Q;
    else Ant->set_ptr(Q);

    Q->set_ptr(Act);
    ultimo++;
}


void lista::eliminar(int pos){
	int i;
	ptr_nodo act, ant;
    
    act=ptr;
    for(i=0; i<pos-1; i++){
        ant=act;
        act=act->get_ptr();
    }
    if (act == ptr) ptr = act->get_ptr();
    else ant->set_ptr(act->get_ptr());
    ultimo--;
    delete act;
    
	return;
}

elemento lista :: consultar(int pos){
	int i;
	ptr_nodo act;
	
	act=ptr;
	
	for(i=0; i<pos; i++){
        act=act->get_ptr();
	}
	elemento e=act->get_elemento();
    return (e);
}

int lista :: longitud(){
	return (ultimo);
}

bool lista :: esta(elemento e){
    int i;
    bool esta=false;
    ptr_nodo act;
	
	act=ptr;
	
    for(i=0; i<ultimo && !esta; i++){
        if(act->get_elemento()==e){
            esta=true;
        }    
        act=act->get_ptr();
	}
	return(esta);
    
}    

elemento lista :: primero(){
    elemento e=ptr->get_elemento();
    return(e);
}

void lista :: resto(){
	ptr_nodo act;
	
    act=ptr;
	ptr=ptr->get_ptr();
    ultimo--;
    delete act;
	return;
}

// operador friend << sobrecargado
ostream& operator << (ostream& co, const lista &lis){
    elemento e;
    ptr_nodo act;
    act=lis.ptr;
    for(int i=0; i < lis.ultimo; i++){
        e=act->get_elemento();
        co << e << " ";
        act=act->get_ptr();
    }
    return co;
}

#endif
