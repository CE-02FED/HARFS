#ifndef RES_STORAGEBLOCK_H_
#define RES_STORAGEBLOCK_H_
#include <string>
#include "../res/structs/linkedList.h"
#include "../res/vector.h"
using namespace std;

class StorageBlock {
private:		//Atributos
	string _name;
	int _tipo;
	int _tipoRaid;
	Vector<string>* _esquema;

	/** Estructuras posibles */
	LinkedList* _lista;


public:			//Metodos
    string getName();
	StorageBlock();
    StorageBlock(string pName, int pTipoEstructura, int pTipoRAID);	
	void definirEsquema(Vector<string>* pEsquema);
	void almacenarRegistro(Vector<string>* pDato);
	void borrarRegistro(int pDesplazamiento);
    string buscar(string pClave, string pColumna);
    string obtenerRegistro(int pDesplazamiento);
};

#endif /* RES_STORAGEBLOCK_H_ */
