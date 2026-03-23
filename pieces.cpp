#include "pieces.h"
#include <iostream>
using namespace std;

int getBit(uint8_t* pieza, int fila, int col) {
    return (pieza[fila] >> (7 - col)) & 1;
}

void setBit(uint8_t* pieza, int fila, int col) {
    pieza[fila] |= (0x80 >> col);
}

uint8_t* generarPieza(int &filas, int &tipo) {
    int num = rand() % 6;
    tipo = num;
    uint8_t* pieza = new uint8_t[3]();
    filas = 3;

    switch(tipo) {
    case 0:  // O
        pieza[0] = 0b11000000;
        pieza[1] = 0b11000000;
        pieza[2] = 0b00000000;
        break;

    case 1:  // T
        pieza[0] = 0b11100000;
        pieza[1] = 0b01000000;
        pieza[2] = 0b00000000;
        break;

    case 2:  // S
        pieza[0] = 0b01100000;
        pieza[1] = 0b11000000;
        pieza[2] = 0b00000000;
        break;

    case 3:  // Z
        pieza[0] = 0b11000000;
        pieza[1] = 0b01100000;
        pieza[2] = 0b00000000;
        break;

    case 4:  // J
        pieza[0] = 0b10000000;
        pieza[1] = 0b11100000;
        pieza[2] = 0b00000000;
        break;

    default:  // L
        pieza[0] = 0b00100000;
        pieza[1] = 0b11100000;
        pieza[2] = 0b00000000;
        break;
    }
    return pieza;
}

uint8_t* rotacion(uint8_t* pieza, int tipo) {


    if(tipo == 0) {
        uint8_t* copia = new uint8_t[3]();
        copia[0] = pieza[0];
        copia[1] = pieza[1];
        copia[2] = pieza[2];
        return copia;
    }
    else{
    uint8_t* rotada = new uint8_t[3]();

    for(int fila = 0; fila < 3; fila++) {
        for(int col = 0; col < 3; col++) {
            if (getBit(pieza, fila, col)) {
                int nuevaFila = col;
                int nuevaCol  = 2 - fila;
                setBit(rotada, nuevaFila, nuevaCol);
                }
            }
        }

    return rotada;
    }
}

void liberarPieza(uint8_t* pieza) {
    delete[] pieza;
}
