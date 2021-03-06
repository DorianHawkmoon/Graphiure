/* 
 * File:   XMLParserCharacter.h
 * Author: dorian
 *
 * Created on 1 de abril de 2015, 13:40
 */

#ifndef XMLPARSERCHARACTER_H
#define	XMLPARSERCHARACTER_H

#include "IXMLParser.h"
#include "StateMachineAnimation.h"
#include "Collision.h"
#include "Weapon.h"

/**
 * Parsea xml con información sobre una entidad personaje
 */
class XMLParserCharacter : public IXMLParser {
public:
    XMLParserCharacter();
    virtual ~XMLParserCharacter();
    
    virtual void parse(DataUnion& data);
private:
    void parseWeapon(PropertyManager* properties, tinyxml2::XMLElement* node);
    void parserAnimations(PropertyManager* properties);
    void parserCollisions(PropertyManager* properties);
};

#endif	/* XMLPARSERCHARACTER_H */

