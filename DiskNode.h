#ifndef DISKNODE_H
#define DISKNODE_H

#include <iostream>
#include <string>
#include "diskNodes/storageBlock.h"
#include <cstdio>
#include <stdio.h>
#include <string.h>
#include "res/lista.h"
#include "random"


#define maxCadenaUID 32
#define tamanoAbecedario 33


using namespace std;


class DiskNode
{
private:
    lista<string>* _SBUniqueID;
    lista<StorageBlock>* _SBList;

public:
    DiskNode();
     string createSB(int pStructure, int pRaidType);
     string createUID();
     lista<string> *showSBList();
     void deleteSB(string pUID);
     void defineSchema(string pUID, Vector<string> pParameters);
     void SaveRegistro(Vector<string>* pRegistro,string pUID);
     void deleteRegistro(string pUID, int pOffset);
     string get_Register(string pUID,int pOffset);
     string search(string pUID, string pClave, string pColumna);
};

#endif // DISKNODE_H
