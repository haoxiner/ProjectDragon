#include "World.h"
#include "Display.h"
#include "PerformanceTimer.h"
#include "RenderingSystem.h"
int main()
{
    constexpr int xResolution = 800;
    constexpr int yResolution = 600;
    PD::Display display;
    if (!display.Startup(xResolution, yResolution)) {
        return 1;
    }
    PD::RenderingSystem renderingSystem;
    renderingSystem.EnableDepthTest();
    renderingSystem.EnableCullFace();
    renderingSystem.SetViewport(0, 0, xResolution, yResolution);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    auto input = display.GetInput();

    float deltaTime = 0.0f;

    // tick
    PD::PerformanceTimer performanceTimer;
    performanceTimer.Reset();
    // game loop
    while (display.Running())
    {
        performanceTimer.Tick();
        deltaTime = performanceTimer.GetDeltaTime();
        display.Update();
        if (input->Quit())
        {
            display.Shutdown();
        }
    }
    return 0;
}