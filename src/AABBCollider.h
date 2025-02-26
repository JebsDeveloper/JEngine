#pragma once

#include "Component.h"

enum CollisionSide {
	NONE,
	TOP,
	BOTTOM,
	LEFT,
	RIGHT
};

class AABBCollider : public Component {
public:
	AABBCollider();
	~AABBCollider() override;

	CollisionSide collisionState(const AABBCollider &other);
};
