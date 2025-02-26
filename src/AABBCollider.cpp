#include "AABBCollider.h"

#include "GameObject.h"
#include "Transform.h"

AABBCollider::AABBCollider() {

}

AABBCollider::~AABBCollider() {

}

CollisionSide AABBCollider::collisionState(const AABBCollider &other) {
	Transform &thisTransform = this -> parent -> getComponent<Transform>();
	Transform &otherTransform = other.parent -> getComponent<Transform>();

	float thisLeft = thisTransform.position.x;
	float thisRight = thisLeft + thisTransform.size.y;
	float thisTop = thisTransform.position.y;
	float thisBottom = thisTop + thisTransform.size.y;

	float otherLeft = otherTransform.position.x;
	float otherRight = otherLeft + otherTransform.size.y;
	float otherTop = otherTransform.position.y;
	float otherBottom = otherTop + otherTransform.size.y;

	if (thisRight < otherLeft || thisLeft > otherRight || thisBottom < otherTop || thisTop > otherBottom) {
		return NONE;
	}

	float overlapLeft = thisRight - otherLeft;
	float overlapRight = otherRight - thisLeft;
	float overlapTop = thisBottom - otherTop;
	float overlapBottom = otherBottom - thisTop;

	if (overlapLeft < overlapRight && overlapLeft < overlapTop && overlapLeft < overlapBottom) {
		return RIGHT;
	}

	if (overlapRight < overlapLeft && overlapRight < overlapTop && overlapRight < overlapBottom) {
		return LEFT;
	}

	if (overlapTop < overlapBottom) {
		return BOTTOM;
	}

	return TOP;
}
