/*
*Shape class source github user rileycr (Riley Cooper)
*
*
*/
#include "Shape.h"

Shape::Shape(Vec2f center, float radius){
	start_center_ = center;
	center_ = center;
	radius_ = radius;
}

void Shape::draw(){
	gl::color(Color8u(255,215,0));
	gl::drawSolidCircle(center_, radius_);
	gl::color(Color8u(255,0,0));
	gl::drawSolidCircle(center_, radius_-8);
}

void Shape::move(int pixels){
	center_.x -=pixels;
	center_.y -=pixels;

}

