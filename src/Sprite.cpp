#include "Sprite.h"

Sprite::Sprite(Texture &texture): texture(texture) {
	
}

Sprite::~Sprite() {
	
}

Texture Sprite::getTexture() {
	return this -> texture;
}

void Sprite::setTexture(Texture texture) {
	this -> texture = texture;
}