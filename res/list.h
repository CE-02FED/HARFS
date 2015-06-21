#ifndef RES_LIST_H_
#define RES_LIST_H_
#include <string>
#include <iostream>
#include "vector.h"
using namespace std;

class List {
private:
	/** Header **/
	int primer;
	int espacio;
	int _index;
	int _offset;
	RAID* _file;

public:
	List(string pName);
	~List();
	void insertar(Vector<string>* pDatos);
	void archivoInicial();
	RAID* getFile();
};

#endif /* RES_LIST_H_ */
