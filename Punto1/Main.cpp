// Main.cpp
#include "Simulation.hpp"
#include "InputReader.hpp"
#include <iostream>

int main()
{
    std::remove("RMS.txt");
    InputParams inputParams = readInputParams("input.txt");
    Simulation simulation(inputParams);
    simulation.run();
    return 0;
}
