#include "Particle.h"

Particle::Particle(float x,float y,float mr)
{
	acceleration = ofVec2f(0,0.01);
	velocity = ofVec2f(ofRandomf(),ofRandomf());
	velocity *= 0.5;
	location = ofVec2f(x,y);
	lifespan = 255.0;
	r = mr;
}

Particle::Particle(ofVec2f l,float mr)
{
	location = l;
	r = mr;
}

void Particle::update()
{
	velocity += acceleration;
	location += velocity;
	if(lifespan > 0.0)
		lifespan -= 2.0;
}

void Particle::display()
{
	ofFill();
	ofSetColor(0);
	ofRectMode(OF_RECTMODE_CENTER);
	ofRect(location.x,location.y,r,r);
}

bool Particle::isDead()
{
	if(lifespan <= 0.0)
		return true;
	else
		return false;
}