#include "ScrollingShooter.h"

void loadGameAudio();

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main() {
    Uint32 frameStart, frameTime;

    //Init game-window
    tdScrollingShooter::Instance() -> init("ScrollingShooter", 400, 100, 650, 700, SDL_WINDOW_SHOWN);

    loadGameAudio();

    //Init game-loop
    while (tdScrollingShooter::Instance() -> running()) {
        frameStart = SDL_GetTicks();

        tdScrollingShooter::Instance() -> handleStates();
        tdScrollingShooter::Instance() -> update();
        tdScrollingShooter::Instance() -> render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameTime < DELAY_TIME) {
            SDL_Delay((int) (DELAY_TIME - frameTime));
        }
    }
    //Clean game
    tdScrollingShooter::Instance()->clean();

    return EXIT_SUCCESS;
}

void loadGameAudio() {
    tdAudioSpaceShip::Instance() -> loadAudio();
    tdAudioEnemyAlien::Instance() -> loadAudio();
    tdAudioEnemyAngrySun::Instance() -> loadAudio();
    tdAudioSpaceShipExplosion::Instance() -> loadAudio();
    tdAudioGameOver::Instance() -> loadAudio();
}
