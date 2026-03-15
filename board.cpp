#include "board.h"
#include <iostream>
using namespace std;

void validacion_tablero(int &alto, int &ancho){

    do {
        cout << "Ingrese el alto (minimo 8): ";
        cin >> alto;
    } while(alto < 8);

    do {
        cout << "Ingrese el ancho (multiplo de 8, minimo 8): ";
        cin >> ancho;
    } while(ancho<8 || ancho%8 != 0);

}

uint8_t** Tablero(int alto, int ancho) {
    uint8_t** tablero = new uint8_t*[alto];
    for(int i = 0; i < alto; i++) {
        tablero[i] = new uint8_t[ancho/8]();
    }
    return tablero;
}
void imprimir_tablero(int alto,int ancho){

}

