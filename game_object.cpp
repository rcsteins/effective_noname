#include "game_object.h"

void GameObject::setSpriteTexture(const sf::Texture& texture) {
    sprite.setTexture(texture);
    sf::Vector2u textureSize= texture.getSize();
    sf::Vector2f origin( (float)textureSize.x / 2, (float)textureSize.y / 2);
    sprite.setOrigin( origin );
}

GameObject::GameObject(sf::Vector2f position, Angle angle, float speed, Team team, const sf::Texture& texture):
position(position) , angle(angle), speed(speed), team(team) 
{
    setSpriteTexture(texture);     
}

GameObject::GameObject(sf::Vector2f position, Angle angle, float speed, Team team):
position(position) , angle(angle), speed(speed), team(team) {}

void GameObject::move(double elapsedTime) {
    position += angle.makeVector( elapsedTime * speed );
}

void GameObject::updateSprite() {
    sprite.setPosition( position );
    sprite.setRotation( angle.forSprite() );
}

void GameObject::update(double timeStep) {
    move( timeStep );
    updateSprite();
}

GameObject GameObject::copyWithNewPosition(sf::Vector2f position) {
    GameObject copy(*this);
    copy.position = position;
    return copy;
}

void GameObject::draw( sf::RenderWindow& window) {
    window.draw( sprite);
} 