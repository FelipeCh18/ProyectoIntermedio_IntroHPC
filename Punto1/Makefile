CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Wpedantic -O2
SANITIZER_FLAGS = -fsanitize=address -fsanitize=undefined
GPROF_FLAGS = -pg
VALGRIND_FLAGS = -g

gprof: main_gprof
    valgrind --tool=cachegrind ./main.exe input.txt > output.txt
    cg_annotate --auto=yes cachegrind.out.* > cachegrind-report.txt

memcheck: main
    valgrind --tool=memcheck ./main.exe input.txt > output.txt

main: Main.o InputReader.o Simulation.o Box.o Particle.o
    $(CXX) $(CXXFLAGS) $(SANITIZER_FLAGS) -o main Main.o InputReader.o Simulation.o Box.o Particle.o

main_gprof: Main.o InputReader.o Simulation.o Box.o Particle.o
    $(CXX) $(CXXFLAGS) $(GPROF_FLAGS) -o main Main.o InputReader.o Simulation.o Box.o Particle.o

Main.o: Main.cpp
    $(CXX) $(CXXFLAGS) -c Main.cpp

InputReader.o: InputReader.cpp
    $(CXX) $(CXXFLAGS) -c InputReader.cpp

Simulation.o: Simulation.cpp
    $(CXX) $(CXXFLAGS) -c Simulation.cpp

Box.o: Box.cpp
    $(CXX) $(CXXFLAGS) -c Box.cpp

Particle.o: Particle.cpp
    $(CXX) $(CXXFLAGS) -c Particle.cpp

clean:
    rm -f *.o main cachegrind.out.* cachegrind-report.txt output.txt
