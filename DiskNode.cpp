#include "DiskNode.h"

DiskNode::DiskNode()
{
    _SBUniqueID = new lista<string>();
    _SBList = new lista<StorageBlock>();
}

string DiskNode::createSB(int pStructure, int pRaidType)
{
    string UIDName = createUID();

    StorageBlock* _storageBlock = new StorageBlock(UIDName,pStructure, pRaidType);


    _SBUniqueID->agregarFinal(&UIDName);

    _SBList->agregarFinal(_storageBlock);

    return UIDName;
}

lista<string> *DiskNode::showSBList()
{
    return _SBUniqueID;
}


/**
 * @brief DiskNode::deleteSB
 * ELIMINAR STORAGE BLOCK
 * @param pUID
 */
void DiskNode::deleteSB(string pUID)
{
    nodo<StorageBlock>* tmpNodo = _SBList->getNodo(0);
    for(int i =0; i< _SBUniqueID->getNumEle(); i++)
    {
        StorageBlock tmpSB = *tmpNodo->getDato();
        if(tmpSB.getName() == (pUID))
        {
            _SBList->eliminar(i);
            break;
        }
        tmpNodo = tmpNodo->getSiguiente();
    }
}

void DiskNode::defineSchema(string pUID, Vector<string> pParameters)
{
    nodo<StorageBlock>* tmpNodo = _SBList->getNodo(0);
    for(int i =0; i< _SBUniqueID->getNumEle(); i++)
    {
        StorageBlock tmpSB = *tmpNodo->getDato();
        if(tmpSB.getName() == (pUID))
        {
            tmpSB.definirEsquema(&pParameters);
            break;
        }
        tmpNodo = tmpNodo->getSiguiente();
    }
}

void DiskNode::SaveRegistro(Vector<string> *pRegistro, string pUID)
{
    nodo<StorageBlock> tmpNodo = _SBList->getElemento(0);
    for(int i =0; i< _SBUniqueID->getNumEle(); i++)
    {
        StorageBlock* tmpSB = tmpNodo.getDato();
        if(tmpSB->getName() == (pUID))
        {
            tmpSB->almacenarRegistro(pRegistro);
            break;
        }
        tmpNodo = *tmpNodo.getSiguiente();
    }

}

void DiskNode::deleteRegistro(string pUID,int pOffset)
{
    nodo<StorageBlock>* tmpNodo = _SBList->getNodo(0);
    for(int i =0; i< _SBUniqueID->getNumEle(); i++)
    {
        StorageBlock tmpSB = *tmpNodo->getDato();
        if(tmpSB.getName() == (pUID))
        {
            tmpSB.borrarRegistro(pOffset);
            break;
        }
        tmpNodo = tmpNodo->getSiguiente();
    }
}

string DiskNode::get_Register(string pUID, int pOffset)
{
    nodo<StorageBlock>* tmpNodo = _SBList->getNodo(0);
    for(int i =0; i< _SBUniqueID->getNumEle(); i++)
    {
        StorageBlock tmpSB = *tmpNodo->getDato();
        if(tmpSB.getName() == (pUID))
        {
            return tmpSB.obtenerRegistro(pOffset);
            break;
        }
        tmpNodo = tmpNodo->getSiguiente();
    }
}

string DiskNode::search(string pUID, string pClave, string pColumna)
{
    nodo<StorageBlock>* tmpNodo = _SBList->getNodo(0);
    for(int i =0; i< _SBUniqueID->getNumEle(); i++)
    {
        StorageBlock tmpSB = *tmpNodo->getDato();
        if(tmpSB.getName() == (pUID))
        {
            return tmpSB.buscar(pClave,pColumna);
            break;
        }
        tmpNodo = tmpNodo->getSiguiente();
    }
}





string DiskNode::createUID()
{
    char abecedario[tamanoAbecedario];
    strcpy(abecedario, "abcdefghijklmnopqrstvwxyz123456789");

    srand(0);
    string UID ="";


    for(int i=0; i<maxCadenaUID; i++)
    {
        UID = UID+ abecedario[rand()%tamanoAbecedario];
    }
    return UID;
}




