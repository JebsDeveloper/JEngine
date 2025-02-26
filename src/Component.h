#pragma once

class GameObject;

class Component {
public:
	virtual ~Component() = default;

	GameObject* parent = nullptr;
};
