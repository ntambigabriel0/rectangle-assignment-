#include <iostream>

class Rectangle {
private:
    double width;
    double length;

public:
    // Default constructor: safe starting values
    Rectangle() : width(1.0), length(1.0) {}

    // Parameterized constructor (reuses setters for validation)
    Rectangle(double w, double l) : width(1.0), length(1.0) {
        setWidth(w);
        setLength(l);
    }

    void setWidth(double w) {
        if (w > 0) {
            width = w;
        } else {
            std::cout << "Width must be positive. Setting default to 1.0\n";
            width = 1.0;
        }
    }

    void setLength(double l) {
        if (l > 0) {
            length = l;
        } else {
            std::cout << "Length must be positive. Setting default to 1.0\n";
            length = 1.0;
        }
    }

    double getWidth() const { return width; }
    double getLength() const { return length; }

    double calculateArea() const { return width * length; }
    double calculatePerimeter() const { return 2 * (width + length); }
};

int main() {
    // Example 1: default constructor, then set dimensions
    Rectangle rect;
    rect.setWidth(5.5);
    rect.setLength(10.0);

    std::cout << "--- Rectangle 1 ---" << std::endl;
    std::cout << "Width: " << rect.getWidth() << std::endl;
    std::cout << "Length: " << rect.getLength() << std::endl;
    std::cout << "Area: " << rect.calculateArea() << std::endl;
    std::cout << "Perimeter: " << rect.calculatePerimeter() << std::endl;

    // Example 2: parameterized constructor
    Rectangle rect2(3.0, 7.0);

    std::cout << "\n--- Rectangle 2 ---" << std::endl;
    std::cout << "Width: " << rect2.getWidth() << std::endl;
    std::cout << "Length: " << rect2.getLength() << std::endl;
    std::cout << "Area: " << rect2.calculateArea() << std::endl;
    std::cout << "Perimeter: " << rect2.calculatePerimeter() << std::endl;

    // Example 3: update an existing rectangle
    rect2.setWidth(4.0);
    rect2.setLength(6.0);

    std::cout << "\n--- Rectangle 2 after update ---" << std::endl;
    std::cout << "Width: " << rect2.getWidth() << std::endl;
    std::cout << "Length: " << rect2.getLength() << std::endl;
    std::cout << "Area: " << rect2.calculateArea() << std::endl;
    std::cout << "Perimeter: " << rect2.calculatePerimeter() << std::endl;

    // Example 4: invalid input falls back to default
    std::cout << "\n--- Invalid input test ---" << std::endl;
    rect.setWidth(-3.0);
    std::cout << "Width after invalid set: " << rect.getWidth() << std::endl;

    return 0;
}
