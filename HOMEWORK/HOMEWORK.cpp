#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <cstdlib>

class Circle {
private:
    double x, y;
    double radius;
    std::string color;

    std::string generateRandomColor() {
        const char* colors[] = { "Red", "Green", "Blue", "Yellow", "Purple", "Orange" };
        int numColors = sizeof(colors) / sizeof(colors[0]);
        int randomIndex = rand() % numColors;
        return colors[randomIndex];
    }

public:
    static const double M_PI;

    Circle(double x, double y, double radius, const std::string& color) {
        setX(x);
        setY(y);
        setRadius(radius);
        setColor(color);
    }

    Circle() : Circle(0.0, 0.0, 1.0, "Black") {}

    double getX() const { return x; }
    void setX(double newX) { x = newX; }

    double getY() const { return y; }
    void setY(double newY) { y = newY; }

    double getRadius() const { return radius; }
    void setRadius(double newRadius) { radius = newRadius; }

    const std::string& getColor() const { return color; }
    void setColor(const std::string& newColor) { color = newColor; }

    double calculateCircumference() const {
        return 2.0 * M_PI * radius;
    }

    double calculateArea() const {
        return M_PI * radius * radius;
    }

    void printToFile(const std::string& filename) const {
        std::ofstream outputFile(filename);
        if (outputFile.is_open()) {
            outputFile << "Circle Information:" << std::endl;
            outputFile << "Center Coordinates: (" << x << ", " << y << ")" << std::endl;
            outputFile << "Radius: " << radius << std::endl;
            outputFile << "Color: " << color << std::endl;
            outputFile << "Circumference: " << calculateCircumference() << std::endl;
            outputFile << "Area: " << calculateArea() << std::endl;
            outputFile.close();
        }
        else {
            std::cerr << "Unable to open file: " << filename << std::endl;
        }
    }

    void changeColorRandomly() {
        setColor(generateRandomColor());
    }
};

const double Circle::M_PI = 3.14159265358979323846;

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    Circle circle1(2.0, 3.0, 5.0, "Blue");
    Circle circle2;

    std::cout << "Circle 1 Circumference: " << circle1.calculateCircumference() << std::endl;
    std::cout << "Circle 1 Area: " << circle1.calculateArea() << std::endl;

    circle1.printToFile("circle1_info.txt");

    std::cout << "Circle 2 Color before change: " << circle2.getColor() << std::endl;
    circle2.changeColorRandomly();
    std::cout << "Circle 2 Color after change: " << circle2.getColor() << std::endl;

    return 0;
}