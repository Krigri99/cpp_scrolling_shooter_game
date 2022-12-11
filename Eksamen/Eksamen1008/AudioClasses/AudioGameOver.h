#ifndef EKSAMEN1008_AUDIOGAMEOVER_H
#define EKSAMEN1008_AUDIOGAMEOVER_H

#include <string>
#include <SDL_audio.h>
#include "AudioScrollingShooter.h"

class AudioGameOver : AudioScrollingShooter {
public:
    bool loadAudio() override;

    void playAudio() override;
    void pauseAudio() override;

    //Check for mInstance of AudioGameOver
    static AudioGameOver *Instance() {
        if (mInstance == nullptr) {
            mInstance = new AudioGameOver();
            return mInstance;
        }

        return mInstance;
    }

private:
    AudioGameOver() = default;
    ~AudioGameOver() override;

    static AudioGameOver *mInstance;
};

typedef AudioGameOver tdAudioGameOver;

#endif //EKSAMEN1008_AUDIOGAMEOVER_H
