/* 
 * File:   XMLParserAnimation.h
 * Author: dorian
 *
 * Created on 11 de marzo de 2015, 11:08
 */

#ifndef XMLPARSERANIMATION_H
#define	XMLPARSERANIMATION_H

#include "IXMLParser.h"


class XMLParserAnimation : public IXMLParser {
public:
    XMLParserAnimation();
    virtual ~XMLParserAnimation();
    
    virtual DataUnion parse(std::string id);
    virtual DataUnion parse();
    
private:
    void storeFrames(tinyxml2::XMLElement* node, StructAnimation* animation);
};

#endif	/* XMLPARSERANIMATION_H */
