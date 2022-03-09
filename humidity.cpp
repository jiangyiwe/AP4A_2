/*
 * humidity.cpp
 *
 *  Created on: 2021年10月9日
 *      Author: Jiang
 */


#include <iostream>
#include <fstream>
#include <unistd.h>
#include <ctime>
using namespace std;
#include"humidity.h"
#include"sensor.h"


#include <iomanip>
#include "typesensor.h"
#include "type.h"
#include <chrono>
#include <random>



float  Humidity::aleaGenVal()
{
	float hum;//Pour g��n��rer un nombre al��atoire
	std::random_device rd;
	std::default_random_engine eng(rd());
	std::uniform_real_distribution<float> distribution(MIN_HUMIDITY, MAX_HUMIDITY);
	hum = distribution(eng);
	//Pour v��rifier si ce nombre al��atoire est hors de port��e
	if( hum < MIN_HUMIDITY) {
		 hum = MIN_HUMIDITY;
		}else if( hum > MAX_HUMIDITY) {
			 hum = MAX_HUMIDITY;
		}

		return hum;
}

Type<float>  Humidity::getData()
 {
	this->m_humidity.setData(this->aleaGenVal());

	return this->m_humidity;

 }

