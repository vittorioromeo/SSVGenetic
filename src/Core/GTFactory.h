#ifndef SSVGT_CORE_FACTORY
#define SSVGT_CORE_FACTORY

#include "Core/GTDependencies.h"

namespace gt
{
	class GTAssets;
	class GTGame;
	class GTOrganism;

	class GTFactory
	{
		private:
			GTAssets& assets;
			GTGame& game;
			sses::Manager& manager;
			ssvsc::World& world;

		public:
			GTFactory(GTAssets& mAssets, GTGame& mGame, sses::Manager& mManager, ssvsc::World& mWorld);

			sses::Entity& createWall(sf::Vector2i mPosition);
			sses::Entity& createAnt(sf::Vector2i mPosition, GTOrganism& mOrganism);
	};
}

#endif
