#include "Mover.h"

Mover::Mover()
{
	location =  ofVec2f(30,30);
    velocity =  ofVec2f(0,0);
    acceleration =  ofVec2f(0,0);
    mass = 10;
}

void Mover::update()
{
	velocity = velocity + acceleration;
    location = location + velocity;
    acceleration *= 0;
}

void Mover::applyForce(ofVec2f force)
{
    acceleration += force/mass;
}

void Mover::display()
{
    ofNoFill();
	ofSetColor(ofColor(0));
	ofSetLineWidth(2);
    ofCircle(location,10);
	ofFill();
	ofSetColor(ofColor(127));
	ofCircle(location,10);
}

void Mover::checkEdges()
{
	if (location.x > ofGetWindowWidth()) {
      location.x = ofGetWindowWidth();
      velocity.x *= -1;
    } else if (location.x < 0) {
      velocity.x *= -1;
      location.x = 0;
    }

	if (location.y > ofGetWindowHeight()) {
      velocity.y *= -1;
      location.y = ofGetWindowHeight();
    }
}

