// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVGT_UTILS_UTILS
#define SSVGT_UTILS_UTILS

#include "Core/GTDependencies.h"

namespace gt
{
	template<typename T> constexpr float toPixels(T mValue) 		{ return mValue / 100; }
	template<typename T> constexpr int toCoords(T mValue) 			{ return mValue * 100; }
	template<typename T> ssvs::Vec2f toPixels(ssvs::Vec2<T> mValue)	{ return {toPixels(mValue.x), toPixels(mValue.y)}; }
	template<typename T> ssvs::Vec2i toCoords(ssvs::Vec2<T> mValue)	{ return {toCoords(mValue.x), toCoords(mValue.y)}; }
	template<typename T> T getMapped(T mValue, T mOldMin, T mOldMax, T mNewMin, T mNewMax)
	{
		T newRange{mNewMax - mNewMin};
		T oldRange{mOldMax - mOldMin};
		return (mValue - mNewMin) / (newRange * oldRange) + mOldMin;


		return mNewMin + (mNewMax - mNewMin) * ((mValue - mOldMin) / (mOldMax - mOldMin));
	}
}

#endif
