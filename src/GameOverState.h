/* 
 * File:   GameOverState.h
 * Author: dorian
 *
 * Created on 14 de diciembre de 2014, 20:59
 */

#ifndef GAMEOVERSTATE_H
#define	GAMEOVERSTATE_H

#include "State.h"
#include "Container.h"
#include <SFML/Graphics.hpp>

/**
 * Estado de juego finalizado
 */
class GameOverState : public State {
public:
    GameOverState(StateStack& stack, Context* context);

    virtual void draw();
    virtual bool update(sf::Time dt);
    virtual bool handleEvent(const sf::Event& event);

    virtual void pushedAction();

private:
    /**
     * Texto a visualizar
     */
    sf::Text mGameOverText;
};

#endif	/* GAMEOVERSTATE_H */