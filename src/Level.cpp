/* 
 * File:   Level.cpp
 * Author: dorian
 * 
 * Created on 9 de febrero de 2015, 0:08
 */

#include "Level.h"

Level::Level(sf::RenderTarget& outputTarget, ResourceHolder<IDFonts, sf::Font>& fonts,
            ResourceHolder<IDTextures, sf::Texture>& images) :
mapView(outputTarget.getDefaultView()), target(outputTarget),
textures(images), fonts(fonts), sceneGraph(), sceneLayers(), 
        worldBounds(0.f, 0.f, mapView.getSize().x, 2000.f) {
    
}


void Level::buildScene(StructMap* infoMap, Character* characterCreated) {
    principalCharacter=characterCreated;
    
    // Initialize the different layers
    for (std::size_t i = 0; i < LayerCount; ++i) {
        SceneNode* layer = new SceneNode();

        sceneLayers[i] = std::move(layer);
        sceneGraph.addChild(std::move(layer));
    }
    
    //prepare the background
    TileMapNode * tileMap(new TileMapNode(textures,
            infoMap,
            mapView.getSize().x, mapView.getSize().y,
            20, 20));
    tileMap->prepareMap(infoMap->tiles);
    sceneLayers[Background]->addChild(std::move(tileMap));
    
    sceneLayers[Ground]->addChild(std::move(principalCharacter));
    
}

void Level::setPointCharacter(int x, int y) {
    int xInitial, yInitial;
    sf::Vector2f window = mapView.getSize();
    xInitial = window.x / 2;
    yInitial = window.y / 2;

    xInitial += x;
    yInitial += y;

    mapView.setCenter(xInitial, yInitial);
}

void Level::draw() {
    target.setView(mapView);
    target.draw(sceneGraph);
}

sf::FloatRect Level::getViewBounds() const {
    return sf::FloatRect(mapView.getCenter() - mapView.getSize() / 2.f, mapView.getSize());
}

Level::~Level() {

}

void Level::update(sf::Time dt) {
    principalCharacter->setVelocity(0.f,0.f);
    
    // Forward commands to scene graph
    while (!commandQueue.isEmpty()) {
        sceneGraph.onCommand(commandQueue.pop(), dt);
    }
    // Regular update step
    sceneGraph.update(dt, commandQueue);
}