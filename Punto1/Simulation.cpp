// Simulation.cpp
#include "Simulation.hpp"
#include <cmath>
#include <iostream>

Simulation::Simulation(const InputParams &params) : box_(params.latticeSize, params.nMolecules), iterations_(params.nIterations), seed_(params.randomSeed) {}

void Simulation::run()
{
    int mod10 = 1;
    for (int i = 0; i <= iterations_; ++i)
    {

        // Realizar la simulación de difusión
        box_.moveParticles();

        // Registro de la distribución de partículas
        // Normalización de la distribución de probabilidad

        // Cálculo de la entropía en intervalos de tiempo especificados
        if (i % mod10 == 0)
        {
            //calculateAndPrintEntropy(i);
            box_.printParticleDistribution(i);
            box_.recordDistribution(i,0);
            }
            if (i == 0)
            {
                box_.recordDistribution(i,1);
            }
            if (i == 100)
            {
                mod10 *= 10;
            }
            if (i == 1000)
            {
                mod10 *= 10;
            }
            if (i == 10000)
            {
                mod10 *= 10;
                box_.recordDistribution(i,1);
            }
            if (i == 100000)
            {
                mod10 *= 10;
                box_.recordDistribution(i,1);
            }
            if (i == 1000000)
            {
                box_.recordDistribution(i,1);
            }
            if (i == 6000000)
            {
                box_.recordDistribution(i,1);
            }
        }
    }

const Box &Simulation::getBox() const
{
    return box_;
}

int Simulation::getIterations() const
{
    return iterations_;
}

int Simulation::getSeed() const
{
    return seed_;
}

void Simulation::calculateAndPrintEntropy(int timeStep)
{
    // Obtener la distribución de partículas actual
    const Box &box = getBox();
    // box.printParticleDistribution(); //Imprimir distribución
    const std::vector<std::vector<int>> &particleCounts = box.getParticleCounts();
    // Calcular la entropía utilizando la distribución de probabilidad actual
    double entropy = 0.0;
    double totalParticles = 0.0;
    for (const auto &row : particleCounts)
    {
        for (int count : row)
        {
            totalParticles += count;
        }
    }

    // std::cout << "Total de partículas: " << totalParticles << std::endl; //Imprimir Total de Particulas

    for (const auto &row : particleCounts)
    {
        for (int count : row)
        {
            if (count > 0)
            {
                double probability = static_cast<double>(count) / totalParticles; // Conversión a double
                // std::cout << "Probabilidad: " << probability << std::endl; //Imprimir La probabilidad
                entropy -= probability * log(probability); // Calcular la contribución a la entropía
            }
        }
    }

    // Imprimir la entropía en la consola
    // std::cout << "Entropia en el paso de tiempo " << timeStep << ": " << entropy << std::endl;
    // std::cout << timeStep << " " << entropy << std::endl;
}
