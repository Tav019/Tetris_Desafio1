#include "game.h"
#include "pieces.h"
#include "board.h"
#include <cstdint>

int hayColision(uint8_t** tablero, int alto, int ancho,
                uint8_t* pieza, int piezaX, int piezaY){

    if(piezaX < 0) return 1;

    // Calcular ancho real de la pieza
    int anchoPieza = 0;
    for(int fila = 0; fila < 3; fila++){
        for(int col = 2; col >= 0; col--){
            if((pieza[fila] >> (7 - col)) & 1){
                if(col + 1 > anchoPieza)
                    anchoPieza = col + 1;
                break;
            }
        }
    }
    if(piezaX + anchoPieza > ancho) return 1;

    for(int fila = 0; fila < 3; fila++){
        if(pieza[fila] == 0) continue;

        // Borde inferior solo para filas activas
        if(piezaY + fila >= alto) return 1;

        uint32_t filaPieza = (uint32_t)pieza[fila] << 24;
        filaPieza = filaPieza >> piezaX;

        int bytesFilas = ancho / 8;
        for(int b = 0; b < bytesFilas; b++){
            int desplazamiento = 24 - (b * 8);
            int bytesPieza = (filaPieza >> desplazamiento) & 0xFF;
            if((bytesPieza & tablero[piezaY + fila][b]) != 0) return 1;
        }
    }
    return 0;
}


void moverIzquierda(uint8_t** tablero, int alto, int ancho,
                    uint8_t* pieza, int &piezaX, int piezaY){
    int nuevaX = piezaX - 1;
    if(hayColision(tablero,alto,ancho,pieza,nuevaX,piezaY) == 0)
        piezaX = nuevaX;

}

void moverDerecha(uint8_t** tablero, int alto, int ancho,
                    uint8_t* pieza, int &piezaX, int piezaY){
    int nuevaX = piezaX + 1;
    if(hayColision(tablero,alto,ancho,pieza,nuevaX,piezaY) == 0)
        piezaX = nuevaX;

}


int bajar(uint8_t** tablero, int alto, int ancho,
                  uint8_t* pieza, int piezaX, int &piezaY){
    int nuevaY = piezaY + 1;
    if(hayColision(tablero,alto,ancho,pieza,piezaX, nuevaY) == 0){
        piezaY = nuevaY;
        return 1;
    }
    else return 0;
}

void fijarPieza(uint8_t** tablero, int ancho,
                uint8_t* pieza, int piezaX, int piezaY){
    int bytesFilas = ancho / 8;

    for(int fila = 0; fila < 3; fila++){
        if(pieza[fila] == 0) continue;

        uint32_t filaPieza = (uint32_t)pieza[fila] << 24;
        filaPieza = filaPieza >> piezaX;

        for(int b = 0; b < bytesFilas; b++){
            int desplazamiento = 24 - (b * 8);
            uint8_t bytesPieza = (filaPieza >> desplazamiento) & 0xFF;
            tablero[piezaY + fila][b] |= bytesPieza;  // OR fija los bits
        }
    }
}

int hayGameOver(uint8_t** tablero, int alto, int ancho,
                uint8_t* pieza, int piezaX, int piezaY){
    return hayColision(tablero, alto, ancho, pieza, piezaX, piezaY);
}
