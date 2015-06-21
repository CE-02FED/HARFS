#ifndef RAID
#include "fileManager.h"
#include <string>
#include <iostream>

#define mil 1000
#define nameRaid "RAID0"
using namespace std;

class RAID{
public:
    RAID(bool pFlag, string pName);
    void write(string pDato,int pOffSet,int pSize);
    void write(int pDato, int pOffSet);

    string read(int pOffSet,int pSize);
    int read(int pOffSet);
private:
    FileManager* _file;
    bool RFlag;
    string RDisk;
    FileManager* RFile;
};

#endif // RAID

