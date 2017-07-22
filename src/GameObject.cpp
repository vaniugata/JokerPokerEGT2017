#include "GameObject.h"
#include "Globals.h"
#include <iostream>
using std::cerr;


GameObject::GameObject(SDL_Renderer* renderer) :
	m_renderer(renderer)
{

}

GameObject::~GameObject()
{
	std::cerr << "GameObject deleted.\n";
}

