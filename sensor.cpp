/*
 * sensor.cpp
 *
 *  Created on: 2021Äê10ÔÂ9ÈÕ
 *      Author: Jiang
 */

#include <random>
#include <iostream>

#include"sensor.h"
using namespace std;
/*
template <class T>


{
 srand((unsigned)time(0));//Afin de g¨¦n¨¦rer diff¨¦rentes valeurs al¨¦atoires

}*/
//template float Sensor<float>::aleaGenVal();
//template int Sensor<int>::aleaGenVal();
//template bool Sensor<bool>::aleaGenVal();
template class Sensor<float>;
template class Sensor<int>;
template class Sensor<bool>;
