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
    float artistico1[99];
    float humanismo1[99];
    float tecnicos1[99];
    float notmax[99];
    float notmax1[99];
    float notmax2[99];
    float notmax3[99];
    float matriz[15000][2];
    float matriz1[15000][2];
    float matriz2[15000][2];
    float matriz3[15000][2];
    float id, max = 0;
    int i = 0, count = 0, n = 0, m = 0, x = 0, id2, j=0;
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
            float promedio1 = (arte + educacionFisica) / 2;
            float promedio2 = (Lenguaje + historia) / 2;
            float promedio3 = (matematicas + tecnologia + ciencias) / 3;
            matriz[count][0] = id;
            matriz[count][1] = promedio;
            matriz1[count][0] = id;
            matriz1[count][1] = promedio1;
            matriz2[count][0] = id;
            matriz2[count][1] = promedio2;
            matriz3[count][0] = id;
            matriz3[count][1] = promedio3;
            count = count + 1;
        }



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

        for (int p = 0; p <= 14999; p++)
        {
            for (int l = 0; l < 14999; l++)
            {

                if (matriz1[p][1] > matriz1[l][1])
                {
                    max = matriz1[p][1];
                    matriz1[p][1] = matriz1[l][1];
                    matriz1[l][1] = max;
                    id2 = matriz1[p][0];
                    matriz1[p][0] = matriz1[l][0];
                    matriz1[l][0] = id2;
                }
            }
        }

        for (int p = 0; p <= 14999; p++)
        {
            for (int l = 0; l < 14999; l++)
            {

                if (matriz2[p][1] > matriz2[l][1])
                {
                    max = matriz2[p][1];
                    matriz2[p][1] = matriz2[l][1];
                    matriz2[l][1] = max;
                    id2 = matriz2[p][0];
                    matriz2[p][0] = matriz2[l][0];
                    matriz2[l][0] = id2;
                }
            }
        }

        for (int p = 0; p <= 14999; p++)
        {
            for (int l = 0; l < 14999; l++)
            {

                if (matriz3[p][1] > matriz3[l][1])
                {
                    max = matriz3[p][1];
                    matriz3[p][1] = matriz3[l][1];
                    matriz3[l][1] = max;
                    id2 = matriz3[p][0];
                    matriz3[p][0] = matriz3[l][0];
                    matriz3[l][0] = id2;
                }
            }
        }



        for (int i = 0; i < 100; i++)
        {

            maximos1[i] = matriz[i][0];
            notmax[i] = matriz[i][1];
        }

        while (m < 100)
        {
            for (int g = 0; g < 14999; g++)
            {
                n = 0;
                for (int k = 0; k <= 100; k++)
                {

                    if (maximos1[k] == matriz1[g][0])
                    {
                        n = n + 1;
                    }
                }
                if ((n < 1) && (m <= 100))
                {
                    artistico1[m] = matriz1[g][0];
                    notmax1[m] = matriz1[g][1];
                    m = m + 1;
                    n = 0;
                }
            }

        }
        while(x < 100){
            for (int g = 0; g < 14999; g++)
            {
                n = 0;
                for (int k = 0; k <= 100; k++)
                {

                    if ((maximos1[k] == matriz2[g][0]) && (artistico1[k] == matriz2[g][0]))
                    {
                        n = n + 1;
                    }
                }
                if ((n < 1) && (x<= 100))
                {
                    humanismo1[x] = matriz2[g][0];
                    notmax2[x] = matriz2[g][1];
                    x = x + 1;
                    n = 0;
                }
            }
        }
        while(j<100){
            for (int g = 0; g < 14999; g++)
            {
                n = 0;
                for (int k = 0; k <= 100; k++)
                {

                    if ((maximos1[k] == matriz3[g][0]) && (artistico1[k] == matriz3[g][0]) && (humanismo1[k] == matriz3[g][0]))
                    {
                        n = n + 1;
                    }
                }
                if ((n < 1) && (j <= 100))
                {
                    tecnicos1[j] = matriz3[g][0];
                    notmax3[j] = matriz3[g][1];
                    j = j + 1;
                    n = 0;
                }
            }
            
        }

        std::ofstream maximos("maximos.csv");
        if (maximos.is_open())
        {

            for (int c = 0; c < 100; c++)
            {
                int valor = maximos1[c];
                std::stringstream a;
                a << valor;
                std::string str = a.str();
                maximos << str + ";"
                        << "Estudiante " << str + ";" << notmax[c];
                maximos << "\n";
                
            }
            maximos.close();
        }

        std::ofstream artistico("artistico.csv");
        if (artistico.is_open())
        {

            for (int c = 0; c < 100; c++)
            {
                int valor = artistico1[c];
                std::stringstream a;
                a << valor;
                std::string str = a.str();
                artistico << str + ";"
                          << "Estudiante " << str + ";" << notmax1[c];
                artistico << "\n";
                
            }
            artistico.close();
        }

        std::ofstream humanismo("humanismo.csv");
        if (humanismo.is_open())
        {

            for (int c = 0; c < 100; c++)
            {
                int valor = humanismo1[c];
                std::stringstream a;
                a << valor;
                std::string str = a.str();
                humanismo << str + ";"
                          << "Estudiante " << str + ";" << notmax2[c];
                humanismo << "\n";
                
            }
            humanismo.close();
        }

        std::ofstream tecnicos("tecnicos.csv");
        if (tecnicos.is_open())
        {

            for (int c = 0; c < 100; c++)
            {
                int valor = tecnicos1[c];
                std::stringstream a;
                a << valor;
                std::string str = a.str();
                tecnicos << str + ";"
                          << "Estudiante " << str + ";" << notmax3[c];
                tecnicos << "\n";
                
            }
            tecnicos.close();
        }
        
    }

    else
    {
        std::cout << "No se pudo abrir el archivo";
    }
}

