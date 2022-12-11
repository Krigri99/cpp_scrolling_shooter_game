#ifndef EKSAMEN1008_AUDIOENEMYANGRYSUN_H
#define EKSAMEN1008_AUDIOENEMYANGRYSUN_H

#include <string>
#include <SDL_audio.h>
#include "AudioScrollingShooter.h"

class AudioEnemyAngrySun : AudioScrollingShooter {
public:
    bool loadAudio() override;

    void playAudio() override;
    void pauseAudio() override;

    //Check for mInstance of AudioEnemyAngrySun
    static AudioEnemyAngrySun *Instance() {
        if (mInstance == nullptr) {
            mInstance = new AudioEnemyAngrySun();
            return mInstance;
        }

        return mInstance;
    }

private:
    AudioEnemyAngrySun() = default;
    ~AudioEnemyAngrySun() override;

    static AudioEnemyAngrySun *mInstance;
};

typedef AudioEnemyAngrySun tdAudioEnemyAngrySun;

#endif //EKSAMEN1008_AUDIOENEMYANGRYSUN_H
