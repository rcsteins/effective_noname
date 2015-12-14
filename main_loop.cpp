#include "main_loop.h"

int MainLoop::run() {
    Setup setup( gameSetting );
    if ( !setup.setup() ) return -1;
    
    window = make_unique<sf::RenderWindow>(sf::VideoMode(1200, 800), "It works!") ;
    window->setFramerateLimit(120);
    
    sf::Clock clock;
    while ( window->isOpen() ) {
        sf::Time time = clock.getElapsedTime();
        clock.restart();
        
        sf::Event event;
        while ( window->pollEvent(event) ) {
            if (event.type == sf::Event::Closed) window->close();
        }
        gameSetting.update( time );
        
        window->clear();
        gameSetting.draw( *window );
        window->display();
    }
    return 0;
}