#include "PauseState.h"

const std::string PauseState::mPauseID = "PAUSE";

void PauseState::update() {
    for (auto & mElement : mElements) {
        mElement -> update();
    }
}

void PauseState::render() {
    for (auto & mElement : mElements) {
        mElement -> draw();
    }
}

bool PauseState::enter() {
    tdTextureHandler::Instance() -> loadTexture("../Assets/images/gamePaused.png", "mGamePausedHeader", tdScrollingShooter::Instance() -> getRenderer());
    tdTextureHandler::Instance() -> loadTexture("../Assets/images/mainMenu.png", "mMainMenuBtn", tdScrollingShooter::Instance() -> getRenderer());
    tdTextureHandler::Instance() -> loadTexture("../Assets/images/resume.png", "mResumeBtn", tdScrollingShooter::Instance() -> getRenderer());

    mGamePausedHeader = new GraphicHeader(new LoadParameters(75, 100, 500, 100, "mGamePausedHeader"));
    mResumeBtn = new MenuChoice(new LoadParameters(130, 300, 400, 80, "mResumeBtn"), resume);
    mMainMenuBtn = new MenuChoice(new LoadParameters(130, 400, 400, 80, "mMainMenuBtn"), pauseToMain);

    mElements.push_back(mGamePausedHeader);
    mElements.push_back(mResumeBtn);
    mElements.push_back(mMainMenuBtn);

    return true;
}

bool PauseState::exit() {
    //Pause function not to collide with menu state
    SDL_Delay(150);

    mElements.clear();

    tdTextureHandler::Instance() -> clearFromTextureMap("mGamePausedHeader");
    tdTextureHandler::Instance() -> clearFromTextureMap("mResumeBtn");
    tdTextureHandler::Instance() -> clearFromTextureMap("mMainMenuBtn");

    tdInputHandler::Instance() -> reset();

    return true;
}

void PauseState::pauseToMain() {
    tdScrollingShooter::Instance() -> getStateMachine() -> changeState(new MenuState);
}

void PauseState::resume() {
    tdScrollingShooter::Instance() -> getStateMachine() -> removeLastState();
}

PauseState::~PauseState() {
    delete mGamePausedHeader;
    delete mResumeBtn;
    delete mMainMenuBtn;
}
