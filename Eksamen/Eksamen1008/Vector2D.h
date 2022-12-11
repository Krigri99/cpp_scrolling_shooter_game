#ifndef EKSAMEN1008_VECTOR2D_H
#define EKSAMEN1008_VECTOR2D_H

#include <cmath>

class Vector2D {
public:
    Vector2D(float x, float y) : mX(x), mY(y) {}

    [[nodiscard]] float getX() const { return mX; }
    [[nodiscard]] float getY() const { return mY; }

    void setX(float x) { mX = x; }
    void setY(float y) { mY = y; }

    Vector2D operator + (const Vector2D &v2) const {
        return {mX + v2.mX, mY + v2.mY};
    }

    Vector2D &operator += (const Vector2D &v2) {
        mX += v2.mX;
        mY += v2.mY;

        return *this;
    }

    Vector2D operator * (float scalar) const {
        return {mX * scalar, mY * scalar};
    }

    Vector2D operator *= (float scalar) {
        mX *= scalar;
        mY *= scalar;

        return *this;
    }

    Vector2D operator - (const Vector2D &v2) const {
        return {mX - v2.mX, mY - v2.mY};
    }

    Vector2D &operator -= (const Vector2D &v2) {
        mX -= v2.mX;
        mY -= v2.mY;

        return *this;
    }

    Vector2D operator / (float scalar) const {
        return {mX / scalar, mY / scalar};
    }

    Vector2D &operator /= (float scalar) {
        mX /= scalar;
        mY /= scalar;

        return *this;
    }

private:
    float mX;
    float mY;

};


#endif //EKSAMEN1008_VECTOR2D_H
