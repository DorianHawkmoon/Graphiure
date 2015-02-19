/* 
 * File:   TileMapNode.cpp
 * Author: dorian
 * 
 * Created on 10 de febrero de 2015, 22:43
 */

#include "TileMapNode.h"
#include "StructMap.h"
#include <iostream>

TileMapNode::TileMapNode(const ResourceHolder<IDTextures, sf::Texture>& images,
        StructMap *mapInfo, int width, int height,
        int numberRowsVisible, int numberColumnsVisible) :

numberRows(mapInfo->numberRows), numberColumns(mapInfo->numberColumns),
widthWindow(width), heightWindow(height), numberColumnsVisible(numberColumnsVisible),
numberRowsVisible(numberRowsVisible), tileset(images.get(IDTextures::TileSet)), chunks(), quadSize() {

    tileSize = sf::Vector2u(mapInfo->tileWidth, mapInfo->tileHeight);
    //ready up empty 2d arrays
    chunks.assign(numberRows,
            std::vector<sf::VertexArray>(numberColumns,
            sf::VertexArray(sf::Quads)));
}

void TileMapNode::prepareMap(const int* tilesMap) {
    //size in window
    quadSize = sf::Vector2u(widthWindow / numberColumnsVisible,
            heightWindow / (numberRowsVisible));
    
    
    // populate the vertex array, with one quad per tile
    for (int j = 0; j < numberRows; ++j) {
        int multiply=j * numberColumns;
        for (int i = 0; i < numberColumns; ++i) {
        
            // get the current tile number
            int tileNumber = tilesMap[i + multiply];
            
            // find its position in the tileset texture
            int division = (tileset.getSize().x / tileSize.x);
            int tu = tileNumber % division;
            int tv = tileNumber / division;

            // get a pointer to the current tile's quad
            //aquí relleno los chunks
            sf::VertexArray* garr = &chunks[j][i];
            
            sf::Vertex ver=*(new sf::Vertex());
            ver.position = sf::Vector2f(i * quadSize.x, j * quadSize.y);
            ver.texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            garr->append(std::move(ver));

            ver.position = sf::Vector2f((i + 1) * quadSize.x, j * quadSize.y);
            ver.texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            garr->append(std::move(ver));

            ver.position = sf::Vector2f((i + 1) * quadSize.x, (j + 1) * quadSize.y);
            ver.texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            garr->append(std::move(ver));

            ver.position = sf::Vector2f(i * quadSize.x, (j + 1) * quadSize.y);
            ver.texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
            garr->append(std::move(ver));
        }
    }
}

void TileMapNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
    // apply the transform
    states.transform *= getTransform();

    // apply the tileset texture
    states.texture = &tileset;


    int left = 0, right = 0, top = 0, bottom = 0;
    //get chunk indices into which top left and bottom right points of view fall:
    sf::Vector2f temp = target.getView().getCenter()-(target.getView().getSize() / 2.f); //get top left point of view
    left = static_cast<int> (temp.x / tileSize.x);
    top = static_cast<int> (temp.y / tileSize.x);
    temp += target.getView().getSize(); //get bottom right point of view
    right = 1 + static_cast<int> (temp.x / tileSize.x);
    bottom = 1 + static_cast<int> (temp.y / tileSize.x);
    //clamp these to fit into array bounds:
    left = std::max(0, std::min(left, numberColumnsVisible));
    top = std::max(0, std::min(top, numberRowsVisible));
    right = std::max(0, std::min(right, numberColumnsVisible));
    bottom = std::max(0, std::min(bottom, numberRowsVisible));

    for (int ix = left; ix < right; ++ix) {
        for (int iy = top; iy < bottom; ++iy) {
            target.draw(chunks[ix][iy], states);
        }
    }
}

TileMapNode::~TileMapNode() {

}
