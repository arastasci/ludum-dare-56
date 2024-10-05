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
#include "stepcount.h"
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

	GLFWwindow* window = glfwCreateWindow(600, 400, "Minecraft alpha 1.0", NULL, NULL);

	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	Game game;
	game.Initialize();
	auto go = new GameObject(transform());
	go->AddComponent(new stepcount());
	GameObject::Instantiate(*go, transform());
	
	RenderProperties* rp = new RenderProperties{};
	go->AddComponent(rp);

	game.ActiveScene->AddGameObject(go);

	//bool a = false;
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.69f, 0.92f, 0.92f, 1.0f);

		game.Update();

		//if (a)
		//	game.ActiveScene->GameObjects[0]->Destroy();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}
