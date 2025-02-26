#include "Texture.h"

#include <iostream>

Texture::Texture(const char* filePath, bool pixel) {
	glGenTextures(1, &this -> texture);

	glBindTexture(GL_TEXTURE_2D, this -> texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, pixel ? GL_NEAREST : GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, pixel ? GL_NEAREST : GL_LINEAR);

	int width;
	int height;
	int nrChannels;

	//stbi_set_flip_vertically_on_load(true);

	unsigned char* data = stbi_load(filePath, &width, &height, &nrChannels, 0);

	if (data) {
		GLenum format = (nrChannels == 4) ? GL_RGBA : GL_RGB;

		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cout << "Failed to load texture '" << filePath << "'.\n";
	}

	stbi_image_free(data);
}

Texture::~Texture() {
	
}

void Texture::bind() const {
	glBindTexture(GL_TEXTURE_2D, this -> texture);
}


unsigned int Texture::getTexture() {
	return this -> texture;
}
