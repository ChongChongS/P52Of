#include "Vehicle.h"

Vehicle::Vehicle(float x,float y)
{
	acceletration = ofVec2f(0,0);
	velocity = ofVec2f(1,0);
	velocity *= 5;
	location = ofVec2f(x,y);
	r = 3;
	maxspeed = 3;
	maxforce = 0.15;

	debug = true;
	circleLocation = ofVec2f(ofGetWindowWidth()/2,ofGetWindowHeight()/2);
	circleRadius = ofGetWindowHeight()/2 - 25;
}

void Vehicle::update()
{
	velocity += acceletration;
	velocity.limit(maxspeed);
	location += velocity;
	acceletration *= 0;
}

void Vehicle::boundaries()
{
	ofVec2f desired = ofVec2f(0,0);
	ofVec2f predict = velocity;
	predict *= 25;
	ofVec2f futureLocation = location + predict;
	float distance = futureLocation.distance(circleLocation);

	if(distance > circleRadius)
	{
		ofVec2f toCenter = circleLocation - location;
		toCenter.normalize();
		toCenter *= velocity.length();
		desired = velocity + toCenter;
		desired.normalize();
		desired *= maxspeed;
	}

	if(desired.length() > 0)
	{
		ofVec2f steer = desired - velocity;
		steer.limit(maxforce);
		applyForce(steer);
	}

	ofSetColor(ofColor(255,0,0));
	ofFill();
	ofCircle(futureLocation,4);
}

void Vehicle::applyForce(ofVec2f force) 
{
	acceletration += force;
}

void Vehicle::display()
{
	float theta = velocity.angle(ofVec2f(1,0)) - 90;
	ofPushMatrix();
	ofSetColor(0);
	ofFill();
	ofTranslate(location.x,location.y);
	ofRotate(-theta);
	ofTriangle(ofPoint(0,-r*2),ofPoint(-r,r*2),ofPoint(r,r*2));
	ofPopMatrix();
}