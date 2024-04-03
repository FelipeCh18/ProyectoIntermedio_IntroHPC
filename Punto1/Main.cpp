// Main.cpp
#include "Simulation.hpp"
#include "InputReader.hpp"
#include <iostream>
#include <fstream>
#include <ctime>

int main()
{
    std::ofstream Time_opt;
    Time_opt.open("time_opt.txt", std::fstream::app);
    clock_t cputime1, cputime2;
    cputime1 = clock();
    std::remove("RMS.txt");
    InputParams inputParams = readInputParams("input.txt");
    Simulation simulation(inputParams);
    simulation.run();
    cputime2 = clock() - cputime1;
    Time_opt << inputParams.latticeSize << "\t" << ((double)cputime2)/CLOCKS_PER_SEC << "\n";
    Time_opt.close();
    return 0;
    
}
