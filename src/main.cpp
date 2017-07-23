#include <iostream>
#include <Game.hpp>

using namespace std;

auto main(int argc, char *argv[]) -> int
{
#ifndef NDEBUG
    cout << "Application is running in debug mode" << endl;
#endif

    Game game;

    if (game.createGame())
        game.mainRun();
}
