#ifndef RES_STRUCTS_ESTRUCTURA_H_
#define RES_STRUCTS_ESTRUCTURA_H_

template <class T>
class Estructura {
public:
	Estructura();
	~Estructura();
};

template<class T>
Estructura<T>::Estructura() {
}

template<class T>
Estructura<T>::~Estructura() {
	delete this;
}

#endif /* RES_STRUCTS_ESTRUCTURA_H_ */
