/*
*Shape class source github user rileycr (Riley Cooper)
*
*
*/
#ifndef SHAPE_H
#define SHAPE_H

#include "cinder\gl\gl.h"


using namespace ci;

class Shape {
public:
	Shape(Vec2f center, float radius);
	void draw();
	void move(int pixels);
	void moveDown(int pixels);
	float getCenterY(); //added this method to access the x-value of center
private:
	Vec2f center_;
	Vec2f start_center_;
	float radius_;
};

#endif