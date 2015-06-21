#include "raid.h"

RAID::RAID(bool pFlag, string pName){
    RFlag=pFlag;
    _file=new FileManager(pName,SIZE);
    if(RFlag){
    	crearRaid();
        RFile= new FileManager(RDisk,SIZE);
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

void RAID::close() {
	_file->close();
}

void RAID::crearRaid() {
	RDisk = _file->getFileName();
	for (int i=0; i < 4; i++) {
		RDisk.erase(RDisk.length()-1);
	}
	RDisk += NAME_RAID;
}
