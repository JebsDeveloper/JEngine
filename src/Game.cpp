#include "Game.h"

#include <glad/glad.h>

#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

#include <raudio.h>

#include "Window.h"
#include "Shader.h"
#include "Renderer.h"

#include "GameObject.h"

#include "Transform.h"
#include "Sprite.h"

#include "AABBCollider.h"

#include "Globals.h"
#include "Callbacks.h"

#include "Scene.h"

Game::Game() {

}

Game::~Game() {

}

void Game::run() {
	Window window = Window(1500, 900, "JEngine");
	window.init();

	Shader shader = Shader(RESOURCES_PATH "shaders/vertexShader.shader", RESOURCES_PATH "shaders/fragmentShader.shader");
	Renderer renderer = Renderer(shader);

	renderer.initRenderData();

	glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(window.getWidth()), static_cast<float>(window.getHeight()), 0.0f, -1.0f, 1.0f);

	shader.use();

	shader.setInt("image", 0);
	shader.setMat4("projection", projection);

	Scene scene = Scene();

	Texture green = Texture(RESOURCES_PATH "textures/player.png");

	GameObject player = GameObject();

	Transform playerTransform = Transform({200.0f, 300.0f}, 0.0f, {100.0f, 100.0f});
	Sprite playerSprite = Sprite(green);
	AABBCollider playerCollider = AABBCollider();

	player.addComponent(&playerTransform);
	player.addComponent(&playerSprite);
	player.addComponent(&playerCollider);

	Globals::player = &player;

	GameObject wall1 = GameObject();

	Transform wall1Transform = Transform({500.0f, 200.0f}, 0.0f, {200.0f, 200.0f});
	Sprite wall1Sprite = Sprite(green);
	AABBCollider wall1Collider = AABBCollider();

	wall1.addComponent(&wall1Transform);
	wall1.addComponent(&wall1Sprite);
	wall1.addComponent(&wall1Collider);

	scene.addGameObject(0, std::make_unique<GameObject>(player));
	scene.addGameObject(1, std::make_unique<GameObject>(wall1));

	//InitAudioDevice();

	//Music bgMusic = LoadMusicStream(RESOURCES_PATH "audio/BGMusic.ogg");

	//PlayMusicStream(bgMusic);

	std::vector<AABBCollider*> colliders;

	for (const auto &[id, obj] : scene.gameObjects) {
		if (!obj.get() -> hasComponent<AABBCollider>()) continue;

		colliders.push_back(&obj.get() -> getComponent<AABBCollider>());
	}

	float deltaTime = 0.0f;
	float lastFrame = 0.0f;

	while (!window.windowShouldClose()) {
		float currentFrame = glfwGetTime();

		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		//UpdateMusicStream(bgMusic);

		glClear(GL_COLOR_BUFFER_BIT);

		for (const AABBCollider* collider : colliders) {
			Globals::playerCollision = playerCollider.collisionState(*collider);
		}

		// William Shakespear
		// will i am shake spear
		// would i was shook speard
		// Wouldiwas Shookspeard

		scene.render(renderer);

		window.update();
		Callbacks::inputPerFrame(window.getWindow(), deltaTime);
	}

	//UnloadMusicStream(bgMusic);
	//CloseAudioDevice();

	window.cleanup();
}
