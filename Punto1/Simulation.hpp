// Simulation.hpp
#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "Box.hpp"
#include "InputReader.hpp"

class Simulation
{
public:
    Simulation(const InputParams &params);

    void run();
    const Box &getBox() const;
    int getIterations() const;
    int getSeed() const;

private:
    Box box_;
    int iterations_;
    int seed_;

    void calculateAndPrintEntropy(int timeStep);
};

#endif // SIMULATION_HPP
