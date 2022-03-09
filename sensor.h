/*
 * sensor.h
 *
 *  Created on: 2021Äê10ÔÂ9ÈÕ
 *      Author: Jiang
 */

#ifndef SENSOR_H_
#define SENSOR_H_
#include <cstdlib>
#include <ctime>

#include <random>
#include <iostream>
#include "type.h"
#include "typesensor.h"
template <class T>
class Sensor
{
private:
	Type<T> m_data;
public:

	Sensor(): m_data(){};//constructeur par d¨¦faut
    virtual ~Sensor(){};//d¨¦constructeur
    virtual Type<T> getData()
    {
	 return this->m_data;
    }

protected:
	virtual T aleaGenVal() = 0;//fonction virtual pure

};


#endif /* SENSOR_H_ */
