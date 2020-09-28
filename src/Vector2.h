#ifndef VECTOR_h_
#define VECTOR_h_

#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include "Window.h"

typedef struct
{
    int x;
    int y;
    int *color;
} Vector2;

void Vector2Init(Vector2 *newVector, int x, int y, int *color)
{
    newVector->x = x;
    newVector->y = y;
    newVector->color = color;
}

void Vector2Read(Vector2 *vector)
{
    while (
        printf("Enter x and y: "),
        fflush(stdin),
        2 != scanf("%d%d", &vector->x, &vector->y) &&
        printf("[!] You have entered incorrect data, please try again.\n"));
    fflush(stdin);
}

double Length(Vector2 *vector)
{
    return sqrt(pow(vector->x, 2) + pow(vector->y, 2));
}

void Display(Vector2 *vector)
{
    printf("<Vector2 (x:%d, y:%d), Length: %lf>\n", vector->x, vector->y, Length(vector));
}

double Scalar(Vector2 *a, Vector2 *b)
{
    return a->x * b->x + a->y * b->y;
}

double Angle(Vector2 *a, Vector2 *b)
{
    double ang = acos(Scalar(a, b) / Length(a) / Length(b)) / M_PI * 180;
    return fmin(ang, 360 - ang);
}

Vector2 Add(Vector2 *a, Vector2 *b)
{
    Vector2 newVector;
    newVector.x = a->x + b->x;
    newVector.y = a->y + b->y;
    return newVector;
}

#endif