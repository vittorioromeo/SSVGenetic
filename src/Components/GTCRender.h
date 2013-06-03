#ifndef SSVGT_COMPONENTS_RENDER
#define SSVGT_COMPONENTS_RENDER

#include "Core/GTDependencies.h"

namespace gt
{
	class GTGame;

	class GTCRender : public sses::Component
	{
		private:
			GTGame& game;
			ssvsc::Body& body;
			std::vector<sf::Sprite> sprites;
			bool flippedX{false}, flippedY{false}, scaleWithBody{false};
			sf::Vector2f offset;

		public:
			GTCRender(sses::Entity& mEntity, GTGame& mGame, ssvsc::Body& mBody);

			void update(float) override;
			void draw() override;

			void addSprite(sf::Sprite mSprite);

			// Getters
			bool isFlippedX() const;
			bool isFlippedY() const;
			std::vector<sf::Sprite>& getSprites();

			// Setters
			void setRotation(float mDegrees);
			void setFlippedX(bool mFlippedX);
			void setFlippedY(bool mFlippedY);
			void setScaleWithBody(bool mScaleWithBody);
			void setOffset(sf::Vector2f mOffset);
	};

	// TODO: find a way to add sprites with individual offsets, and still have a global offset (RenderData struct?)
}

#endif
