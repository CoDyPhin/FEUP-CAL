cmake_minimum_required(VERSION 3.15)
project(CAL)

set(CMAKE_CXX_STANDARD 14)

add_executable(CAL main.cpp Posicao.cpp Posicao.h Pessoa.cpp Pessoa.h Transporte.cpp Transporte.h Estafeta.cpp Estafeta.h Hora.cpp Hora.h Prato.cpp Prato.h Encomenda.cpp Encomenda.h Cliente.cpp Cliente.h Restaurante.cpp Restaurante.h Graph.h Menu.cpp Menu.h Empresa.cpp Empresa.h)