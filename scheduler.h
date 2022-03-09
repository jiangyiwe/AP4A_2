/*
 * scheduler.h
 *
 *  Created on: 2021年10月9日
 *      Author: Jiang
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_
#include <iostream>
#include <chrono>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#define Sleep(x) usleep((x)*1000)
#endif
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <ctime>
#include <cstring>
#include<time.h>
#include"server.h"
#include"sensor.h"
#include "type.h"
#include "typesensor.h"
#include"humidity.h"
#include"light.h"
#include"pression.h"
#include"temperature.h"
#define REFRESH_PERIOD 1000
#define LIGHT_PERIOD 5000
#define TEMPERATURE_PERIOD 3000
#define PRESSION_PERIOD 2000
#define HUMIDITY_PERIOD 1500
//Définir le temps de retard comme une variable globale
using namespace std;
using namespace chrono;
#include <chrono>
#include <thread>
#include <ratio>


class Scheduler {
    private:
	 Server m_server;
	 Light m_light;
	 Temperature m_temperature;
	 Humidity m_humidity;
	 Pression m_pression;

    public:
        // Définition de la forme canonique
	 Scheduler():m_server(),m_light(),m_temperature(),m_humidity(),m_pression()
	 {

	 }

	 Scheduler( Scheduler& scheduler):m_server(scheduler.m_server),m_light(scheduler.m_light),
	     m_temperature(scheduler.m_temperature),m_humidity(scheduler.m_humidity),
	     m_pression(scheduler.m_pression)
	 {

	 }
       ~Scheduler(){};
//Voici le constructeur que nous allons utiliser
        Scheduler(bool console,bool log):m_server(console,log),m_light(),m_temperature(),m_humidity(),m_pression()
        {

        }



      void affiche(){

		   auto now = steady_clock::now();
		   auto lightClock = steady_clock::now();
		   auto temperatureClock = steady_clock::now();
		   auto pressionClock = steady_clock::now();
           auto humidityClock = steady_clock::now();
		   while(1){
			 now =  steady_clock::now();
			 //Définissez le temps pour prolonger le transfert de données,
			 //puis une minuterie sera programmée pour commencer l'écriture et l'affichage du fichier
			 //lorsque l'événement correspondant est atteint
			 if(now - temperatureClock > milliseconds(TEMPERATURE_PERIOD))
			 {
			   this->m_server.dataRcv(m_temperature.getData());
			   temperatureClock = steady_clock::now();
			 }
			if(now - humidityClock > milliseconds(HUMIDITY_PERIOD))
			{
				this->m_server.dataRcv(m_humidity.getData());
				humidityClock = steady_clock::now();
			}

			if(now - pressionClock > milliseconds(PRESSION_PERIOD))
			{

				 this->m_server.dataRcv( m_pression.getData());
				 pressionClock = steady_clock::now();
			}

			if(now - lightClock > milliseconds(LIGHT_PERIOD))
			{

				 this->m_server.dataRcv(  m_light.getData());
				lightClock = steady_clock::now();
			}
				 Sleep(REFRESH_PERIOD);
	     }
        }

};
#endif /* SCHEDULER_H_ */
