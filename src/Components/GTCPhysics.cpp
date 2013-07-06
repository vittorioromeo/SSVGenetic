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
	GTCPhysics::GTCPhysics(GTGame& mGame, World& mWorld, bool mIsStatic, Vec2i mPosition, Vec2i mSize, bool mAffectedByGravity)
		: Component("physics"), game(mGame), world(mWorld), body(world.create(mPosition, mSize, mIsStatic)), affectedByGravity{mAffectedByGravity} { }
	GTCPhysics::~GTCPhysics() { body.destroy(); } // BUG: this has to be called before world is destroyed, or else SEGFAULT - find a way to avoid that!

	void GTCPhysics::init() { body.setUserData(&getEntity()); }
	void GTCPhysics::update(float)
	{
		//if(affectedByGravity && body.getVelocity().y < maxVelocityY) body.applyForce(gravityForce);
	}
}
