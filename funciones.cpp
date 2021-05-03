#include "funciones.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>



void participantes()
{
    std::cout <<"---> INTEGRANTES <---"<<std::endl;

    std::cout << std::endl
              << "Cristobal Valenzuela";
    std::cout << std::endl
              << "Miguel Martinez";
    std::cout << std::endl
              << "Andres Mella" << std::endl;
}



void replace(std::string &subject, const std::string &search, const std::string &replace)
{

    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos)
    {
        subject.replace(pos, search.length(), replace);
        pos += replace.length();
    }
}

std::vector<std::string> split(std::string s, std::string lim)
{
    size_t inicio = 0, final, largo = lim.length();
    std::string token;
    std::vector<std::string> res;

    while ((final = s.find(lim, inicio)) != std::string::npos)
    {
        token = s.substr(inicio, final - inicio);
        inicio = final + largo;
        res.push_back(token);
    }

    res.push_back(s.substr(inicio));
    return res;
}

void archivo(char *valor1)
{
    std::string maximos[99];
    float matriz[1499][2];
    float id;
    int i=0,count=0,n=0, m=0;
    float  Lenguaje = 0,educacionFisica = 0; 
    float ingles = 0, matematicas = 0, ciencias = 0, historia = 0, tecnologia = 0, arte = 0,promc=0;
    std::string linea;
    std::vector<std::string> estudiantes;
    std::vector<std::string> promedios;

    std::ifstream archivo(valor1);
    if (archivo.is_open())
    {
        estudiantes.clear();
        while(getline(archivo,linea)){
            replace(linea, "\"", "");
            estudiantes.push_back(linea);
        }
        archivo.close();
        
        for (int x = 0; x < estudiantes.size(); x++)
        {
            std::string csv = "";
            std::vector<std::string> lugar = split(estudiantes[x], ";" );
            id=std::stof(lugar[0]);
            Lenguaje = std::stof(lugar[2]);
            ingles = std::stof(lugar[3]);
            matematicas = std::stof(lugar[4]);
            ciencias = std::stof(lugar[5]);
            historia = std::stof(lugar[6]);
            tecnologia = std::stof(lugar[7]);
            arte = std::stof(lugar[8]);
            educacionFisica = std::stof(lugar[9]);
            float promedio = (Lenguaje + ingles + matematicas + ciencias + historia + tecnologia + arte + educacionFisica)/8;
            //std::cout << promedio << std::endl;
            matriz[count][1]=id;
            matriz[count][2]=promedio;
            count=count+1;
     
            

            
        //     if (promc<=promedio)
        //     {
        //         promc=promedio;
        //         for(int a = 0; a < 99 ; a++){
        //             if (maximos[a]==id){
        //                 count=count+1;

        //             }   
                
        //         }
        //         if(count==0){
        //             maximos[n]=id;
        //             count=0;
        //             n=n+1;
                
                
        //         }

        //     }

                
                
            
        // } 
        // for(int o=0;o<99;o++){
        //      std::cout << maximos[o]<< std::endl;
            
        // }

        
        
              
        }
      
    }
    /*while ( m!=100 )
    {
        for (int y = 0; y <1499; y++)
        {
            int max = 0;
            float promaux[99];
            if (promi[y]> max)
            {
                max=promi[y];

            }
            
            
        }
        m=m+1;
    }*/
    
    else{
        std::cout << "No se pudo abrir el archivo";
    }
}