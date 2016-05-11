#include "ofMain.h"
#include "Mover.h"
class Attractor{
public:
	Attractor();
	ofVec2f attract(Mover m);
	void draw();
	void clicked(int mx,int my);
	void hover(int mx,int my);
	void stopDragging();
	void drag();
	float constrain(float d,float min,float max);
private:
	float mass;
	float G;
	ofPoint location;
	bool dragging;
	bool rollover;
	ofVec2f dragOffset;
};