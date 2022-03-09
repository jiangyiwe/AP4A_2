/*
 * light.cpp
 *
 *  Created on: 2021年10月9日
 *      Author: Jiang
 */


#include <iostream>
#include <fstream>
#include <unistd.h>
#include <ctime>
using namespace std;
#include"light.h"
#include "typesensor.h"
#include "type.h"
#include <chrono>
#include <random>
#include"sensor.h"
bool  Light::aleaGenVal(){

	    std::random_device rd;
	    std::default_random_engine eng(rd());
	    std::uniform_int_distribution<int> distri(0, 1);//Pour g��n��rer un nombre al��atoire entre 0 et 1

	    return (bool) distri(eng);

}


 Type<bool>  Light::getData()
{
	this->m_light.setData(this->aleaGenVal());

	    return this->m_light;

}

