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

	cout << R"banner( 
	 ______  _                                 _          
	|  ___ \(_)           _                   | |         
	| | _ | |_  ____  ___| |_  ____ ____ _____| |  _ ___  
	| || || | |/ _  |/___)  _)/ _  ) ___|___  ) | / ) _ \ 
	| || || | ( ( | |___ | |_( (/ ( (___ / __/| |< ( |_| |
	|_||_||_|_|\_||_(___/ \___)____)____|_____)_| \_)___/
			 
			by ZeroAlcohol 2017 (WIP))banner" << endl;

    Game game;

    if (game.createGame())
        game.mainRun();
}
