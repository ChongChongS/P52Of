#include "ofMain.h"
class Mover{
public:
	Mover();
	void update();
	void draw();
private:
	ofPoint location;
	ofVec2f velocity;
	ofVec2f acceleration;
	float topSpeed;
};