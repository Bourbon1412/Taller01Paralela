#include <iostream>
#include "funciones.h"

using namespace std;


int main( int argc, char** argv){
    
    if (argc == 2){
            archivo(argv[1]);
            participantes();
        }
        else
        {
            std::cout<<"Parametros erroneos."<<std::endl;
            std::cout << "ej: ./bin/programa ruta/archivo.csv" << std::endl;

        }
    
    return 0;
}