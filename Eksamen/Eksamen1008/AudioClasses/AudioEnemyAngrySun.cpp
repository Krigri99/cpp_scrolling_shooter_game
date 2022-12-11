#include "AudioEnemyAngrySun.h"

AudioEnemyAngrySun *AudioEnemyAngrySun::mInstance = nullptr;

bool AudioEnemyAngrySun::loadAudio() {
    //Load WAV from file
    SDL_LoadWAV("../Assets/audio/enemyAngrySunBullet.wav", &mAudioSpec, &mAudioBuffer, &mAudioLength);

    AudioScrollingShooter::loadAudio();

    return false;
}

void AudioEnemyAngrySun::playAudio() {
    AudioScrollingShooter::playAudio();
}

void AudioEnemyAngrySun::pauseAudio() {
    AudioScrollingShooter::pauseAudio();
}

AudioEnemyAngrySun::~AudioEnemyAngrySun() {
    delete mInstance;
    AudioScrollingShooter::~AudioScrollingShooter();
}