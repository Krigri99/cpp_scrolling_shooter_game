# Scrolling Shooter Game
## Introduction
This is a game I made for the exam in the course PG4400 at Kristiania University College.
The task was to make a game inspired by the classic scrolling shooter genre.
The game should also be based upon the SDL2 library for C++.

## How-to-run
### Download SDL2
* Download MSYS2 from http://www.msys2.org/ and follow the instructions given
  * When finished - open the MSYS terminal
* Write "pacman -Syu" in the terminal
* If the terminal closes, open it again. Now write (in order):
  * pacman -Su
  * pacman -S mingw-w64-x86_64-toolchain
  * pacman -S mingw-w64-x86_64-SDL2
  * pacman -S mingw-w64-x86_64-SDL2_image
  * pacman -S mingw-w64-x86_64-SDL2_mixer
  * pacman -S mingw-w64-x86_64-SDL2_ttf
* To configure CLion to work with MSYS, do the following:
  * Go to "Build, Execution, Deployment"
  * Go to "Toolchains" and add new by pressing "+"
  * Choose MinGW, find the MSYS folder and push "mingw64"
    * Make default by draggin it to the top of the list

### Download font
* Download "Munro" from https://www.fontsquirrel.com/fonts/list/find_fonts?q%5Bterm%5D=Munro&q%5Bsearch_check%5D=Y
