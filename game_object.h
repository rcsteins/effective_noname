#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "angle.h"

enum class Team { RED, GREEN };

class GameObject
{
public:
    GameObject(sf::Vector2f position, Angle angle, float speed, Team team, const sf::Texture& texture);
    GameObject(sf::Vector2f position, Angle angle, float speed, Team team); 
    
    void move(double elapsedTime);  
    void updateSprite(); 
    void update(double timeStep); 
    GameObject copyWithNewPosition(sf::Vector2f position) ; 
    void setSpriteTexture(const sf::Texture& texture);
    void draw(sf::RenderWindow&) ;
           
    sf::Vector2f position;
    Angle angle;
    float speed = 0;
    int scopedGuid = 0;
    Team team;
    sf::Sprite sprite;
};

#endif