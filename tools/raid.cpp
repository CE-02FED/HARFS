#include "raid.h"
RAID::RAID(bool pFlag, FileManager* pFile){
    RFlag=pFlag;
    _file=pFile;
    RDisk=_file->getFileName()+"RAID0";
    if(RFlag){
        RFile= new FileManager(RDisk,_file->getSize());
    }
}

void RAID::write(string pDato,int pOffSet,int pSize){
    _file->write(pDato,pOffSet,pSize);
    if(RFlag){
        RFile->write(pDato,pOffSet,pSize);
    }

}

void RAID::write(int pDato, int pOffSet){
    _file->writeInt(pDato,pOffSet);
    if(RFlag){
        RFile->writeInt(pDato,pOffSet);
    }
}

string RAID::read(int pOffSet,int pSize){
    return _file->read(pOffSet,pSize);
}

int RAID::read(int pOffSet){
    return _file->readInt(pOffSet);

}
