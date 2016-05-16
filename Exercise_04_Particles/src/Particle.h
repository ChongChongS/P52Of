#include "ofMain.h"

#pragma once
#include "ofMain.h"

class Particle{
public:
	Particle(ofVec2f l);
	Particle(float x,float y,float mr);
	//void run();
	virtual void update();
	virtual void display();
	bool isDead();

	ofVec2f location;
	ofVec2f velocity;
	ofVec2f acceleration;
	float lifespan;
	float r;
};