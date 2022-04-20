//
// Created by PC Mateo on 19/03/2022.
//

#ifndef UNTITLED_MATRIZ_H
#define UNTITLED_MATRIZ_H

using namespace std;

class Matriz {
private:
    int filas;
    int columnas;

public:
    Matriz();
    Matriz(int _filas, int _columnas);
    int getFilas();
    int getColumnas();
    void setColumnas(int _columna);
    void setFilas(int _fila);
    string operacionesMatricesJcoco();
};


#endif //UNTITLED_MATRIZ_H
