#include "Simulation.h"
#include <iostream>

#define NORTH 0
#define EAST 1
#define WEST 2
#define SOUTH 3

#define GREEN_MODE 0
#define YELLOW_MODE 1
#define RED_MODE 2


Simulation::Simulation()
{
    GreenLightDuration = 10.0f;
    GreenLightElapsed = 0.0f;

    LightState NLState = GREEN_LIGHT;
    LightState ELState = RED_LIGHT;
    LightState WLState = RED_LIGHT;
    LightState SLState = RED_LIGHT;

    //TODO: Coords to update!
    //!LIGHTS POSITIONS VARIES DEPENDING ON THE CLIENT'S MONITOR'S SIZE
    TrafficLights.push_back(Lights(NLState, (Vector2){(float)GetScreenWidth() * 0.6933, (float)GetScreenHeight() * 0.3477}, 90));
    TrafficLights.push_back(Lights(ELState, (Vector2){(float)GetScreenWidth() * 0.795, (float)GetScreenHeight() * 0.5855}, 180));
    TrafficLights.push_back(Lights(WLState, (Vector2){(float)GetScreenWidth() * 0.56, (float)GetScreenHeight() * 0.53}, 0));
    TrafficLights.push_back(Lights(SLState, (Vector2){(float)GetScreenWidth() * 0.6622, (float)GetScreenHeight() * 0.77}, -90));
}

void Simulation::Update()
{
    if(TrafficLights[NORTH].GetState() == GREEN_LIGHT)
    {
        if(GreenLightElapsed >= GreenLightDuration - 3) //3 SECS FOR THE YELLOWLIGHT
        {
            if(GreenLightElapsed >= GreenLightDuration)
            {
                TrafficLights[NORTH].SetState(RED_MODE);
                TrafficLights[EAST].SetState(GREEN_MODE);
                GreenLightElapsed = 0.0f;
            }
            else
            {
                GreenLightElapsed += GetFrameTime();
                TrafficLights[EAST].SetState(YELLOW_MODE);
            }
        } 
        else GreenLightElapsed += GetFrameTime();
    }
    else if(TrafficLights[EAST].GetState() == GREEN_LIGHT)
    {
        if(GreenLightElapsed >= GreenLightDuration - 3) //3 SECS FOR THE YELLOWLIGHT
        {
            if(GreenLightElapsed >= GreenLightDuration)
            {
                TrafficLights[EAST].SetState(RED_MODE);
                TrafficLights[WEST].SetState(GREEN_MODE);
                GreenLightElapsed = 0.0f;
            }
            else
            {
                GreenLightElapsed += GetFrameTime();
                TrafficLights[WEST].SetState(YELLOW_MODE);
            }
        } 
        else GreenLightElapsed += GetFrameTime();
    }
    else if(TrafficLights[WEST].GetState() == GREEN_LIGHT)
    {
        if(GreenLightElapsed >= GreenLightDuration - 3) //3 SECS FOR THE YELLOWLIGHT
        {
            if(GreenLightElapsed >= GreenLightDuration)
            {
                TrafficLights[WEST].SetState(RED_MODE);
                TrafficLights[SOUTH].SetState(GREEN_MODE);
                GreenLightElapsed = 0.0f;
            }
            else
            {
                GreenLightElapsed += GetFrameTime();
                TrafficLights[SOUTH].SetState(YELLOW_MODE);
            }
        } 
        else GreenLightElapsed += GetFrameTime();
    }
    else if(TrafficLights[SOUTH].GetState() == GREEN_LIGHT)
    {
        if(GreenLightElapsed >= GreenLightDuration - 3) //3 SECS FOR THE YELLOWLIGHT
        {
            if(GreenLightElapsed >= GreenLightDuration)
            {
                TrafficLights[SOUTH].SetState(RED_MODE);
                TrafficLights[NORTH].SetState(GREEN_MODE);
                GreenLightElapsed = 0.0f;
            }
            else
            {
                GreenLightElapsed += GetFrameTime();
                TrafficLights[NORTH].SetState(YELLOW_MODE);
            }
        } 
        else GreenLightElapsed += GetFrameTime();
    }
    else
    {
        std::cerr << "ERROR: May botas sa traffic ligths simulation" << std::endl;
        exit(EXIT_FAILURE);
    }


    for(auto& lights : TrafficLights)
    {
        lights.Draw();
    }
}