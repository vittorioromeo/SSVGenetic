// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVGT_CORE_ASSETS
#define SSVGT_CORE_ASSETS

#include "Core/GTDependencies.h"

namespace gt
{
	class GTAssets
	{
		private:
			ssvs::AssetManager assetManager;

		public:
			GTAssets();

			// Getters
			ssvs::AssetManager& getAssetManager();
			sf::Texture& getTexture(const std::string& mId);
	};
}

#endif
