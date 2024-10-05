
#include "timer.h"
#include <GLFW/glfw3.h>
double Timer::getDeltaTime()
{
	return m_deltaTime;
}

double Timer::getElapsedTime()
{
	return m_elapsedTime;
}

Timer::Timer()
{
	m_lastTime = glfwGetTime();
	m_currentTime = glfwGetTime();
}

Timer::~Timer()
{
}

Timer& Timer::getInstance()
{
	static Timer instance;
	return instance;
}

void Timer::update()
{
	m_lastTime = m_currentTime;
	m_currentTime = glfwGetTime();
	m_deltaTime = m_currentTime - m_lastTime;
	m_elapsedTime += m_deltaTime;
}

