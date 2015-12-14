#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <SFML/Graphics.hpp>

class Config
{
public:
    static const float shipSpeed;
    static const float shotSpeed;
    static const float turnConstant;
    static const float reloadWaitTime;
    static const float shotDuration;
    static sf::Texture* shotTexture;    
    static const float collisionRange;
    static const float explosionDuration;
    static const float explosionRadius;
};

#endif /* end of include guard: _CONFIG_H_ */
