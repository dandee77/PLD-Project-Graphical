#include "Setup.h"

#include <assert.h>
#include <iostream>
#include <raymath.h>


Setup::Setup(std::string title, int monitor)
{
    try
    {
        assert(!GetWindowHandle());
        InitWindow(GetMonitorWidth(monitor), GetMonitorHeight(monitor), title.c_str());
        SetTargetFPS(60);
        SetWindowState(FLAG_FULLSCREEN_MODE);
        
        if(!IsWindowReady())
        {
            throw std::runtime_error("Unable to create window");
        }
    }   
    catch(const std::runtime_error& e)
    {
        std::cerr << "ERROR: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}

std::vector<Texture2D> Setup::textures;

void Setup::LoadAssets()
{
    filepaths.reserve(9);
    filepaths.emplace_back("res/crossing_sa_plaridel.png");
    filepaths.emplace_back("res/lights.png");
    filepaths.emplace_back("res/green_car.png");
    filepaths.emplace_back("res/orange_car.png");
    filepaths.emplace_back("res/pink_car.png");
    filepaths.emplace_back("res/red_car.png");
    filepaths.emplace_back("res/white_van.png");
    filepaths.emplace_back("res/orange_truck.png");
    filepaths.emplace_back("res/red_truck.png");
}

void Setup::AddTexture(std::string filepath)
{
    Texture2D texture = LoadTexture(filepath.c_str());
    if(!IsTextureReady(texture))
    {
        std::cerr << "ERROR: Unable to load a texture" << std::endl;
        exit(EXIT_FAILURE);
    }

    textures.emplace_back(texture);
}

Texture2D Setup::GetBackground()
{
    return textures[0];
}

Texture2D Setup::GetLights()
{
    return textures[1];
}

std::vector<Texture2D> Setup::GetVehicles()
{
    return {textures[2], textures[3], textures[4], 
    textures[5], textures[6], textures[7], textures[8]};
}

std::vector<std::string> Setup::GetFilepaths()
{
    return filepaths;
}

void Setup::Update()
{
    ClearBackground(RAYWHITE);
    DrawTexturePro(GetBackground(), (Rectangle){0, 0, (float)GetBackground().width, (float)GetBackground().height},
    (Rectangle){0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()}, (Vector2){0.0f, 0.0f}, 0.0f, WHITE);
}

Setup::~Setup()
{   
    for(auto& texture : textures)
    {
        UnloadTexture(texture);
    }

    //CloseWindow();
}