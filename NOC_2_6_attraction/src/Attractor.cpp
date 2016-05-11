#include "Attractor.h"

Attractor::Attractor(){
	location = ofPoint(ofGetWindowWidth()/2,ofGetWindowHeight()/2);
	mass = 20;
	G = 1;
	dragOffset = ofVec2f(0,0);
}

ofVec2f Attractor::attract(Mover m){
	ofVec2f force = location - m.location;
	float d = location.distance(m.location);
	d = constrain(d,5.0f,25.0f);
	force.normalize();
	float strength = (G * mass * mass)/(d * d);
	force *= strength;
	return force;
}

float Attractor::constrain(float d,float min,float max)
{
	if(d <= min)
		return min;
	else if(d <= max)
		return d;
	else return max;
}

void Attractor::draw()
{
	ofSetLineWidth(4);
	ofNoFill();
	if(dragging)
	{
		ofFill();
		ofSetColor(ofColor(0,0,0,50));
	}
	else if(rollover)
	{
		ofFill();
		ofSetColor(ofColor(0,0,0,100));
	}
	else
	{
		ofFill();
		ofSetColor(ofColor(0,0,0,200));
	}
	ofCircle(location,mass*2);
}

void Attractor::clicked(int mx,int my)
{
	float d = ofPoint(mx,my).distance(location);
	if(d < mass)
	{
		dragging = true;
		dragOffset.x = location.x - mx;
		dragOffset.y = location.y - my;
	}
}

void Attractor::hover(int mx,int my)
{
	float d = ofPoint(mx,my).distance(location);
	if(d < mass)
	{
		rollover = true;
	}
	else
	{
		rollover = false;
	}
}

void Attractor::stopDragging()
{
	dragging = false;
}

void Attractor::drag()
{
	if(dragging)
	{
		location.x = ofGetMouseX() + dragOffset.x;
		location.y = ofGetMouseY() + dragOffset.y;
	}
}