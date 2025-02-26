#pragma once

#include <vector>
#include <memory>

#include <iostream>
#include <stdexcept>

#include "Component.h"
#include "Transform.h"

class GameObject {
public:
	GameObject();
	~GameObject();
	
	template<typename T> void addComponent(T* component) {
		if (!component) return;
		if (this -> hasComponent<T>()) return;

		this -> components.push_back(component);
		component -> parent = this;
	}

	template<typename T> bool hasComponent() {
		for (auto &component : components) {
			if (dynamic_cast<T*>(component)) {
				return true;
			}
		}

		return false;
	}

	template<typename T> T &getComponent() {
		for (auto &component : components) {
			if (T* casted = dynamic_cast<T*>(component)) {
				return *casted;
			}
		}

		throw std::runtime_error("Failed to get component. No such component exists. Use GameObject::hasComponent<Comp>() to get if the GameObject has the component.");
	}
private:
	std::vector<Component*> components;
};
