#include "imgParticle.h"

imgParticle::imgParticle(ofVec2f l,ofImage m_img):
	Particle(l)
{
	acceleration = ofVec2f(0,0);
	float vx = ofNoise(r) * 0.3f;
	float vy = ofNoise(r) * 0.3f - 1.0;
	velocity = ofVec2f(vx,vy);
	location = l;
	lifespan = 100.0;
	img = m_img;
}

void imgParticle::update()
{
	velocity += acceleration;
	location += velocity;
	lifespan -= 2.5;
	acceleration *= 0;
}

void imgParticle::display()
{
	ofSetColor(ofColor(255,255,255,lifespan));
	ofFill();
	ofEllipse(location,img.width,img.height);
}

void imgParticle::applyForce(ofVec2f f)
{
	acceleration += f;
}