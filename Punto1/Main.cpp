// Main.cpp
#include "Simulation.hpp"
#include "InputReader.hpp"

int main() {
    InputParams inputParams = readInputParams("input.txt");
    Simulation simulation(inputParams);
    simulation.run();
    return 0;
}
