#include "list.h"

/* Header */
#define FIRST_DATA 0
#define FIRST_EMPTY 4
#define OFFSET 8
#define DATA 20

/* Valores */
#define NULO -1
#define NOTHING 0
#define INT 4
#define STRING "string"
#define INTEGER "int"

List::List(string pName) {
	_file = new RAID(false, pName);
	archivoInicial();
	_index = 0;
}

List::~List() {
}

void List::insertar(Vector<string>* datos) {
	int posRelativa = espacio;

	/** Asigna como registro siguiente, si fuera necesario **/
	if (_file->read(primer) != NULO)
		_file->write(espacio, posRelativa - INT);

	/** Clave de registro **/
	_file->write(_index, posRelativa);
	posRelativa += INT;
	_index++;

	/** Dato registro **/
	int contador = 0;
	for (int i = 0; i < datos->getHeight(); i++) {
		if ((*_esquema)[i][1] == STRING) {
			int tamano = stoi((*_esquema)[i][2]);
			_file->write(*(*datos)[i], posRelativa, stoi((*_esquema)[i][2]));
			posRelativa += tamano;
			contador += tamano;
		} else if ((*_esquema)[i][1] == INTEGER) {
			int tamano = stoi((*_esquema)[i][2]);
			_file->write(stoi(*(*datos)[i]), posRelativa);
			posRelativa += tamano;
			contador += tamano;
		}
	}

	/** Asigna offset de tamano dato **/
	_file->write(contador, OFFSET);

	/** Asigna registro siguiente vacio **/
	_file->write(NULO, posRelativa);
	posRelativa += INT;

	/** Establece nuevo primer registro vacio **/
	espacio = posRelativa;
	_file->write(posRelativa, FIRST_EMPTY);
	_file->write(NULO, posRelativa);

	_file->write(DATA, FIRST_DATA);
}

void List::archivoInicial() {
	if (_file->read(FIRST_DATA) == NULO) {
		_file->write(NOTHING, FIRST_DATA); // entero a escribir, desplazamiento
		_file->write(DATA, FIRST_EMPTY);
		_file->write(NOTHING, OFFSET);
		_file->write(NULO, DATA);
	}
	primer = _file->read(FIRST_DATA);
	espacio = _file->read(FIRST_EMPTY);
}

void List::borrar() {
	int nodoActual = primer;
	int nodoTmp, tamDato;
	while (nodoActual != NULO) {
		tamDato = _file->read(OFFSET);
		nodoTmp = nodoActual;
		nodoActual = _file->read(nodoActual + INT + tamDato);
	}
	_file->write(NULO, nodoTmp + INT + tamDato);
	_file->write(nodoActual, FIRST_EMPTY);

}

int List::buscar(string pClave, string pColumna) {
	int nodoActual = primer;
	while (nodoActual != NULO) {
		for (int i = 0; i < _esquema->getHeight(); i++) {
			if ((*_esquema)[i][0] == pColumna) {
				if (i < 1) {
					if (pClave == _file->read(nodoActual + INT, stoi((*_esquema)[i][2]))) {
						return nodoActual;
					}
				} else {
					if (pClave == _file->read(nodoActual + INT + stoi((*_esquema)[i - 1][2]), stoi((*_esquema)[i][2]))) {
						return nodoActual;
					}
				}
			}
		}
	}
	return 0;
}

void List::definirEsquema(Vector<string>* pEsquema) {
	_esquema = pEsquema;
}

Vector<string>* List::getRegistro(int pOffset) {
	Vector<string>* respuesta = new Vector<string>(_esquema->getHeight());
	for (int i = 0; i < respuesta->lenght(); i++) {
		if (i < 1) {
			*(*respuesta)[i] = _file->read(pOffset + INT, stoi((*_esquema)[i][2]));
		} else {
			*(*respuesta)[i] = _file->read(pOffset + INT + stoi((*_esquema)[i - 1][2]), stoi((*_esquema)[i][2]));
		}
	}
	return respuesta;
}

RAID* List::getFile() {
	return _file;
}

