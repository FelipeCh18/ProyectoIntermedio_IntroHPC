// InputReader.hpp
#ifndef INPUT_READER_HPP
#define INPUT_READER_HPP

#include <string>

struct InputParams {
    int nMolecules;
    int latticeSize;
    int nIterations;
    int randomSeed;
};

InputParams readInputParams(const std::string& filename);

#endif // INPUT_READER_HPP
