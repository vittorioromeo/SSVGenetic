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
