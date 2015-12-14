#include "explosion.h"

ExplosionCircle::ExplosionCircle (sf::Vector2f pos) {
    setRadius( Config::explosionRadius );
    sf::FloatRect bounds = this->getLocalBounds();
    setOrigin(bounds.width/2.f, bounds.height/2.f);
    setPosition(pos);
    setFillColor(sf::Color(255,153,9));
};

Explosion::Explosion (sf::Vector2f pos):circle(pos) {}

void Explosion::update(double timeStep) {
    duration += timeStep;
    float scale = duration/Config::explosionDuration;
    circle.setScale( scale, scale );
}

void Explosion::draw( sf::RenderWindow& window) {
    window.draw( circle );
}