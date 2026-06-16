#ifndef SHAPE_H
#define SHAPE_H
#include <string>

enum class ShapeType {
	CUBE,
	RECTANGLE,
	CYLINDER,
	CONE,
	SPHERE,
	INVALID
};

class Shape {
public:
	virtual double getTSA() const = 0;
	virtual double getVolume() const = 0;
	virtual std::string getName() const = 0;
	virtual ~Shape() {}
};

Shape* createShape(const std::string& shape, double l, double w, double h);

//your code goes here

#endif
