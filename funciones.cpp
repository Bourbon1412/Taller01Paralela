#include "funciones.h"
#include <iostream>
#include <algorithm>
#include <functional>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <math.h>

void participantes()
{
    std::cout << "---> INTEGRANTES <---" << std::endl;

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
    float maximos1[99];
     float notmax[99];
    float matriz[15000][2];
    float id, max = 0;
    int i = 0, count = 0, n = 0, m = 0, x = 0,id2;
    float Lenguaje = 0, educacionFisica = 0;
    float ingles = 0, matematicas = 0, ciencias = 0, historia = 0, tecnologia = 0, arte = 0, promc = 0;
    std::string linea;
    std::vector<std::string> estudiantes;
    std::vector<float> promedios;

    std::ifstream archivo(valor1);
    if (archivo.is_open())
    {
        estudiantes.clear();
        while (getline(archivo, linea))
        {
            replace(linea, "\"", "");
            estudiantes.push_back(linea);
        }
        archivo.close();

        for (int x = 0; x < estudiantes.size(); x++)
        {
            std::string csv = "";
            std::vector<std::string> lugar = split(estudiantes[x], ";");
            id = std::stoi(lugar[0]);
            Lenguaje = std::stof(lugar[2]);
            ingles = std::stof(lugar[3]);
            matematicas = std::stof(lugar[4]);
            ciencias = std::stof(lugar[5]);
            historia = std::stof(lugar[6]);
            tecnologia = std::stof(lugar[7]);
            arte = std::stof(lugar[8]);
            educacionFisica = std::stof(lugar[9]);
            float promedio = (Lenguaje + ingles + matematicas + ciencias + historia + tecnologia + arte + educacionFisica) / 8;

            matriz[count][0] = id;
            matriz[count][1] = promedio;
            count = count + 1;
        }

        //    for (int l = 0; l <= 14999; l++)
        //     {
        //         for (int h = 0; h < 2; h++)
        //         {
        //             std::cout << matriz[l][h] << std::endl;
        //         }
        //     }

        for (int y = 0; y <= 14999; y++)
        {
            for (int l = 0; l < 14999; l++)
            {
                if (matriz[y][1] > matriz[l][1])
                {
                    max = matriz[y][1];
                    matriz[y][1] = matriz[l][1];
                    matriz[l][1] = max;
                    id2 = matriz[y][0];
                    matriz[y][0] = matriz[l][0];
                    matriz[l][0] = id2;
                }
                
            }
           
        }

        //  for (int l = 0; l <= 14999; l++)
        //  {
        //      for (int h = 0; h < 2; h++)
        //      {
        //      std::cout << matriz[l][h] << std::endl;
        //      }
        //  }
        
        for (int i = 0; i < 100; i++)
            {
               
                maximos1[i]=matriz[i][0];
                notmax[i]=matriz[i][1];
                
            }
            
        
        std::ofstream maximos("maximos.csv");
        if(maximos.is_open()){
            
            for (int c = 0; c < 100; c++)
            {
                int valor = maximos1[c];
                std::stringstream a; 
                a << valor;
                std::string str = a.str();
                maximos << str + ";" << "Estudiante " << str + ";" << notmax[c];
                maximos << "\n";
             //std::cout << maximos1[c] << std::endl;
             //std::cout << notmax[c] << std::endl;
            }
            maximos.close();
        

        }
        
       
    
    } 

    else
    {
        std::cout << "No se pudo abrir el archivo";
    }
}

//if (promc<=promedio)
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
/*if(notalen>aux && notaed>aux2 && id=!maxidos[i])*/