#ifndef EKSAMEN1008_AUDIOSPACESHIPEXPLOSION_H
#define EKSAMEN1008_AUDIOSPACESHIPEXPLOSION_H

#include <string>
#include <SDL_audio.h>
#include "AudioScrollingShooter.h"

class AudioSpaceShipExplosion : AudioScrollingShooter{
public:
    bool loadAudio() override;

    void playAudio() override;
    void pauseAudio() override;

    //Check for mInstance of AudioSpaceShipExplosion
    static AudioSpaceShipExplosion *Instance() {
        if (mInstance == nullptr) {
            mInstance = new AudioSpaceShipExplosion();
            return mInstance;
        }

        return mInstance;
    }

private:
    AudioSpaceShipExplosion() = default;
    ~AudioSpaceShipExplosion() override;

    static AudioSpaceShipExplosion *mInstance;
};

typedef AudioSpaceShipExplosion tdAudioSpaceShipExplosion;

#endif //EKSAMEN1008_AUDIOSPACESHIPEXPLOSION_H
