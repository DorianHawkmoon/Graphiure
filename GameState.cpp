/* 
 * File:   GameState.cpp
 * Author: dorian
 * 
 * Created on 10 de febrero de 2015, 0:24
 */

#include "GameState.h"
#include <iostream>


GameState::GameState(StateStack& stack, Context context) :
        State(stack, context), level(context.actualLevel) {

}

void GameState::draw() {
    std::cout << "drawed"<<std::endl;
        level->draw();
        std::cout << "drawed"<<std::endl;
}

bool GameState::handleEvent(const sf::Event& event) {

        // Game input handling
        CommandQueue& commands = level->getCommandQueue();
        //player.handleEvent(event, commands);

        // Escape pressed, trigger the pause screen
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            requestStackPush(StatesID::Pause);
    
    return true;
}

bool GameState::update(sf::Time dt) {
    return true;
}
