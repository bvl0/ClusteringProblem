cmake_minimum_required(VERSION 3.17)
project(ClusteringProblem C)

set(CMAKE_C_STANDARD 11)

include_directories(lib)

add_executable(ClusteringProblem
    lib/distancia.h
    lib/entradas.h
    lib/kruskall.h
    lib/ponto.h
    lib/unionFind.h
    lib/saida.h
    src/IO/entradas.c
    src/IO/saida.c
    src/distancia.c
    src/kruskall.c
    src/main.c
    src/ponto.c
    src/unionFind.c)
target_link_libraries(ClusteringProblem m)