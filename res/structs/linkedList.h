#ifndef RES_STRUCTS_LINKEDLIST_H_
#define RES_STRUCTS_LINKEDLIST_H_

/** Caracteristicas header **/
#define FIRST_DATA 1
#define FIRST_EMPTY 5
#define OFFSET 9
/****************************/

#define SIZE 1000
#define EMPTY -1
#define INITIAL_OFFSET 20
#define STRING 0
#define INT 4

#include <stdlib.h>
#include <string>
#include <iostream>
#include "../vector.h"
#include "../../tools/fileManager.h"
using namespace std;


class LinkedList {
private:
	/** Caracteristicas header **/
	int _firstDataFile;
	int _firstEmpty;
	int _offset;
	/****************************/

	int _size;
	string _name;
	FileManager* _file;
	void crearHeader();
	int datoRegistro(int posRelativaNodo, Vector<string>* pDatos);

public:
	LinkedList(string pName);
	~LinkedList();
	void insertar(Vector<string>* pDatos);
	int getFirst();
	void deleteLast();
	bool empty();
	int getSize();
	FileManager* getFile();
	void print(int pOffset, int pSize, bool pTipo=true);
};

#endif /* RES_STRUCTS_LINKEDLIST_H_ */
