#include "AudioSpaceShip.h"

AudioSpaceShip *AudioSpaceShip::mInstance = nullptr;

bool AudioSpaceShip::loadAudio() {
    //Load WAV from file
    SDL_LoadWAV("../Assets/audio/spaceShipBullet.wav", &mAudioSpec, &mAudioBuffer, &mAudioLength);

    AudioScrollingShooter::loadAudio();

    return false;
}

void AudioSpaceShip::playAudio() {
    AudioScrollingShooter::playAudio();
}

void AudioSpaceShip::pauseAudio() {
    AudioScrollingShooter::pauseAudio();
}

AudioSpaceShip::~AudioSpaceShip() {
    delete mInstance;
    AudioScrollingShooter::~AudioScrollingShooter();
}
