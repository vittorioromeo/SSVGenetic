// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

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
	GTCRender::GTCRender(GTGame& mGame, Body& mBody) : game(mGame), body(mBody) { }

	void GTCRender::update(float)
	{
		Vec2f position{toPixels(body.getPosition())}, size{toPixels(body.getSize())};
		for(auto& s : sprites)
		{
			s.setPosition(position + offset);
			s.setScale(flippedX ? -1 : 1, flippedY ? -1 : 1);
			if(scaleWithBody) s.setScale(size.x / 16.f, size.y / 16.f);
		}
	}
	void GTCRender::draw()
	{
		for(const auto& s : sprites) game.render(s);
	}

	void GTCRender::addSprite(Sprite mSprite)
	{
		auto& rect(mSprite.getTextureRect());
		mSprite.setOrigin({rect.width / 2.f, rect.height / 2.f});
		sprites.push_back(mSprite);
	}

	// Getters
	bool GTCRender::isFlippedX() const			{ return flippedX; }
	bool GTCRender::isFlippedY() const			{ return flippedY; }
	vector<Sprite>& GTCRender::getSprites()		{ return sprites; }

	// Setters
	void GTCRender::setRotation(float mDegrees)	{ for(auto& s : sprites) s.setRotation(mDegrees); }
	void GTCRender::setFlippedX(bool mFlippedX)	{ flippedX = mFlippedX; }
	void GTCRender::setFlippedY(bool mFlippedY)	{ flippedY = mFlippedY; }
	void GTCRender::setScaleWithBody(bool mScaleWithBody) { scaleWithBody = mScaleWithBody; }
	void GTCRender::setOffset(Vec2f mOffset)	{ offset = mOffset; }
}
