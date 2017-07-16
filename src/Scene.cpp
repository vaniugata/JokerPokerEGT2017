#include "Scene.h"
#include <iostream>
using std::cout;

Scene::Scene(SDL_Renderer* renderer) :
	m_renderer(renderer)
{

}

Scene::~Scene()
{
	std::cout << "GameState deleted.\n";
}

void Scene::Draw()
{
	SDL_RenderPresent(m_renderer);
	SDL_RenderClear(m_renderer);
}
