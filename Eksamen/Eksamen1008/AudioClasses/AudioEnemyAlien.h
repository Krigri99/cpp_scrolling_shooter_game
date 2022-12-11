#ifndef EKSAMEN1008_AUDIOENEMYALIEN_H
#define EKSAMEN1008_AUDIOENEMYALIEN_H

#include <string>
#include <SDL_audio.h>
#include "AudioScrollingShooter.h"

class AudioEnemyAlien : AudioScrollingShooter {
public:
    bool loadAudio() override;

    void playAudio() override;
    void pauseAudio() override;

    //Check for mInstance of AudioEnemyAlien
    static AudioEnemyAlien *Instance() {
        if (mInstance == nullptr) {
            mInstance = new AudioEnemyAlien();
            return mInstance;
        }

        return mInstance;
    }

private:
    AudioEnemyAlien() = default;
    ~AudioEnemyAlien() override;

    static AudioEnemyAlien *mInstance;
};

typedef AudioEnemyAlien tdAudioEnemyAlien;

#endif //EKSAMEN1008_AUDIOENEMYALIEN_H
