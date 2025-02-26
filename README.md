# JEngine

JEngine is a simple game engine made in C++ and OpenGL. It was made as a simple programming project for me to learn about games and graphics. It includes rendering sprites, keyboard input, and some basic collision so far.

# Usage

JEngine is still in early development and you would have to copy over the files and implement the game in `Game.cpp`. You can create a GameObject like so:

```C++
Scene scene = Scene();

Texture objTexture = Texture(RESOURCES_PATH "textures/obj");

GameObject obj = GameObject(); // Create the Game Object

Transform objTransform = Transform({100.0f, 100.0f}, 0.0f, {100.0f, 100.0f}); // This is position, rotation, and scale. The object is positioned at 100, 100 and it's rotation is 0 degrees and it's size is 100, 100.
Sprite objSprite = Sprite(objTexture); // Sprite is currently just a holder for a Texture

// Add the components
obj.addComponent(&objTransform);
obj.addComponent(&objSprite);

scene.addComponent(0, std::make_unique<GameObject>(obj); // The first number is the object's ID, it determins which object is rendered before the others. If you have a background, it should usually be 0.
```

# Keyboard Input

To do key keyboard input, you need to use the `Callbacks.cpp` file. You can use `keyCallback` and `inputPerFrame`. In `keyCallback`:

```C++
if (action == GLFW_PRESS) {
	if (key == GLFW_KEY_ESCAPE) {
		doStuff();
	}
}
```

You can also put multiple if statements in the `action == GLFW_PRESS`. You can also use `inputPerFrame`:

```C++
if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
	doStuff();
}
```

# Later

More sections and guides will be added to `README.md` later as I work on more features.
