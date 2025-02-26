#pragma once

#include "GameObject.h"
#include "AABBCollider.h"

class Globals {
public:
	static GameObject* player;
	static CollisionSide playerCollision;
};
