#ifndef _EXPLOSION_H_
#define _EXPLOSION_H_

#include <iostream>

#include <SFML/Graphics.hpp>
#include "config.h"

class ExplosionCircle : public sf::CircleShape
{
public:
    ExplosionCircle (sf::Vector2f pos);
};

class Explosion
{
public:
    Explosion (sf::Vector2f pos);

    void update(double timeStep);
    void draw(sf::RenderWindow&) ;
    bool disabled() {
        return duration > Config::explosionDuration;
    }

    ExplosionCircle circle;
private:
    float duration = 0.f;
};

#endif /* end of include guard: _EXPLOSION_H_ */
