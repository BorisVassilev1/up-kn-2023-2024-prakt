#include <iostream>
#include <cstddef>
#include <cmath>

const double EPSILON = 0.001;

struct Point {
    double x, y;
};
struct Rectangle {
    Point p;
    double a, b;
};

bool areEqual(const Point &point1, const Point &point2) {
    return std::abs(point1.x - point2.x) < EPSILON
        && std::abs(point1.y - point2.y) < EPSILON;
}
bool areEqual(const Rectangle &rec1, const Rectangle &rec2) {
    return areEqual(rec1.p, rec2.p)
        && std::abs(rec1.a - rec2.a) < EPSILON
        && std::abs(rec1.b - rec2.b) < EPSILON;
}
double getArea(const Rectangle &rec) {
    return rec.a * rec.b;
}
double unionArea(const Rectangle &rec1, const Rectangle &rec2) {
    double unionArea = getArea(rec1) + getArea(rec2);
    Rectangle intersection = {
        {std::max(rec1.p.x, rec2.p.x), std::max(rec1.p.y, rec2.p.y)},
        std::min(rec1.p.x + rec1.a, rec2.p.x + rec2.a) - std::max(rec1.p.x, rec2.p.x),
        std::min(rec1.p.y + rec1.b, rec2.p.y + rec2.b) - std::max(rec1.p.y, rec2.p.y)
    };

    if (intersection.a > 0 && intersection.b > 0) {
        return unionArea - intersection.a * intersection.b;
    }

    return unionArea;
}

int main() {
    Rectangle rec1{ {0,0}, 3, 4}, rec2{ {1,1}, 3, 4}, rec3{ {-0.0005, 0}, 3, 4};
    std::cout << std::boolalpha << areEqual(rec1, rec2) << std::endl; // -> false
    std::cout << std::boolalpha << areEqual(rec1, rec3) << std::endl; // -> true

    std::cout << unionArea(rec1, rec2) << ' ' << unionArea(rec1, rec3) << std::endl;
    // -> 18 12
    
    return 0;
}