#include "ofMain.h"
class Mover{
public:
	Mover();
	void update();
	void draw();
	void applyForce(ofVec2f force);
	void checkEdges();

	ofPoint location;
private:
	ofVec2f velocity;
	ofVec2f acceleration;
	float mass;
};