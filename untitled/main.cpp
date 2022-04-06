#include <iostream>
#include <fstream>
#include "Matriz.h"
#include "CalculoJcoco.h"
#define linux

using namespace std;

#ifdef WIN32

#elif linux

#endif

void ejecutarJcoco(){
    system("java -jar JCoCo.jar MJS.casm");
    exit(1);
}

void factorial(){
    int numeroUsuario;
    cout<<"Ingrese un número natural mayor o igual a 0:"<<endl;
    cin>>numeroUsuario;
    CalculoJcoco *operacion = new CalculoJcoco(numeroUsuario);
    if (numeroUsuario == feof(stdin)){
        throw "Error, el dato ingresado no es una variable numérica";
    }else if (numeroUsuario > 20){
        throw numeroUsuario;
    }else if (numeroUsuario < 0) {
        throw "Error, el valor ingresado es menor a 0";
    } else{
        cout<<operacion->factorial();
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
    unsigned long long int numeroUsuario1, numeroUsuario2;
    cin>>numeroUsuario1;
    cin>>numeroUsuario2;
    CalculoJcoco *operacion = new CalculoJcoco(numeroUsuario1, numeroUsuario2);
    operacion->escribirArchivo(operacion->matematicas());
    cout<<operacion->matematicas()<<endl;
    ejecutarJcoco();
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
                int n;
                Matriz numFila;
                for (int i = 0; i < 4; i++) {
                    cin>>n;
                    numFila.setFilas(i,n);
                }
                for (int j = 0; j < 4; j++) {
                    cout<<numFila.getFilas(j)<<endl;
                }
                break;
            default:
                cout<<"Opción ingresada no valida.";
        }
    } catch (const char *msg) {
        cerr<<msg;
    } catch (int numero) {
        cerr<<"Error, el resultado de la operación con " << numero << " sobrepasa el valor maximo contenido en una variable";
    }
    return 0;
}
