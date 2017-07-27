#include <iostream>
#include <Game.hpp>

using namespace std;

#if defined WIN32 && defined NDEBUG 
auto WinMain(int argc, char *argv[]) -> int
#else
auto main(int argc, char *argv[]) -> int
#endif // WIN32
{
#ifndef NDEBUG
    cout << "Application is running in debug mode" << endl;
#endif

    Game game;

    if (game.createGame())
        game.mainRun();
}
