#include <Game.hpp>

using namespace std;

auto main(int argc, char* argv[]) -> int
{
    Game game;

    if(game.createGame())
        game.mainRun();

}
