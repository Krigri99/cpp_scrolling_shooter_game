#include "ScrollingShooter.h"
#include "Handlers/InputHandler.h"

ScrollingShooter *ScrollingShooter::mInstance = nullptr;

bool ScrollingShooter::init(const char *title, int x, int y, int width, int height, int flags) {
    //Initializing SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        //Creating window
        mWindow = SDL_CreateWindow(title, x, y, width, height, flags);

        //Check for error opening window
        if (mWindow == nullptr) {
            std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
            SDL_Quit();
            return EXIT_FAILURE;
        } else {
            //Initializing renderer
            mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);

            //Check for error with renderer
            if (mRenderer == nullptr) {
                std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
                SDL_DestroyWindow(mWindow);
                SDL_Quit();
                return EXIT_FAILURE;
            } else {
                //Set renderer background color
                SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);

            }
        }
    }
    //If everything is good, start main loop
    mRunning = true;

    mStateMachineScrollingShooter = new StateMachineScrollingShooter();
    mStateMachineScrollingShooter -> changeState(new MenuState());

    return true;
}

void ScrollingShooter::update() {
    mStateMachineScrollingShooter -> update();
}

void ScrollingShooter::render() {
    SDL_RenderClear(mRenderer);

    mStateMachineScrollingShooter -> render();

    SDL_RenderPresent(mRenderer);
}

void ScrollingShooter::handleStates() {
    tdInputHandler::Instance() -> update();
}

void ScrollingShooter::clean() {
    SDL_DestroyWindow(mWindow);
    SDL_DestroyRenderer(mRenderer);
    SDL_Quit();
}

ScrollingShooter::~ScrollingShooter() {
    delete mInstance;
    delete mStateMachineScrollingShooter;
}


