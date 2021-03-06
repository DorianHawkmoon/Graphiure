/* 
 * File:   SystemCommand.h
 * Author: dorian
 *
 * Created on 27 de marzo de 2015, 18:08
 */

#ifndef SYSTEMCOMMAND_H
#define	SYSTEMCOMMAND_H

#include <vector>
#include "Command.h"
#include "CommandQueue.h"
#include <algorithm>
#include "Entity.h"
#include "ISystem.h"

/**
 * Sistema de comandos
 */
class SystemCommand : public ISystem {
public:
    SystemCommand();
    virtual ~SystemCommand();
    
    virtual void initialize();;
    virtual void finalize();;
    virtual void update(sf::Time dt);
    virtual void updateSecondPart(sf::Time dt);
    virtual void registerEntity(Entity* entity);
    virtual void removedEntity(Entity* entity);
    
    /**
     * Ejecuta los comandos sobre las entidades
     * @param queue cola de comandos
     * @param delta tiempo entre frame y frame
     */
    void onCommand(CommandQueue& queue, sf::Time delta);
    
private:
    /**
     * Lista de entidades comandables
     */
    std::vector<Entity*> commandable;
};

#endif	/* SYSTEMCOMMAND_H */

