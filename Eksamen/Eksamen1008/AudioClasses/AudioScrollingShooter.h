#ifndef EKSAMEN1008_AUDIOSCROLLINGSHOOTER_H
#define EKSAMEN1008_AUDIOSCROLLINGSHOOTER_H

#include <SDL_audio.h>
#include <string>

class AudioScrollingShooter {
public:
    virtual bool loadAudio();

    virtual void playAudio();
    virtual void pauseAudio();

protected:
    explicit AudioScrollingShooter() = default;
    virtual ~AudioScrollingShooter();

    SDL_AudioDeviceID mAudioDevice{};

    SDL_AudioSpec mAudioSpec{};
    Uint8 *mAudioBuffer{};
    Uint32 mAudioLength{};
};

#endif //EKSAMEN1008_AUDIOSCROLLINGSHOOTER_H
