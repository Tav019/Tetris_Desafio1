#ifndef GAME_H
#define GAME_H
#include <cstdint>


//Codificamos aquí
int hayColision(uint8_t** tablero, int alto, int ancho,
                uint8_t* pieza, int piezaX, int piezaY);

void moverIzquierda(uint8_t** tablero, int alto, int ancho,
                    uint8_t* pieza, int &piezaX, int piezaY);

void moverDerecha(uint8_t** tablero, int alto, int ancho,
                  uint8_t* pieza, int &piezaX, int piezaY);

int bajar(uint8_t** tablero, int alto, int ancho,
          uint8_t* pieza, int piezaX, int &piezaY);

void fijarPieza(uint8_t** tablero, int ancho,
                uint8_t* pieza, int piezaX, int piezaY);

int hayGameOver(uint8_t** tablero, int alto, int ancho,
                uint8_t* pieza, int piezaX, int piezaY);

//void jugar(uint8_t** tablero, int alto, int ancho);


#endif // GAME_H
