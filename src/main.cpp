#include <glad/glad.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stb_image.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include "engine/base/transform.h"
#include "engine/base/Game.h"
#include "engine/Vector3.h"
#include "game/scripts/stepcount.h"
#include "constants.h"
#include "game/prefab/Grid.h"
#include "engine/core/Window.h"
int main()
{
    if (!glfwInit())
    {
		std::cout << "Failed to initialize GLFW\n";
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	 #ifdef __APPLE__
	    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); //uncomment this statement to fix compilation on OS X
    #endif

	auto* window = Window::GetInstance();
	window->CreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// Enable transparency for textures
    glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	Game game;
	game.Initialize();
	
	GameObject::Instantiate<Grid>(transform{});

	//bool a = false;
	while (!window->ShouldClose())
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.69f, 0.92f, 0.92f, 1.0f);

		game.Update();

		//if (a)
		//	game.ActiveScene->GameObjects[0]->Destroy();
		window->SwapBuffers();
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}
