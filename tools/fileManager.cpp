#include "fileManager.h"

#define EMPTY -1
#define FIRST_DATA 0

FileManager::FileManager(string pName, int pMaxSize) {
	_name = pName;
	_size = pMaxSize;
	_actualSize = 0;
	open();
}

FileManager::~FileManager() {
}

void FileManager::open() {
	_file.open(_name, fstream::binary | fstream::in | fstream::out);
	if (!_file){
		_file.open(_name, fstream::binary | fstream::trunc | fstream::in | fstream::out);
		cout << "Archivo creado." << endl;
		writeInt(EMPTY,FIRST_DATA);
	}
}

void FileManager::close() {
	_file.close();
}

void FileManager::write(string pData, int pOffset, int pSize) {
	_file.seekp(pOffset, fstream::beg);
	_file.write(pData.c_str(), pSize);
}

void FileManager::writeInt(int pNum, int pOffset) {
	int num = pNum;
	_file.seekp(pOffset, fstream::beg);
	_file.write((char*) &num, sizeof(int));
}
void FileManager::printRegister(int initOffSet) {
	cout << "Clave: " << (readInt(initOffSet)) << endl;
	cout << "Nombre: " << read(initOffSet + 4, 30) << endl;
	cout << "Apellido: " << read(initOffSet + 34, 64) << endl;
	cout << "Edad: " << (readInt(initOffSet + 98)) << endl;
}

string FileManager::read(int pPtr, int pTamano) {
	char* buffer = (char*) malloc(pTamano);
	string resultado;
	_file.seekg(pPtr, fstream::beg);
	_file.read(buffer, pTamano);
	resultado.assign(buffer);
	free(buffer);
	return resultado;
}

int FileManager::readInt(int pPtr) {
	int num;
	char* buffer = (char*) malloc(sizeof(int));
	_file.seekg(pPtr, ios_base::beg);
	_file.read(buffer, sizeof(int));
	num = *((int*) buffer);
	free(buffer);
	return num;
}

int FileManager::getSize() {
	return _size;
}

string FileManager::getFileName() {
	return _name;
}
