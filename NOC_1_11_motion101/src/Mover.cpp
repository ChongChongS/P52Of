#include "Mover.h"

Mover::Mover()
{
	location = ofPoint(ofRandom(ofGetWindowWidth()),ofRandom(ofGetWindowHeight()));
	velocity = ofVec2f(0,0);
	topSpeed = 5;
}

void Mover::update()
{
	ofPoint mouse = ofPoint(ofGetMouseX(),ofGetMouseY());
	acceleration = ofVec2f(mouse - location);
	acceleration.normalize();
	acceleration *= 0.2;

	velocity += acceleration;
	velocity.limit(topSpeed);
	location += velocity;
}

void Mover::draw()
{
	ofSetLineWidth(5);
	ofSetColor(ofColor(0,0,0,50));
	ofSetCircleResolution(60);
	ofNoFill();
	ofCircle(location,48);
	ofFill();
	ofCircle(location,48);
}