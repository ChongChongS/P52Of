#include "ofMain.h"

class Mover{
public:
	Mover();
	Mover(int x,int y);
	void update();
	void display();
	void applyForce(ofVec2f force);
	void stopDragging();
	void drag(int mx,int my);
	void clicked(int mx,int my);

	ofVec2f location;
private:
    ofVec2f velocity;
	ofVec2f acceleration;
	float mass;
	float damping;
	ofVec2f dragOffset;
	bool dragging;
};