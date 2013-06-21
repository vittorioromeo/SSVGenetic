// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVGT_CORE_GAME
#define SSVGT_CORE_GAME

#include "Core/GTDependencies.h"
#include "Core/GTFactory.h"
#include "Core/GTDna.h"

namespace gt
{
	constexpr int cameraWidth{1440};
	constexpr int cameraHeight{900};

	struct Node
	{
		int x, y, g{99999};
		bool closed{false}, obstacle{false}, visited{false};
		Node* parent{nullptr};

		Node(int mX, int mY);
	};

	class GTAssets;

	class GTGame
	{
		private:
			ssvs::GameWindow& gameWindow;
			ssvs::Camera camera{gameWindow, {{320 / 2, 240 / 2}, {cameraWidth / 3, cameraHeight / 3}}};
			GTAssets& assets;
			GTFactory factory;
			ssvs::GameState gameState;
			ssvsc::World world; // BUG: world must be destroyed after manager, find a way to make this not required!
			ssvsc::Grid& grid;
			sses::Manager manager;

			int inputX{0}, inputY{0}, inputShoot{0}, inputJump{0}, inputWalk{0};
			sf::Text debugText;
			std::vector<std::vector<Node*>> nodes;
			std::vector<std::vector<int>> debugGrid;
			sf::VertexArray debugGridVertices{sf::PrimitiveType::Quads};

			bool simulating{true};
			GTPopulation population;
			float generationTimerMax{5650}, generationTimer{0};
			int targetX{160000}, targetY{160000};
			void spawnAnts();
			sf::Sprite grassSprite;
			std::string lastGenerationString{""};

			void initInput();
			void initLevel();
			void initDebugGrid();

			void restart();
			void nextGeneration();
			void bfs(int mX, int mY);

			float getRealFT();

		public:
			GTGame(ssvs::GameWindow& mGameWindow, GTAssets& mAssets);

			void update(float mFrameTime);
			void updateDebugText(float mFrameTime);
			void drawDebugGrid();
			void draw();

			void render(const sf::Drawable& mDrawable);
			void setDebugGrid(int mX, int mY);
			void clearDebugGrid();

			// Getters
			ssvs::GameWindow& getGameWindow();
			ssvs::GameState& getGameState();
			sses::Manager& getManager();
			ssvsc::World& getWorld();
			GTFactory& getFactory();
			sf::Vector2i getMousePosition();
			int getInputX();
			int getInputY();
			int getInputShoot();
			int getInputJump();
			int getInputWalk();
			int getTargetX();
			int getTargetY();
			void drawDebugText();
			int getDebugGrid(int mX, int mY);
			int getNodeG(int mX, int mY);
	};
}

#endif
