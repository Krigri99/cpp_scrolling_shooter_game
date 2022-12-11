#include "AudioScrollingShooter.h"

bool AudioScrollingShooter::loadAudio() {
    //Set up device
    mAudioDevice = SDL_OpenAudioDevice(nullptr, 0, &mAudioSpec, nullptr, 0);

    return false;
}

void AudioScrollingShooter::playAudio() {
    SDL_QueueAudio(mAudioDevice, mAudioBuffer, mAudioLength);
    SDL_PauseAudioDevice(mAudioDevice, 0);
}

void AudioScrollingShooter::pauseAudio() {
    SDL_PauseAudioDevice(mAudioDevice, 1);
}

AudioScrollingShooter::~AudioScrollingShooter() {
    SDL_FreeWAV(mAudioBuffer);
    SDL_CloseAudioDevice(mAudioDevice);
}

