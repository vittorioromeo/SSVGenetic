// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVGT_COMPONENTS_PHYSICS
#define SSVGT_COMPONENTS_PHYSICS

#include "Core/GTDependencies.h"

namespace gt
{
	class GTGame;

	class GTCPhysics : public sses::Component
	{
		private:
			static constexpr int crushedMax{3}, crushedTolerance{1};

			GTGame& game;
			ssvsc::World& world;
			ssvsc::Body& body;
			ssvs::Vec2i lastResolution;
			bool affectedByGravity{true};
			int crushedLeft{0}, crushedRight{0}, crushedTop{0}, crushedBottom{0};
			ssvs::Vec2f gravityForce{0, 25};

		public:
			ssvu::Delegate<void, sses::Entity&> onDetection;
			ssvu::Delegate<void, ssvs::Vec2i> onResolution;

			GTCPhysics(GTGame& mGame, ssvsc::World& mWorld, bool mIsStatic, ssvs::Vec2i mPosition, ssvs::Vec2i mSize, bool mAffectedByGravity = true);
			~GTCPhysics();

			void init() override;
			void update(float mFrameTime) override;

			// Setters
			inline void setAffectedByGravity(bool mAffectedByGravity) { affectedByGravity = mAffectedByGravity; }

			// Getters
			inline ssvsc::World& getWorld() const			{ return world; }
			inline ssvsc::Body& getBody() const				{ return body; }
			inline ssvs::Vec2i getLastResolution() const	{ return lastResolution; }
			inline bool isAffectedByGravity() const			{ return affectedByGravity; }
			inline bool isCrushedLeft() const				{ return crushedLeft > crushedTolerance; }
			inline bool isCrushedRight() const				{ return crushedRight > crushedTolerance; }
			inline bool isCrushedTop() const				{ return crushedTop > crushedTolerance; }
			inline bool isCrushedBottom() const				{ return crushedBottom > crushedTolerance; }
			inline int getCrushedLeft() const				{ return crushedLeft; }
			inline int getCrushedRight() const				{ return crushedRight; }
			inline int getCrushedTop() const				{ return crushedTop; }
			inline int getCrushedBottom() const				{ return crushedBottom; }
	};
}

#endif
