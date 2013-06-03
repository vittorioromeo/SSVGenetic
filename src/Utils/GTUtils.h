#ifndef SSVGT_UTILS_UTILS
#define SSVGT_UTILS_UTILS

#include "Core/GTDependencies.h"

namespace gt
{
	template<typename T> float toPixels(T mValue)						{ return mValue / 100; }
	template<typename T> int toCoords(T mValue)							{ return mValue * 100; }
	template<typename T> sf::Vector2f toPixels(sf::Vector2<T> mValue)	{ return {toPixels(mValue.x), toPixels(mValue.y)}; }
	template<typename T> sf::Vector2i toCoords(sf::Vector2<T> mValue)	{ return {toCoords(mValue.x), toCoords(mValue.y)}; }
	template<typename T> T getMapped(T mValue, T mOldMin, T mOldMax, T mNewMin, T mNewMax)
	{
		T newRange{mNewMax - mNewMin};
		T oldRange{mOldMax - mOldMin};
		return (mValue - mNewMin) / (newRange * oldRange) + mOldMin;


		return mNewMin + (mNewMax - mNewMin) * ((mValue - mOldMin) / (mOldMax - mOldMin));
	}
}

#endif
