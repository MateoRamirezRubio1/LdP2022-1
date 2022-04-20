//
// Created by PC Mateo on 26/03/2022.
//
#include <fstream>
#include "CalculoJcoco.h"

using namespace std;

CalculoJcoco::CalculoJcoco() {}

CalculoJcoco::CalculoJcoco(int pNumeroUsuario) {
    numeroUsuario = pNumeroUsuario;
}

CalculoJcoco::CalculoJcoco(int pNumeroUsuario1, int pNumeroUsuario2) {
    numeroUsuario1 = pNumeroUsuario1;
    numeroUsuario2 = pNumeroUsuario2;
}

int CalculoJcoco::getNumeroUsuario() {
    return numeroUsuario;
}

int CalculoJcoco::getNumeroUsuario1() {
    return numeroUsuario1;
}

int CalculoJcoco::getNumeroUsuario2() {
    return numeroUsuario2;
}

void CalculoJcoco::setNumeroUsuario(int pNumeroUsuario) {
    numeroUsuario = pNumeroUsuario;
}

void CalculoJcoco::setNumeroUsuario1(int pNumeroUsuario1) {
    numeroUsuario1 = pNumeroUsuario1;
}

void CalculoJcoco::setNumeroUsuario2(int pNumeroUsuario2) {
    numeroUsuario2 = pNumeroUsuario2;
}

void CalculoJcoco::escribirArchivo(string texto) {
    ofstream archivo;

    archivo.open("ejecucion_operaciones.casm", ios::out);

    if (archivo.fail()){
        throw "No se pudo abrir el archivo, intentelo de nuevo";
    } else{
        archivo<<texto;
        archivo.close();
    }
}

string CalculoJcoco::trianguloPascal() {
    string codigoJcoco = "";

    return codigoJcoco;
}

string CalculoJcoco::factorial() {
    string codigoJcoco = "Function: factorial/1\n"
                         "Constants: None, 0, 1\n"
                         "Locals: n\n"
                         "Globals: factorial\n"
                         "BEGIN\n"
                         "        LOAD_FAST             0\n"
                         "        LOAD_CONST            1\n"
                         "        COMPARE_OP            2\n"
                         "        POP_JUMP_IF_FALSE     etiqueta\n"
                         "        LOAD_CONST            2\n"
                         "        RETURN_VALUE\n"
                         "etiqueta: LOAD_FAST           0\n"
                         "        LOAD_GLOBAL           0\n"
                         "        LOAD_FAST             0\n"
                         "        LOAD_CONST            2\n"
                         "        BINARY_SUBTRACT\n"
                         "        CALL_FUNCTION         1\n"
                         "        BINARY_MULTIPLY\n"
                         "        RETURN_VALUE\n"
                         "        LOAD_CONST            0\n"
                         "        RETURN_VALUE\n"
                         "END\n"
                         "\n"
                         "Function: main/0\n"
                         "Constants: None, "+ to_string(getNumeroUsuario()) + ", \"El resultado del factorial de\", \"es:\"\n"
                         "Locals: result\n"
                         "Globals: factorial, print\n"
                         "BEGIN\n"
                         "          LOAD_GLOBAL         0\n"
                         "          LOAD_CONST          1\n"
                         "          CALL_FUNCTION       1\n"
                         "          STORE_FAST          0\n"
                         "          LOAD_GLOBAL         1\n"
                         "          LOAD_CONST          2\n"
                         "          LOAD_CONST          1\n"
                         "          LOAD_CONST          3\n"
                         "          LOAD_FAST           0\n"
                         "          CALL_FUNCTION       4\n"
                         "          POP_TOP\n"
                         "          LOAD_CONST          0\n"
                         "          RETURN_VALUE\n"
                         "END";

    return codigoJcoco;
}

string CalculoJcoco::matematicas() {
    string codigoJcoco = "Function: main/0\n"
                   "Constants: None, " + to_string(getNumeroUsuario1()) + ", " + to_string(getNumeroUsuario2()) + ", \"Suma: \", \"Resta : \", \"Multiplicación: \", \"División: \"\n"
                   "Locals: num1, num2\n"
                   "Globals: print\n"
                   "BEGIN\n"
                   "        ;Se cargan los valores en las variables\n"
                   "\n"
                   "        LOAD_CONST                      1\n"
                   "        STORE_FAST                      0\n"
                   "        LOAD_CONST                      2\n"
                   "        STORE_FAST                      1\n"
                   "\n"
                   "        ;Imprimir Suma de las variables\n"
                   "\n"
                   "        LOAD_GLOBAL                     0\n"
                   "        LOAD_CONST                      3\n"
                   "        LOAD_FAST                       0\n"
                   "        LOAD_FAST                       1\n"
                   "        BINARY_ADD\n"
                   "        CALL_FUNCTION                   2\n"
                   "        POP_TOP\n"
                   "\n"
                   "        ;Imprimir resta de las variables\n"
                   "\n"
                   "        LOAD_GLOBAL                     0\n"
                   "        LOAD_CONST                      4\n"
                   "        LOAD_FAST                       0\n"
                   "        LOAD_FAST                       1\n"
                   "        BINARY_SUBTRACT\n"
                   "        CALL_FUNCTION                   2\n"
                   "        POP_TOP\n"
                   "\n"
                   "        ;Imprimir multiplicacion de las variables\n"
                   "\n"
                   "        LOAD_GLOBAL                     0\n"
                   "        LOAD_CONST                      5\n"
                   "        LOAD_FAST                       0\n"
                   "        LOAD_FAST                       1\n"
                   "        BINARY_MULTIPLY\n"
                   "        CALL_FUNCTION                   2\n"
                   "        POP_TOP\n"
                   "\n"
                   "        ;Imprimir division de las variables\n"
                   "\n"
                   "        LOAD_GLOBAL                     0\n"
                   "        LOAD_CONST                      6\n"
                   "        LOAD_FAST                       0\n"
                   "        LOAD_FAST                       1\n"
                   "        BINARY_TRUE_DIVIDE\n"
                   "        CALL_FUNCTION                   2\n"
                   "        POP_TOP\n"
                   "\n"
                   "        LOAD_CONST                      0\n"
                   "        RETURN_VALUE\n"
                   "END";

    return codigoJcoco;
}