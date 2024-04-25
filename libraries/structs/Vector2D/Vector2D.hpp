#pragma once
#include <game/game.hpp>

struct Vector2D {
    Vector2D() = default;
    Vector2D(float x, float y);
    ~Vector2D() = default;

    Vector2D& operator=(Vector2D& rhs) = default;
    bool operator==(const Vector2D& rhs) const = default;
    bool operator!=(const Vector2D& rhs) const = default;

    Vector2D& operator+=(const Vector2D& rhs);
    Vector2D& operator-=(const Vector2D& rhs);

    Vector2D& Add(const Vector2D& vec) noexcept;
    Vector2D& Substract(const Vector2D& vec) noexcept;
    // Vector2D& Multiply(const Vector2D& vec) noexcept;
    // Vector2D& Divide(const Vector2D& vec);

    friend Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs) noexcept;
    friend Vector2D operator-(const Vector2D& lhs, const Vector2D& rhs) noexcept;
    friend Vector2D operator*(const Vector2D& lhs, const Vector2D& rhs) noexcept;
    friend Vector2D operator/(const Vector2D& lhs, const Vector2D& rhs);

    float x = 0.0f;
    float y = 0.0f;
} ;