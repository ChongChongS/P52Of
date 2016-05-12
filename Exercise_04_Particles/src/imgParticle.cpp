#include "imgParticle.h"

imgParticle::imgParticle(ofVec2f l,float r):
	Particle(l,r)
{
	acceleration = ofVec2f(0,0);
	float vx = ofNoise(r) * 0.3f;
	float vy = ofNoise(r) * 0.3f - 1.0;
	velocity = ofVec2f(vx,vy);
	location = l;
	lifespan = 100.0;
}

void imgParticle::update()
{
	velocity += acceleration;
	location += velocity;
	if(lifespan > 0.0)
		lifespan -= 2.0;
	acceleration *= 0;
}

void imgParticle::display()
{
	ofSetColor(ofColor(255,255,255,lifespan));
	ofFill();
	ofCircle(location,r);
}

void imgParticle::applyForce(ofVec2f f)
{
	acceleration += f;
}