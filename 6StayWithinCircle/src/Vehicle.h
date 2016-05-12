#include "ofMain.h"

class Vehicle{
public:
	Vehicle(float x,float y);
	void update();
	void display();
	void boundaries();
	void applyForce(ofVec2f force);

	bool debug;
	ofVec2f circleLocation;
	float circleRadius;
private:
	ofVec2f location;
	ofVec2f velocity;
	ofVec2f acceletration;
	float r;
	float maxspeed;
	float maxforce;
};