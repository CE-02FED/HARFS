#ifndef TOOLS_FILEMANAGER_H_
#define TOOLS_FILEMANAGER_H_
#include <stdio.h>
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

class FileManager {
private:
	string _name;		//Nombre de archivo
	int _size;			//Tamano maximo de archivo
	int _actualSize;	//Tamano actual de archivo
	FILE* _file;
	int _offset;

public:
	FileManager(string pName, int pMaxSize);
	~FileManager();
	void open();
	void write(string pData, int pOffset, int pSize);
	string* read(int pPtr, int pTamano);

};

#endif /* TOOLS_FILEMANAGER_H_ */
