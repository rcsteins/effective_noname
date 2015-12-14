#include <ctime>
#include "main_loop.h"

int main () {
    std::srand (time(NULL));
    MainLoop gm;
    gm.run();
    return 0;
}