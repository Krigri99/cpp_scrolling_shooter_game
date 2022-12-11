#include "PlayState.h"

const std::string PlayState::mPlayID = "PLAY";

void PlayState::update() {
    //If player push escape-key, transfer to PauseState
    if (tdInputHandler::Instance()->readKey(SDL_SCANCODE_ESCAPE)) {
        tdScrollingShooter::Instance()->getStateMachine()->addState(new PauseState);
    }

    //Updating all the game-characters
    mHealthElement[0] -> update();
    mSpaceShipElement[0] ->update();
    mEnemyBlobElement[0] -> update();
    mEnemyAlienElement[0] -> update();
    mEnemyAngrySunElement[0] -> update();

    //Updating health
    if (!mLifeLostElement.empty()) {
        mLifeLostElement[0]->update();

        if (mLifeLostElement[0] -> getPos().getX() > 600) {
            mLifeLostElement.clear();
        }
    }

    //Check if enemies or SpaceShip take damage
    enemyTakeDamage();
    spaceShipTakeDamage();
}

void PlayState::render() {
    //Drawing all the game-characters
    mHealthElement[0] -> draw();
    mSpaceShipElement[0] -> draw();
    mEnemyBlobElement[0] -> draw();
    mEnemyAlienElement[0] -> draw();
    mEnemyAngrySunElement[0] -> draw();

    //Text for keeping track of points
    tdTextFontHandler::Instance() -> drawText("Score:", 0, 0, 70, 30, tdScrollingShooter::Instance() -> getRenderer());
    tdTextFontHandler::Instance() -> drawText(std::to_string(mPointsCounter), 80, 0, 70, 30, tdScrollingShooter::Instance() -> getRenderer());

    //Drawing health
    if (!mLifeLostElement.empty()) {
        mLifeLostElement[0]->draw();
    }
}

//Loading everything in the map when entering PlayState
bool PlayState::enter() {
    loadElementTextures();
    tdTextFontHandler::Instance() -> loadTextFont("../Assets/fonts/munro.ttf", 28);

    mHealth = new Health(new LoadParameters(560, 0, 90, 30, "health"));
    mSpaceShip = new SpaceShip(new LoadParameters(590, 620, 60, 40, "spaceShip"));
    mEnemyBlob = new EnemyBlob(new LoadParameters(520, 200, 60, 40, "blob"));
    mEnemyAlien = new EnemyAlien(new LoadParameters(150, 50, 60, 40, "alien"));
    mEnemyAngrySun = new EnemyAngrySun(new LoadParameters(450, 30, 40, 40, "angrySun"));
    mLifeLost = new LifeLost(new LoadParameters(-200, 250, 200, 100, "lifeLost"));

    mHealthElement.push_back(mHealth);
    mSpaceShipElement.push_back(mSpaceShip);
    mEnemyBlobElement.push_back(mEnemyBlob);
    mEnemyAlienElement.push_back(mEnemyAlien);
    mEnemyAngrySunElement.push_back(mEnemyAngrySun);

    return true;
}

//Cleaning up everything
bool PlayState::exit() {
    mHealthElement.clear();
    mSpaceShipElement.clear();
    mEnemyBlobElement.clear();
    mEnemyAlienElement.clear();
    mEnemyAngrySunElement.clear();
    mLifeLostElement.clear();

    PlayState::clearAllElementsFromTextureMap();


    return true;
}

bool PlayState::checkCollision(SDLElement *element1, SDLElement *element2) {
    int leftA, leftB, rightA, rightB, topA, topB, bottomA, bottomB;

    //Buffer to get more direct hits between elements
    int buf = 7;

    //Calculate sides of rect A
    leftA = element1 -> getPos().getX();
    rightA = element1 -> getPos().getX() + element1 -> getWidth();
    topA = element1 -> getPos().getY();
    bottomA = element1 -> getPos().getY() + element1 -> getHeight();

    //Calculate sides of rect B
    leftB = element2 -> getPos().getX();
    rightB = element2 -> getPos().getX() + element2 -> getWidth();
    topB = element2 -> getPos().getY();
    bottomB = element2 -> getPos().getY() + element2 -> getHeight();

    if((bottomA - buf) <= topB) { return false; }
    if((topA + buf) >= bottomB) { return false; }
    if((rightA - buf) <= leftB) { return false; }
    if((leftA + buf) >= rightB) { return false; }

    return true;
}

void PlayState::enemyTakeDamage() {
    //Using random function to spawn enemies at different places after they get shot
    if (!mSpaceShip->getSpaceShipBullets().empty()) {
        if (mEnemyBlobElement.empty()) {
            mEnemyBlob = new EnemyBlob(new LoadParameters(1 + (rand() % 450), 200, 60, 40, "blob"));
            mEnemyBlobElement.push_back(mEnemyBlob);

        } else if (checkCollision(mSpaceShip -> getSpaceShipBullets().at(0), mEnemyBlobElement[0])) {
            mEnemyBlobElement.clear();
            mPointsCounter += 100;
        }

        if (mEnemyAlienElement.empty()) {
            mEnemyAlien = new EnemyAlien(new LoadParameters(1 + (rand() % 450), 1 + (rand() % 200), 60, 40, "alien"));
            mEnemyAlienElement.push_back(mEnemyAlien);

        } else if (checkCollision(mSpaceShip -> getSpaceShipBullets().at(0), mEnemyAlienElement[0])) {
            mEnemyAlienElement.clear();
            mPointsCounter += 100;
        }

        if (mEnemyAngrySunElement.empty()) {
            mEnemyAngrySun = new EnemyAngrySun(new LoadParameters(1 + (rand() % 450), 30, 40, 40, "angrySun"));
            mEnemyAngrySunElement.push_back(mEnemyAngrySun);

        } else if (checkCollision(mSpaceShip -> getSpaceShipBullets().at(0), mEnemyAngrySunElement[0])) {
            mEnemyAngrySunElement.clear();
            mPointsCounter += 100;
        }
    }
}

