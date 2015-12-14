#ifndef _GAME_SETTING_H_
#define _GAME_SETTING_H_

#include <vector>
#include <cstdlib>
#include <algorithm>

#include <SFML/Graphics.hpp>

#include "compactible_vector.h"
#include "ship.h"
#include "config.h"
#include "guid_set.h"
#include "image_loader.h"
#include "shot.h"
#include "explosion.h"

class Ship;

class Setting
{
public:
    Setting () {};

    bool setup() ;    
    void update(const sf::Time& time) ;
    void draw(sf::RenderWindow& window) ;
    friend class Setup;
private:    
    void assignShipTarget(Ship& ship);
    GuidSet& enemyGuidSet(const Ship& ship);
    GuidSet& teamGuidSet(const Ship& ship);
    bool haveCollision(const Ship& ship, const Shot& shot);
    void checkForCollisions();
    void reassignTargets();
    void updateUnits(const sf::Time&);
    void processCollision( Ship& ship, Shot& shot) ;
    void victoryMessage();
public:
    ImageLoader imageHandler;
    sf::Font font;
    std::vector<Ship> shipList;
    sf::Text message;
    compactible_vector<Shot> shotList;
    compactible_vector<Explosion> explosionList;
    GuidSet liveShipGuids;
    GuidSet redShipGuids;
    GuidSet greenShipGuids;  
    std::vector<int> guidCache;
};

#endif /* end of include guard: _GAME_SETTING_H_ */
