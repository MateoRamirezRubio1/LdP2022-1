//
// Created by PC Mateo on 19/03/2022.
//

#ifndef UNTITLED_MATRIZ_H
#define UNTITLED_MATRIZ_H


class Matriz {
private:
    int *filas;
    int *columnas;

public:
    int getFilas(int _fila);
    int getColumnas(int _columna);
    void setColumnas(int p, int _columna);
    void setFilas(int p, int _fila);
};


#endif //UNTITLED_MATRIZ_H
