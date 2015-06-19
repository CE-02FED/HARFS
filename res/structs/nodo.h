#ifndef RES_STRUCTS_NODO_H_
#define RES_STRUCTS_NODO_H_

/**
 * 	@class Nodo
 * 	Clase del que todos los tipos de nodo heredan
 */
template<class T>
class Nodo {
protected:		//Atributos
	T* _dato;
	int _index;
	int _factorEquilibrio;

public:			//Metodos
	Nodo();
	~Nodo();

	/** Setters y Getters **/
	void setDato(T pDato);
	void setIndex(int pIndex);
	void setFactorEquilibrio(int pFactorEquilibrio);
	T getDato();
	int getIndex();
	int getFactorEquilibrio();

};

template<class T>
Nodo<T>::Nodo() {
	_dato = 0;
	_index = 0;
	_factorEquilibrio = 0;
}

template<class T>
Nodo<T>::~Nodo() {
	delete this;
}

template<class T>
void Nodo<T>::setDato(T pDato) {
	_dato = pDato;
}

template<class T>
void Nodo<T>::setIndex(int pIndex) {
	_index = pIndex;
}

template<class T>
void Nodo<T>::setFactorEquilibrio(int pFactorEquilibrio) {
	_factorEquilibrio = pFactorEquilibrio;
}

template<class T>
T Nodo<T>::getDato() {
	return _dato;
}

template<class T>
int Nodo<T>::getIndex() {
	return _index;
}

template<class T>
int Nodo<T>::getFactorEquilibrio() {
	return _factorEquilibrio;
}

#endif /* RES_STRUCTS_NODO_H_ */
