#include "Spring.h"

Spring::Spring(Mover* ma,Mover* mb,int l)
{
	k = 0.2;
	a = ma;
	b = mb;
	len = l;
}

void Spring::update()
{
	ofVec2f force  = a->location - b->location;
	float d = a->location.distance(b->location);
	float stretch = d - len;
	force.normalize();
	force *= (-1 * k * stretch);
	a->applyForce(force);
	force *= -1;
	b->applyForce(force);
}

void Spring::display()
{
	ofSetLineWidth(2);
	ofNoFill();
	ofSetColor(0);
	ofLine(a->location,b->location);
}