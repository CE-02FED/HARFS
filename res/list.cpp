#include "list.h"

List::List(string pName) {
	_file = new FileManager(pName, 1000);
	archivoInicial();
	_index = 0;
}

List::~List() {
	delete this;
}

void List::insertar(Vector<string>* datos) {
	int posRelativa = espacio;

	_file->open();

	/** Asigna como registro siguiente, si fuera necesario **/
	if (_file->readInt(primer) != -1)
		_file->writeInt(espacio, posRelativa - 4);

	/** Clave de registro **/
	_file->writeInt(_index, posRelativa);
	posRelativa += 4;
	_index++;

	/** Dato registro **/
	for (int i = 0; i < datos->getHeight(); i++) {
		if ((*datos)[i][1] == "string") {
			_file->write((*datos)[i][3], posRelativa, stoi((*datos)[i][2]));
			posRelativa += stoi((*datos)[i][2]);
		} else if ((*datos)[i][1] == "int") {
			_file->writeInt(stoi((*datos)[i][3]), posRelativa);
			posRelativa += stoi((*datos)[i][2]);
		}
	}

	/** Asigna registro siguiente vacio **/
	_file->writeInt(-1, posRelativa);
	posRelativa += 4;

	/** Establece nuevo primer registro vacio **/
	espacio = posRelativa;
	///_file->writeInt(21, 5);
	_file->writeInt(-1, posRelativa);

	_file->writeInt(20, 1);
	_file->close();

}

void List::archivoInicial() {
	_file->open();
	if (_file->readInt(1) == -1) {
		_file->writeInt(0, 1);
		_file->writeInt(20, 5);
		_file->writeInt(-1, 20);
	}
	primer = _file->readInt(1);
	espacio = _file->readInt(5);
	_file->close();
}

FileManager* List::getFile() {
	return _file;
}
