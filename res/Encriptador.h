/*
 * encriptar.h
 *
 *  Created on: 05/06/2015
 *      Author: javier
 */
#include <cstdio>
#include "string.h"

#ifndef ENCRIPTAR_H_
#define ENCRIPTAR_H_
#define cadenaDeEncriptamiento "ae AEbc\"dfghijklmnopqrstuvwxyz{0}12345,6789BCDFGHIJKLMNOPQRSTUVWXYZ:"
#define cadenaDeDesencriptamiento "potre42ASD7531sdfghj\"klF}GHwq086:JKLMNBiu,y{VCXZ QWERzxcvbnmaTYUIOP9"
#define vacio ""
class Encriptador{
public:
	Encriptador();
	char* encriptar(char *cadena, char *llave, int encriptar);
};



#endif /* ENCRIPTAR_H_ */
