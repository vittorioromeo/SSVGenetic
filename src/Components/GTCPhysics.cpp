// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#include "Core/GTGame.h"
#include "Components/GTCPhysics.h"

using namespace ssvs;
using namespace sses;
using namespace std;
using namespace sf;
using namespace ssvsc;
using namespace ssvu;

namespace gt
{
	GTCPhysics::GTCPhysics(Entity& mEntity, GTGame& mGame, World& mWorld, bool mIsStatic, Vec2i mPosition, Vec2i mSize, bool mAffectedByGravity)
		: Component(mEntity, "physics"), game(mGame), world(mWorld), body(world.create(mPosition, mSize, mIsStatic)), affectedByGravity{mAffectedByGravity}
	{
		body.setUserData(&getEntity());
	}
	GTCPhysics::~GTCPhysics() { body.destroy(); } // BUG: this has to be called before world is destroyed, or else SEGFAULT - find a way to avoid that!

	void GTCPhysics::update(float)
	{
		//if(affectedByGravity && body.getVelocity().y < maxVelocityY) body.applyForce(gravityForce);
	}

	// Setters
	void GTCPhysics::setAffectedByGravity(bool mAffectedByGravity) { affectedByGravity = mAffectedByGravity; }

	// Getters
	World& GTCPhysics::getWorld()				{ return world; }
	Body& GTCPhysics::getBody()					{ return body; }
	Vec2i GTCPhysics::getLastResolution()	{ return lastResolution; }
	bool GTCPhysics::isAffectedByGravity()		{ return affectedByGravity; }
	bool GTCPhysics::isCrushedLeft()			{ return crushedLeft > crushedTolerance; }
	bool GTCPhysics::isCrushedRight()			{ return crushedRight > crushedTolerance; }
	bool GTCPhysics::isCrushedTop()				{ return crushedTop > crushedTolerance; }
	bool GTCPhysics::isCrushedBottom()			{ return crushedBottom > crushedTolerance; }
	int GTCPhysics::getCrushedLeft()			{ return crushedLeft; }
	int GTCPhysics::getCrushedRight()			{ return crushedRight; }
	int GTCPhysics::getCrushedTop()				{ return crushedTop; }
	int GTCPhysics::getCrushedBottom()			{ return crushedBottom; }
}
