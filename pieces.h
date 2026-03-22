#ifndef PIECES_H
#define PIECES_H
#include <cstdint>

uint8_t* generarPieza(int &filaspieza, int &tipo);
//filaspieza se declara vacia en el main

uint8_t* rotacion(uint8_t* pieza, int tipo);

void liberarPieza(uint8_t* pieza);

#endif // PIECES_H


