#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "Simulation.hpp"

TEST_CASE("Verify_simulation_behavior_with_different_inputs", "[simulation]") {
    SECTION("Test_case_with_zero_lattice_size_and_particles") {
        // Crear un objeto InputParams con caja de tamaño cero y cero partículas
        InputParams params;
        params.nMolecules = 0;
        params.latticeSize = 0;
        params.nIterations = 100; // Se ejecutan 100 iteraciones arbitrariamente
        params.randomSeed = 0;

        // Crear una simulación con los parámetros
        Simulation simulation(params);

        // Verificar que no ocurran errores al ejecutar la simulación
        REQUIRE_NOTHROW(simulation.run());
    }

    SECTION("Test_case_with_zero_particles") {
        // Crear un objeto InputParams con cero partículas pero un tamaño de caja válido
        InputParams params;
        params.nMolecules = 0;
        params.latticeSize = 20;
        params.nIterations = 100; // Se ejecutan 100 iteraciones arbitrariamente
        params.randomSeed = 0;

        // Crear una simulación con los parámetros
        Simulation simulation(params);

        // Verificar que no ocurran errores al ejecutar la simulación
        REQUIRE_NOTHROW(simulation.run());
    }

    SECTION("Test_case_with_small_lattice_size_and_particles") {
        // Crear un objeto InputParams con un tamaño de caja pequeño y un pequeño número de partículas
        InputParams params;
        params.nMolecules = 10;
        params.latticeSize = 5;
        params.nIterations = 100; // Se ejecutan 100 iteraciones arbitrariamente
        params.randomSeed = 0;

        // Crear una simulación con los parámetros
        Simulation simulation(params);

        // Verificar que no ocurran errores al ejecutar la simulación
        REQUIRE_NOTHROW(simulation.run());
    }

    SECTION("Test_case_with_large_lattice_size_and_particles") {
        // Crear un objeto InputParams con un tamaño de caja grande y un gran número de partículas
        InputParams params;
        params.nMolecules = 1000;
        params.latticeSize = 100;
        params.nIterations = 100; // Se ejecutan 100 iteraciones arbitrariamente
        params.randomSeed = 0;

        // Crear una simulación con los parámetros
        Simulation simulation(params);

        // Verificar que no ocurran errores al ejecutar la simulación
        REQUIRE_NOTHROW(simulation.run());
    }

    SECTION("Test_case_with_large_number_of_iterations") {
        // Crear un objeto InputParams con un gran número de iteraciones
        InputParams params;
        params.nMolecules = 100;
        params.latticeSize = 20;
        params.nIterations = 1000000; // Se ejecutan 1 millón de iteraciones
        params.randomSeed = 0;

        // Crear una simulación con los parámetros
        Simulation simulation(params);

        // Verificar que no ocurran errores al ejecutar la simulación
        REQUIRE_NOTHROW(simulation.run());
    }
}
