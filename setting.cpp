#include "setting.h"

#include <algorithm>
#include <iostream>

static float distanceSquared(sf::Vector2f a, sf::Vector2f b) {
    float xDiff = a.x-b.x;
    float yDiff = a.y-b.y;
    return xDiff * xDiff + yDiff * yDiff;
}

bool Setting::haveCollision( const Ship& ship, const Shot& shot ) {
    return  ship.team != shot.team && 
        distanceSquared ( ship.position, shot.position ) < Config::collisionRange;
} 

void Setting::processCollision(Ship& ship, Shot& shot) {
    ship.hp -= 9;
    shot.disabled_ = true;
    explosionList.emplace_back( (ship.position + shot.position)/2.0f );
}

void Setting::checkForCollisions() {
    for (auto &ship : shipList ) {
          if ( !liveShipGuids.contains( ship.scopedGuid ) ) continue;
          for (auto &shot : shotList ) {
              if ( !haveCollision(ship, shot) ) continue;
              processCollision( ship, shot);
          }
      }
}

void Setting::reassignTargets() {
    for ( auto& ship : shipList ) {
        if ( liveShipGuids.contains( ship.scopedGuid) && (ship.hp <= 0) ) {
            liveShipGuids.erase( ship.scopedGuid );
            teamGuidSet( ship ).erase( ship.scopedGuid ); 
        } else if ( ship.target && !liveShipGuids.contains( ship.target->scopedGuid) ) {
            assignShipTarget( ship );
        }
    }
}

void Setting::update(const sf::Time& time) {
    checkForCollisions();
    
    reassignTargets();

    updateUnits(time);
        
    shotList.compact( [](Shot &shot ) { return shot.disabled(); });
    explosionList.compact( [](Explosion& ex ){ return ex.disabled(); });
    
    victoryMessage();
}

void Setting::updateUnits(const sf::Time& time) {
    float elapsedTime = time.asSeconds();

    for(Shot& shot: shotList) {
        shot.update(elapsedTime) ;
    }
    
         
    for(Ship& ship : shipList) {
        if ( this->liveShipGuids.contains(ship.scopedGuid ) ) {
            ship.update(elapsedTime);
        }
    }

    
    for (Explosion& ex : explosionList) {
        ex.update(elapsedTime);
    }
}

void Setting::victoryMessage() {
    if ( !liveShipGuids.containsAny(redShipGuids) ) {
        message.setColor(sf::Color::Green);
        message.setString("Green Wins!");
    } else if ( !liveShipGuids.containsAny( greenShipGuids)) {
        message.setColor(sf::Color::Red);
        message.setString("Red Wins!"); 
    } 
} 

void Setting::draw(sf::RenderWindow& window) {
    for (Ship& ship  : shipList) {
        if ( this->liveShipGuids.contains(ship.scopedGuid ) ) {
            ship.draw(window);
        }
    }
    
    for (auto & shot : shotList)  window.draw( shot.sprite );
    for (auto& explosion : explosionList ) window.draw( explosion.circle );    
    window.draw(message);
}

void Setting::assignShipTarget(Ship& ship) {
    guidCache.clear();
    GuidSet& enemyGuids = enemyGuidSet(ship);
    if ( enemyGuids.size() == 0 ) {
        ship.target = nullptr;
        ship.speed = 0;
        return;
    }
    
    for (int guid : enemyGuids ) {
        guidCache.push_back(guid);
    }
    int i = std::rand() % guidCache.size();
    int guid = guidCache[i];
    ship.target = &shipList[guid];
}

GuidSet& Setting::enemyGuidSet(const Ship& ship) {
    if (ship.team == Team::RED) return greenShipGuids;
    else return redShipGuids;
}

GuidSet& Setting::teamGuidSet(const Ship& ship) {
    if (ship.team == Team::GREEN) return greenShipGuids;
    else return redShipGuids;
}