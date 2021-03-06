/* 
 * File:   main.cpp
 * Author: dorian
 *
 * Created on 28 de diciembre de 2014, 11:45
 */

#include "Application.h"
#include <iostream>
#include <X11/Xlib.h>

/*
 * PUnto de partida de la aplicación
 */
int main(int argc, char** argv) {
    try {
        //inicializo para poder tener hilos
        XInitThreads();
        Application game;
        game.run();
    } catch (std::exception& e) {
        std::cout << "\nExcepción: " << e.what() << std::endl;
    }
    return 0;
}

