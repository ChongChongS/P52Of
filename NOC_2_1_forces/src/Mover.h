#include "ofMain.h"

class Mover{
public:
	Mover();
	void update();
	void display();
	void applyForce(ofVec2f force);
	void checkEdges();
	

	ofVec2f location;
private:
    ofVec2f velocity;
	ofVec2f acceleration;
	float mass;
	
	
};