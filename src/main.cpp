#include <raylib.h>
#include <raymath.h>
#include "Setup.h"
#include <vector>
#include "Lights.h"
#include "Simulation.h"


int main()
{
    int monitor = GetCurrentMonitor();

    Setup window("graphical", monitor);

    window.LoadAssets();

    for(auto& filepath : window.GetFilepaths())
    {
        window.AddTexture(filepath);
    }   

    Simulation main;

    while(!WindowShouldClose())
    {
        BeginDrawing();

            window.Update();
            main.Update();

        EndDrawing();
    }

    CloseWindow();
    return EXIT_SUCCESS;
}