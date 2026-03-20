#ifndef GAME_H
#define GAME_H
#include <cstdint>

int hayColision(uint8_t** tablero, int alto, int ancho, uint8_t* pieza, int piezaX, int piezaY);

void moverIzquierda(uint8_t** tablero, int alto, int ancho, uint8_t* pieza, int &piezaX, int piezaY);

void moverDerecha(uint8_t** tablero, int alto, int ancho, uint8_t* pieza, int &piezaX, int piezaY);

int bajar(uint8_t** tablero, int alto, int ancho, uint8_t* pieza, int piezaX, int &piezaY);

void fijarPieza(uint8_t** tablero, uint8_t* pieza, int filas, int posY, int posX);

int gameOver(uint8_t** tablero, uint8_t* pieza, int filas, int posX);


#endif // GAME_H
