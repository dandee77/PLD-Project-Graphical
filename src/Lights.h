#pragma once

#include "Setup.h"
#include <raylib.h>
#include <string>


enum LightState
{
    GREEN_LIGHT,
    YELLOW_LIGHT,
    RED_LIGHT
};

class Lights
{
private:
    Texture2D LightsTexture = Setup::GetLights();
    LightState state;
    Rectangle src;
    Rectangle dest;
    float rotation;
public:
    Lights(LightState LightsState, Vector2 LightsPosition, float LightsRotation);
    LightState GetState();
    void SetState(int state);
    void Draw(); 
};