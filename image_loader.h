#ifndef _IMAGE_LOADER_H_
#define _IMAGE_LOADER_H_

#include <unordered_map>
#include <string>

#include <SFML/Graphics.hpp>

struct ImageTexturePair {
    sf::Image image;
    sf::Texture texture;
};

class ImageLoader
{
public:
    
    bool loadImageAndTexture(std::string referenceName, std::string fileName);
    std::unordered_map<std::string, ImageTexturePair> map;
};
#endif
