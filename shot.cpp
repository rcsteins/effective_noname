#include "shot.h"

Shot::Shot( GameObject init): GameObject(init) {
    setSpriteTexture(*Config::shotTexture);
}

void Shot::update(double timeStep) {
    duration += timeStep;
    GameObject::update(timeStep);
}

bool Shot::disabled() {
    return duration > Config::shotDuration || disabled_ ;
}