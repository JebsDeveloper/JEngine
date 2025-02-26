#pragma once

#include <glad/glad.h>
#include <stb_image/stb_image.h>

#include "Shader.h"

#include <string>

class Texture {
public:
	Texture(const char* filePath, bool pixel = false);
	~Texture();

	void bind() const;
	unsigned int getTexture();
private:
	unsigned int texture;
};
