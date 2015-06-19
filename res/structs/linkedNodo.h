#ifndef RES_STRUCTS_LINKEDNODO_H_
#define RES_STRUCTS_LINKEDNODO_H_
#include "nodo.h"
using namespace std;

template<class T> class LinkedNodo: public Nodo<T> {
private:
	int _anterior;
	int _siguiente;

public:
	LinkedNodo();
	LinkedNodo(T pDato);
	~LinkedNodo();
	void setAnterior(int pAnterior);
	void setSiguiente(int pSiguiente);
	int getAnterior();
	int getSiguiente();
};

template<class T>
LinkedNodo<T>::LinkedNodo() {
	super();
	_anterior = 0;
	_siguiente = 0;
}

template<class T>
LinkedNodo<T>::LinkedNodo(T pDato) {
	LinkedNodo<T>* _dato = (LinkedNodo<T>*) malloc(sizeof(LinkedNodo<T> ));
	*_dato = pDato;
	_anterior = 0;
	_siguiente = 0;
}

template<class T>
LinkedNodo<T>::~LinkedNodo() {
	this->~Nodo();
	delete this;
}

template<class T>
void LinkedNodo<T>::setAnterior(int pAnterior) {
	_anterior = pAnterior;
}

template<class T>
void LinkedNodo<T>::setSiguiente(int pSiguiente) {
	_siguiente = pSiguiente;
}

template<class T>
int LinkedNodo<T>::getAnterior() {
	return _anterior;
}

template<class T>
int LinkedNodo<T>::getSiguiente() {
	return _siguiente;
}

#endif /* RES_STRUCTS_LINKEDNODO_H_ */
