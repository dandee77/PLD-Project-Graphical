#include "Lights.h"
#include <iostream>

Lights::Lights(LightState LightsState, Vector2 LightsPosition, float LightsRotation)
: state(LightsState), rotation(LightsRotation) 
{
   dest.x = LightsPosition.x;
   dest.y = LightsPosition.y;
   dest.width = (float)LightsTexture.width / 3;
   dest.height = (float)LightsTexture.height;
};

LightState Lights::GetState()
{
    return state;
}

void Lights::SetState(int state)
{
    switch(state)
    {
        case 0:
            this->state = GREEN_LIGHT;
            break;
        case 1:
            this->state = YELLOW_LIGHT;
            break;
        case 2:
            this->state = RED_LIGHT;
            break;
        default:
            std::cerr << "ERROR: Unable to change light's state" << std::endl;
            exit(EXIT_FAILURE);
    }
}

void Lights::Draw()
{
    switch(state)
    {
        case GREEN_LIGHT:
            src = {0, 0, (float)dest.width, (float)dest.height};
            break;
        case YELLOW_LIGHT:
            src = {63, 0, (float)dest.width, (float)dest.height};
            break;
        case RED_LIGHT:
            src = {126, 0, (float)dest.width, (float)dest.height};
            break;
        default:
            std::cerr << "ERROR: Undefined light state" << std::endl;
            exit(EXIT_FAILURE);
    }   

    DrawTexturePro(LightsTexture, src, dest, (Vector2){0.0f, 0.0f}, rotation, WHITE);
}