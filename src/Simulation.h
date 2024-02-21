#pragma once

#include <vector>
#include "Lights.h"

class Simulation
{
private:
    std::vector<Lights> TrafficLights;
    float GreenLightDuration;
    float GreenLightElapsed;
public:
    Simulation();
    void Update();
};