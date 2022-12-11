#include "AudioSpaceShipExplosion.h"

AudioSpaceShipExplosion *AudioSpaceShipExplosion::mInstance = nullptr;

bool AudioSpaceShipExplosion::loadAudio() {
    //Load WAV from file
    SDL_LoadWAV("../Assets/audio/spaceShipExplosion.wav", &mAudioSpec, &mAudioBuffer, &mAudioLength);

    AudioScrollingShooter::loadAudio();

    return false;
}

void AudioSpaceShipExplosion::playAudio() {
    AudioScrollingShooter::playAudio();
}

void AudioSpaceShipExplosion::pauseAudio() {
    AudioScrollingShooter::pauseAudio();
}

AudioSpaceShipExplosion::~AudioSpaceShipExplosion() {
    delete mInstance;
    AudioScrollingShooter::~AudioScrollingShooter();
}