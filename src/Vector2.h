#ifndef VECTOR_h_
#define VECTOR_h_

#include <stdio.h>
#include "Window.h"

static const int RED[3] = {255,0,0};

typedef struct
{
    int x;
    int y;
    int *color;
} Vector2;

Vector2 Vector2Init(int x, int y, int *color)
{
    Vector2 newVector;
    newVector.x = x;
    newVector.y = y;
    newVector.color = color;
    return newVector;
}

Vector2 Vector2Read()
{
    printf("Enter x and y: ");
    int x, y;
    scanf("%d%d", &x, &y);
    return Vector2Init(x, y, RED);
}

double Length(Vector2 vector)
{
    return sqrt(pow(vector.x, 2) + pow(vector.y, 2));
}

void Display(Vector2 vector)
{
    printf("<Vector2 (x:%d, y:%d), Length: %lf>\n", vector.x, vector.y, Length(vector));
}

double Scalar(Vector2 a, Vector2 b)
{
    return a.x * b.x + a.y * b.y;
}

double Angle(Vector2 a, Vector2 b)
{
    double ang = acos(Scalar(a, b) / Length(a) / Length(b)) / M_PI * 180;
    return fmin(ang, 360-ang);
}

Vector2 Add(Vector2 a, Vector2 b)
{
    Vector2 newVector;
    newVector.x = a.x + b.x;
    newVector.y = a.y + b.y;
    return newVector;
}

#endif