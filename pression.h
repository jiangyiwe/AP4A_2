/*
 * pression.h
 *
 *  Created on: 2021Äê10ÔÂ9ÈÕ
 *      Author: Jiang
 */

#ifndef PRESSION_H_
#define PRESSION_H_


#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <ctime>
#include<time.h>
#include"sensor.h"
#include "typesensor.h"
#include "type.h"
#define MIN_PRESSION 90000
#define MAX_PRESSION 110000


class Pression : public Sensor<int> {
private:
      Type<int> m_pression;
public:

	Pression(){
		this->m_pression.setData(1000000);
		this->m_pression.SetTypesensor(e_pression);
	};

	virtual  ~Pression(){};

    Type<int> getData();

    int aleaGenVal();
};



#endif /* PRESSION_H_ */
