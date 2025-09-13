#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
    int variable=7;
    cout << "Dirección: " << &variable << endl;
    cout << "Valor: " << variable << endl;
    cout << "Indirección: " << *(&variable) << endl;   

    cout << "Tipo de datos" << endl;
    cout << "int: " << sizeof(int) << endl;
    cout << "long: " << sizeof(bool) << endl;
    cout << "char: " << sizeof(char) << endl;
    cout << "double: " << sizeof(double) << endl;
    cout << "float: " << sizeof(float) << endl;
    cout << "byte: " << sizeof(byte) << endl;
    cout << "float: " << sizeof(float) << endl;

    void* direccion = &variable;
    cout << "dirección valor : " << direccion << endl;
    cout << "tamaño: " << sizeof(direccion) << endl;
    cout << "dirección puntero: " << &direccion << endl;    
    return 0;
}