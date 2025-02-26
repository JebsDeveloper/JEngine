#include "Transform.h"

Transform::Transform(glm::vec2 position, float rotation, glm::vec2 size) {
	this -> position = position;
	this -> rotation = rotation;
	this -> size = size;
}

Transform::~Transform() {

}
