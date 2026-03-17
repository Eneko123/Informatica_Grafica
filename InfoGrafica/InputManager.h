#pragma once
#include <GLFW/glfw3.h>
#include <map>

class InputManager
{
public:
	InputManager();
	void Initialise(GLFWwindow* newwindow);
	
	bool isKeyPressed(int key);

	double getMouseDeltaX() { return deltaX; }
	double getMouseDeltaY() { return deltaY; }

private:
	GLFWwindow* window;
	std::map<int, bool> keyState;

	double lastX, lastY;
	double deltaX, deltaY;


	static InputManager* instance;
	static void handleKeys(GLFWwindow* window, int key, int scancode, int action, int mods);

	static void handelMouse(GLFWwindow* window, double posX, double posY);
};

