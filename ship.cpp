#include "ship.h"

#include <iostream>

using namespace std;

Ship::Ship(GameObject start, std::vector<Shot>& shotList) 
    : GameObject(start), shotList(&shotList) {};

void Ship::update(double timeStep) {
    handleTarget( timeStep );
    GameObject::update( timeStep );
}

void Ship::handleTarget( double timeStep ) {
    if ( this->target != nullptr ) {
        targetAngle = Angle::angleTo( position, target->position ) ;
        turnToTarget( timeStep );
        fireIfReady( timeStep );
    }
}

void Ship::turnToTarget( double timeStep ) {
    Angle diff = targetAngle - angle ;
    angle += diff.softSign(5) * timeStep * Config::turnConstant ;
}

void Ship::fireIfReady( double timeStep ) {
    reloadAccumulator+= timeStep;
    if ( reloadAccumulator > Config::reloadWaitTime ) {
        reloadAccumulator = 0;
        shotList->emplace_back( GameObject(position, targetAngle, Config::shotSpeed, team) );
    }
}