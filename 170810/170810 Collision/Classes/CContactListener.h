#pragma once

#include <stdio.h>
#include "cocos2d.h"
#include "Box2D\Box2D.h"

using namespace cocos2d;
struct SContacts
{
	b2Fixture *fixtureA;
	b2Fixture *fixtureB;

	bool operator == (const SContacts& other) const
	{
		return(fixtureA == other.fixtureA) && (fixtureB == other.fixtureB);
	}
};

class CContactListener : public b2ContactListener
{
public:
	std::vector<SContacts> mSContacts;

	CContactListener();
	~CContactListener();

	virtual void BeginContact(b2Contact *contact);
	virtual void EndContact(b2Contact *contact);
	virtual void PreSolve(b2Contact *contact, const b2Manifold *oldManifold);
	virtual void PostSolve(b2Contact *contact, const b2ContactImpulse *inpulse);	
};