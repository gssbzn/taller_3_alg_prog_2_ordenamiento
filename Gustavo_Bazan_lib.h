/*
  Gustavo Bazan
  C.I.:17.777.408
  seccion 22
*/

#ifndef __GUSTAVO_BAZAN_LIB_H__
#define __GUSTAVO_BAZAN_LIB_H__

/* Declaracion de Librerias */
#include <iostream>
#include <fstream>
using namespace std;

//Constantes

//Puntero
typedef struct nodo *ptr_nodo;

/************************************elemento**********************************/
class elemento{
    private:
        int e;
       
    public:
        //constructor por defecto
        elemento();
        //constructor general
        elemento(int );
        //constructor de copia
        elemento(const elemento&);   
        
        void set_elemento(int );
        void set_elemento(elemento );
        int get_elemento();
        
        // Sobrecarga del operador de asignación
        elemento& operator= (const elemento&);
        
        // Sobrecarga de operadores de comparación
        friend int operator< (const elemento&, const elemento&);
        friend int operator> (const elemento&, const elemento&);
        friend int operator== (const elemento&, const elemento&);
        friend int operator== (const elemento&, const int&);
        friend int operator!= (const elemento&, const elemento&);
        friend int operator!= (const elemento&, const int&);
        
        // Sobrecarga del operador de inserción en el flujo de salida
        friend ostream& operator<< (ostream&, const elemento&);
        friend istream& operator>> (istream&, elemento&);
              
};

/***********************************NODO***************************************/

class nodo{
    private:
        elemento elem;
        ptr_nodo prox;
	
	public:
        //Constructor por defecto
        nodo(void);
        
        void set_elemento(elemento );
        elemento get_elemento();
        void set_ptr(ptr_nodo );
	    ptr_nodo get_ptr();
        	    
};

/********************************Listas*******************************/

class lista{
	protected:
		ptr_nodo ptr;
		int ultimo;
		
	public:
		//constructor
		lista (void);

		//destructor
		~lista(void);
		
		void vacia();
		bool es_vacia();
		void insertar(int , elemento );
		void eliminar(int );
		elemento consultar(int );
		int longitud();
		bool esta(elemento );
		elemento primero();
		void resto();
		
        // Sobrecarga del operador de inserción en el flujo de salida
		friend ostream& operator<< (ostream&, const lista&);
	
};

/********************************Pilas*******************************/

class pila : private lista{
		
	public:
		//constructor
		pila ();
		
		//destructor
		~pila(void);
		
		void vacia();
		bool es_vacia();
		void empilar(elemento );
		void desempilar();
		elemento tope();
	    
	    void ordenar();
	    
        // Sobrecarga del operador de inserción en el flujo de salida
		friend ostream& operator<< (ostream&, const pila&);
	
};

/********************************Colas*******************************/

class cola : private lista{
		
	public:
		//constructor
		cola ();
		
		//destructor
		~cola(void);
		
		void vacia();
		bool es_vacia();
		void encolar(elemento );
		void desencolar();
		elemento frente();
	    
        // Sobrecarga del operador de inserción en el flujo de salida
		friend ostream& operator<< (ostream&, const cola&);
	
};

#endif
