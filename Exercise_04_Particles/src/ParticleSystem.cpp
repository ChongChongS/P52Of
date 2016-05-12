#include "ParticleSystem.h"

ParticleSystem::ParticleSystem()
{

}

ParticleSystem::ParticleSystem(float x,float y,float r)
{
	rows = 20;
	cols = 20;
	intact = true;
	
	for(int i = 0; i < rows * cols; i++)
	{
		addParticle(x + (i % cols) * r,y + (i / rows) * r,r);
	}
}

void ParticleSystem::addParticle(float x,float y,float r)
{
	particles.push_back(new Particle(x,y,r));
}

void ParticleSystem::display()
{
	for(auto& p:particles)
	{
		p->display();
	}
}

void ParticleSystem::shatter()
{
	intact = false;
}

void ParticleSystem::update()
{
	if(!intact)
	{
		for(auto& p:particles)
			p->update();
	}
}
