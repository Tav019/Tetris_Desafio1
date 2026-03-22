#include <iostream>
#include <cstdlib>
#include "board.h"
#include "game.h"
#include "pieces.h"

using namespace std;

int main()
{   int ancho = 0, alto = 0;
    validacion_tablero(alto, ancho);

    // Semilla para aleatoriedad
    int semilla;
    std::cout << "Ingrese un numero para iniciar: ";
    std::cin >> semilla;
    srand(semilla);

    uint8_t** tablero = crear_tablero(alto, ancho);

    // Generar primera pieza
    int filas = 0, tipo = 0;
    uint8_t* pieza = generarPieza(filas, tipo);
    int piezaX = (ancho / 2) - 1;  // centro del tablero
    int piezaY = 0;

    int gameOver = 0;
    char accion;

    while(!gameOver){
        imprimir_tablero(tablero, alto, ancho, pieza, piezaX, piezaY, filas);

        std::cin >> accion;

        if(accion == 'q' || accion == 'Q'){
            break;
        }
        else if(accion == 'a' || accion == 'A'){
            moverIzquierda(tablero, alto, ancho, pieza, piezaX, piezaY);
        }
        else if(accion == 'd' || accion == 'D'){
            moverDerecha(tablero, alto, ancho, pieza, piezaX, piezaY);
        }
        else if(accion == 's' || accion == 'S'){
            if(!bajar(tablero, alto, ancho, pieza, piezaX, piezaY)){
                // No pudo bajar → fijar pieza
                fijarPieza(tablero, ancho, pieza, piezaX, piezaY);
                limpiarFilas(tablero, alto, ancho);
                liberarPieza(pieza);

                // Generar nueva pieza
                pieza = generarPieza(filas, tipo);
                piezaX = (ancho / 2) - 1;
                piezaY = 0;

                // Verificar game over
                if(hayGameOver(tablero, alto, ancho, pieza, piezaX, piezaY)){
                    gameOver = 1;
                }
            }
        }
        else if(accion == 'w' || accion == 'W'){
            uint8_t* rotada = rotacion(pieza, tipo);
            if(!hayColision(tablero, alto, ancho, rotada, piezaX, piezaY)){
                liberarPieza(pieza);
                pieza = rotada;
            } else {
                liberarPieza(rotada);
            }
        }
    }

    imprimir_tablero(tablero, alto, ancho, pieza, piezaX, piezaY, filas);
    std::cout << "\n*** GAME OVER ***\n";

    liberarPieza(pieza);
    liberar_tablero(tablero, alto);

    return 0;
}

