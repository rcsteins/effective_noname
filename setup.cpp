#include "setup.h"

bool Setup::setup() {
    if ( !setting.font.loadFromFile( "media/arial.ttf") ) return false;
    setting.message.setFont( setting.font );
    setting.message.setCharacterSize(72);
    setting.message.setPosition(300.f,300.f);
    if ( !loadImages() ) return false;    
    setupFakeShips();  
    setupAI();
    return true;
} 

bool Setup::loadImages() {
    std::vector<StringPair> stringPairs = {
        StringPair("red_ship",  "media/testShip2.bmp"),
        StringPair("green_ship","media/testShip3.bmp"),
        StringPair("laser",     "media/bullet.bmp")
    };
    
    for(auto& stringPair : stringPairs) {
        if ( !setting.imageHandler.loadImageAndTexture(stringPair.first, stringPair.second))
            return false;
    }
    Config::shotTexture = &(setting.imageHandler.map.at("laser").texture);
    return true;
}

void Setup::setupAI() {
    for ( Ship& ship : setting.shipList ) {
        setting.assignShipTarget( ship ) ;
    }
}

void Setup::setupFakeShips() {
    sf::Texture& redTexture = setting.imageHandler.map.at("red_ship").texture;
    sf::Texture& greenTexture = setting.imageHandler.map.at("green_ship").texture;
    
    GameObject redTemplate(sf::Vector2f(0,0), 0, Config::shipSpeed, Team::RED, redTexture );
    GameObject greenTemplate(sf::Vector2f(0,0) , 180, Config::shipSpeed, Team::GREEN, greenTexture );
    
    sf::Vector2f redBase(100,200);
    sf::Vector2f offset(0,150);
    sf::Vector2f greenBase(1100,200);
    
    for (int i = 0; i < 4; ++i) {
        setting.shipList.emplace_back( 
            redTemplate.copyWithNewPosition( redBase + offset * (float)i),
            setting.shotList
        );
    }
    
    for (int i = 0; i < 4; ++i) {
        setting.shipList.emplace_back( 
            greenTemplate.copyWithNewPosition( greenBase + offset * (float)i),
            setting.shotList
        );
    }
    
    for (size_t i = 0; i < setting.shipList.size(); ++i) {
        Ship& ship = setting.shipList[i];
        ship.scopedGuid = i;
        setting.liveShipGuids.insert(i);
        if (ship.team == Team::RED) setting.redShipGuids.insert(i);
        else setting.greenShipGuids.insert(i);
    }
    
}

