/*
 * constanst.cpp
 *
 *  Created on: 09/06/2015
 *      Author: javier
 */
#include "constants.h"

Constants* Constants::m_pInstancia = 0;
Constants* Constants::getInstance(){
	if (!m_pInstancia){
        m_pInstancia = new Constants();
	}
	return m_pInstancia;
}
Constants::Constants(){

}

char*  Constants::stringToChar(string toConvert){
	 char *schar = new char[toConvert.length() + 1];
	 strcpy(schar, toConvert.c_str());
	 return schar;
 }
string Constants::punteroToString(void* puntero){
    const void* address= static_cast<const void*>(puntero);
    stringstream ss;
    ss<<address;
    string name=ss.str();
    return name;
}

string Constants::integerToString(int entero){
     string cadena;
     stringstream ss;
     ss << entero;
     cadena = ss.str();
      return cadena;
}

