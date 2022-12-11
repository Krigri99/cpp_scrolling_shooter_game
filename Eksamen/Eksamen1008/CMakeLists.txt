cmake_minimum_required(VERSION 3.21)
project(Eksamen1008)

set(CMAKE_CXX_STANDARD 20)

add_executable(Eksamen1008 main.cpp ScrollingShooter.cpp ScrollingShooter.h Handlers/TextureHandler.cpp Handlers/TextureHandler.h Element.h GameElements/SpaceShip.cpp GameElements/SpaceShip.h GameElements/EnemyBlob.cpp GameElements/EnemyBlob.h LoadParameters.h SDLElement.cpp SDLElement.h Vector2D.h Handlers/InputHandler.cpp Handlers/InputHandler.h StateMachine/GameState.h StateMachine/MenuState.cpp StateMachine/MenuState.h StateMachine/PlayState.cpp StateMachine/PlayState.h StateMachine/StateMachineScrollingShooter.cpp StateMachine/StateMachineScrollingShooter.h StateMachine/MenuChoice.cpp StateMachine/MenuChoice.h StateMachine/PauseState.cpp StateMachine/PauseState.h StateMachine/GraphicHeader.cpp StateMachine/GraphicHeader.h StateMachine/GameOverState.cpp StateMachine/GameOverState.h GameElements/SpaceShipBullet.cpp GameElements/SpaceShipBullet.h GameElements/EnemyAlienBullet.cpp GameElements/EnemyAlienBullet.h GameElements/EnemyAlien.cpp GameElements/EnemyAlien.h GameElements/EnemyAngrySun.cpp GameElements/EnemyAngrySun.h GameElements/EnemyAngrySunBullet.cpp GameElements/EnemyAngrySunBullet.h GameElements/Health.cpp GameElements/Health.h GameElements/LifeLost.cpp GameElements/LifeLost.h Handlers/TextFontHandler.cpp Handlers/TextFontHandler.h AudioClasses/AudioSpaceShip.cpp AudioClasses/AudioSpaceShip.h AudioClasses/AudioScrollingShooter.h AudioClasses/AudioEnemyAlien.cpp AudioClasses/AudioEnemyAlien.h AudioClasses/AudioEnemyAngrySun.cpp AudioClasses/AudioEnemyAngrySun.h AudioClasses/AudioSpaceShipExplosion.cpp AudioClasses/AudioSpaceShipExplosion.h AudioClasses/AudioGameOver.cpp AudioClasses/AudioGameOver.h AudioClasses/AudioScrollingShooter.cpp)

INCLUDE(FindPkgConfig)
find_package(SDL2 REQUIRED)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
PKG_SEARCH_MODULE(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)

include_directories(${SDL2_INCLUDE_DIR} ${SDL2IMAGE_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LINK_LIBRARIES} ${SDL2TTF_LINK_LIBRARIES})

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")