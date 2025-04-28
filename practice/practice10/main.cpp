#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <string>
#include <sstream>
#include <cmath> 

class Shape {
public:
    virtual double getArea() const = 0; 
    virtual ~Shape() = default; 
};

class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getArea() const override {
        return width * height;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double getArea() const override {
        return M_PI * radius * radius;
    }
};

void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes) {
    for (const auto& shape : shapes) {
        std::cout.precision(4);
        std::cout << "Area: " << std::fixed << shape->getArea() << std::endl;
    }
}

int main() {
    std::ifstream inputFile("shapes.txt");
    if (!inputFile) {
        std::cerr << "Error: Couldn't open file: shapes.txt" << std::endl;
        return 1;
    }

    std::vector<std::unique_ptr<Shape>> shapes;
    std::string line;
    
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string shapeType;
        iss >> shapeType;

        if (shapeType == "rectangle") {
            double width, height;
            iss >> width >> height;
            shapes.push_back(std::make_unique<Rectangle>(width, height));
        } else if (shapeType == "circle") {
            double radius;
            iss >> radius;
            shapes.push_back(std::make_unique<Circle>(radius));
        }
    }

    inputFile.close();

    printAllAreas(shapes);

    return 0;
}
