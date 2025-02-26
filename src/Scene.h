#pragma once

#include <unordered_map>
#include <memory>

#include "GameObject.h"
#include "Renderer.h"

class Scene {
public:
	Scene();
	~Scene();

	void addGameObject(unsigned int id, std::unique_ptr<GameObject> object);
	void removeGameObject(unsigned int id);

	GameObject* getGameObject(unsigned int id);

	void render(Renderer &renderer);

	std::unordered_map<unsigned int, std::unique_ptr<GameObject>> gameObjects;
};
