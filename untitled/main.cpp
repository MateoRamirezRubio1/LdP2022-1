#include <iostream>
#include <fstream>
#include "Matriz.h"
#include "CalculoJcoco.h"

using namespace std;

void ejecutarJcoco(){
    system("java -jar JCoCo.jar ejecucion_operaciones.casm");
    exit(1);
}

void factorial(){
    int numeroUsuario;
    cout<<"Ingrese un número natural mayor a 1:"<<endl;
    cin>>numeroUsuario;

    CalculoJcoco *operacion = new CalculoJcoco(numeroUsuario);

    if (numeroUsuario == false) {
        throw "Error, el dato ingresado no es válido";
    }else if (numeroUsuario < 1) {
        throw "Error, el valor ingresado es menor a 1";
    } else if(numeroUsuario>12) {
        throw numeroUsuario;
    }else {
        operacion->escribirArchivo(operacion->factorial());
        cout<<operacion->factorial()<<"\n"<<endl;
        ejecutarJcoco();
    }
}

void trianguloPascal(){
    int numeroUsuario;
    cout<<"Ingrese el número de filas a realizar del triangulo de Pascal:";
    cin>>numeroUsuario;
    CalculoJcoco *operacion = new CalculoJcoco(numeroUsuario);
    operacion->trianguloPascal();
}

void matematicas(){
    int numeroUsuario1, numeroUsuario2;
    cout<<"Ingrese el primer número:";
    cin>>numeroUsuario1;
    cout<<"Ingrese el segundo número:";
    cin>>numeroUsuario2;

    CalculoJcoco *operacion = new CalculoJcoco(numeroUsuario1, numeroUsuario2);

    if(numeroUsuario1 == false || numeroUsuario2 == false) {
        if (numeroUsuario2 == 0) {
            throw "No se puede dividir entre 0";
        }
        throw "Error, el dato ingresado no es válido";
    }else if (numeroUsuario1 >= 1111111111 || numeroUsuario2 >= 1111111111) {
        if (numeroUsuario1 > numeroUsuario2) {
            throw numeroUsuario1;
        } else {
            throw numeroUsuario2;
        }
    }else {
        operacion->escribirArchivo(operacion->matematicas());
        cout<<operacion->matematicas()<<"\n"<<endl;
        ejecutarJcoco();
    }
}

void operacionesMatriz() {
    int filas, columnas;
    cout<<"Ingrese el número de filas que a de tener la Matriz:";
    cin>>filas;
    cout<<"Ingrese el número de columnas que a de tener la Matriz:";
    cin>>columnas;

    CalculoJcoco *archivo = new CalculoJcoco();
    Matriz *operacion = new Matriz(filas, columnas);

    if (filas == false || columnas == false) {
        throw "Error, el dato ingresado no es válido";
    } else if (filas != columnas) {
        throw "Error, la matriz que intenta crear no es una matriz cuadrada";
    } else {
        archivo->escribirArchivo(operacion->operacionesMatricesJcoco());
        cout<<operacion->operacionesMatricesJcoco()<<"\n"<<endl;
        ejecutarJcoco();
    }
}

int main(){

    char opcionUsuario;

    cout<<"BIENVENIDO!!"<<endl;
    cout<<"_________________________________"<<endl;
    cout<<"\nMenú:"<<endl;
    cout<<"a): Dado un numero n, encontrar el valor n-esimo en el Triangulo de Pascal.\n"
          "b): Dado un numero n, encontrar el valor n-esimo de la serie de Factorial.\n"
          "c): Dado dos números enteros, se haga la suma, resta, multiplicación y división de los mismos.\n"
          "d): Dadas dos matrices cuadradas de dimensión n, se hagan la suma,resta, multiplicación y división de las mismas."<<endl;
    cout<<"\nElija la opción a realizar:"<<endl;

    cin>>opcionUsuario;

    try {
        switch (opcionUsuario) {
            case 'a':
                trianguloPascal();
                break;
            case 'b':
                factorial();
                break;
            case 'c':
                matematicas();
            case 'd':
                operacionesMatriz();
                break;
            default:
                cout<<"Opción ingresada no valida.";
        }
    } catch (const char *msg) {
        cerr<<msg;
    } catch (int numero) {
        cerr<<"Error, el resultado de la operación con " << numero << " sobrepasa el valor maximo contenido en una variable Jcoco";
    }
    return 0;
}
