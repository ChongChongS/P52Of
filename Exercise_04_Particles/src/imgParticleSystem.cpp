#include "imgParticleSystem.h"

imgParticleSystem::imgParticleSystem(int num,ofVec2f v,float mr)
{
	origin = v;
	r = mr;
	for(int i = 0; i < num; i++)
	{
		particles.push_back(new imgParticle(origin,r));
	}
}

void imgParticleSystem::update()
{
	for(vector<imgParticle*>::iterator iter=particles.begin();iter!=particles.end();++iter)
	{
		(*iter)->update();
		if((*iter)->isDead())
		{
			particles.erase(iter--);
		}
	}
	//for(auto& p:particles)
	//{
	//	if(p != NULL)
	//		p->update();
	//	if(p->isDead())
	//		p = NULL;
	//}
}

void imgParticleSystem::display()
{
	for(vector<imgParticle*>::iterator iter=particles.begin();iter!=particles.end();++iter)
	{
		(*iter)->display();
	}
	//for(auto& p:particles)
	//{
	//	if(p != NULL)
	//		p->display();
	//}
}

void imgParticleSystem::applyForce(ofVec2f dir)
{
	for(auto& p:particles)
		p->applyForce(dir);
}

void imgParticleSystem::addParticle()
{
	particles.push_back(new imgParticle(origin,r));
}

void imgParticleSystem::addParticle(imgParticle* p)
{
	particles.push_back(p);
}

bool imgParticleSystem::dead()
{
	if(particles.size() <= 0)
		return true;
	else
		return false;
}


