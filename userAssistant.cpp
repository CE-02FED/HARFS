#include "userAssistant.h"

userAssistant::userAssistant()
{
    _diskNode = new DiskNode();
    run();

}

userAssistant::~userAssistant()
{

}

void userAssistant::run()
{
    cout << "Welcome to HARFS (High Availability Resgister File System) file manager program " << endl;
    cout << "What do you want to do:\n 1. Create Storage Block \n 2. Show Storage Block List \n 3. Delete Storage Block\
            \n 4. Define your storage block organization\n 5. Save Register\n 6. Delete Register\n 7. Search\n 8. Get Register\n 9. Create User\
            \n 10. Link User to Storage Block \n 11. Try permissions" << endl;

    cout << "Select the option by its number" << endl;

    int userAction;
    cin >> userAction;

    switch (userAction) {
    case CreateSB:
    {

        int estructuraDatos;

        int raid;
        cout<< " Which Structure would you like?\n 1. LinkedList\n 2. AVL Tree" << endl;
        cout << "Data Structure:" << endl;
        cin >> estructuraDatos;
        cout << "Raid Type: \n 1. NoRaid \n 2. Raid "<< endl;
        cin >> raid;

        createSB(estructuraDatos, raid);

        break;
    }
    case ShowSBList:
    {

        showSB();
        break;
    }
    case DeleteSB:
    {
        string storageBlockID;
        cout << "Storage Block to Delete:" << endl;
        cin >> storageBlockID;

        deleteSB(storageBlockID);
        cout << "\n"<<endl;
        break;
    }
    case DefineSB:
    {
        int items;
        string UID;
        cout << "Storage Block to define:" << endl;
        cin << UID;
        cout << "how many items to insert:" << endl;
        cin << items;
        Vector<string>* parameters = new Vector<string>(items,columnas);

        string parameter;
        string type;
        int size;

        for(int i =0; i< items ; i++)
        {
            cout << "ParameterName:" << cin << parameter;
            cout << "ParameterType:" << cin << type;
            cout << "ParameterSize:" << cin << size;
            cout << "-----------------------"<<endl;
            (*parameters)[i][1] = parameter;
            (*parameters)[i][2] = type;
            (*parameters)[i][3] = to_string(size);
        }

        defineEsquema(UID, parameters);
        break;
    }
    case SaveRegister:
    {
        string UID;
        cout<< "StorageBlock ID: "<<endl;
        cin >> UID;
        string data;
        Vector<string>* datos = new Vector<string>(6);
        for(int i=0; i< 6; i++)
        {
            cout << "Dato:"<< endl;
            cin >> data;
           *(*datos)[i] = data;
        }

        saveRegister(datos,UID);

        break;
    }
    case DeleteRegister:
    {

        string dataID;
        int offset;
        cout << "Storage Block UID: " << endl;
        cin >> dataID;
        cout << "Register offset: " << endl;
        cin >> offset;

        deleteRegister(dataID,offset);

        break;
    }
    case Search:
    {
        string UID;
        string key;
        string pColumna;

        cout << "Storage Block User ID: " << endl;
        cin >> UID;
        cout << "key search: " << endl;
        cin >> key;
        cout << "Column: " << endl;
        cin >> pColumna;

        search(UID,key,pColumna);

        break;
    }
    case GetRegister:
    {
        int offset;
        string UID;
        cout << "Offset StorageBlock: " << endl;
        cin >> UID;

        cout << "Offset StorageBlock: " <<endl;
        cin >> offset;

        get_Register(UID,offset);

        break;
    }
    /*case CreateUser:

        break;
    case LinkUser:

        break;
    case TryPermissions:

        break;*/
     default:
        break;    
    }
    run();
}


void userAssistant::createSB(int pStructure, int pRaidType)
{
    Vector<string>* userVector =  new Vector<string>(2);
    *(*userVector)[0] = pStructure;
    *(*userVector)[1] = to_string(pRaidType);  

    cout << "Storage Block UID: "<< _diskNode->createSB(pStructure, pRaidType) << endl;
    cout <<"\n"<<endl;
}

void userAssistant::showSB()
{
    nodo<string>tmpNodo = _diskNode->showSBList()->getElemento(0);
    for(int i=0; i< _diskNode->showSBList()->getNumEle(); i++)
    {
        cout << *tmpNodo.getDato() << endl;
        tmpNodo = *tmpNodo.getSiguiente();
    }
    cout << "\n"<<endl;
}

void userAssistant::deleteSB(string pUID)
{
    _diskNode->deleteSB(pUID);
}

void userAssistant::defineEsquema(string pSBUID, Vector<string>* parameters)
{
    _diskNode->defineSchema(pSBUID,*parameters);

}

void userAssistant::saveRegister(Vector<string>* pDatos, string pUID)
{
    _diskNode->SaveRegistro(pDatos,pUID);

}

void userAssistant::deleteRegister(string pID, int pOffset)
{
    _diskNode->deleteRegistro(pID,pOffset);
}

void userAssistant::search(string pUID, string pClave, string pColumna)
{
    _diskNode->search(pUID,pClave,pColumna);
    cout << "Offset: "<<endl;
}

void userAssistant::get_Register(string pUID,int pOffset)
{
    _diskNode->get_Register(pUID, pOffset);
}
