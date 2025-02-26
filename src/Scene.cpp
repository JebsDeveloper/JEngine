#include "Scene.h"

Scene::Scene() {

}

Scene::~Scene() {

}

void Scene::addGameObject(unsigned int id, std::unique_ptr<GameObject> object) {
	gameObjects[id] = std::move(object);
}

void Scene::removeGameObject(unsigned int id) {
	gameObjects.erase(id);
}

GameObject* Scene::getGameObject(unsigned int id) {
	auto it = gameObjects.find(id);

	return it != gameObjects.end() ? it -> second.get() : nullptr;
}

void Scene::render(Renderer &renderer) {
	for (const auto &[id, obj] : gameObjects) {
		renderer.renderGameObject(*obj);
	}
}
