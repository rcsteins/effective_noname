#ifndef _SHOT_H_
#define _SHOT_H_ 

#include <iostream>

#include <SFML/Graphics.hpp>

#include "game_object.h"
#include "config.h"

class Shot : public GameObject
{
public:
    Shot( GameObject init);
    void update(double timeStep);
    bool disabled();
    
    float duration = 0.f;
    bool disabled_ = false;
};

#endif