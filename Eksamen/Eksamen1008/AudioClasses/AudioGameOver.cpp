#include "AudioGameOver.h"

AudioGameOver *AudioGameOver::mInstance = nullptr;

bool AudioGameOver::loadAudio() {
    //Load WAV from file
    SDL_LoadWAV("../Assets/audio/gameOver.wav", &mAudioSpec, &mAudioBuffer, &mAudioLength);

    AudioScrollingShooter::loadAudio();

    return false;
}

void AudioGameOver::playAudio() {
    AudioScrollingShooter::playAudio();
}

void AudioGameOver::pauseAudio() {
    AudioScrollingShooter::pauseAudio();
}

AudioGameOver::~AudioGameOver() {
    delete mInstance;
    AudioScrollingShooter::~AudioScrollingShooter();
}