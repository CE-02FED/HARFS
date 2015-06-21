#include "list.h"

List::List(string pName) {
    _file = new FileManager(pName, 1000);
    archivoInicial();
    _index = 0;
}

List::~List() {
}

void List::insertar(Vector<string>* datos) {
    int posRelativa = espacio;

    //_file->open();

    /** Asigna como registro siguiente, si fuera necesario **/
    if (_file->read(primer) != -1)
        _file->write(espacio, posRelativa - 4);


    /** Clave de registro **/
    _file->write(_index, posRelativa);
    posRelativa += 4;
    _index++;

    /** Dato registro **/
    for (int i = 0; i < datos->getHeight(); i++) {
        if ((*datos)[i][1] == "string") {
            _file->write((*datos)[i][3], posRelativa, stoi((*datos)[i][2]));
            posRelativa += stoi((*datos)[i][2]);
        } else if ((*datos)[i][1] == "int") {
            _file->write(stoi((*datos)[i][3]), posRelativa);
            posRelativa += stoi((*datos)[i][2]);
        }
    }

    /** Asigna registro siguiente vacio **/
    _file->write(-1, posRelativa);
    posRelativa += 4;

    /** Establece nuevo primer registro vacio **/
    espacio = posRelativa;
    // _file->writeInt(21, 5);
    _file->write(-1, posRelativa);

    _file->write(20, 1);
   // _file->close();
}

void List::archivoInicial() {
   // _file->open();
    if (_file->read(1) == -1) {
        _file->write(0, 1); // entero a escribir, desplazamiento
        _file->write(20, 5);
        _file->write(-1, 20);
    }
    primer = _file->read(1);
    espacio = _file->read(5);
    //_file->close();
}

FileManager* List::getFile() {
    return _file;
}
