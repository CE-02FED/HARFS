#include <iostream>
#include "res/list.h"
#include "tools/fileManager.h"
using namespace std;

int main(int argc, char *argv[]) {

	/*if (argc != 3) {
	 cout << "Use: hasfs-disk ---config /<path>/<config-file-name>.cfg" << endl;
	 }

	 else {*/
	cout << "== High Availability Register File System ==" << endl << endl;

	//LinkedList* lis = new LinkedList("LISTA.bin");
	List* lista = new List("test/primer.bin");

	Vector<string>* datos = new Vector<string>(3, 4);
	(*datos)[0][0] = "Nombre";
	(*datos)[0][1] = "string";
	(*datos)[0][2] = "30";
	(*datos)[0][3] = "Ernesto";

	(*datos)[1][0] = "Apellido";
	(*datos)[1][1] = "string";
	(*datos)[1][2] = "64";
	(*datos)[1][3] = "Ulate";

	(*datos)[2][0] = "Edad";
	(*datos)[2][1] = "int";
	(*datos)[2][2] = "4";
	(*datos)[2][3] = "19";

	lista->insertar(datos);
	//lis->insertar(datos);

	//FileManager* file = new FileManager("test.bin", 1000);
	//FileManager* file = lis->getFile();
	FileManager* file = lista->getFile();

	file->open();

	/*file->writeInt(20, 1);
	file->writeInt(20, 5);
	file->writeInt(-1, 9);

	file->writeInt(100, 20);
	file->write((*datos)[0][3], 24, stoi((*datos)[0][2]));
	file->write((*datos)[1][3], 54, stoi((*datos)[1][2]));
	file->writeInt(stoi((*datos)[2][3]), 54 + 64);
	file->writeInt(-1, 54 + 64 + 4);*/

	cout << "Header: " << file->readInt(1) << "| ";
	cout << file->readInt(5) << "| ";
	cout << file->readInt(9) << endl;

	cout << "Tabla:" << endl;
	cout << file->readInt(20) << endl;
	cout << *(file->read(24, 30)) << endl;
	cout << *(file->read(54, 64)) << endl;
	cout << file->readInt(118) << endl;
	cout << file->readInt(122) << endl << endl;
	file->close();

	/*cout << "Escribiendo..." << endl;
	 file->write("Hola", 0, 10);
	 file->writeInt(1024, 10);
	 file->write("Mundo**", 18, 10);
	 cout << "Escrito." << endl << endl;

	 cout << "Leyendo..." << endl;
	 string* str = file->read(0, 10);
	 int str3 = file->readInt(10);
	 string* str2 = file->read(18, 10);
	 cout << "Leido." << endl << endl;

	 cout << *str << " " << str3  << " " << *str2 << endl;*/

	cout << "Terminado." << endl;

	return 0;
	//}
}
