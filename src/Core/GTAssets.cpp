#include "Core/GTAssets.h"

using namespace std;
using namespace sf;
using namespace ssvu::FileSystem;
using namespace ssvs;

namespace gt
{
	GTAssets::GTAssets()
	{
		getFiles("C:/"); // BUG: these useless lines are needed to avoid linker errors (WTF)
		assetManager.loadFolder("Data/");
	}

	// Getters
	AssetManager& GTAssets::getAssetManager() { return assetManager; }
	Texture& GTAssets::getTexture(const string& mId) { return assetManager.getTexture(mId); }
}
