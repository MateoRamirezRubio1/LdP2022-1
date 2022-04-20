//
// Created by PC Mateo on 26/03/2022.
//

#ifndef UNTITLED_CALCULOJCOCO_H
#define UNTITLED_CALCULOJCOCO_H

using namespace std;

class CalculoJcoco {
private:
    int numeroUsuario, numeroUsuario1, numeroUsuario2;
public:
    CalculoJcoco();
    CalculoJcoco(int pNumeroUsuario);
    CalculoJcoco(int pNumeroUsuario1, int pNumeroUsuario2);
    int getNumeroUsuario();
    int getNumeroUsuario1();
    int getNumeroUsuario2();
    void setNumeroUsuario(int pNumeroUsuario);
    void setNumeroUsuario1(int pNumeroUsuario1);
    void setNumeroUsuario2(int pNumeroUsuario2);
    void escribirArchivo(string texto);
    string trianguloPascal();
    string factorial();
    string matematicas();
};


#endif //UNTITLED_CALCULOJCOCO_H
