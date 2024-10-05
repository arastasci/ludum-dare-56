#pragma once
class Timer
{
public:
	static Timer& getInstance();
	Timer(Timer const&) = delete;
	void operator=(Timer const&) = delete;

	void update();
	void release();

	double getDeltaTime();
	double getElapsedTime();
private:
	Timer();
	~Timer();
	double m_deltaTime;
	double m_elapsedTime;
	double m_lastTime;
	double m_currentTime;
};
