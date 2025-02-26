#pragma once

#include "Component.h"
#include "Texture.h"

class Sprite: public Component {
public:
	Sprite(Texture &texture);
	~Sprite() override;

	Texture getTexture();
	void setTexture(Texture texture);
private:
	Texture texture;
};
