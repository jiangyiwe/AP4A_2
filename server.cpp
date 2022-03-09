/*
 * server.cpp
 *
 *  Created on: 2021年10月9日
 *      Author: Jiang
 */


#include"sensor.h"
#include"humidity.h"
#include"light.h"
#include"pression.h"
#include"temperature.h"
#include "server.h"
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <ctime>
using namespace std;

#include "type.h"
#include "typesensor.h"

#include <string>

template <class T>
void Server::dataRcv( Type<T> type)
{
  if (this->m_consol_write==true)
  {
    this-> consolWrite(type);

  }
  if (this->m_file_write==true)
  {
    this-> fileWrite(type);
  }
}
template void Server::dataRcv<float>( Type<float> type);//Pour faciliter l'appel ultérieur de cette fonction
template void Server::dataRcv<int>(Type<int> type);
template void Server::dataRcv<bool>( Type<bool> type);

template<class T>
void Server::fileWrite(Type<T>& type) {
		TypeSensor sensorType = type.GetType();
		//Voir dans quel type de fichier ces données sont écrites.
		time_t tmm = time(0);
		char* dt= ctime(&tmm);
		if(sensorType == e_humidity) {
			//std::stringstream stream;
			ofstream infile("humidity.txt", ios::app);
			infile << "Date et heure :" << dt << endl;
			infile << " /Humidity :" << type.GetData()<< "%" << endl;

		}else if(sensorType == e_light) {
			ofstream infile("light.txt", ios::app);
			infile << "Date et heure :" << dt << endl;
			infile << " /Light :" << (type.GetData()?"Allumee" : "Eteinte" ) << endl;

		}else if(sensorType == e_pression) {
			ofstream infile("pression.txt", ios::app);
			infile << "Date et heure :" << dt << endl;
			infile << " /Pression :" << type.GetData()<< "Pa" << endl;

		}else if(sensorType== e_temperature) {
			ofstream infile("temperature.txt", ios::app);
			infile << "Date et heure :" << dt << endl;
			infile << " /Temperature :" << type.GetData()<< "°C" << endl;

		}
        }
template<class T>
void Server::consolWrite(Type<T>& type) {
    //Les différents types de données sont présentés de différentes manières
	TypeSensor sensorType = type.GetType();
	if(sensorType == e_humidity) {
		cout << "Taux de humidité: " <<  std::fixed << type.GetData() << "%" << endl ;
	}else if(sensorType == e_light) {
	   cout << "La lumière est " << (type.GetData() ? "Allumée" : "Eteinte") << endl ;
	}else if(sensorType == e_pression) {
		cout << "Pression: " << type.GetData() << " Pa" << endl ;
	}else if(sensorType == e_temperature) {
		cout << "Température: " <<  type.GetData() << "°C" << endl ;
	}
}
