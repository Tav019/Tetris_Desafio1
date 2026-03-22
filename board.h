#ifndef BOARD_H
#define BOARD_H
#include <cstdint>

void validacion_tablero(int &alto,int &ancho);

uint8_t** crear_tablero(int ancho, int alto);


void imprimir_tablero(uint8_t** tablero, int alto,int ancho, uint8_t* pieza, int piezaX, int piezaY, int piezaFila);

void liberar_tablero(uint8_t** tablero, int alto);

int filaLlena(uint8_t* fila, int bytesFila);

int limpiarFilas(uint8_t** tablero, int alto, int ancho);



#endif // BOARD_H
