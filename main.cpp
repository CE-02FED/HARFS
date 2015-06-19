#include <iostream>
#include "tools/fileManager.h"
using namespace std;

int main(int argc, char *argv[]) {

	if (argc != 3) {
		cout << "Use: hasfs-disk ---config /<path>/<config-file-name>.cfg" << endl;
	}

	else {
		cout << "== High Availability Register File System ==" << endl << endl;

		/* FileManager* file = new FileManager("test.bin", 10);

		cout << "Escribiendo..." << endl;
		file->write("Hola", 0, 10);
		file->write("Mundo**", 10, 10);
		cout << "Escrito." << endl << endl;

		cout << "Leyendo..." << endl;
		string* str = file->read(0, 10);
		string* str2 = file->read(10, 10);
		cout << "Leido." << endl << endl;

		cout << *str << " " << *str2 << endl; */

		cout << "Terminado." << endl;

		return 0;
	}
}
