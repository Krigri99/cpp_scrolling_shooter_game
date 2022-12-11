#include "GameOverState.h"

const std::string GameOverState::mGameOverID = "GAMEOVER";

void GameOverState::update() {
    for (auto & mElement : mElements) {
        mElement -> update();
    }
}

void GameOverState::render() {
    for (auto & mElement : mElements) {
        mElement -> draw();
    }

    //Play audio when entering GameOverState
    tdAudioGameOver::Instance() -> playAudio();
}

bool GameOverState::enter() {
    tdTextureHandler::Instance() -> loadTexture("../Assets/images/gameOver.png", "mGameOverHeader", tdScrollingShooter::Instance() -> getRenderer());
    tdTextureHandler::Instance() -> loadTexture("../Assets/images/mainMenu.png", "mMainMenuBtn", tdScrollingShooter::Instance() -> getRenderer());
    tdTextureHandler::Instance() -> loadTexture("../Assets/images/restart.png", "mRestartBtn", tdScrollingShooter::Instance() -> getRenderer());

    mGameOverHeader = new GraphicHeader(new LoadParameters(75, 100, 500, 100, "mGameOverHeader"));
    mMainMenuBtn = new MenuChoice(new LoadParameters(130, 300, 400, 80, "mMainMenuBtn"), gameOverToMain);
    mRestartBtn = new MenuChoice(new LoadParameters(130, 400, 400, 80, "mRestartBtn"), restart);

    mElements.push_back(mGameOverHeader);
    mElements.push_back(mMainMenuBtn);
    mElements.push_back(mRestartBtn);

    return true;
}

bool GameOverState::exit() {
    //Pause function not to collide with menu state
    SDL_Delay(150);

    //Pause audio when exiting GameOverState
    tdAudioGameOver::Instance() -> pauseAudio();

    mElements.clear();

    tdTextureHandler::Instance() -> clearFromTextureMap("mGameOverHeader");
    tdTextureHandler::Instance() -> clearFromTextureMap("mMainMenuBtn");
    tdTextureHandler::Instance() -> clearFromTextureMap("mRestartBtn");

    return true;
}

void GameOverState::gameOverToMain() {
    tdScrollingShooter::Instance() -> getStateMachine() -> changeState(new MenuState);
}

void GameOverState::restart() {
    tdScrollingShooter::Instance() -> getStateMachine() -> changeState(new PlayState);
}

GameOverState::~GameOverState() {
    delete mGameOverHeader;
    delete mMainMenuBtn;
    delete mRestartBtn;
}
