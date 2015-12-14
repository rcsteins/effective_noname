#include  "image_loader.h"

bool ImageLoader::loadImageAndTexture(std::string referenceName, std::string fileName) {
    ImageTexturePair& itPair = map[referenceName];
    
    if ( !itPair.image.loadFromFile( fileName ) )
        return false;
    itPair.image.createMaskFromColor( sf::Color(255, 0, 255 ) );
    
    if ( !itPair.texture.loadFromImage(itPair.image) )
        return false;
    itPair.texture.setSmooth(true);
    
    return true;
}