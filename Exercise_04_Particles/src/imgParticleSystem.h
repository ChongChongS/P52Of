#include "ParticleSystem.h"
#include "imgParticle.h"

class imgParticleSystem:public ParticleSystem
{
public:
	imgParticleSystem(int num,ofVec2f v,float mr);
	void update();
	void display();
	void applyForce(ofVec2f dir);
	void addParticle();
	void addParticle(imgParticle* p);
	bool dead();

	vector<imgParticle*> particles;
private:
	ofVec2f origin;
	float r;
};