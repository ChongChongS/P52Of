#include "Mover.h"

Mover::Mover()
{

}

Mover::Mover(int x,int y)
{
	mass = 8;
	damping =0.5;
	dragging = false;
	location = ofVec2f(x,y);
	velocity = ofVec2f(0,0);
	acceleration = ofVec2f(0,0);
	dragOffset = ofVec2f(0,0);
}

void Mover::update()
{
	velocity += acceleration;
	velocity *= damping;
	location += velocity;
	acceleration *= 0;
}

void Mover::applyForce(ofVec2f force)
{
	acceleration += force/mass;
}

void Mover::display()
{
	ofSetLineWidth(2);
	ofFill();
	ofSetColor(175);
	if(dragging)
		ofSetColor(50);
	ofCircle(location,mass*2);
	ofSetColor(0);
	ofNoFill();
	ofCircle(location,mass*2);
}

void Mover::clicked(int mx,int my)
{
	float d = location.distance(ofVec2f(mx,my));
	if(d < mass)
	{
		dragging = true;
		dragOffset.x = location.x - mx;
		dragOffset.y = location.y - my;
	}
}

void Mover::stopDragging()
{
	dragging = false;
}

void Mover::drag(int mx,int my)
{
	if(dragging)
	{
		location.x = mx + dragOffset.x;
		location.y = my + dragOffset.y;
	}
}