/*
 * temperature.cpp
 *
 *  Created on: 2021年10月9日
 *      Author: Jiang
 */
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <ctime>
using namespace std;
#include"temperature.h"
#include"sensor.h"
#include "typesensor.h"
#include "type.h"
#include <chrono>
#include <random>


#include <iomanip>



 float   Temperature::aleaGenVal(){
		float tem;
		std::random_device rd;//Pour générer un nombre aléatoire
		std::default_random_engine eng(rd());
		std::uniform_real_distribution<float> distri(MIN_TEMPERATURE, MAX_TEMPERATURE);
		tem = distri(eng);
		//Pour vérifier si ce nombre aléatoire est hors de portée
		if(tem < MIN_TEMPERATURE) {
			tem = MIN_TEMPERATURE;
			}else if(tem > MAX_TEMPERATURE) {
				tem = MAX_TEMPERATURE;
			}
			return tem;
}

Type<float>  Temperature::getData() {
	    this-> m_temperature.setData(this->aleaGenVal());

	    return this-> m_temperature;

}
