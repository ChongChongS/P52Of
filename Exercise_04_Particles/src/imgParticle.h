#include "Particle.h"

class imgParticle:public Particle
{
public:
	imgParticle(ofVec2f l,ofImage m_img);
	void update();
	void display();
	void applyForce(ofVec2f f);
private:
	ofImage img;
};