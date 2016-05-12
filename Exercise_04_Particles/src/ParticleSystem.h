#pragma once
#include "Particle.h"
#include <vector>

class ParticleSystem{
public:
	ParticleSystem();
	ParticleSystem(float x,float y,float r);
	virtual void addParticle(float x,float y,float r);
	virtual void update();
	virtual void display();
	void shatter();

private:
	vector<Particle*> particles;
	int rows;
	int cols;
	bool intact;
};