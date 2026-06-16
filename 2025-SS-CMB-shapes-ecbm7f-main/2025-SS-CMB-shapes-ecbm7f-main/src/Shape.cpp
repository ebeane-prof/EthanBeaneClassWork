#include "Shape.h"
#include <cmath>
#include <string>
#include <algorithm>

const double PI = M_PI;


class Cube : public Shape{
	double l;
public: 
	Cube(double side) : l(side) {}
	double getTSA() const override { return 6 * l * l; }
	double getVolume() const override { return l * l * l; }
	std::string getName() const override { return "Cube"; }
};

class Rectangle : public Shape {
    double l, w, h;
public:
    Rectangle(double l, double w, double h) : l(l), w(w), h(h) {}
    double getTSA() const override { return 2 * (l*w + l*h + w*h); }
    double getVolume() const override { return l * w * h; }
    std::string getName() const override { return "Rectangle"; }
};

class Cylinder : public Shape {
    double w, h;
public:
    Cylinder(double diameter, double h) : w(diameter), h(h) {}
    double getTSA() const override {
        double r = w / 2.0;
        return 2 * PI * r * (r + h);
    }
    double getVolume() const override {
        double r = w / 2.0;
        return PI * r * r * h;
    }
    std::string getName() const override { return "Cylinder"; }
};

class Cone : public Shape {
    double d, h;
public:
    Cone(double d, double h) : d(d), h(h) {}
    double getTSA() const override {
        double r = d / 2.0;
        double l = std::sqrt(r * r + h * h);
        return PI * r * (r + l);
    }
    double getVolume() const override {
        double r = d / 2.0;
        return (PI * r * r * h) / 3.0;
    }
    std::string getName() const override { return "Cone"; }
};


class Sphere : public Shape {
    double d;
public:
    Sphere(double d) : d(d) {}
    double getTSA() const override {
        double r = d / 2.0;
        return 4 * PI * r * r;
    }
    double getVolume() const override {
        double r = d / 2.0;
        return (4.0 / 3.0) * PI * r * r * r;
    }
    std::string getName() const override { return "Sphere"; }
};

class InvalidShape : public Shape {
public:
    double getTSA() const override { return 0.0; }
    double getVolume() const override { return 0.0; }
    std::string getName() const override { return "Invalid"; }
};

Shape* createShape(const std::string& shape, double l, double w, double h) {
    if (shape == "cube") return new Cube(l);
    else if (shape == "rectangle") return new Rectangle(l, w, h);
    else if (shape == "cylinder") return new Cylinder(w, h);
    else if (shape == "cone") return new Cone(w, h);
    else if (shape == "sphere") return new Sphere(w);
    else return new InvalidShape();
}

//your code goes here
