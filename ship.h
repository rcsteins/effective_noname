#ifndef _SHIP_H_
#define _SHIP_H_ 

#include <vector>

#include <SFML/System.hpp>

#include "game_object.h"
#include "angle.h"
#include "config.h"
#include "setting.h"
#include "shot.h"

class Ship : public GameObject
{
public:
    Ship(GameObject start, std::vector<Shot>& shotList);
    void update( double timeStep );
public:
    //int a= 5;
    Ship* target = nullptr;
    int hp = 100;
    float reloadAccumulator = Config::reloadWaitTime;
    std::vector<Shot>* shotList;
    Angle targetAngle;
private:
    void handleTarget( double timeStep );
    void turnToTarget( double timeStep ) ;
    void fireIfReady( double timeStep ) ;
    GameObject shotData();
};
#endif