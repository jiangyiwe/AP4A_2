/*
 * pression.cpp
 *
 *  Created on: 2021年10月9日
 *      Author: Jiang
 */


#include "typesensor.h"
#include "type.h"
#include <chrono>
#include <random>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <ctime>
using namespace std;
#include"pression.h"
#include"sensor.h"


int   Pression::aleaGenVal()
{
	int pre;//Pour g��n��rer un nombre al��atoire
	std::random_device device;
	std::default_random_engine engine(device());
	std::uniform_int_distribution<int> distribution(MIN_PRESSION,MAX_PRESSION);
	pre = distribution(engine);
	//Pour v��rifier si ce nombre al��atoire est hors de port��e
	if(pre < MIN_PRESSION) {
		pre = MIN_PRESSION;
	}else if(pre > MAX_PRESSION) {
		   pre = MAX_PRESSION;
	   }

	return pre;
}

 Type<int> Pression::getData()
 {
	this->m_pression.setData(this->aleaGenVal());

	 return this->m_pression;

 }

