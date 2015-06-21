#ifndef TOOLS_FILEMANAGER_H_
#define TOOLS_FILEMANAGER_H_
#include <string>
#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

class FileManager {
private:
	string _name;		//Nombre de archivo
	int _size;			//Tamano maximo de archivo
	int _actualSize;	//Tamano actual de archivo
	fstream _file;

public:
	FileManager(string pName, int pMaxSize);
	~FileManager();
	void open();
	void close();
	void write(string pData, int pOffset, int pSize);
	void writeInt(int pNum, int pOffset);
	string read(int pPtr, int pTamano);
	int readInt(int pPtr);
    void printRegister(int initOffSet);
    string getFileName();
    int getSize();
};

#endif /* TOOLS_FILEMANAGER_H_ */
