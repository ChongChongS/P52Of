#include "imgParticleSystem.h"

imgParticleSystem::imgParticleSystem(int num,ofVec2f v,ofImage m_img)
{
	origin = v;
	img =m_img;
	for(int i = 0; i < num; i++)
	{
		particles.push_back(new imgParticle(origin,img));
	}
}

void imgParticleSystem::update()
{
	
	//for(int i = particles.size() - 1; i >= 0; i--)
	//{
	//	particles[i]->update();
	//	if(particles[i]->isDead())
	//	{
	//		//vector<imgParticle*>::iterator iter=particles.begin() + i;
	//		particles.erase(particles.begin() + i); 
	//	}
	//}
	//
	for(vector<imgParticle*>::iterator iter=particles.begin();iter!=particles.end();)
	{
		(*iter)->update();
		if((*iter)->isDead())
		{
			iter = particles.erase(iter);
		}
		else
			iter++;
	}
}

void imgParticleSystem::display()
{
	for(vector<imgParticle*>::iterator iter=particles.begin();iter!=particles.end();++iter)
	{
		(*iter)->display();
	}
}

void imgParticleSystem::applyForce(ofVec2f dir)
{
	for(auto& p:particles)
		p->applyForce(dir);
}

void imgParticleSystem::addParticle()
{
	particles.push_back(new imgParticle(origin,img));
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


