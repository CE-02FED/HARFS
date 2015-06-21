#ifndef RES_LIST_H_
#define RES_LIST_H_
#include <string>
#include <iostream>
#include "../../tools/raid.h"
#include "../vector.h"
using namespace std;

class List {
private:
	/** Header **/
	int primer;
	int espacio;
	int _index;
	int _offset;
	RAID* _file;
	Vector<string>* _esquema;

public:
	List(string pName);
	~List();
	void definirEsquema(Vector<string>* pEsquema);
	void insertar(Vector<string>* pDatos);
	void borrar();
	int buscar(string pClave, string pColumna);
	Vector<string>* getRegistro(int pOffset);
	void archivoInicial();
	RAID* getFile();
};

#endif /* RES_LIST_H_ */
