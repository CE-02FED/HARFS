/*
 * Encriptador.cpp
 *
 *  Created on: 05/06/2015
 *      Author: javier
 */
#include "Encriptador.h"

Encriptador::Encriptador(){
}
char* Encriptador::encriptar(char* cadena, char* llave, int encriptar){
	char alfabetoB[100];
	char alfabetoC[100];
	char alfabeto[2][100];
	char strModificado[100];
	int alf2, pos;

	strcpy(alfabetoB, cadenaDeEncriptamiento);
	strcpy(alfabetoC,  cadenaDeDesencriptamiento);
	strcpy(alfabeto[0], vacio);
	strcpy(alfabeto[1], vacio);
	strcpy(strModificado, vacio);
	strcpy(alfabeto[encriptar], alfabetoB);
	alf2 = (encriptar+1) % 2;

	switch  ( strlen(llave)%3 ) {
	case 0:
		strcpy(alfabeto[alf2], " AeEa"); break;
	case 1:
		strcpy(alfabeto[alf2], "E aeA"); break;
	case 2:
		strcpy(alfabeto[alf2], "e aEA"); break;
	}

	char cad[20];
	int apar1, apar2;
	for (int i =  0; i< strlen(llave) ; i++) {
		cad[0] = llave[i];
		cad[1] = '\0';
		apar1 = apar2 = -1;

		for ( int j=0 ; j<strlen(alfabeto[alf2]); j++)
			if ( alfabeto[alf2][j] == cad[0] ) {
				apar1 = 1;
				break;
			}

		for (int j=0 ; j<strlen(alfabetoB); j++)
			if ( alfabetoB[j] == cad[0] ) {
				apar2 = 1;
				break;
			}

		if ( apar1< 1 && apar2>=1 )
			strcat(alfabeto[alf2], cad);

	}


	apar1 = -1;
	for (int i = 0 ; i<strlen(alfabetoC) ; i++) {
		apar1 = -1;
		cad[0] = alfabetoC[i];
		cad[1] = '\0';

		for (int  j=0 ; j<strlen(alfabeto[alf2]) ; j++) {
			if ( cad[0] == alfabeto[alf2][j]) {
				apar1 = 1;
				break;
			}
		}

		if (apar1 < 1 )
			strcat(alfabeto[alf2], cad);
	}

	for (int i = 0 ; i<strlen(cadena) ; i++) {
		pos = -1;
		cad[0]  = cadena[i];
		cad[1] = '\0';

		for ( int j=0 ; j<strlen(alfabeto[0]) ; j++) {
			if ( cad[0] == alfabeto[0][j] ) {
				pos  = j;
				break;
			}
		}

		if (pos < 0 )
			strcat(strModificado, cad);
		else {
			cad[0] = alfabeto[1][pos];
			cad[1] = '\0';
			strcat(strModificado, cad);
		}
	}

	return strModificado;
}


