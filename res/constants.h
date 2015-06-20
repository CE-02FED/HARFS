/*
 * constanst.h
 *
 *  Created on: 09/06/2015
 *      Author: javier
 */
#ifndef CONSTANTES_H_
#define CONSTANTES_H_
#include <string>
#include <iostream>
#include<sstream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
using namespace std;

class Constants{
	public:
    static Constants* getInstance();
    char* stringToChar(string toConvert);
    string integerToString(int entero);
    string punteroToString(void* puntero);
    int stringToint(string st);

	private:
         Constants();
         static Constants* m_pInstancia;
};
#endif CONSTANTES_H_
