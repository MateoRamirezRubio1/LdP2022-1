//
// Created by PC Mateo on 19/03/2022.
//

#include "Matriz.h"

int Matriz::getFilas(int _fila) {
    return filas[_fila];
}

int Matriz::getColumnas(int _columna) {
    return columnas[_columna];
}

void Matriz::setColumnas(int p, int _columna) {
    columnas[p] = _columna;
}

void Matriz::setFilas(int p ,int _fila) {
    filas[p] = _fila;
}