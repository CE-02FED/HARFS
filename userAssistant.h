#ifndef USERASSISTANT_H
#define USERASSISTANT_H

#include <iostream>
#include <string>
#include "res/vector.h"
#include "DiskNode.h"
#include "res/nodos.h"

#define CreateSB 1
#define ShowSBList 2
#define DeleteSB 3
#define DefineSB 4
#define SaveRegister 5
#define DeleteRegister 6
#define Search 7
#define GetRegister 8
#define CreateUser 9
#define LinkUser 10
#define TryPermissions 11

#define columnas 3

using namespace std;

class userAssistant
{
private:
    DiskNode* _diskNode;
public:
    userAssistant();
    ~userAssistant();
    void run();
    void createSB(int pStructure, int pRaidType);
    void showSB();
    void defineEsquema(string pSBUID, Vector<string>* parameters);
    void saveRegister(Vector<string> *pDatos, string pUID);
    void deleteRegister(string pID, int pOffset);
    void search(string pUID, string pClave, string pColumna);
    void get_Register(string pUID, int pOffset);
    void deleteSB(string pUID);

};

#endif // USERASSISTANT_H
