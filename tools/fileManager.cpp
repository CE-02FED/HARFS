#include "fileManager.h"

FileManager::FileManager(string pName, int pMaxSize) {
	_name = pName;
	_size = pMaxSize;
	_actualSize = 0;
	_file = 0;
	_offset = 0;

	open();
}

FileManager::~FileManager() {
	fclose(_file);
	free(_file);
}

void FileManager::open() {
	_file = fopen(_name.c_str(), "r+b"); 		//Abre archivo
	if (!_file) {								//Verifica si existe archivo
		_file = fopen(_name.c_str(), "w+b");	//Crea Archivo si no existe
	}
}

void FileManager::write(string pData, int pOffset, int pSize) {
	fseek(_file, pOffset, SEEK_SET);
	fwrite(pData.c_str(), pSize, 1, _file);
}

string* FileManager::read(int pPtr, int pTamano) {
	char* buffer = (char*) malloc(pTamano);
	fseek(_file, pPtr, SEEK_SET);
	fread(buffer, pTamano, 1, _file);

	string* resultado = new string();
	resultado->assign(buffer);

	return resultado;
}
