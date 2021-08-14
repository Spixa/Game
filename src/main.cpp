#include "Game.h"
#include <iostream>
#include <experimental/filesystem>
int main(int argc, char const *argv[])
{
    Game::getInstance()->run();
    return 0;
}
