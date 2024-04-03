#include "InputReader.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

InputParams readInputParams(const std::string &filename)
{
    InputParams params;
    std::ifstream file(filename);
    std::string line;
    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            std::istringstream iss(line);
            std::string token;
            // Divide la línea en tokens separados por '#'
            while (std::getline(iss, token, '#'))
            {
                std::istringstream tokenStream(token);
                int value;
                // Intenta extraer el valor numérico
                if (tokenStream >> value)
                {
                    // Verifica qué variable está siendo asignada
                    if (line.find("#nmolecules") != std::string::npos)
                    {
                        params.nMolecules = value;
                    }
                    else if (line.find("#latticesize") != std::string::npos)
                    {
                        params.latticeSize = value;
                    }
                    else if (line.find("#niterations") != std::string::npos)
                    {
                        params.nIterations = value;
                    }
                    else if (line.find("#randomgeneratorseed") != std::string::npos)
                    {
                        params.randomSeed = value;
                    }
                }
            }
        }
        std::cerr << "Lectura: " << params.nMolecules << ": " << params.latticeSize << ": " << params.nIterations << ": " << params.randomSeed << std::endl;
        file.close();
    }
    else
    {
        std::cerr << "Error: No se pudo abrir el archivo " << filename << std::endl;
    }
    return params;
}
