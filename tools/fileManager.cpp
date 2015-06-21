#include "fileManager.h"

#define EMPTY -1
#define FIRST_DATA 1

FileManager::FileManager(string pName, int pMaxSize) {
	_name = pName;
	_size = pMaxSize;
	_actualSize = 0;
	_offset = 0;
}

FileManager::~FileManager() {
}

/*void FileManager::open() {
    _file->open(_name.c_str(),ios_base::binary|ios_base::in|ios_base::out); 		//Abre archivo
    if (!_file) {								//Verifica si existe archivo
        _file = new ofstream(_name.c_str(),ios_base::binary | ios_base::in | ios_base::out); //Crea Archivo si no existe
		this->writeInt(-1,1);
	}
}*/
void FileManager::write(string pData, int pOffset, int pSize) {
    ofstream* _wFile = new ofstream(_name.c_str(),ios_base::binary | ios_base::in | ios_base::out);
    const char* buffer= pData.c_str();
    _wFile->seekp(pOffset,ios_base::beg);
    _wFile->write(buffer,pSize);
    _wFile->close();
    free(_wFile);
}

void FileManager::writeInt(int pNum, int pOffset) {
    ofstream* _wFile = new ofstream(_name.c_str(),ios_base::binary | ios_base::in | ios_base::out);
    const char* buffer= (char*)&pNum;
    _wFile->seekp(pOffset,ios_base::beg);
    _wFile->write(buffer,sizeof(int));
    _wFile->close();
    free(_wFile);
}
void FileManager::printRegister(int initOffSet){
    cout<<"Clave: "<<(readInt(initOffSet))<<endl;
    cout<<"Nombre: "<<*(read(initOffSet+4,30))<<endl;
    cout<<"Apellido: "<<*(read(initOffSet+34,64))<<endl;
    cout<<"Edad: "<<(readInt(initOffSet+98))<<endl;

}

string* FileManager::read(int pPtr, int pTamano) {
    ifstream* _rFile = new ifstream(_name.c_str(),ios_base::binary | ios_base::in | ios_base::out);
    char* buffer= (char*)malloc(pTamano);
    _rFile->seekg(pPtr,ios_base::beg);
    _rFile->read(buffer,pTamano);
	string* resultado = new string();
	resultado->assign(buffer);
    free(buffer);
    _rFile->close();
    free(_rFile);
	return resultado;
}

int FileManager::readInt(int pPtr) {
     ifstream* _rFile = new ifstream(_name.c_str(),ios_base::binary | ios_base::in | ios_base::out);
	int num;
    char* buffer= (char*)malloc(sizeof(int));
    _rFile->seekg(pPtr,ios_base::beg);
    _rFile->read(buffer,sizeof(int));
    num=*((int*)buffer);
    _rFile->close();
    free(_rFile);
    return num;
}
int FileManager::getSize(){
    return _size;
}

string FileManager::getFileName(){
    return _name;
}
