// Box.hpp
#ifndef BOX_HPP
#define BOX_HPP

#include "Particle.hpp"
#include "InputReader.hpp"
#include <vector>

class Box {
public:
    Box(int latticeSize, int nMolecules);

    void moveParticles();
    void recordDistribution(); // Método para registrar la distribución de partículas
    void printParticleDistribution() const;
    const std::vector<std::vector<int>>& getParticleCounts() const;

private:
    int latticeSize_;
    int nMolecules_;
    std::vector<Particle> particles_;
    std::vector<std::vector<int>> particleCounts_; // Para almacenar el número de partículas en cada celda
};

#endif // BOX_HPP
