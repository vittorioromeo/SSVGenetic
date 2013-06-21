// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#include "Components/GTCDnaController.h"
#include "Components/GTCPhysics.h"
#include "Core/GTGame.h"
#include "Core/GTDna.h"
#include "Utils/GTUtils.h"

using namespace ssvs;
using namespace ssvs::Utils;
using namespace sses;
using namespace std;
using namespace sf;
using namespace ssvsc;
using namespace ssvu;

namespace gt
{
	GTCDnaController::GTCDnaController(Entity& mEntity, GTGame& mGame, GTCPhysics& mCPhysics, GTOrganism& mOrganism) : Component(mEntity, "dnaController"),
		game(mGame), cPhysics(mCPhysics), body(cPhysics.getBody()), organism(mOrganism) { }

	void GTCDnaController::update(float mFrameTime)
	{
		auto& dna(organism.dna);
		auto& gene(dna.genes[index]);

		if(index <= dna.genes.size() - 1)
		{
			timer += mFrameTime;
			if(timer < gene.time) return;

			body.setVelocity(gene.velocity);
			timer = 0;

			++index;
		}
		else
		{
			body.setVelocity({0.f, 0.f});
		}
	}

	GTOrganism& GTCDnaController::getOrganism() { return organism; }
}
