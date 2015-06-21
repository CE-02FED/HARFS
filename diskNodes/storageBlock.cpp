#include "storageBlock.h"

string StorageBlock::getName()
{
    return _name;
}

StorageBlock::StorageBlock(string pName, int pTipoEstructura, int pTipoRAID) {
	_name = pName;
	_tipo = pTipoEstructura;
	_tipoRaid = pTipoRAID;
	_esquema = 0;

	/** Estructuras posibles **/
	_lista = 0;
	switch (_tipo) {
		case 1:
			//_lista = new LinkedList<string>(pName);
			break;
			/** Faltan casos **/
	}
}

void StorageBlock::definirEsquema(Vector<string>* pEsquema) {
	_esquema = pEsquema;
}

void StorageBlock::almacenarRegistro(Vector<string>* pDato) {
	Vector<string>* datosOrganizados = new Vector<string>(_esquema->getHeight(),
			_esquema->getWidth() + 1);

	int j;
	for (int i = 0; i < datosOrganizados->getHeight(); i++) {
		for (j = 0; j < _esquema->getWidth(); j++) {
			(*datosOrganizados)[i][j] = (*_esquema)[i][j];
		}
		(*datosOrganizados)[i][j] = *(*pDato)[j];
	}

	switch (_tipo) {
		case 1:
			//_lista->insertar(datosOrganizados);
			break;

	}
}

void StorageBlock::borrarRegistro(int pDesplazamiento) {
}

string StorageBlock::buscar(string pClave, string pColumna) {
}

string StorageBlock::obtenerRegistro(int pDesplazamiento)
{
}
