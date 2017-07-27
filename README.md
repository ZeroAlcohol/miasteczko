# miasteczko

## Build instructions
[linux] On the command line, enter:
```
#release
cmake -DCMAKE_BUILD_TYPE=Release CMakeList.txt_localization

#debug
cmake -DCMAKE_BUILD_TYPE=Debug CMakeList.txt_localization

make -j4
```

[windows] 
* set environment variable SFML_ROOT (sfml library location)
* On the command line, enter
  ````
  cmake -G "Visual Studio 14 2015 Win64" CMakeList.txt_localization
  ````
 * open miasteczko.sln with Visual Studio

## Running executables 

 Game executable you can find in:  
project_directory/bin/miasteczko

Tests executable you can find in:  
project-directory/bin-tests/miasteczko-ut-tests
