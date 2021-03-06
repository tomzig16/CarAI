#ifndef VECTOR3_H
#define VECTOR3_H

struct Vector3
{
    float x, y, z;
    Vector3() : x(0), y(0), z(0) {};
    Vector3(float _x) : x(_x), y(0), z(0) {};
    Vector3(float _x, float _y) : x(_x), y(_y), z(0) {};
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {};
};

#endif // !VECTOR3_H
