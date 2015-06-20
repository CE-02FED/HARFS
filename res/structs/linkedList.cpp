#include "linkedList.h"

LinkedList::LinkedList(string pName) {
	_size = 0;
	_name = pName;
	_file = new FileManager(pName, SIZE);

	if (empty())
		crearHeader();

	_file->open();
	_firstDataFile = _file->readInt(1);
	_firstEmpty = _file->readInt(5);
	_offset = _file->readInt(9);
	_file->close();

}

LinkedList::~LinkedList() {
	delete this;
}

int LinkedList::datoRegistro(int posRelativaNodo, Vector<string>* pDatos) {

	for (int i = 0; i < pDatos->getHeight(); i++) {
		if (stoi((*pDatos)[i][1]) == 0) {
			//Insercion de string
			string dato = (*pDatos)[i][3];
			int tamanoRelativo = stoi((*pDatos)[i][2]);
			_file->write(dato, posRelativaNodo, tamanoRelativo);
			posRelativaNodo += tamanoRelativo;

		} else if (stoi((*pDatos)[i][1]) == 4) {
			//Insercion de int
			int dato = stoi((*pDatos)[i][3]);
			_file->writeInt(dato, posRelativaNodo);
			posRelativaNodo += 4;

		}
	}

	return posRelativaNodo;
}

void LinkedList::insertar(Vector<string>* pDatos) {
	_file->open();

	int posRelativaNodo = _firstEmpty;		//Posicion del registro

	/** Asigna como registro siguiente **/
	if (_file->readInt(_firstDataFile) != -1)
		_file->writeInt(_firstEmpty, posRelativaNodo - 4);

	/** Clave de registro **/
	_size += 100;
	_file->writeInt(_size, posRelativaNodo);
	posRelativaNodo += 4;

	/** Dato registro **/
	posRelativaNodo = datoRegistro(posRelativaNodo, pDatos);

	/** Asigna registro siguiente vacio **/
	_file->writeInt(-1, posRelativaNodo);
	posRelativaNodo += INT;

	/** Establece tamano de desplazamiento **/
	_offset = posRelativaNodo - _firstEmpty;
	_file->writeInt(_offset, 9);

	/** Establece nuevo primer registro vacio **/
	_firstEmpty = posRelativaNodo;
	_file->writeInt(_firstEmpty, 5);
	cout << "¡Insertado con éxito!" << endl;
	_file->close();
}

int LinkedList::getFirst() {
	return _firstDataFile;
}

void LinkedList::deleteLast() {
}

bool LinkedList::empty() {
	_file->open();
	if (_file->readInt(1) == -1) {
		_file->close();
		return true;
	} else {
		_file->close();
		return false;
	}
}

int LinkedList::getSize() {
	return _size;
}

void LinkedList::crearHeader() {
	_file->open();
	_file->writeInt(20, 1);
	_file->writeInt(20, 5);
	_file->writeInt(-1, 9);
	_file->writeInt(-1, 20);
	_file->close();
}

FileManager* LinkedList::getFile() {
	return _file;
}
