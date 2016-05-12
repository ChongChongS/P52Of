#include "ParticleSystem.h"
#include "imgParticle.h"

class imgParticleSystem:public ParticleSystem
{
public:
	imgParticleSystem(int num,ofVec2f v,ofImage m_img);
	void update();
	void display();
	void applyForce(ofVec2f dir);
	void addParticle();
	void addParticle(imgParticle* p);
	bool dead();
private:
	vector<imgParticle*> particles;
	ofVec2f origin;
	ofImage img;
};