/* 
 * File:   Hole.h
 * Author: dorian
 *
 * Created on 30 de marzo de 2015, 17:53
 */

#ifndef HOLE_H
#define	HOLE_H

#include "Collision.h"
#include "PropertyManager.h"
#include "Entity.h"
#include "Life.h"
#include "Behaviour.h"
#include "Position.h"
#include "GameObjects.h"

class Hole : public GameObjects {
public:
    virtual ~Hole() {
    }

    virtual Entity* prepareEntity(PropertyManager& parameters);
private:
    void makeBehaviour(IdEntity idObject, Behaviour* behaviour);
};

#endif	/* HOLE_H */
