#pragma once

#include <glm/glm.hpp>

#include "Component.h"

class Transform : public Component {
public:
	Transform(glm::vec2 position = {0, 0}, float rotation = 0.0f, glm::vec2 size = {10, 10});
	~Transform() override;

	glm::vec2 position;
	float rotation;
	glm::vec2 size;
};
