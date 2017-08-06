#include "config.hpp"
#include <iostream>
#include <easylogging++.h>
#include <app.hpp>

INITIALIZE_EASYLOGGINGPP;

using namespace std;

void _main()
{
	el::Loggers::reconfigureAllLoggers(el::Configurations(EASYLOGGINGPP_CONFIG));
	el::Loggers::addFlag(el::LoggingFlag::ColoredTerminalOutput);

#ifndef NDEBUG
	LOG(INFO) << "Application is running in debug mode";
#endif

	cout << R"banner( 
	 ______  _                                 _          
	|  ___ \(_)           _                   | |         
	| | _ | |_  ____  ___| |_  ____ ____ _____| |  _ ___  
	| || || | |/ _  |/___)  _)/ _  ) ___|___  ) | / ) _ \ 
	| || || | ( ( | |___ | |_( (/ ( (___ / __/| |< ( |_| |
	|_||_||_|_|\_||_(___/ \___)____)____|_____)_| \_)___/
			 
			by ZeroAlcohol 2017 (WIP)
)banner" << endl;

	App app;

	LOG(DEBUG) << "App created";

	app.run();
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