void PlayState::spaceShipTakeDamage() {
    //Respawn SpaceShip if it takes damage
    if (!mEnemyBlobElement.empty()) {
        if (mSpaceShipElement.empty()) {
            mSpaceShip = new SpaceShip(new LoadParameters(590, 620, 60, 40, "spaceShip"));
            mSpaceShipElement.push_back(mSpaceShip);

        } else if (checkCollision(mEnemyBlobElement[0], mSpaceShipElement[0])) {
            mEnemyBlobElement.clear();
            updateHealth();
            lifeLost();
        }
    }
    if (mEnemyBlobElement.empty()) {
        mEnemyBlob = new EnemyBlob(new LoadParameters(1 + (rand() % 600), 200, 60, 40, "blob"));
        mEnemyBlobElement.push_back(mEnemyBlob);
    }

    if (!mEnemyAlien->getAlienBullets().empty()) {
        if (mSpaceShipElement.empty()) {
            mSpaceShip = new SpaceShip(new LoadParameters(590, 620, 60, 40, "spaceShip"));
            mSpaceShipElement.push_back(mSpaceShip);

        } else if (checkCollision(mEnemyAlien->getAlienBullets().at(0), mSpaceShipElement[0])) {
            updateHealth();
            lifeLost();
        }
    }

    if (!mEnemyAngrySun->getAngrySunBullets().empty()) {
        if (mSpaceShipElement.empty()) {
            mSpaceShip = new SpaceShip(new LoadParameters(590, 620, 60, 40, "spaceShip"));
            mSpaceShipElement.push_back(mSpaceShip);

        } else if (checkCollision(mEnemyAngrySun->getAngrySunBullets().at(0), mSpaceShipElement[0])) {
            updateHealth();
            lifeLost();
        }
    }

    //If spaceShip lose three lives, transfer to GameOverState
    if (mHealth -> getCurrentFrame() == 4) {
        tdScrollingShooter::Instance() -> getStateMachine() -> addState(new GameOverState);
    }
}

void PlayState::updateHealth() {
    mSpaceShipElement.clear();
    mHealthElement.clear();
    mHealth -> setCurrentFrame(1);
    mHealthElement.push_back(mHealth);
}

void PlayState::lifeLost() {
    if (mLifeLostElement.empty()) {
        mLifeLost = new LifeLost(new LoadParameters(-200, 250, 200, 100, "lifeLost"));
        mLifeLostElement.push_back(mLifeLost);
        tdAudioSpaceShipExplosion::Instance() -> playAudio();
    }
}

void PlayState::loadElementTextures() {
    tdTextureHandler::Instance() -> loadTexture("../Assets/images/health.png", "health", tdScrollingShooter::Instance() -> getRenderer());
    tdTextureHandler::Instance() -> loadTexture("../Assets/images/spaceShip.png", "spaceShip", tdScrollingShooter::Instance() -> getRenderer());
    tdTextureHandler::Instance() -> loadTexture("../Assets/images/spaceShipBullet.png", "spaceShipBullet", tdScrollingShooter::Instance() -> getRenderer());
    tdTextureHandler::Instance() -> loadTexture("../Assets/images/enemyBlob.png", "blob", tdScrollingShooter::Instance() -> getRenderer());
    tdTextureHandler::Instance() -> loadTexture("../Assets/images/enemyAlien.png", "alien", tdScrollingShooter::Instance() -> getRenderer());
    tdTextureHandler::Instance() -> loadTexture("../Assets/images/alienBullet.png", "alienBullet", tdScrollingShooter::Instance() -> getRenderer());
    tdTextureHandler::Instance() -> loadTexture("../Assets/images/enemyAngrySun.png", "angrySun", tdScrollingShooter::Instance() -> getRenderer());
    tdTextureHandler::Instance() -> loadTexture("../Assets/images/angrySunBullet.png", "angrySunBullet", tdScrollingShooter::Instance() -> getRenderer());
    tdTextureHandler::Instance() -> loadTexture("../Assets/images/lifeLost.png", "lifeLost", tdScrollingShooter::Instance() -> getRenderer());
}

void PlayState::clearAllElementsFromTextureMap() {
    tdTextureHandler::Instance() -> clearFromTextureMap("health");
    tdTextureHandler::Instance() -> clearFromTextureMap("spaceShip");
    tdTextureHandler::Instance() -> clearFromTextureMap("spaceShipBullet");
    tdTextureHandler::Instance() -> clearFromTextureMap("blob");
    tdTextureHandler::Instance() -> clearFromTextureMap("alien");
    tdTextureHandler::Instance() -> clearFromTextureMap("alienBullet");
    tdTextureHandler::Instance() -> clearFromTextureMap("angrySun");
    tdTextureHandler::Instance() -> clearFromTextureMap("angrySunBullet");
    tdTextureHandler::Instance() -> clearFromTextureMap("lifeLost");
}

PlayState::~PlayState() {
    delete mHealth;
    delete mSpaceShip;
    delete mEnemyBlob;
    delete mEnemyAlien;
    delete mEnemyAngrySun;
    delete mLifeLost;
}
