#ifndef LISTA_H_
#define LISTA_H_

#include <stdlib.h>
#include <iostream>

#include "nodoBak.h"
using namespace std;

/**
 * 	@class Lista
 * 	@brief Lista doblemente enlazada
 */
template<class T> class Lista {
public:
	Lista();						//Constructor
	~Lista();						//Destructor
	void insertarFinal(T dato);		//Inserta un elemento al final
	void insertarInicio(T dato);	//Inserta un elemento al inicio
	void print();					//Imprime la lista en consola
	NodoBak<T>* getPrimer();			//Obtener el primer elemento
	NodoBak<T>* getUltimo();			//Obtener el ultimo elemento
	NodoBak<T>* getElemento(int ind);	//Obtener elemento del indice
	void borrarElemento(int ind);	//Borrar elemento de la lista
private:
	NodoBak<T>* primer;				//Primer nodo de la lista
	NodoBak<T>* ultimo;				//Ultimo nodo de la lista
	bool vacia();					//Verifica si esta vacia la lista
	int contador;					//Contador de elementos
	void sumInd(NodoBak<T>* nodo);		//Suma indices
	void resInd(NodoBak<T>* nodo);		//Resta indices
};

/**
 * 	@brief Constructor de la lista
 */
template<class T> Lista<T>::Lista() {
	primer = ultimo = 0;
	contador = 0;
}

/**
 * 	@brief Destructor de la lista
 */
template<class T> Lista<T>::~Lista() {
	free(primer);
	free(ultimo);
}

/**
 * 	@brief Inserta un elemento al final
 * 	@param Dato a insetar
 */
template<class T> void Lista<T>::insertarFinal(T dato) {
	NodoBak<T>* nodo = (NodoBak<T>*) malloc(sizeof(NodoBak<T> ));
	new (nodo) NodoBak<T>(dato);
	if (vacia()) {
		primer = ultimo = nodo;
		nodo->setIndice(0);
		contador++;
	} else {
		nodo->setAnterior(ultimo);
		ultimo->setSiguiente(nodo);
		ultimo = nodo;
		nodo->setIndice(contador);
		contador++;
	}
}

/**
 * 	@brief Inserta un elemento al inicio
 * 	@param Dato a insetar
 */
template<class T> void Lista<T>::insertarInicio(T dato) {
	NodoBak<T>* nodo = (NodoBak<T>*) malloc(sizeof(NodoBak<T> ));
	new (nodo) NodoBak<T>(dato);
	if (vacia()) {
		primer = ultimo = nodo;
		nodo->setIndice(0);
		contador++;
	} else {
		nodo->setSiguiente(primer);
		primer->setAnterior(nodo);
		sumInd(primer);
		primer = nodo;
		contador++;
	}
}

/**
 * 	@brief Borra un elemento de la lista
 */
template<class T> void Lista<T>::borrarElemento(int ind) {
	NodoBak<T>* actual = primer;
	while (actual != 0) {
		if (((int) actual->getIndice()) != ind) {
			actual = actual->getSiguiente();
		} else {
			resInd(actual->getSiguiente());
			NodoBak<T>* aux = actual->getAnterior();
			if (aux != 0)
				aux->setSiguiente(actual->getSiguiente());
			aux = actual->getSiguiente();
			if (aux != 0)
				aux->setAnterior(actual->getAnterior());
			break;
		}
	}
}

/**
 * 	@brief Suma indices desde un nodo
 */
template<class T> void Lista<T>::sumInd(NodoBak<T>* nodo) {
	NodoBak<T>* actual = nodo;
	while (actual != 0) {
		actual->setIndice(actual->getIndice() + 1);
		actual = actual->getSiguiente();
	}
}

/**
 * 	@brief Resta indices desde un nodo
 */
template<class T> void Lista<T>::resInd(NodoBak<T>* nodo) {
	NodoBak<T>* actual = nodo;
	while (actual != 0) {
		actual->setIndice(actual->getIndice() - 1);
		actual = actual->getSiguiente();
	}
}

/**
 * 	@brief Obtiene primer elemento
 */
template<class T> NodoBak<T>* Lista<T>::getPrimer() {
	return primer;
}

/**
 * 	@brief Obtiene ultimo elemento
 */
template<class T> NodoBak<T>* Lista<T>::getUltimo() {
	return ultimo;
}

template<class T> NodoBak<T>* Lista<T>::getElemento(int ind) {
	NodoBak<T>* actual = primer;
	while (actual != 0) {
		if (actual->getIndice() != ind)
			actual = actual->getSiguiente();
		else
			return actual;
	}
}

/**
 * 	@brief Imprime la lista en consola
 */
template<class T> void Lista<T>::print() {
	if (!vacia()) {
		NodoBak<T>* actual = primer;
		while (*(actual->getDato()) != 0) {
			cout << "| " << *(actual->getDato()) << endl;
			actual = actual->getSiguiente();
		}
	} else
		cout << "Lista vacia" << endl;
}

/**
 * 	@brief Verficia si esta vacia la lista
 */
template<class T> bool Lista<T>::vacia() {
	if (primer == 0 and ultimo == 0) {
		return true;
	} else
		return false;
}

#endif /* LISTA_H_ */
