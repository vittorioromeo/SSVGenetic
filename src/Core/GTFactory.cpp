#include "Core/GTFactory.h"
#include "Core/GTAssets.h"
#include "Core/GTGame.h"
#include "Core/GTDna.h"
#include "Components/GTCPhysics.h"
#include "Components/GTCRender.h"
#include "Components/GTCDnaController.h"
#include "Components/GTCAnt.h"

using namespace std;
using namespace sf;
using namespace ssvu;
using namespace ssvuj;
using namespace sses;
using namespace ssvs;
using namespace ssvsc;
using namespace ssvsc::Utils;

namespace gt
{
	GTFactory::GTFactory(GTAssets& mAssets, GTGame& mGame, Manager& mManager, World& mWorld) : assets(mAssets), game(mGame),
		manager(mManager), world(mWorld) { }

	Entity& GTFactory::createWall(Vector2i mPosition)
	{
		auto& result(manager.createEntity("wall"));
		auto& cPhysics(result.createComponent<GTCPhysics>(game, world, true, mPosition, Vector2i{1600, 1600}));
		auto& cRender(result.createComponent<GTCRender>(game, cPhysics.getBody()));

		Body& body(cPhysics.getBody());
		body.addGroups({"solid"});
		body.addGroups({"wall"});

		cRender.addSprite(Sprite{assets.getTexture("wall.png")});
		cRender.setScaleWithBody(true);

		return result;
	}

	Entity& GTFactory::createAnt(Vector2i mPosition, GTOrganism& mOrganism)
	{
		auto& result(manager.createEntity("ant"));
		auto& cPhysics(result.createComponent<GTCPhysics>(game, world, false, mPosition, Vector2i{1000, 1000}));
		auto& cRender(result.createComponent<GTCRender>(game, cPhysics.getBody()));
		auto& cDnaController(result.createComponent<GTCDnaController>(game, cPhysics, mOrganism));
		result.createComponent<GTCAnt>(game, cDnaController, cPhysics, cRender);

		Body& body(cPhysics.getBody());
		body.addGroups({"ant"});
		body.addGroupsToCheck({"solid"});
		body.addGroupsNoResolve({"ant"});

		cRender.addSprite(Sprite{assets.getTexture("ant.png")});
		cRender.setScaleWithBody(true);

		return result;
	}
}
