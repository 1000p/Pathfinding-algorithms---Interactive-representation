#include "Node.h"

#include "RenderManager.h"

SDL_Texture* Node::openT = nullptr;
SDL_Texture* Node::closedT = nullptr;
SDL_Texture* Node::startT = nullptr;
SDL_Texture* Node::endT = nullptr;
SDL_Texture* Node::pathT = nullptr;
SDL_Texture* Node::obstacleT = nullptr;
SDL_Texture* Node::whiteT = nullptr;
SDL_Texture* Node::hoverT = nullptr;


void Node::initializeNodeTextures()
{

	SDL_Renderer* renderer = RenderManager::getRenderer();

	//SDL_ShowWindow(RenderManager::getWindow());

	//Check if textures are initialized
	if (openT != nullptr || closedT != nullptr || startT != nullptr ||
		endT != nullptr || pathT != nullptr || obstacleT != nullptr ||
		whiteT != nullptr)
	{
		std::cout << "Textures already initialized!" << std::endl;
		return;
	}

	//Load surfaces from files
	SDL_Surface* open = IMG_Load("Tiles/opened.png");
	SDL_Surface* close = IMG_Load("Tiles/closed.png");
	SDL_Surface* start = IMG_Load("Tiles/start.png");
	SDL_Surface* end = IMG_Load("Tiles/end.png");
	SDL_Surface* path = IMG_Load("Tiles/path.png");
	SDL_Surface* obstacle = IMG_Load("Tiles/obstacle.png");
	SDL_Surface* white = IMG_Load("Tiles/white.png");
	SDL_Surface* hover = IMG_Load("Tiles/hover.png");

	//If any surface is not initialized exit
	if (open == nullptr || close == nullptr || start == nullptr ||
		end == nullptr || path == nullptr || obstacle == nullptr ||
		white == nullptr || hover == nullptr)
	{
		std::cout << "Could not load tile/s surfaces!" << std::endl;
		exit(-404);
	}

	//TEST
	SDL_RenderClear(renderer);

	//Create textures from surfaces and global renderer
	openT = SDL_CreateTextureFromSurface(renderer, open);
	closedT = SDL_CreateTextureFromSurface(renderer, close);
	startT = SDL_CreateTextureFromSurface(renderer, start);
	endT = SDL_CreateTextureFromSurface(renderer, end);
	pathT = SDL_CreateTextureFromSurface(renderer, path);
	obstacleT = SDL_CreateTextureFromSurface(renderer, obstacle);
	whiteT = SDL_CreateTextureFromSurface(renderer, white);
	hoverT = SDL_CreateTextureFromSurface(renderer, hover);

	/*SDL_ShowWindow(RenderManager::getWindow());
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, hoverT, NULL, NULL);
	SDL_RenderPresent(renderer);*/

	//If any texture is not initialized exit
	if (openT == nullptr || closedT == nullptr || startT == nullptr ||
		endT == nullptr || pathT == nullptr || obstacleT == nullptr ||
		whiteT == nullptr || hoverT == nullptr)
	{
		std::cout << "Could not load tile/s textures from surfaces!" << std::endl;
		exit(-404);
	}
	//Release resources
	SDL_FreeSurface(open);
	SDL_FreeSurface(close);
	SDL_FreeSurface(start);
	SDL_FreeSurface(end);
	SDL_FreeSurface(path);
	SDL_FreeSurface(obstacle);
	SDL_FreeSurface(white);
	SDL_FreeSurface(hover);

}

void Node::handleEvent(SDL_Event* evt)
{
	switch (evt->type)
	{
	case SDL_MOUSEMOTION:
	{
		changeState(NodeState::HOVER);
		owner->setLastHovered(this);
	}
	default:
		break;
	}
}