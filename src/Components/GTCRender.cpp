#include "Core/GTGame.h"
#include "Components/GTCRender.h"
#include "Utils/GTUtils.h"

using namespace ssvs;
using namespace sses;
using namespace std;
using namespace sf;
using namespace ssvsc;
using namespace ssvu;

namespace gt
{
	GTCRender::GTCRender(Entity& mEntity, GTGame& mGame, Body& mBody) : Component(mEntity, "render"), game(mGame), body(mBody) { }

	void GTCRender::update(float)
	{
		Vector2f position{toPixels(body.getPosition())}, size{toPixels(body.getSize())};
		for(auto& sprite : sprites)
		{
			auto& rect(sprite.getTextureRect());
			sprite.setOrigin({rect.width / 2.f, rect.height / 2.f});

			sprite.setPosition(position + offset);
			sprite.setScale(flippedX ? -1 : 1, flippedY ? -1 : 1);
			if(scaleWithBody) sprite.setScale(size.x / 16.f, size.y / 16.f);
		}
	}
	void GTCRender::draw() { for(auto& sprite : sprites) game.render(sprite); }

	void GTCRender::addSprite(Sprite mSprite) { sprites.push_back(mSprite); }

	// Getters
	bool GTCRender::isFlippedX() const			{ return flippedX; }
	bool GTCRender::isFlippedY() const			{ return flippedY; }
	vector<Sprite>& GTCRender::getSprites()		{ return sprites; }

	// Setters
	void GTCRender::setRotation(float mDegrees)	{ for(auto& sprite : sprites) sprite.setRotation(mDegrees); }
	void GTCRender::setFlippedX(bool mFlippedX)	{ flippedX = mFlippedX; }
	void GTCRender::setFlippedY(bool mFlippedY)	{ flippedY = mFlippedY; }
	void GTCRender::setScaleWithBody(bool mScaleWithBody) { scaleWithBody = mScaleWithBody; }
	void GTCRender::setOffset(Vector2f mOffset)	{ offset = mOffset; }
}
