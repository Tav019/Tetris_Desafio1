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

uint8_t** crear_tablero(int alto, int ancho) {
    int bytesFila = ancho/8;
    uint8_t** tablero = new uint8_t*[alto];

    for(int i= 0; i < alto; i++) {
        tablero[i] = new uint8_t[bytesFila]();
    }
    return tablero;
}

void liberar_tablero(uint8_t** tablero, int alto) {
    for (int i = 0; i < alto; i++) {
        delete[] tablero[i];
    }
    delete[] tablero;
}

int filaLlena(uint8_t* fila, int bytesFila){
    for(int b = 0; b<bytesFila; b++){
        if(fila[b] != 0xFF)
            return 0;
    }
    return 1;
}

int limpiarFilas(uint8_t **tablero, int alto, int ancho){
    int bytesFila = ancho/8;
    int eliminadas = 0;

    for(int i = alto - 1; i>=0;i--){
        if(filaLlena(tablero[i], bytesFila)){
            delete[] tablero[i];
            eliminadas++;


        for(int j = i; j>0;j--){
            tablero[j] = tablero[j-1];
        }

        tablero[0] = new uint8_t[bytesFila]();

        i++;
        }
    }
    return eliminadas;
}

void imprimir_tablero(uint8_t** tablero,int alto,int ancho,
                      uint8_t* piezaForma, int piezaX, int piezaY, int piezaFilas){

    //int bytesFila = ancho/8;
    for(int fila = 0; fila<alto; fila++){
        cout << "|";

        for(int col = 0; col<ancho; col++){
            int celda = 0;
            int filaPieza = fila - piezaY;

            if (filaPieza >= 0 && filaPieza < piezaFilas){
                int colPieza = col - piezaX;
                if (colPieza >= 0 && colPieza < 4){
                    celda =(piezaForma[filaPieza] >> (7-colPieza)) & 1;
                }
            }
            if(!celda){
                int byte = col/8;
                int bit = 7-(col%8);
                celda = (tablero[fila][byte] >> bit) & 1;
            }

            cout <<(celda ? "#" : ".");

            cout <<"|\n";


        }
    }


    cout << "+";
    for(int c = 0; c < ancho; c++) cout << "-";
    cout <<"+\n";
    cout << "Accion [A]Izq [D]Der [S]Bajar [W]Rotar [Q]Salir ";
}
