#include <iostream>
#include <cmath>
#include <cstddef>

const double EPSILON = 0.001;

struct Point {
    double x, y;
};

bool areEqual(const Point &point1, const Point &point2) {
    return std::abs(point1.x - point2.x) < EPSILON
        && std::abs(point1.y - point2.y) < EPSILON;
}

double distanceFromOrigin(const Point &point) {
    return std::sqrt(point.x*point.x + point.y*point.y);
}

void swapPoints(Point &point1, Point &point2) {
    Point temp = point1;
    point1 = point2;
    point2 = temp;

    return;
}

bool haveToSwap(const Point &point1, const Point &point2) {
    return (point1.x > point2.x) ||
        (std::abs(point1.x - point2.x) < EPSILON
            && point1.y < point2.y);
}

void sortPoints(Point points[], std::size_t size) {
    for (std::size_t i = 0; i < size - 1; ++i) {
        bool swapped = false;

        for (std::size_t j = 0; j < size - 1 - i; ++j) {
            if (haveToSwap(points[j], points[j + 1])) {
                swapPoints(points[j], points[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false) {
            return;
        }
    }

    return;
}

void printPoints(const Point points[], std::size_t size) {
    for (std::size_t i = 0; i < size; ++i) {
        std::cout << '(' << points[i].x << ',' << points[i].y << ") ";
    }
    std::cout << std::endl;
}

int main() {
    Point x{3, 5}, y{3, 6}, z{3.0001, 5};

    std::cout << std::boolalpha << areEqual(x, y) << ' '
        << areEqual(x, z) << std::endl; // false true
    std::cout << distanceFromOrigin(y) << std::endl; // around 6.7

    Point points[10] = {
        {3, 5},
        {3, 6},
        {4, 5},
        {5, 12},
        {4, 13}
    };
    sortPoints(points, 5);
    printPoints(points, 5);

    return 0;
}