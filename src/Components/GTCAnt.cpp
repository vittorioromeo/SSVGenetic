// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#include "Components/GTCAnt.h"
#include "Components/GTCPhysics.h"
#include "Components/GTCRender.h"
#include "Components/GTCDnaController.h"
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
	GTCAnt::GTCAnt(Entity& mEntity, GTGame& mGame, GTCDnaController& mCDnaController, GTCPhysics& mCPhysics, GTCRender& mCRender) : Component(mEntity, "ant"),
		game(mGame), cDnaController(mCDnaController), cPhysics(mCPhysics), cRender(mCRender), body(cPhysics.getBody())
	{
		body.onDetection += [&](DetectionInfo mInfo)
		{
			if(contains(mInfo.body.getGroups(), "wall")) fitness += 2000;
		};
	}

	void GTCAnt::update(float mFrameTime)
	{
		cRender.setRotation(getDegrees(body.getVelocity()));

		auto& s(body.getShape());
		Grid& grid = body.getWorld().getSpatial<Grid>();
		auto dist( game.getNodeG(grid.getIndex(s.getPosition()).x, grid.getIndex(s.getPosition()).y));

		if(dist < 10)
		{
			dist = 0;
			body.setStatic(true);
			fitness = 0;
			winner = true;
		}
		else
		{
			fitnessTimer += mFrameTime;
			fitness = dist + fitnessTimer / 100;
		}

		cDnaController.getOrganism().fitness = fitness;
	}

	GTCDnaController& GTCAnt::getDnaController() { return cDnaController; }

	bool GTCAnt::isWinner() { return winner; }
}
