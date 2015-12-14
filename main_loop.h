#ifndef _GAME_LOOP_H_
#define _GAME_LOOP_H_

#include <utility>
#include <memory>

#include <SFML/Graphics.hpp>

#include "make_uniq.h"
#include "setting.h"
#include "setup.h"

class MainLoop
{
public:
    int run();

private:   
    std::unique_ptr<sf::RenderWindow> window;
    Setting gameSetting; 
};

#endif
