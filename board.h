#ifndef BOARD_H
#define BOARD_H
#include <cstdint>

void validacion_tablero(int &alto,int &ancho);

uint8_t** crearTablero(int ancho, int alto);


void imprimir_tablero(int alto,int ancho);


#endif // BOARD_H
