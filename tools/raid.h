#ifndef RAID
#include "fileManager.h"
#include <string>
#include <iostream>
//#include "userAsistant.h"

using namespace std;

class RAID{
public:
    RAID(bool pFlag, FileManager* file);
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

