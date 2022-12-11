#include "AudioEnemyAlien.h"

AudioEnemyAlien *AudioEnemyAlien::mInstance = nullptr;

bool AudioEnemyAlien::loadAudio() {
    //Load WAV from file
    SDL_LoadWAV("../Assets/audio/enemyAlienBullet.wav", &mAudioSpec, &mAudioBuffer, &mAudioLength);

    AudioScrollingShooter::loadAudio();

    return false;
}

void AudioEnemyAlien::playAudio() {
    AudioScrollingShooter::playAudio();
}

void AudioEnemyAlien::pauseAudio() {
    AudioScrollingShooter::pauseAudio();
}

AudioEnemyAlien::~AudioEnemyAlien() {
    delete mInstance;
    AudioScrollingShooter::~AudioScrollingShooter();
}