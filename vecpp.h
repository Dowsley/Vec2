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
    Vec2() : e{0, 0} {}
    Vec2(double x, double y) : e{x, y} {}

    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double width() const { return x(); }
    double height() const { return y(); }

    static Vec2 random() {
        return Vec2(random::randomDouble(), random::randomDouble());
    }

    static Vec2 random(double min, double max) {
        return Vec2(random::randomDouble(min, max), random::randomDouble(min, max));
    }

    Vec2 operator-() const { return Vec2(-e[0], -e[1]); }
    double operator[](int i) const { return e[i]; }
    double& operator[](int i) { return e[i]; }

    Vec2& operator+=(const Vec2 &v) {
        e[0] += v[0];
        e[1] += v[1];
        return *this;
    }

    Vec2& operator+=(const double t) {
        e[0] += t;
        e[1] += t;
        return *this;
    }

    Vec2& operator*=(const double t) {
        e[0] *= t;
        e[1] *= t;
        return *this;
    }

    Vec2& operator/=(const double t) {
        return *this *= 1 / t;
    }

    double length() const {
        return std::sqrt(lengthSquared());
    }

    double lengthSquared() const {
        return (e[0] * e[0]) + (e[1] * e[1]);
    }

    double dot(const Vec2 &v) const {
        return e[0] * v[0] + e[1] * v[1];
    }

    Vec2 unitVector() const {
        return *this / this->length();
    }

    bool isNearZero() const {
        const auto s = 1e-8;
        return (std::fabs(e[0]) < s) && (std::fabs(e[1]) < s);
    }

private:
    double e[2];
};

Vec2 operator+(const Vec2 &u, const Vec2 &v) { return Vec2(u[0] + v[0], u[1] + v[1]); }
Vec2 operator+(const Vec2 &u, double val) { return Vec2(u[0] + val, u[1] + val); }
Vec2 operator+(double val, const Vec2 &u) { return u + val; }
Vec2 operator-(const Vec2 &u, const Vec2 &v) { return Vec2(u[0] - v[0], u[1] - v[1]); }
Vec2 operator*(const Vec2 &u, const Vec2 &v) { return Vec2(u[0] * v[0], u[1] * v[1]); }
Vec2 operator*(double t, const Vec2 &v) { return Vec2(t * v[0], t * v[1]); }
Vec2 operator*(const Vec2 &v, double t) { return t * v; }
Vec2 operator/(Vec2 v, double t) { return (1 / t) * v; }
std::ostream& operator<<(std::ostream &out, const Vec2 &v) { return out << "Vec2(" << v[0] << ' ' << v[1] << ")"; }


class Vec3 {
public:
    Vec3() : e{0, 0, 0} {}
    Vec3(const Vec2& v, int z) {
        e[0] = v.x();
        e[1] = v.y();
        e[2] = z;
    }
    Vec3(double x, double y, double z) : e{x, y, z} {}

    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }

    static Vec3 random() {
        return Vec3(random::randomDouble(), random::randomDouble(), random::randomDouble());
    }

    static Vec3 random(double min, double max) {
        return Vec3(random::randomDouble(min, max), random::randomDouble(min, max), random::randomDouble(min, max));
    }

    static Vec3 randomUnitVector() {
        return geometry::randomPointInUnitSphere().unitVector();
    }

    Vec3 operator-() const { return Vec3(-e[0], -e[1], -e[2]); }
    double operator[](int i) const { return e[i]; }
    double& operator[](int i) { return e[i]; }

    Vec3& operator+=(const Vec3 &v) {
        e[0] += v[0];
        e[1] += v[1];
        e[2] += v[2];
        return *this;
    }

    Vec3& operator+=(const double t) {
        e[0] += t;
        e[1] += t;
        e[2] += t;
        return *this;
    }

    Vec3& operator*=(const double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    Vec3& operator/=(const double t) {
        return *this *= 1 / t;
    }

    double length() const {
        return std::sqrt(lengthSquared());
    }

    double lengthSquared() const {
        return (e[0] * e[0]) + (e[1] * e[1]) + (e[2] * e[2]);
    }

    double dot(const Vec3 &v) const {
        return e[0] * v[0] + e[1] * v[1] + e[2] * v[2];
    }

    Vec3 cross(const Vec3 &v) const {
        return Vec3(e[1] * v[2] - e[2] * v[1],
                    e[2] * v[0] - e[0] * v[2],
                    e[0] * v[1] - e[1] * v[0]);
    }

    Vec3 unitVector() const {
        return *this / this->length();
    }

    bool isNearZero() const {
        const auto s = 1e-8;
        return (std::fabs(e[0]) < s) && (std::fabs(e[1]) < s) && (std::fabs(e[2]) < s);
    }

private:
    double e[3];
};

Vec3 operator+(const Vec3 &u, const Vec3 &v) { return Vec3(u[0] + v[0], u[1] + v[1], u[2] + v[2]); }
Vec3 operator+(const Vec3 &u, double val) { return Vec3(u[0] + val, u[1] + val, u[2] + val); }
Vec3 operator+(double val, const Vec3 &u) { return u + val; }
Vec3 operator-(const Vec3 &u, const Vec3 &v) { return Vec3(u[0] - v[0], u[1] - v[1], u[2] - v[2]); }
Vec3 operator*(const Vec3 &u, const Vec3 &v) { return Vec3(u[0] * v[0], u[1] * v[1], u[2] * v[2]); }
Vec3 operator*(double t, const Vec3 &v) { return Vec3(t * v[0], t * v[1], t * v[2]); }
Vec3 operator*(const Vec3 &v, double t) { return t * v; }
Vec3 operator/(Vec3 v, double t) { return (1 / t) * v; }
std::ostream& operator<<(std::ostream &out, const Vec3 &v) { return out << "Vec3(" << v[0] << ' ' << v[1] << ' ' << v[2] << ")"; }

namespace random {
    inline double randomDouble() {
        static std::uniform_real_distribution<double> distribution(0.0, 1.0);
        static std::mt19937 generator;
        return distribution(generator);
    }

    inline double randomDouble(double min, double max) {
        return min + (max - min) * randomDouble();
    }
}

namespace geometry {
    constexpr static const double pi = 3.1415926535897932385;

    inline double degreesToRadians(double degrees) {
        return degrees * pi / 180.0;
    }

    inline Vec3 randomPointInUnitSphere() {
        while (true) {
            Vec3 p = Vec3::random(-1, 1);
            if (p.lengthSquared() >= 1) continue;
            return p;
        }
    }

    inline Vec3 getRandomDirInHemisphere(const Vec3 &normal) {
        Vec3 inUnitSphere = randomPointInUnitSphere();
        if (inUnitSphere.dot(normal) > 0.0) // In the same hemisphere as the normal
            return inUnitSphere;
        else
            return -inUnitSphere;
    }

    inline Vec3 randomPointInUnitDisk() {
        while (true) {
            auto p = Vec3(random::randomDouble(-1, 1), random::randomDouble(-1, 1), 0);
            if (p.lengthSquared() >= 1) continue;
            return p;
        }
    }
}

namespace arithmetics {
    inline double scale(double num, double inMin, double inMax, double outMin, double outMax) {
        return (num - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
    }

    inline double clamp(double x, double min, double max) {
        if (x < min) return min;
        if (x > max) return max;
        return x;
    }
}

}

#endif // VECPP_H
