#include "Mover.h"

Mover::Mover()
{
	location = ofPoint(400,50);
	velocity = ofVec2f(1,0);
	acceleration = ofVec2f(0,0);
	mass = 1;
}

void Mover::applyForce(ofVec2f force)
{
	ofVec2f f = force / mass;
	acceleration += f;
}

void Mover::update()
{
	velocity += acceleration;
	location += velocity;
	acceleration *= 0;
}

void Mover::draw()
{
	ofSetLineWidth(5);
	ofSetColor(ofColor(127));
	ofSetCircleResolution(60);
	ofNoFill();
	ofCircle(location,16);
	ofFill();
	ofCircle(location,16);
}

void Mover::checkEdges()
{
	if(location.x > ofGetWindowWidth())
		location.x = 0;
	else if(location.x < 0)
		location.x = ofGetWindowWidth();

	if(location.y > ofGetWindowHeight()){
		velocity.y *= -1;
		location.y = ofGetWindowHeight();
	}
}