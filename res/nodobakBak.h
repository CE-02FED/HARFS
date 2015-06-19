#ifndef NODO_H_
#define NODO_H_

#include <stdlib.h>
using namespace std;

/**
 * 	@class Nodo
 * 	@brief Clase nodo para una lista enlazada
 */
template<class T> class NodoBak {
public:
	NodoBak(T dato);									//Constructor
//	~Nodo();										//Destructor
	T* getDato();								//Obtener dato dentro del nodo
	NodoBak<T>* getSiguiente();						//Obtener nodo siguiente
	NodoBak<T>* getAnterior();							//Obtener nodo anterior
	void setSiguiente(NodoBak* sig);					//Asigna nodo siguiente
	void setAnterior(NodoBak* ant);					//Asigna nodo anterior
	int getIndice();								//Obtener indice del nodo en la lista enlazada
	void setIndice(int num);						//Asignar indice del nodo en la lista enlazada
private:
	T* atributo;									//Dato almacenado en nodo
	NodoBak<T>* anterior;								//Nodo anterior en una lista enlazada
	NodoBak<T>* siguiente;								//Nodo siguiente en una lista enlazada
	int indice;										//Indice del nodo en ua lista enlazada
};

/**
 *	@brief Constructor del nodo
 *	@param dato Dato a almacenar en nodo
 */
template<class T> NodoBak<T>::NodoBak(T dato) {
	atributo = (T*) malloc(sizeof(dato));
	*atributo = dato;
	anterior = siguiente = 0;
	indice = 0;
}

/**
 * 	@brief Obtener dato dentro de nodo
 */
template<class T> T* NodoBak<T>::getDato() {
	return atributo;
}

/**
 * 	@brief Destructor del nodo
 */
//template<class T> Nodo<T>::~Nodo() {
//	delete this;
//}
/**
 * 	@brief Obtiene el nodo siguiente
 */
template<class T> void NodoBak<T>::setSiguiente(NodoBak<T>* sig) {
	siguiente = sig;
}

/**
 * 	@brief Obtiene el nodo anterior
 */
template<class T> void NodoBak<T>::setAnterior(NodoBak<T>* ant) {
	anterior = ant;
}

/**
 * 	@brief Asigna el nodo siguiente
 */
template<class T> NodoBak<T>* NodoBak<T>::getSiguiente() {
	return siguiente;
}

/**
 * 	@brief Asigna el nodo anterior
 */
template<class T> NodoBak<T>* NodoBak<T>::getAnterior() {
	return anterior;
}

/**
 * 	@brief Asignar indice al nodo en una lista enlazada
 */
template<class T> void NodoBak<T>::setIndice(int ind) {
	indice = ind;
}

/**
 * 	@brief Obtener indice del nodo en una lista enlazada
 */
template<class T> int NodoBak<T>::getIndice() {
	return indice;
}

#endif /* NODO_H_ */
