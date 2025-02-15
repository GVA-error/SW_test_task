cmake_minimum_required(VERSION 3.27)
project(sw_battle_test)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES src/*.cpp src/*.hpp)
add_executable(sw_battle_test ${SOURCES}
    src/simulation/simulation.h src/simulation/simulation.cpp
    src/IO/Events/Error.hpp
    src/entities/gamefield.h src/entities/gamefield.cpp
    src/utils/Coordinates.h
    src/utils/UnitPaths.h src/utils/UnitPaths.cpp
    src/entities/Unit.h src/entities/Unit.cpp
    src/mechanics/Spawn.h src/mechanics/Spawn.cpp
    src/entities/UnitEnums.h
    src/AI/AI_Swordsman.h src/AI/AI_Swordsman.cpp
    src/AI/ai.h src/AI/ai.cpp
    src/AI/AI_Hunter.h src/AI/AI_Hunter.cpp
    src/utils/Coordinates.cpp
    src/mechanics/meleeattack.h src/mechanics/meleeattack.cpp
    src/mechanics/rangeattack.h src/mechanics/rangeattack.cpp
    src/mechanics/march.h src/mechanics/march.cpp
    src/AI/primitives/pai_meleeattack.h src/AI/primitives/pai_meleeattack.cpp
    src/AI/primitives/pai_march.h src/AI/primitives/pai_march.cpp
    src/AI/primitives/pai_rangeattack.h src/AI/primitives/pai_rangeattack.cpp
    src/AI/primitives/pai_defaultattacklog.h src/AI/primitives/pai_defaultattacklog.cpp
    src/mechanics/mechanicsresults.h src/mechanics/mechanicsresults.cpp
    src/entities/unitsheap.h src/entities/unitsheap.cpp
    src/mechanics/attack.h src/mechanics/attack.cpp
    src/utils/randomfuncs.h src/utils/randomfuncs.cpp
    src/utils/MoveOrder.h src/utils/MoveOrder.cpp





)

target_include_directories(sw_battle_test PUBLIC src/)
