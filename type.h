/*
 * type.h
 *
 *  Created on: 2021年10月20日
 *      Author: Jiang
 */

#ifndef TYPE_H_
#define TYPE_H_

#include "typesensor.h"

template <class T>
class Type
{
private:
//D¨¦finir une classe pour combiner les donn¨¦es et les types de capteurs ensemble
	  TypeSensor m_TypeSensor;
	  T m_data;
public:
	  Type():m_TypeSensor(TypeSensor::e_default),m_data(){};//constructeur par defaut

	  Type(const Type& type):m_TypeSensor(type.m_TypeSensor),m_data(type.m_data){};//constructeur par recopie

	  ~Type(){};

	  Type<T>& operator=(const Type& type)
	  {
		  m_TypeSensor=type.m_TypeSensor;
		  m_data=type.m_data;
		  return (*this);
	  };


	  Type(TypeSensor type,T data)
	  {
		  m_TypeSensor = type;
		  m_data = data;
	  };

	  TypeSensor GetType()
	  {
		return this->m_TypeSensor;
	  };//pour obtenir de  type

	  void SetTypesensor(const TypeSensor& typesensor)
		{
		  this->m_TypeSensor=typesensor;
		};//pour definir de type

	  void setData(const T& data) {
				  this->m_data = data;
			  }//pour definir des donnes


	  T GetData()
	  {
		return this->m_data;
	  };//pour obtenir des donnes



};

#endif /* TYPE_H_ */
