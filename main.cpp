/*
 * main.cpp
 *
 *  Created on: 2021年10月9日
 *      Author: Jiang
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <ctime>
#include<time.h>
#include"scheduler.h"

using namespace std;

bool Choix()
{
  std::string choix;

  do
  {
    std::cin>>choix;

    if (choix == "yes" || choix == "Yes")
    {
      return true;
    }
    else if (choix == "no" || choix == "No")
    {
      return false;
    }
    else
    {
      std::cout<<"Please choose Yes or No!"<<std::endl;
    }
  } while (!(choix == "yes" || choix == "Yes" ||choix == "no" || choix == "No"));

  return false;
}

int main()
{
  bool log,console;


  srand (time(NULL));
  std::cout<<"Capteurs allumés dans le sous-marin"<<std::endl;

  std::cout<<"Voulez-vous écrire dans les fichiers ?"<<std::endl;
  log=Choix();

  std::cout<<"Voulez-vous écrire dans le consol ?"<<std::endl;
  console=Choix();


  if (!(log == false && console == false))
  {
   Scheduler schedule(console,log);
    schedule.affiche();
  }

  return EXIT_SUCCESS;
}
