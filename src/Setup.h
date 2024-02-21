#pragma once

#include <raylib.h>
#include <vector>
#include <string>


class Setup
{
private:
    static std::vector<Texture2D> textures;
    std::vector<std::string> filepaths;
public:
    Setup(std::string title, int monitor);
    ~Setup();

    void LoadAssets();
    void AddTexture(std::string filepath);
    Texture2D GetBackground();
    static Texture2D GetLights();
    static std::vector<Texture2D> GetVehicles();
    std::vector<std::string> GetFilepaths();

    void Update();
};