#ifndef FILEPARSER_H
#define FILEPARSER_H
#include <iostream>
#include <fstream>
#include <string>
#include "State.h"

class FileParser
{
public:

    static State* parse(std::string str) {

        std::ifstream file(str.c_str(), std::ios::in);

        if(file) {
           char pipe;
           int taille = 0;
           file >> taille;
           int* tab;
           tab = new int[taille*taille];

           for(int i = 0 ; i < taille*taille ; i++) {
               file >> tab[i];
               file >> pipe; // ignore "|"
           }

           file.close();
           return new State(taille, tab);
       }
       std::cout  << "Impossible d'ouvrir le fichier !" << std::endl;
       return NULL;
    }

};

#endif // FILEPARSER_H
