#pragma once

#include <iostream>
using namespace std;
#include <cmath>

#include <vector>
#include <queue>//FIFO


class Point {
    public:
        float x = 0.0f;
        float y = 0.0f;

        Point() {}
        Point(float x, float y) : x(x), y(y) {}
};

// Non-member operator+ overload
Point operator+(const Point& lhs, const Point& rhs) {
    return Point(lhs.x + rhs.x, lhs.y + rhs.y);
}

// Non-member operator- overload
Point operator-(const Point& lhs, const Point& rhs) {
    return Point(lhs.x - rhs.x, lhs.y - rhs.y);
}

// Non-member operator+= overload
Point& operator+=(Point& lhs, const Point& rhs) {
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    return lhs;
}

// Non-member operator-= overload
Point& operator-=(Point& lhs, const Point& rhs) {
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    return lhs;
}


// equality operator (==) overload
bool operator==(const Point& lhs, const Point& rhs) {
    return (lhs.x == rhs.x) && (lhs.y == rhs.y);
}


// Function to calculate the Euclidean distance between two points
float B_Distance(const Point& p1, const Point& p2) {
    float deltaX = p2.x - p1.x;
    float deltaY = p2.y - p1.y;

    return std::sqrt(deltaX * deltaX + deltaY * deltaY);
}

