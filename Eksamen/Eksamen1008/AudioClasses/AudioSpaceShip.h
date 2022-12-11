#ifndef EKSAMEN1008_AUDIOSPACESHIP_H
#define EKSAMEN1008_AUDIOSPACESHIP_H

#include <string>
#include <SDL_audio.h>
#include "AudioScrollingShooter.h"

class AudioSpaceShip : AudioScrollingShooter {
public:
    bool loadAudio() override;

    void playAudio() override;
    void pauseAudio() override;

    //Check for mInstance of AudioSpaceShip
    static AudioSpaceShip *Instance() {
        if (mInstance == nullptr) {
            mInstance = new AudioSpaceShip();
            return mInstance;
        }

        return mInstance;
    }

private:
    AudioSpaceShip() = default;
    ~AudioSpaceShip() override;

    static AudioSpaceShip *mInstance;
};

typedef AudioSpaceShip tdAudioSpaceShip;

#endif //EKSAMEN1008_AUDIOSPACESHIP_H
