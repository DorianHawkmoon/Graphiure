/* 
 * File:   main.cpp
 * Author: dorian
 *
 * Created on 28 de diciembre de 2014, 11:45
 */

#include "Application.h"
#include <iostream>

/*
 * 
 */
int main(int argc, char** argv) {
    try {
        Application game;
        game.run();
    } catch (std::exception& e) {
        std::cout << "\nExcepción: " << e.what() << std::endl;
    }
    return 0;
}

