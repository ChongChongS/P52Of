#include "ofMain.h"
#include "Mover.h"

class Spring{
public:
	Spring(Mover* ma,Mover* mb,int l);
	void update();
	void display();
private:
	ofVec2f anchor;
	float len;
	float k;
	Mover* a;
	Mover* b;
};