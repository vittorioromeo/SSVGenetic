#ifndef SSVGT_COMPONENTS_ANT
#define SSVGT_COMPONENTS_ANT

#include "Core/GTDependencies.h"

namespace gt
{
	class GTGame;
	class GTCDnaController;
	class GTCPhysics;
	class GTCRender;
	struct GTDna;

	class GTCAnt : public sses::Component
	{
		private:
			GTGame& game;
			GTCDnaController& cDnaController;
			GTCPhysics& cPhysics;
			GTCRender& cRender;
			ssvsc::Body& body;

			bool winner{false};
			float fitness{15000};
			float fitnessTimer{0};

		public:

			GTCAnt(sses::Entity& mEntity, GTGame& mGame, GTCDnaController& mCDnaController, GTCPhysics& mCPhysics, GTCRender& mCRender);

			void update(float mFrameTime) override;

			GTCDnaController& getDnaController();
			bool isWinner();
	};
}

#endif
