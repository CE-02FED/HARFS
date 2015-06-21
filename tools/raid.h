#ifndef RAID
#include "fileManager.h"
#include <string>
#include <iostream>

#define SIZE 1000
#define NAME_RAID "RAID0.bin"
using namespace std;

class RAID{
public:
    RAID(bool pFlag, string pName);
    void write(string pDato,int pOffSet,int pSize);
    void write(int pDato, int pOffSet);

    string read(int pOffSet,int pSize);
    int read(int pOffSet);
    void close();
private:
    FileManager* _file;
    bool RFlag;
    string RDisk;
    FileManager* RFile;
    void crearRaid();
};

#endif // RAID

