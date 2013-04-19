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
		auto dist(sqrt(pow((s.getX() - game.getTargetX()), 2) + pow((s.getY() - game.getTargetY()), 2)));

		if(dist < 1000)
		{
			dist = 0;
			body.setStatic(true);
			fitness = fitnessTimer;
			winner = true;
		}
		else
		{
			fitnessTimer += mFrameTime;
			fitness = dist + fitnessTimer;
		}

		cDnaController.getOrganism().fitness = fitness;
	}

	GTCDnaController& GTCAnt::getDnaController() { return cDnaController; }

	bool GTCAnt::isWinner() { return winner; }
}
