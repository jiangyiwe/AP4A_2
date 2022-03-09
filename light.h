/*
 * light.h
 *
 *  Created on: 2021Äê10ÔÂ9ÈÕ
 *      Author: Jiang
 */

#ifndef LIGHT_H_
#define LIGHT_H_


#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <ctime>
#include<time.h>
#include "typesensor.h"
#include "type.h"
#include"sensor.h"

#define MIN_LIGHT 0
#define MAX_LIGHT 2
class Light : public Sensor<bool> {
private:
 	Type<bool> m_light;

public:

	Light() {
		 this->m_light.setData(1);
		 this->m_light.SetTypesensor(e_light);
	 }

	 virtual  ~Light(){};


	 Type<bool> getData();


	 bool aleaGenVal();
};




#endif /* LIGHT_H_ */
