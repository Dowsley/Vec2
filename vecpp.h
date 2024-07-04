// MIT License

// Copyright (c) 2024 João F. Dowsley

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
//$$\    $$\  $$$$$$\   $$$$$$$\  $$$$$$\   $$$$$$\
//\$$\  $$  |$$  __$$\ $$  _____|$$  __$$\ $$  __$$\
// \$$\$$  / $$$$$$$$ |$$ /      $$ /  $$ |$$ /  $$ |
//  \$$$  /  $$   ____|$$ |      $$ |  $$ |$$ |  $$ |
//   \$  /   \$$$$$$$\ \$$$$$$$\ $$$$$$$  |$$$$$$$  |
//    \_/     \_______| \_______|$$  ____/ $$  ____/
//                               $$ |      $$ |
//                               $$ |      $$ |
//                               \__|      \__|
// VERSION: 1.0.0
// https://github.com/Dowsley/vecpp

#ifndef VECPP_H
#define VECPP_H

#include <cmath>
#include <random>
#include <limits>
#include <iostream>

namespace vecpp {
    class Vec2 {
    public:
        Vec2();
        Vec2(double x, double y);

        double x() const;
        double y() const;
        double width() const;
        double height() const;

        static Vec2 random();
        static Vec2 random(double min, double max);

        Vec2 operator-() const;
        double operator[](int i) const;
        double& operator[](int i);

        Vec2& operator+=(const Vec2 &v);
        Vec2& operator+=(const double t);
        Vec2& operator*=(const double t);
        Vec2& operator/=(const double t);

        double length() const;
        double lengthSquared() const;
        double dot(const Vec2 &v) const;
        Vec2 unitVector() const;
        bool isNearZero() const;

    private:
        double e[2];
    };

    class Vec3 {
    public:
        Vec3();
        Vec3(const Vec2& v, int z);
        Vec3(double x, double y, double z);

        double x() const;
        double y() const;
        double z() const;

        static Vec3 random();
        static Vec3 random(double min, double max);
        static Vec3 randomUnitVector();

        Vec3 operator-() const;
        double operator[](int i) const;
        double& operator[](int i);

        Vec3& operator+=(const Vec3 &v);
        Vec3& operator+=(const double t);
        Vec3& operator*=(const double t);
        Vec3& operator/=(const double t);

        double length() const;
        double lengthSquared() const;
        double dot(const Vec3 &v) const;
        Vec3 cross(const Vec3 &v) const;
        Vec3 unitVector() const;
        bool isNearZero() const;

    private:
        double e[3];
    };

    Vec2 operator+(const Vec2 &u, const Vec2 &v);
    Vec2 operator+(const Vec2 &u, double val);
    Vec2 operator+(double val, const Vec2 &u);
    Vec2 operator-(const Vec2 &u, const Vec2 &v);
    Vec2 operator*(const Vec2 &u, const Vec2 &v);
    Vec2 operator*(double t, const Vec2 &v);
    Vec2 operator*(const Vec2 &v, double t);
    Vec2 operator/(Vec2 v, double t);
    std::ostream& operator<<(std::ostream &out, const Vec2 &v);

    Vec3 operator+(const Vec3 &u, const Vec3 &v);
    Vec3 operator+(const Vec3 &u, double val);
    Vec3 operator+(double val, const Vec3 &u);
    Vec3 operator-(const Vec3 &u, const Vec3 &v);
    Vec3 operator*(const Vec3 &u, const Vec3 &v);
    Vec3 operator*(double t, const Vec3 &v);
    Vec3 operator*(const Vec3 &v, double t);
    Vec3 operator/(Vec3 v, double t);
    std::ostream& operator<<(std::ostream &out, const Vec3 &v);

    namespace random {
        double randomDouble();
        double randomDouble(double min, double max);
    }

    namespace geometry {
        extern const double pi;

        double degreesToRadians(double degrees);
        Vec3 randomPointInUnitSphere();
        Vec3 getRandomDirInHemisphere(const Vec3 &normal);
        Vec3 randomPointInUnitDisk();
    }

    namespace arithmetics {
        double scale(double num, double inMin, double inMax, double outMin, double outMax);
        double clamp(double x, double min, double max);
    }

}

#endif // VECPP_H
