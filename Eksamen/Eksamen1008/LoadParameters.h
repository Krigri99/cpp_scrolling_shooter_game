#ifndef EKSAMEN1008_LOADPARAMETERS_H
#define EKSAMEN1008_LOADPARAMETERS_H

#include <string>
#include <utility>

class LoadParameters {
public:
    LoadParameters(int x, int y, int width, int height, std::string id) :
                mX(x), mY(y), mWidth(width), mHeight(height), mId(std::move(id)) {
    }

    [[nodiscard]] int getX() const { return mX; }
    [[nodiscard]] int getY() const { return mY; }
    [[nodiscard]] int getWidth() const { return mWidth; }
    [[nodiscard]] int getHeight() const { return mHeight; }
    [[nodiscard]] std::string getID() const { return mId; }

private:
    int mX;
    int mY;

    int mWidth;
    int mHeight;

    std::string mId;
};

#endif //EKSAMEN1008_LOADPARAMETERS_H
