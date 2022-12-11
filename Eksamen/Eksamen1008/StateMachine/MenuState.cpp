#include "MenuState.h"

const std::string MenuState::mMenuId = "MENU";

void MenuState::update() {
    for (auto & mElement : mElements) {
        mElement -> update();
    }
}

void MenuState::render() {
    for (auto & mElement : mElements) {
        mElement -> draw();
    }
}

bool MenuState::enter() {
    tdTextureHandler::Instance() -> loadTexture("../Assets/images/scrollingShooterHeader.png", "scrollingShooterHeader", tdScrollingShooter::Instance() -> getRenderer());
    tdTextureHandler::Instance() -> loadTexture("../Assets/images/play.png", "mPlayBtn", tdScrollingShooter::Instance() -> getRenderer());
    tdTextureHandler::Instance() -> loadTexture("../Assets/images/quit.png", "mQuitBtn", tdScrollingShooter::Instance() -> getRenderer());

    mHeader = new GraphicHeader(new LoadParameters(75, 100, 500, 100, "scrollingShooterHeader"));
    mPlayBtn = new MenuChoice(new LoadParameters(130, 300, 400, 80, "mPlayBtn"), menuToPlay);
    mQuitBtn = new MenuChoice(new LoadParameters(130, 400, 400, 80, "mQuitBtn"), exitFromMenu);

    mElements.push_back(mHeader);
    mElements.push_back(mPlayBtn);
    mElements.push_back(mQuitBtn);

    return true;
}

bool MenuState::exit() {
    mElements.clear();

    tdTextureHandler::Instance() -> clearFromTextureMap("scrollingShooterHeader");
    tdTextureHandler::Instance() -> clearFromTextureMap("mPlayBtn");
    tdTextureHandler::Instance() -> clearFromTextureMap("exitBtn");

    return true;
}

void MenuState::menuToPlay() {
    tdScrollingShooter::Instance() -> getStateMachine() -> changeState(new PlayState);
}

void MenuState::exitFromMenu() {
    tdScrollingShooter::Instance() -> quit();
}

MenuState::~MenuState() {
    delete mHeader;
    delete mPlayBtn;
    delete mQuitBtn;
}