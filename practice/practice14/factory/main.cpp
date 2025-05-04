#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <cmath>
#include <string>

class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return M_PI * radius * radius;
    }
};

class Square : public Shape {
    double side;
public:
    Square(double s) : side(s) {}
    double area() const override {
        return side * side;
    }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override {
        return width * height;
    }
};

class ShapeFactory {
public:
    static std::unique_ptr<Shape> createShape(const std::string& line) {
        std::istringstream iss(line);
        std::string type;
        iss >> type;

        if (type == "circle") {
            double r;
            if (iss >> r)
                return std::make_unique<Circle>(r);
        } else if (type == "square") {
            double s;
            if (iss >> s)
                return std::make_unique<Square>(s);
        } else if (type == "rectangle") {
            double w, h;
            if (iss >> w >> h)
                return std::make_unique<Rectangle>(w, h);
        }

        return nullptr;
    }
};

int main() {
    std::ifstream file("shapes.txt");
    if (!file) {
        std::cerr << "Failed to open file: shapes.txt\n";
        return 1;
    }

    std::vector<std::unique_ptr<Shape>> shapes;
    std::string line;

    while (std::getline(file, line)) {
        auto shape = ShapeFactory::createShape(line);
        if (shape) {
            shapes.push_back(std::move(shape));
        } else {
            std::cerr << "Invalid shape description: " << line << "\n";
        }
    }

    double totalArea = 0.0;
    for (const auto& shape : shapes) {
        totalArea += shape->area();
    }

    std::cout << "Total area of all shapes: " << totalArea << "\n";
    return 0;
}
