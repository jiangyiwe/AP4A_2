/*
 * server.h
 *
 *  Created on: 2021年10月9日
 *      Author: Jiang
 */

#ifndef SERVER_H_
#define SERVER_H_


#include <iostream>
#include"sensor.h"
#include"humidity.h"
#include"light.h"
#include"pression.h"
#include"temperature.h"
#include <fstream>
#include "type.h"
#include "typesensor.h"
#include <string>


class Server
{
private:
	bool m_consol_write;
	bool m_file_write;

public:
	 Server(): m_consol_write(true), m_file_write(true){};//constructeur par defaut
	 Server(const Server& server): m_consol_write(server.m_consol_write), m_file_write(server.m_file_write){};//constructeur par recopie
	 virtual ~Server(){};
	 Server(const bool& consol_write, const bool& file_write):
		m_consol_write(consol_write), m_file_write(file_write){};
	 //Voici le constructeur que nous utilisons réellement

	 template<class T>
	 void fileWrite(Type<T>& type);
	 template<class T>
	 void consolWrite(Type<T>& type);
	 void operator=(const Server& server)
	   {
	     this->m_consol_write = server.m_consol_write;
	     this->m_file_write = server.m_file_write;
	   };//operateur d'affectation
	  template <class T>
	  void dataRcv( Type<T> data_p);//Afin de savoir s'il faut exécuter ces deux fonctions
	  void setfilewrite(bool& file_write)
	  {
		 this->m_file_write = file_write;
	  }
	  void setconsolwrite(bool& consol_write)
	  {
		 this->m_consol_write = consol_write;
	  }
	  bool getfilewrite()
	  {
		 return this->m_file_write;
	  }
	  bool consolwrite()
	  {
		 return this->m_consol_write;
	  }


};


#endif /* SERVER_H_ */
