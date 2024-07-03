
# vecpp

Lightweight, header-only C++ library providing vector mathematics functionality and other basic geometry & arithmetic utilities. I created this for reuse in my graphics and game development projects.

## Features

- Vec2 and Vec3 classes
- Geometric utilities
- Arithmetic utilities
- Basic random number generation

## Use

### Example

```cpp
#include <iostream>
#include "vecpp.h"

int main() {
    vecpp::Vec3 v1(1.0, 2.0, 3.0);
    vecpp::Vec3 v2 = vecpp::Vec3::random();

    std::cout << "Vector 1: " << v1 << std::endl;
    std::cout << "Vector 2 (random): " << v2 << std::endl;

    vecpp::Vec3 v3 = v1 + v2;
    std::cout << "Vector 3 (v1 + v2): " << v3 << std::endl;

    double dotProduct = v1.dot(v2);
    std::cout << "Dot product of v1 and v2: " << dotProduct << std::endl;

    vecpp::Vec3 crossProduct = v1.cross(v2);
    std::cout << "Cross product of v1 and v2: " << crossProduct << std::endl;

    vecpp::Vec2 v4(1.0, 2.0);
    vecpp::Vec2 v5 = vecpp::Vec2::random();

    std::cout << "Vector 4: " << v4 << std::endl;
    std::cout << "Vector 5 (random): " << v5 << std::endl;

    vecpp::Vec2 v6 = v4 + v5;
    std::cout << "Vector 6 (v4 + v5): " << v6 << std::endl;

    double dotProduct2 = v4.dot(v5);
    std::cout << "Dot product of v4 and v5: " << dotProduct2 << std::endl;

    return 0;
}
```

### Vec2 Class

The `Vec2` class provides various methods for vector operations:

- **Constructors**:
  - `Vec2()`
  - `Vec2(double x, double y)`

- **Accessors**:
  - `double x() const`
  - `double y() const`

- **Static Methods**:
  - `static Vec2 random()`
  - `static Vec2 random(double min, double max)`

- **Operators**:
  - `Vec2 operator-() const`
  - `double operator[](int i) const`
  - `double& operator[](int i)`
  - `Vec2& operator+=(const Vec2 &v)`
  - `Vec2& operator+=(const double t)`
  - `Vec2& operator*=(const double t)`
  - `Vec2& operator/=(const double t)`

- **Methods**:
  - `double length() const`
  - `double lengthSquared() const`
  - `double dot(const Vec2 &v) const`
  - `Vec2 unitVector() const`
  - `bool isNearZero() const`

### Vec3 Class

The `Vec3` class provides various methods for vector operations:

- **Constructors**:
  - `Vec3()`
  - `Vec3(double x, double y, double z)`

- **Accessors**:
  - `double x() const`
  - `double y() const`
  - `double z() const`

- **Static Methods**:
  - `static Vec3 random()`
  - `static Vec3 random(double min, double max)`
  - `static Vec3 randomUnitVector()`

- **Operators**:
  - `Vec3 operator-() const`
  - `double operator[](int i) const`
  - `double& operator[](int i)`
  - `Vec3& operator+=(const Vec3 &v)`
  - `Vec3& operator+=(const double t)`
  - `Vec3& operator*=(const double t)`
  - `Vec3& operator/=(const double t)`

- **Methods**:
  - `double length() const`
  - `double lengthSquared() const`
  - `double dot(const Vec3 &v) const`
  - `Vec3 cross(const Vec3 &v) const`
  - `Vec3 unitVector() const`
  - `bool isNearZero() const`

### Random Number Generation

The `random` namespace provides methods for generating random numbers:

- `double random::randomDouble()`
- `double random::randomDouble(double min, double max)`

### Geometry Utilities

The `geometry` namespace provides various geometric utilities:

- `double geometry::degreesToRadians(double degrees)`
- `Vec3 geometry::randomPointInUnitSphere()`
- `Vec3 geometry::getRandomDirInHemisphere(const Vec3 &normal)`
- `Vec3 geometry::randomPointInUnitDisk()`

### Arithmetic Utilities

The `arithmetics` namespace provides basic arithmetic utilities:

- `double arithmetics::scale(double num, double inMin, double inMax, double outMin, double outMax)`
- `double arithmetics::clamp(double x, double min, double max)`