#ifndef _SETUP_H_
#define _SETUP_H_

#include <vector>

#include <SFML/Graphics.hpp>

#include "game_object.h"
#include "ship.h"
#include "shot.h"
#include "config.h"
#include "guid_set.h"
#include "setting.h"

typedef std::pair<std::string, std::string> StringPair;

class Setup
{
public:
    Setup (Setting& setting) : setting(setting){};

    bool setup();
private:
    Setting& setting;
private:
    bool loadImages();
    void setupFakeShips();
    void setupAI();
};

#endif /* end of include guard: _SETUP_H_ */
