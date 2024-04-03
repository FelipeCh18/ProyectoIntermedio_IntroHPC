// Box.cpp
#include "Box.hpp"
#include <iostream>
#include <random>
#include <fstream>
#include <cmath>

Box::Box(int latticeSize, int nMolecules) : latticeSize_(latticeSize), nMolecules_(nMolecules)
{
    // Inicializar la matriz de recuento de partículas con ceros
    particleCounts_.resize(latticeSize_, std::vector<int>(latticeSize_, 0));

    // Calcular el tamaño del cuadrado central
    int squareSize = 2;
    double cellSize = static_cast<double>(squareSize) / std::sqrt(nMolecules_); // Espaciamiento uniforme entre partículas

    // Distribuir equitativamente las partículas en el cuadrado central
    for (int i = 0; i < squareSize; ++i)
    {
        for (int j = 0; j < squareSize; ++j)
        {
            // Calcular las coordenadas de la celda actual
            double posX = (latticeSize_ - squareSize) / 2.0 + 0.9 + i*0.2;
            double posY = (latticeSize_ - squareSize) / 2.0 + 0.9 + j*0.2;

            // Distribuir las partículas en la celda actual
            int particlesInCell = std::min(nMolecules_, 1);
            for (int p = 0; p < particlesInCell; ++p)
            {
                double particleX = (posX + cellSize * p);
                double particleY = posY;
                particles_.emplace_back(particleX, particleY);
            }

            // Incrementar el recuento de partículas en la celda
            particleCounts_[(latticeSize_ - squareSize) / 2 + i][(latticeSize_ - squareSize) / 2 + j] += particlesInCell;
            nMolecules_ -= particlesInCell;
        }
    }

    // Colocar las partículas restantes en el centro
    int center = 2;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(-0.1, 0.1);
    for (int i = 0; i < nMolecules_; ++i)
    {
        double posX = center + dis(gen);
        double posY = center + dis(gen);
        particles_.emplace_back(posX, posY);
        particleCounts_[center][center]++;
    }
}

void Box::moveParticles()
{
    // Configurar el generador de números aleatorios
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(-0.5, 0.5); // Distribución uniforme entre -0.5 y 0.5

    // Mover cada partícula de manera aleatoria
    for (auto &particle : particles_)
    {
        // Generar desplazamientos aleatorios en x e y, limitando a una casilla alrededor de la posición actual
        double maxDelta = 1.0; // Distancia máxima permitida en una dirección
        double dx = std::max(-maxDelta, std::min(maxDelta, dis(gen)));
        double dy = std::max(-maxDelta, std::min(maxDelta, dis(gen)));

        // Mover la partícula
        particle.move(dx, dy);

        // Asegurar que la partícula no se salga de los límites de la caja
        double x = particle.getX();
        double y = particle.getY();
        x = std::max(0.0, std::min(static_cast<double>(latticeSize_) - 1.0, x));
        y = std::max(0.0, std::min(static_cast<double>(latticeSize_) - 1.0, y));
        particle.move(x - particle.getX(), y - particle.getY());
    }
}

void Box::recordDistribution(int timestep, int print_bit)
{
    // Resetear los recuentos de partículas
    for (auto &row : particleCounts_)
    {
        std::fill(row.begin(), row.end(), 0);
    }
    if (print_bit == 1)
    {
        std::ofstream distribucion("distribucion" + std::to_string(timestep) + ".txt");
        for (const auto &particle : particles_)
        {
            distribucion << std::max(std::min((particle.getX() - 2), 2.0), -2.0) << "\t" << std::max(std::min((particle.getY() - 2), 2.0), -2.0) << "\n";
            int x = static_cast<int>(std::round(particle.getX())); // Convertir la coordenada x a entero
            int y = static_cast<int>(std::round(particle.getY())); // Convertir la coordenada y a entero
            particleCounts_[x][y]++;
        }
        distribucion.close();
    }
    else
    {
        for (const auto &particle : particles_)
        {
            int x = static_cast<int>(std::round(particle.getX())); // Convertir la coordenada x a entero
            int y = static_cast<int>(std::round(particle.getY())); // Convertir la coordenada y a entero
            particleCounts_[x][y]++;
        }
    }
}

void Box::printParticleDistribution(int timestep) const
{
    // Imprimir la distribución de partículas en la consola
    double distance = 0;
    double nParticles = 0;
    std::ofstream RMS_txt;
    RMS_txt.open("RMS.txt", std::fstream::app);
    // std::cout << "Distribución de partículas en la caja:" << std::endl;
    for (int i = 0; i < latticeSize_; ++i)
    {
        for (int j = 0; j < latticeSize_; ++j)
        {
            distance += particleCounts_[i][j] * (std::pow(abs(i - latticeSize_ / 2), 2) + std::pow(abs(j - latticeSize_ / 2), 2));
            nParticles += particleCounts_[i][j];
            // std::cout << particleCounts_[i][j] << " ";
        }
        // std::cout << std::endl;
    }
    double RMS = std::sqrt(distance / nParticles);
    RMS_txt << timestep << "\t" << RMS << "\n";
    RMS_txt.close();
}

const std::vector<std::vector<int>> &Box::getParticleCounts() const
{
    return particleCounts_;
}