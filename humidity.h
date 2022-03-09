/*
 * humidity.h
 *
 *  Created on: 2021Äê10ÔÂ9ÈÕ
 *      Author: Jiang
 */

#ifndef HUMIDITY_H_
#define HUMIDITY_H_



#include <iostream>
#include <stdlib.h>
#include <string.h>

#include"sensor.h"
//#include "type.h"

#define MIN_HUMIDITY 30.0f
#define MAX_HUMIDITY 90.0f

class Humidity : public Sensor<float> {
    private:

   Type<float> m_humidity;

    public:

    Humidity() {
       this-> m_humidity.setData(50.0f);
       this-> m_humidity.SetTypesensor(e_humidity);
   }

	virtual ~Humidity(){};

	Type<float> getData();

	float aleaGenVal();
};

#endif /* HUMIDITY_H_ */
