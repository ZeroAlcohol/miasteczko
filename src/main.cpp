#include <easylogging++.h>
#include <iostream>

#include "config.hpp"
//#include "TextureContainer.hpp"
#include "app.hpp"
#include "Game.hpp"
#include "Menu.hpp"
#include "resources.textures.hpp"
#include "TextureContainer.hpp"

INITIALIZE_EASYLOGGINGPP

void _main()
{
	el::Loggers::reconfigureAllLoggers(el::Configurations(Config::EASYLOGGINGPP_CONFIG));
	el::Loggers::addFlag(el::LoggingFlag::ColoredTerminalOutput);

#ifndef NDEBUG
	LOG(INFO) << "Application is running in debug mode";
#endif

	std::cout << R"banner( 
	 ______  _                                 _          
	|  ___ \(_)           _                   | |         
	| | _ | |_  ____  ___| |_  ____ ____ _____| |  _ ___  
	| || || | |/ _  |/___)  _)/ _  ) ___|___  ) | / ) _ \ 
	| || || | ( ( | |___ | |_( (/ ( (___ / __/| |< ( |_| |
	|_||_||_|_|\_||_(___/ \___)____)____|_____)_| \_)___/
			 
			by ZeroAlcohol 2017 (WIP)
    )banner" << std::endl;

	Spirit::TextureContainer l_textureContainer;
	
	l_textureContainer.putTexturesByKey({
		rs::tx::tile::grass,
		rs::tx::tile::pavementLeft,
		rs::tx::tile::pavementRight,
		rs::tx::tile::pavementTopLeft,
		rs::tx::tile::pavementTop,
		rs::tx::tile::pavementBottom,
		rs::tx::tile::pavement,
		rs::tx::tile::asphalt,
		rs::tx::tile::pavementTopLeftIn
	}, "tiles/");

	l_textureContainer.putTexturesByKey({
		rs::tx::flowerBox,
		rs::tx::bench,
		rs::tx::player
	});

	auto l_menu{ std::make_unique<Menu>(Config::APP_STATE_CODE_MENU) };
	auto l_game{ std::make_unique<Game>(Config::APP_STATE_CODE_GAME, l_textureContainer) };
	
	Spirit::App l_app;
	l_app.putState(std::move(l_menu), true);
	l_app.putState(std::move(l_game));

	LOG(DEBUG) << "App created";

	l_app.run();
}

#if defined WIN32 && defined NDEBUG 
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	_main();
}
#else
auto main(int argc, char *argv[]) -> int
{
	START_EASYLOGGINGPP(argc, argv);
	_main();
}
#endif // WIN32

