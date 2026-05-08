#include "Clock.h"

Clock::Clock() 
{
    DeltaTime = 0;
    CurrentTime = 0;
    LastTime = 0;
}

Clock::~Clock()
{

}

float Clock::GetDeltaTime() 
{
    return DeltaTime;
}

void Clock::StartCounter() 
{
    LastTime = glfwGetTime();
}

void Clock::ProcessDelta() 
{
    CurrentTime = glfwGetTime();
    DeltaTime = CurrentTime - LastTime;
    LastTime = CurrentTime;
    // Delta esta em segundos.
}

float Clock::GetFPS() 
{
    return 1.0f / DeltaTime;
}

float Clock::GetMS() 
{
    return DeltaTime*1000;
}