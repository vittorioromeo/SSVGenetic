// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVGT_COMPONENTS_DNACONTROLLER
#define SSVGT_COMPONENTS_DNACONTROLLER

#include "Core/GTDependencies.h"
#include "Core/GTDna.h"

namespace gt
{
	class GTGame;
	class GTCPhysics;

	class GTCDnaController : public sses::Component
	{
		private:
			GTGame& game;
			GTCPhysics& cPhysics;
			ssvsc::Body& body;
			GTOrganism& organism;
			float timer{0};
			unsigned int index{0};

		public:
			GTCDnaController(sses::Entity& mEntity, GTGame& mGame, GTCPhysics& mCPhysics, GTOrganism& mOrganism);

			void update(float mFrameTime) override;

			GTOrganism& getOrganism();
	};
}

#endif
