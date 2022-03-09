/*
 * temperature.h
 *
 *  Created on: 2021年10月9日
 *      Author: Jiang
 */

#ifndef TEMPERATURE_H_
#define TEMPERATURE_H_


#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <ctime>
#include<time.h>
#include"sensor.h"
#include"type.h"
#include "typesensor.h"
#define MAX_TEMPERATURE 40.0f
#define MIN_TEMPERATURE 0.0f

class Temperature : public Sensor<float>
{

private:

		Type<float>  m_temperature;


public:
//constructeur
        Temperature() {
            this->m_temperature.setData(14.5f);
            this->m_temperature.SetTypesensor(e_temperature);
        }



        ~Temperature(){};


         Type<float> getData();

         float aleaGenVal();

};



#endif /* TEMPERATURE_H_ */
