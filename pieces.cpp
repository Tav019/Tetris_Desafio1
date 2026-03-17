#include "pieces.h"
#include <iostream>
using namespace std;


uint8_t* generarPieza(int &filas) {
    int num = rand() % 6;
    uint8_t* pieza;

    switch(num) {
    case 0:  // O
        filas = 2;
        pieza = new uint8_t[2];
        pieza[0] = 0b00110000;
        pieza[1] = 0b00110000;
        break;

    case 1:  // T
        filas = 3;
        pieza = new uint8_t[3];
        pieza[0] = 0b00010000;
        pieza[1] = 0b00111000;
        pieza[2] = 0b00000000;
        break;

    case 2:  // S
        filas = 3;
        pieza = new uint8_t[3];
        pieza[0] = 0b00011000;
        pieza[1] = 0b00110000;
        pieza[2] = 0b00000000;
        break;

    case 3:  // Z
        filas = 3;
        pieza = new uint8_t[3];
        pieza[0] = 0b00110000;
        pieza[1] = 0b00011000;
        pieza[2] = 0b00000000;
        break;

    case 4:  // J
        filas = 3;
        pieza = new uint8_t[3];
        pieza[0] = 0b00100000;
        pieza[1] = 0b00111000;
        pieza[2] = 0b00000000;
        break;

    default:  // L
        filas = 3;
        pieza = new uint8_t[3];
        pieza[0] = 0b00001000;
        pieza[1] = 0b00111000;
        pieza[2] = 0b00000000;
        break;
    }
    return pieza;
}

uint8_t* rotacion(uint8_t* pieza, int filas) {
    int pivote = 3;

    if(filas == 2) {
        uint8_t* copia = new uint8_t[2];
        copia[0] = pieza[0];
        copia[1] = pieza[1];
        return copia;
    }

    uint8_t* rotada = new uint8_t[filas]();

    for(int fila = 0; fila < filas; fila++) {
        for(int col = 0; col < 8; col++) {
            int bit = (pieza[fila] >> (7 - col)) & 1;
            if(bit) {
                int nuevaFila = col - pivote + (filas / 2);
                int nuevaCol  = pivote - fila + (filas / 2);
                if(nuevaFila >= 0 && nuevaFila < filas &&
                    nuevaCol  >= 0 && nuevaCol  < 8) {
                    rotada[nuevaFila] |= (0x80 >> nuevaCol);
                }
            }
        }
    }
    return rotada;
}

void liberarPieza(uint8_t* pieza) {
    delete[] pieza;
}
